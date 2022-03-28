/*
Известные проблемы:

1) Хотел сделать по крутому с ручным вводом размеров матриц, но не работает, возможно проблема в передачи переменных, так что я без понятия,
поэтому DMA и FDMA не будут функциональны. В коде эти функции закомменчены :(

2) После тестирования без DMA и FDMA, вылезла другая проблема: Если отдельно запустить 6ю фунцию 1 раз и 7ю функцию по 1 разу - то всё гуд
Если же запустить что-то несколько раз (дважды запустить 6 (определитель)) то выдаст исключение... Что-то мне подсказывает что проблема в очитки кучи,
хотя всё делалось по примеру из презентации

3) микропроблема - не рандомно рандомит arr_X и arr_Y (как пример с остатком 5, генерит 3 и 4 соответсвенно. С остатком 10, генерит 8 и 9 соответсвенно. Эти значения постоянны)

Ну а так, если запускать операции с матрицами по 1 разу, то всё работает)))
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
void DMA(double** memo, int z, int y) // Выделение памяти
{
	int i = 0;
	double** memory = (double**)malloc(z * sizeof(double*));
	for (int i = 0; i < z; ++i) {
		memory[i] = (double*)malloc(y * sizeof(double));
	}
	memo = memory;
}

void FDMA(double** mem, int n) // Очищение памяти
{
	for (int i = 0; i < n; i++)
		free(mem[i]);
	free(mem);
}
*/
void print_matrix(double** x, int z, int y) // Вывод матрицы в консоль
{
	for (int i = 0; i < z; i++)
	{
		for (int j = 0; j < y; j++)
		{
			printf("%lg  ", x[i][j]);
		}
		printf("\n\n");
	}
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
	srand(NULL);
	printf("Welcome to a simple calculator.\n\n");
	const int N = 3;
	int checkvar = 0, checkvar1 = 0, arr_X = rand() % 5, arr_Y = rand() % 5;
	double** m1 = (double**)malloc(arr_X * sizeof(double*));
	for (int i = 0; i < arr_X; ++i) {
		m1[i] = (double*)malloc(arr_Y * sizeof(double));
	}
	double** m2 = (double**)malloc(arr_X * sizeof(double*));
	for (int i = 0; i < arr_X; ++i) {
		m2[i] = (double*)malloc(arr_Y * sizeof(double));
	}
	double** m3 = (double**)malloc(arr_X * sizeof(double*));
	for (int i = 0; i < arr_X; ++i) {
		m3[i] = (double*)malloc(arr_Y * sizeof(double));
	}
	double** m4 = (double**)malloc(N * sizeof(double*));
	for (int i = 0; i < N; ++i) {
		m4[i] = (double*)malloc(N * sizeof(double));
	}
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
			//DMA(m4, N, N);
			Input_Array(m4, N, N);
			print_matrix(m4, N, N);
			printf("\n");
			ans = MatDeterminant(m4);
			PrintOnScreenAns(ans);
			for (int i = 0; i < N; i++)
				free(m4[i]);
			free(m4);
			break;

		case 7:
			do
			{
				printf("You have chosen: Operations with matrices.\n");
				printf("What do you want to choose?\n\n 1 - Addition of matrices\n 2 - Subtraction of matrices\n 0 - return\n\n");
				scanf_s("%d", &checkvar1);

				//if (checkvar1 != 0)
				//{
				//	printf("Enter the size of the matrices\n");
				//	scanf_s("%d%d", &arr_X, &arr_Y);
				//	DMA(m1, arr_X, arr_Y);
				//	DMA(m2, arr_X, arr_Y);
				//	DMA(m3, arr_X, arr_Y);
				//}
				//printf("\n");
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
					for (int i = 0; i < arr_X; i++)
						free(m1[i]);
					free(m1);
					for (int i = 0; i < arr_X; i++)
						free(m2[i]);
					free(m2);
					for (int i = 0; i < arr_X; i++)
						free(m3[i]);
					free(m3);
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
					for (int i = 0; i < arr_X; i++)
						free(m1[i]);
					free(m1);
					for (int i = 0; i < arr_X; i++)
						free(m2[i]);
					free(m2);
					for (int i = 0; i < arr_X; i++)
						free(m3[i]);
					free(m3);
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