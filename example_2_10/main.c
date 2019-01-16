#include <stdio.h>
#define ElementType int
void swap(ElementType *x, ElementType *y);
ElementType FindKthLarge(ElementType S[], int K, int left, int right);

void main()
{
	int S[5], N,median,i;
	scanf_s("%d", &N);
	for (i = 0; i < N; i++) scanf_s("%d", S + i);
	median = FindKthLarge(S, (N + 1) / 2, 0, N - 1);
	printf("%d", median);
	return;
}

void swap(ElementType *x, ElementType *y)
{
	ElementType temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

ElementType FindKthLarge(ElementType S[], int K, int left, int right)
{
	ElementType e = S[left];
	int L = left, R = right;

	while (1)
	{
		while ((left <= right) && (e <= S[left])) left++;
		while ((left < right) && (e > S[right])) right--;
		if (left < right) swap(&S[left], &S[right]);
		else break;
	}
	swap(&S[left - 1], &S[L]);
	if ((left - L - 1) >= K) return FindKthLarge(S, K, L, left - 2);
	else if ((left - L - 1) < K - 1) return FindKthLarge(S, K - (left - L - 1) - 1, left, R);
	else return e;
}