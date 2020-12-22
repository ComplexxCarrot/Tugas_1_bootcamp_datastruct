#include <stdio.h>
#include <stdlib.h>
//Soal 2
struct Node {
  	int value; // store node's value
  	Node *next; // node's next pointer
}; //*head, *tail, *curr; // global head, tail, and current

void pushTail(Node** head_ref, int new_data){  
    /* 1. allocate node */
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
bool cyclecheck(Node *a){
	Node *storage = NULL;//storing values
	bool flag2=false;
    while (a != NULL) {
		Node *temp = storage;
		while(temp){//check inside of temp one by one
			if(temp->value==a->value){//if we found any duplicate/cycle
				if(temp->next!=NULL){//if it's not in the last node
					return true;
				}
			}
			temp = temp->next;//next node of temp
		}
        pushTail(&storage,a->value);//add a->value to storage, more numbers to check
        a = a->next;//next node of a
    }

    return false;
}
void createcycle(Node **a, int x){
	Node *last = *a;
	while(last->next!=NULL){//traverse till last node
		last = last->next;
	}
	Node *curr = *a;
	while(curr->value!=x){
		curr=curr->next;
	}
	last->next=curr;//set cycle
}
int main(){
	struct Node *a = NULL;
	int n;
	printf("insert n: ");
	scanf("%d",&n);
	int x;
	printf("insert %d number(s) (0 - 100000): ",n);
	bool check[100000]={0};
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		pushTail(&a,x);
		if(check[x]){//if there's duplicate, create cycle
			createcycle(&a,x);
		}
		check[x]=true;
	}
	bool flag = cyclecheck(a);
	if(flag) printf("cycle found!\n");
	else printf("no cycle found!\n");
	return 0;
}

