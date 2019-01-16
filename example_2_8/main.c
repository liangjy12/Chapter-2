#include <stdio.h>

int factorial(int N);

void main()
{
	int N, fac;
	scanf_s("%d", &N);
	fac = factorial(N);
	printf("%d", fac);
	return;
}

int factorial(int N)
{
	if (N == 1)	return 1;
	else return	N * factorial(N - 1);
}
