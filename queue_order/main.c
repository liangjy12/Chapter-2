#include<stdio.h>
typedef int position;
typedef int ElementType;
typedef enum{false,true} bool;
typedef struct QNode *queue;
struct QNode
{
	ElementType *Data;
	position front, rear;
	int Maxsize;
};
queue createqueue(int Maxsize);
bool isfull(queue q);
bool isempty(queue q);
bool addq(queue q, ElementType x);
ElementType deleteq(queue q);
void main()
{
	queue q = createqueue(3);
	isempty(q);
	addq(q, 4);
	addq(q, 5);
	printf("%d",deleteq(q));
	addq(q, 6);
	printf("%d", q->Data[1]);
	system("pause");
	return;
}

queue createqueue(int Maxsize)
{
	queue q = (queue)malloc(sizeof(struct QNode));
	q->Data = (ElementType)malloc(Maxsize * sizeof(ElementType));
	q->front = q->rear = 0;
	q->Maxsize = Maxsize;
	return q;
}
bool isfull(queue q)
{
	return((q->rear + 1) % q->Maxsize == q->front);
}
bool isempty(queue q)
{
	return(q->front == q->rear);
}
bool addq(queue q, ElementType x)
{
	if (isfull(q))
	{
		printf("The queue is full!");
		return false;
	}
	else
	{
		q->rear = (q->rear + 1) % q->Maxsize;
		q->Data[q->rear] = x;
		return true;
	}
}
ElementType deleteq(queue q)
{
	if (isempty(q))
	{
		printf("The queue is empty!");
		return false;
	}
	else
	{
		q->front = (q->front + 1) % q->Maxsize;
		return q->Data[q->front];
	}
}