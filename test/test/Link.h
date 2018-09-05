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
};
#endif // LINK_H_