
/*
**�ļ����ƣ�find
**�ļ�Ŀ�ģ����lasthao���Ӧ���߼�����
**ʱ�临�Ӷȣ�k1*���ĸ߶�+k2*�������
**�ռ临�Ӷȣ�����
*/

#include<lasthao.h>
#include<stdio.h>
#include<string.h>
#include<alloc.h>
#include<stdlib.h>
#include<time.h>
#include<find.h>
#include<xiezi.h>
#include<page.h>
#include<dos.h>

//�������ƣ�find_logic
//����Ŀ�ģ�ʵ�ֵ������ӵ����ײ���
 
char* find_logic(ZHUWEIBIN arr,char* eventual,char* result)
{
	int i;
	FILE* fphhh;
	char temp;
	char rchar;
	int rrr;
	int counting=0;
	int cishu=0;
	char shuzu[400]={0};
	for(i=0;i<400;i++)
	{
		shuzu[i]='\0';
	}
	char weiyucici[50];
	char binyucici[50];
	memset(weiyucici,0,50);
	memset(binyucici,0,50);
	char transit[200]={0};
	char str[100]={0};
	int branch=panduanshenmeci(arr);
	strcpy(str,file_zhu(arr));
	
	char filechar;
	int suiji;
	int filenum=0;
	int zanghua=0;
	int sss=0;
	
	//char hahaha[100]={0};
	//itoa(arr.wei[1],hahaha,10);
	//strcpy(shuzu,str);
	//return shuzu;
	
	if(arr.zhu[7]<=0||arr.zhu[7]>11)
	{
		goto tiaoyixia;
	}
	
	fphhh=fopen(str,"rb");
	//delay(10);
	if(fphhh==NULL)
	{
		tiaoyixia:
		if(strstr(eventual,"�ҿ�")!=NULL)
		{
			strcpy(shuzu,"Ī˵�໰��");
			zanghua=10;
			sss=1;
		}
		else if(strstr(eventual,"ɵ��")!=NULL)
		{
			strcpy(shuzu,"Ī˵�໰��");
			zanghua=10;
		}
		else if(strstr(eventual,"�Ҳ�")!=NULL)
		{
			strcpy(shuzu,"Ī˵�໰��");
			zanghua=10;
			sss=1;
		}
		else if(strstr(eventual,"���")!=NULL)
		{
			strcpy(shuzu,"Ī˵�໰��");
			zanghua=10;
		}
		if(strstr(eventual,"����")!=NULL)
		{
			if(sss==1)
			{
				goto shelter;
			}
			replace(eventual,"����","���");
			strcpy(shuzu,eventual);
			replace(eventual,"���","����");
			//fclose(fphhh);
			return shuzu;
		}
		if(strstr(eventual,"��")!=NULL)
		{
			if(sss==1)
			{
				goto shelter;
			}
			if(strstr(eventual,"��")==NULL)
			{
				replace(eventual,"��","��");
				strcpy(shuzu,eventual);
				replace(eventual,"��","��");
				//fclose(fphhh);
				return shuzu;
			}
		}
		if(strstr(eventual,"��")!=NULL)
		{
			if(sss==1)
			{
				goto shelter;
			}
			if(strstr(eventual,"��")==NULL)
			{
				replace(eventual,"��","��");
				strcpy(shuzu,eventual);
				replace(eventual,"��","��");
				//fclose(fphhh);
				return shuzu;
			}
		}
		shelter:
		srand(time(0));
		suiji=rand()%5;
		if(suiji==0)
		{
			strcpy(shuzu,"��Ǹ��û���������˼");
		}
		else if(suiji==1)
		{
			strcpy(shuzu,"��һ˿û����");
		}
		else if(suiji==2)
		{
			strcpy(shuzu,"��˵��ɶ��ľ�и㶮");
		}
		else if(suiji==3)
		{
			strcpy(shuzu,"������СAI����������������Ļ���");
		} 
		else if(suiji==4)
		{
			strcpy(shuzu,"ɶ������û����");
		}
		if(fphhh!=NULL)
			fclose(fphhh);
		return shuzu;
	}
	

	
	//����������������
	if(branch==0)
	{
		if(strstr(eventual,"�ҿ�")!=NULL)
		{
			strcpy(shuzu,"�������������㲻Ҫ˵�໰��");
			zanghua=26;
		}
		else if(strstr(eventual,"ɵ��")!=NULL)
		{
			strcpy(shuzu,"�������������㲻Ҫ˵�໰��");
			zanghua=26;
		}
		else if(strstr(eventual,"�Ҳ�")!=NULL)
		{
			strcpy(shuzu,"�������������㲻Ҫ˵�໰��");
			zanghua=26;
		}
		else if(strcpy(eventual,"���")!=NULL)
		{
			strcat(shuzu,"�������������㲻Ҫ˵�໰��");
			zanghua=26;
		}
		
		//strcpy(shuzu,"branch=0");
		//return shuzu;
		
		if(strstr(eventual,"��")!=NULL)
		{
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0)
					{
						filenum=1;
					}
				}
				else if(filechar=='$'&&filenum==1)
				{
					fclose(fphhh);
					goto x;
				}
				if(filenum==1)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
		}
		
		if(strstr(eventual,"ʲô")!=NULL)
		{
			//memset(shuzu,0,500);
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0)
					{
						filenum=1;
						//exit(0);
					}
				}
				else if(filechar=='9'&&filenum==1)
				{
					fclose(fphhh);
					goto x1;
					break;
				}
				else if(filenum==1)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
		}
		
		else if(strstr(eventual,"��")!=NULL)
		{
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0||filenum==1)
					{
						filenum++;
					}
				}
				else if(filechar=='$'&&filenum==2)
				{
					fclose(fphhh);
					goto x;
				}
				else if(filenum==2)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
		}
		
		else if(strstr(eventual,"���")!=NULL)
		{
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0||filenum==1)
					{
						filenum++;
					}
				}
				else if(filechar=='$'&&filenum==2)
				{
					fclose(fphhh);
					goto x;
				}
				else if(filenum==2)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
		}
		
		else if(strstr(eventual,"զ")!=NULL)
		{
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0||filenum==1)
					{
						filenum++;
					}
				}
				else if(filechar=='$'&&filenum==2)
				{
					fclose(fphhh);
					goto x;
				}
				else if(filenum==2)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
			
			x:
				shuzu[strlen(shuzu)-1]='\0';
				return shuzu;
				
		}
		
		goto gogogo;
		//�����ֻ������
	}
	
	else if(branch==1)
	{
		if(strstr(eventual,"�ҿ�")!=NULL)
		{
			strcpy(shuzu,"�������������㲻Ҫ˵�໰��");
			zanghua=26;
		}
		else if(strstr(eventual,"ɵ��")!=NULL)
		{
			strcpy(shuzu,"�������������㲻Ҫ˵�໰��");
			zanghua=26;
		}
		else if(strstr(eventual,"�Ҳ�")!=NULL)
		{
			strcpy(shuzu,"�������������㲻Ҫ˵�໰��");
			zanghua=26;
		}
		else if(strstr(eventual,"���")!=NULL)
		{
			strcpy(shuzu,"�������������㲻Ҫ˵�໰��");
			zanghua=26;
		}
		
		//strcpy(shuzu,"branch=1");
		//return shuzu;
		
		if(strstr(eventual,"��")!=NULL)
		{
			//memset(shuzu,0,500);
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0)
					{
						filenum=1;
						//exit(0);
					}
				}
				else if(filechar=='9'&&filenum==1)
				{
					fclose(fphhh);
					goto x1;
					break;
				}
				else if(filenum==1)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
		}
		
		if(strstr(eventual,"ʲô")!=NULL)
		{
			//memset(shuzu,0,500);
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0)
					{
						filenum=1;
						//exit(0);
					}
				}
				else if(filechar=='9'&&filenum==1)
				{
					fclose(fphhh);
					goto x1;
					break;
				}
				else if(filenum==1)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
		}
		
		else if(strstr(eventual,"��")!=NULL)
		{
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0||filenum==1)
					{
						filenum++;
					}
				}
				else if(filechar=='$'&&filenum==2)
				{
					fclose(fphhh);
					goto x;
				}
				else if(filenum==2)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
		}
		
		else if(strstr(eventual,"���")!=NULL)
		{
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0||filenum==1)
					{
						filenum++;
					}
				}
				else if(filechar=='$'&&filenum==2)
				{
					fclose(fphhh);
					goto x;
				}
				else if(filenum==2)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
		}
		
		else if(strstr(eventual,"զ")!=NULL)
		{
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0||filenum==1)
					{
						filenum++;
					}
				}
				else if(filechar=='$'&&filenum==2)
				{
					fclose(fphhh);
					goto x;
				}
				else if(filenum==2)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
			
			x1:
				shuzu[strlen(shuzu)-1]='\0';
				//fclose(fphhh);
				return shuzu;
				
		}
		
		goto gogogo;
	}
	
	else
	{
		gogogo:
		
		if(strstr(eventual,"�ҿ�")!=NULL)
		{
			strcpy(shuzu,"�������������㲻Ҫ˵�໰��");
			zanghua=26;
		}
		else if(strstr(eventual,"ɵ��")!=NULL)
		{
			strcpy(shuzu,"�������������㲻Ҫ˵�໰��");
			zanghua=26;
		}
		else if(strstr(eventual,"�Ҳ�")!=NULL)
		{
			strcpy(shuzu,"�������������㲻Ҫ˵�໰��");
			zanghua=26;
		}
		else if(strstr(eventual,"���")!=NULL)
		{
			strcpy(shuzu,"�������������㲻Ҫ˵�໰��");
			zanghua=26;
		}
			
		if(strstr(eventual,"��")!=NULL)
		{
			//memset(shuzu,0,500);
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0)
					{
						filenum=1;
						//exit(0);
					}
				}
				else if(filechar=='9'&&filenum==1)
				{
					fclose(fphhh);
					//shuzu[strlen(shuzu)-1]='\0';
					goto x1;
					break;
				}
				else if(filenum==1)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
		}
		
		if(strstr(eventual,"ʲô")!=NULL)
		{
			//memset(shuzu,0,500);
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0)
					{
						filenum=1;
						//exit(0);
					}
				}
				else if(filechar=='9'&&filenum==1)
				{
					fclose(fphhh);
					goto x1;
					break;
				}
				else if(filenum==1)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
		}
		
		if(strstr(eventual,"��")!=NULL)
		{
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0||filenum==1)
					{
						filenum++;
					}
				}
				else if(filechar=='$'&&filenum==2)
				{
					fclose(fphhh);
					goto x2;
				}
				else if(filenum==2)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
			
			x2:
				shuzu[strlen(shuzu)-1]='\0';
				//fclose(fphhh);
				return shuzu;
		}
		
		if(strstr(eventual,"���")!=NULL)
		{
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0||filenum==1)
					{
						filenum++;
					}
				}
				else if(filechar=='$'&&filenum==2)
				{
					fclose(fphhh);
					goto x3;
				}
				else if(filenum==2)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
			
			x3:
				shuzu[strlen(shuzu)-1]='\0';
				//fclose(fphhh);
				return shuzu;
		}
		
		if(strstr(eventual,"զ")!=NULL)
		{
			while(1)
			{
				filechar=fgetc(fphhh);
				if(filechar=='5')
				{
					if(filenum==0||filenum==1)
					{
						filenum++;
					}
				}
				else if(filechar=='$'&&filenum==2)
				{
					fclose(fphhh);
					goto x4;
				}
				else if(filenum==2)
				{
					shuzu[strlen(shuzu)]=filechar;
					//shuzu[strlen(shuzu)]='\0';
				}
			}
			
			x4:
				shuzu[strlen(shuzu)-1]='\0';
				//fclose(fphhh);
				return shuzu;
		}
		
		memset(shuzu,0,400);
		//��ν�б���޷��ǹ۲����ʵ���ϵ
		if(arr.bin[2]==1)
		{
			while(1)
			{
				temp=fgetc(fphhh);
				if(strstr(str,"$")==NULL)
				{
					if(temp=='$')
					{
						strcat(str,"$");
					}
					continue;
				}
				if(strstr(str,"$")!=NULL&&strstr(str,"$9")==NULL)
				{
					if(temp=='9')
					{
						strcat(str,"9");
					}
					else
					{
						str[0]='\0';
					}
					continue;
				}
				if(strstr(str,"$9")!=NULL&&strstr(str,"$98")==NULL)
				{
					if(temp=='8')
					{
						strcat(str,"8");
					}
					else
					{
						str[0]='\0';
						str[1]='\0';
					}
					continue;
				}
				if(strstr(str,"$98")!=NULL&&strstr(str,"$985")==NULL)
				{
					if(temp=='5')
					{
						str[0]='\0';
						str[1]='\0';
						str[2]='\0';
						break;
					}
					else
					{
						str[0]='\0';
						str[1]='\0';
						str[2]='\0';
						continue;
					}
				}
				if(feof(fphhh))
				{
					break;
				}
			}
			while(1)
			{
				temp=fgetc(fphhh);
				if(temp=='$')
				{
					counting=0;
					break;
				}
				else
				{
					result[counting++]=temp;
				}
				if(feof(fphhh))
				{
					break;
				}
			}
			strcpy(shuzu,result);
			fclose(fphhh);
			return shuzu;
		}
		//��ô������
		else if(arr.bin[2]==3)
		{
			while(1)
			{
				temp=fgetc(fphhh);
				if(strstr(str,"$")==NULL)
				{
					if(temp=='$')
					{
						strcat(str,"$");
					}
					continue;
				}
				if(strstr(str,"$")!=NULL&&strstr(str,"$9")==NULL)
				{
					if(temp=='9')
					{
						strcat(str,"9");
					}
					else
					{
						str[0]='\0';
					}
					continue;
				}
				if(strstr(str,"$9")!=NULL&&strstr(str,"$98")==NULL)
				{
					if(temp=='8')
					{
						strcat(str,"8");
					}
					else
					{
						str[0]='\0';
						str[1]='\0';
					}
					continue;
				}
				if(strstr(str,"$98")!=NULL&&strstr(str,"$985")==NULL)
				{
					if(temp=='5')
					{
						if(cishu==0)
						{
							str[0]='\0';
							str[1]='\0';
							str[2]='\0';
							cishu++;
						}
						else
						{
							cishu=0;
							str[0]='\0';
							str[1]='\0';
							str[2]='\0';
							break;
						}
					}
					else
					{
						str[0]='\0';
						str[1]='\0';
						str[2]='\0';
						continue;
					}
				}
				if(feof(fphhh))
				{
					break;
				}
			}
			while(1)
			{
				temp=fgetc(fphhh);
				if(temp=='$')
				{
					counting=0;
					break;
				}
				else
				{
					result[counting++]=temp;	
				}
				if(feof(fphhh))
				{
					break;
				}
			}
			strcpy(shuzu,result);
			fclose(fphhh);
			return shuzu;
		}
		//��������
		else
		{
			while(1)
			{
				temp=fgetc(fphhh);
				
				if(feof(fphhh))
				{
					goto shelter;
					break;
				}
				
				if(strstr(str,"$")==NULL)
				{
					if(temp=='$')
					{
						strcat(str,"$");
					}
					//goto shelter;
					continue;
				}
				if(strstr(str,"$")!=NULL&&strstr(str,"$9")==NULL)
				{
					if(temp=='9')
					{
						strcat(str,"9");
					}
					else
					{
						str[0]='\0';
					}
					//goto shelter;
					continue;
				}
				if(strstr(str,"$9")!=NULL&&strstr(str,"$98")==NULL)
				{
					if(temp=='8')
					{
						strcat(str,"8");
					}
					else
					{
						str[0]='\0';
						str[1]='\0';
					}
					//goto shelter;
					continue;
				}
				if(strstr(str,"$98")!=NULL&&strstr(str,"$985")==NULL)
				{
					if(temp=='5')
					{
						if(cishu==0||cishu==1)
						{
							str[0]='\0';
							str[1]='\0';
							str[2]='\0';
							cishu++;
							//goto shelter;
							continue;
						}
						else
						{
							cishu=0;
							str[0]='\0';
							str[1]='\0';
							str[2]='\0';
							//goto shelter;
							break;
						}
					}
					else
					{
						str[0]='\0';
						str[1]='\0';
						str[2]='\0';
						//goto shelter;
						continue;
					}
				}
			}
			strcpy(weiyucici,weiyuci(arr));
			FILE *fphhhwei;
			fphhhwei=fopen(weiyucici,"rt+");
			if(fphhhwei==NULL)
			{
				goto shelter;
			}
			char weiyurecord[50]={0};
			int hhh;
			char hhhwei;
			for(hhh=0;;hhh++)
			{
				hhhwei=fgetc(fphhhwei);
				if(hhhwei!='$')
				{
					weiyurecord[hhh]=hhhwei;
				}
				else
				{
					break;
				}
			}
			
			strcpy(weiyucici,weiyurecord);
			
			//����ɹ���ָ�����������Ĳ���
			while(1)
			{
				temp=fgetc(fphhh);
				//�˴���ı�һ�£�������Ǹ��ĳɱ���
				if(strstr(str,"-")==NULL)
				{
					if(temp=='-')
					{
						strcat(str,"-");
					}
					continue;
				}
				if(strstr(str,"-=")==NULL&&strstr(str,"-")!=NULL)
				{
					if(temp=='=')
					{
						strcat(str,"=");
					}
					else
					{
						str[0]='\0';
					}
					continue;
				}
				if(strstr(str,"-=")!=NULL&&strstr(str,"-=+")==NULL)
				{
					if(temp=='+')
					{
						strcat(str,"+");
						continue;
					}
					else
					{
						result[counting++]=temp;
						//result[counting++]='\0';
						continue;
					}
				}
				if(strstr(str,"-=+")!=NULL&&strstr(str,"-=+=")==NULL)
				{
					if(temp=='='&&!feof(fphhh))
					{
						result[counting++]='\0';
						
						if(strstr(weiyucici,result)!=NULL)
						{
							rrr=0;
							while(1)
							{
								rchar=fgetc(fphhh);
								if(rchar!='-')
								{
									shuzu[rrr++]=rchar;
								}
								else
								{
									shuzu[rrr]='\0';
									break;
								}
							}
							fclose(fphhh);
							fclose(fphhhwei);
							return shuzu;
						}
						//result[counting++]=temp;
						//continue;
					}
					else if(feof(fphhh))//�����ļ�ĩβ
					{
						//��Ϊ�쳣��������б�ǣ���Ϊ����Ϊ�� 
						int j;
						shuzu[0]=1;
						shuzu[1]=1;
						shuzu[2]=4;
						shuzu[3]=5;
						shuzu[4]=1;
						shuzu[5]=4;
						goto shelter;
						break;
					}
					else
					{
						str[0]='\0';
						str[1]='\0';
						str[2]='\0';
						memset(result,0,sizeof(result));
						continue;
					}
				}/*
				if(strstr(str,"-=+=")!=NULL&&strstr(str,"-=+=-")==NULL)
				{
					if(temp=='-'&&!feof(fphhh))
					{
						strcat(str,"-");
						continue;
					}
					else if(feof(fphhh))
					{
						if(strcmp(weiyucici,result)==0)
						{
							strcpy(shuzu,result);
						}
						else
						{
							//û�ҵ��ʵĻ�......
							goto shelter;
						}
						break;
					}
					else
					{
						result[counting++]=temp;
						continue;
					}
				}
				if(strstr(str,"-=+=-")!=NULL)
				{
					if(temp=='=')
					{
						int j;
						for(j=2;j<6;j++)
						{
							str[j]='\0';
						}
						//ע����һ�λ�����str[0]��str[1]�أ�
						if(strcmp(result,weiyucici)==0)
						{
							strcpy(shuzu,result);
							memset(result,0,sizeof(result));
							break;
						}
						else
						{
							counting=0;
							continue;
						}
					}
					else
					{
						str[4]='\0';
						result[counting++]='-';
						result[counting++]=temp;
					}
				}*/
			}
		}
		//���ϵĻ��������ǣ����治����-=,+=���ŵ���������
		fclose(fphhh);

		return shuzu;
	}
	fclose(fphhh);
	return shuzu;
}

//�������ƣ�file_zhu
//����Ŀ�ģ��ó�������ļ���

char* file_zhu(ZHUWEIBIN arr)
{
	char str1[100];
	char str2[100];
	char str3[100];
	char str4[100];
	itoa(arr.zhu[7],str2,10);
	itoa(arr.zhu[8],str3,10);
	itoa(arr.zhu[9],str4,10);
	strcpy(str1,"C:\\CODE\\inf\\");
	strcat(str1,str2);
	strcat(str1,"\\");
	strcat(str1,str2);
	strcat(str1,"-");
	strcat(str1,str3);
	strcat(str1,"\\");
	strcat(str1,str2);
	strcat(str1,"-");
	strcat(str1,str3);
	strcat(str1,"-");
	strcat(str1,str4);
	strcat(str1,".txt");
	return str1;
}

//�������ƣ�file_wei
//����Ŀ�ģ��ó�ν����ļ��� 

char* file_wei(ZHUWEIBIN arr)
{
	char str11[100];
	char str2[100];
	char str3[100];
	char str4[100];	
	itoa(arr.wei[6],str2,10);
	itoa(arr.wei[7],str3,10);
	itoa(arr.wei[8],str4,10);
	strcpy(str11,"C:\\CODE\\inf\\");
	strcat(str11,str2);
	strcat(str11,"\\");
	strcat(str11,str2);
	strcat(str11,"-");
	strcat(str11,str3);
	strcat(str11,"\\");
	strcat(str11,str2);
	strcat(str11,"-");
	strcat(str11,str3);
	strcat(str11,"-");
	strcat(str11,str4);
	strcat(str11,".txt");
	return str11;
}

//�������ƣ�file_bin 
//����Ŀ�ģ��ó�������ļ��� 

char* file_bin(ZHUWEIBIN arr)
{
	char str111[100];
	char str2[100];
	char str3[100];
	char str4[100];
	itoa(arr.zhu[6],str2,10);
	itoa(arr.zhu[7],str3,10);
	itoa(arr.zhu[8],str4,10);
	strcpy(str111,"C:\\CODE\\inf\\");
	strcat(str111,str2);
	strcat(str111,"\\");
	strcat(str111,str2);
	strcat(str111,"-");
	strcat(str111,str3);
	strcat(str111,"\\");
	strcat(str111,str2);
	strcat(str111,"-");
	strcat(str111,str3);
	strcat(str111,"-");
	strcat(str111,str4);
	strcat(str111,".txt");
	return str111;
}

//�������ƣ�weiyuci 
//����Ŀ�ģ��ó�ν��ʱ�Ŷ�Ӧ��char*�ַ��� 

char* weiyuci(ZHUWEIBIN arr)
{
	static char temp1[50];
	memset(temp1,0,50);
	char shuzu1[50];
	char shuzu2[50];
	char shuzu3[50];
	itoa(arr.wei[7],shuzu1,10);
	itoa(arr.wei[8],shuzu2,10);
	itoa(arr.wei[9],shuzu3,10);
	strcpy(temp1,"C:\\CODE\\inf\\");
	strcat(temp1,shuzu1);
	strcat(temp1,"\\");
	strcat(temp1,shuzu1);
	strcat(temp1,"-");
	strcat(temp1,shuzu2);
	strcat(temp1,"\\");
	strcat(temp1,shuzu1);
	strcat(temp1,"-");
	strcat(temp1,shuzu2);
	strcat(temp1,"-");
	strcat(temp1,shuzu3);
	strcat(temp1,".txt");
	return temp1;
}

//�������ƣ�binyuci 
//����Ŀ�ģ��ó�����ʱ�Ŷ�Ӧ��char*�ַ���

char* binyuci(ZHUWEIBIN arr)
{
	static char temp1[50];
	memset(temp1,0,50);
	char shuzu1[50];
	char shuzu2[50];
	char shuzu3[50];
	itoa(arr.wei[6],shuzu1,10);
	itoa(arr.wei[7],shuzu2,10);
	itoa(arr.wei[8],shuzu3,10);
	strcpy(temp1,"C:\\CODE\\inf\\");
	strcat(temp1,shuzu1);
	strcat(temp1,"\\");
	strcat(temp1,shuzu1);
	strcat(temp1,"-");
	strcat(temp1,shuzu2);
	strcat(temp1,"\\");
	strcat(temp1,shuzu1);
	strcat(temp1,"-");
	strcat(temp1,shuzu2);
	strcat(temp1,"-");
	strcat(temp1,shuzu3);
	strcat(temp1,".txt");
	return temp1;
}

//�������ƣ�panduanNULL 
//����Ŀ�ģ��ж�һ������������û�пյĲ���

int panduanNULL(ZHUWEIBIN arr)
{
	//1�Ƿǿգ�0�ǿ� 
	int i;
	for(i=0;i<40;i++)
	{
		if(arr.zhu[i]!=0)
		{
			return 1;
		}
	}
	for(i=0;i<40;i++)
	{
		if(arr.wei[i]!=0)
		{
			return 1;
		}
	}
	for(i=0;i<40;i++)
	{
		if(arr.bin[i]!=0)
		{
			return 1;
		}
	}
	return 0;
}

//�������ƣ�shenmeci 
//����Ŀ�ģ�ֱ�Ӳ������Ӧ��ν��/����� 

char* shenmeci(ZHUWEIBIN arr)
{
	int temp=0,i;
	for(i=0;i<40;i++)
	{
		if(arr.bin[i]!=0)
		{
			temp=1;
		}
	}
	if(temp==1)
	{
		static char tempp[50];
		strcpy(tempp,weiyuci(arr));
		return tempp;
		//����ν��� 
	}
	if(temp==0)
	{
		static char tempp[50];
		strcpy(tempp,binyuci(arr));
		return tempp;
		//���ұ���� 
	}
}

//�������ƣ�panduanshenmeci
//����Ŀ�ģ�ͨ��һ����������ĳЩ���ִʿղ��գ��������ж�

int panduanshenmeci(ZHUWEIBIN arr)
{
	int temp=0,i,tteemmpp=0;
	for(i=0;i<30;i++)
	{
		if(arr.bin[i]!=0)
		{
			temp=1;
		}
	}
	for(i=0;i<30;i++)
	{
		if(arr.wei[i]!=0)
		{
			tteemmpp=1;
		}
	}
	if(temp==0&&tteemmpp==0)
	{
		return 0;
		//ֻ������
	}
	if(temp==0&&tteemmpp==1)
	{
		return 1;
		//��ν��ޱ���
	}
	if(temp==1&&tteemmpp==0)
	{
		return 2;
		//�б����ν��
	}
	if(temp==1&&tteemmpp==1)
	{
		return 3;
		//�б����ν��
	}
}

void replace(char *str,const char *s1,const char *s2)
{
	int i;
	int size1 = strlen(s1), size2 = strlen(s2);
	int delta = size2 - size1;
	char *pfind = strstr(str, s1);
	char *p;
	
	while(pfind)
	{
		//�ƶ��滻λ��֮����ַ���Ϊ�滻�ַ��������ռ�
		//��ǰ/����ƶ�ʱ��pָ���ƶ�����ͬ��
		if(delta>0)
		{
			for(p=str+strlen(str);p>=pfind+size1;p--)
			{
				*(p+delta)=*p;
			}
		}
		else if(delta<0)
		{
			for(p=pfind+size1;p<=str+strlen(str);p++)
			{
				*(p+delta)=*p;
			}
		}
		
		for(i=0;i<size2;i++)
		{
			*(pfind+i)=*(s2+i);
		}
		
		pfind=strstr(pfind+1,s1);
	}
}
