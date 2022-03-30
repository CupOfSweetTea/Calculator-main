#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


double** DMA_2(int z, int y) // Выделение памяти
{
	double** memo = (double**)malloc(z * sizeof(double*));
	for (int i = 0; i < z; ++i) {
		memo[i] = (double*)malloc(y * sizeof(double));
	}
	return memo;
}

void FDMA(double** mem, int n) // Очищение памяти
{
	for (int i = 0; i < n; i++)
		free(mem[i]);
	free(mem);
}

void print_matrix(double** x, int z, int y) // Вывод матрицы в консоль
{
	for (int i = 0; i < z; i++)
	{
		for (int j = 0; j < y; j++)
		{
			printf("%lg ", x[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void PrintOnScreenAns(double ans) // Вывод ответа в консоль
{
	printf("Answer = %lg\n\n", ans);
}

void Input_Array(double** x, int z, int y) //Ввод рандомной матрицы
{
	double arrMax = 20, arrMin = 0;
	for (int i = 0; i < z; i++)
		for (int j = 0; j < y; j++)
			x[i][j] = arrMin + (arrMax - arrMin) * ((double)rand() / RAND_MAX);
}

double Addition(double num1, double num2) //Сложение
{
	return num1 + num2;
}

double Subtraction(double num1, double num2) //Вычитание
{
	return num1 - num2;
}

double Multiplication(double num1, double num2) //Умножение
{
	return num1 * num2;
}

double Division(double num1, double num2) //Деление
{
	return num1 / num2;
}

double Exponentiation(double num1, double num2) //Возведение в степень
{
	return pow(num1, num2);;
}

void MatAddition(double** m, double** n, double** res, int z, int y) //Сложение матриц
{
	for (int i = 0; i < z; i++)
		for (int j = 0; j < y; j++)
			res[i][j] = m[i][j] + n[i][j];
}

void MatSubtraction(double** m, double** n, double** res, int z, int y) //Вычитание матриц
{
	for (int i = 0; i < z; i++)
		for (int j = 0; j < y; j++)
			res[i][j] = m[i][j] - n[i][j];
}

double MatDeterminant(double** a) //Определитель матрицы
{
	return a[0][0] * a[1][1] * a[2][2] + a[1][0] * a[2][1] * a[0][2] + a[0][1] * a[1][2] * a[2][0] - a[2][0] * a[1][1] * a[0][2] - a[2][1] * a[1][2] * a[0][0] - a[2][2] * a[1][0] * a[0][1];
}

int main() //Выбор функции
{
	srand(time(NULL));
	printf("Welcome to a simple calculator.\n\n");
	const int N = 3;
	int checkvar = 0, checkvar1 = 0, arr_X = 0, arr_Y = 0;
	double** m1 = NULL;
	double** m2 = NULL;
	double** m3 = NULL;
	double** m5 = NULL;
	double num1 = 0, num2 = 0, ans = 0;
	do
	{
		printf("What do you want to choose?\n\n 1 - Addition\n 2 - Subtraction\n 3 - Multiplication\n 4 - Division\n 5 - Exponentiation\n 6 - Matrix determinant (only 3x3)\n 7 - Operations with matrices\n 0 - Exit\n\n");
		scanf_s("%d", &checkvar);
		printf("\n");
		switch (checkvar)
		{
		case 0: break;

		case 1: printf("You have chosen: Addition.\n");
			printf("Enter first number: ");
			scanf_s("%lg", &num1);
			printf("Enter second number: ");
			scanf_s("%lg", &num2);
			ans = Addition(num1, num2);
			PrintOnScreenAns(ans);
			break;

		case 2:printf("You have chosen: Subtraction.\n");
			printf("Enter first number: ");
			scanf_s("%lg", &num1);
			printf("Enter second number: ");
			scanf_s("%lg", &num2);
			ans = Subtraction(num1, num2);
			PrintOnScreenAns(ans);
			break;

		case 3: printf("You have chosen: Multiplication.\n");
			printf("Enter first number: ");
			scanf_s("%lg", &num1);
			printf("Enter second number: ");
			scanf_s("%lg", &num2);
			ans = Multiplication(num1, num2);
			PrintOnScreenAns(ans);
			break;

		case 4: printf("You have chosen: Division.\n");
			printf("Enter first number: ");
			scanf_s("%lg", &num1);
			printf("Enter second number: ");
			scanf_s("%lg", &num2);
			if (num2 == 0)
				printf("\nCannot divide by zero!\n\n");
			else
			{
				ans = Division(num1, num2);
				PrintOnScreenAns(ans);
			}
			break;

		case 5: printf("You have chosen: Exponentiation.\n");
			printf("Enter first number: ");
			scanf_s("%lg", &num1);
			printf("Enter second number: ");
			scanf_s("%lg", &num2);
			ans = Exponentiation(num1, num2);
			PrintOnScreenAns(ans);
			break;

		case 6:	printf("You have chosen: Matrix Determinant 3x3.\n");
			m5 = DMA_2(N, N);
			Input_Array(m5, N, N);
			print_matrix(m5, N, N);
			printf("\n");
			ans = MatDeterminant(m5);
			PrintOnScreenAns(ans);
			FDMA(m5, N);
			break;

		case 7:
			do
			{
				printf("You have chosen: Operations with matrices.\n");
				printf("What do you want to choose?\n\n 1 - Addition of matrices\n 2 - Subtraction of matrices\n 0 - return\n\n");
				scanf_s("%d", &checkvar1);

				if (checkvar1 == 1 or checkvar1 == 2)
				{
					printf("Enter the size of the matrices\n");
					scanf_s("%d%d", &arr_X, &arr_Y);
					m1 = DMA_2(arr_X, arr_Y);
					m2 = DMA_2(arr_X, arr_Y);
					m3 = DMA_2(arr_X, arr_Y);
				}

				printf("\n");
				switch (checkvar1)
				{
				case 0: break;

				case 1:printf("You have chosen: Matrix addition %dx%d.\n", arr_X, arr_Y); //Сложение матриц
					printf("First Matrix:\n");
					Input_Array(m1, arr_X, arr_Y);
					print_matrix(m1, arr_X, arr_Y);
					printf("\nSecond Matrix:\n");
					Input_Array(m2, arr_X, arr_Y);
					print_matrix(m2, arr_X, arr_Y);
					printf("\nAnswer: \n");
					MatAddition(m1, m2, m3, arr_X, arr_Y);
					print_matrix(m3, arr_X, arr_Y);

					FDMA(m1, arr_X);
					FDMA(m2, arr_X);
					FDMA(m3, arr_X);
					break;

				case 2:printf("You have chosen: Matrix Subtraction %dx%d.\n", arr_X, arr_Y); //Вычитание матриц
					printf("First Matrix:\n");
					Input_Array(m1, arr_X, arr_Y);
					print_matrix(m1, arr_X, arr_Y);
					printf("\nSecond Matrix:\n");
					Input_Array(m2, arr_X, arr_Y);
					print_matrix(m2, arr_X, arr_Y);
					printf("\nAnswer: \n");
					MatSubtraction(m1, m2, m3, arr_X, arr_Y);
					print_matrix(m3, arr_X, arr_Y);
					FDMA(m1, arr_X);
					FDMA(m2, arr_X);
					FDMA(m3, arr_X);
					break;

				default: printf("Incorrect number!\n\n");
					break;
				}

			} while (checkvar1 != 0);
			break;

		default: printf("Incorrect number!\n\n");
			break;
		}

	} while (checkvar != 0);
	printf("Exiting...\n");

	return 0;
}
