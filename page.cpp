
/*
** �ļ����ƣ�page 
** �ļ�Ŀ�ģ�ʵ�ֻ�ҳ 
** ʱ�临�Ӷȣ�OH(1) 
** �ռ临�Ӷȣ�OH(1) 
*/

#include<stdio.h>
#include<pstat.h>
#include<pregi.h>
#include<page.h>
#include<dos.h>
#include<mouse.h>
#include<pchat.h>

void change_page(int *page)//��������ʲô����������Ӿ��У�Ҫ����Ĭ�ϱ����void�Ϳ��� 
{
	//clrmous(MouseX,MouseY,*page);
	static int initial_page=PAGE_START;//��ʼ�㿪ʼ
	int current_page=*page;
	switch(*page)
	{
		case PAGE_TEST:
			*page=page_test();
			break;
		case PAGE_START:
			*page=page_start(PAGE_START);
			break;
		case PAGE_CHAT1:
			*page=page_chat1();
			clean_chat2();
			break;
		case PAGE_CHAT2:
			*page=page_chat2();
			clean_chat1();
			break;
		case PAGE_EXIT:
			*page=page_exit();
			break;
		case PAGE_BEFORE:
			*page=initial_page;
			break;
		case PAGE_REGISTER:
			*page=register_picture(PAGE_REGISTER);
			break;
		default:
			printf("��֪��ҳ����һҳȥ�ˣ�");
	}
	initial_page=current_page;
	mouseinit(*page);
}
