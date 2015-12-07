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
struct node *reverse(struct node *head);

//Main Algorithm Starts Here

struct node *getResult(struct node *head)
{
	struct node *start = head, *temp = NULL;
	while (start != NULL&&start->num < start->next->num)
	{
		temp = start;
		start = start->next;
	}
	temp->next = reverse(start);
	return head;
}


void testInputCases()
{
	int i;
	struct node *head1 = numberToLinkedList(12348765);
	struct node *head2 = numberToLinkedList(12876543);
	struct node *head3 = numberToLinkedList(18765432);
	struct node *head4 = numberToLinkedList(12345687);
	struct testcases
	{
		struct node *head;
		int result;
	}test[4] = {
			{ head1, 12345678 },
			{ head2, 12345678 },
			{ head3, 12345678 },
			{ head4, 12345678 }
	};
	for (i = 0; i<4; i++)
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

struct node *reverse(struct node *head)
{
	struct node  *temp1 = NULL, *temp2 = NULL;
	while (head != NULL)
	{
		temp2 = head->next;
		head->next = temp1;
		temp1 = head;
		head = temp2;
	}
	return temp1;
}
