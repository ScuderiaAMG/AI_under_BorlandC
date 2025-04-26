
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int atoi_f(char* a, int* num_arr, int n, int ci_xing, int* c);
int atoI(const char* str);
int get_num(char* a);

/***************
    PHR�ṹ�壺���ڴ洢�Ͼ������и����ɷֵı�ţ��Լ����ת��֮��ı��
***************/
typedef struct
{
    char* str; // �洢�ξ����������
    int num_arr[15]; //�洢��С����ָ���ı�ţ����û���ҵ�num_arr[0]==0
    int num_pre[15]; //�洢һ�����Ա��ؼ�������������Ĵ���ı��
    int x; //�����жϸô��Ƿ���Ҫ�ؼ��������x=1����Ա������x=0���ܱ����
} PHR;


/***************
    Temp�ṹ�壺������ʱ�洢�����ļ�ʱ��ʱ�ѵ��ı��+��������
***************/
typedef struct
{
    char num[20];
    char phrase[100];
} Temp;



/***************
    �������ƣ�mark
    ����Ŀ�ģ����Ͼ������еĳɷֱ��
    ����������str���Ͼ��Ķ������飨�ַ������飩
              ceng����¼������м������֣���1.23.��2�����ǹؼ��ʣ����ɱ��������1.23.4����3�� �����ǹؼ��ʣ���Ҫ�����
***************/
PHR* mark(char** str, int* ceng)
{
    int ceng_shu;//���ڼ�¼������м������֣���1.23.��2������1.23.4����3�� 
    //static PHR arr[300]; // �����ṹ��
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
    char c; // ��c����ȡfileָ����ַ�



    // arr[i]�Ǵ�]����ľ����еĸ������ֵ���Ϣ�Ľṹ��
    while (str[i])
    {
        arr[i].str = str[i]; // �ȴ洢��ʼ����
        i++;
    }
    i = 0; // ���㣬�Ա��´�ʹ��

    while (str[i])
    {
        // ������ʱ����
        memset(&temp, 0, sizeof(temp));

        // 1.�����ǲ������������
        file = fopen("C:\\CODE\\word\\mingci.txt", "rt"); // ��ֻ��ģʽ���ļ�,file�Զ�ָ��ͷ
        if (file == NULL)
        {
            //perror("�޷����ļ�");
            return 0;
        }
        else 
		{
            //printf("�ļ��ɹ���: D:\\mingci.txt\n");
        }

        while (!feof(file))// �������ļ���δ�������ʱ
        {
            // ���⿪ʼ�ļ�ָ��ָ��հ�����
            do
            {
                c = fgetc(file); // �ļ�ָ������һ����λ
            } while (c != EOF && (c > '9' || c < '0')); // ������Ǳ���е�����
            if (c == EOF)
            {
                break;
            }
            fseek(file, -1, SEEK_CUR); // ��ԭ

            // ���ļ��е�%d.%f�ʹ���浽temp�ṹ����һ��һ���Ƚ�
            j = 0; // ���㣬�Ա��´�ʹ��
            while ((c = fgetc(file)) != EOF && ((c >= '0' && c <= '9') || c == '.')) // �渡����
            {
                temp.num[j++] = c;
            }
            temp.num[j] = '\0'; // ����ַ���������

            k = 0; // ���㣬�Ա��´�ʹ��
            while (c != EOF && c < '0')  // �����
            {
                temp.phrase[k++] = c;
                c = fgetc(file);
            }
            temp.phrase[k] = '\0'; // ����ַ���������
            fseek(file, -1, SEEK_CUR); // ��ԭ

            // if (strstr(temp.phrase, str[i]) != NULL) // �����ʶ�Ӧ�ļ����ҵ��ˣ����������棩

            if (strstr(temp.phrase, str[i]) != NULL) // ���ļ����ҵ���
            {
                int num_points = get_num(temp.num);//�����м�����


                if (atoi_f(temp.num, arr[i].num_arr, num_points + 1, 1, &ceng_shu) == 1) // ����������ײ�Ĵ�����Խ������
                {
                    arr[i].x = 1;
                }
                else
                {
                    arr[i].x = 0;
                }
                ceng[i] = ceng_shu;
                break;//���Ƴ���һ��ѭ��
            }

        }
        fclose(file); // �ر��ļ�

        if (arr[i].num_arr[0] == 1)
        {
            i++;
            continue;
        }

        // 2.�����ǲ��Ƕ��������
        file = fopen("C:\\CODE\\word\\dongci.txt", "rt"); // ��ֻ��ģʽ���ļ�,file�Զ�ָ��ͷ
        if (file == NULL)
        {
           // perror("�޷����ļ�");
            return 0;
        }
        else
        {
            //printf("�ļ��ɹ���: D:\\dongci.txt\n");
        }

        while (!feof(file))
        {
            // ���⿪ʼ�ļ�ָ��ָ��հ�����
            do
            {
                c = fgetc(file); // �ļ�ָ������һ����λ
            } while (c != EOF && (c > '9' || c < '0')); // ������Ǳ���е�����
            if (c == EOF)
            {
                break;
            }
            fseek(file, -1, SEEK_CUR); // ��ԭ

            // ���ļ��е�%d.%f�ʹ���浽temp�ṹ����
            j = 0; // ���㣬�Ա��´�ʹ��
            while ((c = fgetc(file)) != EOF && ((c >= '0' && c <= '9') || c == '.'))  // �渡����
            {
                temp.num[j++] = c;
            }
            temp.num[j] = '\0'; // ����ַ���������

            k = 0; // ���㣬�Ա��´�ʹ��
            while (c != EOF && c < '0')  // �����
            {
                temp.phrase[k++] = c;
                c = fgetc(file);
            }
            temp.phrase[k] = '\0'; // ����ַ���������
            fseek(file, -1, SEEK_CUR); // ��ԭ

            if (strstr(temp.phrase, str[i]) != NULL)  // �ڶ��ʶ�Ӧ�ļ����ҵ���

            {
                int num_points = get_num(temp.num);//�����м����� 


                if (atoi_f(temp.num, arr[i].num_arr, num_points + 1, 2, &ceng_shu) == 1) // ����������ײ�Ĵ�����Խ������
                {
                    arr[i].x = 1;
                }
                else
                {
                    arr[i].x = 0;
                }
                ceng[i] = ceng_shu;
                break;//���Ƴ���һ��ѭ�� 
            }

        }
        fclose(file); // �ر��ļ�

        if (arr[i].num_arr[0] == 2)
        {
            i++;
            continue;
        }

        // 3.�����ǲ������ݴ������
        file = fopen("C:\\CODE\\word\\xingrongci.txt", "rt"); // ��ֻ��ģʽ���ļ�,file�Զ�ָ��ͷ
        if (file == NULL)
        {
           // perror("�޷����ļ�");
            return 0;
        }
        else
        {
            //printf("�ļ��ɹ���: D:\\xingrongci.txt\n");
        }

        while (!feof(file))
        {
            // ���⿪ʼ�ļ�ָ��ָ��հ�����
            do
            {
                c = fgetc(file); // �ļ�ָ������һ����λ
            } while (c != EOF && (c > '9' || c < '0')); // ������Ǳ���е�����
            if (c == EOF)
            {
                break;
            }
            fseek(file, -1, SEEK_CUR); // ��ԭ

            // ���ļ��е�%d.%f�ʹ���浽temp�ṹ����һ��һ���Ƚ�
            j = 0; // ���㣬�Ա��´�ʹ��
            while ((c = fgetc(file)) != EOF && ((c >= '0' && c <= '9') || c == '.')) // �渡����
            {
                temp.num[j++] = c;
            }
            temp.num[j] = '\0'; // ����ַ���������

            k = 0; // ���㣬�Ա��´�ʹ��
            while (c != EOF && c < '0') // �����
            {
                temp.phrase[k++] = c;
                c = fgetc(file);
            }
            temp.phrase[k] = '\0'; // ����ַ���������
            fseek(file, -1, SEEK_CUR); // ��ԭ

            if (strstr(temp.phrase, str[i]) != NULL) // �����ݴʶ�Ӧ�ļ����ҵ���
            {
                int num_points = get_num(temp.num);//�����м����� 


                if (atoi_f(temp.num, arr[i].num_arr, num_points + 1, 3, &ceng_shu) == 1) // ����������ײ�Ĵ�����Խ������
                {
                    arr[i].x = 1;
                }
                else
                {
                    arr[i].x = 0;
                }
                ceng[i] = ceng_shu;
                break;//���Ƴ���һ��ѭ�� 
            }
        }
        fclose(file); // �ر��ļ�

        if (arr[i].num_arr[0] == 3)
        {
            i++;
            continue;
        }

        // 4.�����ǲ��Ǹ��������
        file = fopen("C:\\CODE\\word\\fuci.txt", "rt"); // ��ֻ��ģʽ���ļ�,file�Զ�ָ��ͷ
        if (file == NULL)
        {
           // perror("�޷����ļ�");
            return 0;
        }
        else
        {
            //printf("�ļ��ɹ���: D:\\fuci.txt\n");
        }

        while (!feof(file))
        {
            // ���⿪ʼ�ļ�ָ��ָ��հ�����
            do
            {
                c = fgetc(file); // �ļ�ָ������һ����λ
            } while (c != EOF && (c > '9' || c < '0')); // ������Ǳ���е�����
            if (c == EOF)
            {
                break;
            }
            fseek(file, -1, SEEK_CUR); // ��ԭ

            // ���ļ��е�%d.%f�ʹ���浽temp�ṹ����
            j = 0; // ���㣬�Ա��´�ʹ��
            while ((c = fgetc(file)) != EOF && ((c >= '0' && c <= '9') || c == '.'))  // �渡����
            {
                temp.num[j++] = c;
            }
            temp.num[j] = '\0'; // ����ַ���������

            k = 0; // ���㣬�Ա��´�ʹ��
            while (c != EOF && c < '0')  // �����
            {
                temp.phrase[k++] = c;
                c = fgetc(file);
            }
            temp.phrase[k] = '\0'; // ����ַ���������
            fseek(file, -1, SEEK_CUR); // ��ԭ

            if (strstr(temp.phrase, str[i]) != NULL)  // �ڸ��ʶ�Ӧ�ļ����ҵ���
            {
                int num_points = get_num(temp.num);//�����м����� 


                if (atoi_f(temp.num, arr[i].num_arr, num_points + 1, 4, &ceng_shu) == 1) // ����������ײ�Ĵ�����Խ������
                {
                    arr[i].x = 1;
                }
                else
                {
                    arr[i].x = 0;
                }
                ceng[i] = ceng_shu;
                break;//���Ƴ���һ��ѭ�� 
            }
        }
        fclose(file); // �ر��ļ�

        if (arr[i].num_arr[0] == 4)
        {
            i++;
            continue;
        }

        // 5.�����ǲ������������
        file = fopen("C:\\CODE\\word\\lianci.txt", "rt"); // ��ֻ��ģʽ���ļ�,file�Զ�ָ��ͷ
        if (file == NULL)
        {
          //  perror("�޷����ļ�");
            return 0;
        }
        else
        {
            //printf("�ļ��ɹ���: D:\\lianci.txt\n");
        }

        while (!feof(file))
        {
            // ���⿪ʼ�ļ�ָ��ָ��հ�����
            do
            {
                c = fgetc(file); // �ļ�ָ������һ����λ
            } while (c != EOF && (c > '9' || c < '0')); // ������Ǳ���е�����
            if (c == EOF)
            {
                break;
            }
            fseek(file, -1, SEEK_CUR); // ��ԭ

            // ���ļ��е�%d.%f�ʹ���浽temp�ṹ����
            j = 0; // ���㣬�Ա��´�ʹ��
            while ((c = fgetc(file)) != EOF && ((c >= '0' && c <= '9') || c == '.'))  // �渡����
            {
                temp.num[j++] = c;
            }
            temp.num[j] = '\0'; // ����ַ���������

            k = 0; // ���㣬�Ա��´�ʹ��
            while (c != EOF && c < '0')  // �����
            {
                temp.phrase[k++] = c;
                c = fgetc(file);
            }
            temp.phrase[k] = '\0'; // ����ַ���������
            fseek(file, -1, SEEK_CUR); // ��ԭ

            if (strstr(temp.phrase, str[i]) != NULL)  // �����ʶ�Ӧ�ļ����ҵ���
            {
                int num_points = get_num(temp.num);//�����м����� 


                if (atoi_f(temp.num, arr[i].num_arr, num_points + 1, 5, &ceng_shu) == 1) // ����������ײ�Ĵ�����Խ������
                {
                    arr[i].x = 1;
                }
                else
                {
                    arr[i].x = 0;
                }
                ceng[i] = ceng_shu;
                break;//���Ƴ���һ��ѭ�� 
            }
        }
        fclose(file); // �ر��ļ�

        if (arr[i].num_arr[0] == 5)
        {
            i++;
            continue;
        }

        // 6.�����ǲ��ǽ�������
        file = fopen("C:\\CODE\\word\\jieci.txt", "rt"); // ��ֻ��ģʽ���ļ�,file�Զ�ָ��ͷ
        if (file == NULL)
        {
           // perror("�޷����ļ�");
            return 0;
        }
        else
        {
            //printf("�ļ��ɹ���: D:\\jieci.txt\n");
        }

        while (!feof(file))
        {
            // ���⿪ʼ�ļ�ָ��ָ��հ�����
            do
            {
                c = fgetc(file); // �ļ�ָ������һ����λ
            } while (c != EOF && (c > '9' || c < '0')); // ������Ǳ���е�����
            if (c == EOF)
            {
                break;
            }
            fseek(file, -1, SEEK_CUR); // ��ԭ

            // ���ļ��е�%d.%f�ʹ���浽temp�ṹ����
            j = 0; // ���㣬�Ա��´�ʹ��
            while ((c = fgetc(file)) != EOF && ((c >= '0' && c <= '9') || c == '.'))  // �渡����
            {
                temp.num[j++] = c;
            }
            temp.num[j] = '\0'; // ����ַ���������

            k = 0; // ���㣬�Ա��´�ʹ��
            while (c != EOF && c < '0')  // �����
            {
                temp.phrase[k++] = c;
                c = fgetc(file);
            }
            temp.phrase[k] = '\0'; // ����ַ���������
            fseek(file, -1, SEEK_CUR); // ��ԭ

            if (strstr(temp.phrase, str[i]) != NULL)  // �ڶ��ʶ�Ӧ�ļ����ҵ���
            {
                int num_points = get_num(temp.num);//�����м�����


                if (atoi_f(temp.num, arr[i].num_arr, num_points + 1, 6, &ceng_shu) == 1) // ����������ײ�Ĵ�����Խ������
                {
                    arr[i].x = 1;
                }
                else
                {
                    arr[i].x = 0;
                }
                ceng[i] = ceng_shu;
                break;//���Ƴ���һ��ѭ�� 
            }
        }
        fclose(file); // �ر��ļ�

        if (arr[i].num_arr[0] == 6)
        {
            i++;
            continue;
        }


        // 7.�����ǲ��Ǵ��������
        file = fopen("C:\\CODE\\word\\daici.txt", "rt"); // ��ֻ��ģʽ���ļ�,file�Զ�ָ��ͷ
        if (file == NULL)
        {
           // perror("�޷����ļ�");
            return 0;
        }
        else
        {
            //printf("�ļ��ɹ���: D:\\daici.txt\n");
        }

        while (!feof(file))
        {
            // ���⿪ʼ�ļ�ָ��ָ��հ�����
            do
            {
                c = fgetc(file); // �ļ�ָ������һ����λ
            } while (c != EOF && (c > '9' || c < '0')); // ������Ǳ���е�����
            if (c == EOF)
            {
                break;
            }
            fseek(file, -1, SEEK_CUR); // ��ԭ

            // ���ļ��е�%d.%f�ʹ���浽temp�ṹ����
            j = 0; // ���㣬�Ա��´�ʹ��
            while ((c = fgetc(file)) != EOF && ((c >= '0' && c <= '9') || c == '.'))  // �渡����
            {
                temp.num[j++] = c;
            }
            temp.num[j] = '\0'; // ����ַ���������

            k = 0; // ���㣬�Ա��´�ʹ��
            while (c != EOF && c < '0')  // �����
            {
                temp.phrase[k++] = c;
                c = fgetc(file);
            }
            temp.phrase[k] = '\0'; // ����ַ���������
            fseek(file, -1, SEEK_CUR); // ��ԭ

            if (strstr(temp.phrase, str[i]) != NULL)  // �ڶ��ʶ�Ӧ�ļ����ҵ���
            {
                int num_points = get_num(temp.num);//�����м�����


                if (atoi_f(temp.num, arr[i].num_arr, num_points + 1, 7, &ceng_shu) == 1) // ����������ײ�Ĵ�����Խ������
                {
                    arr[i].x = 1;
                }
                else
                {
                    arr[i].x = 0;
                }
                ceng[i] = ceng_shu;
                break;//���Ƴ���һ��ѭ�� 
            }
        }
        fclose(file); // �ر��ļ�

        if (arr[i].num_arr[0] == 7)
        {
            i++;
            continue;
        }

        // 8.�����ǲ��������������
        file = fopen("C:\\CODE\\word\\shuliangci.txt", "rt"); // ��ֻ��ģʽ���ļ�,file�Զ�ָ��ͷ
        if (file == NULL)
        {
          //  perror("�޷����ļ�");
            return 0;
        }
        else
        {
            //printf("�ļ��ɹ���: D:\\shuliangci.txt\n");
        }

        while (!feof(file))
        {
            // ���⿪ʼ�ļ�ָ��ָ��հ�����
            do
            {
                c = fgetc(file); // �ļ�ָ������һ����λ
            } while (c != EOF && (c > '9' || c < '0')); // ������Ǳ���е�����
            if (c == EOF)
            {
                break;
            }
            fseek(file, -1, SEEK_CUR); // ��ԭ

            // ���ļ��е�%d.%f�ʹ���浽temp�ṹ����
            j = 0; // ���㣬�Ա��´�ʹ��
            while ((c = fgetc(file)) != EOF && ((c >= '0' && c <= '9') || c == '.'))  // �渡����
            {
                temp.num[j++] = c;
            }
            temp.num[j] = '\0'; // ����ַ���������

            k = 0; // ���㣬�Ա��´�ʹ��
            while (c != EOF && c < '0')  // �����
            {
                temp.phrase[k++] = c;
                c = fgetc(file);
            }
            temp.phrase[k] = '\0'; // ����ַ���������
            fseek(file, -1, SEEK_CUR); // ��ԭ

            if (strstr(temp.phrase, str[i]) != NULL) // ���ļ����ҵ���
            {
                int num_points = get_num(temp.num);//�����м�����


                if (atoi_f(temp.num, arr[i].num_arr, num_points + 1, 8, &ceng_shu) == 1) // ����������ײ�Ĵ�����Խ������
                {
                    arr[i].x = 1;
                }
                else
                {
                    arr[i].x = 0;
                }
                ceng[i] = ceng_shu;
                break;//���Ƴ���һ��ѭ��
            }
        }
        fclose(file); // �ر��ļ�

        if (arr[i].num_arr[0] == 8)
        {
            i++;
            continue;
        }


        i++; // ׼�������������ڶϾ�����һ���ɷֽ��б��
    }
		return arr;
}




/***************
    �������ƣ�atoi_f
    ����Ŀ�ģ���ȡ�ļ����Ѿ��ҵ��Ķ���ǰ���Ӧ�������ַ���������ת��Ϊ���飬�Ա��ڽ���Ŵ���PHR�ṹ���arr.num_arr��
    ���������� a���Ѿ��ҵ��Ķ���ǰ���Ӧ�������ַ���
               num_arr����PHR�ṹ����arr.num_arr���β�
               n�������ַ��������м���'.'
               ci_xing�����ʱ�Ϊ1�����ʱ�Ϊ2���ȵ�
               c����¼������м������֣�Ҳ���ǲ���
***************/
int atoi_f(char* a, int* num_arr, int n, int ci_xing, int* c)
{
    int i = 0, j = 0, k = 0;
    static char s1[5]; // �洢��һ��С����ǰ�����
    static char s2[5]; // �洢�ڶ���С����ǰ����� 

    num_arr[0] = ci_xing;
    *c = 2;
    // �洢��һ��С������ߵ�������ʾ����֮��ĵ�һ������
    while (a[i] != '.' && a[i] != '\0')
    {
        s1[j++] = a[i++];
    }
    s1[j] = '\0'; // ����ַ���������
    num_arr[1] = atoI(s1);

    for (k = 2; k <= n + 1; k++)
    {
        if (a[i] == '.' && a[i + 1] <= '9' && a[i + 1] >= '0') // ע�����в�����1.0�����
        {
            i++; // ��С��������ȥ
            j = 0;
            while (a[i] != '.' && a[i] != '\0')
            {
                s2[j++] = a[i++];
            }
            s2[j] = '\0'; // ����ַ���������
            num_arr[k] = atoI(s2);
            (*c)++;
        }
    }
    if (*c == n)
    {
        return 2;// �������˵��û�п�������������ģ�Ҳ�������Ƿ��������
    }
    else
    {
        return 1;// �������˵�������������ײ�Ĵ���,��Ҫһ���ϲ�������	
    }
}


/***************
�������ƣ�remark
����Ŀ�ģ��Ա���ŵ�PHR�ṹ��������мӹ�
����������str���Ͼ��Ķ������飨�ַ������飩
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
�������ƣ�get_num
����Ŀ�ģ���������������м����㣬Ҳ�����ڴʻ��������ڵڼ���
����������a���Ͼ��Ķ����Ӧ�������ַ���
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
�������ƣ�atoI
����Ŀ�ģ���ΪBC������û�������������atoi������ͬ
����������str�������ַ���
***************/
int atoI(const char* str) 
{
    int result = 0;
    int sign = 1;

    // �����հ��ַ�
    while (*str == ' ' || *str == '\t')
	{
        str++;
    }

    // �������
    if (*str == '-') 
	{
        sign = -1;
        str++;
    }
    else if (*str == '+') 
	{
        str++;
    }

    // ���ַ�ת��
    while (*str >= '0' && *str <= '9') 
	{
        result = result * 10 + (*str - '0');
        str++;
    }

    return sign * result;
}

PHR* input(char **word,char* biaohao)
{
    //�������
	int m;
	char shapowanyi[100]={0};
	int ceng[8];//�ֱ��¼��Ӧ������ʵ���
	char* inputArray[3]; // �������õ�ʱ����Ը���ʵ�������̬�����ڴ�,���ڼ�����8��

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
    // ����remark����
    //static PHR* phrases = remark(inputArray);
    PHR* phrases = remark(inputArray);
    for (i = 0; i < 1; i++)
	{
        if (phrases[i].num_arr[0] != 0)
        {
        	if(phrases[i].num_arr[3]==0)
        	{
				//printf("���: ");
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
    // �������
	int m;
	char shapowanyi[100]={0};
	int ceng[8];//�ֱ��¼��Ӧ������ʵ���
	char* inputArray[3]; // �������õ�ʱ����Ը���ʵ�������̬�����ڴ�,���ڼ�����8��
    
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
    // ����remark����
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
