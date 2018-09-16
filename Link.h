#pragma once
#ifndef LINK_H_
#define LINK_H_


#define ERROR 0
#define OK 1
#define MAXSIZE 20
typedef int Elemtype;
typedef int Status;
typedef struct
{
	Elemtype data[MAXSIZE];
	int length;
}SqList;

typedef struct Node
{
	Elemtype data;
	Node *next;
}Node;
typedef struct Node *LinkList;

typedef struct
{
	Elemtype data;
	int cur;
}component,StaticLinkList[MAXSIZE];

class SqLink
{
public:
	SqLink();
	~SqLink();
	Status GetElem(SqList L,int i,Elemtype *e);
	Status ListInsert(SqList *L, int i,Elemtype e);
	Status ListDelete(SqList *L, int i,Elemtype *e);
private:
};

class CnLink
{
public:
	CnLink();
	~CnLink();
	Status GetElem(LinkList L,int i,Elemtype *e);
	Status ListInsert(LinkList *L, int i, Elemtype e);
	Status ListDelete(LinkList *L, int i, Elemtype *e);
	void CreateListHead(LinkList *L, int n);
	void CreateListTail(LinkList *L, int n);
	Status ClearList(LinkList *L);
};

class StCnLink
{
public:
	StCnLink();
	~StCnLink();
	int ListLength(StaticLinkList space);
	Status InitList(StaticLinkList space);
	int Malloc_SLL(StaticLinkList space);
	Status ListInsert(StaticLinkList L, int i, Elemtype e);
	void Free_SSL(StaticLinkList space, int k);
	Status ListDelete(StaticLinkList L, int i);
};


typedef int SElemtype;
typedef struct
{
	SElemtype data[MAXSIZE];
	int top;
}SqStack;

class SqStackL
{
	SqStackL();
	~SqStackL();
public:
	Status Push(SqStack *S, SElemtype e);
	Status Pop(SqStack *S, SElemtype *e);
};

typedef struct
{
	SElemtype data[MAXSIZE];
	int top1;
	int top2;
}SqDoubleStack;

class SqTStack
{
	SqTStack();
	~SqTStack();
public:
	Status Push(SqDoubleStack *S, SElemtype e, int stackNumber);
	Status Pop(SqDoubleStack *S, SElemtype *e, int stackNumber);
};


typedef struct StackNode
{
	SElemtype data;
	struct StackNode *Next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;
	int count;
}LinkStack;

class linkStack
{
	linkStack();
	~linkStack();
	Status Push(LinkStack *S, SElemtype e);
	Status Pop(LinkStack *S, SElemtype *e);
};


typedef int QElemtype;
typedef struct
{
	QElemtype data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

class SqQueueC
{
	SqQueueC();
	~SqQueueC();
	Status InitQueue(SqQueue *Q);
	int QueueLength(SqQueue Q);
	Status EnQueue(SqQueue *Q, QElemtype e);
	Status DeQueue(SqQueue *Q, QElemtype *e);
};


typedef struct QNode
{
	QElemtype data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct
{
	QueuePtr front, rear;
}LinkQueue;

class LinkQueueC
{
	LinkQueueC();
	~LinkQueueC();
	Status EnQueue(LinkQueue *Q, QElemtype e);
	Status DeQueue(LinkQueue *Q, QElemtype *e);
};

/**
* @brief ���Ա���֮��������˳��洢�ṹ˫�ױ�ʾ��
* -<�������ɲ���>
* @author
* -���ĺ� 13390580649
*/

#define MAX_TREE_SIZE 100
typedef int TelemType;
typedef struct PTNode
{
	Elemtype data;
	int parent;
};
 
typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];
	int r, n;
}PTree
;

#endif // LINK_H_