#include <stdio.h>
#include <stdlib.h>
//Soal 1
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
void printAll(struct Node *node){
	printf("Output: ");
	while(node != NULL){//while there's still some node
		printf("%d ",node->value);
        node = node->next;  
	} printf("\n");
}
void flip(Node **a){
	Node *temp = NULL;//create a storage to store the numbers
	Node *last = *a;
	while(last){
		pushHead(&temp,last->value);
		last = last->next;
	}
	*a = temp;
}
int main(){
	struct Node *a = NULL;//1st linked list
	int n;
	printf("insert n: ");
	scanf("%d",&n);
	int x;
	printf("insert %d numbers (ascending order): ",n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		pushTail(&a,x);
	}
	//merge both linked list
	printf("\nbefore flipping:\n");
	printAll(a);
	printf("\nafter flipping:\n");
	flip(&a);
	printAll(a);
	return 0;
}
