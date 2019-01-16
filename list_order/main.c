#include <stdio.h>
#define MAXSIZE 5
#define ERROR -1

typedef int Position;
typedef int ElementType;
typedef enum{false,true}bool;

typedef struct LNode *List;
struct LNode
{
	ElementType Data[MAXSIZE];
	Position Last;
};

List makelist();
Position findX(List L, ElementType X);
bool insertP(List L, ElementType X, Position p);
bool deleteP(List L, Position p);

void main()
{
	List L1, L2;
	int i;
	L1 = makelist();
	L2 = makelist();
	for (i = 0; i < 5; i++)
	{
		L2->Data[i] = i + 1;
		L2->Last = i;
	}
	findX(L2, 3);
	insertP(L2, 6, 4);
	deleteP(L2, 1);
	return;
}

//创建空表
List makelist()
{
	List L;
	L = (List)malloc(sizeof(struct LNode));
	L->Last = -1;
	return L;
}

//查找元素X
Position findX(List L, ElementType X)
{
	Position i = 0;
	while (i <= L->Last&&L->Data[i] != X) i++;
	if (i > L->Last) return ERROR;
	else return i;
}

//插入元素X
bool insertP(List L, ElementType X, Position p)
{
	Position i;
	if (L->Last == MAXSIZE - 1)
	{
		printf("L is FULL.");
		return false;
	}
	if (p<0 || p>L->Last + 1)
	{
		printf("P is a wrong position");
		return false;
	}
	for (i = L->Last; i >= p; i--) L->Data[i + 1] = L->Data[i];
	L->Data[p] = X;
	L->Last++;
	return true;
}

//删除元素第p个元素
bool deleteP(List L, Position p)
{
	Position i;
	if (p<0 || p>L->Last)
	{
		printf("P is a wrong position.");
		return false;
	}
	for (i = p + 1; i <= L->Last; i++) L->Data[i - 1] = L->Data[i];
	L->Last--;
	return true;
}