
/*
** �������ƣ�SVGA�����߼� 
** ����Ŀ�ģ�ʵ��SVGA 
** ʱ�临�Ӷȣ����ϵ�����ٶ�
** �ռ临�Ӷȣ���С�ռ� 
*/

#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<xiezi.h>
#include<mouse.h>
#include<draw.h>

//�������ƣ�start_SVGA
//����Ŀ�ģ���ʼ��65536ɫSVGA��ʾ
void start_SVGA()
{
	union REGS our_AI_regs;
	our_AI_regs.x.ax=0x4f02;//������ʾģʽ
	our_AI_regs.x.bx=0x117;//���ó�65536ɫSVGA��ʾ
	int86(0x10,&our_AI_regs,&our_AI_regs);
	//���жϳ���SVGA��Ȩ���ܣ��Ĵ����洢ֵ
	if(our_AI_regs.x.ax!=0x004f)
	{
		printf("��ʼ��ʧ�ܣ�����0x%x��������˳�",our_AI_regs.x.ax);
		getchar();
		exit(1);
	}
}

//�������ƣ�examine_start_SVGA
//����Ŀ�ģ��ж��Ƿ��ʼ���ɹ�

int examine_start_SVGA()
{
	union REGS our_AI_regs;
	our_AI_regs.x.ax=0x4f03;//����ǰ��ʾģʽ
	int86(0x10,&our_AI_regs,&our_AI_regs);//���ж�
	if(our_AI_regs.x.ax!=0x004f)
	{
		printf("��ʼ��ʧ�ܣ�����0x%x��������˳�",our_AI_regs.x.ax);
		getchar();
		exit(1);
	}
	return 1;
}

//�������ƣ�pageturn
//����Ŀ�ģ���ҳ����,������pageҳ 
/*
void pageturn(register int page)//�üĴ������ӿ컻ҳ�ٶ� 
{
	static int flag = 0;  // 0 ���� false��1 ���� true,BC��֧�ֲ���ֵ 
	union REGS our_AI_regs;
	static int whether=0;//������ܱ�
	static int initial_page;//���Ҳ��Ҫ���ֲ��� 
	our_AI_regs.x.ax=0x4f05;//�����ڴ�ҳ�����л�
	our_AI_regs.x.bx=0;//�Ĵ������ֵΪ0
	if(whether==0)
	{
		our_AI_regs.x.dx=page;//��ҳ 
		int86(0x10,&our_AI_regs,&our_AI_regs);//���ж� 
		flag=1;
		initial_page=page;//����ά�� 
	} 
	else if(page!=initial_page)
	{
		our_AI_regs.x.dx=page;
		int86(0x10,&our_AI_regs,&our_AI_regs);
		initial_page=page;
	}
}
*/

void pageturn(register int page)
{
	union REGS our_AI_regs;
	our_AI_regs.x.ax=0x4f05;
	our_AI_regs.x.bx=0;
	our_AI_regs.x.dx=page;
	int86(0x10,&our_AI_regs,&our_AI_regs);
}

//�������ƣ�point_drawing
//����Ŀ�ģ��ɵ���ߣ�ȷ�����㺯��

int point_drawing(int x,int y,int color,int page)
{
	unsigned int far *const buffer= (unsigned int far*)0xa0000000L;
	//ָ���׵�ַ���ɶ�����д��ִ�� 
	if(x<0||x>XMAX||y<0||y>YMAX)//�Լ�Ҫ�ȶ���һ�£����� 
	{
		return 0;
	}
	//����㲻����Ļ���棬�Ͳ���������
	unsigned long long int delta=((unsigned long long int)y<<10)+x;
	//��������ƫ����delta��1024=2<<10,һ��y������ô������
	int i=y/32;
	int eventual_page=(page>>16)+i;//2^16���㻻ҳһ��
	pageturn(eventual_page); 
	buffer[delta]=color; 
}

//�������ƣ�line_drawing
//����Ŀ�ģ���Bresenham�㷨����
int line_drawing(int x1,int y1,int x2,int y2,int color,int page,int status)
{
	int delta_x=abs(x2-x1);
	int delta_y=abs(y2-y1);//�����ֵ
	int delta_x2,delta_y2;
	int sign_x=0,sign_y=0;
	int i,min,max;
	int error,flag;
	if(status==0)
	{
		if(x1<x2)
		{
			sign_x=1;
		}
		else if(x1>x2)
		{
			sign_x=-1;
		}
		else//��ֱ�߶�ֱ�ӻ�
		{
			if(y1>y2)
			{
				max=y1;
				min=y2;
			}
			else
			{
				max=y2;
				min=y1;
			}
			for(i=min;i<=max;i++)
			{
				point_drawing(x1,i,color,page);
			}
			//return 0;
		}
		if(y1<y2)
		{
			sign_y=1;
		} 
		else if(y1>y2)
		{
			sign_y=-1;
		}
		else//ˮƽֱ��ֱ�ӻ� 
		{
			if(x1<x2)
			{
				max=x2;
				min=x1;
			} 
			else
			{
				max=x1;
				min=x2;
			}
			for(i=min;i<=max;i++)
			{
				point_drawing(i,y1,color,page);
			}
		}
		point_drawing(x1,y1,color,page);
		delta_x2=delta_x<<1;
		delta_y2=delta_y<<1;//�������2������
		if(delta_x>=delta_y)//�������ʺ���Ϊ��׼
		{
			error=delta_y2-delta_x;//ȷ�������
			flag=delta_y2-delta_x2;
			while(delta_x--)//����x�ڿ�����Ҫ�ǵ�0�Ͳ�ִ����
			{
				if(error<=0)
				{
					error+=delta_y2;
				}
				else
				{
					y1+=sign_y;
					error+=flag;
				}
				//ƽ��ÿ��delta_x2-delta_y2/delta_y2+1 ����ͻ�һ����,�Ǹ�+1����else����û��ִ�п���x������һ��
				x1+=sign_x;
				point_drawing(x1,y1,color,page);
			}
		}
		else
		{
			error=delta_x2-delta_y;
			flag=delta_x2-delta_y2;
			while(delta_y--)
			{
				if(error<=0)
				{
					error+=delta_x2;
				}
				else
				{
					x1+=sign_x;
					error+=flag;
				}
				y1+=sign_y;
				point_drawing(x1,y1,color,page);
			}
		}		
	}
	else if(status==1)
	{
		if(x1<x2)
		{
			sign_x=1;
		}
		else if(x1>x2)
		{
			sign_x=-1;
		}
		else//��ֱ�߶�ֱ�ӻ�
		{
			if(y1>y2)
			{
				max=y1;
				min=y2;
			}
			else
			{
				max=y2;
				min=y1;
			}
			for(i=min;i<=max;i++)
			{
				if(i<=565)
				{
					point_drawing(x1,i,color,page);	
				}
			}
			//return 0;
		}
		if(y1<y2)
		{
			sign_y=1;
		} 
		else if(y1>y2)
		{
			sign_y=-1;
		}
		else//ˮƽֱ��ֱ�ӻ� 
		{
			if(x1<x2)
			{
				max=x2;
				min=x1;
			} 
			else
			{
				max=x1;
				min=x2;
			}
			for(i=min;i<=max;i++)
			{
				if(y1<=565)
				{
					point_drawing(i,y1,color,page);	
				}
			}
		}
		if(y1<=565)
		{
			point_drawing(x1,y1,color,page);
		}
		delta_x2=delta_x<<1;
		delta_y2=delta_y<<1;//�������2������
		if(delta_x>=delta_y)//�������ʺ���Ϊ��׼
		{
			error=delta_y2-delta_x;//ȷ�������
			flag=delta_y2-delta_x2;
			while(delta_x--)//����x�ڿ�����Ҫ�ǵ�0�Ͳ�ִ����
			{
				if(error<=0)
				{
					error+=delta_y2;
				}
				else
				{
					y1+=sign_y;
					error+=flag;
				}
				//ƽ��ÿ��delta_x2-delta_y2/delta_y2+1 ����ͻ�һ����,�Ǹ�+1����else����û��ִ�п���x������һ��
				x1+=sign_x;
				if(y1<=565)
				{
					point_drawing(x1,y1,color,page);
				}
			}
		}
		else
		{
			error=delta_x2-delta_y;
			flag=delta_x2-delta_y2;
			while(delta_y--)
			{
				if(error<=0)
				{
					error+=delta_x2;
				}
				else
				{
					x1+=sign_x;
					error+=flag;
				}
				y1+=sign_y;
				if(y1<=565)
				{
					point_drawing(x1,y1,color,page);	
				}
			}
		}
	}
}

//�������ƣ�circle_without_drawing
//����Ŀ�ģ�Bresenham�㷨��ԲȦ

void circle_without_drawing(int x,int y,int r,int color,int page)
{
	if(r<=0)
	{
		printf("�뾶Ϊ����������˳�");
		getchar();
		exit(1);
	}
	int i=r;
	int error=3-2*r;//�����
	int j;
	for(j=0;j<=i;j++)
	{
		point_drawing(x+j,y+i,color,page);
		point_drawing(x+j,y-i,color,page);
		point_drawing(x-j,y+i,color,page);
		point_drawing(x-j,y-i,color,page);
		point_drawing(x+i,y+j,color,page);
		point_drawing(x+i,y-j,color,page);
		point_drawing(x-i,y+j,color,page);
		point_drawing(x-i,y-j,color,page);
		//Բ�ĶԳ��Ի�8���ԳƵĵ�
		if(error<0)
		{
			error+=4*j+6;
		}
		else
		{
			error+=4*(j-i)+10;
			i--;
		}
	}
}

//�������ƣ�circle_with_drawing
//����Ŀ�ģ���ʵ��Բ

void circle_with_drawing(int x,int y,int r,int color,int page,int status)
{
	int setx=0,sety=r,dx=3,d2=2-2*r,d=1-r;
	if(r<=0)
	{
		printf("�뾶Ϊ����������˳�");
		getchar();
		exit(1);
	}
	while(setx<=sety)
	{
		line_drawing(x-setx,y-sety,x+setx,y-sety,color,page,status);
		line_drawing(x-sety,y-setx,x+sety,y-setx,color,page,status);
		line_drawing(x-sety,y+setx,x+sety,y+setx,color,page,status);
		line_drawing(x-setx,y+sety,x+setx,y+sety,color,page,status);
		if(d<0)
		{
			d+=dx;
			dx+=2;
		}
		else
		{
			sety--;
			d+=(dx+d2);
			dx+=2;
			d2+=2;
		}
		setx++;
	}
}

//�������ƣ�fill_color
//����Ŀ�ģ�ʵ����ɫ�����λ���

void fill_color(int x1,int y1,int x2,int y2,int color,int page,int status)
{
	int i,j;
	if(status==0)
	{
		for(i=x1;i<=x2;i++)
		{
			for(j=y1;j<=y2;j++)
			{
				point_drawing(i,j,color,page);
			}
		}	
	}
	else
	{
		if(y1<=575&&y2>=575)
		{
			for(i=x1;i<=x2;i++)
			{
				for(j=y1;j<=575;j++)
				{
					point_drawing(i,j,color,page);
				}
			}
		}
		if(y1<=575&&y2<=575)
		{
			for(i=x1;i<=x2;i++)
			{
				for(j=y1;j<=y2;j++)
				{
					point_drawing(i,j,color,page);
				}
			}	
		}
	}
}

//�������ƣ�exit_SVGA
//����Ŀ�ģ��ر�SVGA

void exit_SVGA()
{
	union REGS our_AI_regs;
	our_AI_regs.h.ah=0;
	our_AI_regs.h.al=0x03;
	int86(0x10,&our_AI_regs,&our_AI_regs);
}
