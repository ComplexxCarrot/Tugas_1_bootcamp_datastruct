#include <stdio.h>
#include <stdlib.h>
//Soal 3
struct Node {
  	int value; // store node's value
  	Node *next; // node's next pointer
}; //*head, *tail, *curr; // global head, tail, and current

void pushTail(Node** head_ref, int new_data){  
    /* 1. allocate node */
    //Node* new_node = new Node();
	Node* new_node = (Node *)malloc(sizeof(Node));  
    Node *last = *head_ref; /* used in step 5*/
    /* 2. put in the data */
    new_node->value = new_data;  
    /* 3. This new node is going to be  
    the last node, so make next of  
    it as NULL*/
    new_node->next = NULL;  
    /* 4. If the Linked List is empty, 
    then make the new node as head */
    if (*head_ref == NULL)  {  
        *head_ref = new_node;  
        return;  
    }  
    /* 5. Else traverse till the last node */
    while (last->next != NULL)  
        last = last->next;  
    /* 6. Change the next of last node */
    last->next = new_node;  
    return;  
}  

void pushHead(Node** head_ref, int new_data){
    /* 1. allocate node */
	Node* new_node = (Node *)malloc(sizeof(Node));
	/* 2. put in the data */
	new_node->value = new_data;
	/* 3. This new node is going to be  
    the last node, so make next of  
    it as NULL*/
	new_node->next = NULL;
	/* 4. If the Linked List is empty, 
    then make the new node as head */
	if (*head_ref == NULL){
        *head_ref = new_node;  
        return;  
    }
    /* 5. set new_node as the first node */
    Node *last = new_node;
    /* 6. set the next node as head_ref */
    last->next = *head_ref;
    /* 7. set head_ref as last,
	so new_node will be infront of head_ref */
    *head_ref = last;
    return;
}  
void findMid(struct Node *node){
	Node *last = node;
	Node *output = node;
	int count=1;//count+1 for the last node
	while(last->next!=NULL){//while there's node in the next node
		count++;
		last = last->next;
	}
	int mid = count/2 - 1;
	while(mid--){
		output = output->next;
	}
	printf("middle number: %d\n",output->value);
}
void printAll(struct Node *node){
	printf("Numbers: ");
	while(node != NULL){//while there's still some node
		printf("%d ",node->value);
        node = node->next;  
	} printf("\n");
}
int main(){
	struct Node *a = NULL;//1st linked list
	pushTail(&a,1);
	pushHead(&a,2);
	pushTail(&a,3);
	pushTail(&a,4);
	pushHead(&a,5);
	pushHead(&a,6);
	printAll(a);
	findMid(a);
	return 0;
}
