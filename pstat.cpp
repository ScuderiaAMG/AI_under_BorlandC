
/*
** �ļ����ƣ�pstat
** �ļ�Ŀ�ģ�ʵ�ֵ�¼ҳ��Ļ�ͼ
** ʱ�临�Ӷȣ�Bresenham�㷨��Ӧ�ĸ��Ӷ�
** �ռ临�Ӷȣ������ҳ�����ش�С
*/

#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<draw.h>
#include<color.h>
#include<page.h>
#include<mouse.h>
#include<dos.h>
#include<time.h>
#include<bios.h>
#include<xiezi.h>
#include<pstat.h>
#include<English.h>
#include<pregi.h>
#include<input.h>
#include<Bezier.h>
#include<ptext.h>

extern int MouseX,MouseY,MouseS,press;
extern void* buffer;
extern union REGS our_AI_regs;
extern int MouseX_memory,MouseY_memory;


//�������ƣ�page_start
//����Ŀ�ģ�ʵ�ֵ�¼

int page_start(int page)
{
	//���Ͻǵ�С������
	int i;
	fill_color(0,0,1024,768,SPRING_GREEN_,page,0);
	circle_with_drawing(224,210,140,SNOW_,page,0);
	fill_color(154,138,294,212,ROSY_BROWN_,page,0);
	circle_with_drawing(192,176,20,YELLOW_,page,0);
	circle_with_drawing(256,176,20,YELLOW_,page,0);
	for(i=-3;i<=3;i++)
	{
		line_drawing(192+i,138,192+i,114,COCOUNT_BROWN_,page,0);
		line_drawing(256+i,138,256+i,114,COCOUNT_BROWN_,page,0);
	}//��΢��һ��
	circle_with_drawing(192,101,13,SPRING_GREEN_,page,0);
	circle_with_drawing(256,101,13,SPRING_GREEN_,page,0);
	fill_color(192,212,256,338,ROSY_BROWN_,page,0);
	for(i=-2;i<=2;i++)
	{
		line_drawing(192,256+i,154,256+i,ROSY_BROWN_,page,0);
		line_drawing(256,256+i,294,256+i,ROSY_BROWN_,page,0);
	}
	for(i=0;i<5;i++)
	{
		line_drawing(154-i,226,154-i,286,ROSY_BROWN_,page,0);
		line_drawing(294+i,226,294+i,286,ROSY_BROWN_,page,0);
		line_drawing(154,226-i,129,226-i,ROSY_BROWN_,page,0);
		line_drawing(154,286+i,129,286+i,ROSY_BROWN_,page,0);
		line_drawing(294,226-i,319,226-i,ROSY_BROWN_,page,0);
		line_drawing(294,286+i,319,286+i,ROSY_BROWN_,page,0);
	}

	circle_with_drawing(224,252,29,LIGHT_SALMON,page,0);
	fill_color(192,212,256,252,ROSY_BROWN_,page,0);

	circle_with_drawing(256,176,5,RED_,page,0);
	circle_with_drawing(192,176,5,RED_,page,0);

	fill_color(206,252,218,264,WHITE_,page,0);
	fill_color(230,252,242,264,WHITE_,page,0);

	//���Ͻǵ�����
	string_drawing("�����������֣�С��",440,150,48,26,15,0,RED_,4000,12,page,0);
	//string_drawing("AI",850,150,32,20,12,-8,RED_,400,12,page,0);
	//string_drawing("produced by",530,250,24,15,9,-6,RED_,348,9,page,0);
	//string_drawing("���ߣ������ܣ������",480,250,24,15,9,-6,RED_,1000,12,page,0);
	string_drawing("���ߣ���",480,250,24,15,9,-6,RED_,1000,12,page,0);
	string_drawing("��",480+5*24+4,250,24,15,9,-6,RED_,1000,12,page,0);
	fill_color(480+5*24+4,250,480+5*24+12,300,SPRING_GREEN_,page,0);
	string_drawing("��",480+5*24-9,250,24,15,9,-6,RED_,1000,12,page,0);
	fill_color(480+5*24-8,250,480+5*24-1,300,SPRING_GREEN_,page,0);
	string_drawing("��",480+4*24,250,24,15,9,-6,RED_,1000,12,page,0);
	//fill_color(480+5*24,250,480+5*24+8,300,SPRING_GREEN_,page,0);
	//string_drawing("�",480+5*24,253,24,15,9,-6,RED_,1000,12,page,0);
	//fill_color(480+5*24+12,250,480+5*24+24,300,SPRING_GREEN_,page,0);

	//fill_color(480+5*24+20,250,480+5*24+32,300,SPRING_GREEN_,page,0);
	string_drawing("�������",480+6*24+4,250,24,15,9,-6,RED_,1000,12,page,0);
	//����Ŀ�
	string_drawing("�û�����",100,440,32,20,12,-8,BLUE_,128,12,page,0);
	string_drawing("���룺",120,580,32,20,12,-8,BLUE_,96,12,page,0);
	fill_color(310,420,850,510,TROPICAL_ORANGE_,page,0);//�û���
	fill_color(310,560,850,650,TROPICAL_ORANGE_,page,0);//����
	fill_color(150,680,480,750,TROPICAL_ORANGE_,page,0);//��¼
	fill_color(530,680,860,750,TROPICAL_ORANGE_,page,0);//ע��
	string_drawing("��¼",260,700,32,20,12,-8,BLUE_,64,12,page,0);
	string_drawing("ע��",645,700,32,20,12,-8,BLUE_,64,12,page,0);
	//�ò��ֻ���֮������ٸģ�ҲҪ������ĵ�¼ע���������
	fill_color(964,0,1024,60,RED_,page,0);
	for(i=-2;i<=2;i++)
	{
		line_drawing(968+i,8,1020+i,52,WHITE_,page,0);
		line_drawing(1020+i,8,968+i,52,WHITE_,page,0);
	}
	//�����ϽǵĲ��
	while(1)
	{
		mouse_page_start(page,&i);
		delay(20);
	}
	return PAGE_START;
}

//�������ƣ�mouse_page_start
//����Ŀ�ģ�ʵ�ֵ�¼ע����������ƶ��͵����ת

void mouse_page_start(int page,int *num)
{

	//mread(&MouseX,&MouseY,&MouseS);
	//memory_mouse(MouseX,MouseY);
	mouseinit(page);
	//truly_clean_mouse(MouseX,MouseY);
	//clrmous(MouseX,MouseY,page);
	//delay(20);
	//save_bk_mou(MouseX,MouseY);
	int status=0;
	int position=0;//�ж��Ƿ���������
	int temp=TEST_INPUT;
	char str[16]={0};
	char password_recording[16]={0};
	char str_input[16]={0};
	char password_recording_input[16]={0};
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press,page);
		//mread(&MouseX,&MouseY,&press);
		memory_mouse(MouseX,MouseY,page);
		//drawmous(MouseX,MouseY,page);
		mouse_drawing(MouseX,MouseY,page);
		delay(20);
		truly_clean_mouse(MouseX,MouseY,page);
		//�û���
		if(MouseX>=310&&MouseX<=850&&MouseY>=420&&MouseY<=510)
		{
			if(mouse_press(310,420,850,510)==2)
			{
				MouseS=2;
				if(status==0&&position==0)
				{
					status=1;//bug:status!=1
				}
				continue;
			}
			else if(mouse_press(310,420,850,510)==1)
			{
				status=1;
				color_change_mouse(1,page);
				MouseS=0;
				//memset(str_input,0,16);
				visible_input1(str_input,310,420,15,BLACK_,GAINSBORO_,page);
				//str_input[0]='\0';
				if(temp==ILLEGAL_INPUT)
				{
					string_inspection(page);
					temp=TEST_INPUT;
					page=0;
					//break;
				}
				if(temp==LEGAL_INPUT)
				{
					if(strlen(str_input)!=0)
					{
						position=1;
					}
					else
					{
						position=0;
					}
					temp=TEST_INPUT;
					continue;
				}
			}
		}
		//����
		else if(MouseX>=310&&MouseX<=850&&MouseY>=560&&MouseY<=650)
		{
			if(mouse_press(310,560,850,650)==2)
			{
				MouseS=2;
				if(status==0&&position==0)
				{
					status=2;
				}
				continue;
			}
			else if(mouse_press(310,560,850,650)==1)
			{
				status=2;
				color_change_mouse(2,page);
				MouseS=0;
				invisible_input1(password_recording_input,310,560,15,BLACK_,GAINSBORO_,page);
				str[0]='\0';
				if(temp==ILLEGAL_INPUT)
				{
					string_inspection(page);
					temp=TEST_INPUT;
					page=0;
					//break;
				}
				if(temp==LEGAL_INPUT)
				{
					if(strlen(str)!=0)
					{
						position=1;
					}
					else
					{
						position=0;
					}
					temp=TEST_INPUT;
					continue;
				}
			}
		}
		//��¼
		else if(MouseX>=150&&MouseX<=480&&MouseY>=680&&MouseY<=750)
		{
			if(mouse_press(150,680,480,750)==2)
			{
				MouseS=1;
				status=3;
				if(status==0)
				{
					color_change_mouse(3,page);
					status=3;
				}
				continue;
			}
			else if(mouse_press(150,680,480,750)==1)
			{
				color_change_mouse(3,page);
				//text_register("flag1","flag2");//test

				/*
				getchar();
				string_drawing(password_recording_input,0,0,48,26,15,0,TROPICAL_ORANGE_,BIG_NUMBER,BIG_NUMBER,page);
				getchar();
				exit(1);
				***********************************test***********************************
				*/

				status=3;
				MouseS=0;
				if(password_judge(str_input,password_recording_input,num,page)==1)
				{
					fill_color(0,0,1024,768,WHITE_,page,0);
					string_drawing("��¼�ɹ���",274,220,48,26,15,0,TROPICAL_ORANGE_,BIG_NUMBER,BIG_NUMBER,page,0);
					delay(2000);
					fill_color(274,220,524,268,WHITE_,page,0);
					page=PAGE_CHAT1;
					change_page(&page);//��ת���û����ܽ���
					break;
				}
				else
				{
					//fill_color(270,225,370,255,DARK_GRAY_,page);
					//string_drawing("��¼ʧ�ܣ�",274,220,48,26,15,0,TROPICAL_ORANGE_,BIG_NUMBER,BIG_NUMBER,page);
					//delay(20);

				}
			}
		}
		//ע��
		else if(MouseX>=530&&MouseX<=860&&MouseY>=680&&MouseY<=750)
		{
			if(mouse_press(530,680,860,750)==2)
			{
				MouseS=1;
				if(status==0)
				{
					color_change_mouse(4,page);
					status=4;
				}
				continue;
			}
			else if(mouse_press(530,680,860,750)==1)
			{
				MouseS=0;
				color_change_mouse(4,page);
				page=PAGE_REGISTER;
				change_page(&page);
				break;
			}
		}
		//�˳�
		else if(MouseX>=964&&MouseX<=1024&&MouseY>=0&&MouseY<=60)
		{
			if(mouse_press(964,0,1024,60)==2)
			{
				MouseS=1;
				if(status==0)
				{
					color_change_mouse(5,page);
					status=5;
				}
				continue;
			}
			else if(mouse_press(964,0,1024,60)==1)
			{
				color_change_mouse(5,page);
				MouseS=0;
				delay(200);
				exit(1);
				break;
			}
		}
		//����λ��
		else
		{

			switch(status)
			{
				/*
				case 1:
					color_change_back_mouse(1,page);
					break;
				case 2:
					color_change_back_mouse(2,page);
					break;
				*/
				case 3:
					color_change_back_mouse(3,page);
					break;
			}

			MouseS=0;
			//color_change_mouse(6,page);
			status=6;
		}
	}
}

//�������ƣ�color_change_mouse
//����Ŀ�ģ������ĵ�������淢���仯

void color_change_mouse(int i,int page)
{
	//clrmous(MouseX,MouseY,page);
	delay(10);
	switch(i)
	{
		case 1:
			//�û���
			fill_color(310,420,850,510,GAINSBORO_,page,0);
			break;
		case 2:
			//����
			fill_color(310,560,850,650,GAINSBORO_,page,0);
			break;
		case 3:
			//��¼
			fill_color(150,680,480,750,GAINSBORO_,page,0);
			string_drawing("��¼",220,700,32,20,12,-8,BLUE_,64,12,page,0);
			break;
		case 4:
			//ע��
			fill_color(530,680,860,750,GAINSBORO_,page,0);
			string_drawing("ע��",600,700,32,20,12,-8,BLUE_,64,12,page,0);
			break;
		case 5:
			//�˳�
			fill_color(964,0,1024,60,SALMON_,page,0);
			break;
		default:
			fill_color(310,420,850,510,TROPICAL_ORANGE_,page,0);//�û���
			fill_color(310,560,850,650,TROPICAL_ORANGE_,page,0);//����
			fill_color(150,680,480,750,TROPICAL_ORANGE_,page,0);//��¼
			fill_color(530,680,860,750,TROPICAL_ORANGE_,page,0);//ע��
			fill_color(964,0,1024,60,RED_,page,0);
			for(i=-2;i<=2;i++)
			{
				line_drawing(968+i,8,1020+i,52,WHITE_,page,0);
				line_drawing(1020+i,8,968+i,52,WHITE_,page,0);
			}
			break;
	}

}

//�������ƣ�color_change_back_mouse
//����Ŀ�ģ����仯�Ŀ������

void color_change_back_mouse(int i,int page)
{
	switch(i)
	{
		case 1:
			fill_color(310,420,850,510,TROPICAL_ORANGE_,page,0);
			break;
		case 2:
			fill_color(310,560,850,650,TROPICAL_ORANGE_,page,0);
			break;
		case 3:
			fill_color(150,680,480,750,TROPICAL_ORANGE_,page,0);
			string_drawing("��¼",260,700,32,20,12,-8,BLUE_,64,12,page,0);
			break;
	}
}


//�������ƣ�string_inspection
//����Ŀ�ģ��ַ�������Υ���ַ���ʾ

void string_inspection(int page)
{
	string_drawing("ֻ���������ֺ���ĸ",330,430,32,20,12,-8,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
}

//�������ƣ�password_judge
//����Ŀ�ģ��ж������Ƿ���ȷ

int password_judge(char *str,char *password_record,int *n,int page)
{
	int haoma;
	int i;
	FILE *fp;
	//LOGIN *input_now=NULL;
	char input_now[35];
	char pass[17]={0};
	char name[15]={0};
	char read_information[34];
	char temp;
	if((fp=fopen("C:\\CODE\\data\\password.dat","rb+"))==NULL)
	{
		printf("�޷�������⣡������˳�");
		getchar();
		exit(1);
	}
	//��֪�ļ����
	fseek(fp,0,SEEK_END);
	long int size=ftell(fp)/34;
	int size_record=0;
	//�����ַ����ıȶ�
	strcpy(input_now,"  ");
	for(i=2;i<18;i++)
	{
		input_now[i]=str[i-2];
	}
	for(i=17;i<33;i++)
	{
		input_now[i]=password_record[i-17];
	}
	input_now[33]=' ';
	input_now[34]='\0';
	for(i=0;i<34;i++)
	{
		if((input_now[i]>='a'&&input_now[i]<='z')
		||(input_now[i]>='A'&&input_now[i]<='Z')
		||(input_now[i]>='0'&&input_now[i]<='9'))
		{
			;
		}
		else
		{
			input_now[i]=' ';
		}
	}
	//string_drawing(input_now,0,0,48,26,15,0,RED_,BIG_NUMBER,BIG_NUMBER,page);//test
	fseek(fp,0,SEEK_SET);
	while(1)
	{
		 size_record++;
		for(i=0;i<34;i++)
		{
			temp=getc(fp);
			read_information[i]=temp;
			if((read_information[i]>='a'&&read_information[i]<='z')
			||(read_information[i]>='A'&&read_information[i]<='Z')
			||(read_information[i]>='0'&&read_information[i]<='9'))
			{
				;
			}
			else
			{
				read_information[i]=' ';
			}
		}

		/*
		string_drawing(read_information,0,0,48,26,15,0,RED_,BIG_NUMBER,BIG_NUMBER,page);
		break;
		//**************************************test********************************************
		*/

		if(strcmp(input_now,read_information)==0)
		{
			fill_color(530,300,730,350,SPRING_GREEN_,page,0);
			string_drawing("������ȷ",530,300,48,26,15,0,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
			//fill_color(310,420,850,510,TROPICAL_ORANGE_,page,0);//�û���
			//fill_color(310,560,850,650,TROPICAL_ORANGE_,page,0);//����
			//fill_color(150,680,480,750,TROPICAL_ORANGE_,page,0);//��¼
			//fill_color(530,680,860,750,TROPICAL_ORANGE_,page,0);//ע��
			//string_drawing("��¼",260,700,32,20,12,-8,BLUE_,64,12,page,0);
			//string_drawing("ע��",645,700,32,20,12,-8,BLUE_,64,12,page,0);
			for(i=0;i<strlen(input_now);i++)
			{
				input_now[i]=0;
			}
			for(i=0;i<strlen(read_information);i++)
			{
				read_information[i]=0;
			}
			return 1;
		}
		if(size_record==size)
		{
			string_drawing("�������",530,300,48,26,15,0,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
			fill_color(310,420,850,510,GAINSBORO_,page,0);
			fill_color(310,560,850,650,GAINSBORO_,page,0);
			fill_color(310,420,850,510,TROPICAL_ORANGE_,page,0);//�û���
			fill_color(310,560,850,650,TROPICAL_ORANGE_,page,0);//����
			fill_color(150,680,480,750,TROPICAL_ORANGE_,page,0);//��¼
			fill_color(530,680,860,750,TROPICAL_ORANGE_,page,0);//ע��
			string_drawing("��¼",260,700,32,20,12,-8,BLUE_,64,12,page,0);
			string_drawing("ע��",645,700,32,20,12,-8,BLUE_,64,12,page,0);
			for(i=0;i<16;i++)
			{
				str[i]=0;
			}
			for(i=0;i<16;i++)
			{
				password_record[i]=0;
			}
			return 0;
		}
	}
}
