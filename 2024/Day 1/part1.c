#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define LEN 1000

void swap(int*a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int arr1[LEN];
    int arr2[LEN];
    int output = 0;
    FILE* fp = fopen("input", "rb");
    if(fp==NULL){
        printf("Error opening file!");
    }
    for(int i=0;i<LEN;i++){
        fscanf(fp, "%d", &arr1[i]);
        fscanf(fp, "%d", &arr2[i]);
    }

    for(int i=0;i<LEN;i++){
        for(int j=0;j<LEN-i-1; j++){
            if(arr1[j]>arr1[j+1]){
                swap(&arr1[j], &arr1[j+1]);
            }
            if(arr2[j]>arr2[j+1]){
                swap(&arr2[j], &arr2[j+1]);
            }
        }
    }

    for(int i=0;i<LEN;i++){
        output += abs(arr1[i] - arr2[i]);
    }

    printf("Output is : %d\n", output);
    return 0;
}