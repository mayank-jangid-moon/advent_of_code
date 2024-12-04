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

    int count = 0;
    
    for(int i = 0; i < LEN - 1; i++){
        for(int j = 0; j < LEN - 1; j++){
            if(data[i].ptr[j] == 'A'){
                if(data[i+1].ptr[j+1] == 'S' && data[i-1].ptr[j-1] == 'M'){
                    if(data[i-1].ptr[j+1] == 'S' && data[i+1].ptr[j-1] == 'M'){
                        count++;
                    }
                    else if(data[i+1].ptr[j-1] == 'S' && data[i-1].ptr[j+1] == 'M'){
                        count++;
                    }
                }
                if(data[i-1].ptr[j-1] == 'S' && data[i+1].ptr[j+1] == 'M'){
                    if(data[i-1].ptr[j+1] == 'S' && data[i+1].ptr[j-1] == 'M'){
                        count++;
                    }
                    else if(data[i+1].ptr[j-1] == 'S' && data[i-1].ptr[j+1] == 'M'){
                        count++;
                    }
                }
            }
        }
    }

    printf("Count is : %d\n", count);
    return 0;
}