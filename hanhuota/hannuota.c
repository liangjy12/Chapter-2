#include <stdio.h>
void hannuota(int n, int start, int goal, int temp);

void main()
{
	int n, start, goal, temp;
	scanf_s("%d%d%d%d", &n, &start, &goal, &temp);
	hannuota(n, start, goal, temp);
	system("pause");
	return;
}

void hannuota(int n, int start, int goal, int temp)
{
	if (n >= 1)
	{
		hannuota(n - 1, start, temp, goal);
		printf("move tower %d from %d to %d\n", n, start, goal);
		hannuota(n - 1, temp, goal, start);
	}
}