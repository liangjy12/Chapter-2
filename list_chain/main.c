#include <stdio.h>

typedef int ElementType;
typedef enum{false,true}bool;
typedef struct LNode *PtrToLNode;
struct LNode
{
	ElementType Data;
	PtrToLNode Next;
};

typedef PtrToLNode Position;
typedef PtrToLNode List;

void main()
{
	List L, pnew, tail;
	int i;
	L = (List)malloc(sizeof(struct LNode));
	tail = L;
	for (i = 0; i < 5; i++)
	{
		pnew = (List)malloc(sizeof(struct LNode));
		pnew->Next = NULL;
		pnew->Data = i;
		tail->Next = pnew;
		tail = pnew;
	}
}

//²éÕÒ
#define ERROR NULL
Position findX(List L, ElementType X)
{
	Position p = L;
	while (p&&p->Data != X) p = p->Next;
	if (p) return p;
	else return ERROR;
}

//²åÈë
bool insertX(List L, ElementType X, Position p)
{
	Position pre, tmp;
	for (pre = L; pre&&pre->Next != p; pre = pre->Next);
	if (pre == NULL)
	{
		printf("Position p is wrong.");
		return false;
	}
	else
	{
		tmp = (Position)malloc(sizeof(struct LNode));
		tmp->Data = X;
		tmp->Next = p;
		pre->Next = tmp;
		return true;
	}
}

bool deletep(List L, Position p)
{
	Position pre, tmp;
	for (pre = L; pre&&pre->Next != p; pre = pre->Next);
	if (pre == NULL || p==NULL)
	{
		printf("Position p is wrong.");
		return false;
	}
	else
	{
		pre->Next = p->Next;
		free(p);
		return true;
	}
}