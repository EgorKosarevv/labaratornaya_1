#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int main()
{
	double d = 0;
	long int min, max;
	long int c;
	long int n;
	double* mas;
	int* masdrob;
	double sum = 0;
	int i = 0;
	int j = 0;
	srand(time(NULL));
	setlocale(0, "rus");
	printf("Введите размер массива: ");
	scanf_s("%d", &n);
	printf("Введите минимальное значение: ");
	scanf_s("%d", &min);
	printf("Введите максимальное значение: ");
	scanf_s("%d", &max);
	if (n <= 0)
	{
		printf("Введите корректные данные");
		return 0;
	}
	if (min > max)
	{
		c = max;
		max = min;
		min = c;
	}
	mas = malloc(n * sizeof(double));
	masdrob = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		double d = (min + (max - min) * (double)rand() / RAND_MAX);
		mas[i] = d;
		masdrob[i] = ((mas[i] - (int)mas[i]) * 1000000);
	}
	printf("Полученная сумма равна = ");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == masdrob[j])
			{
				sum = sum - mas[i];
				masdrob[j] = 0.0;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		sum = sum + mas[i];

	}
	printf("%lf", sum);
	free(mas);
	free(masdrob);
	return 0;
}