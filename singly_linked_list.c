#include <stdio.h>
#include <stdlib.h>

//? Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
}*curr,*prev,*temp;


//?----------------------------------------------------------------
//? different types of insertions of new nodes

void insertionAtFront(struct Node** headRef, int newData) {
    //? Allocate memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = newData;
    newNode->next = *headRef;
    // Make the new node the new head
    *headRef = newNode;
}

void insertionAtEnd(struct Node** headRef , int newData){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    curr = *headRef;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    if(curr->next == NULL){
        newNode->data = newData;
        curr->next = newNode;
        newNode->next = NULL;
    }
}

void insertionAtPos(struct Node** headRef, int newData, int pos){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    curr = *headRef;
    prev = NULL;
    int count = 0;
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = newData;
    newNode->next = NULL;

    if(*headRef == NULL )
    {
        *headRef = newNode;
        return;
    }
    while(curr != NULL && count != pos)
    {
        prev = curr ;
        curr = curr->next;
        count++;
    }
    if(curr == NULL && count == pos)
    {
        prev->next = newNode;
        return;
    }
    if(count == pos)
    {
        prev->next = newNode;
        newNode->next = curr;
    }
    else{
        printf("Position out of range\n");
    }
}
//?----------------------------------------------------------------

//?----------------------------------------------------------------
//? different types of deletions of nodes

void deletionAtFront(struct Node** headRef){
    if(*headRef == NULL){
        printf("Linked list is empty\n");
        return;
    }
    temp = *headRef;
    *headRef = (*headRef)->next;
    //free the deleted node memory space
    free(temp);
}

void deletionAtEnd(struct Node** headRef){
    if(*headRef == NULL){
        printf("Linked list is empty\n");
        return;
    }
    // If the list contains only one node
    if ((*headRef)->next == NULL) {
        free(*headRef);
        *headRef = NULL;
        return;
    }

    curr = *headRef;

    while((curr->next)->next != NULL)
    {
        curr = curr->next;
    }
    // free the last node
    free(curr->next);
    // Set the next pointer of the second to last node to NULL, indicating the new end of the list
    curr->next = NULL; 
}

void deletionAtPos(struct Node** headRef,int pos){
    if(*headRef == NULL){
        printf("Linked list is empty\n");
        return;
    }
    curr = *headRef;
    prev = NULL;
    int count =0 ;
    // if the pos is the first node 
    if(pos == 0 ){
        *headRef = curr->next;
        free(curr);
        return;
    }
    // to traverse to the corresponding pos
    while(curr->next != NULL && count != pos){
        prev = curr;
        curr = curr->next;
        count++;
    }
    // if the position is out of range
    if (curr == NULL) {
        printf("Position out of range\n");
        return;
    }
    
    prev->next = curr->next;
    free(curr);

}

//?----------------------------------------------------------------

//? Function to print the linked list
void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

//?----------------------------------------------------------------
//? insertion operations menu

void insertionOperation(struct Node** head){
    int choice,pos,newData;
    do
    {
        printf("1.Insertion at Front\n2.Insertion at End\n3.Insertion at Position\n4.Exit\n");
        printf("Enter your choice:\t");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1 :printf("Enter the data:");
                scanf("%d",&newData);
                insertionAtFront(head,newData);
                break;
        case 2 :printf("Enter the data:");
                scanf("%d",&newData);
                insertionAtEnd(head,newData);
                break;
        case 3 :printf("Enter the data:");
                scanf("%d",&newData); 
                printf("Enter the position:");
                scanf("%d",&pos);
                insertionAtPos(head,newData,pos);
                break;    
        case 4 :printf("Exiting...\n");      
                return;
        default:
            break;
        }
    } while (1);
}

//?----------------------------------------------------------------

//?----------------------------------------------------------------
//? deletion operations menu

void deletionOperation(struct Node** head ){
    int choice,pos;
    do
    {
        printf("1.Deletion at Front\n2.Deletion at End\n3.Deletion at Position\n4.Exit\n");
        printf("Enter your choice:\t");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1 :deletionAtFront(head);
                break;
        case 2 :deletionAtEnd(head);
                break;
        case 3 :printf("Enter the position:");
                scanf("%d",&pos);
                deletionAtPos(head,pos);
                break;    
        case 4 :printf("Exiting...\n");      
                return;
        default:
            break;
        }
    } while (1);
}

//?----------------------------------------------------------------


int main() {
    //? Initialize an empty linked list
    struct Node* head = NULL;
    int choice;
    do
    {
        printf("1.Insertion\n2.Deletion\n3.Traversal\n4.Exit\n");
        printf("Enter your choice:\t");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1 : insertionOperation(&head);
            break;
        case 2 : deletionOperation(&head);
            break;
        case 3 : printLinkedList(head);
            break;    
        case 4 : printf("Exiting...\n");      
            return 0;
        default:
            break;
        }
    } while (1);

    printf("Linked List: ");
    printLinkedList(head);

    return 0;
}
