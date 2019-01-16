#include"myfunction.h"
#define N 1000
void store_array()
{
	int i, j, coef, inde, cnt1=0,cnt2=0;
	int n1 = 0, n2 = 0;
	int a1[N] = { 0 };
	int a2[N] = { 0 };
	int asum[N] = { 0 };
	int apro[N*2] = { 0 };
	scanf_s("%d", &n1);
	for (i = 0; i < n1; i++)
	{
		scanf_s("%d %d", &coef, &inde);
		a1[inde] = coef;
	}
	scanf_s("%d", &n2);
	for (i = 0; i < n2; i++)
	{
		scanf_s("%d %d", &coef, &inde);
		a2[inde] = coef;
	}

	for (i = N - 1; i >= 0; i--)
	{
		if (a1[i])
		{
			for (j = N - 1; j >= 0; j--)
			{
				if (a2[j]) apro[i + j] += a1[i] * a2[j];
			}
		}
	}

	for (i = N * 2 - 1; i >= 0; i--)
	{
		if (apro[i])
		{
			if (cnt1) printf(" ");
			printf("%d %d", apro[i], i);
			cnt1++;
		}
	}
	if (!cnt1) printf("0 0");

	printf("\n");

	for (i = N-1; i >= 0; i--)
	{
		asum[i] = a1[i] + a2[i];
		if (asum[i])
		{
			if (cnt2) printf(" ");
			printf("%d %d", asum[i], i);
			cnt2++;
		}
	}
	if (!cnt2) printf("0 0");
	return;
}