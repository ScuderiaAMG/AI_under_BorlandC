
#ifndef _new_h_
#define _new_h_

/***************
    PHR�ṹ�壺���ڴ洢�Ͼ������и����ɷֵı�ţ��Լ����ת��֮��ı��
***************/
typedef struct
{
    char* str; //�洢�ξ����������
    int num_arr[15]; //�洢��С����ָ���ı�ţ����û���ҵ�num_arr[0]==0
    int num_pre[15]; //�洢һ�����Ա��ؼ�������������Ĵ���ı��
    int x; //�����жϸô��Ƿ���Ҫ�ؼ��������x=1����Ա������x=0���ܱ����
    int record;//��ʾnum_pre������˶��ٸ�����
} PHR;

/***************
    Temp�ṹ�壺������ʱ�洢�����ļ�ʱ��ʱ�ѵ��ı��+��������
***************/
typedef struct
{
    char num[20];
    char phrase[100];
} Temp;

int atoi_f(char* a, int* num_arr, int n, int ci_xing, int* c);
int atoI(const char* str);
int get_num(char* a);
PHR* remark(char** str);
PHR* mark(char** str, int* ceng);
PHR* input(char** word,char* biaohao);
PHR* input2(char word[1][101],char* biaohao);

#endif 
