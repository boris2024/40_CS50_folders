#include<stdio.h>
#include<stdlib.h>

// source https://www.geeksforgeeks.org/menu-driven-program-for-all-operations-on-singly-linked-list-in-c/

// C program for the all operations in
// the Singly Linked List
// Linked List Node

struct node
{
	int info;
	struct node *link;
};

struct node *start = NULL;

// 00 Function to create list with n nodes initially
void createList()
{
	if (start == NULL)
	{
		int n;
		printf("\nEnter the number of nodes: ");
		scanf("%d", &n);

		if (n != 0)
		{
			int data;
			struct node *newnode;
			struct node *temp;

			newnode = malloc(sizeof(struct node));
			start = newnode;
			temp = start;

			printf("\nEnter number to"
				" be inserted : ");

			scanf("%d", &data);
			start->info = data;

			for (int i = 2; i <= n; i++)
			{
				newnode = malloc(sizeof(struct node));
				temp->link = newnode;
				printf("\nEnter number to"
					" be inserted : ");
				scanf("%d", &data);
				newnode->info = data;
				temp = temp->link;
			}
		}
		printf("\nThe list is created\n");
	}
	else
		printf("\nThe list is already created\n");
}

// 01 Function to traverse the linked list
void traverse()
{
	struct node* temp;

	// List is empty
	if (start == NULL)
		printf("\nList is empty\n");

	// Else print the LL
	else
	{
		temp = start;
		while (temp != NULL) {
			printf("Data = %d\n", temp->info);
			temp = temp->link;
		}
	}
}

// 02 Function to insert at the front of the linked list
void insertAtFront()
{
	int data;
	struct node* temp;
	temp = malloc(sizeof(struct node));
	printf("\nEnter number to"
		" be inserted : ");
	scanf("%d", &data);
	temp->info = data;

	// Pointer of temp will be
	// assigned to start
	temp->link = start;
	start = temp;
}

// 03 Function to insert at the end of the linked list
void insertAtEnd()
{
	int data;
	struct node *temp, *head;
	temp = malloc(sizeof(struct node));

	// Enter the number
	printf("\nEnter number to"
		" be inserted : ");
	scanf("%d", &data);

	// Changes links
	temp->link = 0;
	temp->info = data;
	head = start;
	while (head->link != NULL) {
		head = head->link;
	}
	head->link = temp;
}

// 04 Function to insert at any specified position in the linked list
void insertAtPosition()
{
	struct node *temp, *newnode;
	int pos, data, i = 1;
	newnode = malloc(sizeof(struct node));

	// Enter the position and data
	printf("\nEnter position and data :");
	scanf("%d %d", &pos, &data);

	// Change Links
	temp = start;
	newnode->info = data;
	newnode->link = 0;
	while (i < pos - 1) {
		temp = temp->link;
		i++;
	}
	newnode->link = temp->link;
	temp->link = newnode;
}


// Driver Code
int main()
{
	int choice;
	while (1)
		{

		printf("\n\t1 To see list\n");
		printf("\t2 For insertion at"
			" starting\n");
		printf("\t3 For insertion at"
			" end\n");
		printf("\t4 For insertion at "
			"any position\n");


		printf("\t13 To exit\n");
		printf("\nEnter Choice :\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:	{traverse();	break;}

		case 2:	{insertAtFront(); break;}

		case 3:	{insertAtEnd();	break;}

		case 4: {insertAtPosition();break;}

		default:
			printf("Incorrect Choice\n");
		}
	}
	return 0;
}
