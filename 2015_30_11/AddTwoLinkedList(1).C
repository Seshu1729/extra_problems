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
int getLength(struct node *head);

//Main Algorithm Starts Here

struct node *linkedListAdder(struct node *head1, struct node *head2, int *carry)
{
	struct node *node;
	if (head1 != NULL)
	{
		node = getNode();
		node->next = linkedListAdder(head1->next, head2->next, carry);
	}
	else
		return NULL;
	node->num = (head1->num + head2->num + *carry) % 10;
	*carry = (head1->num + head2->num + *carry) / 10;
	return node;
}

struct node *addCarry(struct node *head, int carry)
{
	struct node *carryNode = getNode();
	if (carry != 0)
	{
		carryNode->num = carry;
		carryNode->next = head;
		return carryNode;
	}
	else
		return head;
}
struct node *appendZeros(struct node *head, int noOfZeros)
{
	struct node *newNode = NULL;
	while (noOfZeros--)
	{
		newNode = getNode();
		newNode->num = 0;
		newNode->next = head;
		head = newNode;
	}
	return head;
}

struct node* getResult(struct node *head1, struct node *head2)
{
	struct node *head;
	int length1, length2, carry = 0;
	length1 = getLength(head1);
	length2 = getLength(head2);
	if (length1 < length2)
	{
		head1 = appendZeros(head1, length2 - length1);
		head = linkedListAdder(head1, head2, &carry);
		return addCarry(head, carry);
	}
	else if (length1 > length2)
	{
		head2 = appendZeros(head2, length1 - length2);
		head = linkedListAdder(head1, head2, &carry);
		return addCarry(head, carry);
	}
	else
	{
		head = linkedListAdder(head1, head2, &carry);
		return addCarry(head, carry);
	}
}


void testInputCases()
{
	int i;
	struct node *head11 = numberToLinkedList(135);
	struct node *head12 = numberToLinkedList(246);
	struct node *head21 = numberToLinkedList(1478);
	struct node *head22 = numberToLinkedList(289);
	struct node *head31 = numberToLinkedList(947);
	struct node *head32 = numberToLinkedList(9892);
	struct testcases
	{
		struct node *head1;
		struct node *head2;
		int result;
	}test[3] = {
			{ head11, head12, 381 },
			{ head21, head22, 1767 },
			{ head31, head32, 10839 }
	};
	for (i = 0; i<3; i++)
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

int getLength(struct node *head)
{
	int length = 0;
	while (head != NULL)
	{
		head = head->next;
		length++;
	}
	return length;
}