
/*
**�ļ����ƣ�logic
**�ļ�Ŀ�ģ�ʵ���߼����Ĵ 
**ʱ�临�Ӷȣ�\Theta (������)
**�ռ临�Ӷȣ�\Theta (������) 
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<alloc.h>
#include<lasthao.h>
#include<find.h>
#include<logic.h>

//�㷨�Ļ���˼·������"����ʻ�"�ĸ��������Ĵʻ���з���

//�������ƣ�virtual_word
//����Ŀ�ģ�ʵ������ʻ�ļܹ�

int virtual_word(ZHUWEIBIN* arr,ZHUWEIBIN* virtual_arr)
{
	//static ZHUWEIBIN virtual_arr[200];
	int jushu;
	for(jushu=0;;jushu++)
	{
		if(panduanNULL(arr[jushu])==0)
		{
			break;
		}
	}
	jushu=jushu-1;
	int i,j;
	for(i=0;i<jushu-1;i++)
	{
		for(j=0;j<40;j++)
		{
			virtual_arr[i].zhu[j]=arr[i].bin[j];
		}
	}
	//��һ��virtual_arr[jushu-1]�����ﲻ��
	return jushu;
}

//�������ƣ�virtual_logic
//����Ŀ�ģ�ʵ������ʻ��߼��ϵļܹ� 

void virtual_logic(ZHUWEIBIN* arr,ZHUWEIBIN* virtual_arr)
{
	int jushu=virtual_word(arr,virtual_arr);
	int i,j;
	for(i=0;i<jushu;i++)
	{
		int pronn=pron(arr[i]);
		if(pronn==1)
		{
			for(j=0;j<40;j++)
			{
				virtual_arr[jushu-1].zhu[j]=arr[i].bin[j];
				virtual_arr[jushu-1].wei[j]=arr[i].wei[j];
			}
		}
		else if(pronn==2)
		{
			for(j=0;j<40;j++)
			{
				virtual_arr[jushu-1].zhu[j]=arr[i].bin[j];
				virtual_arr[jushu-1].wei[j]=arr[i].wei[j];
			}
			//��ɱ��� 
			virtual_arr[jushu-1].wei[2]=1-virtual_arr[jushu-1].wei[2];
		}
	}
	//����̫����߼���������Ȼ�������ѩ��ЧӦ��2���Ǽ���
	int m;
	for(m=0;m<2;m++)
	{
		for(i=0;i<jushu-1;i++)
		{
			if(zhuweibin_same(virtual_arr[jushu-1].zhu,arr[i].zhu))
			{
				for(j=0;j<40;j++)
				{
					virtual_arr[jushu-1].zhu[j]=arr[i].bin[j];
					virtual_arr[jushu-1].wei[j]=arr[i].wei[j];
					//��¼��ν�����ʲô������virtual_arr��ν��ûɶ��
				}
			}
			else if(zhuweibin_same(virtual_arr[jushu-1].zhu,arr[i].bin))
			{
				for(j=0;j<40;j++)
				{
					virtual_arr[jushu-1].zhu[j]=arr[i].zhu[j];
					virtual_arr[jushu-1].wei[j]=arr[i].wei[j];
				}
				//��ɱ��� 
				virtual_arr[jushu-1].wei[2]=1-virtual_arr[jushu-1].wei[2];
			}
		}	
	}
}

//�������ƣ�zhuweibin_same
//����Ŀ�ģ��ж�ZHUWEIBIN���Ԫ���Ƿ���ͬ

int zhuweibin_same(int* arr1,int* arr2)
{
	int i,temp=0;
	for(i=0;i<40;i++)
	{
		if(arr1[i]!=arr2[i])
		{
			temp=1;
			break;
		}
	}
	return temp;
	//1��ͬ��0��ͬ 
} 

//�������ƣ�pron
//����Ŀ�ģ��жϾ��ӵ����Ƿ����ָ���Դ���

int pron(ZHUWEIBIN arr)
{
	if(arr.zhu[6]==5)
	{
		if(arr.zhu[7]==1)
		{
			if(arr.zhu[8]>=3&&arr.zhu[8]<=5)
			{
				return 1;
			}
			else if(arr.zhu[8]>=8&&arr.zhu[8]<=10)
			{
				return 1;
			}
			else if(arr.zhu[8]==16)
			{
				return 1;
			}
		}
	}
	if(arr.bin[6]==5)
	{
		if(arr.bin[7]==1)
		{
			if(arr.bin[8]>=3&&arr.bin[8]<=5)
			{
				return 2;
			}
			else if(arr.bin[8]>=8&&arr.bin[8]<=10)
			{
				return 2;
			}
			else if(arr.bin[8]==16)
			{
				return 2;
			}
		}
	}
	return 0;
	//0��û��,1����Ϊ����,2����Ϊ���� 
} 
