
/*
**�ļ����ƣ�trans12
**�ļ�Ŀ�ģ�ʵ�ֵ�1��2�����ν�
**ʱ�临�Ӷȣ�k1*����+k2*����
**�ռ临�Ӷȣ�����������
*/

#include<stdio.h>
#include<string.h>
#include<trans12.h>
#include<alloc.h>
#include<stdlib.h>
#include<num.h>

void trans12(char *eventual,char *biaohao)
{
	memset(biaohao,0,sizeof(biaohao));
	int i=0,j=0,m=0;
	char temp[100]={0};
	int count=0;
	//char** str=(char**)malloc(1*sizeof(char*));
	//��ʾһ�£���һά���ǵڼ����ʣ��ڶ�ά��������ʵĵڼ����ַ�
	/*if(str==NULL)
	{
		printf("�ڴ����ʧ���ˣ�");
		//delay(2000);
		return;
	}
	for(i=0;i<1;i++)
	{
		str[i]=(char*)malloc(101*sizeof(char));
		if(str[i]==NULL)
		{
			printf("�ڴ����ʧ���ˣ�");
			return;
		}
	}*/
	char str[1][101]={0};
	/*for(i=0;i<1;i++)
	{
		memset(str[i],0,101);
	}*/
	int ceng[8]={0};
	char nownownow[100]={0};
	for(i=0;i<strlen(eventual);i++)
	{
		if(eventual[i]!='|'&&eventual[i]!=','&&eventual[i]!='?')
		{
			temp[count++]=eventual[i];
		}
		else if(eventual[i]=='|'&&eventual[i+1]=='|')
		{
			strcpy(str[0],temp);
			//strcat(biaohao,"��");
			for(j=0;j<1;j++)
			{
				//strcat(biaohao,"��");
				//PHR* structure=input(str,biaohao);//BC����structure�����Ҿͽ���structure
				input2(str,nownownow);
				if(nownownow[0]!='\0')
				{
					strcat(biaohao,nownownow);
				}
				//strcat(biaohao,".");//�����������һ��"."������"1.52.43."����
			}
		}
		else if(eventual[i]=='|'&&eventual[i+1]!='|')
		{
			for(m=0;m<100;m++)
			{
				temp[m]='\0';
				nownownow[m]='\0';
			}
			for(m=0;m<101;m++)
			{
				str[0][m]='\0';
			}
			count=0;
		}
		else
		{
			memset(temp,0,100);
			count=0;
			strcat(biaohao,",,");
		}
	}
	//if(biaohao[0]=='\0')
	{
		strcpy(str[0],temp);
		
		//for(j=0;j<remark(str)->record;j++)
		for(j=0;j<1;j++)
		{
			//strcat(biaohao,"��");
			//PHR* structure=input(str,biaohao);//BC����structure�����Ҿͽ���structure
			input2(str,nownownow);
			if(nownownow[0]!='\0')
			{
				strcat(biaohao,nownownow);
			}
			//strcat(biaohao,".");//�����������һ��"."������"1.52.43."����
			memset(temp,0,100);
			count=0;
		}
	}
	//strcpy(biaohao,str[0]);
}
//���ĸ�ʽ����sentence�ı����
