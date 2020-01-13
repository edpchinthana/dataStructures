#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxBooks 20
typedef enum{TRUE,FALSE} Boolean;
typedef struct Book{
    char book_code[20];
    char title[20];
    int copies_avail;
    int price;
}book;

typedef struct BookArray{
    int count;
    book bookArr[maxBooks];
}bookArray;

void createBookArray(bookArray *b){
    b->count=0;
}

Boolean isEmpty(bookArray *b){
    if(b->count==0){
        return 1;
    }else{
        return 0;
    }
}

Boolean isFull(bookArray *b){
    if(b->count==maxBooks-1){
        return 1;
    }else{
        return 0;
    }
}

void inputData(bookArray *b){
    FILE *fp;
    fp=fopen("data.txt","r");
    char bc[100];
    char title[100];
    int cop;
    int price;

    while(!feof(fp)){
        fscanf(fp,"%s %s %d %d",&bc,&title,&cop,&price);
        strcpy(b->bookArr[b->count].book_code,bc);
        strcpy(b->bookArr[b->count].title,title);
        b->bookArr[b->count].copies_avail=cop;
        b->bookArr[b->count].price=price;
        b->count++;
    }
    fclose(fp);
}

void displayData(bookArray *b){
    for(int x=0;x<b->count;x++){
        printf("\n\n------Book %d------",x+1);
        printf("\nBook Code   : %s",b->bookArr[x].book_code);
        printf("\nBook Title  : %s",b->bookArr[x].title);
        printf("\nBook Copies : %d",b->bookArr[x].copies_avail);
        printf("\nBook Price  : %d",b->bookArr[x].price);
    }
}

void sortByTitleAsc(bookArray *b){
    book temp;

    for(int x=1;x<b->count;x++){
        strcpy(temp.book_code,b->bookArr[x].book_code);
        strcpy(temp.title,b->bookArr[x].title);
        temp.copies_avail=b->bookArr[x].copies_avail;
        temp.price=b->bookArr[x].price;

        for(int y=x-1;y>=0 &&strcmp(temp.title,b->bookArr[y].title)<0;y--){
            strcpy(b->bookArr[y+1].book_code,b->bookArr[y].book_code);
            strcpy(b->bookArr[y+1].title,b->bookArr[y].title);
            b->bookArr[y+1].copies_avail=b->bookArr[y].copies_avail;
            b->bookArr[y+1].price=b->bookArr[y].price;
            strcpy(b->bookArr[y].book_code,temp.book_code);
            strcpy(b->bookArr[y].title,temp.title);
            b->bookArr[y].copies_avail=temp.copies_avail;
            b->bookArr[y].price=temp.price;
        }
    }
}

void sortByTitleDesc(bookArray *b){
    book temp;

    for(int x=1;x<b->count;x++){
        strcpy(temp.book_code,b->bookArr[x].book_code);
        strcpy(temp.title,b->bookArr[x].title);
        temp.copies_avail=b->bookArr[x].copies_avail;
        temp.price=b->bookArr[x].price;

        for(int y=x-1;y>=0 &&strcmp(temp.title,b->bookArr[y].title)>0;y--){
            strcpy(b->bookArr[y+1].book_code,b->bookArr[y].book_code);
            strcpy(b->bookArr[y+1].title,b->bookArr[y].title);
            b->bookArr[y+1].copies_avail=b->bookArr[y].copies_avail;
            b->bookArr[y+1].price=b->bookArr[y].price;
            strcpy(b->bookArr[y].book_code,temp.book_code);
            strcpy(b->bookArr[y].title,temp.title);
            b->bookArr[y].copies_avail=temp.copies_avail;
            b->bookArr[y].price=temp.price;
        }
    }
}

void sortByPriceAsc(bookArray *b){

    book temp;
    int smallest;
    for(int x=0;x<b->count;x++){
        smallest = x;
        for(int y=x+1;y<b->count;y++){
            if(b->bookArr[smallest].price>b->bookArr[y].price){
                smallest=y;
            }
        }
        if(x!=smallest){
            strcpy(temp.book_code,b->bookArr[x].book_code);
            strcpy(temp.title,b->bookArr[x].title);
            temp.copies_avail=b->bookArr[x].copies_avail;
            temp.price=b->bookArr[x].price;
            strcpy(b->bookArr[x].book_code,b->bookArr[smallest].book_code);
            strcpy(b->bookArr[x].title,b->bookArr[smallest].title);
            b->bookArr[x].copies_avail=b->bookArr[smallest].copies_avail;
            b->bookArr[x].price=b->bookArr[smallest].price;
            strcpy(b->bookArr[smallest].book_code,temp.book_code);
            strcpy(b->bookArr[smallest].title,temp.title);
            b->bookArr[smallest].copies_avail=temp.copies_avail;
            b->bookArr[smallest].price=temp.price;
        }
    }
}

void sortByPriceDesc(bookArray *b){

    book temp;
    int smallest;
    for(int x=0;x<b->count;x++){
        smallest = x;
        for(int y=x+1;y<b->count;y++){
            if(b->bookArr[smallest].price<b->bookArr[y].price){
                smallest=y;
            }
        }
        if(x!=smallest){
            strcpy(temp.book_code,b->bookArr[x].book_code);
            strcpy(temp.title,b->bookArr[x].title);
            temp.copies_avail=b->bookArr[x].copies_avail;
            temp.price=b->bookArr[x].price;
            strcpy(b->bookArr[x].book_code,b->bookArr[smallest].book_code);
            strcpy(b->bookArr[x].title,b->bookArr[smallest].title);
            b->bookArr[x].copies_avail=b->bookArr[smallest].copies_avail;
            b->bookArr[x].price=b->bookArr[smallest].price;
            strcpy(b->bookArr[smallest].book_code,temp.book_code);
            strcpy(b->bookArr[smallest].title,temp.title);
            b->bookArr[smallest].copies_avail=temp.copies_avail;
            b->bookArr[smallest].price=temp.price;
        }
    }
}

void printFile(bookArray *b){
    FILE *fp;
    fp=fopen("dataOutput.txt","w");
    fprintf(fp,"\n\nSort by title ascending......\n");
    sortByTitleAsc(b);
    for(int x=0;x<b->count;x++){
        fprintf(fp,"\n\n------BOOK %d------",x+1);
        fprintf(fp,"\nBook Code   : %s",b->bookArr[x].book_code);
        fprintf(fp,"\nTitle       : %s",b->bookArr[x].title);
        fprintf(fp,"\nCopies      : %d",b->bookArr[x].copies_avail);
        fprintf(fp,"\nPrice       : %d",b->bookArr[x].price);
    }

    fprintf(fp,"\n\nSort by title ascending......\n");
    sortByTitleDesc(b);
    for(int x=0;x<b->count;x++){
        fprintf(fp,"\n\n------BOOK %d------",x+1);
        fprintf(fp,"\nBook Code   : %s",b->bookArr[x].book_code);
        fprintf(fp,"\nTitle       : %s",b->bookArr[x].title);
        fprintf(fp,"\nCopies      : %d",b->bookArr[x].copies_avail);
        fprintf(fp,"\nPrice       : %d",b->bookArr[x].price);
    }

    fprintf(fp,"\n\nSort by price descending......\n");
    sortByPriceAsc(b);
    for(int x=0;x<b->count;x++){
        fprintf(fp,"\n\n------BOOK %d------",x+1);
        fprintf(fp,"\nBook Code   : %s",b->bookArr[x].book_code);
        fprintf(fp,"\nTitle       : %s",b->bookArr[x].title);
        fprintf(fp,"\nCopies      : %d",b->bookArr[x].copies_avail);
        fprintf(fp,"\nPrice       : %d",b->bookArr[x].price);
    }

    fprintf(fp,"\n\nSort by price descending......\n");
    sortByPriceDesc(b);
    for(int x=0;x<b->count;x++){
        fprintf(fp,"\n\n------BOOK %d------",x+1);
        fprintf(fp,"\nBook Code   : %s",b->bookArr[x].book_code);
        fprintf(fp,"\nTitle       : %s",b->bookArr[x].title);
        fprintf(fp,"\nCopies      : %d",b->bookArr[x].copies_avail);
        fprintf(fp,"\nPrice       : %d",b->bookArr[x].price);
    }

    fclose(fp);
}

int mainMenu(){
    printf("\n\n-----------------Menu-----------------");
    printf("\n(1) Ascending order of Title");
    printf("\n(2) Descending order of Title");
    printf("\n(3) Ascending order of Price");
    printf("\n(4) Descending order of Price");
    printf("\n(5) Print to a text file");
    printf("\n(6) Exit");
    printf("\nSelect : ");
    int x;
    scanf("%d",&x);
    return x;
}

int main()
{
    bookArray b;
    createBookArray(&b);
    inputData(&b);
    int x=0;
    while(x!=6){
        x=mainMenu();
        switch(x){
        case 1:
            sortByTitleAsc(&b);
            displayData(&b);
            break;
        case 2:
            sortByTitleDesc(&b);
            displayData(&b);
            break;
        case 3:
            sortByPriceAsc(&b);
            displayData(&b);
            break;
        case 4:
            sortByPriceDesc(&b);
            displayData(&b);
            break;
        case 5:
            printFile(&b);
            break;
        }
    }
    return 0;
}
