#ifndef _page_h_
#define _page_h_

enum PAGE
{
	PAGE_TEST,
	PAGE_START,
	PAGE_REGISTER,
	PAGE_CHAT1,
	PAGE_CHAT2,
	PAGE_BEFORE,//�����ϸ����� 
	PAGE_EXIT,//�������� 
	PAGE_CLOSE// �رս��� 
};

void change_page(int *page);

#endif
