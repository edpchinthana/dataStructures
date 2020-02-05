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
    char number[12];
    printf("\n\n--------Add Contacts-------");
    if(isFull(cl)){
        printf("\nSorry contact list is full");
    }else{
        printf("\nName : \n");
        scanf("%s",&name);
        printf("Number  : \n");
        scanf("%s",&number);
    printf("name %s",name);
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
        printf("Keyword : \n");
        scanf("%s",&keyword);


        if(choice!=1&&choice!=2){
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
                printf("\nDo you want to delete(y/n)?\n");
                char a;
                scanf("%c",&a);
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
    printf("\n\t----------View Contacts-----------");
    if(isEmpty(cl)){
        printf("\nSorry contact list is empty..");
    }else{
        Node *temp = cl->head;
        int y=0;
        printf("\n\n -----------------------------------------------------");
        printf("\n|    |          Name          |    Telephone Number   |");
        printf("\n -----------------------------------------------------");
        while(temp!=NULL){
            int a = strlen(temp->name);
            int b = (24-a-1)/2;
            int c = strlen(temp->number);
            int d = (24-c-1)/2;

            printf("\n| %02d |",y);
            for(int x=0;x<b;x++){
                printf(" ");
            }
            printf(" %s",temp->name);
            for(int x=0;x<b;x++){
                printf(" ");
            }
            printf("|");
            for(int x=0;x<d;x++){
                printf(" ");
            }
            printf(" %s",temp->number);
            for(int x=0;x<d;x++){
                printf(" ");
            }
            printf("|");
            temp=temp->next;
            y++;
        }
        printf("\n -----------------------------------------------------");

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

void contactsMenu(ContactList *cl){
    printf("\n\n----------------Contacts-Menu----------------");
    printf("\n\t1. Add contacts");
    printf("\n\t2. Update contats");
    printf("\n\t3. Delete contacts");
    printf("\n\t4. View contacts");
    printf("\n\t5. Exit to main menu");
    printf("\nEnter your choice : ");
    int a;
    scanf("%d",&a);
    switch(a){
        case 1:
            addContact(cl);
            contactsMenu(cl);
            break;
        case 2:
            break;
        case 3:
            deleteContact(cl);
            contactsMenu(cl);
            break;
        case 4:
            viewContacts(cl);
            contactsMenu(cl);
            break;
        case 5:
        break;
    }
}

int main()
{
    ContactList cl;
    createContactList(&cl);
    int x=0;
    while(x!=3){
        x=menu();
        switch(x){
            case 1:
                contactsMenu(&cl);
                break;
            case 3:
                exit(1);
                break;
        }
    }
    return 0;
}
