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

void printAll(struct Node *node){
	printf("Output: ");
	while(node != NULL){//while there's still some node
		printf("%d ",node->value);
        node = node->next;  
	} printf("\n");
}
void merge(Node *a, Node *b, Node **c, int n, int m){
	int p1=0,p2=0;
	//how it works is just like combining 2 arrays in merge sort
	while(p1<=n && p2<=m){
		//cout<<a->value<<" "<<b->value;
		if(a->value < b->value){
			pushTail(&*c,a->value);//pushTail value in a to c
			p1++;//just for the limit
			a = a->next;//next node for a
		}else{
			pushTail(&*c,b->value);//pushTail value in b to c
			p2++;//just for the limit
			b = b->next;//next node for b
		}
	}
	while(p1<=n){//make sure everything is inside node c
		pushTail(&*c,a->value);
		p1++;
		a = a->next;
	}
	while(p2<=m){// same as above
		pushTail(&*c,b->value);
		p2++;
		b = b->next;
	}
}
int main(){
	struct Node *a = NULL;//1st linked list
	struct Node *b = NULL;//2nd linked list
	struct Node *c = NULL;//combined linked list
	int n,m;
	printf("insert n and m: ");
	scanf("%d %d",&n,&m);
	int x;
	printf("insert %d numbers (ascending order): ",n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		pushTail(&a,x);
	}
	printf("insert %d numbers (ascending order): ",m);
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		pushTail(&b,x);
	}
	//merge both linked list
	merge(a,b,&c,n-1,m-1);
	printAll(c);
	return 0;
}
