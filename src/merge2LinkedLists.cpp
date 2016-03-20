/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>
struct node {
	int num;
	struct node *next;
};
void swap(struct node *a, struct node *b);

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL && head2 == NULL) return NULL;
	else if (head1 == NULL&&head2 != NULL) return head2;
	else if (head1 != NULL && head2 == NULL) return head1;
	else{
		struct node* temp1 = head1;
		struct node* temp = head1;
		while (temp1->next != NULL){
			temp1 = temp1->next;
		}
		temp1->next = head2;
		for (temp = head1; temp->next != NULL; temp = temp->next){
			for (temp1 = temp->next; temp1 != NULL; temp1 = temp1->next){
				if (temp->num > temp1->num)
					swap(temp, temp1);
			}
		}
		//free(head2);
		return head1;
	}
}
void swap(struct node *a,struct node *b)
{
	int temp = a->num;
	a->num = b->num;
	b->num = temp;
}

