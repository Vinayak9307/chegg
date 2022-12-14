#include<stdio.h>

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int arr[10] = {9,8,7,6,5,4,3,2,1,0};
    int i,j;
    for (i = 0 ; i < 9 ; i++){
        int min = arr[i];
        int minIndex = i;
        for(j = i + 1 ; j < 10 ; j++){
            if(min > arr[j]){
                min = arr[j];
                minIndex = j;
            }
        }
        swap(&arr[i] , &arr[minIndex]);
    }

    for(i = 0 ; i < 10 ; i++){
        printf("%d " , arr[i]);
    }
    printf("\n");
}