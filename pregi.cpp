
/*
/*�ļ����ƣ�pregi
/*�ļ�Ŀ�ģ�ʵ��ע����� 
/*ʱ�临�Ӷȣ�\Theta(1) 
/*�ռ临�Ӷȣ�\Theta(1024*768) 
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
#include<ptext.h>
#include<pregi.h>
#include<input.h>
#include<pchat.h>
 
extern int MouseX,MouseY,MouseS,press;
extern void* buffer;
extern union REGS our_AI_regs;
extern int MouseX_memory,MouseY_memory;

//�������ƣ�register_picture
//����Ŀ�ģ�ʵ��ע�����

int register_picture(int page)
{
	//mread(&MouseX,&MouseY,&MouseS);
	//clrmous(MouseX,MouseY,page);
	delay(20);
	//save_bk_mou(MouseX,MouseY);
	//��겿��
	fill_color(0,0,1024,768,SPRING_GREEN_,page,0);
	
	robot_avatar(55,35+80,page);
	int i;
	for(i=-1;i<=1;i++)
	{
		line_drawing(104,35+80,135,15+80,WHITE_,page,1);
		line_drawing(104,35+80,135,40+80,WHITE_,page,1);
		line_drawing(135,15+80,475,15+80,WHITE_,page,1);
	}
	fill_color(135,15+80,475,15+80+WORDWIDTH,WHITE_,page,1);
	for(i=16;i<40;i++)
	{
		line_drawing(104,35+80,135,i+80,WHITE_,page,1);
	}
	//else if(status==NONFILL_STATUS)
	//{
	//	fill(120,1,WHITE_,page,1);
	//	;
	//}
	line_drawing(104,35+80,135,15+80,BLACK_,page,1);
	line_drawing(104,35+80,135,40+80,BLACK_,page,1);
	line_drawing(135,15+80,400,15+80,BLACK_,page,1);
	line_drawing(135,15+80,475,15+80,BLACK_,page,1);
	line_drawing(475,15+80,475,15+80+WORDWIDTH,BLACK_,page,1);
	line_drawing(475,15+80+WORDWIDTH,135,15+80+WORDWIDTH,BLACK_,page,1);
	line_drawing(135,20+80,135,15+80,BLACK_,page,1);
	line_drawing(135,40+80,135,15+80+WORDWIDTH,BLACK_,page,1);
	string_drawing("��ע�ᣡ",140,13+80,32,20,12,-8,RED_,32*23,10000,page,1);

	string_drawing("�û�����",196,290,32,20,12,-8,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
	string_drawing("���룺",228,410,32,20,12,-8,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
	string_drawing("�ٴ�ȷ�����룺",100,530,32,20,12,-8,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
	fill_color(350,260,900,360,TROPICAL_ORANGE_,page,0);
	fill_color(350,380,900,480,TROPICAL_ORANGE_,page,0);
	fill_color(350,500,900,600,TROPICAL_ORANGE_,page,0);
	fill_color(300,650,600,720,TROPICAL_ORANGE_,page,0);
	fill_color(964,0,1024,60,RED_,page,0);
	for(i=-2;i<=2;i++)
	{
		line_drawing(968+i,8,1020+i,52,WHITE_,page,0);
		line_drawing(1020+i,8,968+i,52,WHITE_,page,0);
	}
	string_drawing("ע��",400,670,32,20,12,-8,WHITE_,BIG_NUMBER,BIG_NUMBER,page,0);
	//�����ǻ�ͼ����
	int status=0;
	int position=0;
	char name_input[16]={'\0'};
	char password_input[16]={'\0'};
	char password_again_input[16]={'\0'};
	int error1;
	int error2;
	int error3;
	int error4;
	mouseinit(page);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press,page);
		//mread(&MouseX,&MouseY,&press);
		memory_mouse(MouseX,MouseY,page);
		//drawmous(MouseX,MouseY,page);
		mouse_drawing(MouseX,MouseY,page);
		delay(20);
		truly_clean_mouse(MouseX,MouseY,page);
		//�˳�
		if(MouseX>=964&&MouseX<=1024&&MouseY>=0&&MouseY<=60)
		{
			if(mouse_press(964,0,1024,60)==2)
			{
				//if(status==0)
				{
					MouseS=1;
					status=4;
				}
				continue;
			}
			else if(mouse_press(964,0,1024,60)==1)
			{
				register_color_change_mouse(4,page);
				status=4;
				MouseS=0;
				page=PAGE_START;
				change_page(&page);
			}
		}
		//�û���
		else if(MouseX>=350&&MouseX<=900&&MouseY>=260&&MouseY<=360)
		{
			if(mouse_press(350,260,900,360)==2)
			{
				MouseS=2;
				if(status==0&&position==0)
				{
					status=1;
				}
				continue;
			}
			else if(mouse_press(350,260,900,360)==1)
			{
				status=1;
				MouseS=0;
				register_color_change_mouse(1,page);
				name_input[0]='\0';
				visible_input(name_input,350,260,15,BLACK_,DARK_GRAY_,page);
				error1=check_law(name_input,page);
				continue;
			}
		}
		//����
		else if(MouseX>=350&&MouseX<=900&&MouseY>=380&&MouseY<=480)
		{
			if(mouse_press(350,380,900,480)==2)
			{
				MouseS=2;
				if(status==0&&position==0)
				{
					status=2;
				}
				continue;
			}
			else if(mouse_press(350,380,900,480)==1)
			{
				status=2;
				MouseS=0;
				register_color_change_mouse(2,page);
				password_input[0]='\0';
				invisible_input(password_input,350,380,15,BLACK_,DARK_GRAY_,page);
				error2=check_law(password_input,page);
				error4=check_password1(password_again_input,password_input,page);
				continue;
			}
		}
		//�ٴ���������
		else if(MouseX>=350&&MouseX<=900&&MouseY>=500&&MouseY<=600)
		{
			if(mouse_press(350,500,900,600)==2)
			{
				MouseS=2;
				if(status==0&&position==0)
				{
					status=3;
				}
				continue;
			}
			else if(mouse_press(350,500,900,600)==1)
			{
				status=3;
				MouseS=0;
				register_color_change_mouse(3,page);
				password_again_input[0]='\0';
				invisible_input(password_again_input,350,500,15,BLACK_,DARK_GRAY_,page);
				error3=check_law(password_again_input,page);
				error4=check_password(password_again_input,password_input,page);
				continue;
			}
		}
		//ע������
		else if(MouseX>=300&&MouseX<=650&&MouseY>=600&&MouseY<=720)
		{
			if(mouse_press(300,650,600,720)==2)
			{
				MouseS=1;
				if(status==0&&position==0)
				{
					status=1;
				}
				continue;
			}
			else if(mouse_press(300,650,600,720)==1)
			{
				MouseS=0;
				register_color_change_mouse(5,page);
				if(error1==0&&error2==0&&error3==0&&error4==0)
				{
					text_register(name_input,password_input);
					page=PAGE_START;
					fill_color(600,55,600+48*5,55+48,SPRING_GREEN_,page,0);
					string_drawing("ע��ɹ���",600,55,48,26,15,0,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
					change_page(&page);
				}
				else
				{
					string_drawing("ע������",600,55,48,26,15,0,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
					fill_color(350,260,900,360,TROPICAL_ORANGE_,page,0);
					fill_color(350,380,900,480,TROPICAL_ORANGE_,page,0);
					fill_color(350,500,900,600,TROPICAL_ORANGE_,page,0);
					fill_color(300,650,600,720,TROPICAL_ORANGE_,page,0);
					string_drawing("ע��",400,670,32,20,12,-8,WHITE_,BIG_NUMBER,BIG_NUMBER,page,0);
				}
				continue;
			}
		}
		//��������
		else
		{
			/*
			switch(status)
			{
				case 1:
					back_register_color(1,page);
					break;
				case 2:
					back_register_color(2,page);
					break;
				case 3:
					back_register_color(3,page);
					break;
			}
			*/
			MouseS=0;
			status=4;
		} 
	}
	return PAGE_REGISTER;
}

//�������ƣ�register_color_change_mouse
//����Ŀ�ģ�ʵ��ע��ҳ������ͼ����ɫ

void register_color_change_mouse(int i,int page)
{
	//clrmous(MouseX,MouseY,page);
	delay(10);
	switch(i)
	{
		//�û���
		case 1:
			fill_color(350,260,900,360,DARK_GRAY_,page,0);
			break;
		//����
		case 2:
			fill_color(350,380,900,480,DARK_GRAY_,page,0);
			break;
		//�ٴ�ȷ������
		case 3:
			fill_color(350,500,900,600,DARK_GRAY_,page,0);
			break;
		//�˳�
		case 4:
			fill_color(964,0,1024,60,DARK_GRAY_,page,0);
			break;
		//ע��
		case 5:
			fill_color(300,650,600,720,DARK_GRAY_,page,0);
			break;
	}
}

//�������ƣ�check_law
//����Ŀ�ģ��ж��û����������Ƿ���������淶

int check_law(char *input,int page)
{
	int length=strlen(input);
	int i;
	if(length>=15)
	{
		string_drawing("���ʮ��λ��",550,175,48,26,15,0,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
		return 1;
	}
	for(i=0;i<length;i++)
	{
		if((input[i]>='0'&&input[i]<='9')||(input[i]>='a'&&input[i]<='z')||(input[i]>='A'&&input[i]<='Z'))
		{
			//���·���
		}
		else
		{
			string_drawing("ֻ��������ĸ�����֣�",100,75,48,26,15,0,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
			input[i]='\0';
			return 1;
		}
	}
	return 0;
	//0��û���⣬1��������
}

//�������ƣ�check_password
//����Ŀ�ģ���������Ƿ��ٴ��������״�����һ��

int check_password(char *arr1,char *arr2,int page)
{
	if(strcmp(arr1,arr2)==0)
	{
		return 0;
	}
	else
	{
		string_drawing("�������벻һ�£�",550,115,48,26,15,0,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
		return 1;
	}
	//ͬ���أ�0��û���⣬1��������
}

//�������ƣ�check_password1
//����Ŀ�ģ���������Ƿ��ٴ��������״�����һ��

int check_password1(char *arr1,char *arr2,int page)
{
	if(strcmp(arr1,arr2)==0)
	{
		return 0;
	}
	else
	{
		//string_drawing("�������벻һ�£�",550,115,48,26,15,0,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
		return 1;
	}
	//ͬ���أ�0��û���⣬1�������� 
}

//�������ƣ�text_register
//����Ŀ�ģ�����Ϣд���ļ�

void text_register(char *arr1,char *arr2)
{
	LOGIN* log;
	FILE* fp;
	if((fp=fopen("C:\\CODE\\data\\password.dat","rb+"))==NULL)
	{
		printf("�������ݿ��޷��򿪣�������˳�");
		getchar();
		exit(1);
	}
	if((log=(LOGIN*)malloc(sizeof(LOGIN)))==NULL)//����ռ�
	{
		printf("�����ڴ���䲻�㣡������˳�");
		getchar();
		exit(1);
	}
	fseek(fp,0,SEEK_END);
	int sum=ftell(fp)/sizeof(LOGIN);
	log->num=sum+1;
	strcpy(log->name,arr1);
	strcpy(log->password,arr2);
	log->chattext=0;
	fseek(fp,0,SEEK_END);
	fwrite(log,sizeof(LOGIN),1,fp);
	if(log!=NULL)
	{
		free(log);
		log=NULL;
	}
	if(fclose(fp)!=0)
	{
		printf("�������ݿ��ļ��ز�����������˳�");
		getchar();
		exit(1);
	}
}

//�������ƣ�back_register_color
//����Ŀ�ģ����仯��ɫ��ע�ᰴ����ԭ
void back_register_color(int i,int page)
{
	switch(i)
	{
		case 1:
			fill_color(350,260,900,360,TROPICAL_ORANGE_,page,0);
			break;
		case 2:
			fill_color(350,380,900,480,TROPICAL_ORANGE_,page,0);
			break;
		case 3:
			fill_color(350,500,900,600,TROPICAL_ORANGE_,page,0);
			break;
	}
} 

int page_test()
{
	return PAGE_TEST;
}
int page_chat2()
{
	return PAGE_CHAT2;
}
int page_exit()
{
	return PAGE_EXIT;
}
void clean_chat1()
{
	
}
void clean_chat2()
{
	
}
