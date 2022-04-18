#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>


int print_in_file(int answer, double** x, int z, int y) {
    FILE* fptr;
    if ((fopen_s(&fptr, "Answer.txt", "a")) != NULL) {
        perror("Error");
        return 1;
    }
    if (answer == NULL) {
        for (int i = 0; i < z; i++)
        {
            for (int j = 0; j < y; j++)
            {
                fprintf(fptr, "%lg", x[i][j]);
            }
            fprintf(fptr, "\n");
        }
        fprintf(fptr, "\n\n\n");
    }
    else {
        fprintf(fptr, "%d\n\n\n", answer);
    }
    fclose(fptr);
    return 0;
}

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

void fadd(double num1, double num2, double ans, const char yep[], const char nope[], char save[], const int N) {
    printf("You have chosen: Addition.\n");
    printf("Enter first number: ");
    scanf_s("%lg", &num1);
    printf("Enter second number: ");
    scanf_s("%lg", &num2);
    ans = Addition(num1, num2);
    PrintOnScreenAns(ans);
    printf("Do you want save answer in file? (y - yes, n - no) ");
    scanf_s("%s", save, N);
    if (strcmp(save, yep) == 0) {
        print_in_file(ans, NULL, NULL, NULL);
    }
    else if (strcmp(save, nope) != 0) {
        printf("\nWrong character! You enter ( %s ), valid character: y - yes, n - no\n", save);
    }
}

void fsub(double num1, double num2, double ans, const char yep[], const char nope[], char save[], const int N) {
    printf("You have chosen: Subtraction.\n");
    printf("Enter first number: ");
    scanf_s("%lg", &num1);
    printf("Enter second number: ");
    scanf_s("%lg", &num2);
    ans = Subtraction(num1, num2);
    PrintOnScreenAns(ans);
    printf("Do you want save answer in file? (y - yes, n - no) ");
    scanf_s("%s", save, N);
    if (strcmp(save, yep) == 0) {
        print_in_file(ans, NULL, NULL, NULL);
    }
    else if (strcmp(save, nope) != 0) {
        printf("\nWrong character! You enter ( %s ), valid character: y - yes, n - no\n", save);
    }
}

void fmult(double num1, double num2, double ans, const char yep[], const char nope[], char save[], const int N) {
    printf("You have chosen: Multiplication.\n");
    printf("Enter first number: ");
    scanf_s("%lg", &num1);
    printf("Enter second number: ");
    scanf_s("%lg", &num2);
    ans = Multiplication(num1, num2);
    PrintOnScreenAns(ans);
    printf("Do you want save answer in file? (y - yes, n - no) ");
    scanf_s("%s", save, N);
    if (strcmp(save, yep) == 0) {
        print_in_file(ans, NULL, NULL, NULL);
    }
    else if (strcmp(save, nope) != 0) {
        printf("\nWrong character! You enter ( %s ), valid character: y - yes, n - no\n", save);
    }
}

void fdiv(double num1, double num2, double ans, const char yep[], const char nope[], char save[], const int N) {
    printf("You have chosen: Division.\n");
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
        printf("Do you want save answer in file? (y - yes, n - no) ");
        scanf_s("%s", save, N);
        if (strcmp(save, yep) == 0) {
            print_in_file(ans, NULL, NULL, NULL);
        }
        else if (strcmp(save, nope) != 0) {
            printf("\nWrong character! You enter ( %s ), valid character: y - yes, n - no\n", save);
        }
    }
}

void fexp(double num1, double num2, double ans, const char yep[], const char nope[], char save[], const int N) {
    printf("You have chosen: Exponentiation.\n");
    printf("Enter first number: ");
    scanf_s("%lg", &num1);
    printf("Enter second number: ");
    scanf_s("%lg", &num2);
    ans = Exponentiation(num1, num2);
    PrintOnScreenAns(ans);
    printf("Do you want save answer in file? (y - yes, n - no) ");
    scanf_s("%s", save, N);
    if (strcmp(save, yep) == 0) {
        print_in_file(ans, NULL, NULL, NULL);
    }
    else if (strcmp(save, nope) != 0) {
        printf("\nWrong character! You enter ( %s ), valid character: y - yes, n - no\n", save);
    }
}

void fmatdet(double** m5, double ans, const char yep[], const char nope[], char save[], const int N) {
    printf("You have chosen: Matrix Determinant 3x3.\n");
    m5 = DMA_2(N, N);
    Input_Array(m5, N, N);
    print_matrix(m5, N, N);
    printf("\n");
    ans = MatDeterminant(m5);
    PrintOnScreenAns(ans);
    printf("Do you want save answer in file? (y - yes, n - no): ");
    scanf_s("%s", save, N);
    if (strcmp(save, yep) == 0) {
        print_in_file(ans, NULL, NULL, NULL);
    }
    else if (strcmp(save, nope) != 0) {
        printf("\nWrong character! You enter ( %s ), valid character: y - yes, n - no\n", save);
    }
    FDMA(m5, N);
}

void fmatadd(double** m1, double** m2, double** m3, int arr_X, int arr_Y, const char yep[], const char nope[], char save[], const int N) {
    printf("You have chosen: Matrix addition %dx%d.\n", arr_X, arr_Y);
    printf("Enter the size of the matrices\n");
    scanf_s("%d%d", &arr_X, &arr_Y);
    m1 = DMA_2(arr_X, arr_Y);
    m2 = DMA_2(arr_X, arr_Y);
    m3 = DMA_2(arr_X, arr_Y);
    printf("First Matrix:\n");
    Input_Array(m1, arr_X, arr_Y);
    print_matrix(m1, arr_X, arr_Y);
    printf("\nSecond Matrix:\n");
    Input_Array(m2, arr_X, arr_Y);
    print_matrix(m2, arr_X, arr_Y);
    printf("\nAnswer: \n");
    MatAddition(m1, m2, m3, arr_X, arr_Y);
    print_matrix(m3, arr_X, arr_Y);
    printf("Do you want save answer in file? (y - yes, n - no): ");
    scanf_s("%s", save, N);
    printf("\n");
    if (strcmp(save, yep) == 0) {
        print_in_file(NULL, m3, arr_X, arr_Y);
    }
    else if (strcmp(save, nope) != 0) {
        printf("\nWrong character! You enter ( %s ), valid character: y - yes, n - no\n", save);
    }
    FDMA(m1, arr_X);
    FDMA(m2, arr_X);
    FDMA(m3, arr_X);
}

void fmatsub(double** m1, double** m2, double** m3, int arr_X, int arr_Y, const char yep[], const char nope[], char save[], const int N) {
    printf("You have chosen: Matrix Subtraction %dx%d.\n", arr_X, arr_Y);
    printf("Enter the size of the matrices\n");
    scanf_s("%d%d", &arr_X, &arr_Y);
    m1 = DMA_2(arr_X, arr_Y);
    m2 = DMA_2(arr_X, arr_Y);
    m3 = DMA_2(arr_X, arr_Y);
    printf("First Matrix:\n");
    Input_Array(m1, arr_X, arr_Y);
    print_matrix(m1, arr_X, arr_Y);
    printf("\nSecond Matrix:\n");
    Input_Array(m2, arr_X, arr_Y);
    print_matrix(m2, arr_X, arr_Y);
    printf("\nAnswer: \n");
    MatSubtraction(m1, m2, m3, arr_X, arr_Y);
    print_matrix(m3, arr_X, arr_Y);
    printf("Do you want save answer in file? (y - yes, n - no) ");
    scanf_s("%s", save, N);
    if (strcmp(save, yep) == 0) {
        print_in_file(NULL, m3, arr_X, arr_Y);
    }
    else if (strcmp(save, nope) != 0) {
        printf("\nWrong character! You enter ( %s ), valid character: y - yes, n - no\n", save);
    }
    FDMA(m1, arr_X);
    FDMA(m2, arr_X);
    FDMA(m3, arr_X);
}

int main() //Выбор функции
{
    srand(time(NULL));
    printf("Welcome to a simple calculator.\n\n");
    const int N = 3, Q = 8;
    char save[N] = "", cfunc[Q] = "";
    const char yep[N] = "y\0", nope[N] = "n\0", add[Q] = "add\0", sub[Q] = "sub\0", mult[Q] = "multi\0", div[Q] = "div\0", exp[Q] = "exp\0", matadd[Q] = "matadd\0", matsub[Q] = "matsub\0", matdet[Q] = "matdet\0", vecadd[Q] = "vecadd\0", vecsub[Q] = "vecsub\0", veclen[Q] = "veclen\0", exit[Q] = "exit\0";
    int checkvar = 1, arr_X = 0, arr_Y = 0;
    double** m1 = NULL;
    double** m2 = NULL;
    double** m3 = NULL;
    double** m5 = NULL;
    double num1 = 0, num2 = 0, ans = 0;

    struct Vector
    {
        double x;
        double y;
        double z;
    };

    do
    {
        printf("What do you want to choose?\n\n %s\t -\t Addition\n %s\t -\t Subtraction\n %s\t -\t Multiplication\n %s\t -\t Division\n %s\t -\t Exponentiation\n %s\t -\t Matrix determinant (only 3x3)\n %s\t -\t Matrix Addition\n %s\t -\t Matrix Subtraction\n %s\t -\t Vector addition\n %s\t -\t Vector subtraction\n %s\t -\t Vector lenght\n %s\t -\t Exit\n\n", add, sub, mult, div, exp, matdet, matadd, matsub, vecadd, vecsub, veclen, exit);
        scanf_s("%s", cfunc, Q);
        printf("\n");

        if (strcmp(cfunc, add) == 0) {
            fadd(num1, num2, ans, yep, nope, save, N);
        }
        else if (strcmp(cfunc, sub) == 0) {
            fsub(num1, num2, ans, yep, nope, save, N);
        }
        else if (strcmp(cfunc, mult) == 0) {
            fmult(num1, num2, ans, yep, nope, save, N);
        }
        else if (strcmp(cfunc, div) == 0) {
            fdiv(num1, num2, ans, yep, nope, save, N);
        }
        else if (strcmp(cfunc, exp) == 0) {
            fexp(num1, num2, ans, yep, nope, save, N);
        }
        else if (strcmp(cfunc, matdet) == 0) {
            fmatdet(m5, ans, yep, nope, save, N);
        }
        else if (strcmp(cfunc, matadd) == 0) {
            fmatadd(m1, m2, m3, arr_X, arr_Y, yep, nope, save, N);
        }
        else if (strcmp(cfunc, matsub) == 0) {
            fmatsub(m1, m2, m3, arr_X, arr_Y, yep, nope, save, N);
        }
        else if (strcmp(cfunc, vecadd) == 0) {
            printf("You have chosen: Vector addition.\n");
            struct Vector vector[2];

            for (int i = 0; i < 2; ++i)
            {
                printf("X: ");
                scanf_s("%lg", &vector[i].x);
                printf("Y: ");
                scanf_s("%lg", &vector[i].y);
                printf("Z: ");
                scanf_s("%lg", &vector[i].z);
                printf("\n");
            }
            printf("\nFirst vector:\t (%lg ; %lg ; %lg)\n", vector[0].x, vector[0].y, vector[0].z);
            printf("Second vector:\t (%lg ; %lg ; %lg)\n\n", vector[1].x, vector[1].y, vector[1].z);
            printf("Answer: (%lg ; %lg ; %lg)\n\n", vector[0].x + vector[1].x, vector[0].y + vector[1].y, vector[0].z + vector[1].z);
        }
        else if (strcmp(cfunc, vecsub) == 0) {
            printf("You have chosen: Vector subtraction.\n");
            struct Vector vector[2];

            for (int i = 0; i < 2; ++i)
            {
                printf("X: ");
                scanf_s("%lg", &vector[i].x);
                printf("Y: ");
                scanf_s("%lg", &vector[i].y);
                printf("Z: ");
                scanf_s("%lg", &vector[i].z);
                printf("\n");
            }
            printf("\nFirst vector:\t (%lg ; %lg ; %lg)\n", vector[0].x, vector[0].y, vector[0].z);
            printf("Second vector:\t (%lg ; %lg ; %lg)\n", vector[1].x, vector[1].y, vector[1].z);
            printf("Answer:\t (%lg ; %lg ; %lg)\n\n", vector[0].x - vector[1].x, vector[0].y - vector[1].y, vector[0].z - vector[1].z);
        }
        else if (strcmp(cfunc, veclen) == 0) {
            printf("You have chosen: Vector lenght.\n");
            struct Vector vector[1];
            printf("X: ");
            scanf_s("%lg", &vector[0].x);
            printf("Y: ");
            scanf_s("%lg", &vector[0].y);
            printf("Z: ");
            scanf_s("%lg", &vector[0].z);
            printf("\nFirst vector:\t (%lg ; %lg ; %lg)\n", vector[0].x, vector[0].y, vector[0].z);
            printf("Answer: %lg \n\n", sqrt(vector[0].x * vector[0].x + vector[0].y * vector[0].y + vector[0].z * vector[0].z));
        }
        else if (strcmp(cfunc, exit) == 1) {
            printf("Incorrect command! Correct commands: add sub multi div exp matdet matadd matsub exit \n\n");
        }
        else {
            checkvar = 0;
        }
    } while (checkvar != 0);
    printf("Exiting...\n");

    return 0;
}