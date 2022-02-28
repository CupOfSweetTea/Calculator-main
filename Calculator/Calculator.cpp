#include <stdio.h>
#include <math.h>

#define N 3


void Addition() //Сложение
{
	double num1, num2, ans;
	printf("You have chosen: Addition.\n");
	printf("Enter first number: ");
	scanf_s("%lg", &num1);
	printf("Enter second number: ");
	scanf_s("%lg", &num2);
	ans = num1 + num2;
	printf("\n%lg + %lg = %lg \n\n", num1, num2, ans);
}

void Subtraction() //Вычитание
{
	double num1, num2, ans;
	printf("You have chosen: Subtraction.\n");
	printf("Enter first number: ");
	scanf_s("%lg", &num1);
	printf("Enter second number: ");
	scanf_s("%lg", &num2);
	ans = num1 - num2;
	printf("\n%lg - %lg = %lg \n\n", num1, num2, ans);
}

void Multiplication() //Умножение
{
	double num1, num2, ans;
	printf("You have chosen: Multiplication.\n");
	printf("Enter first number: ");
	scanf_s("%lg", &num1);
	printf("Enter second number: ");
	scanf_s("%lg", &num2);
	ans = num1 * num2;
	printf("\n%lg * %lg = %lg \n\n", num1, num2, ans);
}

void Division() //Деление
{
	double num1, num2, ans;
	printf("You have chosen: Division.\n");
	printf("Enter first number: ");
	scanf_s("%lg", &num1);
	printf("Enter second number: ");
	scanf_s("%lg", &num2);
	if (num2 == 0)
		printf("\nCannot divide by zero!\n\n");
	else
	{
		ans = num1 / num2;
		printf("\n%lg / %lg = %lg \n\n", num1, num2, ans);
	}
}

void Exponentiation() //Возведение в степень
{
	double num1, num2, ans;
	printf("You have chosen: Exponentiation.\n");
	printf("Enter first number: ");
	scanf_s("%lg", &num1);
	printf("Enter second number: ");
	scanf_s("%lg", &num2);
	ans = pow(num1, num2);
	printf("\n%lg^%lg = %lg \n\n", num1, num2, ans);
}

void MatAddition() //Сложение матриц
{
	double a[N][N] = {}, b[N][N] = {}, c[N][N] = {};
	printf("You have chosen: Matrix addition %dx%d.\n", N, N);
	printf("Enter first Matrix:\n");
	
	for (int i = 0; i < N; i++) //Ввод матрицы
	{
		for (int j = 0; j < N; j++)
		{
			printf("a[%d][%d]=", i, j);
			scanf_s("%lg", &a[i][j]);
		}
	}

	printf("\nEnter second Matrix:\n");

	for (int i = 0; i < N; i++) //Ввод матрицы
	{
		for (int j = 0; j < N; j++)
		{
			printf("a[%d][%d]=", i, j);
			scanf_s("%lg", &b[i][j]);
		}
	}

	printf("\nAnswer:\n");
	for (int i = 0; i < N; i++) //Вывод матрицы
	{
		for (int j = 0; j < N; j++)
		{
			printf("%lg ", c[i][j] = a[i][j] + b[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void MatSubtraction() //Вычитание матриц
{
	double a[N][N] = {}, b[N][N] = {}, c[N][N] = {};
	printf("You have chosen: Matrix Subtraction %dx%d.\n", N, N);
	printf("Enter first Matrix:\n");

	for (int i = 0; i < N; i++) //Ввод матрицы
	{
		for (int j = 0; j < N; j++)
		{
			printf("a[%d][%d]=", i, j);
			scanf_s("%lg", &a[i][j]);
		}
	}

	printf("\nEnter second Matrix:\n");

	for (int i = 0; i < N; i++) //Ввод матрицы
	{
		for (int j = 0; j < N; j++)
		{
			printf("a[%d][%d]=", i, j);
			scanf_s("%lg", &b[i][j]);
		}
	}

	printf("\nAnswer:\n");
	for (int i = 0; i < N; i++) //Вывод матрицы
	{
		for (int j = 0; j < N; j++)
		{
			printf("%lg ", c[i][j] = a[i][j] - b[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void MatDeterminant() //Определитель матрицы
{
	double ans = 0;
	double a[N][N] = {};
	printf("You have chosen: Matrix determinant %dx%d.\n", N, N);
	printf("Enter Matrix:\n");

	for (int i = 0; i < N; i++) //Ввод матрицы
	{
		for (int j = 0; j < N; j++)
		{
			printf("a[%d][%d]=", i, j);
			scanf_s("%lg", &a[i][j]);
		}
	}

	ans = a[0][0] * a[1][1] * a[2][2] + a[1][0] * a[2][1] * a[0][2] + a[0][1] * a[1][2] * a[2][0] - a[2][0] * a[1][1] * a[0][2] - a[2][1] * a[1][2] * a[0][0] - a[2][2] * a[1][0] * a[0][1]; //Без понятия как можно сократить, мб есть <Название.h> для этого

	printf("\nDeterminant = %lg\n\n", ans);
}

int main() //Выбор функции
{
	printf("Welcome to a simple calculator.\n\n");
	int checkvar = 0;

	do
	{
		printf("What do you want to choose?\n\n 1 - Addition\n 2 - Subtraction\n 3 - Multiplication\n 4 - Division\n 5 - Exponentiation\n 6 - Matrix addition 3x3\n 7 - Matrix subtraction 3x3\n 8 - Matrix determinant 3x3\n 0 - Exit\n\n");
		scanf_s("%d", &checkvar);
		printf("\n");
		switch (checkvar)
		{
		case 0: break;

		case 1: Addition();
				break;

		case 2: Subtraction();
				break;

		case 3: Multiplication();
				break;

		case 4: Division();
				break;

		case 5: Exponentiation();
				break;

		case 6: MatAddition();
				break;

		case 7: MatSubtraction();
				break;

		case 8: MatDeterminant();
				break;

		default: printf("Wrong number!\n\n");
				break;
		}

	} while (checkvar != 0);
	printf("Exiting...\n");

	return 0;
}