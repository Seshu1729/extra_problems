#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
	int num;
	struct node *next;
};
struct node *getNode();
struct node *numberToLinkedList(int N);
int linkedListToNumber(struct node *head);
void swap(int *a, int *b);

//Main Algorithm Starts Here

struct node *getResult(struct node *head)
{
	struct node *start = head;
	int *a = NULL, *b = NULL;
	while (start != NULL)
	{
		if (start->next->num < start->num)
			break;
		start = start->next;
	}
	a = &start->num;
	while (start != NULL&&start->num <= *a)
	{
		b = &start->num;
		start = start->next;
	}
	swap(a, b);
	return head;
}


void testInputCases()
{
	int i;
	struct node *head1 = numberToLinkedList(12645378);  //general condition
	struct node *head2 = numberToLinkedList(82345671);  //boundary condition 1
	struct node *head3 = numberToLinkedList(12354678);  //boundary condition 2
	struct testcases
	{
		struct node *head;
		int result;
	}test[3] = {
			{ head1, 12345678 },
			{ head2, 12345678 },
			{ head3, 12345678 }
	};
	for (i = 0; i<3; i++)
	{
		if (linkedListToNumber(getResult(test[i].head)) == test[i].result)
			printf("pass\n");
		else
			printf("fail\n");
	}
}

int main()
{
	testInputCases();
	_getch();
}

struct node *getNode()
{
	struct node *newNode;
	newNode = (struct node *)malloc(sizeof(struct node));
	return newNode;
}

struct node * numberToLinkedList(int N)
{
	struct node *start = NULL, *newNode;
	while (N)
	{
		newNode = getNode();
		newNode->num = N % 10;
		newNode->next = start;
		start = newNode;
		N /= 10;
	}
	return start;
}

int linkedListToNumber(struct node *head)
{
	int result = 0;
	do
	{
		result = (result * 10) + head->num;
		head = head->next;
	} while (head != NULL);
	return result;
}

void swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}