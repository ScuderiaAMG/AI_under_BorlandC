#ifndef _queue_h_
#define _queue_h_

struct QueueNode
{
	struct TrieNode* data;
	struct QueueNode* next;
};
//������ʽ��֪���Լ���˭��֪����һ����˭ 

typedef struct
{
	QueueNode* front;//����֮�� 
	QueueNode* rear;//����֮β 
}Queue;
//������ʽ��֪����һ����˭��Ҳ֪�����һ����˭ 

void initqueue(Queue* q);
void push(Queue* q,struct TrieNode* node);
struct TrieNode* pop(Queue* q);
int queue_empty(Queue* q);

#endif
