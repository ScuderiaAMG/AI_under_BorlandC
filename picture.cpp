
#include<graphics.h>
#include<draw.h>
#include<stdarg.h>
#include<conio.h>
#include<Bezier.h>
#include<xiezi.h>
#include<color.h>
#include<dos.h>
#include<stddef.h>
#include<mouse.h>
#include<stdlib.h>
#include<string.h>

//����ͼ��Ԫ��,������ͼ��Ԫ���е���Ϣ 
//���溯��������ʱ��ֻ���Ƚ����ṹ�壬֮���ٵ�������������Ϳ������ƽṹ���ˡ�  
void creat_pic(object p,char name[30],int num[3],int x,int y)
{
	
	int i=0;
	
	//��һ��ֵ
	strcpy(p.name,name);
	
	for(i=0;i<3;i++)
	{
		p.num[i]=num[i];
	} 
	 
	p.x=x;
	p.y=y;
	//��ֵ��ϣ����԰���������ͼ����һ���ƽṹ��
} 




//����֪ͼ����Ԫ�ؼ�λ��ʱ������λ�ø�ʵ��������л�����
//���������ֵ�ͼ���л��ϲ� 
//�ص����Ż���������������ͼ�εĴ�λ 
void merge(object* a)
{
	
	int i=0;
	int j=0;

	switch(a[i])
	{
		case 0:
			
			
	}
}


//�����������ɵ�ͼ 
void wen_sheng_tu(int color[4],int a[5],int b[5],int c[5])
{
	int a[8];
	int draw;
	int i;
	int j;
	int p;
	
	//��Ҫ�󴴽�����
	//�������2�� 
	
	 
	fill_color(0,0,1024,768,color,page,0);//���һλ��0/1��һ��
	switch()
	
		
}
