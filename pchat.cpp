
/*
/*�ļ����ƣ�pchat
/*�ļ�Ŀ�ģ�AI�������
/*ʱ�临�Ӷȣ�AIʱ�临�Ӷ�
/*�ռ临�Ӷȣ�ʵ���������ض�Ӧ�Ŀռ�
*/

#include<stdio.h>
#include<string.h>
#include<input.h>
#include<AI.h>
#include<page.h>
#include<mouse.h>
#include<dos.h>
#include<pchat.h>
#include<color.h>
#include<draw.h>
#include<hz.h>
#include<fenci.h>
#include<ptext.h>

extern int MouseX,MouseY,MouseS,press;
extern void* buffer;
extern union REGS our_AI_regs;
extern int MouseX_memory,MouseY_memory;

char far input[51][421];

//�������ƣ�page_chat1
//����Ŀ�ģ�ʵ�������������Ͱ�������

int page_chat1()
{
	int i;
	static int input_counter=1;
  //	int status=0;
	int ha,ah;
	int j;
	int zishu=0;
	int sha=0;
	for(i=0;i<51;i++)
	{
		for(j=0;j<421;j++)
		{
			input[i][j]='\0';
		}
	}
	char inputinput[101]={0};
	int page=PAGE_CHAT1;
	int kkk;
	int asc2hanzi;
	int keyboard=0;
	page_SVGA_chat1(page,keyboard);
	//FILE *fpp;
	//mread(&MouseX,&MouseY,&MouseS);
	//clrmous(MouseX,MouseY,page);
	delay(20);
	//save_bk_mou(MouseX,MouseY);
	mouseinit(page);
	//char input[1001];//֧������500�����֣�2����=1���֣�
	//char *input=(char*)malloc(10001);//֧������5000�����֣�2����=1���֣�
	//char *eventual=(char*)malloc(10001);
	//int status=0;
	char py[100]={0};
	char save[3]={0,0,0};
	int choose=0;//0�������ģ�1������ͼ
	int counting=0;
	int asc2number=0;
	char value;
	int hanzinumber=0;
	int tempp;
	int pianyi;
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press,page);
		//mread(&MouseX,&MouseY,&press);
		memory_mouse(MouseX,MouseY,page);
		//drawmous(MouseX,MouseY,page);
		mouse_drawing(MouseX,MouseY,page);
		delay(20);
		truly_clean_mouse(MouseX,MouseY,page);
		//��������
		if(MouseX>=85&&MouseX<=935&&MouseY>=609&&MouseY<=768)
		{
			if(mouse_press(85,650,935,738)==2)
			{
				//if(status==0)
				{
					MouseS=2;
			//		status=2;
				}
				continue;
			}
			else if(mouse_press(85,650,935,738)==1)
			{
		  //		status=2;
				MouseS=0;
				color_change_chat1(2,page);
				while(1)
				{
					huiqu:
				if(24*asc2number+32*hanzinumber<20*32)
				{
					;
				}
				else
				{
					while(1)
					{
						newmouse(&MouseX, &MouseY, &press,page);
						//mread(&MouseX,&MouseY,&press);
						memory_mouse(MouseX, MouseY, page);
						//drawmous(MouseX,MouseY,page);
						mouse_drawing(MouseX, MouseY, page);
						delay(20);
						truly_clean_mouse(MouseX, MouseY, page);
						//�˳�
						if(MouseX>=964&&MouseX<=1024&&MouseY>=0&&MouseY<=60)
						{
							if(mouse_press(964,0,1024,60)==2)
							{
								//if(status==0)
								//{
									MouseS=1;
		//							status=1;
								//}
								continue;
							}
							else if(mouse_press(964,0,1024,60)==1)
							{
								for(i=1;i<51;i++)
								{
									memset(input[i],0,421);
								}
								input_counter=1;
								color_change_chat1(1,page);
	  //							status=1;
								MouseS=0;
								page=PAGE_START;
								change_page(&page);
							}
						}
						//�����İ���
						if(MouseX>=85&&MouseX<=235&&MouseY>=585&&MouseY<=638)
						{
							if(mouse_press(85,585,235,638)==2)
							{
								//if(status==0)
								//{
									MouseS=1;
		 //							status=3;
								//}
								continue;
							}
							else if(mouse_press(85,585,235,638)==1)
							{
								//wenshengwen:
								input_counter=0;
								for(kkk=0;kkk<51;kkk++)
								{
									memset(input[kkk],0,421);
								}
								color_change_chat1(3,page);
		 //						status=3;
								MouseS=0;
								choose=0;
								strcpy(input[0],"���ã�������ʲô���԰���������");
								input_counter=1;
							}
						}
						//����ͼ����
						if(MouseX>=315&&MouseX<=465&&MouseY>=585&&MouseY<=638)
						{
							if(mouse_press(315,585,465,638)==2)
							{
								//if(status==0)
								//{
									MouseS=1;
	   //								status=4;
								//}
								continue;
							}
							else if(mouse_press(315,585,465,638)==1)
							{
								//wenshengtutu:
								input_counter=0;
								for(kkk=0;kkk<51;kkk++)
								{
									memset(input[kkk],0,421);
								}
								color_change_chat1(4,page);
	 //							status=4;
								MouseS=0;
								choose=1;
							}
						}
						//��ͷ��
						if(MouseX>=947&&MouseX<=1011&&MouseY>=662&&MouseY<=726)
						{
							if(mouse_press(947,662,1011,726)==2)
							{
								//if(status==0)
								//{
									MouseS=1;
		//							status=5;
								//}
								continue;
							}
							else if(mouse_press(947,662,1011,726)==1)
							{
								fill_color(85, 650, 935, 738, SNOW_, page, 0);
								color_change_chat1(5,page);
		//						status=5;
								MouseS=0;
								goto zhenhao;
								//ִ��AI���ܵ���ں���->������

								//fenci(input,eventual);
								//fill_color(85,650,935,738,SNOW_,page);
							}
								}
							//����λ��
							else
							{
								MouseS=0;
	  //							status=0;
							}
/*
							if(kbhit())
							{
								value=bioskey(0);
								if(value=='\b')
								{
									if(inputinput[strlen(inputinput)-1]>0)
									{
										fill_color(85+24*asc2number+32*hanzinumber-24,650,85+24*asc2number+32*hanzinumber,738,SNOW_,page,0);
										//-24
										asc2number--;
										counting--;
										inputinput[strlen(inputinput)-1]='\0';
									}
									else
									{
										fill_color(85+24*asc2number+32*hanzinumber-32,650,85+24*asc2number+32*hanzinumber,738,SNOW_,page,0);
										//-32
										hanzinumber--;
										counting-=2;
										inputinput[strlen(inputinput)-1]='\0';
										inputinput[strlen(inputinput)-1]='\0';
									}
									goto huiqu;
								}
							}*/
					}
					//zishu=0;
					//asc2number=0;
					//hanzinumber=0;
					//fill_color(85,650,935,738,SNOW_,page,0);
				}
					tempp=input_method(150+24*asc2number+32*hanzinumber,609,save,BLACK_,py,page,&choose,&keyboard,&pianyi,inputinput,&input_counter);

					if(save[0]==32||save[0]==13)
					{
						continue;
					}
					if(tempp==666)
					{
						if(save[0]>='0'&&save[0]<='9')
						{
							;
						}
						else if(save[0]=='+'||save[0]=='-'||save[0]=='*'
						||save[0]=='/'||save[0]=='='||save[0]==','
						||save[0]=='!'||save[0]=='.'||save[0]=='?')
						{
							;
						}
						else
						{
							continue;
						}
					}

					if(save[0]>0)
					{
						asc2number++;
					}
					else if(save[0]<0)
					{
						hanzinumber++;
					}

					if(tempp==500)
					{
						goto wenshengwen;
					}
					if(tempp==2001)
					{
						goto wenshengtutu;
					}
					if(tempp==100)//�������y���߼�����
					{
						if(inputinput[0]!='\0')
						{
							zhenhao:
							strcpy(input[input_counter++],inputinput);
							//Ҫ��Ҫɾ������6��ASC2�ַ�������
							//display_text(input,0,page);

							if(input[49][0]!='\0')
							{
								for(ha=0;ha<51;ha++)
								{
									for(ah=0;ah<421;ah++)
									{
										input[ha][ah]='\0';
									}
								}
								strcpy(input[0],"���Զ�Ϊ�������¶Ի�");
								strcpy(input[1],inputinput);
								input_counter=2;
								keyboard=0;
							}
							entrance(page,&keyboard,choose,&input_counter);
							asc2number=0;
							hanzinumber=0;
							zishu=0;
							MouseS=0;
							counting=0;
							memset(inputinput,0,101);
						}
					}
					else if((tempp==4||tempp==3)&&inputinput[0]!='\0')
					{
						if(inputinput[counting-1]>0)
						{
							zishu-=24;
							asc2number--;
							counting--;
							inputinput[counting]='\0';
						}
						else
						{
							zishu-=32;
							hanzinumber--;
							counting-=2;
							inputinput[counting]='\0';
							inputinput[counting+1]='\0';
						}
						goto x9;
					}
					else if((tempp==4||tempp==3)&&inputinput[0]=='\0')
					{
						//number--;
						goto x9;
					}
					else
					{
						;
					}

					if(save[0]==0&&save[1]==0)
					{
						//if(number>0)
						//{
							//number--;
						//}
						goto x9;
					}
					//fpp=fopen("C:\\CODE\\data\\tempchat.txt","rt+");
					//fputc(save[0],fpp);
					//fputc(save[1],fpp);
					//fputc(save[2],fpp);
					//fpp--;
					if(save[0]>='0'&&save[0]<='9')
					{
						save[1]=' ';
					}
					else if(save[0]>='a'&&save[0]<='z')
					{
						save[0]='\0';
						save[1]='\0';
						sha=1;
					}
					else if(save[0]>='A'&&save[0]<='Z')
					{
						save[0]='\0';
						save[1]='\0';
						sha=1;
					}
					if(save[1]==' ')
					{
						inputinput[counting++]=save[0];
						save[1]='\0';
					}
					else
					{
						if(save[0]!='\0')
						{
							inputinput[counting++]=save[0];
						}
						if(save[1]!='\0')
						{
							inputinput[counting++]=save[1];
						}
					}

					if(inputinput[0]>0)
					{
						asc2hanzi=0;
					}
					else
					{
						asc2hanzi=1;
					}

					if(sha==0)
					{
						if(save[1]==' ')
						{
							save[1]='\0';
							if(asc2hanzi==0)
								string_drawing(save,85+asc2number*24+hanzinumber*32-24,650,32,20,12,-8,BLACK_,320,320,page,0);
							else
								string_drawing(save,85+asc2number*24+hanzinumber*32-32,650,32,20,12,-8,BLACK_,320,320,page,0);
							//zishu+=24;
							save[1]=' ';
						}
						else
						{
							if(asc2hanzi==0)
								string_drawing(save,85+asc2number*24+hanzinumber*32-24,650,32,20,12,-8,BLACK_,320,320,page,0);
							else
								string_drawing(save,85+asc2number*24+hanzinumber*32-32,650,32,20,12,-8,BLACK_,320,320,page,0);
							//zishu+=32;
						}
					}
					else if(sha==1)
					{
						counting-=2;
						sha=0;
						//number--;
					}
					//string_drawing(input,85,650,32,20,12,-8,BLACK_,32,32,page);//test
					x9:memset(save,0,2);
					//save[0]=0;
					//save[1]=0;
					memset(py,0,100);
				}
			  //	continue;
			}
		}
			//�˳�
			if(MouseX>=964&&MouseX<=1024&&MouseY>=0&&MouseY<=60)
			{
				if(mouse_press(964,0,1024,60)==2)
				{
					//if(status==0)
					//{
						MouseS=1;
			//			status=1;
					//}
					continue;
				}
				else if(mouse_press(964,0,1024,60)==1)
				{
					for(i=1;i<21;i++)
					{
						memset(input[i],0,421);
					}
					input_counter=1;
					color_change_chat1(1,page);
		  //			status=1;
					MouseS=0;
					page=PAGE_START;
					change_page(&page);
				}
			}
			//�����İ���
			if(MouseX>=85&&MouseX<=235&&MouseY>=585&&MouseY<=638)
			{
				if(mouse_press(85,585,235,638)==2)
				{
					//if(status==0)
					//{
						MouseS=1;
		 //				status=3;
					//}
					continue;
				}
				else if(mouse_press(85,585,235,638)==1)
				{
					wenshengwen:
					input_counter=0;
					for(kkk=0;kkk<21;kkk++)
					{
						memset(input[kkk],0,421);
					}
					color_change_chat1(3,page);
			//		status=3;
					MouseS=0;
					choose=0;
					strcpy(input[0],"���ã�������ʲô���԰���������");
					input_counter=1;
				}
			}
			//����ͼ����
			if(MouseX>=315&&MouseX<=465&&MouseY>=585&&MouseY<=638)
			{
				if(mouse_press(315,585,465,638)==2)
				{
					//if(status==0)
					//{
						MouseS=1;
		  //				status=4;
					//}
					continue;
				}
				else if(mouse_press(315,585,465,638)==1)
				{
					wenshengtutu:
					input_counter=0;
					for(kkk=0;kkk<21;kkk++)
					{
						memset(input[kkk],0,421);
					}
					color_change_chat1(4,page);
				//	status=4;
					MouseS=0;
					choose=1;
				}
			}
			//��ͷ��
			if(MouseX>=947&&MouseX<=1011&&MouseY>=662&&MouseY<=726)
			{
				if(mouse_press(947,662,1011,726)==2)
				{
					//if(status==0)
					//{
						MouseS=1;
			  //			status=5;
					//}
					continue;
				}
				else if(mouse_press(947,662,1011,726)==1)
				{
					color_change_chat1(5,page);
			//		status=5;
					MouseS=0;
					//ִ��AI���ܵ���ں���->������

					//fenci(input,eventual);
					//fill_color(85,650,935,738,SNOW_,page);
				}
			}
		//����λ��
		else
		{
			MouseS=0;
		  //	status=0;
		}
	}
   //	return choose;
}

//�������ƣ�page_SVGA_chat1
//����Ŀ�ģ�����������chat1�Ľ���

int page_SVGA_chat1(int page,int keyboard)
{
   //	int pianyi=0;//ƫ������ʼΪ0
	line_drawing(0,576,1024,576,BLACK_,page,0);
	//fill_color(0,0,1024,575,SPRING_GREEN_,page);
	fill_color(0,577,1024,764,GAINSBORO_,page,0);

	fill_color(85,650,935,738,SNOW_,page,0);//�Ի���
	fill_color(85,585,235,638,RED_,page,0);//�����İ���
	fill_color(315,585,465,638,RED_,page,0);//����ͼ����

	//��ԲȦ
	circle_with_drawing(979,694,32,ROSY_BROWN_,page,0);

	//����ͷ
	for(int i=0;i<=2;i++)
	{
		line_drawing(979+i,670,979+i,718,BLUE_,page,0);
		line_drawing(959+i,690,979+i,670,BLUE_,page,0);
		line_drawing(999+i,690,979+i,670,BLUE_,page,0);
	}

	//д����
	string_drawing("������",111,595,32,20,12,-8,SNOW_,1000,1000,page,0);
	string_drawing("����ͼ",341,595,32,20,12,-8,SNOW_,1000,1000,page,0);
	//�˳���
	fill_color(964,0,1024,60,RED_,page,0);
	for(i=-2;i<=2;i++)
	{
		line_drawing(968+i,8,1020+i,52,WHITE_,page,0);
		line_drawing(1020+i,8,968+i,52,WHITE_,page,0);
	}
	//�Ի������
	strcpy(input[0],"���ã�������ʲô���԰�������");
	display_text(input,0,page,keyboard);
	return 0;
}

//�������ƣ�color_change_chat1
//����Ŀ�ģ�ʵ��chat1����ɫ�任

void color_change_chat1(int i,int page)
{
	int j;
	//clrmous(MouseX,MouseY,page);
	delay(10);
	switch(i)
	{
		//�˳�
		case 1:
			fill_color(964,0,1024,60,DARK_GRAY_,page,0);
			break;
		//����
		case 2:
			;
			break;
		//�����İ���
		case 3:
			fill_color(85,585,235,638,DARK_GRAY_,page,0);
			delay(1000);
			fill_color(85,585,235,638,RED_,page,0);
			string_drawing("������",111,595,32,20,12,-8,SNOW_,1000,1000,page,0);
			break;
		//����ͼ����
		case 4:
			fill_color(315,585,465,638,DARK_GRAY_,page,0);
			delay(1000);
			fill_color(315,585,465,638,RED_,page,0);
			string_drawing("����ͼ",341,595,32,20,12,-8,SNOW_,1000,1000,page,0);
			break;
		case 5:
			circle_with_drawing(979,694,32,DARK_GRAY_,page,0);
			delay(1000);
			circle_with_drawing(979,694,32,ROSY_BROWN_,page,0);
			for(j=0;j<=2;j++)
			{
				line_drawing(979+j,670,979+j,718,BLUE_,page,0);
				line_drawing(959+j,690,979+j,670,BLUE_,page,0);
				line_drawing(999+j,690,979+j,670,BLUE_,page,0);
			}
			break;
	}
}
