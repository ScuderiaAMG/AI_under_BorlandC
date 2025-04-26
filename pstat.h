#ifndef _pstat_h_
#define _pstat_h_

#define BIG_NUMBER 10000

#define LEGAL_INPUT 0
#define ILLEGAL_INPUT 1
#define TEST_INPUT 2 

typedef struct
{
	int num;//�û�����
	char name[15];//�û���
	char password[15];//���� 
	int chattext;//�Ի���Ӧ���ļ���� 
}LOGIN;

int page_start(int page);
void mouse_page_start(int page,int* num);
void color_change_mouse(int i,int page);
void string_inspection(int page);
int password_judge(char *str,char *password_record,int *n,int page); 

#endif
