#include<stdio.h>
#include<stdlib.h>

#define SIZE 130
int main(){
    FILE *fp = fopen("input.txt", "r");
    if(fp==NULL){
        printf("Error opening file!");
        exit(-1);
    }
    int pos[2] = {0};
    char map[SIZE][SIZE] = {0};
    char ch = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            ch =  fgetc(fp);
            if(ch == '.')
                map[i][j] = '.';
            else if(ch == '#')
                map[i][j] = '#';
            else if(ch == '^'){
                map[i][j] = '^';
                pos[0] = i;
                pos[1] = j;
            }
        }
        fgetc(fp);
    }
    map[pos[0]][pos[1]] = '.';

    // for(int i = 0; i < SIZE; i++){
    //     for(int j = 0; j< SIZE; j++){
    //         printf("%c", map[i][j]);
    //     }
    //     printf("\n");
    // }
    int **pos_list = malloc(sizeof(int*));
    pos_list[0] = malloc(2*sizeof(int));
    pos_list[0][0] = pos[0];
    pos_list[0][1] = pos[1];
    int pos_list_len = 1;
    int i = 1;
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int dir_idx = 0;
    lmao: while(pos[0] >= 0 && pos[1] >= 0 && pos[0] < SIZE && pos[1] < SIZE){
        if(map[pos[0] + dir[dir_idx][0]][pos[1] + dir[dir_idx][1]] == '.'){
            pos[0] += dir[dir_idx][0];
            pos[1] += dir[dir_idx][1];
            if(pos[0] < 0 || pos[1] < 1 || pos[0] >= SIZE || pos[1] >= SIZE){
                break;
            }
            for(int j = 0; j < i; j++){
                if(pos[0]==pos_list[j][0] && pos[1]==pos_list[j][1]){
                    goto lmao;
                }
            }
            i++;
            pos_list = realloc(pos_list, i*sizeof(int*));
            pos_list[i-1] = malloc(2*sizeof(int));
            pos_list[i-1][0] = pos[0];
            pos_list[i-1][1] = pos[1];
            printf("(%d, %d)\n", pos[0], pos[1]);
        }
        else if(map[pos[0] + dir[dir_idx][0]][pos[1] + dir[dir_idx][1]] == '#'){
            dir_idx = (dir_idx+1)%4;
        }
        else{
            break;
        }
    }
    
    printf("%d\n", i);


    


    return 0;
}