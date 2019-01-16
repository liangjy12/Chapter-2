#include<stdio.h>

typedef int position;
typedef int ElementType;
typedef struct SNode *stack;
struct SNode
{
	ElementType *Data;
	position top;
	int maxsize;
};

typedef enum{ true,false }bool;

stack createstack(int maxsize);
bool isFull(stack s);
bool isEmpty(stack s);
bool spush(stack s, ElementType x);
ElementType spop(stack s);

void main()
{
	stack s = createstack(2);
	spush(s, 2);
	spush(s, 3);
	spush(s, 4);
	printf("%d",spop(s));
	printf("%d", spop(s));
	printf("%d",spop(s));
	return;
}

stack createstack(int maxsize)
{
	stack s = (stack)malloc(sizeof(struct SNode));
	s->Data = (ElementType *)malloc(maxsize * sizeof(ElementType));
	s->maxsize = maxsize;
	s->top = -1;
	return s;
}

bool isFull(stack s)
{
	return (s->top == s->maxsize - 1);
}

bool isEmpty(stack s)
{
	return (s->top == -1);
}

bool spush(stack s, ElementType x)
{
	if (isFull(s)) return false;
	else
	{
		s->Data[++(s->top)] = x;
		return true;
	}
}

ElementType spop(stack s)
{
	if (isEmpty(s)) return 0;
	else
	{
		return (s->Data[(s->top)--]);
	}
}