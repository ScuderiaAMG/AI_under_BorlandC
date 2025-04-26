
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int atoi_f(char* a, int* num_arr, int n, int ci_xing, int* c);
int atoI(const char* str);
int get_num(char* a);

/***************
    PHR结构体：用于存储断句后句子中各个成分的标号，以及替代转化之后的标号
***************/
typedef struct
{
    char* str; // 存储段句后的这个短语
    int num_arr[15]; //存储用小数点分隔后的标号，如果没有找到num_arr[0]==0
    int num_pre[15]; //存储一旦可以被关键词替代，替代后的词语的标号
    int x; //用于判断该词是否需要关键词替代，x=1则可以被替代，x=0则不能被替代
} PHR;


/***************
    Temp结构体：用于临时存储搜索文件时暂时搜到的标号+短语或词语
***************/
typedef struct
{
    char num[20];
    char phrase[100];
} Temp;



/***************
    函数名称：mark
    函数目的：给断句后句子中的成分标号
    函数参数：str：断句后的短语数组（字符串数组）
              ceng：记录标号中有几个数字，如1.23.有2个，是关键词，不可被替代；而1.23.4就有3个 ，不是关键词，需要被替代
***************/
PHR* mark(char** str, int* ceng)
{
    int ceng_shu;//用于记录标号中有几个数字，如1.23.有2个；而1.23.4就有3个 
    //static PHR arr[300]; // 声明结构体
    PHR arr[30]={0};
    int i = 0, j = 0, k = 0;
    for(i=0;i<30;i++)
    {
		arr[i].str=(char*)malloc(30);
		memset(arr[i].str,0,30);
		for(j=0;j<15;j++)
		{
			arr[i].num_arr[j]=0;
			arr[i].num_pre[j]=0;
		}
		arr[i].x=0;
	}
	i=0;
	j=0;
    //int m=0;
    FILE* file;
    //static Temp temp;
    Temp temp;
    char c; // 用c来读取file指向的字符



    // arr[i]是存断完的句子中的各个部分的信息的结构体
    while (str[i])
    {
        arr[i].str = str[i]; // 先存储初始内容
        i++;
    }
    i = 0; // 清零，以便下次使用

    while (str[i])
    {
        // 重置临时变量
        memset(&temp, 0, sizeof(temp));

        // 1.查找是不是名词里面的
        file = fopen("C:\\CODE\\word\\mingci.txt", "rt"); // 以只读模式打开文件,file自动指向开头
        if (file == NULL)
        {
            //perror("无法打开文件");
            return 0;
        }
        else 
		{
            //printf("文件成功打开: D:\\mingci.txt\n");
        }

        while (!feof(file))// 当名词文件尚未检索完毕时
        {
            // 避免开始文件指针指向空白区域
            do
            {
                c = fgetc(file); // 文件指针右移一个单位
            } while (c != EOF && (c > '9' || c < '0')); // 如果不是标号中的数字
            if (c == EOF)
            {
                break;
            }
            fseek(file, -1, SEEK_CUR); // 复原

            // 把文件中的%d.%f和词语存到temp结构体中一个一个比较
            j = 0; // 清零，以便下次使用
            while ((c = fgetc(file)) != EOF && ((c >= '0' && c <= '9') || c == '.')) // 存浮点数
            {
                temp.num[j++] = c;
            }
            temp.num[j] = '\0'; // 添加字符串结束符

            k = 0; // 清零，以便下次使用
            while (c != EOF && c < '0')  // 存短语
            {
                temp.phrase[k++] = c;
                c = fgetc(file);
            }
            temp.phrase[k] = '\0'; // 添加字符串结束符
            fseek(file, -1, SEEK_CUR); // 复原

            // if (strstr(temp.phrase, str[i]) != NULL) // 在名词对应文件中找到了（在名词里面）

            if (strstr(temp.phrase, str[i]) != NULL) // 在文件中找到了
            {
                int num_points = get_num(temp.num);//计算有几个点


                if (atoi_f(temp.num, arr[i].num_arr, num_points + 1, 1, &ceng_shu) == 1) // 如果这个是最底层的词语，可以进行替代
                {
                    arr[i].x = 1;
                }
                else
                {
                    arr[i].x = 0;
                }
                ceng[i] = ceng_shu;
                break;//仅推出这一层循环
            }

        }
        fclose(file); // 关闭文件

        if (arr[i].num_arr[0] == 1)
        {
            i++;
            continue;
        }

        // 2.查找是不是动词里面的
        file = fopen("C:\\CODE\\word\\dongci.txt", "rt"); // 以只读模式打开文件,file自动指向开头
        if (file == NULL)
        {
           // perror("无法打开文件");
            return 0;
        }
        else
        {
            //printf("文件成功打开: D:\\dongci.txt\n");
        }

        while (!feof(file))
        {
            // 避免开始文件指针指向空白区域
            do
            {
                c = fgetc(file); // 文件指针右移一个单位
            } while (c != EOF && (c > '9' || c < '0')); // 如果不是标号中的数字
            if (c == EOF)
            {
                break;
            }
            fseek(file, -1, SEEK_CUR); // 复原

            // 把文件中的%d.%f和词语存到temp结构体中
            j = 0; // 清零，以便下次使用
            while ((c = fgetc(file)) != EOF && ((c >= '0' && c <= '9') || c == '.'))  // 存浮点数
            {
                temp.num[j++] = c;
            }
            temp.num[j] = '\0'; // 添加字符串结束符

            k = 0; // 清零，以便下次使用
            while (c != EOF && c < '0')  // 存短语
            {
                temp.phrase[k++] = c;
                c = fgetc(file);
            }
            temp.phrase[k] = '\0'; // 添加字符串结束符
            fseek(file, -1, SEEK_CUR); // 复原

            if (strstr(temp.phrase, str[i]) != NULL)  // 在动词对应文件中找到了

            {
                int num_points = get_num(temp.num);//计算有几个点 


                if (atoi_f(temp.num, arr[i].num_arr, num_points + 1, 2, &ceng_shu) == 1) // 如果这个是最底层的词语，可以进行替代
                {
                    arr[i].x = 1;
                }
                else
                {
                    arr[i].x = 0;
                }
                ceng[i] = ceng_shu;
                break;//仅推出这一层循环 
            }

        }
        fclose(file); // 关闭文件

        if (arr[i].num_arr[0] == 2)
        {
            i++;
            continue;
        }

        // 3.查找是不是形容词里面的
        file = fopen("C:\\CODE\\word\\xingrongci.txt", "rt"); // 以只读模式打开文件,file自动指向开头
        if (file == NULL)
        {
           // perror("无法打开文件");
            return 0;
        }
        else
        {
            //printf("文件成功打开: D:\\xingrongci.txt\n");
        }

        while (!feof(file))
        {
            // 避免开始文件指针指向空白区域
            do
            {
                c = fgetc(file); // 文件指针右移一个单位
            } while (c != EOF && (c > '9' || c < '0')); // 如果不是标号中的数字
            if (c == EOF)
            {
                break;
            }
            fseek(file, -1, SEEK_CUR); // 复原

            // 把文件中的%d.%f和词语存到temp结构体中一个一个比较
            j = 0; // 清零，以便下次使用
            while ((c = fgetc(file)) != EOF && ((c >= '0' && c <= '9') || c == '.')) // 存浮点数
            {
                temp.num[j++] = c;
            }
            temp.num[j] = '\0'; // 添加字符串结束符

            k = 0; // 清零，以便下次使用
            while (c != EOF && c < '0') // 存短语
            {
                temp.phrase[k++] = c;
                c = fgetc(file);
            }
            temp.phrase[k] = '\0'; // 添加字符串结束符
            fseek(file, -1, SEEK_CUR); // 复原

            if (strstr(temp.phrase, str[i]) != NULL) // 在形容词对应文件中找到了
            {
                int num_points = get_num(temp.num);//计算有几个点 


                if (atoi_f(temp.num, arr[i].num_arr, num_points + 1, 3, &ceng_shu) == 1) // 如果这个是最底层的词语，可以进行替代
                {
                    arr[i].x = 1;
                }
                else
                {
                    arr[i].x = 0;
                }
                ceng[i] = ceng_shu;
                break;//仅推出这一层循环 
            }
        }
        fclose(file); // 关闭文件

        if (arr[i].num_arr[0] == 3)
        {
            i++;
            continue;
        }

        // 4.查找是不是副词里面的
        file = fopen("C:\\CODE\\word\\fuci.txt", "rt"); // 以只读模式打开文件,file自动指向开头
        if (file == NULL)
        {
           // perror("无法打开文件");
            return 0;
        }
        else
        {
            //printf("文件成功打开: D:\\fuci.txt\n");
        }

        while (!feof(file))
        {
            // 避免开始文件指针指向空白区域
            do
            {
                c = fgetc(file); // 文件指针右移一个单位
            } while (c != EOF && (c > '9' || c < '0')); // 如果不是标号中的数字
            if (c == EOF)
            {
                break;
            }
            fseek(file, -1, SEEK_CUR); // 复原

            // 把文件中的%d.%f和词语存到temp结构体中
            j = 0; // 清零，以便下次使用
            while ((c = fgetc(file)) != EOF && ((c >= '0' && c <= '9') || c == '.'))  // 存浮点数
            {
                temp.num[j++] = c;
            }
            temp.num[j] = '\0'; // 添加字符串结束符

            k = 0; // 清零，以便下次使用
            while (c != EOF && c < '0')  // 存短语
            {
                temp.phrase[k++] = c;
                c = fgetc(file);
            }
            temp.phrase[k] = '\0'; // 添加字符串结束符
            fseek(file, -1, SEEK_CUR); // 复原

            if (strstr(temp.phrase, str[i]) != NULL)  // 在副词对应文件中找到了
            {
                int num_points = get_num(temp.num);//计算有几个点 


                if (atoi_f(temp.num, arr[i].num_arr, num_points + 1, 4, &ceng_shu) == 1) // 如果这个是最底层的词语，可以进行替代
                {
                    arr[i].x = 1;
                }
                else
                {
                    arr[i].x = 0;
                }
                ceng[i] = ceng_shu;
                break;//仅推出这一层循环 
            }
        }
        fclose(file); // 关闭文件

        if (arr[i].num_arr[0] == 4)
        {
            i++;
            continue;
        }

        // 5.查找是不是连词里面的
        file = fopen("C:\\CODE\\word\\lianci.txt", "rt"); // 以只读模式打开文件,file自动指向开头
        if (file == NULL)
        {
          //  perror("无法打开文件");
            return 0;
        }
        else
        {
            //printf("文件成功打开: D:\\lianci.txt\n");
        }

        while (!feof(file))
        {
            // 避免开始文件指针指向空白区域
            do
            {
                c = fgetc(file); // 文件指针右移一个单位
            } while (c != EOF && (c > '9' || c < '0')); // 如果不是标号中的数字
            if (c == EOF)
            {
                break;
            }
            fseek(file, -1, SEEK_CUR); // 复原

            // 把文件中的%d.%f和词语存到temp结构体中
            j = 0; // 清零，以便下次使用
            while ((c = fgetc(file)) != EOF && ((c >= '0' && c <= '9') || c == '.'))  // 存浮点数
            {
                temp.num[j++] = c;
            }
            temp.num[j] = '\0'; // 添加字符串结束符

            k = 0; // 清零，以便下次使用
            while (c != EOF && c < '0')  // 存短语
            {
                temp.phrase[k++] = c;
                c = fgetc(file);
            }
            temp.phrase[k] = '\0'; // 添加字符串结束符
            fseek(file, -1, SEEK_CUR); // 复原

            if (strstr(temp.phrase, str[i]) != NULL)  // 在连词对应文件中找到了
            {
                int num_points = get_num(temp.num);//计算有几个点 


                if (atoi_f(temp.num, arr[i].num_arr, num_points + 1, 5, &ceng_shu) == 1) // 如果这个是最底层的词语，可以进行替代
                {
                    arr[i].x = 1;
                }
                else
                {
                    arr[i].x = 0;
                }
                ceng[i] = ceng_shu;
                break;//仅推出这一层循环 
            }
        }
        fclose(file); // 关闭文件

        if (arr[i].num_arr[0] == 5)
        {
            i++;
            continue;
        }

        // 6.查找是不是介词里面的
        file = fopen("C:\\CODE\\word\\jieci.txt", "rt"); // 以只读模式打开文件,file自动指向开头
        if (file == NULL)
        {
           // perror("无法打开文件");
            return 0;
        }
        else
        {
            //printf("文件成功打开: D:\\jieci.txt\n");
        }

        while (!feof(file))
        {
            // 避免开始文件指针指向空白区域
            do
            {
                c = fgetc(file); // 文件指针右移一个单位
            } while (c != EOF && (c > '9' || c < '0')); // 如果不是标号中的数字
            if (c == EOF)
            {
                break;
            }
            fseek(file, -1, SEEK_CUR); // 复原

            // 把文件中的%d.%f和词语存到temp结构体中
            j = 0; // 清零，以便下次使用
            while ((c = fgetc(file)) != EOF && ((c >= '0' && c <= '9') || c == '.'))  // 存浮点数
            {
                temp.num[j++] = c;
            }
            temp.num[j] = '\0'; // 添加字符串结束符

            k = 0; // 清零，以便下次使用
            while (c != EOF && c < '0')  // 存短语
            {
                temp.phrase[k++] = c;
                c = fgetc(file);
            }
            temp.phrase[k] = '\0'; // 添加字符串结束符
            fseek(file, -1, SEEK_CUR); // 复原

            if (strstr(temp.phrase, str[i]) != NULL)  // 在动词对应文件中找到了
            {
                int num_points = get_num(temp.num);//计算有几个点


                if (atoi_f(temp.num, arr[i].num_arr, num_points + 1, 6, &ceng_shu) == 1) // 如果这个是最底层的词语，可以进行替代
                {
                    arr[i].x = 1;
                }
                else
                {
                    arr[i].x = 0;
                }
                ceng[i] = ceng_shu;
                break;//仅推出这一层循环 
            }
        }
        fclose(file); // 关闭文件

        if (arr[i].num_arr[0] == 6)
        {
            i++;
            continue;
        }


        // 7.查找是不是代词里面的
        file = fopen("C:\\CODE\\word\\daici.txt", "rt"); // 以只读模式打开文件,file自动指向开头
        if (file == NULL)
        {
           // perror("无法打开文件");
            return 0;
        }
        else
        {
            //printf("文件成功打开: D:\\daici.txt\n");
        }

        while (!feof(file))
        {
            // 避免开始文件指针指向空白区域
            do
            {
                c = fgetc(file); // 文件指针右移一个单位
            } while (c != EOF && (c > '9' || c < '0')); // 如果不是标号中的数字
            if (c == EOF)
            {
                break;
            }
            fseek(file, -1, SEEK_CUR); // 复原

            // 把文件中的%d.%f和词语存到temp结构体中
            j = 0; // 清零，以便下次使用
            while ((c = fgetc(file)) != EOF && ((c >= '0' && c <= '9') || c == '.'))  // 存浮点数
            {
                temp.num[j++] = c;
            }
            temp.num[j] = '\0'; // 添加字符串结束符

            k = 0; // 清零，以便下次使用
            while (c != EOF && c < '0')  // 存短语
            {
                temp.phrase[k++] = c;
                c = fgetc(file);
            }
            temp.phrase[k] = '\0'; // 添加字符串结束符
            fseek(file, -1, SEEK_CUR); // 复原

            if (strstr(temp.phrase, str[i]) != NULL)  // 在动词对应文件中找到了
            {
                int num_points = get_num(temp.num);//计算有几个点


                if (atoi_f(temp.num, arr[i].num_arr, num_points + 1, 7, &ceng_shu) == 1) // 如果这个是最底层的词语，可以进行替代
                {
                    arr[i].x = 1;
                }
                else
                {
                    arr[i].x = 0;
                }
                ceng[i] = ceng_shu;
                break;//仅推出这一层循环 
            }
        }
        fclose(file); // 关闭文件

        if (arr[i].num_arr[0] == 7)
        {
            i++;
            continue;
        }

        // 8.查找是不是数量词里面的
        file = fopen("C:\\CODE\\word\\shuliangci.txt", "rt"); // 以只读模式打开文件,file自动指向开头
        if (file == NULL)
        {
          //  perror("无法打开文件");
            return 0;
        }
        else
        {
            //printf("文件成功打开: D:\\shuliangci.txt\n");
        }

        while (!feof(file))
        {
            // 避免开始文件指针指向空白区域
            do
            {
                c = fgetc(file); // 文件指针右移一个单位
            } while (c != EOF && (c > '9' || c < '0')); // 如果不是标号中的数字
            if (c == EOF)
            {
                break;
            }
            fseek(file, -1, SEEK_CUR); // 复原

            // 把文件中的%d.%f和词语存到temp结构体中
            j = 0; // 清零，以便下次使用
            while ((c = fgetc(file)) != EOF && ((c >= '0' && c <= '9') || c == '.'))  // 存浮点数
            {
                temp.num[j++] = c;
            }
            temp.num[j] = '\0'; // 添加字符串结束符

            k = 0; // 清零，以便下次使用
            while (c != EOF && c < '0')  // 存短语
            {
                temp.phrase[k++] = c;
                c = fgetc(file);
            }
            temp.phrase[k] = '\0'; // 添加字符串结束符
            fseek(file, -1, SEEK_CUR); // 复原

            if (strstr(temp.phrase, str[i]) != NULL) // 在文件中找到了
            {
                int num_points = get_num(temp.num);//计算有几个点


                if (atoi_f(temp.num, arr[i].num_arr, num_points + 1, 8, &ceng_shu) == 1) // 如果这个是最底层的词语，可以进行替代
                {
                    arr[i].x = 1;
                }
                else
                {
                    arr[i].x = 0;
                }
                ceng[i] = ceng_shu;
                break;//仅推出这一层循环
            }
        }
        fclose(file); // 关闭文件

        if (arr[i].num_arr[0] == 8)
        {
            i++;
            continue;
        }


        i++; // 准备给输入内容在断句后的下一个成分进行编号
    }
		return arr;
}




/***************
    函数名称：atoi_f
    函数目的：提取文件中已经找到的短语前面对应的数字字符串并将其转化为数组，以便在将标号存入PHR结构体的arr.num_arr中
    函数参数： a：已经找到的短语前面对应的数字字符串
               num_arr：是PHR结构体中arr.num_arr的形参
               n：数字字符串里面有几个'.'
               ci_xing：名词标为1，动词标为2，等等
               c：记录标号中有几个数字，也就是层数
***************/
int atoi_f(char* a, int* num_arr, int n, int ci_xing, int* c)
{
    int i = 0, j = 0, k = 0;
    static char s1[5]; // 存储第一个小数点前面的数
    static char s2[5]; // 存储第二个小数点前面的数 

    num_arr[0] = ci_xing;
    *c = 2;
    // 存储第一个小数点左边的数，表示词性之后的第一级分类
    while (a[i] != '.' && a[i] != '\0')
    {
        s1[j++] = a[i++];
    }
    s1[j] = '\0'; // 添加字符串结束符
    num_arr[1] = atoI(s1);

    for (k = 2; k <= n + 1; k++)
    {
        if (a[i] == '.' && a[i + 1] <= '9' && a[i + 1] >= '0') // 注意标号中不能有1.0的情况
        {
            i++; // 把小数点跳过去
            j = 0;
            while (a[i] != '.' && a[i] != '\0')
            {
                s2[j++] = a[i++];
            }
            s2[j] = '\0'; // 添加字符串结束符
            num_arr[k] = atoI(s2);
            (*c)++;
        }
    }
    if (*c == n)
    {
        return 2;// 这种情况说明没有可以替代这个词语的，也就是它是分类的名称
    }
    else
    {
        return 1;// 这种情况说明这个词语是最底层的词语,需要一个上层的来替代	
    }
}


/***************
函数名称：remark
函数目的：对标完号的PHR结构体数组进行加工
函数参数：str：断句后的短语数组（字符串数组）
***************/

PHR* remark(char** str)
{
    int i = 0;
    int j;
    int ceng[300];
    //static PHR* arr;
    PHR* arr;
    arr = mark(str, ceng);

    //while (str[i])
	{
        if (arr[i].num_arr[0] != 0)
        {

            for (j = 0; j < (ceng[i] - arr[i].x); j++)
            {
                arr[i].num_pre[j] = arr[i].num_arr[j];
            }
        }
        i++;
    }
    x:
    return arr;
}

/***************
函数名称：get_num
函数目的：测量出标号里面有几个点，也就是在词汇树中属于第几层
函数参数：a：断句后的短语对应的数字字符串
***************/

int get_num(char* a)
{
    int n = 0, i = 0;
    while (a[i] != '\0')
    {
        if (a[i] == '.')
        {
            n++;
        }
        i++;
    }
    return n;
}


/***************
函数名称：atoI
函数目的：因为BC库里面没有这个函数，与atoi作用相同
函数参数：str：数字字符串
***************/
int atoI(const char* str) 
{
    int result = 0;
    int sign = 1;

    // 跳过空白字符
    while (*str == ' ' || *str == '\t')
	{
        str++;
    }

    // 处理符号
    if (*str == '-') 
	{
        sign = -1;
        str++;
    }
    else if (*str == '+') 
	{
        str++;
    }

    // 逐字符转换
    while (*str >= '0' && *str <= '9') 
	{
        result = result * 10 + (*str - '0');
        str++;
    }

    return sign * result;
}

PHR* input(char **word,char* biaohao)
{
    //输入词语
	int m;
	char shapowanyi[100]={0};
	int ceng[8];//分别记录对应几个真实标号
	char* inputArray[3]; // 真正调用的时候可以根据实际情况动态分配内存,现在假设是8个

	inputArray[0]=(char*)malloc(1001);
	inputArray[1]=(char*)malloc(1001);
	inputArray[2]=(char*)malloc(1001);
	memset(inputArray[0],0,1001);
	memset(inputArray[1],0,1001);
	memset(inputArray[2],0,1001);

    int i = 0;
    int j = 0;
    char temp[50];
    memset(biaohao,0,100);
    for (i = 0; i < 1; i++)
    {
		inputArray[i] = word[i];
    }
    //inputArray[2] = NULL;
    // 调用remark函数
    //static PHR* phrases = remark(inputArray);
    PHR* phrases = remark(inputArray);
    for (i = 0; i < 1; i++)
	{
        if (phrases[i].num_arr[0] != 0)
        {
        	if(phrases[i].num_arr[3]==0)
        	{
				//printf("标号: ");
				while (phrases[i].num_arr[j] != 0)
				{
				    //printf("%d ", phrases[i].num_arr[j]);
				    itoa(phrases[i].num_arr[j],shapowanyi,10);
				    strcat(biaohao,shapowanyi);
				    memset(shapowanyi,0,100);
				    strcat(biaohao,".");
				    memset(temp,0,50);
				    j++;
				}
			}
            j = 0;
        }
    }
    x0:
    	return 0;
}

PHR* input2(char word[1][101],char* biaohao)
{
    // 输入词语
	int m;
	char shapowanyi[100]={0};
	int ceng[8];//分别记录对应几个真实标号
	char* inputArray[3]; // 真正调用的时候可以根据实际情况动态分配内存,现在假设是8个
    
    inputArray[0]=(char*)malloc(1001);
    inputArray[1]=(char*)malloc(1001);
    inputArray[2]=(char*)malloc(1001);
    
    memset(inputArray[0],0,1001);
    memset(inputArray[1],0,1001);
    memset(inputArray[2],0,1001);
    
    int i = 0;
    int j = 0;
    char temp[50];
    memset(biaohao,0,100);
    
    for (i = 0; i < 1; i++)
    {
		inputArray[i] = word[i];
    }
    //inputArray[2] = NULL;
    // 调用remark函数
    //static PHR* phrases = remark(inputArray);
    PHR* phrases = remark(inputArray);
    for (i = 0; i < 1; i++) 
	{
        if (phrases[i].num_arr[0] != 0)
        {
        	if(phrases[i].num_arr[3]==0)
        	{
				while (phrases[i].num_arr[j] != 0)
				{
				    itoa(phrases[i].num_arr[j],shapowanyi,10);
				    strcat(biaohao,shapowanyi);
				    memset(shapowanyi,0,100);
				    strcat(biaohao,".");
				    memset(temp,0,50);
				    j++;
				}
			}
            j = 0;
        }
    }
    x0:
    	return 0;
}
