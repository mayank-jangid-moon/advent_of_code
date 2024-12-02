#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define LEN 1000

struct row {
    int* ptr;
    int len;
};

typedef struct row row;

int main(){
    FILE *fp = fopen("input.txt", "r");
    if(fp==NULL){
        printf("Error opening file!");
        exit(-1);
    }

    char buffer[100];
    row* data = malloc(LEN*sizeof(row));
    int temp = 0;
    int i = 0;
    

    while(fgets(buffer, 100, fp)){
        int count = 0;
        int j = 0;
        FILE *buf = fopen("buffer.txt", "w+");
        if(buf==NULL){
            printf("Error opening buffer!");
            exit(-1);
        }
        fputs(buffer, buf);
        fflush(buf);
        rewind(buf);
        while(fscanf(buf, "%d", &temp) != -1){
            count++;
            data[i].ptr=realloc(data[i].ptr, count*sizeof(int));
            (data[i].ptr)[j]=temp;
            // printf("%d ", data[i].ptr[j]);
            j++;            
        }
        data[i].len = count;
        i++;
        // printf("\n");
    }
    
    int count = 0;
    for(int i = 0; i < LEN; i++){
        int flag1 = 0;
        int flag2 = 0;
        for(int j = 0; j < data[i].len - 1; j++){
            if(!((data[i].ptr[j] - data[i].ptr[j+1] <= 3 && data[i].ptr[j] - data[i].ptr[j+1] >= 1) || (data[i].ptr[j] - data[i].ptr[j+1] >= -3 && data[i].ptr[j] - data[i].ptr[j+1] <= -1))){
                break;
            }
            if(data[i].ptr[j]>data[i].ptr[j+1]){
                flag1++;
            }
            else if(data[i].ptr[j]<data[i].ptr[j+1]){
                flag2++;
            }
        }
        if(flag1 == data[i].len - 1 || flag2 == data[i].len - 1){
            count++;
        }
    }

    printf("Number of Safe Records are: %d\n", count);
    return 0;
}