
/*
**�ļ����ƣ�lasthao
**�ļ�Ŀ�ģ�ʵ�����յı�����
**ʱ�临�Ӷȣ�k1*����+k2*����
**�ռ临�Ӷȣ���Խ�Ϊ���ӣ���Ϊ���
*/

#include<stdio.h>
#include<lasthao.h>
#include<string.h>
#include<stdlib.h>
#include<alloc.h>
#include<stce.h>
#include<dos.h>
#include<num.h>
#include<trans12.h>

/*AC�Զ��� 
ZHUWEIBIN* lasthao(char* biaohao,char* input)
{
	//����˼·�����ɳ������ν���ĸ�ʽ�������㷨��װ
	ZHUWEIBIN* record=(ZHUWEIBIN*)malloc(5*sizeof(struct ZHUWEIBIN*));//����5���߼���ϵ
	//�������ռ���������Ĵ洢����
	char* temp=(char*)malloc(500);

	//����AC�Զ������ֵ�����������ִ��Ч�ʻ��Щ
	TrieNode* tree1=(TrieNode*)malloc(600);
	tree1=init_automation();
	TrieNode* tree2=(TrieNode*)malloc(600);
	tree2=init_automation_2();
	
	int counting=0;
	int i;
	Tense tense_,already_;
	int beibei;
	int dijiju=0;
	for(i=0;input[i]!='\0';i++)
	//ֱ����input��\0Ϊֹ
	//��֪ʶ���ո��ASC2����32���س���13��EOF��26��������0
	{
		if(input[i]==','||input[i]=='?')
		{
			counting=0;
			if(temp[0]!='\0')
			{
				//ִ�м�¼�����Ǹ��ṹ�����洢��
				//���ж���ص����
				tense_=tense(temp,tree1);
				already_=already(temp,tree2);
				beibei=beidong(temp);
				yijuhua(temp,tense_,already_,beibei,record+(dijiju++));//С��bug
			}
			memset(temp,0,sizeof(temp));
		}
		else
		{
			temp[counting++]=input[i];
		}
	}
	
	if(input[strlen(input)-1]!=','&&input[strlen(input)-1]!='?')
	{
		tense_=tense(temp,tree1);
		already_=already(temp,tree2);
		beibei=beidong(temp);
		//yijuhua(temp,tense_,already_,beibei,record+(dijiju++));//С��bug
	}
	
	free(tree1);
	free(tree2);
	return record;
}*/

void lasthao(char far* input,char far* fencihou,ZHUWEIBIN* record,char* biaohao)
{
	if(strlen(biaohao)==0)
	{
		return;
	}
	if(strcmp(biaohao,"2.1.96.")==0)
	{
		return;
	}
	//����˼·�����ɳ������ν���ĸ�ʽ�������㷨��װ
	//ZHUWEIBIN* record=(ZHUWEIBIN*)malloc(10*sizeof(struct ZHUWEIBIN*));//����5���߼���ϵ
	//�������ռ���������Ĵ洢����
	char* temp=(char*)malloc(300);
	int i=0;
	memset(temp,0,100);
	
	int j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<30;j++)
		{
			record[i].zhu[j]=0;
			record[i].wei[j]=0;
			record[i].bin[j]=0;
		}
	}

	//����AC�Զ������ֵ�����������ִ��Ч�ʻ��Щ
	//TrieNode* tree1=(TrieNode*)malloc(600);
	//tree1=init_automation();
	//TrieNode* tree2=(TrieNode*)malloc(600);
	//tree2=init_automation_2();
	
	int counting=0;
	Tense tense_,already_;
	int beibei;
	int dijiju=0;
	for(i=0;input[i]!='\0';i++)
	//ֱ����input��\0Ϊֹ
	//��֪ʶ���ո��ASC2����32���س���13��EOF��26��������0
	{
		if(input[i]==','||input[i]=='?')
		{
			counting=0;
			if(temp[0]!='\0')
			{
				//ִ�м�¼�����Ǹ��ṹ�����洢��
				//���ж���ص����
				tense_=tense(temp);
				already_=already(temp);
				beibei=beidong(temp);
				yijuhua(temp,tense_,already_,beibei,record+(dijiju++));//С��bug
			}
			memset(temp,0,300);
		}
		else
		{
			temp[counting++]=input[i];
		}
	}

	if(input[strlen(input)-1]!=','&&input[strlen(input)-1]!='?')
	{
		tense_=tense(temp);
		already_=already(temp);
		beibei=beidong(temp);
		yijuhua(fencihou,tense_,already_,beibei,record+(dijiju++));//С��bug
	}
	//strcpy(biaohao,fencihou);
	
	//strcpy(biaohao,"ţ��");//test
	
	free(temp);
	//free(tree1);
	//free(tree2);
	return;
}

void yijuhua(char* temp,Tense tense_,Tense already_,int beibei,ZHUWEIBIN* zhuweibin)
{
	//�ȸ���ά���鶯̬�����ڴ�ɣ�����
	//char** arr=(char**)malloc(10*sizeof(char*));
	//��ʾһ�£���һά���ǵڼ����ʣ��ڶ�ά��������ʵĵڼ����ַ�
	int i,j;
	char chayuan[7][50]={{0}};
	/*if(arr==NULL)
	{
		printf("�ڴ����ʧ���ˣ�");
		delay(2000);
		return;
	}
	for(i=0;i<10;i++)
	{
		arr[i]=(char*)malloc(50*sizeof(char));
		if(arr[i]==NULL)
		{
			printf("�ڴ����ʧ���ˣ�");
			return;
		}
	}*/
	char arr[7][50]={{0}};
	/*for(i=0;i<10;i++)
	{
		memset(arr[i],0,50);
	}*/
	//Ȼ�������
	int counting_2=0;
	int count_1=0;
	
	//for(i=0;temp[i]!='\0';i++)
	//����˵ɨ���temp�������ж�����
	{
		for(j=0;temp[j]!='\0';j++)
		//����˵ɨ��Ĺ����У��Ǹ��ַ�������ֹ�ַ�
		{
			if(temp[j]=='|')
			{
				counting_2=0;
				if(arr[count_1][0]!='\0')
				{
					count_1++;
				}
			}
			else
			{
				arr[count_1][counting_2]=temp[j];
				counting_2++;
			}
		}
	}
	
	
	//zhuweibin���ҽ���һ����phr���ǿ����кܶ��
	//���ݷֳ����Ĵʣ�������仰�ķ���~
	//����PHR�������
	
	//PHR* phr=(PHR*)malloc(10*sizeof(PHR));
	//for(i=0;i<10;i++)
	//{
	//	phr->str=(char*)malloc(50);
	//}
	//phr=remark(arr);
	
	//for(i=0;i<7;i++)
	for(i=0;i<7;i++)
	{
		trans12(arr[i],chayuan[i]);
	}
	
	int qinghua[50]={0};
	int huake[50]={0};
	int wuda[50]={0};
	char temppp[50]={0};
	int counttt=0;
	int mxz=0;
	for(i=0;i<7;i++)
	{
		for(j=0;j<50;j++)
		{
			if(chayuan[i][j]=='.'||chayuan[i][j]=='\0')
			{
				qinghua[i]=atoi(temppp);
				memset(temppp,0,50);
				break;
			}
			else
			{
				temppp[j]=chayuan[i][j];
			}
		}
	}
	for(i=0;i<7;i++)
	{
		for(j=0;j<50;j++)
		{
			if(chayuan[i][j]=='\0')
			{
				huake[i]=atoi(temppp);
				memset(temppp,0,50);
				break;
			}
			else if(chayuan[i][j]=='.'&&mxz==0)
			{
				mxz=1;
				counttt=j;
			}
			else if(chayuan[i][j]=='.'&&mxz==1)
			{
				huake[i]=atoi(temppp);
				memset(temppp,0,50);
				break;
			}
			else if(mxz==0)
			{
				;
			}
			else
			{
				temppp[j-counttt-1]=chayuan[i][j];
			}
		}
		mxz=0;
	}
	for(i=0;i<7;i++)
	{
		for(j=0;j<50;j++)
		{
			if(chayuan[i][j]=='\0')
			{
				wuda[i]=atoi(temppp);
				memset(temppp,0,50);
				break;
			}
			else if(chayuan[i][j]=='.'&&mxz==0)
			{
				mxz=1;
			}
			else if(chayuan[i][j]=='.'&&mxz==1)
			{
				mxz=2;
				counttt=j;
			}
			else if(chayuan[i][j]=='.'&&mxz==2)
			{
				wuda[i]=atoi(temppp);
				memset(temppp,0,50);
				break;
			}
			else if(mxz==0||mxz==1)
			{
				;
			}
			else
			{
				temppp[j-counttt-1]=chayuan[i][j];
			}
		}
		mxz=0;
	}
	
	//û��phr�����飡�����飡�����飡
	//������ʵ�Ľṹ�����ڶ���
	switch(tense_)
	{
		case TENSE_PAST:
			zhuweibin->wei[0]=TENSE_PAST;
			break;
		case TENSE_PRESENT:
			zhuweibin->wei[0]=TENSE_PRESENT;
			break;
		case TENSE_FUTURE:
			zhuweibin->wei[0]=TENSE_FUTURE;
			break;
	}
	switch(already_)
	{
		case TENSE_PAST:
			zhuweibin->wei[1]=TENSE_PAST;//���
			break;
		case TENSE_PRESENT:
			zhuweibin->wei[1]=TENSE_PRESENT;//����
			break;
		case TENSE_FUTURE:
			zhuweibin->wei[1]=TENSE_FUTURE;//Ҫȥ��
			break;
	}
	switch(beibei)
	{
		case 0:
			zhuweibin->wei[2]=0;//������
			break;
		case 1:
			zhuweibin->wei[2]=1;//������
			break;
	}
	switch(yiwen_gantan(temp))
	{
		case 0:
			zhuweibin->bin[2]=0;
			break;
		case 1:
			zhuweibin->bin[2]=1;
			break;
		case 2:
			zhuweibin->bin[2]=2;
			break;
		case 3:
			zhuweibin->bin[3]=3;
			break;
	}
	int num_he=0;
	int num_huo=0;
	int zhubin=ZHUYU;
	int fucishu=0;
	int adj=0;
	for(i=0;arr[i][0]!='\0';i++)
	{
		if(strcmp(arr[i],"��")==0||strcmp(arr[i],"����")==0||strstr(arr[i],"��")!=NULL)
		{
			num_he++;
			if(zhubin==BINYU)
			//������֮ǰ���������˼
			{
				zhubin=ZHUYU;
			}
			else
			{
				zhubin=BINYU;
			}
			continue;
		}
		else if(strcmp(arr[i],"��")==0||strcmp(arr[i],"����")==0||strcmp(arr[i],"�ֻ�")==0)
		{
			num_he++;
			if(zhubin==BINYU)
			{
				zhubin=ZHUYU;
			}
			else
			{
				zhubin=BINYU;
			}
			continue;
		}
		else if(qinghua[i]==1||qinghua[i]==5)
		{
			//Ŀǰ�ı�ŷ�ʽ�Ǽܹ��������ŷ�֮�ϵ�
			if(zhubin==ZHUYU)
			{
				//�����ͣ�����ô���ݴʴ���
				if(strcmp(arr[i-1],"��")==0||strcmp(arr[i-1],"����")==0||strstr(arr[i-1],"��")!=NULL)
				{
					for(j=3*adj-1;j>=0;j--)
					{
						zhuweibin->zhu[10+num_he*3+num_huo*3+3+j]=zhuweibin->zhu[10+num_he*3+num_huo*3+j];
					}
				}
				//���������������
				zhuweibin->zhu[7+num_he*3+num_huo*3]=qinghua[i];
				zhuweibin->zhu[8+num_he*3+num_huo*3]=huake[i];
				zhuweibin->zhu[9+num_he*3+num_huo*3]=wuda[i];
				zhubin=BINYU;
				/*
				�����Ҫ��3��ת��6໣�ǰ��ҲҪ��
				zhuweibin->zhu[10+num_he*3+num_huo*3]=phr->num_pre[0];
				zhuweibin->zhu[11+num_he*3+num_huo*3]=phr->num_pre[1];
				zhuweibin->zhu[12+num_he*3+num_huo*3]=phr->num_pre[2];
				//�������ã�������µı�ʾ������
				*/
			}
			else if(zhubin==BINYU)
			{
				//���ݴʰ��
				for(j=3*adj-1;j>=0;j--)
				{
					zhuweibin->zhu[10+num_he*3+num_huo*3+3+j]=zhuweibin->zhu[10+num_he*3+num_huo*3+j];
				}
				//��������
				zhuweibin->bin[7+num_he*3+num_huo*3]=qinghua[i];
				zhuweibin->bin[8+num_he*3+num_huo*3]=huake[i];
				zhuweibin->bin[9+num_he*3+num_huo*3]=wuda[i];
				zhubin=ZHUYU;
				/*
				�����Ҫ��3��ת��6໣�ǰ��ҲҪ��
				zhuweibin->bin[10+num_he*3+num_huo*3]=phr->num_pre[0];
				zhuweibin->bin[11+num_he*3+num_huo*3]=phr->num_pre[1];
				zhuweibin->bin[12+num_he*3+num_huo*3]=phr->num_pre[2];
				//�������ã�������µı�ʾ������
				*/
			}
		}
		else if(qinghua[i]==2)
		//����
		{
			zhuweibin->wei[6]=0;
			//�����滹�и��ĵĻ���
			zhuweibin->wei[7]=qinghua[i];
			zhuweibin->wei[8]=huake[i];
			zhuweibin->wei[9]=wuda[i];
			num_he=0;
			num_huo=0;
			//�ڶ�������Ϊ������׼��
		}
		else if(qinghua[i]==4)
		//����
		{
			fucishu++;
			zhuweibin->wei[3]=1;
			zhuweibin->wei[4]=fucishu;
			zhuweibin->wei[10+(fucishu-1)*3]=qinghua[i];
			zhuweibin->wei[11+(fucishu-1)*3]=huake[i];
			zhuweibin->wei[12+(fucishu-1)*3]=wuda[i];
		}
		else if(qinghua[i]==3)
		//���ݴ�
		{
			if(qinghua[i+1]==1||qinghua[i+1]==5||
			strcmp("��",arr[i])==0||strcmp("����",arr[i])==0||
			strstr(arr[i],"��")!=NULL||strcmp("Ҫô",arr[i])==0)
			//����˵��һ����������߱��������һЩ����Ŀ��ܳ��ֵĴ���
			{
				if(zhubin==ZHUYU)
				{
					zhuweibin->zhu[8+adj*3]=qinghua[i];
					zhuweibin->zhu[8+adj*3]=huake[i];
					zhuweibin->zhu[8+adj*3]=wuda[i];
					adj++;
				}
				else
				{
					zhuweibin->bin[8+adj*3]=qinghua[i];
					zhuweibin->bin[8+adj*3]=huake[i];
					zhuweibin->bin[8+adj*3]=wuda[i];
				}
			}
			else
			{
				if(zhubin==BINYU)
				{
					zhuweibin->wei[6]=1;
					zhuweibin->wei[7]=qinghua[i];
					zhuweibin->wei[8]=huake[i];
					zhuweibin->wei[9]=wuda[i];
					//û������Ҫ��ûɶ�õ�ԭ���ʸ��ǵ�
				}
			}
		} 
	}
	//���������ͷ��ڴ�~
	/*for(i=0;i<10;i++)
	{
		free(arr[i]);
	}
	free(arr);*/
}

int yiwen_gantan(char* str)
{
	//1����ʲô��2�Ǹ�̾��0������������3����ô��
	if(strstr(str,"ʲô")!=NULL)
	return 1;
	if(strstr(str,"ɶ")!=NULL)
	return 1;
	if(strstr(str,"��")!=NULL)
	return 3;
	if(strstr(str,"զ")!=NULL)
	return 3;
	if(strstr(str,"���")!=NULL)
	return 3;
	if(strstr(str,"��")!=NULL)
	return 2;
	if(strstr(str,"��")!=NULL)
	return 2;
	if(strstr(str,"�ܸ�ʲô")!=NULL)
	return 3;
	if(strstr(str,"�ܸ�ɶ")!=NULL)
	return 3;
	if(strstr(str,"ѽ")!=NULL)
	return 2;
	if(strstr(str,"����")!=NULL)
	return 1;
	if(strstr(str,"ԭ��")!=NULL)
	return 1;
	if(strstr(str,"����")!=NULL)
	return 3;
	if(strstr(str,"����")!=NULL)
	return 3;
	if(strstr(str,"����")!=NULL)
	return 3;
	if(strstr(str,"��")!=NULL)
	return 1;
	if(strstr(str,"�취")!=NULL)
	return 3;
	if(strstr(str,"����")!=NULL)
	return 3;
	return 0;
}
