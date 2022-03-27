#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

const int N = 3;

void print_matrix(double c[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%lg  ", c[i][j]);
		}
		printf("\n");
	}
}

void PrintOnScreenAns(double ans)
{
	printf("Answer = %lg\n\n", ans);
}

void Input_Array(double x[N][N])
{
	double *ptr;
		for (int i = 0; i < N; i++) //Ввод матрицы a
			for (int j = 0; j < N; j++)
				x[i][j] = rand() % 10;
		ptr = &x[N][N];
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


void MatAddition(double m[N][N], double n[N][N], double res[N][N])
{
  for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	  res[i][j] = m[i][j] + n[i][j];
}

void MatSubtraction(double m[N][N], double n[N][N], double res[N][N])
{
  for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	  res[i][j] = m[i][j] - n[i][j];
}

double MatDeterminant(double a[N][N]) //Определитель матрицы
{
	return a[0][0] * a[1][1] * a[2][2] + a[1][0] * a[2][1] * a[0][2] + a[0][1] * a[1][2] * a[2][0] - a[2][0] * a[1][1] * a[0][2] - a[2][1] * a[1][2] * a[0][0] - a[2][2] * a[1][0] * a[0][1];
}

int main() //Выбор функции
{
	srand(NULL);
	printf("Welcome to a simple calculator.\n\n");
	int checkvar = 0;
	double num1 = 0, num2 = 0, ans = 0, a[N][N] = {}, b[N][N] = {}, c[N][N] = {}, x[3][3] = {};
	do
	{
		printf("What do you want to choose?\n\n 1 - Addition\n 2 - Subtraction\n 3 - Multiplication\n 4 - Division\n 5 - Exponentiation\n 6 - Matrix addition %dx%d\n 7 - Matrix subtraction %dx%d\n 8 - Matrix determinant (only 3x3)\n 0 - Exit\n\n", N,N,N,N);
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
			
		case 6: printf("You have chosen: Matrix addition %dx%d.\n", N, N);
			printf("First Matrix:\n");
			Input_Array(a);
			print_matrix(a);
			printf("\nSecond Matrix:\n");
			Input_Array(b);
			print_matrix(b);
			printf("\nAnswer: \n");
			MatAddition(a, b, c);
			print_matrix(c);
			break;

		case 7: printf("You have chosen: Matrix Subtraction %dx%d.\n", N, N);
			printf("First Matrix:\n");
			Input_Array(a);
			print_matrix(a);
			printf("\nSecond Matrix:\n");
			Input_Array(b);
			print_matrix(b);
			printf("\nAnswer: \n");
			MatSubtraction(a, b, c);
			print_matrix(c);
			break;

		case 8: 
			printf("You have chosen: Matrix Determinant 3x3.\n");
			Input_Array(x);
			print_matrix(x);
			printf("\n");
			ans = MatDeterminant(x);
			PrintOnScreenAns(ans);
			break;

		default: printf("Wrong number!\n\n");
			break;
		}

	} while (checkvar != 0);
	printf("Exiting...\n");

	return 0;
}