
/*
** �ļ�����wentu
** �ļ�Ŀ�ģ���������ͼ
** ʱ�临�Ӷȣ��������ַ������� 
** �ռ临�Ӷȣ���ֵ 
*/
//�ˡ���������������ͼ�ε����ҹ�ϵ
//����������������ҷ�ת 
#include<ptext.h>
#include<draw.h>
#include<xiezi.h>
#include<English.h>
#include<string.h>
#include<AI.h>
#include<page.h>
#include<pchat.h>
#include<color.h>
#include<fish.h>
#include<view.h>
#include<boy.h>
#include<car.h>
#include<dog.h>
#include<view.h>
#include<fish.h>
#include<car.h>
#include<allo.h>
#include<wentu.h>
#include<BEZIER.H>

void wenshengtu(char* shuru,char input[51][421])
{
	
	static int posi[6]={0};
	static int judge[2]={0};
	
	char shuru_1[10][50]={0};
	int k=0;
	int j=0;
	int m=0;
	int n=0; //1:����2:���� 
	int i;//ѭ���� 
	int color; 
	int height=12; 
	int y=90;
	int page=PAGE_CHAT1;	
	
	fill_color(0,0,1024,575,SPRING_GREEN_,PAGE_CHAT1,0);
	strcpy(input[0],shuru);
	strcpy(input[1],"");

	draw_final1(input[0],1,20,page,0);
	fill_color(964,0,1024,60,RED_,page,0);
	for(i=-2;i<=2;i++)
	{
		line_drawing(968+i,8,1020+i,52,WHITE_,page,0);
		line_drawing(1020+i,8,968+i,52,WHITE_,page,0);
	}
	robot_avatar(50,160,PAGE_CHAT1);
	for(i=-1;i<=1;i++)
	{
		line_drawing(104,y+35,135,y+15,WHITE_,page,1);
		line_drawing(104,y+35,135,y+40,WHITE_,page,1);
		line_drawing(135,y+15,800,y+15,WHITE_,page,1);
	}
	fill_color(135,y+15,925,y+15+height*WORDWIDTH,WHITE_,page,1);
	for(i=16;i<40;i++)
	{
		line_drawing(104,y+35,135,y+i,WHITE_,page,1);
	}

	//�ص����ɣ��ڶ���ͼ���ŵ�һ��ͼ���� 
	if(strstr(shuru,"�ص�")!=NULL||
	strstr(shuru,"����")!=NULL||
	strstr(shuru,"��һ")!=NULL||
	strstr(shuru,"����")!=NULL||
	strstr(shuru,"����")!=NULL||
	strstr(shuru,"��")!=NULL||
	strstr(shuru,"��")!=NULL
	)
	{
		wenshengtu_overlap(shuru);
		//���� 
		return ;
	}
	
	i=0;
	m=0;
	while(shuru[i]!='\0'&&i<=50)
	{
		if(shuru[i]==',') //||((unsigned char)shuru[i]==0xBA)
		{
			j++;
			m=0;
		}
		shuru_1[j][m++]=shuru[i];
		i++;
	}
	
	
	
	
	line_drawing(104,y+35,135,y+15,BLACK_,page,1);
	line_drawing(104,y+35,135,y+40,BLACK_,page,1);
	line_drawing(135,y+15,925,y+15,BLACK_,page,1);
	line_drawing(925,y+15,925,y+15+height*WORDWIDTH,BLACK_,page,1);
	line_drawing(925,y+15+height*WORDWIDTH,135,y+15+height*WORDWIDTH,BLACK_,page,1);
	line_drawing(135,y+20,135,y+15,BLACK_,page,1);
	line_drawing(135,y+40,135,y+15+height*WORDWIDTH,BLACK_,page,1);
	
	
	
	i=0;
	while(shuru_1[i][0]!='\0')
	{
		color=TROPICAL_ORANGE_;
		if(strstr(shuru_1[i],"��")!=NULL)
		{
			color=RED1_; 
		}
		else if(strstr(shuru_1[i],"��")!=NULL)
		{
			color=GREEN_1; 
		}
		else if(strstr(shuru_1[i],"��")!=NULL)
		{
			color=BLUE_1; 
		}
		else if(strstr(shuru_1[i],"��")!=NULL)
		{
			color=YELLOW_1; 
		}
		
		
	//ɽ	
	if(strstr(shuru_1[i],"ɽ")!=NULL&&
	strstr(shuru_1[i],"ɽ����")==NULL&&
	strstr(shuru_1[i],"ɽ����")==NULL&&
	strstr(shuru_1[i],"ɽ����")==NULL&&
	strstr(shuru_1[i],"ɽ��")==NULL&&
	strstr(shuru_1[i],"ɽ��")==NULL)
	{
		posi[0]=325;
		posi[1]=470;
		posi[2]=135;
		posi[3]=925; 
		judge[0]=1;
		judge[1]=2;
		//mountain(300,150,1,BLUE_,page);
		put_picture_mountain(posi,judge,page,color) ;
	} 
	
	//�� 
	if(strstr(shuru_1[i],"��")!=NULL)
	{
		if(strstr(shuru_1[i],"1��")!=NULL||
		strstr(shuru_1[i],"1Ƭ")!=NULL||
		strstr(shuru_1[i],"һ��")!=NULL||
		strstr(shuru_1[i],"һƬ")!=NULL)
		{
			if(strstr(shuru_1[i],"��")!=NULL)	
			{
				cloud(0,422,1,BLUE_1,page);
			}		
			else if(strstr(shuru_1[i],"��")!=NULL) 
			{
				cloud(470,430,1,BLUE_1,page);
			}
			else
			{
				cloud(236,430,1,BLUE_1,page);
			} 
		}
		
		else if(strstr(shuru_1[i],"2��")!=NULL||
		strstr(shuru_1[i],"2Ƭ")!=NULL||
		strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"��Ƭ")!=NULL)	
		{
			cloud(0,422,1,BLUE_1,page);
			cloud(470,430,1,BLUE_1,page);
		}	
		
		else
		{
			cloud(0,422,1,BLUE_1,page);
			cloud(470,430,1,BLUE_1,page);
			cloud(236,430,1,BLUE_1,page);
			
		} 
		 
	//	cloud(0,422,1,BLUE_1,page);
	//	cloud(400,430,1,BLUE_1,page);
	//	cloud(150,409,1,BLUE_1,page);
	}
	
	//ˮ 
	if((strstr(shuru_1[i],"ˮ")!=NULL||
	strstr(shuru_1[i],"��")!=NULL||
	strstr(shuru_1[i],"��")!=NULL||
	strstr(shuru_1[i],"��")!=NULL)&&
	(strstr(shuru_1[i],"����")==NULL&&
	strstr(shuru_1[i],"����")==NULL&&
	strstr(shuru_1[i],"����")==NULL&&
	strstr(shuru_1[i],"ˮ��")==NULL)) 
	{
		water(290,105,1,BLUE_,page);
		water(50,88,1,BLUE_,page);
		water(100,55,1,BLUE_,page);
		water(86,25,1,BLUE_,page);
	}
	
	
	//�� 
	if((strstr(shuru_1[i],"��")!=NULL)&&
	(strstr(shuru_1[i],"������")==NULL&&
	strstr(shuru_1[i],"����ǰ")==NULL&&
	strstr(shuru_1[i],"������")==NULL&&
	strstr(shuru_1[i],"���ĺ�")==NULL))
	{
		
		//λ��	
		switch(judge_position(shuru_1[i]))
		{
			case 1:
				posi[0]=350;
				posi[1]=489;
				posi[2]=135;
				posi[3]=500; 
			 
				judge[0]=3;
				judge[1]=1;
				break;
			case 2:
				posi[0]=350;
				posi[1]=489;
				posi[2]=800;
				posi[3]=925; 
				judge[0]=4;
				judge[1]=1;
				break;
			//��ԭͼ�������	
			case 6:
				judge[0]=4;
				posi[3]=posi[2];
				break;
		
			//��ԭͼ�ұ�����	
			case 7:
				judge[0]=3;
				posi[2]=posi[3];
				break;
			
	
			default:
				if(strstr(shuru_1[i],"��")!=NULL)
				{
				posi[0]=390;
				posi[1]=476;
				posi[4]=530;
				posi[5]=360;
				judge[0]=5;
				judge[1]=1;	
				break;					
				}
				else
				{
				posi[0]=330;
				posi[1]=476;
				posi[4]=530;
				posi[5]=390;
				judge[0]=5;
				judge[1]=1;	
				break;					
				}		

					
		}		
		
		 
		if(strstr(shuru_1[i],"��")!=NULL) 
		{
		posi[0]=220;

		if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			put_picture_car1(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			put_picture_car2(posi,judge,page,color);
			n=2;
		}		
		else//δ��˵�����Զ����� 
		{
			put_picture_car1(posi,judge,page,color);
			n=1;
		}
		}
		
		else if(strstr(shuru_1[i],"С")!=NULL) 
		{
		posi[0]=400;

		if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			put_picture_car1(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			put_picture_car2(posi,judge,page,color);
			n=2;
		}		
		else//δ��˵�����Զ����� 
		{
			put_picture_car1(posi,judge,page,color);
			n=1;
		}		
		}
		
		else
		{
		if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			put_picture_car1(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			put_picture_car2(posi,judge,page,color);
			n=2;
		}		
		else//δ��˵�����Զ����� 
		{
			put_picture_car1(posi,judge,page,color);
			n=1;
		}					
		}
	}
	
	
	//�к� 
	if(
	strstr(shuru_1[i],"Ů")!=NULL||
	strstr(shuru_1[i],"��")!=NULL||
	strstr(shuru_1[i],"��")!=NULL||
	strstr(shuru_1[i],"�к�")!=NULL||
	strstr(shuru_1[i],"����")!=NULL||
	strstr(shuru_1[i],"����")!=NULL||
	strstr(shuru_1[i],"��ʿ")!=NULL||
	strstr(shuru_1[i],"�е�")!=NULL||
	strstr(shuru_1[i],"����")!=NULL
	)
	{
	   //λ�� 

	   switch(judge_position(shuru_1[i]))
	   {
	   	case 1:
	   		posi[0]=300;
	   		posi[1]=489;
	   		posi[2]=150;
	   		posi[3]=370;
	   		judge[0]=3;
	   		judge[1]=1;
		    break;
		case 2:
	   		posi[0]=300;
	   		posi[1]=489;
	   		posi[2]=800;
	   		posi[3]=916;
	   		judge[0]=4;
	   		judge[1]=1;	 
			break; 
		
		//��ԭͼ�������	
		case 6:
			judge[0]=4;
			posi[3]=posi[2];
	   		posi[0]=300;
	   		posi[1]=489;
			break;
		
		//��ԭͼ�ұ�����	
		case 7:
			judge[0]=3;
			posi[2]=posi[3];
	   		posi[0]=300;
	   		posi[1]=489;
			break;
			
		case 5:
	   		posi[0]=300;
	   		posi[1]=489;
	   		posi[2]=440;
	   		posi[3]=670;
	   		judge[0]=3;
	   		judge[1]=1;	
			break;  
		
		default:
	   		posi[0]=300;
	   		posi[1]=489;
	   		posi[2]=500;
	   		posi[3]=730;
	   		judge[0]=3;
	   		judge[1]=1;	  				    				 				
		   	break;  		
	   }
	   //��С 
	if(strstr(shuru_1[i],"��")!=NULL||
	strstr(shuru_1[i],"��")!=NULL||
	strstr(shuru_1[i],"׳")!=NULL)
		posi[0]=200; 
	put_picture_boy(posi,judge,page,color);
	}
	
	
	
	//�� 
	if(strstr(shuru_1[i],"��")!=NULL&&strstr(shuru_1[i],"����")==NULL)
	{	
		//λ��	
		switch(judge_position(shuru_1[i]))
		{
			case 1:
				posi[0]=390;
				posi[1]=476;
				posi[2]=140;
				posi[3]=320;
				judge[0]=3;
				judge[1]=1;
				break;
			case 2:
				posi[0]=390;
				posi[1]=476;
				posi[2]=860;
				posi[3]=910;
				judge[0]=4;
				judge[1]=1;	
				break;
	
			default:
				posi[0]=390;
				posi[1]=476;
				posi[4]=530;
				posi[5]=400;
				judge[0]=5;
				judge[1]=1;	
				break;
					
		}
		
		//��С 
		if(strstr(shuru_1[i],"��")!=NULL)
		{
			posi[0]=330;
		}
		
		//���� 
		if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			put_picture_fish1(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			put_picture_fish2(posi,judge,page,color);
			n=2;
		}		
		else//δ��˵�����Զ����� 
		{
			put_picture_fish1(posi,judge,page,color);
			n=1;
		}
		if(strstr(shuru_1[i],"���")!=NULL)		
		{
			fill_1(color,page);
		}					
	}
	//���� 
	if(strstr(shuru_1[i],"����")!=NULL&&strstr(shuru_1[i],"��")!=NULL) 
	{
			posi[0]=320;
			posi[1]=460;
			posi[2]=160;
			posi[3]=350;
			judge[0]=3;
			judge[1]=1; 

		if(strstr(shuru_1[i],"С")!=NULL)
		{
			posi[0]=390;			
		}
			
		if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			put_picture_fish1(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			put_picture_fish2(posi,judge,page,color);
			n=2;
		}		
		else//δ��˵�����Զ����� 
		{
			put_picture_fish1(posi,judge,page,color);
			n=1;
		}					
		
		//�ڶ��� 
		posi[2]=560;
		posi[3]=850;
				
		if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			put_picture_fish1(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			put_picture_fish2(posi,judge,page,color);
			n=2;
		}		
		else//δ��˵�����Զ����� 
		{
			put_picture_fish1(posi,judge,page,color);
			n=1;	
		}					
	}	

	//�� 
	if(strstr(shuru_1[i],"��")!=NULL&&strstr(shuru_1[i],"����")==NULL)
	{	
		//λ��	
		switch(judge_position(shuru_1[i]))
		{
			case 1:
				posi[0]=180;
				posi[1]=600;
				posi[2]=40;
				posi[3]=320;
				judge[0]=3;
				judge[1]=1;
				if(strstr(shuru_1[i],"����")!=NULL||
					strstr(shuru_1[i],"����")!=NULL)
					{
						posi[2]+=70; 
					}	
				else
				{
					posi[2]-=70;	
				}	
				break;
			case 2:
				posi[0]=180;
				posi[1]=600;
				posi[2]=520;
				posi[3]=980;
				judge[0]=4;
				judge[1]=1;	
				
				if(strstr(shuru_1[i],"����")!=NULL||
					strstr(shuru_1[i],"����")!=NULL)
					{
						; 
					}
				else
					{
						posi[3]-=290; 
					}	
				break;
			default:
				posi[0]=180;
				posi[1]=600;
				posi[4]=530;
				posi[5]=376;
				judge[0]=5;
				judge[1]=1;	
				
				if(strstr(shuru_1[i],"����")!=NULL||
					strstr(shuru_1[i],"����")!=NULL)
					{
						; 
					}
				else
				{
					posi[4]-=200;
				}
				break;
					
		}
		
		//��С 
		if(strstr(shuru_1[i],"С")!=NULL)
		{
			posi[0]=230;
			posi[1]-=20; 
		}
		
		//���� 
		if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			
			if(strstr(shuru_1[i],"���")!=NULL)		
			{
				put_picture_dog2_fill(posi,judge,page,color);
			}	
			else	
			put_picture_dog2(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
		if(strstr(shuru_1[i],"���")!=NULL)		
		{
			put_picture_dog1_fill(posi,judge,page,color);
		}		
		else
			put_picture_dog1(posi,judge,page,color);
			n=2;
		}		
		else//δ��˵�����Զ����� 
		{
		if(strstr(shuru_1[i],"���")!=NULL)		
		{
			put_picture_dog2_fill(posi,judge,page,color);
		}		
		else
			put_picture_dog2(posi,judge,page,color);
			n=1;
		}			
	}

	i++;
	}
}



//�ж�λ�ù�ϵ��������������ɵ�ͼ������������һ�����ɵ�ͼ�Σ� 
int judge_position(char* shuru)
{
	if(strstr(shuru,"��Ļ����")!=NULL||
	strstr(shuru,"���Ե���")!=NULL||
	strstr(shuru,"ͼƬ����")!=NULL||
	strstr(shuru,"ͼ����")!=NULL||
	strstr(shuru,"�������")!=NULL||
	strstr(shuru,"����")!=NULL||
	strstr(shuru,"��Ļ��")!=NULL||
	strstr(shuru,"������")!=NULL||
	strstr(shuru,"ͼƬ��")!=NULL||
	strstr(shuru,"ͼ��")!=NULL||
	strstr(shuru,"������")!=NULL||
	strstr(shuru,"����")!=NULL)
	return  1;
	
	if(strstr(shuru,"��Ļ����")!=NULL||
	strstr(shuru,"���Ե���")!=NULL||
	strstr(shuru,"ͼƬ����")!=NULL||
	strstr(shuru,"ͼ����")!=NULL||
	strstr(shuru,"�������")!=NULL||
	strstr(shuru,"����")!=NULL||
	strstr(shuru,"��Ļ��")!=NULL||
	strstr(shuru,"������")!=NULL||
	strstr(shuru,"ͼƬ��")!=NULL||
	strstr(shuru,"ͼ��")!=NULL||
	strstr(shuru,"������")!=NULL||
	strstr(shuru,"����")!=NULL)
	return  2;
	
	if(strstr(shuru,"��Ļ����")!=NULL||
	strstr(shuru,"���Ե���")!=NULL||
	strstr(shuru,"ͼƬ����")!=NULL||
	strstr(shuru,"ͼ����")!=NULL||
	strstr(shuru,"�������")!=NULL||
	strstr(shuru,"����")!=NULL)
	return  3;
	
	if(strstr(shuru,"��Ļ����")!=NULL||
	strstr(shuru,"���Ե���")!=NULL||
	strstr(shuru,"ͼƬ����")!=NULL||
	strstr(shuru,"ͼ����")!=NULL||
	strstr(shuru,"�������")!=NULL||
	strstr(shuru,"����")!=NULL)
	return 4;
	
	if(strstr(shuru,"��Ļ����")!=NULL||
	strstr(shuru,"���Ե���")!=NULL||
	strstr(shuru,"ͼƬ����")!=NULL||
	strstr(shuru,"ͼ����")!=NULL||
	strstr(shuru,"�������")!=NULL||
	strstr(shuru,"����")!=NULL)
	return 5;
	
	if(strstr(shuru,"����")!=NULL)
	return 6;
	
	if(strstr(shuru,"����")!=NULL||
	strstr(shuru,"���Ա�")!=NULL)
	return 7;
	
	if(strstr(shuru,"��ǰ")!=NULL)
	return 8;
	
	if(strstr(shuru,"�ĺ�")!=NULL)
	return 9;
	
	return 0;
}



//����ģʽ���ڶ���ͼ���ŵ�һ��ͼ���� 
void wenshengtu_overlap(char* shuru)
{
	
	static int posi[6]={0};
	static int judge[2]={0};
	
	static char shuru_1[10][50]={0};
	int k=0;
	static int j;
	int m=0;
	int n=0; //1:����2:���� 
	int i;//ѭ���� 
	int color; 
	int height=12; 
	static int number_1[4]={0};//���ƴ���
	static int number_2[4]={0};//���ƴ��� 
	int y=90;
	int page=PAGE_CHAT1;	
	i=0;
	m=0; 
	//Խ���Զ���������ģʽ 
	if(shuru_1[9][0]!='\0')
	{
		for(i=0;i<10;i++)
		{
			for(k=0;k<50;k++)
			{
				shuru_1[i][k]='\0';
				j=0;
			} 
		}
		for(i=0;i<4;i++)
		{
		number_1[i]=0;
		number_2[i]=0;			
		}
	} 
	
	//��������ģʽ 
	if(strstr(shuru,"���")!=NULL||
	strstr(shuru,"���")!=NULL||
	strstr(shuru,"ɾ��")!=NULL||
	strstr(shuru,"����")!=NULL||
	strstr(shuru,"ֹͣ")!=NULL)
	{
		for(i=0;i<10;i++)
		{
			for(k=0;k<50;k++)
			{
				shuru_1[i][k]='\0';
			} 
		}	
		j=0;	
		for(i=0;i<4;i++)
		{
		number_1[i]=0;
		number_2[i]=0;			
		}
	}
	
	
	i=0;
	m=0;
	while(shuru[i]!='\0'&&i<=50)
	{
		if(shuru[i]==',') //||((unsigned char)shuru[i]==0xBA)
		{
			j++;
			m=0;
		}
		shuru_1[j][m++]=shuru[i];
		i++;
	}
	
	
	
	
	line_drawing(104,y+35,135,y+15,BLACK_,page,1);
	line_drawing(104,y+35,135,y+40,BLACK_,page,1);
	line_drawing(135,y+15,925,y+15,BLACK_,page,1);
	line_drawing(925,y+15,925,y+15+height*WORDWIDTH,BLACK_,page,1);
	line_drawing(925,y+15+height*WORDWIDTH,135,y+15+height*WORDWIDTH,BLACK_,page,1);
	line_drawing(135,y+20,135,y+15,BLACK_,page,1);
	line_drawing(135,y+40,135,y+15+height*WORDWIDTH,BLACK_,page,1);
	
	
	
	i=0;
	while(shuru_1[i][0]!='\0')
	{
		color=TROPICAL_ORANGE_;
		if(strstr(shuru_1[i],"��")!=NULL)
		{
			color=RED1_; 
		}
		else if(strstr(shuru_1[i],"��")!=NULL)
		{
			color=GREEN_1; 
		}
		else if(strstr(shuru_1[i],"��")!=NULL)
		{
			color=BLUE_1; 
		}
		else if(strstr(shuru_1[i],"��")!=NULL)
		{
			color=YELLOW_1; 
		}
		
		
	//ɽ	
	if(strstr(shuru_1[i],"ɽ")!=NULL&&
	strstr(shuru_1[i],"ɽ����")==NULL&&
	strstr(shuru_1[i],"ɽ����")==NULL&&
	strstr(shuru_1[i],"ɽ����")==NULL&&
	strstr(shuru_1[i],"ɽ��")==NULL&&
	strstr(shuru_1[i],"ɽ��")==NULL)
	{
		posi[0]=325;
		posi[1]=470;
		posi[2]=135;
		posi[3]=925; 
		judge[0]=1;
		judge[1]=2;
		//mountain(300,150,1,BLUE_,page);
		put_picture_mountain(posi,judge,page,color) ;
	} 
	
	//�� 
	if(strstr(shuru_1[i],"��")!=NULL)
	{
		if(strstr(shuru_1[i],"1��")!=NULL||
		strstr(shuru_1[i],"1Ƭ")!=NULL||
		strstr(shuru_1[i],"һ��")!=NULL||
		strstr(shuru_1[i],"һƬ")!=NULL)
		{
			if(strstr(shuru_1[i],"��")!=NULL)	
			{
				cloud(0,422,1,BLUE_1,page);
			}		
			else if(strstr(shuru_1[i],"��")!=NULL) 
			{
				cloud(470,430,1,BLUE_1,page);
			}
			else
			{
				cloud(236,430,1,BLUE_1,page);
			} 
		}
		
		else if(strstr(shuru_1[i],"2��")!=NULL||
		strstr(shuru_1[i],"2Ƭ")!=NULL||
		strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"��Ƭ")!=NULL)	
		{
			cloud(0,422,1,BLUE_1,page);
			cloud(470,430,1,BLUE_1,page);
		}	
		
		else
		{
			cloud(0,422,1,BLUE_1,page);
			cloud(470,430,1,BLUE_1,page);
			cloud(236,430,1,BLUE_1,page);
			
		} 
		 
	//	cloud(0,422,1,BLUE_1,page);
	//	cloud(400,430,1,BLUE_1,page);
	//	cloud(150,409,1,BLUE_1,page);
	}
	
	//ˮ 
	if((strstr(shuru_1[i],"ˮ")!=NULL||
	strstr(shuru_1[i],"��")!=NULL||
	strstr(shuru_1[i],"��")!=NULL||
	strstr(shuru_1[i],"��")!=NULL)&&
	(strstr(shuru_1[i],"����")==NULL&&
	strstr(shuru_1[i],"����")==NULL&&
	strstr(shuru_1[i],"����")==NULL&&
	strstr(shuru_1[i],"ˮ��")==NULL)) 
	{
		water(290,105,1,BLUE_,page);
		water(50,88,1,BLUE_,page);
		water(100,55,1,BLUE_,page);
		water(86,25,1,BLUE_,page);
	}
	
	
	//�� 
	if((strstr(shuru_1[i],"��")!=NULL)&&
	(strstr(shuru_1[i],"������")==NULL&&
	strstr(shuru_1[i],"����ǰ")==NULL&&
	strstr(shuru_1[i],"������")==NULL&&
	strstr(shuru_1[i],"���ĺ�")==NULL))
	{
		
		//λ��	
		switch(judge_position(shuru_1[i]))
		{
			case 1:
				posi[0]=350;
				posi[1]=489;
				posi[2]=135;
				posi[3]=500; 
			 
				judge[0]=3;
				judge[1]=1;
				break;
			case 2:
				posi[0]=350;
				posi[1]=489;
				posi[2]=800;
				posi[3]=925; 
				judge[0]=4;
				judge[1]=1;
				break;
			//��ԭͼ�������	
			case 6:
				judge[0]=4;
				posi[3]=posi[2];
				break;
		
			//��ԭͼ�ұ�����	
			case 7:
				judge[0]=3;
				posi[2]=posi[3];
				break;


			default:
				if(strstr(shuru_1[i],"��")!=NULL)
				{
				posi[0]=390;
				posi[1]=476;
				posi[4]=530;
				posi[5]=360;
				judge[0]=5;
				judge[1]=1;	
				break;					
				}
				else
				{
				posi[0]=330;
				posi[1]=476;
				posi[4]=530;
				posi[5]=390;
				judge[0]=5;
				judge[1]=1;	
				break;					
				}		
		}
		
			if(move(shuru)==1) 
			{
				number_1[0]++;				
			}
			if(move(shuru)==2)
			{
				number_2[0]++;
			}
	
			for(k=0;k<number_1[0];k++)
			{
			posi[2]-=30;
			posi[3]-=30;	
			posi[4]-=30;			
			}
			for(k=0;k<number_2[0];k++)
			{
			posi[2]+=30;
			posi[3]+=30;
			posi[4]+=30;				
			}			
		
		 
		if(strstr(shuru_1[i],"��")!=NULL) 
		{
		posi[0]=220;

		if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			put_picture_car1(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			put_picture_car2(posi,judge,page,color);
			n=2;
		}		
		else//δ��˵�����Զ����� 
		{
			put_picture_car1(posi,judge,page,color);
			n=1;
		}
		}
		
		else if(strstr(shuru_1[i],"С")!=NULL) 
		{
		posi[0]=400;

		if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			put_picture_car1(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			put_picture_car2(posi,judge,page,color);
			n=2;
		}		
		else//δ��˵�����Զ����� 
		{
			put_picture_car1(posi,judge,page,color);
			n=1;
		}		
		}
		
		else
		{
		if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			put_picture_car1(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			put_picture_car2(posi,judge,page,color);
			n=2;
		}		
		else//δ��˵�����Զ����� 
		{
			put_picture_car1(posi,judge,page,color);
			n=1;
		}					
		}
	}
	
	
	//�к� 
	if(
	strstr(shuru_1[i],"Ů")!=NULL||
	strstr(shuru_1[i],"��")!=NULL||
	strstr(shuru_1[i],"��")!=NULL||
	strstr(shuru_1[i],"�к�")!=NULL||
	strstr(shuru_1[i],"����")!=NULL||
	strstr(shuru_1[i],"����")!=NULL||
	strstr(shuru_1[i],"��ʿ")!=NULL||
	strstr(shuru_1[i],"�е�")!=NULL||
	strstr(shuru_1[i],"����")!=NULL
	)
	{
	   //λ�� 

	   switch(judge_position(shuru_1[i]))
	   {
	   	case 1:
	   		posi[0]=300;
	   		posi[1]=489;
	   		posi[2]=150;
	   		posi[3]=370;
	   		judge[0]=3;
	   		judge[1]=1;
		    break;
		case 2:
	   		posi[0]=300;
	   		posi[1]=489;
	   		posi[2]=800;
	   		posi[3]=916;
	   		judge[0]=4;
	   		judge[1]=1;	 
			break; 
		
		//��ԭͼ�������	
		case 6:
			judge[0]=4;
			posi[3]=posi[2];
	   		posi[0]=300;
	   		posi[1]=489;
			break;
		
		//��ԭͼ�ұ�����	
		case 7:
			judge[0]=3;
			posi[2]=posi[3];
	   		posi[0]=300;
	   		posi[1]=489;
			break;
	
		case 5:
	   		posi[0]=300;
	   		posi[1]=489;
	   		posi[2]=440;
	   		posi[3]=670;
	   		judge[0]=3;
	   		judge[1]=1;	
			break;  
		
		default:
	   		posi[0]=300;
	   		posi[1]=489;
	   		posi[2]=500;
	   		posi[3]=730;
	   		judge[0]=3;
	   		judge[1]=1;	  				    				 				
		   	break;  		
	   }
	   
			if(move(shuru)==1) 
			{
				number_1[1]++;				
			}
			if(move(shuru)==2)
			{
				number_2[1]++;
			}
	
			for(k=0;k<number_1[1];k++)
			{
			posi[2]-=30;
			posi[3]-=30;	
			posi[4]-=30;			
			}
			for(k=0;k<number_2[1];k++)
			{
			posi[2]+=30;
			posi[3]+=30;
			posi[4]+=30;				
			}			
			   
	   //��С 
	if(strstr(shuru_1[i],"��")!=NULL||
	strstr(shuru_1[i],"��")!=NULL||
	strstr(shuru_1[i],"׳")!=NULL)
		posi[0]=200; 
	put_picture_boy(posi,judge,page,color);
	}
	
	
	
	//�� 
	if(strstr(shuru_1[i],"��")!=NULL&&strstr(shuru_1[i],"����")==NULL)
	{	
		//λ��	
		switch(judge_position(shuru_1[i]))
		{
			case 1:
				posi[0]=390;
				posi[1]=476;
				posi[2]=140;
				posi[3]=320;
				judge[0]=3;
				judge[1]=1;
				break;
			case 2:
				posi[0]=390;
				posi[1]=476;
				posi[2]=860;
				posi[3]=910;
				judge[0]=4;
				judge[1]=1;	
				break;
	
			default:
				posi[0]=390;
				posi[1]=476;
				posi[4]=530;
				posi[5]=400;
				judge[0]=5;
				judge[1]=1;	
				break;
					
		}

		if(move(shuru)==1)//���� 
		{
			number_1[2]++;
			for(k=0;k<number_1[2];k++)
			{
			posi[2]-=30;
			posi[3]-=30;				
			}
		}
		else if(move(shuru)==2)
		{
			number_2[2]++;
			for(k=0;k<number_2[2];k++)
			{
			posi[2]+=30;
			posi[3]+=30;				
			}
		}	
		//��С 
		if(strstr(shuru_1[i],"��")!=NULL)
		{
			posi[0]=330;
		}
		
		//���� 
		if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			put_picture_fish1(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			put_picture_fish2(posi,judge,page,color);
			n=2;
		}		
		else//δ��˵�����Զ����� 
		{
			put_picture_fish1(posi,judge,page,color);
			n=1;
		}
		if(strstr(shuru_1[i],"���")!=NULL)		
		{
			fill_1(color,page);
		}					
	}
	
	//���� 
	if(strstr(shuru_1[i],"����")!=NULL&&strstr(shuru_1[i],"��")!=NULL) 
	{
			posi[0]=320;
			posi[1]=460;
			posi[2]=160;
			posi[3]=350;
			judge[0]=3;
			judge[1]=1; 

		if(strstr(shuru_1[i],"С")!=NULL)
		{
			posi[0]=390;			
		}
			
		if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			put_picture_fish1(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			put_picture_fish2(posi,judge,page,color);
			n=2;
		}		
		else//δ��˵�����Զ����� 
		{
			put_picture_fish1(posi,judge,page,color);
			n=1;
		}					
		
		//�ڶ��� 
		posi[2]=560;
		posi[3]=850;
				
		if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			put_picture_fish1(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			put_picture_fish2(posi,judge,page,color);
			n=2;
		}		
		else//δ��˵�����Զ����� 
		{
			put_picture_fish1(posi,judge,page,color);
			n=1;	
		}					
	}	

	//�� 
	if(strstr(shuru_1[i],"��")!=NULL&&strstr(shuru_1[i],"����")==NULL)
	{	
		//λ��	
		switch(judge_position(shuru_1[i]))
		{
			case 1:
				posi[0]=180;
				posi[1]=600;
				posi[2]=40;
				posi[3]=320;
				judge[0]=3;
				judge[1]=1;
				if(strstr(shuru_1[i],"����")!=NULL||
					strstr(shuru_1[i],"����")!=NULL)
					{
						posi[2]+=70; 
					}	
				else
				{
					posi[2]-=70;	
				}	
				break;
			case 2:
				posi[0]=180;
				posi[1]=600;
				posi[2]=520;
				posi[3]=980;
				judge[0]=4;
				judge[1]=1;	
				
				if(strstr(shuru_1[i],"����")!=NULL||
					strstr(shuru_1[i],"����")!=NULL)
					{
						; 
					}
				else
					{
						posi[3]-=290; 
					}	
				break;
			default:
				posi[0]=180;
				posi[1]=600;
				posi[4]=530;
				posi[5]=376;
				judge[0]=5;
				judge[1]=1;	
				
				if(strstr(shuru_1[i],"����")!=NULL||
					strstr(shuru_1[i],"����")!=NULL)
					{
						; 
					}
				else
				{
					posi[4]-=200;
				}
				break;
					
		}

		if(move(shuru)==1)//���� 
		{
			number_1[3]++;
			for(k=0;k<number_1[3];k++)
			{
			posi[2]-=30;
			posi[3]-=30;				
			}
		}
		else if(move(shuru)==2)
		{
			number_2[3]++;
			for(k=0;k<number_2[3];k++)
			{
			posi[2]+=30;
			posi[3]+=30;				
			}
		}			
		//��С 
		if(strstr(shuru_1[i],"С")!=NULL)
		{
			posi[0]=230;
			posi[1]-=20; 
		}
		
		//���� 
		if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
			
			if(strstr(shuru_1[i],"���")!=NULL)		
			{
				put_picture_dog2_fill(posi,judge,page,color);
			}	
			else	
			put_picture_dog2(posi,judge,page,color);
			n=1;
		}
		else if(strstr(shuru_1[i],"����")!=NULL||
		strstr(shuru_1[i],"����")!=NULL)
		{
		if(strstr(shuru_1[i],"���")!=NULL)		
		{
			put_picture_dog1_fill(posi,judge,page,color);
		}		
		else
			put_picture_dog1(posi,judge,page,color);
			n=2;
		}		
		else//δ��˵�����Զ����� 
		{
		if(strstr(shuru_1[i],"���")!=NULL)		
		{
			put_picture_dog2_fill(posi,judge,page,color);
		}		
		else
			put_picture_dog2(posi,judge,page,color);
			n=1;
		}			
	}

	i++;
	}
	j++;
}

//����ģʽ�����һ��ͼ�ε��ƶ� 
int move(char* shuru)
{
	if(strstr(shuru,"����")!=NULL) 
	{
		return 1;
	}
	else if(strstr(shuru,"����")!=NULL)
	{
		return 2; 
	}
}
