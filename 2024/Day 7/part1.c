#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 850

struct row{
    long long int* ptr;
    long long int len;
};

typedef struct row row;

long long int check(long long int value, row list);

long long int main(){
    FILE *fp = fopen("input.txt", "r");
    FILE *fb = fopen("buffer.txt", "w+");
    if(fp==NULL || fb==NULL){
        printf("Error opening file!");
        exit(-1);
    }
    long long int output[SIZE] = {0};
    char *buffer;
    buffer = malloc(100*sizeof(char));
    long long int i = 0;
    while(fgets(buffer, 100, fp) != NULL){
        sscanf(buffer, "%lld", &output[i]);
        i++;
    }
    rewind(fp);

    // for(long long int i = 0; i < SIZE; i++){
    //     printf("%lld\n", output[i]);
    // }

    row* num = malloc(SIZE*sizeof(row));
    char* token = NULL;
    i = 0;
    char* endptr = NULL;
    for(long long int i = 0; i < SIZE; i++){
        buffer = malloc(100*sizeof(char));
        fgets(buffer, 100, fp);
        char* pos = strchr(buffer, ':');
        buffer = pos + 2;
        // printf("%s", buffer);
        long long int j = 0;
        if((token = strtok(buffer, " ")) != NULL){
            j++;
            num[i].ptr = malloc((j)*sizeof(long long int));
            num[i].ptr[j-1] = strtol(token, &endptr, 10);
        }
        else{
            continue;
        }
        
        while(token != NULL){
            token = strtok(NULL, " ");
            if(token != NULL){
                j++;
                num[i].ptr = realloc(num[i].ptr, (j)*sizeof(long long int));
                num[i].ptr[j-1] = strtol(token, &endptr, 10);
            }
        }
        num[i].len = j;
    }

    long long unsigned int answer = 0;
    
    // for(long long int i = 0; i < SIZE; i++){
    //     printf("%lld\n", num[i].len);
    // }
    for(long long int i = 0; i < SIZE; i++){
        if(check(output[i], num[i])){
            answer += output[i];
        }
    }

    printf("Answer is : %llu\n", answer);
    return 0;
}

long long int check(long long int value, row list){
    if(list.len==1){
        return value == list.ptr[0];
    }

    long long int last_element = list.ptr[list.len-1];
    list.len--;
    if(value%last_element==0 && check(value/last_element, list)){
        return 1;
    }
    if(value-last_element>=0 && check(value-last_element, list)){
        return 1;
    }
    return 0;

}