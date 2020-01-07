#include <stdio.h>
#include <stdlib.h>
#define maxQueue 5
typedef enum{TRUE,FALSE} boolean;
typedef int queueEntryType;
typedef struct Queue{
    int count;
    int front;
    int rear;
    queueEntryType elements[maxQueue];
}queue;

void createQueue(queue *q){
    q->count=0;
    q->front=-1;
    q->rear=-1;
}

boolean isEmpty(const queue *q){
    if(q->count==0){
        return 1;
    }else{
        return 0;
    }
}

boolean isFull(const queue *q){
    if(q->count==maxQueue){
        return 1;
    }else{
        return 0;
    }
}

void enQueue(queue *q){
    if(isFull(q)){
        printf("\nQueue is full");
    }else{
        printf("\nEnter the number : ");
        int item;
        scanf("%d",&item);
        q->rear=(q->rear+1)%maxQueue;
        q->elements[q->rear]=item;
        q->count++;
        if(q->front==-1){
            q->front=0;
        }
    }
}

void deQueue(queue *q){
    if(isEmpty(q)){
        printf("\nQueue is empty...");
    }else{
        if(q->front==q->rear){
            q->rear=-1;
            q->front=-1;
        }else{
            q->front = (q->front+1)%maxQueue;
        }
        q->count--;

    }
}
void viewQueue(queue *q){
    if(isEmpty(q)){
       printf("\nQueue is empty");
    }else{
        printf("\n");
        if(q->front<=q->rear){
            for(int x=q->front;x<=q->rear;x++){
                printf("%d ",q->elements[x]);
            }
        }else{
            for(int x=q->front;x<maxQueue;x++){
                printf("%d ",q->elements[x]);
            }
            for(int x=0;x<=q->rear;x++){
                printf("%d ",q->elements[x]);
            }
        }
    }
}

int menu(){
    int x;
    printf("\n\n--------Queues Example------\n");
    printf("\n(1) Insert numbers");
    printf("\n(2) Remove numbers");
    printf("\n(3) View queue");
    printf("\n(4) Exit");
    printf("\n\nSelect : ");
    scanf("%d",&x);
    return x;
}

int main()
{
    queue q;
    createQueue(&q);
    int x=0;
    while(x!=4){
        x=menu();
        switch(x){
        case 1:
            enQueue(&q);
            break;
        case 2:
            deQueue(&q);
            break;
        case 3:
            viewQueue(&q);
            break;
        default:
            break;
        }
    }
    return 0;
}
