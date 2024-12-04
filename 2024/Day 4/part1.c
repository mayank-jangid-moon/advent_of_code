#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LEN 140

struct row{
    char* ptr;
    int len;
};

typedef struct row row;

int main(){
    FILE* fp = fopen("input.txt", "r");
    if(fp==NULL){
        printf("Error opening file!");
        exit(-1);
    }
    
    row* data = malloc(LEN*sizeof(row));
    for(int i = 0;i < LEN; i++){
        data[i].ptr = malloc(LEN*sizeof(char));
    }

    for(int j = 0; j < LEN; j++){
        for(int i = 0; i < LEN; i++){
            data[j].ptr[i] = fgetc(fp);
        }
        fgetc(fp);
    }


    // for(int j = 0; j < 140; j++){
    //     for(int i = 0; i < 140; i++){
    //     printf("%c", data[j].ptr[i]);
    //     }
    // }

    int dir[8][2] = {{1, 0}, {0, 1}, {1, 1}, {-1, -1}, {-1, 0}, {0, -1}, {-1, 1}, {1, -1}};

    int count = 0;

    for(int i = 0; i < LEN; i++){
        for(int j = 0; j < LEN; j++){
            for(int k = 0; k < 8; k++){
                if(i < LEN && i >= 0 && i+3*dir[k][0] < LEN && i+3*dir[k][0] >= 0 && j < LEN && j >= 0 && j+3*dir[k][1] < LEN && j+3*dir[k][1] >= 0){
                    if(data[i].ptr[j] == 'X' && data[i+1*dir[k][0]].ptr[j+1*dir[k][1]] == 'M' && data[i+2*dir[k][0]].ptr[j+2*dir[k][1]] == 'A' && data[i+3*dir[k][0]].ptr[j+3*dir[k][1]] == 'S'){
                        count++;
                    }
                }            
            }
        }
    }

    printf("Count is : %d\n", count);
    return 0;
}