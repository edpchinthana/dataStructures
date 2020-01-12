#include <stdio.h>
#include <stdlib.h>
#define maxDEQueue 5
typedef enum{TRUE,FALSE} boolean;
typedef int DEQueueEntryType;
typedef struct Queue{
    int count;
    int front;
    int rear;
    DEQueueEntryType elements[maxDEQueue];
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
    if(q->count==maxDEQueue){
        return 1;
    }else{
        return 0;
    }
}

void enQueueRear(queue *q){
    if(isFull(q)){
        printf("\nQueue is full");
    }else{
        printf("\nEnter the number : ");
        int item;
        scanf("%d",&item);
        if(isEmpty(q)){
            q->front = 0;
            q->rear = 0;
        }else{
            if(q->rear==maxDEQueue-1){
                q->rear=0;
            }else{
                q->rear = q->rear+1;
            }
        }
        q->elements[q->rear]=item;
        q->count++;
    }
}

void enQueueFront(queue *q){
    if(isFull(q)){
        printf("\nQueue is full");
    }else{
        printf("\nEnter the number : ");
        int item;
        scanf("%d",&item);
        if(isEmpty(q)){
            q->front = 0;
            q->rear = 0;
        }else{
            if(q->front == 0){
                q->front = maxDEQueue-1;
            }else{
                q->front=q->front-1;
            }
        }
        q->elements[q->front]=item;
        q->count++;
    }
}

void deQueueFront(queue *q){
    if(isEmpty(q)){
        printf("\nQueue is empty...");
    }else{
        if(q->front==q->rear){
            q->rear=-1;
            q->front=-1;
        }else{
            if(q->front==maxDEQueue-1){
                q->front=0;
            }else{
                q->front=q->front+1;
            }
        }
        q->count--;
    }
}

void deQueueRear(queue *q){
    if(isEmpty(q)){
        printf("\nQueue is empty...");
    }else{
        if(q->front==q->rear){
            q->rear=-1;
            q->front=-1;
        }else{
            if(q->rear==0){
                q->rear=maxDEQueue-1;
            }else{
                q->rear=q->rear -1;
            }
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
            for(int x=q->front;x<maxDEQueue;x++){
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
    queue q;
    createQueue(&q);
    int x=0;
    while(x!=6){
        x=menu();
        switch(x){
        case 1:
            enQueueFront(&q);
            break;
        case 2:
            enQueueRear(&q);
            break;
        case 3:
            deQueueFront(&q);
            break;
        case 4:
            deQueueRear(&q);
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
