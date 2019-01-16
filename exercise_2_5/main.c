#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

//List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main()
{
	List L1, L2, L;
//	L1 = Read();
//	L2 = Read();

	L = Merge(L1, L2);
	Print(L);
	Print(L1);
	Print(L2);
	return 0;
}

List Merge(List L1, List L2)
{
	if (!L1 && !L2) return NULL;
	List L, temp, temp1, temp2;
	L = (PtrToNode)malloc(sizeof(struct Node));
	temp1 = L1->Next;
	temp2 = L2->Next;
	temp = L;
	while (temp1 && temp2)
	{
		if (temp1->Data >= temp2->Data)
		{
			temp->Next = temp2;
			temp2 = temp2->Next;
		}
		else
		{
			temp->Next = temp1;
			temp1 = temp1->Next;
		}
	}
	if (temp1) temp->Next = temp1;
	else if (temp2) temp->Next = temp2;
	L1->Next = NULL;
	L2->Next = NULL;
	return L;
}

void Print(List L)
{
	if (L->Next == NULL)
	{
		printf("NULL\n");
		return;
	}
	L = L->Next;
	while (L!=NULL)
	{
		printf("%d ", L->Data);
		L = L->Next;
	}
	printf("\n");
	return;
}