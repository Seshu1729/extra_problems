#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
	int num;
	struct node *next;
};
struct node *getNode();
struct node * numberToLinkedList(int N);

//Main Algorithm Start Here

int getResult(struct node *head)
{
	struct node *result = head;
	while (head->next != NULL)
	{
		head = head->next;
		if (head->next != NULL)
		{
			head = head->next;
			result = result->next;
		}
	}
	return result->num;
}

void testInputCases()
{
	int i;
	struct node *head1 = numberToLinkedList(123456789);
	struct node *head2 = numberToLinkedList(12345678);
	struct node *head3 = numberToLinkedList(12);
	struct node *head4 = numberToLinkedList(1);
	struct testcases
	{
		struct node *head;
		int result;
	}test[4] = {
			{ head1, 5 },
			{ head2, 4 },
			{ head3, 1 },
			{ head4, 1 }
	};
	for (i = 0; i<4; i++)
	{
		if (getResult(test[i].head) == test[i].result)
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

void getLinkedList(struct node *head, struct node **newHead, struct node *pre)
{
	if (head->next != NULL)
	{
		*newHead = head->next;
		getLinkedList(head->next, newHead, head);
	}
	head->next = pre;
}

struct node * numberToLinkedList(int N)
{
	struct node *start = NULL, *newNode;
	do
	{
		newNode = getNode();
		newNode->num = N % 10;
		newNode->next = start;
		start = newNode;
		N /= 10;
	} while (N);
	return start;
}