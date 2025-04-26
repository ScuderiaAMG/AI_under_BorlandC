




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
#include<car.h>
#include<dog.h>
#include<boy.h>
#include<fish.h>
#include<allo.h>
#include<view.h>
/********************
	
����Ŀ�ģ����¶�λ�����ղ�ͬ��Ҫ�� 
	
	x,y:��ͼ��ԭ�㣨�����ĵ㣩����λ�ã����ں��滭ͼ
	��car(int x,int y,float k,int color,int page)�����x,y 

	k:�������� 
	
	posi:�ṩ��λ���ݵ����� 
			posi[0]���� 
			posi[1]����
			posi[2]����
			posi[3]���� 
			posi[4]����x
			posi[5]����y			
			
	p0:ԭͼ�еĳ�ʼ���꣨�ջ������ģ� 
			p0[0]���� 
			p0[1]����
			p0[2]����
			p0[3]���� 
			p0[4]����x
			p0[5]����y	
			
	xy0:ԭͼ�е�ԭ�����꣨�ջ������ģ� 	
			
	judge[0]�� ȷ����Ҫ����ʲô��λ��ֻ�Ƕ�λ�������������� 
	
			1������ ���� ��λ��ͣ���� 
			2������ �ҡ��� ��λ��ͣ���� 
			3������ ���� ��λ��ͣ���� 
			4������ �ҡ��� ��λ��ͣ���� 
			5������ ���Ķ�λ������ͣ���� 
			
	judge[1]: �ȿ���λ�ã������ƴ�С���ú����������ƴ�С 
			���Ҫ���������Ҷ������ƵĻ������ݱȺ��п��ܲ�һ����ͼ�ε���״�ͻ�����⣬�����ر������⼸����� 
		
			1���� �ϡ��� ���ƴ�С
			2���� ���� ���ƴ�С
140********************/

void allo(int* x,int* y,float* k,int page,int* posi,int* p0,int* xy0,int* judge)
{
	/******
	��ʽ���� 
	posi[0] = k*(*y-xy0[1]+p0[0])-*y*(k-1) = (p0[0]-xy0[1])*k+*y
	posi[1] = k*(*y-xy0[1]+p0[1])-*y*(k-1) = (p0[1]-xy0[1])*k+*y
	posi[2] = k*(*x-xy0[0]+p0[2])-*x*(k-1) = (p0[2]-xy0[0])*k+*x
	posi[3] = k*(*x-xy0[0]+p0[3])-*x*(k-1) = (p0[3]-xy0[0])*k+*x

	posi[4] = k*(*x-xy0[0]+p0[4])-*x*(k-1) = ((posi[2]+posi[3])/2-xy0[0])*k+*x
	posi[5] = k*(*y-xy0[1]+p0[5])-*y*(k-1) = ((posi[0]+posi[1])/2-xy0[1])*k+*y
	******/	

/*	
��ã� 
	*y=posi[0]-(p0[0]-xy0[1])*k;
	*y=posi[1]-(p0[1]-xy0[1])*k;
	*x=posi[2]-(p0[2]-xy0[0])*k;
	*x=posi[3]-(p0[3]-xy0[0])*k;
	
	*x=posi[4]-((posi[2]+posi[3])/2-xy0[0])*k;
	*y=posi[5]-((posi[0]+posi[1])/2-xy0[1])*k;
*/	

	//��������ı��� 
	switch(judge[1])
	{
		case 1:
			*k=((float)(posi[1]-posi[0]))/((float)(p0[1]-p0[0])); 
			break;
		case 2:
			*k=((float)(posi[3]-posi[2]))/((float)(p0[3]-p0[2])); 
			break;	
		default:
			*k=((float)(posi[3]-posi[2]))/((float)(p0[3]-p0[2])); 
			break;
	}
	
	//���嶨λͼ��λ�� 
	switch(judge[0])
	{
		case 1:
			*y=posi[0]-(p0[0]-xy0[1])*(*k);
			*x=posi[2]-(p0[2]-xy0[0])*(*k);
			posi[1]=posi[0]+*k*(p0[1]-p0[0]);
			posi[3]=posi[2]+*k*(p0[3]-p0[2]);
			break;
		case 2:
			*y=posi[0]-(p0[0]-xy0[1])*(*k);
			*x=posi[3]-(p0[3]-xy0[0])*(*k);
			posi[1]=posi[0]+*k*(p0[1]-p0[0]);
			posi[2]=posi[3]-*k*(p0[3]-p0[2]);
			break;
		case 3:
			*y=posi[1]-(p0[1]-xy0[1])*(*k);
			*x=posi[2]-(p0[2]-xy0[0])*(*k);
			posi[0]=posi[1]-*k*(p0[1]-p0[0]);
			posi[3]=posi[2]+*k*(p0[3]-p0[2]);
			break;
		case 4:
			*y=posi[1]-(p0[1]-xy0[1])*(*k);
			*x=posi[3]-(p0[3]-xy0[0])*(*k);
			posi[0]=posi[1]-*k*(p0[1]-p0[0]);
			posi[2]=posi[3]-*k*(p0[3]-p0[2]);
			break;
		case 5:
			*x=posi[4]-(p0[4]-xy0[0])*(*k);
			*y=posi[5]-(p0[5]-xy0[1])*(*k);
			posi[0]=posi[5]-*k*(p0[5]-p0[0]);
			posi[1]=posi[5]+*k*(p0[1]-p0[5]);
			posi[2]=posi[4]-*k*(p0[4]-p0[2]);
			posi[3]=posi[4]+*k*(p0[3]-p0[4]);
			break;

		default:
			*x=posi[4]-(p0[4]-xy0[0])*(*k);
			*y=posi[5]-(p0[5]-xy0[1])*(*k);
			posi[0]=posi[5]-*k*(p0[5]-p0[0]);
			posi[1]=posi[5]+*k*(p0[1]-p0[5]);
			posi[2]=posi[4]-*k*(p0[4]-p0[2]);
			posi[3]=posi[4]+*k*(p0[3]-p0[4]);
			break;
	}
} 




//��С�������� 
void put_picture_car1(int* posi,int* judge,int page,int color)
{
	
	int x=0;
	int y=0;
	float k=1.0;
	int xy0[2]={304,618};
	int p0[6]={362,662,207,683,445,512};
			
	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	secure(posi);
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
	car(x,y,k,color,page,0);
	car_light(x,y,k,color,page,0); 
	car_windows(x,y,k,color,page,0); 
}

//��С�������� 
void put_picture_car2(int* posi,int* judge,int page,int color)
{
	
	int x=0;
	int y=0;
	float k=1.0;
	int xy0[2]={304,618};
	int p0[6]={362,662,207,683,445,512};
			
	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	secure(posi);
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
	car(x,y,k,color,page,1);
	car_light(x,y,k,color,page,1); 
	car_windows(x,y,k,color,page,1); 
}


//��С�к� 
void put_picture_boy(int* posi,int* judge,int page,int color)	
{
	int x=0;
	int y=0;
	float k=1.0;
	int xy0[2]={524,353};
	int p0[6]={350,689,442,585,513,520};	
 
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
	secure(posi);	
	allo(&x,&y,&k,page,posi, p0, xy0,judge);
	boy(x,y,k,color,page);	
}


//��С�����ң� 
void put_picture_dog1(int* posi,int* judge,int page,int color)
{
 	int x=0;
 	int y=0;
 	float k=1.0;
 	int xy0[2]={414,245};
 	int p0[6]={70,470,216,610,413,270};	
 	
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	dog_body(x,y,k,color,page,0);	
	dog_eyes(x,y,k,color,page,0);	
}

//�����С�����ң� 
void put_picture_dog1_fill(int* posi,int* judge,int page,int color)
{
 	int x=0;
 	int y=0;
 	float k=1.0;
 	int xy0[2]={414,245};
 	int p0[6]={70,470,216,610,413,270};	
 	
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	dog_body(x,y,k,color,page,0);	
 	fill_1(color,page);
	dog_eyes(x,y,k,color,page,0);
}
 
//��С������ 
void put_picture_dog2(int* posi,int* judge,int page,int color)
{
 	int x=0;
 	int y=0;
 	float k=1.0;
 	int xy0[2]={414,245};
 	int p0[6]={70,470,216,610,413,270};	
 	
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	dog_body(x,y,k,color,page,1);	
 	dog_eyes(x,y,k,color,page,1);
}

//�����С������ 
void put_picture_dog2_fill(int* posi,int* judge,int page,int color)
{
 	int x=0;
 	int y=0;
 	float k=1.0;
 	int xy0[2]={414,245};
 	int p0[6]={70,470,216,610,413,270};	
 	
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	dog_body(x,y,k,color,page,1);
 	fill_1(color,page);
	dog_eyes(x,y,k,color,page,1);	
}

//����(��) 
void put_picture_fish1(int* posi,int* judge,int page,int color)	
{
 	int x=0;
 	int y=0;
 	float k=1.0;
 	int xy0[2]={497,411};
 	int p0[6]={411,490,445,635,540,450};	
 	
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	secure(posi);
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	fish(x,y,k,color,page,0);	
 	fish_head(x,y,k,color+1,page,0);
 	fish_eye(x,y,k,color+2,page,0);
}
 

//����(��) 
void put_picture_fish2(int* posi,int* judge,int page,int color)	
{
 	int x=0;
 	int y=0;
 	float k=1.0;
 	int xy0[2]={497,411};
 	int p0[6]={411,490,445,635,540,450};	
 	
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	secure(posi);
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	fish(x,y,k,color,page,1);	
 	fish_head(x,y,k,color+1,page,1);
 	fish_eye(x,y,k,color+1,page,1);
}
 
//�����಻�ϵ�ɽ����������kΪ1�Ǵ����������������棩 
void put_picture_mountain(int* posi,int* judge,int page,int color)	
 {	int x=0;
 	int y=0;
 	float k=1.0;
 	int xy0[2]={1,343};
 	int p0[6]={0,689,1,1024,512,363};	
 	
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	mountain(x,y,k,color,page);
}


//��ˮ�Ĳ��� 
void put_picture_water(int* posi,int* judge,int page,int color)
{
	int x=0;
 	int y=0;
 	float k=1.0;
 	int xy0[2]={1,343};
 	int p0[6]={653,697,214,620,417,675};	
 	
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	water(x,y,k,color,page);
}


//������е��� 
void put_picture_cloud(int* posi,int* judge,int page,int color)
{
 	int x=0;
 	int y=0;
 	float k=1.0;
 	int xy0[2]={1,343};
 	int p0[6]={39,125,186,302,244,164};	
 	
 	allo(&x,&y,&k,page,posi, p0, xy0,judge);
 	cloud(x,y,k,color,page);
}

//��ֹͼ��Խ�� 
void secure(int* posi)
{
	if(posi[0]<=105)
	{
		posi[1]+=(105-posi[0]);
		posi[0]=105;
	}
	if(posi[1]>=489)
	{
		posi[0]-=(posi[1]-489);
		posi[1]=489;
	}
	if(posi[2]<=135)
	{
		posi[3]+=(135-posi[2]);
		posi[2]=135;
	}
	if(posi[3]>=925)
	{
		posi[2]-=(posi[3]-925);
		posi[3]=925;
	} 
}
