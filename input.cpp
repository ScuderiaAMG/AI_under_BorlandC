
/*
/*�ļ����ƣ�input 
/*�ļ�Ŀ�ģ�ʵ���ַ��ڽ����ϵ����� 
/*ʱ�临�Ӷȣ�������ǣ���������ظ��� 
/*�ռ临�Ӷȣ�OH(1)
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
#include<conio.h>

//�������ƣ�visible_input
//����Ŀ�ģ�ʵ�ֿ�������

int visible_input(char *str,int x,int y,int limit,int color,int color2,int page)
{
	//clrmous(MouseX,MouseY,page);
	int sum=0;
	char keyboard;
	//line_drawing(x+10,y+6,x+10,y+20,color,page);//���
	//������һ��
	while(1)
	{
		keyboard=bioskey(0);
		if(sum<limit)
		{
			fill_color(550,175,550+48*6,175+48,SPRING_GREEN_,page,0);
			if(keyboard!='\n'&&keyboard!='\r'&&keyboard!=' '&&keyboard!=0x1b)//���С��ո��˳�
			{
				if(keyboard!='\b')
				{
					if((keyboard>='0'&&keyboard<='9')||(keyboard>='A'&&keyboard<='Z')||(keyboard>='a'&&keyboard<='z'))
					{
						//�ı��ַ�����ֵ
						*(str+sum)=keyboard;
						*(str+sum+1)='\0';
						//�ı���λ��
						//fill_color(x+8+sum*18,y+3,x+12+sum*18,y+24,SPRING_GREEN_,page);
						English_text_drawing(x+8+sum*18,y-1,str+sum,color,page,0);
						//outtextxy(x+8+sum*18,y-1,str+sum);
						sum++;
						//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
					}
					else
					{
						return ILLEGAL_INPUT;
						//ɶҲ����
					}
				}
				else if(keyboard=='\b'&&sum>0)
				{
					fill_color(x-6+sum*18,y+3,x+12+sum*18,y+32,DARK_GRAY_,page,0);
					//�����һ��������ַ�
					//fill_color(x+8+sum*18,y+3,x+12+sum*18,y+36,color2,page,0);
					sum--; //�ı�sumֵ
					//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
					//���ù��
					*(str+sum)='\0';
					//�ı��ַ���
				}
			}
			else
			{
				fill_color(x+8+sum*18,y+3,x+12+sum*18,y+24,color2,page,0);
				break;
			}
		}
		else if(sum>=limit)
		{
			if(keyboard!='\n'&&keyboard!='\r'&&keyboard!=' '&&keyboard!=0x1b)
			{
				string_drawing("���ʮ��λ��",550,175,48,26,15,0,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
				while(1)
				{
					if(kbhit())
					{
						char value=bioskey(0);
						if(value==13)
						{
							return LEGAL_INPUT;
						}
						else if(value=='\b')
						{
							fill_color(x-6+sum*18,y+3,x+12+sum*18,y+54,DARK_GRAY_,page,0);
							//fill_color(x-10+sum*18,y+3,x+7+sum*18,y+24,color,page,0);
							sum--;
							//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
							*(str+sum)='\0';
							break;
						}
					}
				}
			}
			else
			{
				if(keyboard=='\b'&&sum>0)
				{
					//��ǰ����˸�һģһ��
					fill_color(x-6+sum*18,y+3,x+12+sum*18,y+32,DARK_GRAY_,page,0);
					//fill_color(x-10+sum*18,y+3,x+7+sum*18,y+24,color,page,0);
					sum--;
					//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
					*(str+sum)='\0';
				}
				else
				{
					//fill_color(x+8+sum*18,y+3,x+12+sum*18,y+24,color,page,0);
					break;
				}
			}
		}
	}
	return LEGAL_INPUT;
}

//�������ƣ�invisible_input
//����Ŀ�ģ�ʵ�ֺ����Ĳ���������

int invisible_input(char *str,int x,int y,int limit,int color,int color2,int page)
{
	//clrmous(MouseX,MouseY,page);
	int sum=0;
	char keyboard;
	//line_drawing(x+10,y+6,x+10,y+20,color,page);//���
	//������һ��
	while(1)
	{
		keyboard=bioskey(0);
		if(sum<limit)
		{
			fill_color(550,175,550+48*6,175+48,SPRING_GREEN_,page,0);
			if(keyboard!='\n'&&keyboard!='\r'&&keyboard!=' '&&keyboard!=0x1b)//���С��ո��˳�
			{
				if(keyboard!='\b')
				{
					if((keyboard>='0'&&keyboard<='9')||(keyboard>='A'&&keyboard<='Z')||(keyboard>='a'&&keyboard<='z'))
					{
						//�ı��ַ�����ֵ
						*(str+sum)=keyboard;
						*(str+sum+1)='\0';
						//�ı���λ��
						//fill_color(x+8+sum*18,y+3,x+12+sum*18,y+24,SPRING_GREEN_,page);
						English_text_drawing(x+8+sum*18,y+4,"-",color,page,0);
						//outtextxy(x+8+sum*18,y-1,str+sum);
						sum++;
						//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
					}
					else
					{
						return ILLEGAL_INPUT;
						//ɶҲ����
					}
				}
				else if(keyboard=='\b'&&sum>0)
				{
					fill_color(x-6+sum*18,y+3,x+12+sum*18,y+40,DARK_GRAY_,page,0);
					//�����һ��������ַ�
					//fill_color(x+8+sum*18,y+3,x+12+sum*18,y+36,color2,page,0);
					sum--; //�ı�sumֵ
					//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
					//���ù��
					*(str+sum)='\0';
					//�ı��ַ���
				}
			}
			else
			{
				fill_color(x+8+sum*18,y+3,x+12+sum*18,y+40,color2,page,0);
				break;
			}
		}
		else if(sum>=limit)
		{
			if(keyboard!='\n'&&keyboard!='\r'&&keyboard!=' '&&keyboard!=0x1b)
			{
				string_drawing("���ʮ��λ��",550,175,48,26,15,0,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
				while(1)
				{
					if(kbhit())
					{
						char value=bioskey(0);
						if(value==13)
						{
							return LEGAL_INPUT;
						}
						else if(value=='\b')
						{
							fill_color(x-6+sum*18,y+3,x+12+sum*18,y+64,DARK_GRAY_,page,0);
							//fill_color(x-10+sum*18,y+3,x+7+sum*18,y+24,color,page,0);
							sum--;
							//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
							*(str+sum)='\0';
							break;
						}
					}
				}
			}
			else
			{
				if(keyboard=='\b'&&sum>0)
				{
					//��ǰ����˸�һģһ��
					fill_color(x-6+sum*18,y+3,x+12+sum*18,y+32,DARK_GRAY_,page,0);
					//fill_color(x-10+sum*18,y+3,x+7+sum*18,y+24,color,page,0);
					sum--;
					//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
					*(str+sum)='\0';
				}
				else
				{
					//fill_color(x+8+sum*18,y+3,x+12+sum*18,y+24,color,page,0);
					break;
				}
			}
		}
	}
	return LEGAL_INPUT;
}

//�������ƣ�visible_input1
//����Ŀ�ģ�ʵ�ֿ�������

int visible_input1(char *str,int x,int y,int limit,int color,int color2,int page)
{
	//clrmous(MouseX,MouseY,page);
	int sum=0;
	char keyboard;
	//line_drawing(x+10,y+6,x+10,y+20,color,page);//���
	//������һ��
	while(1)
	{
		keyboard=bioskey(0);
		if(sum<limit)
		{
			fill_color(550,20,550+48*6,68,SPRING_GREEN_,page,0);
			if(keyboard!='\n'&&keyboard!='\r'&&keyboard!=' '&&keyboard!=0x1b)//���С��ո��˳�
			{
				if(keyboard!='\b')
				{
					if((keyboard>='0'&&keyboard<='9')||(keyboard>='A'&&keyboard<='Z')||(keyboard>='a'&&keyboard<='z'))
					{
						//�ı��ַ�����ֵ
						*(str+sum)=keyboard;
						*(str+sum+1)='\0';
						//�ı���λ��
						//fill_color(x+8+sum*18,y+3,x+12+sum*18,y+24,SPRING_GREEN_,page);
						English_text_drawing(x+8+sum*18,y-1,str+sum,color,page,0);
						//outtextxy(x+8+sum*18,y-1,str+sum);
						sum++;
						//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
					}
					else
					{
						return ILLEGAL_INPUT;
						//ɶҲ����
					}
				}
				else if(keyboard=='\b'&&sum>0)
				{
					fill_color(x-6+sum*18,y+3,x+12+sum*18,y+40,GAINSBORO_,page,0);
					//�����һ��������ַ�
					//fill_color(x+8+sum*18,y+3,x+12+sum*18,y+36,color2,page,0);
					sum--; //�ı�sumֵ
					//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
					//���ù��
					*(str+sum)='\0';
					//�ı��ַ���
				}
			}
			else
			{
				fill_color(x+8+sum*18,y+3,x+12+sum*18,y+24,color2,page,0);
				break;
			}
		}
		else if(sum>=limit)
		{
			if(keyboard!='\n'&&keyboard!='\r'&&keyboard!=' '&&keyboard!=0x1b)
			{
				string_drawing("���ʮ��λ��",550,20,48,26,15,0,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
				while(1)
				{
					if(kbhit())
					{
						char value=bioskey(0);
						if(value==13)
						{
							return LEGAL_INPUT;
						}
						else if(value=='\b')
						{
							fill_color(x-6+sum*18,y+3,x+12+sum*18,y+44,GAINSBORO_,page,0);
							//fill_color(x-10+sum*18,y+3,x+7+sum*18,y+24,color,page,0);
							sum--;
							//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
							*(str+sum)='\0';
							break;
						}
					}
				}
			}
			else
			{
				if(keyboard=='\b'&&sum>0)
				{
					//��ǰ����˸�һģһ��
					fill_color(x-6+sum*18,y+3,x+12+sum*18,y+40,GAINSBORO_,page,0);
					//fill_color(x-10+sum*18,y+3,x+7+sum*18,y+24,color,page,0);
					sum--;
					//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
					*(str+sum)='\0';
				}
				else
				{
					//fill_color(x+8+sum*18,y+3,x+12+sum*18,y+24,color,page,0);
					break;
				}
			}
		}
	}
	return LEGAL_INPUT;
}

//�������ƣ�invisible_input
//����Ŀ�ģ�ʵ�ֺ����Ĳ���������

int invisible_input1(char *str,int x,int y,int limit,int color,int color2,int page)
{
	//clrmous(MouseX,MouseY,page);
	int sum=0;
	char keyboard;
	//line_drawing(x+10,y+6,x+10,y+20,color,page);//���
	//������һ��
	while(1)
	{
		keyboard=bioskey(0);
		if(sum<limit)
		{
			fill_color(550,20,550+48*6,68,SPRING_GREEN_,page,0);
			
			if(keyboard!='\n'&&keyboard!='\r'&&keyboard!=' '&&keyboard!=0x1b)//���С��ո��˳�
			{
				if(keyboard!='\b')
				{
					if((keyboard>='0'&&keyboard<='9')||(keyboard>='A'&&keyboard<='Z')||(keyboard>='a'&&keyboard<='z'))
					{
						//�ı��ַ�����ֵ
						*(str+sum)=keyboard;
						*(str+sum+1)='\0';
						//�ı���λ��
						//fill_color(x+8+sum*18,y+3,x+12+sum*18,y+24,SPRING_GREEN_,page);
						English_text_drawing(x+8+sum*18,y+4,"-",color,page,0);
						//outtextxy(x+8+sum*18,y-1,str+sum);
						sum++;
						//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
					}
					else
					{
						return ILLEGAL_INPUT;
						//ɶҲ����
					}
				}
				else if(keyboard=='\b'&&sum>0)
				{
					fill_color(x-6+sum*18,y+3,x+12+sum*18,y+44,GAINSBORO_,page,0);
					//�����һ��������ַ�
					//fill_color(x+8+sum*18,y+3,x+12+sum*18,y+36,color2,page,0);
					sum--; //�ı�sumֵ
					//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
					//���ù��
					*(str+sum)='\0';
					//�ı��ַ���
				}
			}
			else
			{
				fill_color(x+8+sum*18,y+3,x+12+sum*18,y+44,color2,page,0);
				break;
			}
		}
		else if(sum>=limit)
		{
			if(keyboard!='\n'&&keyboard!='\r'&&keyboard!=' '&&keyboard!=0x1b)
			{
				string_drawing("���ʮ��λ��",550,20,48,26,15,0,RED_,BIG_NUMBER,BIG_NUMBER,page,0);
				while(1)
				{
					if(kbhit())
					{
						char value=bioskey(0);
						if(value==13)
						{
							return LEGAL_INPUT;
						}
						else if(value=='\b')
						{
							fill_color(x-6+sum*18,y+3,x+12+sum*18,y+44,GAINSBORO_,page,0);
							//fill_color(x-10+sum*18,y+3,x+7+sum*18,y+24,color,page,0);
							sum--;
							//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
							*(str+sum)='\0';
							break;
						}
					}
				}
			}
			else
			{
				if(keyboard=='\b'&&sum>0)
				{
					//��ǰ����˸�һģһ��
					fill_color(x-6+sum*18,y+3,x+12+sum*18,y+44,GAINSBORO_,page,0);
					//fill_color(x-10+sum*18,y+3,x+7+sum*18,y+24,color,page,0);
					sum--;
					//line_drawing(x+10+sum*18,y+6,x+10+sum*18,y+20,color,page);
					*(str+sum)='\0';
				}
				else
				{
					//fill_color(x+8+sum*18,y+3,x+12+sum*18,y+24,color,page,0);
					break;
				}
			}
		}
	}
	return LEGAL_INPUT;
}
