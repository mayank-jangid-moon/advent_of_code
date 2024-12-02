#include<stdio.h>

#define LEN 1000

int main(){
    int arr1[LEN];
    int arr2[LEN];
    int score = 0;
    FILE* fp = fopen("input", "rb");
    if(fp==NULL){
        printf("Error opening file!");
    }
    for(int i=0;i<LEN;i++){
        fscanf(fp, "%d", &arr1[i]);
        fscanf(fp, "%d", &arr2[i]);
    }

    for(int i=0;i<LEN; i++){
        int count = 0;
        for(int j=0;j<LEN;j++){
            if(arr1[i]==arr2[j]){
                count++;
            }
        }
        score += arr1[i]*count;
    }

    printf("Score is : %d\n", score);
    return 0;
}