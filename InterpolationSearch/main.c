#include <stdio.h>
#include <stdlib.h>
int size;
int searching(int a[], int key){
    int start = 0;
    int end = size-1;
    int middle = start+(end-start)*((key-a[start])/(a[end]-a[start]));
    while(key!=a[middle]&&start<=end){
        if(key>a[middle]){
            start=middle+1;
        }else{
            end=middle-1;
        }
        middle = start+(end-start)*((key-a[start])/(a[end]-a[start]));
    }
    if(key==a[middle]){
        printf("\nFound");
        return a[middle];
    }else{
        printf("\nCouldnt find");
        return -1;
    }
}

int main()
{
    int a[10]={1,5,7,9,11,15,23,25,56,60};
    int key=5;
    size=sizeof(a)/sizeof(a[0]);
    int result = searching(a,key);
    printf("\n%d",result);
    return 0;
}
