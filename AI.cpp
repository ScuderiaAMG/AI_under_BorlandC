
/*
**�ļ����ƣ�AI 
**�ļ�Ŀ�ģ���˵���ں�����滮 
**ʱ�临�Ӷȣ�\Theta(1) 
**�ռ临�Ӷȣ�\Theta(1) 
*/

#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<alloc.h>
#include<fenci.h>
#include<color.h>
#include<detect.h>
#include<trans12.h>
#include<lasthao.h>
#include<ptext.h>
#include<teshu.h>
#include<draw.h>
#include<jisuan.h>
#include<AI.h>
#include<42km.h>
#include<xiezi.h>
#include<find.h>
#include<wentu.h>
#include<string.h>//test

extern char far input[51][421];

void entrance(int page,int* keyboard,int status,int* input_counter)
{
	ZHUWEIBIN* zhuweibin=(ZHUWEIBIN*)malloc(10*sizeof(ZHUWEIBIN));
	int strategy;
	int sum;
	char test;
	int kk;
	char jizong[200]={0};
	char ttest[5]={0};
	int forty_two=0;
	char far* eventual=(char*)malloc(400);
	char far* biaohao=(char*)malloc(150);
	*keyboard=0;
	
	memset(eventual,0,400);
	memset(biaohao,0,150);
	int qingchu;
	int chuqing;
	for(qingchu=0;qingchu<10;qingchu++)
	{
		for(chuqing=0;chuqing<30;chuqing++)
		{
			zhuweibin[qingchu].zhu[chuqing]=0;
			zhuweibin[qingchu].wei[chuqing]=0;
			zhuweibin[qingchu].bin[chuqing]=0;
		}
	}
	
	switch(status)
	{
			
		case 0:
			//Ԥ�Ȳ�����ѧ����
			sum=detect(input[*input_counter-1],&strategy);
			if(strategy==CALCULATE)
			{
				forty_two=calculate_all(input[*input_counter-1],strategy,input[*input_counter]);
				if(forty_two==1)
				{
					goto x1;
				}
			}
			//���ⲽ�������ַ����Ĵ���
			if(teshu_find(input[*input_counter-1],eventual)==SUCCESSTESHU)
			{
				strcpy(input[*input_counter],eventual);
				goto x1;
			}
			if(strcmp(input[*input_counter-1],input[*input_counter-3])==0)
			{
				strcpy(input[*input_counter],"������֮ǰ�����ʹ�����");
				display_text(input,0,page,*keyboard);
				(*input_counter)++;
				free(eventual);
				free(zhuweibin);
				free(biaohao);
				break;
			}
			//��һ�����ִ�
			fenci(input[*input_counter-1],eventual);

			//���ɲ�������С������б��
			trans12(eventual,biaohao);

			//�ڶ��������ϳ����ĳ�����
			lasthao(input[*input_counter-1],eventual,zhuweibin,biaohao);
			//memset(eventual,0,400);
			//for(kk=0;kk<30;kk++)
			//{
			//	test=zhuweibin[0].bin[kk];
			//	itoa(test,ttest,10);
			//	strcat(jizong,ttest);
			//} 
			//strcpy(eventual,jizong);
			//���������߼�����+ʵ�ֻش�
			strcpy(eventual,find_logic(zhuweibin[0],input[*input_counter-1],eventual));

			//����������о�
				strcpy(input[*input_counter],eventual);
			x1:
				display_text(input,0,page,*keyboard);
				(*input_counter)++;
				free(eventual);
				free(zhuweibin);
			    free(biaohao);
			
			break;
			
		case 1:
			wenshengtu(input[0],input);
			*input_counter=0;
	}
	
	return; 
}

int text_height(char input[51][421])
{
	int i;
	for(i=0;i<51;i++)
	{
		if(input[i][0]==0)//���Ե�һ�����벻���ǿո����enter,Ҫ����
		{
			break;
		}
	}
	i/=46;
	i++;
	return i;
}

int text_position(int height,int pianyi)
//height���ַ�����ʾ�ĸ߶�,pianyi���ı���ƫ�Ƶľ���
//height�Ǹ߶ȵ�������,pianyi�Ǹ߶ȵļ�����
{
	static int sum_height=0;
	sum_height+=height;
	return sum_height-pianyi;
}

int text_jushu(char input[51][421])
{
	int i,aha=0;
	for(i=0;input[i][0]!=0;i++)
	{
		aha++;
	}
	return aha;
	//aha����һ���ľ�����
}

int display_text(char input[51][421],int pianyi,int page,int keyboard)
{
	fill_color(0,0,963,575,SPRING_GREEN_,page,0);
	fill_color(964,61,1024,575,SPRING_GREEN_,page,0);
	int jushu=text_jushu(input);
	int sum_height=0;
	int height[100];
	int i;
	int sum_temp=0;
	int temp;
	int status;
	int zaipianyi=0;
	int zonggong=0;
	int haohaohao=0;
	for(i=0;i<jushu;i++)
	{
		height[i]=text_height(input);
		sum_height+=(height[i]+2);
	}
	for(i=0;input[i][0]!='\0';i++)
	{
		zonggong+=32*(strlen(input[i])/46+2);
		zonggong+=32;
	}
	for(i=0;input[i][0]!='\0';i++)
	{
		zaipianyi+=(strlen(input[i])/46)*32;
	}
	if(zonggong<=18*32)
	{
		zaipianyi=0;
	}
	for(i=0;input[i][0]!='\0';i++)
	{
		;
	}
	int iii=i;
	for(i=0;i<jushu;i++)
	{
		temp=sum_temp-pianyi;
		pianyi=pianyiliang(sum_height,height[i],keyboard);
		if(temp>=0&&temp<=18)
		{
			status=FILL_STATUS;
		}
		else if(temp<0)
		{
			status=NONFILL_STATUS;
		}
		else
		{
			status=NONNONFILL_STATUS;
		}
		if(i%2==ROBOT_ROLE)
		{
			if(i==0)
			{
				if(iii<=5)
				{
					draw_final0(input[i],strlen(input[i])/46+1,20+temp*32-zaipianyi+haohaohao-32*keyboard,page,status);
				}
				else
				{
					;
				}
			}
			else
			{
				draw_final0(input[i],strlen(input[i])/46+1,20+temp*32-zaipianyi+haohaohao-32*keyboard,page,status);
			}
		}
		else if(i%2==USER_ROLE)
		{
			draw_final1(input[i],strlen(input[i])/46+1,20+temp*32-zaipianyi+haohaohao-32*keyboard,page,status);
		}
		haohaohao+=(strlen(input[i])/46)*32;
		sum_temp+=(height[i]+2);
	}
	//��ֹ�����С�����˳�������
	fill_color(964,0,1024,60,RED_,page,0);
	for(i=-2;i<=2;i++)
	{
		line_drawing(968+i,8,1020+i,52,WHITE_,page,0);
		line_drawing(1020+i,8,968+i,52,WHITE_,page,0);
	}
}

int pianyiliang(int sum_height,int height,int keyboard)
{
	int temp=sum_height+height+2;
	int pianyi;
	int i;
	if(temp<=19)
	{
		pianyi=0;
	}
	else
	{
		pianyi=temp-19+keyboard;
	}
	return pianyi;
}
