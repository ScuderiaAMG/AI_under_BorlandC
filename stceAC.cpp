
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

//��AC�Զ������ٶ���Ŀ죨����WA�Զ�������bushi��

//�������ƣ�create_node
//����Ŀ�ģ������½ڵ�
//����Ч����
// 1 -> 2
//����˼·��
// �����½ڵ㣬����ʱ̬��end��ע������ĩβ������עΪĩβ����
// failureʧ��ָ���У�����û����ӣ�Ȼ�󷵻�����ڵ㱾�������
struct TrieNode* create_node()
{
	TrieNode* node=(TrieNode*)malloc(sizeof(TrieNode));
	
	//test!!!
	
	for(int i=0;i<53;i++)
	{
		node->children[i]=(TrieNode*)malloc(sizeof(TrieNode));
	}
	node->failure=(TrieNode*)malloc(sizeof(TrieNode));
	node->tense=TENSE_NONE;
	node->end=0;
	node->failure=NULL;
	return node;
}

//�������ƣ�insert_keyword
//����Ŀ�ģ�����ؼ��ʣ�ά�����ȼ�
//����Ч���� 
// 1-> 2 -> 3
// |   L---> 4 -> 5
// |
// L---> 6 -> 7
//����˼·��
// 1.�ʻ��ǰ�������������Ҫдѭ����
// 2.node���½�һ�������û�����"��ĸ"��Ӧ��children��Ů�����
// 3.�﷨�̳���һ������������ڵ�������ӵ��﷨����biaohao�﷨��enumֵ������������none��
// 4.����end����ر���ĩβ

void insert_keyword(struct TrieNode* root,const char* word,Tense tense)
{
	TrieNode* node=root;
	int i;
	unsigned char temp;
	for(i=0;word[i]!='\0';i++)
	{
		temp=word[i];
		if(node->children[temp]==NULL)
		{
			node->children[temp]=create_node();
		}
		node=node->children[temp];//�����ӷ�����
	}
	if(tense<node->tense||node->tense==TENSE_NONE)
	{
		node->tense=tense;//�̳и������﷨
	}
	node->end=0;//������ˣ���Ϊû��nil
}

//�������ƣ�build_failure_links
//����Ŀ�ģ�����ʧ��ָ��
//����Ч���� 
// @
//  1<-> 2 <-> 3
//  |    L<---> 4 -> 5	_______\   2
//  |                          /
//  L<---> 6 <-> 7   _______\
//����˼·��                /  1
// 1.��������
// 2.���ڵ��ʧ��ָ��ָ���Լ������ڵ㵫���и����ӣ�ѭ������ȥ����Ҫ�󲻿գ���failureָ����ڵ㣬�������,���о���"��������",������BFS�Ĳ�α���
// 3.ֻҪ���в��գ��ͽ��Ų��ң�����һ��������ѭ����Ȼ����һ�¶�����ǰ�����˭�������Ƶ���һ���ԣ�������ӣ�����Ϊ�����ٸ�ڶ�����໣���|��O��|��
// 4.��curr���ӽڵ㣬ѭ��ȥ�ң������и����ӾͶ�������child���ٶ��嵱ǰ�ڵ��ʧ��ָ�룬Ȼ��һ·����׷�ݣ�fail��fail��ʧ��ָ�룬�������׷�� 
// ׷�ݵ�ʲôʱ��Ϊֹ�أ�ֱ��fail��root��ȥroot���ɣ�����fail��children������Ӧ�ĵڼ�����ĸ���Ǿ�ȥ�Ǹ���Ӧ��ĸ�ˣ�
// 5.Ҫ��fail��children[i]���Ǿ�ȥfail��children�����ˣ���Ȼ��ȥroot
// 6.���ӵ�ʱ̬���Ǻ���ʧ��ָ���ʱ̬
// 7.�ӽڵ���ӣ��������BFS�������Ͼ͸���һ��BFS

void build_failure_links(struct TrieNode* root)
{
	Queue* q;
	q;//test
	q->front;//test
	q->rear;//test
	//�������з������BFS
	root->failure=root;
	//���ڵ��ʧ��ָ��ָ���Լ�
	int i;
	struct TrieNode* child;
	struct TrieNode* fail;
	for(i=0;i<70;i++)
	{
		if(root->children[i]!=NULL)
		{
			root->children[i]->failure=root;//�е�һ���ӽڵ�Ļ���ָ����ڵ�
			push(q,root->children[i]);//�ѵ�һ���ӽڵ�Ŷ�������
			//�ڵ���ڶ���β��
		}
	}
	
	
	//���������ѭ�������ܣ�
	
	 
	//��һ���ӽڵ��ʧ��ָ��ָ����ڵ�
	//BFS
	
	while(queue_empty(q)==0)
	//�ж϶����Ƿ�Ϊ�գ����в�Ϊ��ʱѭ��
	{
		//���еĶ��׽ڵ���curr
		struct TrieNode* curr=pop(q);
		//��ȡ���׽ڵ㣨��ɾ�汾�����Ƴ����ж��׽ڵ�
		for(i=0;i<128;i++)
		{
			if(curr->children[i]!=NULL)
			{
				//�ӽڵ�
				child=curr->children[i];
				//��ǰ�ڵ��ʧ��ָ��
				fail=curr->failure;
				while(fail!=root&&fail->children[i]==NULL)
				//��˼���ǰ���һ��ɨ������
				{
					fail=fail->failure;
					//fail��fail��ʧ��ָ��
				}
				//Ҫ�ǻ��к��ӣ��Ǿ���fail�����ߣ���Ȼ�ͻ�root
				child->failure=fail->children[i]?fail->children[i]:root;
				if(child->failure->tense!=child->tense)
				{
					child->tense=child->failure->tense;
				}
				//�ӽڵ㣬��ӣ��Ⱥ���˾��Զ��еĽ�һ�����
				//push(q,child);
			}
		}
	}
}

//�������ƣ�detect_tense 
//����Ŀ�ģ��Զ�������
//����˼·��
// 1.�ְ�ʱ̬���NONE
// 2.�����������α������������root����childrenû���ҵ����������ߣ���failure
// 3.������滹�еĻ���curr����children�ˣ���������һ��
// 4.Ȼ����һ��once��once��������ʱ̬�ģ�ͨ����result��ʱ̬��ֻҪonce���ص�root����һֱִ��������������
// 5.���once��ĩ�˵��ˣ�end����1������ôʱ̬�ǹ�ȥʱ�ķ��ع�ȥʱ��Ҫ��Ȼresult����once��ʱ̬��Ҫ����result���Ǹ�NONE����once��ʱ̬enum��resultС�����ȼ�����
// 6.������Σ�once���once��Ӧ��failure��Ҳ����������ָ���ߣ�����ִ�У�ֱ���ߵ�rootΪֹ
// 7.����once��Ӧ��ʱ̬

Tense detect_tense(struct TrieNode* root,char* biaohao)
{
	Tense result=TENSE_NONE;//�ȸ㵽Ĭ��״̬��˵
	struct TrieNode* curr=root;
	int i;
	unsigned char temp;
	for(i=0;biaohao[i]!='\0';i++)
	{
		temp=biaohao[i];
		while(curr!=root&&curr->children[temp]==NULL)
		//����˵�ǲ��Ǹ��ڵ�Ľ�β
		{
			curr=curr->failure;
		}
		if(curr->children!=NULL)
		{
			curr=curr->children[temp];
		}
		struct TrieNode* once=curr;
		while(once!=root)
		{
			if(once->end==1)
			{
				if(once->tense==TENSE_PAST)
				{
					return TENSE_PAST;
				}
				if(once->tense<result||result==TENSE_NONE)
				{
					result=once->tense;
				}
			}
			once=once->failure;
		}
	}
	return (result!=TENSE_NONE)?result:TENSE_PRESENT;
}

//�������ƣ�init_automation
//����Ŀ�ģ�Tense���ݵĳ�ʼ��

struct TrieNode* init_automation()
{
	struct TrieNode* root=create_node();
	
	//����ֱ�Ӱ���������ڴ���ζ��Ƿ����ļ��������γ�һ�������в���
	insert_keyword(root,"��",TENSE_PAST);
	insert_keyword(root,"��",TENSE_PAST);
	insert_keyword(root,"��",TENSE_PAST);
	insert_keyword(root,"��",TENSE_PAST);
	insert_keyword(root,"��",TENSE_PAST);
	insert_keyword(root,"��",TENSE_PAST);
	insert_keyword(root,"��",TENSE_PAST);
	insert_keyword(root,"��ǰ",TENSE_PAST);
	insert_keyword(root,"֮ǰ",TENSE_PAST);
	insert_keyword(root,"��ǰ",TENSE_PAST);
	insert_keyword(root,"��ȥ",TENSE_PAST);
	insert_keyword(root,"�ϻ�",TENSE_PAST);
	insert_keyword(root,"�ϴ�",TENSE_PAST);
	insert_keyword(root,"��ʱ",TENSE_PAST);
	insert_keyword(root,"��ʱ",TENSE_PAST);
	insert_keyword(root,"����",TENSE_PAST);
	insert_keyword(root,"ǰ��",TENSE_PAST);
	insert_keyword(root,"ȥ��",TENSE_PAST);
	insert_keyword(root,"ǰ��",TENSE_PAST);
	insert_keyword(root,"����",TENSE_PAST);
	insert_keyword(root,"����",TENSE_PAST);
	insert_keyword(root,"��ǰ",TENSE_PAST);
	insert_keyword(root,"֮ǰ",TENSE_PAST);
	insert_keyword(root,"����",TENSE_PAST);
	insert_keyword(root,"����",TENSE_PAST);
	insert_keyword(root,"��ʱ",TENSE_PAST);
	
	insert_keyword(root,"δ��",TENSE_FUTURE);
	insert_keyword(root,"����",TENSE_FUTURE);
	insert_keyword(root,"����",TENSE_FUTURE);
	insert_keyword(root,"����",TENSE_FUTURE);
	insert_keyword(root,"����",TENSE_FUTURE);
	insert_keyword(root,"����",TENSE_FUTURE);
	insert_keyword(root,"����",TENSE_FUTURE);
	insert_keyword(root,"���",TENSE_FUTURE);
	insert_keyword(root,"����",TENSE_FUTURE);
	insert_keyword(root,"����",TENSE_FUTURE);
	insert_keyword(root,"Զ��",TENSE_FUTURE);
	insert_keyword(root,"Զ��",TENSE_FUTURE);
	insert_keyword(root,"�˺�",TENSE_FUTURE);
	insert_keyword(root,"����",TENSE_FUTURE);
	insert_keyword(root,"�Ժ�",TENSE_FUTURE);
	insert_keyword(root,"չ��",TENSE_FUTURE);
	insert_keyword(root,"����",TENSE_FUTURE);
	insert_keyword(root,"֮��",TENSE_FUTURE);
	
	insert_keyword(root,"����",TENSE_PRESENT);
	insert_keyword(root,"�˿�",TENSE_PRESENT);
	insert_keyword(root,"��ʱ",TENSE_PRESENT);
	insert_keyword(root,"����",TENSE_PRESENT);
	insert_keyword(root,"Ŀǰ",TENSE_PRESENT);
	insert_keyword(root,"����",TENSE_PRESENT);
	insert_keyword(root,"�漴",TENSE_PRESENT);
	insert_keyword(root,"�˿�",TENSE_PRESENT);
	insert_keyword(root,"��",TENSE_PRESENT);	
	
	build_failure_links(root);
	return root;
}

//�������ƣ�init_automation_2
//����Ŀ�ģ�ʵ����ȻδȻ�жϵĳ�ʼ��

struct TrieNode* init_automation_2()
//��ɾ���TENSE_PAST
//��������TENSE_PRESENT
//Ҫȥ������TENSE_FUTURE
{
	struct TrieNode* root2=create_node();
	
	insert_keyword(root2,"��",TENSE_PAST);
	insert_keyword(root2,"��",TENSE_PAST);
	insert_keyword(root2,"�Ѿ�",TENSE_PAST);
	insert_keyword(root2,"�ո�",TENSE_PAST);
	insert_keyword(root2,"����",TENSE_PAST);
	insert_keyword(root2,"��",TENSE_PAST);
	insert_keyword(root2,"��",TENSE_PAST);
	insert_keyword(root2,"��",TENSE_PAST);
	insert_keyword(root2,"��",TENSE_PAST);
	insert_keyword(root2,"��",TENSE_PAST);
	insert_keyword(root2,"��",TENSE_PAST);
	insert_keyword(root2,"��",TENSE_PAST);
	insert_keyword(root2,"��",TENSE_PAST);
	insert_keyword(root2,"��",TENSE_PAST);
	insert_keyword(root2,"��",TENSE_PAST);
	insert_keyword(root2,"����",TENSE_PAST);
	insert_keyword(root2,"�վ�",TENSE_PAST);
	insert_keyword(root2,"����",TENSE_PAST);
	insert_keyword(root2,"��",TENSE_PAST);
	insert_keyword(root2,"֮��",TENSE_PAST);
	insert_keyword(root2,"����",TENSE_PAST);
	insert_keyword(root2,"��",TENSE_PAST);
	insert_keyword(root2,"��",TENSE_PAST);
	
	insert_keyword(root2,"����",TENSE_FUTURE);
	insert_keyword(root2,"����",TENSE_FUTURE);
	insert_keyword(root2,"����",TENSE_FUTURE);
	insert_keyword(root2,"��Ҫ",TENSE_FUTURE);
	insert_keyword(root2,"׼��",TENSE_FUTURE);
	insert_keyword(root2,"����",TENSE_FUTURE);
	insert_keyword(root2,"�ƻ�",TENSE_FUTURE);
	insert_keyword(root2,"����",TENSE_FUTURE);
	insert_keyword(root2,"Ҫ",TENSE_FUTURE);
	insert_keyword(root2,"��",TENSE_FUTURE);
	insert_keyword(root2,"ȥ",TENSE_FUTURE);
	insert_keyword(root2,"�ۿ�",TENSE_FUTURE);
	insert_keyword(root2,"�н�",TENSE_FUTURE);
	insert_keyword(root2,"����",TENSE_FUTURE);
	insert_keyword(root2,"����",TENSE_FUTURE);
	insert_keyword(root2,"����",TENSE_FUTURE);
	insert_keyword(root2,"����",TENSE_FUTURE);
	insert_keyword(root2,"����",TENSE_FUTURE);
	insert_keyword(root2,"��",TENSE_FUTURE);
	insert_keyword(root2,"��",TENSE_FUTURE);	
	
	insert_keyword(root2,"��",TENSE_PRESENT);
	insert_keyword(root2,"��",TENSE_PRESENT);
	insert_keyword(root2,"��",TENSE_PRESENT);
	insert_keyword(root2,"����",TENSE_PRESENT);
	insert_keyword(root2,"����",TENSE_PRESENT);
	insert_keyword(root2,"����",TENSE_PRESENT);
	insert_keyword(root2,"֮��",TENSE_PRESENT);
	insert_keyword(root2,"���",TENSE_PRESENT);
	insert_keyword(root2,"��ʱ",TENSE_PRESENT);
	
	build_failure_links(root2);
	return root2;
}

//���棡���º���ֻ��һ������һ�����ӵķ��������� 

//�������ƣ�tense
//����Ŀ�ģ��ж�ʱ̬
Tense tense(char* biaohao,TrieNode* tree)
{
	/*
	TrieNode* tree=(TrieNode*)malloc(1000);
	tree=init_automation();
	*///��һ�������ִ�к���������ӣ����Ķ�
	Tense tense_;
	tense_=detect_tense(tree,biaohao);
	return tense_;
}

//�������ƣ�already
//����Ŀ�ģ��ж���Ȼ��δȻ
Tense already(char* biaohao,TrieNode* tree)
{
	/*
	TrieNode* tree=(TrieNode*)malloc(1000);
	tree=init_automation_2();
	*///��һ��Ҳ�������Ǹ�ִ�к����������
	Tense tense_;
	tense_=detect_tense(tree,biaohao);
	return tense_;
} 

//�������ƣ�beidong
//����Ŀ�ģ��ж��ǲ��Ǳ�����

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

void recursiveFunction(TrieNode* node)
{
    if (node == NULL) 
	{  
	// �սڵ���Ϊһ�ֿ��ܵ��˳�����
        return;
    }
    // �����ݹ��߼�
    // ��������ӽڵ�
    for (int i = 0; i < 256; i++) 
	{
        if (node->children[i] != NULL) 
		{
            recursiveFunction(node->children[i]);
        }
    }
}
