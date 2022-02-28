#include <stdio.h>
#include <math.h>


int main()
{
	printf("Welcome to a simple calculator.\n\n");
	int checkvar = 0;
	double num1, num2, ans;

	do
	{
		printf("What do you want to choose?\n\n 1 - Addition\n 2 - Subtraction\n 3 - Multiplication\n 4 - Division\n 5 - Exponentiation\n 0 - Exit\n\n");
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
			ans = num1 + num2;
			printf("\n%lg + %lg = %lg \n\n", num1, num2, ans);
			break;

		case 2: printf("You have chosen: Subtraction.\n");
			printf("Enter first number: ");
			scanf_s("%lg", &num1);
			printf("Enter second number: ");
			scanf_s("%lg", &num2);
			ans = num1 - num2;
			printf("\n%lg - %lg = %lg \n\n", num1, num2, ans);
			break;

		case 3: printf("You have chosen: Multiplication.\n");
			printf("Enter first number: ");
			scanf_s("%lg", &num1);
			printf("Enter second number: ");
			scanf_s("%lg", &num2);
			ans = num1 * num2;
			printf("\n%lg * %lg = %lg \n\n", num1, num2, ans);
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
				ans = num1 / num2;
				printf("\n%lg / %lg = %lg \n\n", num1, num2, ans);
			}
			break;

		case 5: printf("You have chosen: Exponentiation.\n");
			printf("Enter first number: ");
			scanf_s("%lg", &num1);
			printf("Enter second number: ");
			scanf_s("%lg", &num2);
			ans = pow(num1, num2);
			printf("\n%lg^%lg = %lg \n\n", num1, num2, ans);
			break;

		default: printf("Wrong number!\n\n");
			break;
		}
	} while (checkvar != 0);
	printf("Exiting...\n");

	return 0;
}