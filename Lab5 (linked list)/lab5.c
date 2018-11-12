#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node* next;
	struct node* prev;
} node;


node* new, *crawler;
node* head = NULL, *tail = NULL, *head1 = NULL, *tail1 = NULL;
int number = 0, number1 = 0;

node* create_node(int element);
node* create_node1(int element);
void add_node();
void display_from_beg();
void display_in_rev();
void display_from_given_to_prev();
void insert_at_first();
void insert_at_last();
void display_from_given_to_next();
void clear();

int main()
{
	int button;

	printf("1 - create list\n");
	printf("2 - display list from begining\n");
	printf("3 - display list from end\n");
	printf("4 - display list from K to K-1 and create new list\n");
	printf("0 - exit\n");

	while (1)
	{
		printf("Enter your choise: ");
		scanf("%d", &button);

		switch (button)
		{
			case 1:
			{
				add_node();
				break;
			}

			case 2:
			{
				display_from_beg();
				break;
			}

			case 3:
			{
				display_in_rev();
				break;
			}

			case 4:
			{
				display_from_given_to_prev();
				printf("5 - add first and last element in new list\n");
				printf("0 - exit\n");
				break;
			}

			case 5:
			{
				insert_at_first();
				insert_at_last();

				int i;
				for (crawler = head1, i = 1; i <= number1; i++, crawler = crawler->next)
				{
					printf("%d ", crawler->val);
				}

				printf("\n");
				printf("6 - display list from K to K + 1\n");
				printf("0 - exit\n");
				break;
			}

			case 6:
			{
				display_from_given_to_next();
				break;
			}

			case 0:
			{
				clear();
				exit(0);
			}

			default:
			{
				printf("Invalid input!\n");
			}
		}
	}

	return 0;
}

node* create_node(int element)
{
	number++;
	new = (node*)malloc(sizeof(node));
	new->val = element;
	new->next = NULL;
	new->prev = NULL;
	return new;
}

node* create_node1(int element)
{
	number1++;
	new = (node*)malloc(sizeof(node));
	new->val = element;
	new->next = NULL;
	new->prev = NULL;
	return new;
}

void add_node()
{
	int num, element[50];

	printf("Enter the number of list elements: ");
	scanf("%d", &num);
	printf("Enter the list elements:\n");

	for (int i = 1; i <= num; i++)
	{
		printf("%d element is ", i + number);
		scanf("%d", &element[i]);
	}

	for (int i = 1; i <= num; i++)
	{
		new = create_node(element[i]);

		if (head == tail && head == NULL)
		{
			head = tail = new;
			head->next = tail->next = NULL;
			head->prev = tail->prev = NULL;
		}

		else
		{
			tail->next = new;
			new->prev = tail;
			tail = new;
			tail->next = head;
			head->prev = tail;
		}
	}
}

void display_from_beg()
{
	int i;
	if (head == tail && head == NULL)
	{
		printf("List is empty!\n");
	}

	else
	{
		for (crawler = head, i = 1; i <= number; i++, crawler = crawler->next)
		{
			printf("%d ", crawler->val);
		}

		printf("\n");
	}
}

void display_in_rev()
{
	int i;
	if (head == tail && head == NULL)
	{
		printf("List is empty!\n");
	}

	else
	{
		for (crawler = tail, i = 1; i <= number; i++, crawler = crawler->prev)
		{
			printf("%d ", crawler->val);
		}

		printf("\n");
	}
}

void display_from_given_to_prev()
{
	int i, k;
	int check = 0;

	printf("Enter the value for K: ");
	scanf("%d", &k);

	if (head == tail && head == NULL)
	{
		printf("List is empty!\n");
	}

	else
	{
		for (crawler = head, i = 1; i <= number; i++, crawler = crawler->next)
		{
			if (i == k)
			{
					new = create_node1(crawler->val);

					if (head1 == tail1 && head1 == NULL)
					{
						head1 = tail1 = new;
						head1->next = tail1->next = NULL;
						head1->prev = tail1->prev = NULL;
					}

					else
					{
						tail1->next = new;
						new->prev = tail1;
						tail1 = new;
						tail1->next = head1;
						head1->prev = tail1;
					}

					new = create_node1(crawler->prev->val);

					if (head1 == tail1 && head1 == NULL)
					{
						head1 = tail1 = new;
						head1->next = tail1->next = NULL;
						head1->prev = tail1->prev = NULL;
					}

					else
					{
						tail1->next = new;
						new->prev = tail1;
						tail1 = new;
						tail1->next = head1;
						head1->prev = tail1;
					}

					printf("New list\n");

					for (crawler = head1, i = 1; i <= number1; i++, crawler = crawler->next)
					{
						printf("%d ", crawler->val);
					}

					check = 1;
			}
			
		}

		if (check == 0)
		{
			printf("This node doesn't exist!");
		}

		printf("\n");
	}
}

void insert_at_first()
{
	int element;

	printf("Enter the value you want to add at first posistion: ");
	scanf("%d", &element);

	new = create_node1(element);

	if (head1 == tail1 && head1 == NULL)
	{
		head1 = tail1 = new;
		head1->next = tail1->next = NULL;
		head1->prev = tail1->prev = NULL;
	}

	else
	{
		new->next = head1;
		head1->prev = new;
		head1 = new;
		head1->prev = tail1;
		tail1->next = head1;
	}
}

void insert_at_last()
{
	int element;

	printf("Enter the value you want to add at last position: ");
	scanf("%d", &element);

	new = create_node1(element);

	if (head1 == tail1 && head1 == NULL)
	{
		head1 = tail1 = new;
		head1->next = tail1->next = NULL;
		head1->prev = tail1->prev = NULL;
	}

	else
	{
		tail1->next = new;
		new->prev = tail1;
		tail1 = new;
		tail1->next = head1;
		head1->prev = tail1;
	}
}

void display_from_given_to_next()
{
	int i, k;
	int check = 0;

	printf("Enter the value for K: ");
	scanf("%d", &k);

	if (head1 == tail1 && head1 == NULL)
	{
		printf("List is empty!\n");
	}

	else
	{
		for (crawler = head1, i = 1; i <= number; i++, crawler = crawler->next)
		{
			if (i == k)
			{
				printf("%d %d", crawler->val, crawler->next->val);
			}

		}
		printf("\n");
	}
}

void clear()
{
	int i;
	if (number > 0)
	{
		for (crawler = head, i = 1; i <= number; i++, crawler = crawler->next)
		{
			free(crawler);
		}
	}

	if (number1 > 0)
	{
		for (crawler = head1, i = 1; i <= number1; i++, crawler = crawler->next)
		{
			free(crawler);
		}
	}
}