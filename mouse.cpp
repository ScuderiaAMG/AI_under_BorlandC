
/*
** �ļ����ƣ�mouse 
** �ļ�Ŀ�ģ�����ͼ��
** ʱ�临�Ӷȣ���С 
** �ռ临�Ӷȣ���С 
*/

#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include<color.h>
#include<draw.h>
#include<mouse.h>

extern int MouseX;
extern int MouseY;
extern int MouseS;
extern int press;
extern int MouseX_memory;
extern int MouseY_memory;
extern unsigned int far* buffer;
extern union REGS our_AI_regs;
int flag=0;
extern int mouse_color[15][22];

//�������ƣ�mouseinit
//����Ŀ�ģ���ʼ�����

void mouseinit(int page)
{
	int retcode;
	int xmin,xmax,ymin,ymax,x_max=1024,y_max=768;
	int size;

	xmin=2;
	xmax=x_max-1;
	ymin=8;
	ymax=y_max-2;
	our_AI_regs.x.ax=0;
	int86(51,&our_AI_regs,&our_AI_regs);
	retcode=our_AI_regs.x.ax;
	our_AI_regs.x.ax=7;
	our_AI_regs.x.cx=xmin;
	our_AI_regs.x.dx=xmax;
	int86(51,&our_AI_regs,&our_AI_regs);
	our_AI_regs.x.ax=8;
	our_AI_regs.x.cx=ymin;
	our_AI_regs.x.dx=ymax;
	int86(51,&our_AI_regs,&our_AI_regs);
	//save_bk_mou(0,0);
	//mouse_drawing(MouseX,MouseY,page);
	flag=1;
}

//�������ƣ�mouse_drawing
//����Ŀ�ģ�����ͬ��̬�����

void mouse_drawing(int x,int y,int page)
{
	switch(MouseS)
	{
		case 1:                                  //�������
			line_drawing(x-1,y+9,x-1,y+8,WHITE_,page,0);
			line_drawing(x,y+7,x,y+11,WHITE_,page,0);
			line_drawing(x+1,y+6,x+1,y+13,WHITE_,page,0);
			line_drawing(x+2,y+8,x+2,y+14,WHITE_,page,0);
			line_drawing(x+3,y-1,x+3,y+15,WHITE_,page,0);
			line_drawing(x+4,y-2,x+4,y+15,WHITE_,page,0);
			line_drawing(x+5,y-1,x+5,y+16,WHITE_,page,0);
			line_drawing(x+6,y+2,x+6,y+16,WHITE_,page,0);
			line_drawing(x+7,y+3,x+7,y+17,WHITE_,page,0);
			line_drawing(x+8,y+4,x+8,y+17,WHITE_,page,0);
			line_drawing(x+9,y+5,x+9,y+16,WHITE_,page,0);
			line_drawing(x+10,y+6,x+10,y+16,WHITE_,page,0);
			line_drawing(x+11,y+7,x+11,y+13,WHITE_,page,0);
			line_drawing(x-1,y+9,x-1,y+8,DARK_GRAY_,page,0);
			line_drawing(x-1,y+8,x+1,y+6,DARK_GRAY_,page,0);
			line_drawing(x+1,y+6,x+3,y+10,DARK_GRAY_,page,0);
			line_drawing(x+3,y+10,x+3,y-1,DARK_GRAY_,page,0);
			line_drawing(x+5,y-1,x+5,y+5,DARK_GRAY_,page,0);
			line_drawing(x+7,y+3,x+7,y+7,DARK_GRAY_,page,0);
			line_drawing(x+9,y+5,x+9,y+9,DARK_GRAY_,page,0);
			line_drawing(x+11,y+7,x+11,y+13,DARK_GRAY_,page,0);
			line_drawing(x+7,y+17,x+3,y+15,DARK_GRAY_,page,0);
			line_drawing(x+3,y+15,x+1,y+13,DARK_GRAY_,page,0);
			line_drawing(x+1,y+13,x-1,y+9,DARK_GRAY_,page,0);
			break;
		case 2:                        //���
			line_drawing(x+1,y-1,x+9,y-1,DARK_GRAY_,page,0);
			line_drawing(x+1,y+15,x+9,y+15,DARK_GRAY_,page,0);
			line_drawing(x+5,y-1,x+5,y+15,DARK_GRAY_,page,0);
			break;
		case 3:                        //ʮ��
			line_drawing(x-1,y+7,x+11,y+7,WHITE_,page,0);
			line_drawing(x+5,y-1,x+5,y+15,WHITE_,page,0);
			break;
		default:              //Ĭ�����
			line_drawing(x,y,x,y+13,WHITE_,page,0);
			line_drawing(x+1,y+1,x+1,y+12,WHITE_,page,0);
			line_drawing(x+2,y+2,x+2,y+11,WHITE_,page,0);
			line_drawing(x+3,y+3,x+3,y+10,WHITE_,page,0);
			line_drawing(x+4,y+4,x+4,y+12,WHITE_,page,0);
			line_drawing(x+5,y+5,x+5,y+9,WHITE_,page,0);
			line_drawing(x+5,y+11,x+5,y+14,WHITE_,page,0);
			line_drawing(x+6,y+6,x+6,y+9,WHITE_,page,0);
			line_drawing(x+6,y+13,x+6,y+15,WHITE_,page,0);
			line_drawing(x+7,y+7,x+7,y+9,WHITE_,page,0);
			line_drawing(x+8,y+8,x+8,y+9,WHITE_,page,0);
			line_drawing(x+9,y+9,x+9,y+9,WHITE_,page,0);
			line_drawing(x-1,y-1,x-1,y+14,DARK_GRAY_,page,0);
			line_drawing(x-1,y+14,x+3,y+11,DARK_GRAY_,page,0);
			line_drawing(x+3,y+11,x+3,y+12,DARK_GRAY_,page,0);
			line_drawing(x+3,y+12,x+4,y+13,DARK_GRAY_,page,0);
			line_drawing(x+4,y+13,x+4,y+14,DARK_GRAY_,page,0);
			line_drawing(x+4,y+14,x+7,y+17,DARK_GRAY_,page,0);
			line_drawing(x+7,y+17,x+7,y+13,DARK_GRAY_,page,0);
			line_drawing(x+7,y+13,x+6,y+12,DARK_GRAY_,page,0);
			line_drawing(x+6,y+12,x+6,y+11,DARK_GRAY_,page,0);
			line_drawing(x+6,y+11,x+5,y+10,DARK_GRAY_,page,0);
			line_drawing(x+5,y+10,x+11,y+10,DARK_GRAY_,page,0);
			line_drawing(x+11,y+10,x-1,y-2,DARK_GRAY_,page,0);
			break;
	}
}

//�������ƣ�mread
//����Ŀ�ģ���ȡ�Ĵ�����Ϣ

void mread(int *nx,int *ny,int *nbuttons)
{
	our_AI_regs.x.ax=3;
	int86(51,&our_AI_regs,&our_AI_regs);
	*nx=our_AI_regs.x.cx;
	*ny=our_AI_regs.x.dx;
	*nbuttons=our_AI_regs.x.bx;
}

//�������ƣ�newmouse
//����Ŀ�ģ��������״̬

void newmouse(int *nx,int *ny,int *nbuttons,int page)
{
	int xn,yn,buttonsn;
	int x0=*nx,y0=*ny,buttons0=*nbuttons;
	mread(&xn,&yn,&buttonsn);
	*nx=xn;
	*ny=yn;
	*nbuttons=buttonsn;
	if(buttons0==*nbuttons)
		*nbuttons=0;    //ʹ������������
	if(xn==x0&&yn==y0&&buttonsn==buttons0)
		return;            //���״̬������ֱ�ӷ���S
	//mouse_drawing(*nx,*ny,page);
	//clrmous(MouseX,MouseY,page);
	//truly_clean_mouse(MouseX,MouseY);        //˵�����״̬�����˸ı�
	//save_bk_mou(*nx,*ny);
	//drawmous(*nx,*ny,page);
}

//�������ƣ�save_bk_mou
//����Ŀ�ģ�����걳��

void save_bk_mou(int nx,int ny)
{
	int size;
	size=imagesize(nx-1,ny-2,nx+11,ny+17);
	if(buffer!=NULL)
	{
		free(buffer);
		buffer=(unsigned int*)malloc(size);
	}
	if(buffer!=NULL)
	{
		getimage(nx-1,ny-2,nx+11,ny+17,buffer);
	}
	else
	{
		printf("Error");
	}
}

//�������ƣ�clrmous
//����Ŀ�ģ�������

void clrmous(int nx,int ny,int page)
{
	if(flag==1)
	{
		setwritemode(XOR_PUT);
		mouse_drawing(nx,ny,page);
		putimage(nx-1,ny-2,buffer,COPY_PUT);
		free(buffer);
		flag=0;
		setwritemode(COPY_PUT);
	}
}

//�������ƣ�drawmous
//����Ŀ�ģ�������������

void drawmous(int nx,int ny,int page)
{
	if(flag==0)
	{
		//setwritemode(COPY_PUT);
		mouse_drawing(nx,ny,page);
		flag=1;
	}
}

//�������ƣ�mouse_press
//����Ŀ�ģ��ж����ĵ�����

//����ڿ��е�����򷵻�1���ڿ���δ������򷵻�2�����ڿ����򷵻�0
int mouse_press(int x1, int y1, int x2, int y2)
{
	//�ڿ��е�����򷵻�1
	if(MouseX>x1
	&&MouseX<x2
	&&MouseY>y1
	&&MouseY<y2
	&&press==1)
	{
		return 1;
	}

	//�ڿ���δ������򷵻�2
	else if(MouseX>x1
	&&MouseX<x2
	&&MouseY>y1
	&&MouseY<y2
	&&press==0)
	{
		return 2;
	}

	//�ڿ��е���Ҽ����򷵻�3
	else if(MouseX>x1
	&&MouseX<x2
	&&MouseY>y1
	&&MouseY<y2
	&&press==2)
	{
		return 3;
	}

	else
	{
		return 0;
	}
}

//�������ƣ�memory_mouse
//����Ŀ�ģ������������ľ������ص�

void memory_mouse(int x,int y,int page)
//x=MouseX,y=MouseY
{
	int i,j;
	for(i=0;i<15;i++)
	{
		for(j=0;j<22;j++)
		{
			mouse_color[i][j]=get_pixel_color(x-2+i,y-3+j,page);
		}
	}
	MouseX_memory=x;
	MouseY_memory=y;
}

//�������ƣ�truly_clean_mouse
//����Ŀ�ģ�ʵ���������

void truly_clean_mouse(int x,int y,int page)
//x=MouseX,y=MouseY
{
	int x0,y0;
	for(x0=x-2;x0<=x+12;x0++)
	{
		for(y0=y-3;y0<=y+18;y0++)
		{
			point_drawing(x0,y0,mouse_color[x0-x+2][y0-y+3],page);
		}
	}
}

//�������ƣ�get_pixel_color
//����Ŀ�ģ���ȡ���ص���ɫ

int get_pixel_color(int x,int y,int page) 
{
    unsigned int far *const buffer=(unsigned int far*)0xa0000000L;
    if(x<0||x>XMAX||y<0||y>YMAX) 
	{
        return -1;//����-1��ʾ���곬����Χ
    }
    // ����ƫ����
    unsigned long long int delta=((unsigned long long int)y<<10)+x;
    // ��������ҳ
    int i=y/32;
    int eventual_page=(page>>16)+i;
    pageturn(eventual_page); 
    // ���ظ����ص����ɫ
    return buffer[delta];
}

