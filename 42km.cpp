
/*
**�ļ����ƣ�42km
**�ļ�Ŀ�ģ�C���������̣����ȫ������ 
**ʱ�临�Ӷȣ����������� 
**�ռ临�Ӷȣ����������� 
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<alloc.h>
#include<jisuan.h>
#include<42km.h>
#include<detect.h>
#include<math.h>

int calculate_all(char* input,int strategy,char* input2)
{
	long long int shuzi1;
	long long int shuzi2;
	long long int shuzi3;
	double shuzi4;
	int bansui=0;
	int jishu=0;
	int s,t;
	int status=0;
	int records=0;
	int recordt=0;
	char ccc[400]={0};
	char c1[100]={0};
	char c2[100]={0};
	char c3[100]={0};
	char c4[100]={0};
	if(strategy==CALCULATE)
	{
		int length=strlen(input);
		if(strstr(input,"��")!=NULL)
		{
			status=ADD;
			goto x;
		}
		if(strstr(input,"��")!=NULL)
		{
			status=SUB;
			goto x;
		}
		if(strstr(input,"��")!=NULL)
		{
			status=MUL;
			goto x;
		}
		if(strstr(input,"��")!=NULL)
		{
			status=DIV;
			goto x;
		}
		if(strstr(input,"��")!=NULL)
		{
			status=DIV;
			goto x;
		}
		if(strstr(input,"����")!=NULL)
		{
			status=ZUIDAGONGYUE;
			goto x;
		}
		if(strstr(input,"����")!=NULL)
		{
			status=ZUIXIAOGONGBEI;
			goto x;
		}
		if(strstr(input,"Լ��")!=NULL)
		{
			status=ZUIDAGONGYUE;
			goto x;
		}
		if(strstr(input,"����")!=NULL)
		{
			status=PRIME;
			goto x;
		}
		if(strstr(input,"����")!=NULL)
		{
			status=PRIME;
			goto x;
		}
		if(strstr(input,"����")!=NULL)
		{
			status=PRIME;
			goto x;
		}
		if(strstr(input,"+")!=NULL)
		{
			status=ADD;
			goto x;
		}
		if(strstr(input,"-")!=NULL)
		{
			status=SUB;
			goto x;
		}
		if(strstr(input,"*")!=NULL)
		{
			status=MUL;
			goto x;
		}
		if(strstr(input,"/")!=NULL)
		{
			status=DIV;
			goto x;
		}
		if(strstr(input,"����")!=NULL)
		{
			status=SQRT;
			goto x;
		}
		//��ת��ֱ�Ӽ���1�����ң�һ�����Ӧ�ø���
		x:char calculate_array[30][50]={0};
		char result[54]={0};
		char rresult[54]={0};
		char ALU[30]={0};
		char temp[50]={0};
		int final=0;
		int wwhhaatt;
		int ALU_counter=0;
		int calculate_array_pointer=0;
		int calculate_array_after=0;
		int hhh=0;
		int i,j;
		int m;
		int recorddot=0;
		char ttemp[80]={0};
		switch(status)
		{
			case ADD:
			case SUB:
			case MUL:
			case DIV:
				for(i=0;i<length;i++)
				{
					if(input[i]>='0'&&input[i]<='9')
					{
						calculate_array[calculate_array_pointer][calculate_array_after++]=input[i];
						hhh=1;
						if(i+1==length)
						{
							calculate_array_pointer++;
							hhh=0;
						}
					}
					else if(input[i]=='.')
					{
						if(calculate_array_after!=0&&input[i+1]>='0'&&input[i+1]<='9')
						{
							calculate_array[calculate_array_pointer][calculate_array_after++]=input[i];
							hhh=1;
						}
					}
					else
					{
						if(hhh==1)
						{
							hhh=0;
							calculate_array_pointer++;
							calculate_array_after=0;
						}
						else if(hhh==2)
						{
							hhh=0;
						}
					}	
					switch(input[i])
					{
						case '+':
							hhh=2;
							ALU[ALU_counter++]=ADD;
							jishu=1;
							break;
						case '-':
							hhh=2;
							ALU[ALU_counter++]=SUB;
							jishu=1;
							break;
						case '*':
							hhh=2;
							ALU[ALU_counter++]=MUL;
							jishu=1;
							break;
						case '/':
							hhh=2;
							ALU[ALU_counter++]=DIV;
							jishu=1;
							break;
						default:
							break;
					}
					if(jishu==1)
					{
						jishu=0;
						continue;
					}
					ttemp[0]=input[i];
					ttemp[1]=input[i+1];
					if(strcmp(ttemp,"��")==0)
					{
						hhh=2;
						ALU[ALU_counter++]=ADD;
						continue;
					}
					if(strcmp(ttemp,"��")==0)
					{
						hhh=2;
						ALU[ALU_counter++]=SUB;
						continue;
					}
					if(strcmp(ttemp,"��")==0)
					{
						hhh=2;
						ALU[ALU_counter++]=MUL;
						continue;
					}
					if(strcmp(ttemp,"��")==0)
					{
						hhh=2;
						ALU[ALU_counter++]=DIV;
						continue;
					}
					if(strcmp(ttemp,"��")==0)
					{
						hhh=2;
						ALU[ALU_counter++]=DIV;
						continue;
					}
					memset(ttemp,0,5);
				}
				aha:
				for(i=0;i<calculate_array_pointer-1+bansui;i++)
				{
					switch(ALU[i])
					{
						case ADD:
							if(i==0)
							{
								strcpy(result,calculate_array[0]);
							}
							for(m=strlen(result)-1;m>=0;m--)
							{
								if(result[m]=='.'&&recorddot==0)
								{
									recorddot=1;
								}
								//if(result[m]=='.'&&recorddot==1)
								//{
								//	strcpy(result,"���Ǹ��ǣ��������������");
								//	recorddot=0;
								//	goto back;
								//}
							}
							//strcpy(result,"��������");//test
							real_add(result,calculate_array[i+1],result);
							wwhhaatt=strlen(result);
							for(j=0;j<wwhhaatt;j++)
							{
								rresult[j]=result[wwhhaatt-1-j];
							}
							for(j=0;j<wwhhaatt;j++)
							{
								result[j]=rresult[j];
								rresult[j]='\0';
							}
							final=1;
							break;
						case SUB:
							if(i==0)
							{
								strcpy(result,calculate_array[0]);
							}
							if(calculate_array_pointer!=ALU_counter+1)
							{
								for(m=strlen(result)-1;m>=0;m--)
								{
									bansui=-1;
									if(result[m]=='.'&&recorddot==0)
									{
										recorddot=1;
									}
									//if(result[m]=='.'&&recorddot==1)
									//{
									//	strcpy(result,"���Ǹ��ǣ�������������С����");
									//	recorddot=0;
									//	goto back;
									//}
								}
								memset(temp,0,50);
								temp[0]='-';
								strcat(temp,calculate_array[i+1+bansui]);
								real_add(result,temp,result);
								memset(temp,0,50);
								wwhhaatt=strlen(result);
								for(j=0;j<wwhhaatt;j++)
								{
									rresult[j]=result[wwhhaatt-1-j];
								}
								for(j=0;j<wwhhaatt;j++)
								{
									result[j]=rresult[j];
									rresult[j]='\0';
								}
								for(m=strlen(result)-1;m>=0;m--)
								{
									if(result[m]=='.'&&recorddot==0)
									{
										if(result[m+1]=='\0'||result[m+1]=='.'||m==0||result[m+1]==' ')
										{
											result[m]='\0';
										}
										else
										{
											recorddot=1;
										}
									}
								}
								recorddot=0;
								memset(rresult,0,50);
								strcpy(rresult,"-");
								strcat(rresult,result);
								rresult[strlen(rresult)-1]='\0';
								memset(result,0,50);
								strcpy(result,rresult);
								final=1;
								break;
							}
							temp[0]='-'; 
							strcat(temp,calculate_array[i+1+bansui]);
							real_add(result,temp,result);
							memset(temp,0,50);
							if(strstr(result,".")!=NULL)
							{
								if(result[0]!='-')
								{
									for(s=0;result[s]!='.';s++)
									{
										c1[s]=result[s];
									}
									for(t=s+1;result[t]!='\0';t++)
									{
										c2[t-s-1]=result[t];
									}
									records=s;
									recordt=t-s-1;
									for(s=0;s<records;s++)
									{
										c3[s]=c1[records-s-1];
									}
									for(t=0;t<recordt;t++)
									{
										c4[t]=c2[recordt-t-1];
									}
									strcpy(result,c3);
									strcat(result,".");
									strcat(result,c4);
								}
								else
								{
									for(s=1;result[s]!='.';s++)
									{
										c1[s]=result[s];
									}
									for(t=s+1;result[t]!='\0';t++)
									{
										c2[t-s-1]=result[t];
									}
									records=s-1;
									recordt=t-s-1;
									for(s=0;s<records;s++)
									{
										c3[s]=c1[records-s-1];
									}
									for(t=0;t<recordt;t++)
									{
										c4[t]=c2[recordt-t-1];
									}
									strcpy(result,"-");
									strcat(result,c3);
									strcat(result,".");
									strcat(result,c4);
								}							
							}
							break;
						case MUL:
							if(i==0)
							{
								strcpy(result,calculate_array[0]);
							}
							for(m=strlen(result)-1;m>=0;m--)
							{
								if(result[m]=='.'&&recorddot==0)
								{
									recorddot=1;
								}
								//if(result[m]=='.'&&recorddot==1)
								//{
								//	strcpy(result,"���Ǹ��ǣ�����������е�������");
								//	recorddot=0;
								//	goto back;
								//}
							}
							real_multiply(result,calculate_array[i+1],result);
							break;
						case DIV:
							if(i==0)
							{
								strcpy(result,calculate_array[0]);
							}
							for(m=strlen(result)-1;m>=0;m--)
							{
								if(result[m]=='.'&&recorddot==0)
								{
									recorddot=1;
								}
								//if(result[m]=='.'&&recorddot==1)
								//{
								//	strcpy(result,"���Ǹ��ǣ���������滵���ǰ�");
								//	recorddot=0; 
								//	goto back;
								//}
							}
							if(strcmp(calculate_array[i+1],"0")==0||strcmp(calculate_array[i+1],"0.0")==0)
							{
								strcpy(result,"������Ϊ�㣡����Ϊ��ûѧ��Сѧ��ѧ");
								goto back;
							}
							reciprocal(calculate_array[i+1],calculate_array[i+1]);
							real_multiply(result,calculate_array[i+1],result);
							if(strlen(result)>=5)
							{
								result[strlen(result)-1]='\0';
							}
							break;
					}
				}
				if((strstr(result,".")!=NULL||strstr(result,"-")!=NULL)&&final==1)
				{
					char beforedot[50]={0};
					char afterdot[50]={0};
					for(i=0;result[i]!='.';i++)
					{
						beforedot[i]=result[i];
					}
					for(j=i+1;result[j]!='\0';j++)
					{
						afterdot[j-i-1]=result[j];
					}
					strcpy(result,afterdot);
					strcat(result,".");
					strcat(result,beforedot);
				}
				memset(input2,0,400);
				strcpy(input2,"�����");
				strcat(input2,result);
				return 1;
				break;
			case PRIME:
				for(i=0;i<length;i++)
				{
					if(input[i]>='0'&&input[i]<='9')
					{
						calculate_array[0][calculate_array_after++]=input[i];
						hhh=1;
						if(i+1==length)
						{
							hhh=0;
						}
					}
					else
					{
						if(hhh==1)
						{
							hhh=0;
							calculate_array_after=0;
						}
					}
				}
				long long int shuzi=atoi(calculate_array[0]);
				if(isPrime(shuzi)==1)
				{
					memset(input2,0,400);
					strcpy(input2,"��������");
					return 1;
				}
				else
				{
					memset(input2,0,400);
					strcpy(input2,"���Ǻ���");
					return 1;
				}
				break;
			case ZUIDAGONGYUE:
				for(i=0;i<length;i++)
				{
					if(input[i]>='0'&&input[i]<='9')
					{
						calculate_array[calculate_array_pointer][calculate_array_after++]=input[i];
						hhh=1;
						if(i+1==length)
						{
							calculate_array_pointer++;
							hhh=0;
						} 
					}
					else
					{
						if(hhh==1)
						{
							hhh=0;
							calculate_array_pointer++;
							calculate_array_after=0;
						}
					}
				}
				for(i=0;i<calculate_array_pointer-1;i++)
				{
					shuzi1=atoi(calculate_array[i]);
					shuzi2=atoi(calculate_array[i+1]);
				}
				shuzi3=gcd(shuzi1,shuzi2);
				itoa(shuzi3,ccc,10);
				memset(input2,0,400);
				strcpy(input2,"��������ǣ�");
				strcat(input2,ccc);
				return 1;
				break;
			case ZUIXIAOGONGBEI:
				for(i=0;i<length;i++)
				{
					if(input[i]>='0'&&input[i]<='9')
					{
						calculate_array[calculate_array_pointer][calculate_array_after++]=input[i];
						hhh=1;
						if(i+1==length)
						{
							calculate_array_pointer++;
							hhh=0;
						} 
					}
					else
					{
						if(hhh==1)
						{
							hhh=0;
							calculate_array_pointer++;
							calculate_array_after=0;
						}
					}
				}
				shuzi1=atoi(calculate_array[0]);
				shuzi2=atoi(calculate_array[1]);
				shuzi3=gcd(shuzi1,shuzi2);
				shuzi3=shuzi1*shuzi2/shuzi3;
				itoa(shuzi3,ccc,10);
				memset(input2,0,400);
				strcpy(input2,"��С�������ǣ�");
				strcat(input2,ccc);
				return 1;
				break;
			case SQRT:
				for(i=0;i<length;i++)
				{
					if(input[i]>='0'&&input[i]<='9')
					{
						calculate_array[calculate_array_pointer][calculate_array_after++]=input[i];
						hhh=1;
						if(i+1==length)
						{
							calculate_array_pointer++;
							hhh=0;
						}
					}
					else
					{
						if(hhh==1)
						{
							hhh=0;
							calculate_array_pointer++;
							calculate_array_after=0;
						}
					}
				}
				shuzi4=atof(calculate_array[0]);
				shuzi4=sqrt(shuzi4);
				shuzi2=(int)shuzi4;
				memset(input2,0,400);
				strcpy(input2,"���ǣ�");
				itoa(shuzi2,ccc,10);
				strcat(input2,ccc);
				strcat(input2,".");
				memset(ccc,0,400);
				shuzi4=shuzi4-shuzi2;
				shuzi4*=10;
				shuzi2=(int)shuzi4;
				itoa(shuzi2,ccc,10);
				strcat(input2,ccc);
				ccc[0]='\0';
				shuzi4=shuzi4-shuzi2;
				shuzi4*=10;
				shuzi2=(int)shuzi4;
				itoa(shuzi2,ccc,10);
				strcat(input2,ccc);
				return 1;
				break;
			default:
				return 0;
				break;
		}
		return 0;
		back:
			strcpy(input2,result);
			return 1;	
	}
	return 0;
}
