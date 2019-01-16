#include<stdio.h>
typedef int ElementType;
typedef struct SNode *PtrToSNode;
struct SNode
{
	ElementType Data;
	PtrToSNode Next;
};
typedef PtrToSNode stack;
typedef enum{false,true}bool;
stack createstack();
bool isempty(stack S);
bool spush(stack S, ElementType x);
ElementType spop(stack S);
void main()
{
	stack s;
	ElementType x;
	s = createstack();
	spush(s, 10);
	x = spop(s);
	system("pause");
	return;
}

stack createstack()
{
	stack S;
	S = (stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
}

bool isempty(stack S)
{
	return (S->Next == NULL);
}
bool spush(stack S, ElementType x)
{
	stack tempcell;
	tempcell = (stack)malloc(sizeof(struct SNode));
	tempcell->Data = x;
	tempcell->Next = S->Next;
	S->Next = tempcell;
	return true;
}
ElementType spop(stack S)
{
	if (isempty(S))
	{
		printf("The stack is empty!");
		return false;
	}
	else
	{
		stack firstcell;
		ElementType topelement;
		firstcell = S->Next;
		topelement = firstcell->Data;
		S->Next = firstcell->Next;
		free(firstcell);
		return topelement;
	}
}