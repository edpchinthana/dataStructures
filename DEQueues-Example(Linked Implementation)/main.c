#include <stdio.h>
#include <stdlib.h>
typedef enum {true,false} Boolean;
typedef int elementType;
typedef struct Node{
    elementType element;
    struct node *next, *prev;
}node;

typedef struct DEQueue{
    int count;
    Boolean full;
    node *rear;
    node *front;
}DEQueue;

void createDEQueue(DEQueue *q){
    q->count = 0;
    q-> full = false;
    q->rear=q->front=NULL;
}

Boolean isEmpty(DEQueue *q){
    return(q->rear==NULL&&q->front==NULL);
}
Boolean isFull(DEQueue *q){
    if(q->full==true){
        return 1;
    }else{
        return 0;
    }
}

void insertFront(DEQueue *q){
    if(isFull(q)){
        printf("\nQueue is full..");
    }else{
        printf("\nEnter the number : ");
        elementType item;
        scanf("%d",&item);
        node *np;
        np=(node*)malloc(sizeof(node));
        np->element=item;
        if(q->front==NULL){
            q->front=q->rear=np;
        }else{
            np->next=q->front;
            q->front->prev=np;
            np->prev=NULL;
            q->front=np;
        }
        q->count++;
    }
}

void insertRear(DEQueue *q){
    if(isFull(q)){
        printf("\nQueue is full..");
    }else{
        printf("\nEnter the number : ");
        elementType item;
        scanf("%d",&item);
        node *np;
        np=(node*)malloc(sizeof(node));
        np->element=item;
        if(q->front==NULL){
            q->front=q->rear=np;
        }
        else{
            np->prev=q->rear;
            q->rear->next=np;
            q->rear=np;
            np->next=NULL;
        }
        q->count++;
    }
}

void deleteFront(DEQueue *q){
    if(isEmpty(q)){
        printf("\nQueue is empty...");
    }else{
        node *temp;
        temp=(node*)malloc(sizeof(node));
        temp = q->front;
        q->front=temp->next;
        if(q->front==NULL){
            q->rear=NULL;
        }else{
            q->front->prev=NULL;
        }
        free(temp);
        q->count--;
    }
}

void deleteRear(DEQueue *q){
    if(isEmpty(q)){
        printf("\nQueue is empty...");
    }else{
        node *temp;
        temp = q->rear;
        q->rear=temp->prev;
        if(q->rear==NULL){
            q->front=NULL;
        }else{
           q->rear->next=NULL;
        }
        free(temp);
        q->count--;
    }
}

void viewQueue(DEQueue *q){
    if(isEmpty(q)){
        printf("\nQueue is empty...");
    }else{
        printf("\n");
        node *temp = q->front;
        for(int x=0;x<q->count;x++){
            printf("%d ",temp->element);
            temp=temp->next;
        }
    }
}

int menu(){
    int x;
    printf("\n\n--------Queues Example------\n");
    printf("\n(1) Insert numbers to front");
    printf("\n(2) Insert numbers to rear");
    printf("\n(3) Remove numbers from front");
    printf("\n(4) Remove numbers from rear");
    printf("\n(5) View queue");
    printf("\n(6) Exit");
    printf("\n\nSelect : ");
    scanf("%d",&x);
    return x;
}


int main()
{
    DEQueue q;
    createDEQueue(&q);
    int x=0;
    while(x!=6){
        x=menu();
        switch(x){
        case 1:
            insertFront(&q);
            break;
        case 2:
            insertRear(&q);
            break;
        case 3:
            deleteFront(&q);
            break;
        case 4:
            deleteRear(&q);
            break;
        case 5:
            viewQueue(&q);
            break;
        default:
            break;
        }
    }
    return 0;
}
