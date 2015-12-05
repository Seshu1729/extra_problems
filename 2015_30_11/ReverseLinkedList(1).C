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
int linkedListToNumber(struct node *head);

//Main Algorithm Starts Here

void getLinkedList(struct node *head, struct node **newHead, struct node *pre)
{
	if (head->next != NULL)
	{
		*newHead = head->next;
		getLinkedList(head->next, newHead, head);
	}
	head->next = pre;
}

struct node* getResult(struct node *head)
{
	struct node *newHead;
	if (head == NULL || head->next == NULL)
		return NULL;
	getLinkedList(head, &newHead, NULL);
	return newHead;
}

void testInputCases()
{
	int i;
	struct node *head;
	struct node *head1 = numberToLinkedList(123456);
	struct node *head2 = numberToLinkedList(12345);
	struct testcases
	{
		struct node *head;
		int result;
	}test[2] = {
			{ head1, 654321 },
			{ head2, 54321 }
	};
	for (i = 0; i<2; i++)
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

int linkedListToNumber(struct node *head)
{
	int result = 0;
	while (head != NULL)
	{
		result = (result * 10) + head->num;
		head = head->next;
	}
	return result;
}
