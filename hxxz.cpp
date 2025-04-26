
/*
** �������ƣ�GB2312����Ϣֵѵ������ main 
** �������ã�ѵ��GB2312����Ϣֵ���ݿ⣬��ò�ͬ���ּ�Ļ���Ϣֵ���Ӷ�Ϊ�����Ͼ�ִʴ��»����� 
** ʱ�临�Ӷȣ�������(6766+6766)
** �ռ临�Ӷȣ�6766��6767 
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>

#define GB_NUMBER 6763
#define INPUT_NUMBER 186962*2+1//����λ���������Ǻ���������2+1

void match(double num,char *array);

int main()
{
	int i,j,m;
	long long int jishu=0;
	//���ļ����价��
	FILE *fp;
	setlocale(LC_ALL, "zh_CN.gb2312");
	if((fp=fopen("D:\\BC\\DISK_C\\CODE\\data\\GB2312.txt","rt+"))==NULL)
	{
		printf("GB2312���ݿ��޷��򿪣�������˳�");
		getchar();
		exit(1);
	}
	FILE *fp2;
	setlocale(LC_ALL, "zh_CN.gb2312");
	if((fp2=fopen("D:\\BC\\DISK_C\\CODE\\train\\����Ϣֵѵ������.txt","rt+"))==NULL)
	{
		printf("Ŀ�����ݿ��޷��򿪣�������˳�");
		getchar();
		exit(1);
	}
	//����ѵ���ַ��������ö�̬�ڴ���� 
	char *arr=(char*)malloc(1000000*sizeof(char));
	if(arr==NULL)
	{
		printf("�ڴ����ʧ�ܣ�������˳�");
		getchar();
		exit(1);
	}
	FILE *fp3;
	if((fp3=fopen("D:\\BC\\DISK_C\\CODE\\data\\tn.txt","rt+"))==NULL)
	{
		printf("����Ϣֵѵ�������޷��򿪣�������˳�");
		getchar();
		exit(1);
	}
	for(i=0;!feof(fp2);i++)
	{
		arr[i]=fgetc(fp2);
	}
	//��������ڴ�ʵ�֣�double count[GB_NUMBER][GB_NUMBER+1]={0}; 
	double **count=(double**)malloc(GB_NUMBER*sizeof(double*));
	if(count==NULL)
	{
		printf("�ڴ����ʧ�ܣ�������˳�");
		getchar();
		return 1;
	}
	for(i=0;i<GB_NUMBER;i++) 
	{
		count[i]=(double*)malloc((GB_NUMBER+1)*sizeof(double));
		if(count[i]==NULL)
		{
			printf("�ڴ����ʧ�ܣ�������˳�");
			// �ͷ�֮ǰ������ڴ�
			for(j=0;j<i;j++)
			{
				free(count[j]);
			}
			free(count);
			getchar();
			return 1;
		}
	}
	for(i=0;i<GB_NUMBER;i++)
	{
		for(j=0;j<GB_NUMBER+1;j++)
		{
			count[i][j]=0;
		}
	}
	//���ϵ��£�count��Ӧ�ĺ�����ԭ�ļ���������˳����ͬ;
	//�����ң�count��Ӧ�ĺ�����ԭ�ļ���������˳����ͬ�����һ��������
	//ͳ�ƺ��ֳ��ֵĸ������Լ��������ֳ��ֵĸ���
	for(i=0;i<strlen(arr);i+=2)
	{//ÿ������ѭ��һ�Σ�����GB2312���֣���ASC2�벿�֣���Ӧ2 bites,���Բ�����2
		for(j=0;j<GB_NUMBER*2;j+=2)
		{
			fseek(fp,j,0);//���ļ�����һ������һ�����ֵ���
			char temp_char=fgetc(fp);
			char temp_char_after=fgetc(fp);//�ȹ̶�ס�ļ��к��ֶ�Ӧ�Ķ����Ʊ�ʾ
			if(temp_char==arr[i]&&temp_char_after==arr[i+1])
			{
				//������һ��ʱ�����Լ�¼������1��ά��
				count[j/2][GB_NUMBER]++;
				printf("%d\n",j);//debug
				//��������д���¸��ַ���ϵ���ã�����¸��ַ���\0,����Ȼû�µ�
				for(m=0;m<GB_NUMBER*2;m+=2)
				{
					fseek(fp,m,0);//����һ������һ�����ֵ���
					char temp_char_2=fgetc(fp);
					char temp_char_after_2=fgetc(fp);//�̶�
					if(temp_char_2==arr[i+2]&&temp_char_after_2==arr[i+3])
					{
						count[j/2][m/2]++;//������Ϣֵ��Ӧ�Ĳ���+1
						break;
					}
				}
				break;
			}
		}
	}
	fclose(fp2);
	fclose(fp);
	free(arr);
	//��һ������������ַ���Ӧ�ĳ���Ƶ��
	double sum=0;
	for(i=0;i<GB_NUMBER;i++)
	{
		sum+=count[i][GB_NUMBER];
	}
	
	//��һ�����������Ϣֵ������Ӧ��Ƶ�ʣ������滻
	for(i=0;i<GB_NUMBER;i++)
	{
		for(j=0;j<GB_NUMBER;j++)
		{
			if(count[i][GB_NUMBER]!=0)
			{
				count[i][j]/=count[i][GB_NUMBER];
			}
			else
			{
				count[i][j]=0;
			}
		}
	}
	for(i=0;i<GB_NUMBER;i++)
	{
		for(j=0;j<GB_NUMBER;j++)
		{
			if(count[j][GB_NUMBER]!=0)
			{
				count[i][j]/=count[j][GB_NUMBER];
			}
			else
			{
				count[i][j]=0;
			}
		}
	}
	for(i=0;i<GB_NUMBER;i++)
	{
		if(sum!=0)
		{
			count[i][GB_NUMBER]/=sum;
		}
		else
		{
			count[i][GB_NUMBER]=0;
		}
	}
	count[GB_NUMBER-1][GB_NUMBER]=1;
	
	//��һ�����ù̶��ĸ�ʽ��ӡ������Ҫ�Ļ���Ϣֵ���ݿ��� 
	char array[13];
	for(i=0;i<GB_NUMBER;i++)
	{
		fputs("{",fp3);
		match(count[i][0],array);
		fputs(array,fp3);
		for(j=1;j<GB_NUMBER;j++)
		{
			match(count[i][j],array);
			fputs(array,fp3);
		}
		fputs("}",fp3);
	}
	return 0;
}

void match(double num,char *array)
{
	int i;
	array[0]='0';
	array[1]='.'; 
	for(i=1;i<11;i++)
	{
		num*=10;
		array[i+1]=(int)num+'0';
		num-=(int)num;
	}
	array[12]=',';
	array[13]='\0';
}
