#ifndef _stceAC_h_
#define _stceAC_h_

#define PAST 0
#define NOW 1
#define FUTURE 2

typedef enum
{
	TENSE_PAST,
	//��� 
	TENSE_PRESENT,//����Ĭ��Ϊ���ʱ̬
	//���� 
	TENSE_FUTURE,
	//Ҫȥ��
	TENSE_NONE
}Tense;

struct TrieNode
{
	struct TrieNode* children[53];//�ӽڵ�
	//��˵һ��TrieNode����128�����ӣ�NULL�Ĳ��У����ղ��Ǻö���(bushi
	struct TrieNode* failure;//ʧ��ָ��
	//���ָ��ʧ�ܺ��ȥ���ĵط�
	Tense tense;//��ǰʱ̬
	//ʱ̬���⣬�����Ҫ�δμ�¼�δε���
	int end;//�ؼ��ʽ�����־
	//������־�������ĩβ�ű��
};

struct TrieNode* create_node();
void insert_keyword(struct TrieNode* root,const char* word,Tense tense);
Tense detect_tense(struct TrieNode* root,char* input);
struct TrieNode* init_automation(); 
struct TrieNode* init_automation_2();
Tense tense(char* input,TrieNode* tree);
Tense already(char* input,TrieNode* tree);
int beidong(char* str);
void recursiveFunction(TrieNode* node);
 
#endif
