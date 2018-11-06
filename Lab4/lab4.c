#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

int main()
{
	int array[100];
	int array1[5];
	int n, k, k1, el1, el2;
	int button, button1;
	int count = 0, count1 = 0;

	printf("Enter the number of array elements, please:\n");
	scanf("%d", &n);

	if (n <= 0)
	{
		printf("Retry\n");
		scanf("%d", &n);
	}

	printf("Enter array of integer digit elements, please:\n");
	for (int i = 0; i < n; i++)
	{
		printf("array[%d] = ", i);
		scanf("%d", &array[i]);
	}

	printf("1 - to walk through the array to the right\n");
	printf("2 - to walk through the array to the left\n");
	printf("3 - to walk through the array step by step\n");
	printf("4 - to walk through the array from K to K - 1 and create new array\n");
	printf("0 - quit\n");
	
	scanf("%d", &button);

	while (button != 0)
	{
		while (button > 4 || button < 1)
		{
			printf("Retry:\n");
			scanf("%d", &button);
		}

		if (button == 1)
		{
			for (int i = 0; i < n; i++)
			{
				printf("%d ", *(array + i));
			}

			printf("\n");
		}

		else if (button == 2)
		{
			for (int i = (n - 1); i >= 0; i--)
			{
				printf("%d ", *(array + i));
			}

			printf("\n");
		}

		else if (button == 3)
		{
			printf("array[%d] is %d ", count, *(array + count));
			count++;

			if (count > n - 1)
			{
				count = 0;
			}

			printf("\n");
		}

		else
		{
			printf("Enter the value for K from 0 to %d:\n", n - 1);
			scanf("%d", &k);

			while (k < 0 || k > n)
			{
				printf("Retry:\n");
				scanf("%d", &k);
			}

			for (int i = k, j = 1; i <= k && i >= k - 1; i--, j++)
			{
				if (*(array + i) == *(array))
				{
					*(array + i - 1) = *(array + (n - 1));
				}

				array1[j] = array[i];
				printf("%d ", *(array + i));
				count1++;
			}

			printf("\n");

			printf("1 - add first and last element in new array and walk from K to K + 1\n");
			printf("0 - quit\n");

			scanf("%d", &button1);

			while (button1 != 0)
			{
				if (button1 == 1)
				{
					printf("Enter the first element:\n");
					scanf("%d", &el1);

					printf("Enter the second element:\n");
					scanf("%d", &el2);

					*array1 = el1;
					*(array1 + count1 + 1) = el2;

					printf("New array is:\n");

					for (int i = 0; i < count1 + 2; i++)
					{
						printf("%d ", *(array1 + i));
					}

					printf("\n");

					printf("Enter the value for K from 0 to %d:\n", count1 + 1);
					scanf("%d", &k1);


					while (k1 < 0 || k1 > count1 + 1)
					{
						printf("Retry:\n");
						scanf("%d", &k1);
					}

					for (int i = k1; i >= k1 && i <= k1 + 1; i++)
					{
						if (*(array1 + i) == *(array1 + count1 + 1))
						{
							*(array1 + i + 1) = *(array1);
						}

						printf("%d ", *(array1 + i));
					}

					printf("\n");

					printf("1 - add first and last element in new array and walk from K to K + 1\n");
					printf("0 - quit\n");

					scanf("%d", &button1);

					if (button1 != 1 && button1 != 0)
					{
						printf("Retry:\n");
						scanf("%d", &button1);
					}

					if (button1 == 0)
					{
						return 0;
					}
				}
			}
		}
		printf("1 - to walk through the array to the right\n");
		printf("2 - to walk through the array to the left\n");
		printf("3 - to walk through the array step by step\n");
		printf("4 - to walk through the array from K to K - 1 and create new array\n");
		printf("0 - quit\n");

		scanf("%d", &button); 
	}
	return 0;
}