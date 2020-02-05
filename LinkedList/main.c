#include <stdio.h>
#include <stdlib.h>

typedef enum {TRUE,FALSE} Boolean;
typedef int entryType;

typedef struct Node{
    entryType element;
    struct node *next;
}node;

typedef struct linkedList{
    int count;
    node *head;
    Boolean full;
}linkedList;

void createList(linkedList *l){
    l->count=0;
    l->full=FALSE;
    l->head=NULL;
}
Boolean isEmpty(linkedList *l){
    if(l->head==NULL){
        return 1;
    }else{
        return 0;
    }
}

Boolean isFull(linkedList *l){
    if(l->full==TRUE){
        return 1;
    }else{
        return 0;
    }
}

int listSize(linkedList *l){
    return (l->count);
}

void insertFront(linkedList *l){
    if(isFull(l)){
        printf("\nList is full.");
    }else{
        printf("\nEnter the number : ");
        entryType item;
        scanf("%d",&item);
        node *np;
        np = (node*)malloc(sizeof(node));
        np->element=item;
        if(l->head==NULL){
            np->next=NULL;
        }else{
            np->next=l->head;
        }
        l->head=np;
        l->count++;
    }
}

void insertRear(linkedList *l){
    if(isFull(l)){
        printf("\nList is full.");
    }else{
        printf("\nEnter the number : ");
        entryType item;
        scanf("%d",&item);
        node *np,*temp;
        temp=(node*)malloc(sizeof(node));
        np=(node*)malloc(sizeof(node));
        np->next=NULL;
        np->element=item;
        if(l->head==NULL){
            l->head=np;
        }
        else{
           temp=l->head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=np;
        }
        l->count++;
    }
}

void insertMid(linkedList *l){
    if(isFull(l)){
        printf("\nList is full");
    }else{
        int pos;
        entryType item;
        printf("\nEnter the number : ");
        scanf("%d",&item);
        printf("\nEnter the position : ");
        scanf("%d",&pos);
        node *temp;
        temp=l->head;
        if(pos>0&&pos<=l->count){
            for(int x=1;x<pos;x++){
                temp=temp->next;
            }
            node *np;
            np=(node*)malloc(sizeof(node));
            np->element=item;
            np->next=temp->next;
            temp->next=np;
            l->count++;
        }else{
            printf("\nEntered position is not in the range.");
        }
    }
}

void deleteFront(linkedList *l){
    if(isEmpty(l)){
        printf("\nLink is empty");
    }else{
        node *temp;
        temp = (node*)malloc(sizeof(node));
        temp=l->head;
        l->head=l->head->next;
        l->count--;
        free(temp);
    }
}

void deleteRear(linkedList *l){
    if(isEmpty(l)){
        printf("\nList is empty.");
    }else{
        node *temp,*temp2;
        temp=(node*)malloc(sizeof(node));
        temp2=(node*)malloc(sizeof(node));
        temp=l->head;
        while(temp->next!=NULL){
            temp2=temp;
            temp=temp->next;
        }
        free(temp->next);
        temp2->next=NULL;
        l->count--;
    }
}

void deleteMid(linkedList *l){
    if(isEmpty(l)){
        printf("\nList is empty");
    }else{
        printf("\nEnter the position : ");
        int pos;
        scanf("%d",&pos);
        if(pos>0&&pos<l->count){
            node *temp;
            temp=(node*)malloc(sizeof(node));
            temp=l->head;
            for(int x=1;x<pos;x++){
                temp=temp->next;
            }
            node *temp2=temp->next;
            temp->next=temp2->next;
            l->count--;
        }else{
            printf("\nEntered position is out of range.");
        }
    }
}
void viewList(linkedList *l){
    if(isEmpty(l)){
        printf("\nList is empty.");
    }else{
        node *temp;
        temp = l->head;
        printf("\n");
        for(int x=0;x<l->count;x++){
            printf("%d ",temp->element);
            temp=temp->next;
        }
    }
}

int menu(){
    int x;
    printf("\n\n--------LinkedList Example------\n");
    printf("\n(1) Insert numbers to front");
    printf("\n(2) Insert numbers to rear");
    printf("\n(3) Insert numbers to a specified position");
    printf("\n(4) Remove numbers from front");
    printf("\n(5) Remove numbers from rear");
    printf("\n(6) Remove numbers from a specified position");
    printf("\n(7) View queue");
    printf("\n(8) Exit");
    printf("\n\nSelect : ");
    scanf("%d",&x);
    return x;
}

int main()
{
    linkedList l;
    createList(&l);
    int x=0;
    while(x!=8){
        x=menu();
        switch(x){
        case 1:
            insertFront(&l);
            break;
        case 2:
            insertRear(&l);
            break;
        case 3:
            insertMid(&l);
            break;
        case 4:
            deleteFront(&l);
            break;
        case 5:
            deleteRear(&l);
            break;
        case 6:
            deleteMid(&l);
            break;
        case 7:
            viewList(&l);
            break;
        default:
            break;
        }
    }
    return 0;
}
