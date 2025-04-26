
/*
**�ļ����ƣ�queue
**�ļ�Ŀ�ģ�ʵ�ֶ��е�����
**ʱ�临�Ӷȣ����
**�ռ临�Ӷȣ����
*/

#include<stdlib.h>
#include<queue.h>
#include<stce.h>

//�������ƣ�initqueue
//����Ŀ�ģ�ʵ�ֶ��еĳ�ʼ��

void initqueue(Queue* q)
{
	//���ǿյģ���Ϊɶ��û��
	q->front=q->rear=NULL;
}

//�������ƣ�push
//����Ŀ�ģ��������

void push(Queue* q,struct TrieNode* node)
{
	//QueueNode* newNode=(QueueNode*)malloc(sizeof(QueueNode));
	QueueNode* newNode=(QueueNode*)malloc(sizeof(QueueNode));
	//QueueNode* newNode=(QueueNode*)malloc(8);
	newNode->data=node;//newNode�����ݾ���node����
	newNode->next=NULL;//newNode����һ�����ǿյģ���Ϊɶ��û��
	if(q->rear==NULL)//����������ǿյ�
	{
		q->front=q->rear=newNode;//����������Ǹ��Ͷ�����newNode
	}
	else//Ҫ�ǲ��ǿյ�
	{
		q->rear->next=newNode;//����Ǹ���һ����newNode������ѭ��
		q->rear=newNode;//�����Ǹ�����newNode
	}
}

//�������ƣ�pop
//����Ŀ�ģ�ɾ���׸��ڵ�

struct TrieNode* pop(Queue* q)
{
	if(q->front==NULL)
	{
		return NULL;//���������Ǹ������ˣ���ûʲô����ɾ����
	}
	QueueNode* temp=q->front;
	struct TrieNode* node=temp->data;
	q->front=q->front->next;
	//ֱ�Ӱ�q->front�����ƣ�����Ҳ�ò���q->front�ˣ�Ȼ��q->front->next��˳����³�Ϊ���Ǹ�front
	if(q->front==NULL)
	{
		q->rear=NULL;//����Ҫ����front����֮��Ҫ�Ǳ�����ˣ��ǾͰ�rear��Ϊ�հɣ�
	}
	free(temp);//�ڴ��������
	return node;
}

//�������ƣ�queue_empty
//����Ŀ�ģ��ж϶����Ƿ�Ϊ��

int queue_empty(Queue* q)
{
	if(q->front==NULL)
	{
		return 1;
	} 
	else
	{
		return 0;
	}
} 
