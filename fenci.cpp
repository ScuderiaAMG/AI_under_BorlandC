
/*
** �������ƣ�interrupt
** ����Ŀ�ģ�ͨ���Ի���Ϣֵ��ȷ����ʵ�ֶϾ䡣
** ʱ�临�Ӷȣ�OH(����)
** �ռ临�Ӷȣ�OH(����)+6766
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<page.h>
#include<xiezi.h>
#include<color.h>

#define MI_VALUE 0.0000000000001
#define ROW_LENGTH 87921
#define EACH_LENGTH 13
#define INPUT_SIZE 10000
#define GB2312_NUMBER 6763

double mi_value(int i,int j)
{
	//���ļ� 
	FILE *fp;
	if((fp=fopen("C:\\CODE\\data\\tn","rt"))==NULL)
	{
		return -1;
	}
	//�ҵ�λ�ã���ȡ
	long long int calculate;
	calculate=i*ROW_LENGTH+j*EACH_LENGTH+1;
	//calculate=87919;
	fseek(fp,calculate,0);
	//��¼�ַ�����Ȼ����С��
	char record[12];
	for(i=0;i<12;i++)
	{
		record[i]=fgetc(fp);
	}
	record[12]='\0';
	double result;
	result=atof(record);
	fclose(fp);
	return result;
}


int fenci(char* input,char* eventual)
{
	char arr[GB2312_NUMBER][2];
	FILE *fp;
	int i;
	char zi5[5]={0};
	if((fp=fopen("C:\\CODE\\data\\GB2312","r"))==NULL)
	{
		return -1;
	}
	for(i=0;i<GB2312_NUMBER;i++)
	{
		for(int j=0;j<2;j++)
		{
			arr[i][j]=fgetc(fp);
		}
	}
	//int *count=(int*)malloc(INPUT_SIZE/2);
	int count[INPUT_SIZE/2];
	int counting=0;
	int flag=0;
	char temp[5];
	for(i=0;i<strlen(input);i+=2)
	{
		if(input[i]>0)//���ǲ��Ǻ��ֵ���˼
		{
			count[counting++]=0;//0�Ǳ�־���ӷֿ�
			//i--;
		}
		else
		{
			for(int j=0;j<GB2312_NUMBER;j++)
			{
				if(input[i]==arr[j][0])
				{
					if(input[i+1]==arr[j][1])
					{
						count[counting++]=j;//��󴢴�Ĵ�0��ʼ����
					}
				}
			}
		}
		flag++;
		//ÿִ��һ�麯����count���һ����flag��1,flag����ֵ����count����Ԫ�صĸ���
	}
	for(i=0;i<counting;i++)
	{
		printf("%d",count[i]);
		printf("\n");
	}
	for(i=0;i<strlen(input);i+=2)
	{
		if(input[i]>0)//���ǲ��Ǻ��ֵ���˼
		{
			count[counting++]=0;//0�Ǳ�־���ӷֿ�
			//i--;
		}
		else
		{
			for(int j=0;j<GB2312_NUMBER;j++)
			{
				if(input[i]==arr[j][0])
				{
					if(input[i+1]==arr[j][1])
					{
						count[counting++]=j;//��󴢴�Ĵ�0��ʼ����
					}
				}
			}
		}
		flag++;
		//ÿִ��һ�麯����count���һ����flag��1,flag����ֵ����count����Ԫ�صĸ���
	}
	
	int record=-2;
	counting=0;
	unsigned int char_code;
	//���濪ʼ�Ͼ������
	for(i=0;i<flag+1;i++)
	{
		//���ȫ�ϣ�����δ����Ӣ�ĺ�����
		if(input[record]>0)
		{
		 	record++;
		 	//printf("||,||");//�˴����ݻ����Ը��������
		 	strcat(eventual,"||");
			//    ||,||
		}
		//��һ�����Ǻ��֣��ڶ����Ǳ�㣬�����Ͳ��ں������
		else if(input[record]<0&&input[record+2]>=0)
		{
		 	record+=2;
		 	//printf("%c%c",input[record],input[record+1]);
		 	temp[0]=input[record];
		 	temp[1]=input[record+1];
		 	temp[2]='\0';
		 	strcat(eventual,temp);
		}
		else
		{
			//�����ֶ��Ǻ���
		 	record+=2;
		 	if(mi_value(count[counting],count[counting+1])==-1)
		 	{
			 	printf("�ٰ�һ�Σ������˳�");
			 	getchar();
			 	return 1;
			}
		 	if(mi_value(count[counting],count[counting+1])>=MI_VALUE)
		 	{
		 		//��Ӧ����һ�����
		 		zi5[0]=input[record];
		 		zi5[1]=input[record+1];
				if(strcmp(zi5,"��")==0||
				strcmp(zi5,"��")==0||
				strcmp(zi5,"˭")==0||
				strcmp(zi5,"ɶ")==0)
					//���������ڴʣ�����������������Ӧ�÷ֿ�
					//�������ң�����˳ƴ��ʣ�����Ϊ�����ǣ��������ּ����˳ƴ���
				{
					temp[0]=input[record];
					temp[1]=input[record+1];
					temp[2]='|';
					temp[3]='|';
					temp[4]='\0';
					strcat(eventual,temp);
				}
				else
				{
					zi5[0]=input[record+2];
					zi5[1]=input[record+3];
					if(strcmp(zi5,"��")==0||
					strcmp(zi5,"��")==0||
					strcmp(zi5,"˭")==0||
					strcmp(zi5,"ɶ")==0)
					{
						temp[0]=input[record];
						temp[1]=input[record+1];
						temp[2]='|';
						temp[3]='|';
						temp[4]='\0';
						strcat(eventual,temp);						
					}
					else
					{
						temp[0]=input[record];
						temp[1]=input[record+1];
						temp[2]='\0';
						strcat(eventual,temp);
					}
				}
			}
			else
			{
				//����Ӧ����һ�����
				//printf("%c%c||",input[record],input[record+1]);
				temp[0]=input[record];
				temp[1]=input[record+1];
				temp[2]='|';
				temp[3]='|';
				temp[4]='\0';
				strcat(eventual,temp);
			}
		}
		counting++;
	}
	fclose(fp);
	for(i=strlen(eventual)-1;i>=0;i--)
	{
		if(eventual[i]>=0)
		{
			eventual[i]='\0';
		}
		else
		{
			break;
		}
	}
	//printf("%s\n",eventual);
	return 0;
}
