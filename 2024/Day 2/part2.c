#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define LEN 1000

struct array {
    int* ptr;
    int len;
};

typedef struct array array;

array* remove_element(array row, int index){
    array* new_row = malloc(sizeof(array));
    new_row->ptr = malloc((row.len)*sizeof(int));
    for(int i = 0;i<row.len;i++){
        new_row->ptr[i] = row.ptr[i];
    }
    new_row->len = row.len;
    for(int i = index; i < new_row->len - 1; i++){
        new_row->ptr[i] = new_row->ptr[i+1];
    }
    new_row->len--;
    return new_row;
}

int check_row(array* row){
    int flag1 = 0;
    int flag2 = 0;
    for(int j = 0; j < row->len - 1; j++){
        if(!((row->ptr[j] - row->ptr[j+1] <= 3 && row->ptr[j] - row->ptr[j+1] >= 1) || (row->ptr[j] - row->ptr[j+1] >= -3 && row->ptr[j] - row->ptr[j+1] <= -1))){
            break;
        }
        if(row->ptr[j]>row->ptr[j+1]){
            flag1++;
        }
        else if(row->ptr[j]<row->ptr[j+1]){
            flag2++;
        }
    }
    if(flag1 == row->len - 1 || flag2 == row->len - 1){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    FILE *fp = fopen("input.txt", "r");
    if(fp==NULL){
        printf("Error opening file!");
        exit(-1);
    }

    char buffer[100];
    array* data = malloc(LEN*sizeof(array));
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
        if(check_row(&data[i])){
            count++;
        }
        else{
            for(int j = 0; j<data[i].len; j++){
                array* rm_row = remove_element(data[i], j);
                if(check_row(rm_row)){
                    count++;
                    break;
                }
            }
        }
    }

    printf("Number of Safe Records are: %d\n", count);
    return 0;
}