
/*
**�ļ����ƣ�detect
**�ļ�Ŀ�ģ������û���������͵��ַ����ı䣬��¼����
**ʱ�临�Ӷȣ������������������ַ���
**�ռ临�Ӷȣ������������������ַ���
*/

#include<stdio.h>
#include<string.h>
#include<detect.h>

//������ӿո񣬱��������ַ��Ĵ����ո���ȥ����Ϊ��ţ����������
int detect(char* input,int* strategy)
{
	int sum=0;
	*strategy=CHINESE;
	int length=strlen(input);
	int i,j;
	for(i=0;i<length;i++)
	{
		if(input[i]<0)
		{
			continue;
		}
		else if(input[i]>='0'&&input[i]<='9')
		{
			sum++;
			*strategy=CALCULATE;
			//�������������ظ�һ�飬����ӦGB2312���ֽ���
			//strcpy(input,"����������������������������������������");//test
			/*
			input[length+1]='\0';
			for(j=length-1;j>=i+1;j--)
			{
				input[j+1]=input[j];
			}
			input[i+1]=input[i];
			length++;
			*/
		}
		else if(input[i]=='+'||input[i]=='='||input[i]=='-'||input[i]=='*'||input[i]=='/')
		{
			sum++;
			*strategy=CALCULATE;
		}
		else if((input[i]>='a'&&input[i]<='z')||(input[i]>='A'&&input[i]<='Z'))
		{
			//strcpy(input,"����Ӣ�");//test
			sum++;
			//*strategy=ENGLISH;
			//��Ӣ����ĸ�ظ�һ�飬����ӦGB2312���ֽ���
			/*
			input[length+1]=0;
			for(j=length-1;j>=i+1;j--)
			{
				input[j+1]=input[j];
			}
			input[i+1]=input[i];
			length++;
			*/
		} 
	}
	return sum;//����ASC2�ַ�������
}

int ddetect(char* input)
{
	int length=strlen(input);
	int i,j;
	for(i=0;i<length;i++)
	{
		if(input[i]<0)
		{
			continue;
		}
		else
		{
			input[length+1]='\0';
			for(j=length-1;j>=i+1;j--)
			{
				input[j+1]=input[j];
			}
			input[i+1]=input[i];
			length++;			
		}
	}
}
