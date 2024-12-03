#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct str{
    char* ptr;
    int len;
};

typedef struct str str;

int check_digit(char ch){
    if(ch <= '9' && ch >='0'){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    FILE *fp = fopen("input.txt", "r");
    if(fp==NULL){
        printf("ERROR OPENING THE FILE!");
        exit(-1);
    }
    char ch = 0;
    str data;
    data.ptr = malloc(sizeof(char));
    int i = 0;
    while((ch = fgetc(fp)) != EOF){
        data.ptr[i] = ch;
        i++;
        data.ptr = realloc(data.ptr, (i+1)*sizeof(char));
    }
    data.len = i;
    int total_sum = 0;
    i = 0;
    while(i<data.len){
        if(!strncmp(data.ptr+i, "mul(", 4)){
            int num1 = 0;
            int num2 = 0;
            int skip = 0;
            sscanf(data.ptr+i, "mul(%d,%d)%n", &num1, &num2, &skip);
            if(skip==0){
                goto lmao;
            }
            total_sum += num1*num2;
            i += skip;
        }
        else{
            lmao: i++;
        }
    }

    printf("%d\n", total_sum);
    return 0;
}