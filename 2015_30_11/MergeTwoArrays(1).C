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

struct node* getResult(struct node *head1, struct node *head2)
{
	struct node *head;
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head2;
	else if (head1->num < head2->num)
	{
		head1->next = getResult(head1->next, head2);
		return head1;
	}
	else
	{
		head2->next = getResult(head1, head2->next);
		return head2;
	}
}

void testInputCases()
{
	int i;
	struct node *head;
	struct node *head11 = numberToLinkedList(135);
	struct node *head12 = numberToLinkedList(246);
	struct node *head21 = numberToLinkedList(147);
	struct node *head22 = numberToLinkedList(289);
	struct testcases
	{
		struct node *head1;
		struct node *head2;
		int result;
	}test[2] = {
			{ head11, head12, 123456 },
			{ head21, head22, 124789 }
	};
	for (i = 0; i<2; i++)
	{
		if (linkedListToNumber(getResult(test[i].head1, test[i].head2)) == test[i].result)
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