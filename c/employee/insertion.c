#include<stdio.h>

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int arr[10] = {9,8,7,6,5,4,3,2,1,0};
    int i;
    for (i = 1 ; i < 10 ; i++){
        int key = arr[i];
        int sIndex = i;

        while( sIndex > 0 && arr[sIndex - 1] > key ){
            arr[sIndex] = arr[sIndex - 1];
            sIndex--;
        }
        
        arr[sIndex] = key;
    }

    for(i = 0 ; i < 10 ; i++){
        printf("%d " , arr[i]);
    }
    printf("\n");
}