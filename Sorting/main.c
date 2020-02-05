#include <stdio.h>
#include <stdlib.h>
int size;
void bubbleSort(int a[]){
    int temp;
    for(int x=0;x<size;x++){
        for(int y=0;y<size-x-1;y++){
            if(a[y]>a[y+1]){
                temp=a[y];
                a[y]=a[y+1];
                a[y+1]=temp;
            }
        }
    }
    printArray(a);
}

void selectionSort(int a[]){
    int temp;
    int smallest;
    for(int x=0;x<size;x++){
        smallest = x;
        for(int y=x+1;y<size;y++){
            if(a[smallest]<a[y]){
                smallest=y;
            }
        }
        if(x!=smallest){
            temp=a[x];
            a[x]=a[smallest];
            a[smallest]=temp;
        }
    }
    printArray(a);
}

void insertionSort(int a[]){
    int temp;
    for(int x=1;x<size;x++){
        temp=a[x];
        for(int y=x-1;y>=0 &&temp>a[y];y--){
            a[y+1]=a[y];
            a[y]=temp;
        }
    }
    printArray(a);
}

void mergeSort(int a[]){

}

void quickSort(int a[]){

}

void radixSort(int a[]){

}

void printArray(int a[]){
    for(int x=0;x<size;x++){
        printf("%d ",a[x]);
    }

}

int main()
{
    int a[10]={5,60,15,20,30,1,23,25,45,2};
    size=sizeof(a)/sizeof(a[0]);
    //bubbleSort(a);
    selectionSort(a);
    //insertionSort(a);

    return 0;
}
