#include <stdio.h>
#include <stdlib.h>
int size;
int searching(int a[], int key){
    int result=-1;
    for(int x=0;x<size;x++){
        if(key==a[x]){
            result=a[x];
            printf("\nFound");
            break;
        }
    }
    return result;
}

int main()
{
    int a[10]={1,5,7,9,11,15,23,25,56,60};
    int key=15;
    size=sizeof(a)/sizeof(a[0]);
    int result = searching(a,key);
    printf("\n%d",result);
    return 0;
}
