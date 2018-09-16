#include "Link.h"
#include "Setting.h"

/**
* @brief 线性表函数之线性顺序存储结构
* -<详述，可不加>
* @author
* -李文浩 13390580649
*/

SqLink::SqLink()
{
}

SqLink::~SqLink()
{
}

Status SqLink::GetElem(SqList L, int i, Elemtype *e)
{
	if (L.length==0 || i<1 || i> MAXSIZE)
		return ERROR;
	*e = L.data[i-1];
	return OK;
}

Status SqLink::ListInsert(SqList *L, int i, Elemtype e)
{
	if (L->length == MAXSIZE)
		return ERROR;
	if (L->length == 0 || i<1 || i>L->length+1)
		return ERROR;
	if (i <= L->length)
	{
		for (int j = L->length - 1;j >= i - 1;j--)
		{
			L->data[j + 1] = L->data[j];
		}
	}
	L->data[i - 1] = e;
	L->length++;
	return OK;
}

Status SqLink::ListDelete(SqList *L, int i, Elemtype *e)
{
	if (L->length == 0 || i<1 || i>L->length)
		return ERROR;
	*e = L->data[i - 1];
	if (i < L->length)
	{
		for (int j = i - 1; j < L->length-1;j++)
			L->data[j] = L->data[j + 1];
	}
	L->length--;
	return OK;
}

/**
* @brief 线性表函数之线性单链表存储结构
* -<详述，可不加>
* @author
* -李文浩 13390580649
*/
CnLink::CnLink()
{
}

CnLink::~CnLink()
{
}

Status CnLink::GetElem(LinkList L, int i, Elemtype *e)
{
	if (i < 0)
		return ERROR;
	LinkList s;
	int j;
	s = L->next;
	if (s)
	{
		for ( j= 1;j < i;j++)
			s = s->next;
	}
	if (!s || j > i)
		return ERROR;
	*e = s->data;
	return OK;
}

Status CnLink::ListInsert(LinkList *L, int i, Elemtype e)
{
	if (i < 0)
		return ERROR;
	LinkList s,q;
	s = *L;
	int j = 1;
	if(s)
	{
		for (;j < i;j++)
			s = s->next;
	}
	if (!s || j > i)
		return ERROR;
	q = (LinkList)malloc(sizeof(Node));
	q->next = s->next;
	s->next = q;
	q->data = e;
	return OK;
}

Status CnLink::ListDelete(LinkList *L, int i, Elemtype *e)
{
	if (i < 0)
		return ERROR;
	LinkList p, q;
	p = (*L);
	int j = 1;
	if (p)
	{
		for (;j < i;j++)
			p = p->next;
	}
	if (!p || j > i)
		return ERROR;
	p->next = q;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}

void CnLink::CreateListHead(LinkList *L, int n)
{
	LinkList p;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for (i=0;i < n;i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

void CnLink::CreateListTail(LinkList *L, int n)
{
	LinkList p,r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for (i = 0;i < n;i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}


/**
* @brief 线性表函数之线性静态链表存储结构
* -<详述，可不加>
* @author
* -李文浩 13390580649
*/
StCnLink::StCnLink()
{
}
StCnLink::~StCnLink()
{
}

int StCnLink::ListLength(StaticLinkList space)
{
	int j = 1;
	int i=space[0].cur;
	while (i)
	{
		i = space[i].cur;
		j++;
	}
	return j;
}

Status StCnLink::InitList(StaticLinkList space)
{
	int i;
	for (i = 0;i < MAXSIZE - 1;i++)
	{
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0;
	return OK;
}

int StCnLink::Malloc_SLL(StaticLinkList space)
{
	int i = space[0].cur;
	if(space[0].cur)
	space[0].cur = space[i].cur;
	return i;
}

Status StCnLink::ListInsert(StaticLinkList L, int i, Elemtype e)
{
	int j;
	if (i<0 || i>ListLength(L)+1)
		return ERROR;
	int p = Malloc_SLL(L);
	int s = MAXSIZE-1;
	if (p)
	{
		for (j = 1;j < i;j++)
		s = L[s].cur;
		L[p].cur = L[s].cur;
		L[p].data = e;
		L[s].cur = p;
		return OK;
	}
	
	return ERROR;
}

void StCnLink::Free_SSL(StaticLinkList space, int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

Status StCnLink::ListDelete(StaticLinkList L, int i)
{
	int  j,k;
	if (i<0 || i>ListLength(L))
		return ERROR;
	k = MAXSIZE - 1;
	for (j = 1;j < i;j++)
		k = L[k].cur;
	int p = L[k].cur;
	L[k].cur = L[p].cur;
	Free_SSL(L,i);
	return OK;
}

/**
* @brief 线性表函数之---栈-线性顺序存储结构
* -<详述，可不加>
* @author
* -李文浩 13390580649
*/

SqStackL::SqStackL()
{
}
SqStackL::~SqStackL()
{
}

Status SqStackL::Push(SqStack *S, SElemtype e)
{
	if (S->top == MAXSIZE - 1)
		return ERROR;
	S->top++;
	S->data[S->top] = e;
	return OK;
}

Status SqStackL::Pop(SqStack *S, SElemtype *e)
{
	if (S->top == -1)   // 一个数也可以的
		return ERROR;
	e = &S->data[S->top];
	S->top--;
	return ERROR;
}

/**
* @brief 线性表函数之---双栈共享空间-线性顺序存储结构
* -<详述，可不加>
* @author
* -李文浩 13390580649
*/
SqTStack::SqTStack()
{
}
SqTStack::~SqTStack()
{
}

Status SqTStack::Push(SqDoubleStack *S, SElemtype e, int stackNumber)
{
	if (S->top1 + 1 == S->top2)
		return ERROR;
	if (stackNumber == 1)
		S->data[++S->top1] = e;
	if (stackNumber == 2)
		S->data[--S->top2] = e;
	return OK;
}

Status SqTStack::Pop(SqDoubleStack *S, SElemtype *e, int stackNumber)
{
	if (stackNumber == 1)
	{
		if (S->top1 == -1)
			return ERROR;
		*e = S->data[S->top1--];
	}
	else if (stackNumber == 2)
	{
		if (S->top2 == MAXSIZE)
			return ERROR;
		*e = S->data[S->top2++];
	}
	return OK;
}


/**
* @brief 线性表函数之---栈的链式存储结构
* -<详述，可不加>
* @author
* -李文浩 13390580649
*/

linkStack::linkStack()
{
}
linkStack::~linkStack()
{
}

Status linkStack::Push(LinkStack *S, SElemtype e)
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s->data = e;
	s->Next = S->top;
	S->top = s;
	S->count++;
	return OK;
}

Status linkStack::Pop(LinkStack *S, SElemtype *e)
{
	LinkStackPtr p;
	if (StackEmpty(*S))
		return ERROR;
	*e = S->top->data;
	p = S->top;
	S->top = S->top->Next;
	free(p);
	S->count--;
	return OK;
}

/**
* @brief 线性表函数之---栈的应用之斐波那列
* -<详述，可不加>
* @author
* -李文浩 13390580649
*/

int Fbi(int i)
{
	if (i < 2)
		return i == 0 ? 0 : 1;
	return Fbi(i - 1) + Fbi(i - 2);
}

/**
* @brief 线性表函数之---循环队列的顺序存储结构
* -<详述，可不加>
* @author
* -李文浩 13390580649
*/

Status SqQueueC::InitQueue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

int SqQueueC::QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE);
}

Status SqQueueC::EnQueue(SqQueue *Q, QElemtype e)
{
	if ((Q->rear + 1) == Q->front)
		return ERROR;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear+1)%MAXSIZE;
	return OK;
}

Status SqQueueC::DeQueue(SqQueue *Q, QElemtype *e)
{
	if (Q->rear == Q->front)
		return ERROR;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return OK;
}

/**
* @brief 线性表函数之---循环队列的链式存储结构
* -<详述，可不加>
* @author
* -李文浩 13390580649
*/
LinkQueueC::LinkQueueC()
{
}

LinkQueueC::~LinkQueueC()
{
}

Status LinkQueueC::EnQueue(LinkQueue *Q, QElemtype e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if (!s)
		exit(OVERFLOW);
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
	return OK;
}

Status LinkQueueC::DeQueue(LinkQueue *Q, QElemtype *e)
{
	QueuePtr P;
	if (Q->front == Q->rear)
		return ERROR;
	P = Q->front->next;
	*e = P->data;
	Q->front->next = P->next;
	if (Q->rear == P)
		Q->rear = Q->front;
	free(P);
	return ERROR;
}

/**
* @brief 线性表函数之---串之朴素的模式匹配算法
* -<详述，可不加>
* @author
* -李文浩 13390580649
*/

int Index(std::string S, std::string T, int pos)
{
	int i = pos;
	int j = 1;
	while (i <= S[0] && j <= T[0])
	{
		if (S[i] == T[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}

/**
* @brief 线性表函数之---串之KMP模式匹配算法
* -<详述，可不加>
* @author
* -李文浩 13390580649
*/

void get_next(std::string T, int *next)
{
	int i, j;
	i = 1;
	j = 0;
	next[1] = 0;
	while (i < T[0])
	{
		if (j == 0 || T[i] == T[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}