#ifndef _pic_h
#define _pic_h

//����ÿ������Ԫ�صĽṹ��
typedef struct {

//���������ͼ��Ԫ�س�ʼ������
	char name[30];//��¼����

	//num[0]Ϊ�û���Ԫ�صĵ�һ�����
	//num[1]Ϊ�û���Ԫ�صĵڶ������
	//������ʱ���ص��������������
	int num[3];

	//��ʼ�̶���ĺ������꣨���ǵ�һ�ʻ����Ǹ���ʼ�㣩
	int x;
	int y;



//�����ǻ�ͼ��ʱ�����Ҫ��ɵ���
	//ָ����ĺ�������
	//Ҳ����ָ����ȷ��λ��
	int x1;
	int y1;

	//int color;//ͼ����ɫ

	//�жϴ�С�����Ƿ����ı���k
	int size;

	//�洢��Ԫ�ص����ȼ�
	//��ֵԽ�����ȼ�Խ�ߣ�Խ������ʾ
	int level;

} object;




//�����ڵ㣬������������ʲôͼƬ
//���ڲ���ʱ��Ϊ����
typedef struct 
{

	object a;//�����ṹ��

	int kind;//��¼ͼ�������࣬���Ͳ��ҵ�ʱ�临�Ӷ�

} node;


void wen_sheng_tu(int color, int a[][5]);

void creat_pic(object p,char name[30],int num[3],int x,int y);
#endif
