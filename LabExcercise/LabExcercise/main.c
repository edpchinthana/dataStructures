#include <stdio.h>
#include <stdlib.h>
#define maxList 50

typedef enum{TRUE,FALSE} Boolean;

typedef struct LinkedListNode{
    char name[100];
    char number[10];
    struct Node *next;
    struct Node *prev;
}Node;

typedef struct ContactList{
    int count;
    struct Node* head;
    Boolean isFull;
}ContactList;

Boolean isFull(ContactList *cl){
    if(cl->count>=maxList){
        return 1;
    }else{
        return 0;
    }
}

Boolean isEmpty(ContactList *cl){
    if(cl->count==0){
        return 1;
    }else{
        return 0;
    }
}

void createContactList(ContactList *cl){
    cl->count=0;
    cl->head=NULL;
    cl->isFull=FALSE;
}

void addContact(ContactList *cl){
    char name[100];
    char number[10];
    printf("\n\n--------Add Contacts-------");
    if(isFull(cl)){
        printf("\nSorry contact list is full");
    }else{
        printf("\nName : ");
        scanf("%s",&name);
        printf("Number  : ");
        scanf("%s",&number);

        Node *newNode;
        newNode = (Node*)malloc(sizeof(Node));
        strcpy(newNode->name,name);
        strcpy(newNode->number,number);
        newNode->next=NULL;
        if(isEmpty(cl)){
            cl->head=newNode;
            newNode->prev=NULL;
        }else{
            Node *temp =cl->head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->prev=temp;
            }
        cl->count++;
    }
}

void deleteContact(ContactList *cl){
    printf("\n\n-------------Delete Contact-----------");
    if(!isEmpty(cl)){
        int choice;
        char keyword[100];
        printf("\nSearch by\t1. Name\t2. Number");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        printf("Keyword : ");
        scanf("%s",&keyword);


        if(choice!=1||choice!=2){
            printf("\nWrong choice...please try again");
        }else{
            int check = 0;
            Node* temp = cl->head;

            if(choice==1){
                while(temp!=NULL){
                    if(strcmp(temp->name,keyword)){
                        check = 1;
                        break;
                    }
                    temp=temp->next;
                }
            }else if(choice==2){
                while(temp!=NULL){
                    if(strcmp(temp->number,keyword)){
                        check = 1;
                        break;
                    }
                    temp=temp->next;
                }
            }

            if(check==1){
                printf("\n-----Contact Information---------");
                printf("\nName   : %s",temp->name);
                printf("\nNumber : %s",temp->number);
                printf("\nDo you want to delete(y/n)?");
                char a;
                scanf("%c",&a);
                if(a=='y'){
                    Node *tempPrev = temp->prev;
                    Node *tempNext = temp->next;
                    tempPrev->next=tempNext;
                    tempNext->prev = tempPrev;
                    free(temp);
                    cl->count--;
                    printf("\nSuccessfully deleted....");
                }else{

                }
            }else{
                printf("\nSorry.. No results found");
            }
        }
    }else{
        printf("\nContact list is empty....");
    }
}

void viewContacts(ContactList *cl){
    printf("\n----------View Contacts-----------");
    if(isEmpty(cl)){
        printf("\nSorry contact list is empty..");
    }else{
        Node *temp = cl->head;

    }
}

int menu(){
    int x;
    printf("\n\n--------------Menu-------------");
    printf("\n\t1. Contact");
    printf("\n\t2. Messages");
    printf("\n\t3. Exit");
    printf("\n\tSelect your choice : ");
    scanf("%d",&x);
    if(x>=1||x<=3){
        return x;
    }else{
        x = menu();
        return x;
    }
}

int main()
{

    int x=0;
    while(x!=3){
        x=menu();
        switch(x){
            case 3:
                exit(1);
                break;
        }
    }
    return 0;
}
