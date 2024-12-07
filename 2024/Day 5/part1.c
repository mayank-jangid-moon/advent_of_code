/*INCOMPLETE*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NUM_PAGE 6
#define NUM_RULES 21
struct row{
    int* ptr;
    int len;
};

typedef struct row row;

int main(){
    FILE* fr = fopen("rules.txt", "r");
    FILE *fp = fopen("pages.txt", "r");
    if(fp == NULL || fr == NULL){
        printf("Error handling files!");
        exit(-1);
    }
    int rule1 = 0, rule2 = 0, check = 0, i = 0;
    char buf[100] = {0};
    row* rules = malloc(sizeof(row));
    rules[0].ptr = malloc(2*sizeof(int));
    while(fgets(buf, 10, fr) != NULL){
        sscanf(buf, "%d|%d%n", &rule1, &rule2, &check);
        rules[i].ptr[0] = rule1;
        rules[i].ptr[1] = rule2;
        rules[i].len = 2;
        i++;
        rules = realloc(rules, (i+1)*sizeof(row));
        rules[i].ptr = malloc(2*sizeof(int));
    }
    free(rules[i].ptr);
    rules = realloc(rules, i*sizeof(row));

    // printf("%d %d\n", rules[20].ptr[0], rules[20].ptr[1]);
    char ch = '\0';
    row* pages = malloc(sizeof(row));
    pages[0].ptr = NULL;
    int temp = 0;
    int j = 0;
    while(fgets(buf, 100, fp) != NULL){
        int i = 0;
        char* token = strtok(buf, ",");
        pages[j].ptr = realloc(pages[j].ptr, (i + 1)*sizeof(int));
        char* endptr = '\0';
        pages[j].ptr[i] = strtol(token, &endptr, 10);
        i++;
        
        while((token = strtok(NULL, ",")) != NULL){
            pages[j].ptr = realloc(pages[j].ptr, (i + 1)* sizeof(int));
            pages[j].ptr[i] = strtol(token, &endptr, 10);
            i++;  
        }
        pages[j].len = i;
        j++;
        pages = realloc(pages, (j+1)*sizeof(row));
    }
    pages = realloc(pages, j*sizeof(row));

    // printf("%d\n", pages[5].ptr[4]);
    
    
    for(int i = 0; i < NUM_PAGE; i++){
        int flag1 = 0;
        int flag2 = 0;
        int flag1_loc = 0;
        int flag2_loc = 0;
        for(int j = 0; j < pages[i].len; j++){
            for(int k = 0; k < NUM_RULES; k++){
                if(pages[i].ptr[j] == rules[k].ptr[0]){
                    flag1 = 1;
                    flag1_loc = j;
                }
                else if(pages[i].ptr[j] == rules[k].ptr[1]){
                    flag2 = 1;
                    flag2_loc = j;
                }
            }
            if(flag1_loc < flag2_loc){

            }
        }
    }
    return 0;
}