
/*
**�ļ����ƣ�stceAC
**�ļ�Ŀ�ģ�ʱ̬��������ݵ��ж�
**�ռ临�Ӷȣ����ӱ�ų���
**ʱ�临�Ӷȣ�\Theta(1)
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<alloc.h>
#include<queue.h>
#include<stce.h>

int tense(char*temp)
{
	// �����ȥʱ̬�ؼ���
	if(strstr(temp,"��") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��ǰ") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"֮ǰ") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��ǰ") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��ȥ") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"�ϻ�") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"�ϴ�") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��ʱ") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��ʱ") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"����") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"ǰ��") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"ȥ��") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"ǰ��") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"����") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"����") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��ǰ") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"֮ǰ") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"����") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"����") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��ʱ") != NULL)
	    return TENSE_PAST;
	
	// ������ʱ̬�ؼ���
	if(strstr(temp,"δ��") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"����") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"����") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"����") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"����") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"����") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"����") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"���") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"����") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"����") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"Զ��") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"Զ��") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"�˺�") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"����") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"�Ժ�") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"չ��") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"����") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"֮��") != NULL)
	    return TENSE_FUTURE;
	
	// ��������ʱ̬�ؼ���
	if(strstr(temp,"����") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"�˿�") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"��ʱ") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"����") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"Ŀǰ") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"����") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"�漴") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"�˿�") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"��") != NULL)
	    return TENSE_PRESENT;
	return 4;
}

int already(char* temp)
{
	// ���������ؼ���
	if(strstr(temp,"��") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"�Ѿ�") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"�ո�") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"����") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"����") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"�վ�") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"����") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"֮��") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"����") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��") != NULL)
	    return TENSE_PAST;
	if(strstr(temp,"��") != NULL)
	    return TENSE_PAST;
	
	// ����Ҫ���ؼ���
	if(strstr(temp,"����") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"����") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"����") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"��Ҫ") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"׼��") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"����") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"�ƻ�") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"����") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"Ҫ") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"��") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"ȥ") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"�ۿ�") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"�н�") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"����") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"����") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"����") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"����") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"����") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"��") != NULL)
	    return TENSE_FUTURE;
	if(strstr(temp,"��") != NULL)
	    return TENSE_FUTURE;
	
	// ���������ؼ���
	if(strstr(temp,"��") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"��") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"��") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"����") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"����") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"����") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"֮��") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"���") != NULL)
	    return TENSE_PRESENT;
	if(strstr(temp,"��ʱ") != NULL)
	    return TENSE_PRESENT;
}

int beidong(char* str)
{
	if(strstr(str,"��")!=NULL)
	{
		if(strstr(str,"����")==NULL)
		{
			return 1;
			//1��Ӧ������
		}
	}
	return 0;
	//0��Ӧ������
}
