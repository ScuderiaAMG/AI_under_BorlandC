
/*
** �ļ����ƣ�xiezi
** �ļ�Ŀ�ģ������뷨���뺺�� 
** ʱ�临�Ӷȣ�\Theta(1) 
** �ռ临�Ӷȣ�\Theta(1) 
*/

/*�ȽϺÿ���������£�����ֱ������Щ���� 
**���ֿ��  ��16 | 24 | 32 | 48
**Ӣ�Ŀ��  �� 8 | 15 | 20 | 26
**�����С  �� 6 |  9 | 12 | 15
**������ƫ�ƣ�-3 | -6 | -8 |  0
*/ 

#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<draw.h>
#include<math.h>
#include<xiezi.h>
#include<English.h>
#include<string.h>

//�������ƣ�SVGA_string_length
//����Ŀ�ģ�����ַ�������Ļ����ʾ�ĳ���

int SVGA_string_length(const char *str,int Chinese_length,int English_length)
{
	int sum=0; 
	while(*str!='\0')
	{
		if(*str<0)//���Ǻ������˼
		{
			sum+=Chinese_length;
			str+=2;
		}
		else//���ASC2�����е��ַ� 
		{
			sum+=English_length;
			str++;
		}
	}
	return sum;
}

//�������ƣ�string_drawing
//����Ŀ�ģ������ַ���

void string_drawing(const char *str,int x,int y,int Chinese_length,int English_length,int size,int deviation,int color,int width,int length,int page,int status)
{
	FILE *phzk=NULL;
	unsigned char quma,weima;
	unsigned long offset;
	int x0=x,y0=y,temp_y;
	unsigned char mask[8]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
	char paths[25]={'\0'};
	char data[288];
	char eng[2]={'\0'};
	sprintf(paths,"C:\\CODE\\write\\HZ%d",Chinese_length);
	phzk=fopen(paths,"rb");
	if(phzk==NULL)
	{
		printf("�޷��򿪺��ֿ⣡������˳�");
		getchar();
		exit(1);
	}
	long square=pow(Chinese_length,2)/8;//8��һ���ֽڰ����ı�����
	//int driver=IBM8514,mode=IBM8514HI;
	//char path[]="C:\\BORLANDC\\BGI";
	//initgraph(&driver,&mode,path);
	//setcolor(color);
	//settextjustify(LEFT_TEXT, TOP_TEXT);
	//settextstyle(SMALL_FONT,HORIZ_DIR,size);
	int i,j,calculate;
	if(status==0)
	{
		while(x<XMAX&&(*str)!='\0')
		{
			if(str[0]<0)
			{
				if(width>=Chinese_length&&x+Chinese_length>x0+width)//���й���
				{
					x=x0;
					y+=Chinese_length;
					if(length>=Chinese_length&&y+Chinese_length>y0+length)
					{
						break;
					}
				} 
				temp_y=y;
				quma=str[0]-0xa0;
				weima=str[1]-0xa0;
				offset=(94*(quma-1)+(weima-1))*square;//�������ֿ��ļ����ƫ������
				fseek(phzk,offset,SEEK_SET);
				fread(data,square,1,phzk);
				for(i=0;i<Chinese_length;i++)
				{
					calculate=Chinese_length*i/8;
					for(j=0;j<Chinese_length;j++)
					{
						if(mask[j&7]&data[calculate+(j>>3)])//j%8ÿ8��һѭ����j/8ÿ2��һѭ��
						{
							point_drawing(x+j,temp_y,color,page);
						}
					}
					temp_y++;
				}
				x+=Chinese_length;
				str+=2;
			}
			else
			{
				/*
				int driver=IBM8514,mode=IBM8514HI;
				char path[]="C:\\BORLANDC\\BGI";
				initgraph(&driver,&mode,path);
				setcolor(color);
				settextjustify(LEFT_TEXT, TOP_TEXT);
				settextstyle(SMALL_FONT,HORIZ_DIR,size);		
				if((width>=Chinese_length&&x+English_length>x0+width)||str[0]=='\n')
				{
					x=x0;
					y+=English_length;
					if(length>=Chinese_length&&y+Chinese_length>y0+length)//���й���
					{
						break;
					}
				}
				else if(str[0]!='\n')
				{
					eng[0]=str[0];
					English_drawing(x,y+deviation,eng,page);
					x+=English_length;
				}
				str++;*/
				English_text_drawing(x,y+deviation,str,color,page,status);
				str+=strlen(str);
			}
			//fclose(phzk);//test
		}
		fclose(phzk);	
	}
	else if(status==1)
	{
		while(x<XMAX&&(*str)!='\0')
		{
			if(str[0]<0)
			{
				if(width>=Chinese_length&&x+Chinese_length>x0+width)//���й���
				{
					x=x0;
					y+=Chinese_length;
					if(length>=Chinese_length&&y+Chinese_length>y0+length)
					{
						break;
					}
				}
				temp_y=y;
				if(y+32<=575)
				{
					quma=str[0]-0xa0;
					weima=str[1]-0xa0;
					offset=(94*(quma-1)+(weima-1))*square;//�������ֿ��ļ����ƫ������
					fseek(phzk,offset,SEEK_SET);
					fread(data,square,1,phzk);
					for(i=0;i<Chinese_length;i++)
					{
						calculate=Chinese_length*i/8;
						for(j=0;j<Chinese_length;j++)
						{
							if(mask[j&7]&data[calculate+(j>>3)])//j%8ÿ8��һѭ����j/8ÿ2��һѭ��
							{
								point_drawing(x+j,temp_y,color,page);
							}
						}
						temp_y++;
					}
					x+=Chinese_length;
					str+=2;				
				}
				else
				{
					break;
				}
			}
			else
			{
				/*
				int driver=IBM8514,mode=IBM8514HI;
				char path[]="C:\\BORLANDC\\BGI";
				initgraph(&driver,&mode,path);
				setcolor(color);
				settextjustify(LEFT_TEXT, TOP_TEXT);
				settextstyle(SMALL_FONT,HORIZ_DIR,size);		
				if((width>=Chinese_length&&x+English_length>x0+width)||str[0]=='\n')
				{
					x=x0;
					y+=English_length;
					if(length>=Chinese_length&&y+Chinese_length>y0+length)//���й��� 
					{
						break;
					}
				}
				else if(str[0]!='\n')
				{
					eng[0]=str[0];
					English_drawing(x,y+deviation,eng,page);
					x+=English_length;
				}
				str++;*/
				English_text_drawing(x,y+deviation,str,color,page,status);
				str+=strlen(str);
			}
			//fclose(phzk);//test
		}
		fclose(phzk);
	}
} 
