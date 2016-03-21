/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head == NULL || K <= 0)return NULL;
	struct node* temp=head;
	int len = 1;
	while (temp->next != NULL){
		len++; temp = temp->next;
	}
	if (K >len){
		return head;
	}
	else{
		temp = head;
		struct node* temp2 = head->next;
		int count = 0;
		while (temp!= NULL&& temp2!= NULL) {
			++count;
			if (count == K){
				struct node* temp1 = (struct node*)malloc(sizeof(struct node));
				temp1->num = K;
				temp1->next = temp->next;
				temp->next = temp1;
				count = 0;
				temp=temp->next;
			}
			temp = temp->next;
			if (temp != NULL) temp2 = temp->next;
		}
		if (K == 1){
			struct node* temp1 = (struct node*)malloc(sizeof(struct node));
			temp1->num = K;
			temp1->next = NULL;
			temp->next = temp1;


		}
		return head;
	}
}
