
/*
/*�ļ����ƣ�hz
/*�ļ�Ŀ�ģ�ʵ�ֺ��ֵ����뷨
/*ʱ�临�Ӷȣ�GB2312������
/*�ռ临�Ӷȣ�\Theta(1)
*/

#include<hz.h>
#include<pchat.h>
#include<page.h>
#include<AI.h>
#include<draw.h>//test

extern int MouseX,MouseY,MouseS,press;
extern void* buffer;
extern union REGS our_AI_regs;
extern int MouseX_memory,MouseY_memory;

extern char far input[51][421];

//�������ƣ�input_method
//����Ŀ�ģ��������뷨����

int input_method(int x, int y, char *str, int value, char *py, int page, int* choose, int *keyboard, int* pianyi,char* inputinput,int* input_counter) 
{
	int status = 0;
	int ha,ah;
	//int color[201][41];
	FILE *fp = NULL, *oldfp = NULL;
	int fJudge = FAIL;
	char *p = py;
	int trigger = 1; //����ʱ���������־
	char temphz[5][3] = {{'\0', '\0', '\0'}, {'\0', '\0', '\0'}, {'\0', '\0', '\0'}, {'\0', '\0', '\0'}, {'\0', '\0', '\0'}}, temp[3];
	int fposition = 0;
	int hznow = 0, hznum = 0;
	int asc, i;
	int keykeykeyboard;
	int kkk;
	int sum_height;
	int height[100];
	int PyStartx = x + 8, PyStarty = y + 4;
	int HzStartx = x + 8, HzStarty = y + 22;
	char *ABpath = "C:\\CODE\\hzk\\"; //����ƴ��������׼·��
	char pypath[45];		   // ����ƴ���������·��
	// settextjustify(LEFT_TEXT, CENTER_TEXT);
	strcpy(pypath, "C:\\CODE\\hzk\\");

	newmouse(&MouseX, &MouseY, &press,page);
	//mread(&MouseX,&MouseY,&press);
	memory_mouse(MouseX, MouseY, page);
	//drawmous(MouseX,MouseY,page);
	mouse_drawing(MouseX, MouseY, page);
	delay(20);
	truly_clean_mouse(MouseX, MouseY, page);

	//memory_hz(x-96,y+80,color,page);

	while(1)
	{
		//for(;;){string_drawing("������",0,0,24,15,9,-6,DARK_GRAY_,40000,120,page);}//test
		newmouse(&MouseX, &MouseY, &press,page);
		//mread(&MouseX,&MouseY,&press);
		memory_mouse(MouseX, MouseY, page);
		//drawmous(MouseX,MouseY,page);
		mouse_drawing(MouseX, MouseY, page);
		delay(20);
		truly_clean_mouse(MouseX, MouseY, page);
		//��ͷ��
		if (MouseX >= 947 && MouseX <= 1011 && MouseY >= 662 && MouseY <= 726)
		{
			if (mouse_press(947, 662, 1011, 726) == 2)
			{
				if (status == 0)
				{
					MouseS = 1;
					status = 5;
				}
				continue;
			}
			else if (mouse_press(947, 662, 1011, 726) == 1)
			{
				fill_color(85, 650, 935, 738, SNOW_, page, 0);
				color_change_chat1(5, page);
				status = 5;
				MouseS = 0;

				//ִ��AI���ܵ���ں���->������
				//memset(input,0,100001);
				//memset(eventual,0,100001);

				return 100;
			}
		}
		//�˳�
		if (MouseX >= 964 && MouseX <= 1024 && MouseY >= 0 && MouseY <= 60)
		{
			if (mouse_press(964, 0, 1024, 60) == 2)
			{
				if (status == 0)
				{
					MouseS = 1;
					status = 1;
				}
				continue;
			}
			else if (mouse_press(964, 0, 1024, 60) == 1)
			{
				color_change_chat1(1, page);
				status = 1;
				MouseS = 0;
				page = PAGE_START;
				change_page(&page);
			}
		}
		//�����İ���
		if (MouseX >= 85 && MouseX <= 235 && MouseY >= 585 && MouseY <= 638)
		{
			if (mouse_press(85, 585, 235, 638) == 2) 
			{
				if (status == 0)
				{
					MouseS = 1;
					status = 3;
				}
				continue;
			} 
			else if (mouse_press(85, 585, 235, 638) == 1) 
			{
				//color_change_chat1(3, page);
				status = 3;
				MouseS = 0;
				*choose = 0;
				*input_counter=0;
				int kkk;
				for(kkk=0;kkk<51;kkk++)
				{
					memset(input[kkk],0,421);
				}
				strcpy(input[0],"���ã�������ʲô���԰���������");
				*input_counter=1;
				color_change_chat1(3,page);
			}
		}
		//����ͼ����
		if (MouseX >= 315 && MouseX <= 465 && MouseY >= 585 && MouseY <= 638)
		{
			if (mouse_press(315, 585, 465, 638) == 2)
			{
				if (status == 0)
				{
					MouseS = 1;
					status = 4;
				}
				continue;
			}
			else if (mouse_press(315, 585, 465, 638) == 1)
			{
				//color_change_chat1(4, page);
				status = 4;
				MouseS = 0;
				*choose = 1;
				*input_counter=0;
				for(kkk=0;kkk<51;kkk++)
				{
					memset(input[kkk],0,421);
				}
				color_change_chat1(4,page);
			}
		}
		if (trigger || kbhit())
		{ // ��һ�ν����Զ����� �Ժ�������
			//clrmous(MouseX,MouseY);//test
			//mouseinit();//test
			//UpdateMouse();
			trigger = 0;
			if (kbhit())
			{
				value = bioskey(0);
			}
			asc = value & 0xff;
			/*���ⰴ������*/
			switch (value) 
			{
				case UP:
					//�Ի���
					//if((MouseX>=0&&MouseX<=963&&MouseY>=0&&MouseY<=575)||
					//(MouseX>=964&&MouseX<=1024&&MouseY>=61&&MouseY<=575))
					//{
					//if(mouse_press(0,1024,0,575)==1)
					//{

					sum_height = 0;
					for (i = 0; input[i][0] != '\0'; i++) 
					{
						sum_height += strlen(input[i]) / 46;
						sum_height += 2;
					}
					*keyboard -= 2;
					if (sum_height >= 15) 
					{
						display_text(input, *pianyi, page, *keyboard);
					}
					//	}
					//}
					break;
				case DOWN:
					//if((MouseX>=0&&MouseX<=963&&MouseY>=0&&MouseY<=575)||
					//(MouseX>=964&&MouseX<=1024&&MouseY>=61&&MouseY<=575))
					//{
					//if(mouse_press(0,1024,0,575)==1)
					//{

					sum_height = 0;
					for (i = 0; input[i][0] != '\0'; i++)
					{
						sum_height+=strlen(input[i])/46;
						sum_height+=2;
					}
					*keyboard+=2;
					if (sum_height >= 15)
					{
						display_text(input,*pianyi,page,*keyboard);
					}
					//}
					//}
					break;
				case BACK:
					if(py[0]!='\0')
					{
						p--;
						*p='\0';
						break;
					}
					if(inputinput[0]!=0)
					{
						if(inputinput[strlen(inputinput)-1]<0)
						{
							fill_color(x-94,y+42,x-62,y+74,SNOW_,page,0);
							fill_color(x-64,y+72,x+172,y+126,SNOW_,page,0);
						}
						else if(inputinput[strlen(inputinput)-1]>0)
						{
							fill_color(x-90,y+42,x-62,y+74,SNOW_,page,0);
							fill_color(x-64,y+72,x+172,y+126,SNOW_,page,0);				
						}
					}
					else
					{
						;
					}
					if(py[0]=='\0')
					{
						str[0]='\0';
						if(oldfp)
						{
							fclose(oldfp);
						}
						if(fp)
						{
							fclose(fp);
						}
						return 3;
					}
					else
					{
						fill_color(x - 64, y + 72, x+200 - 64, y+40 + 80, SNOW_, page, 0);
						if(strlen(py)>=1)
						{
							py[strlen(py)-1]='\0';
						}
					}
				case SPACE:
					strcpy(str,temphz[hznow]);
					if(oldfp)
						fclose(oldfp);
					if(fp)
						fclose(fp);
					//clean_hz(x-96,y+80,color,page);
					fill_color(x - 64, y + 70, x + 138, y + 124, SNOW_, page, 0);
					return 1;
				case ENTER:
					strcpy(str, py);
					if (oldfp)
						fclose(oldfp);
					if (fp)
						fclose(fp);
					//clean_hz(x-96,y+80,color,page);
					fill_color(x - 64, y + 70, x + 138, y + 124, SNOW_, page, 0);
					return 666;
				case LASTLINE:
					if (fposition >= 8) 
					{ //�������ض�λ�ļ�ָ��ǰ�˸��ֽڣ��ĸ����֣�
						fposition -= 8;
					}
					break;
				case NEXTLINE:
					if (!feof(fp)) 
					{ //�������ض�λ�ļ�ָ���˸��ֽڣ��ĸ����֣�
						fposition += 8;
					}
					break;
				case LEFT://���ƶ�һ��
					//if(hznow)
					//{
					//hznow--;
					if (fposition >= 8) 
					{
						fposition -= 8;
						//hznow=3;
					}
					//}
					//else if(fposition>=8)//��Ҫ��ҳ
					//{
					//	fposition-=8;
					//	hznow=3;
					//}
					break;
				case RIGHT:
					if (hznow < hznum - 1) 
					{ //ͬ��
						//hznow++;
						if (!feof(fp)) 
						{
							fposition += 8;
							//hznow=0;
						}
					}
					//else if(!feof(fp))
					//{
					//	fposition+=8;
					//	hznow=0;
					//}
					break;

				/*�����ּ�ѡ�����뺺��*/
				case FIRST:
					if (py[0] == '\0') 
					{
						;
					} 
					else 
					{
						strcpy(str, temphz[0]);
						if (oldfp)
							fclose(oldfp);
						if (fp)
							fclose(fp);
						fill_color(x - 64, y + 70, x + 138, y + 124, SNOW_, page, 0);
						//string_drawing("Hello world!",0,0,24,15,9,-6,BLACK_,40000,120,page);
						return 1;
					}
				case SECOND:
					if (py[0] == '\0') 
					{
						;
					} 
					else 
					{
						strcpy(str,temphz[1]);
						if(oldfp)
							fclose(oldfp);
						if(fp)
							fclose(fp);
						fill_color(x - 64, y + 70, x + 138, y + 124, SNOW_, page, 0);
						//string_drawing("Hello world!",0,0,24,15,9,-6,BLACK_,40000,120,page);
						return 1;
					}
				case THIRD:
					if (py[0] == '\0') 
					{
						;
					} 
					else 
					{
						strcpy(str,temphz[2]);
						if(oldfp)
							fclose(oldfp);
						if(fp)
							fclose(fp);
						fill_color(x - 64, y + 70, x + 138, y + 124, SNOW_, page, 0);
						//string_drawing("Hello world!",0,0,24,15,9,-6,BLACK_,40000,120,page);
						return 1;
					}
				case FOURTH:
					if (py[0] == '\0') 
					{
						;
					} 
					else 
					{
						strcpy(str, temphz[3]);
						if (oldfp)
							fclose(oldfp);
						if (fp)
							fclose(fp);
						fill_color(x - 64, y + 70, x + 138, y + 124, SNOW_, page, 0);
						//string_drawing("Hello world!",0,0,24,15,9,-6,BLACK_,40000,120,page);
						return 1;
					}
			}

			/*�����ַ�����*/
			if (asc > 31 && asc < 127 && strlen(py) < MAXPY && asc != '[' && asc != ']') 
			{ 
				//��Ч����ʱ��λ
				*p = asc;
				p++;
				fposition = 0;
				hznow = 0;
			}
			pyFrm(x, y, x + 200, y + 40, page);
			string_drawing(py, PyStartx - 64, PyStarty + 72, 24, 15, 9, -6, DARK_GRAY_, 40000, 120, page, 0);
			//setfillstyle(1,WHITE);
			//settextstyle(1,0,2);
			//settextjustify(LEFT_TEXT,CENTER_TEXT);
			//outtextxy(PyStartx,PyStarty,py);//ƴ������
			//string_drawing(PyStartx,PyStarty,py,16,BLUE_,page);
			strcat(pypath, py);
			strcat(pypath, ".txt");
			if (fJudge) 
			{ //����ǰ�ļ�ָ�뱣�� ͬʱ�ر���һ���ļ�  Ϊ���������ַ�׼��
				if (oldfp) 
				{
					fclose(oldfp);
				}
				oldfp = fp;
			}
			//string_drawing(pypath,0,0,48,26,15,0,RED_,10000,10000,page);//test
			if ((fp = fopen(pypath, "r")) == NULL) 
			{ //�����ַ�����  ������һ���ļ��������
				fJudge = FAIL;
				fp = oldfp;
			} 
			else 
			{
				fJudge = SUCCESS;
			}
			if (fp) 
			{
				fseek(fp, fposition, SEEK_SET);
				for (i = 0; i < 5; i++) 
				{
					fread(temphz[i], 2, 1, fp); //����һ������
					if (feof(fp)) 
					{ //�����ļ�β
						hznum = i; //������˴��ļ�β���һ�� ��Ҫ��һ  Ȼ���˴�����һ��Ч������
						break;
					}
				}
				if (!feof(fp)) 
				{ //δ�����ļ�β ȫ�Ժ���
					hznum = 4;
				}
				//string_drawing(temphz[hznow],HzStartx+hznow*50-68,HzStarty+20,24,15,9,-6,DARK_GRAY_,400,12,page);
			if(py[0]!='\0')
				for (i = 0; i < hznum; i++) 
				{
					//setcolor(BLUE);
					//settextstyle(1,0,2);
					//xouttextxy(HzStartx + i * 50, HzStarty + 5, itostr(i + 1, temp), DARK_GRAY_);
					//string_drawing(HzStartx+i*50,HzStarty+2,itostr(i+1,temp),16,DARK_GRAY_,page);
					//string_drawing(itostr(i+1,temp),0,0,16,8,6,-3,DARK_GRAY_,400,12,page);//test
					string_drawing(itostr(i + 1, temp), HzStartx + i * 50 - 64, HzStarty + 76, 24, 15, 9, -6, DARK_GRAY_, 40000, 120, page, 0);
					// puthz(HzStartx+i*50+16,HzStarty,temphz[i],16,16,DARK_GRAY_);
					//string_drawing(HzStartx+i*50+16,HzStarty,temphz[i],16,DARK_GRAY_,page);
					string_drawing(temphz[i], HzStartx + i * 50 - 48, HzStarty + 76, 24, 15, 9, -6, DARK_GRAY_, 40000, 120, page, 0);
				}
				else
				{
					pyFrm(x, y, x + 200, y + 40, page);
				}
				//puthz(HzStartx+hznow*50+16,HzStarty,temphz[hznow],16,16,CYAN);//��ʾѡ�к���
				//string_drawing(HzStartx+hznow*50+16,HzStarty,temphz[hznow],16,DARK_GRAY_,page);
				//string_drawing(temphz[hznow],HzStartx+hznow*50-64,HzStarty+16,32,20,12,-8,BLACK_,40000,120,page);
			}
		}
		//string_drawing(pypath,0,0,24,15,9,-6,DARK_GRAY_,400,12,page);//test
		strcpy(pypath, ABpath); //����·����ԭ�������٣�
		value = 0;
		//hznow=0;
		//mouse_drawing(MouseX,MouseY,page);
		//drawtext(HzStartx + hznow * 50 + 16, HzStarty, temphz[hznow], 16, CYAN);
		delay(20);
	}
}

//�������ƣ�itostr
//����Ŀ�ģ����ֱ��

char *itostr(int a, char *s) 
{
	switch (a) 
	{
		case 1:
			strcpy(s, "1");
			return s;
		case 2:
			strcpy(s, "2");
			return s;
		case 3:
			strcpy(s, "3");
			return s;
		case 4:
			strcpy(s, "4");
			return s;
	}
	return s;
}


//�������ƣ�pyFrm
//����Ŀ�ģ����뷨С��


void pyFrm(int x1, int y1, int x2, int y2, int page) 
{
	//fill_color(x1,y1,x2,y2,WHITE_,page);
	//fill_color(x1,y1-32,x2,y2-32,DARK_GRAY_,page);
	fill_color(x1 - 64, y1 + 72, x2 - 64, y2 + 80, WHITE_, page, 0);
	line_drawing(x1 - 59, y1 + 92, x2 - 69, y1 + 92, BLUE_, page, 0);
}

//�������ƣ�memory_hz
//����Ŀ�ģ��������뷨֮ǰ�Ļ���

void memory_hz(int x, int y, int color[201][41], int page) 
{
	int i, j;
	for (i = 0; i < 201; i++) 
	{
		for (j = 0; j < 41; j++) 
		{
			color[i][j] = get_pixel_color(x + i, y + j, page);
		}
	}
}

//�������ƣ�clean_hz
//����Ŀ�ģ�ʵ�����뷨��������

void clean_hz(int x, int y, int color[201][41], int page) 
{
	int i, j;
	for (i = 0; i < 201; i++) 
	{
		for (j = 0; j < 41; j++) 
		{
			point_drawing(x + i, y + j, color[i][j], page);
		}
	}
}
