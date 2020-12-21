#include <stdio.h>
#include <stdlib.h>
//Soal 4
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

void removeDuplicate(struct Node **node){
	Node *store = NULL;//store all the numbers
	int prev;//will be useful later
	Node *temp = *node;
	while(temp->next!=NULL){
		if(temp->value != temp->next->value){
		/* if the curr node value and the next is different, pushTail to store */
			pushTail(&store,temp->value);
			prev = temp->value;
		}
		temp = temp->next;
	}
	if(temp->value!=prev){
		/* if the previous number and the last number is different,
		pushTail to store */
		pushTail(&store,temp->value);
	}
	/* delete all node */
	free(*node);
	/* set node as store */
	*node = store;
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
	struct Node *b = NULL;
	pushTail(&a,1); pushTail(&a,1);	pushTail(&a,1);	pushTail(&a,1);
	pushTail(&a,1);	pushTail(&a,1);	pushTail(&a,1);	pushTail(&a,1);
	pushTail(&a,1);	pushTail(&a,1);	pushTail(&a,1);
	printf("Node a before:\n");
	printAll(a);
	pushTail(&b,1); pushTail(&b,1);	pushTail(&b,1);	pushTail(&b,1);
	pushTail(&b,2);	pushTail(&b,2);	pushTail(&b,2);	pushTail(&b,2);
	pushTail(&b,3);	pushTail(&b,3);	pushTail(&b,4);
	printf("Node b before:\n");
	printAll(b);
	removeDuplicate(&a);
	removeDuplicate(&b);
	printf("Node a after:\n");
	printAll(a);
	printf("Node b after:\n");
	printAll(b);
	return 0;
}
