/*My code is off by 4 in answer, commented code ka answer sahi hai but idk how and why 
kisi ko pata chale toh plij bata dijiyega*/

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#define SIZE 130

typedef struct state state;

int main(){
    FILE *fp = fopen("input.txt", "r");
    if(fp==NULL){
        printf("Error opening file!");
        exit(-1);
    }
    int pos[2] = {0};
    int start_pos[2] = {0};
    char map[SIZE][SIZE] = {0};
    char original_map[SIZE][SIZE] = {0};
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
                start_pos[0] = i;
                start_pos[1] = j;
            }
        }
        fgetc(fp);
    }
    map[pos[0]][pos[1]] = '.';
    memcpy(original_map, map, sizeof(map));

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
            // printf("(%d, %d)\n", pos[0], pos[1]);
        }
        else if(map[pos[0] + dir[dir_idx][0]][pos[1] + dir[dir_idx][1]] == '#'){
            dir_idx = (dir_idx+1)%4;
        }
        else{
            break;
        }
    }
    
    
    
    int count = 0;

    for(int k = 1; k < i; k++){
        int record[SIZE][SIZE];
        memset(record, -1, sizeof(record));
        pos[0] = start_pos[0];
        pos[1] = start_pos[1];
        dir_idx = 0;
        char map_obs[SIZE][SIZE] = {0};
        memcpy(map_obs, original_map, sizeof(original_map));
        map_obs[pos_list[k][0]][pos_list[k][1]] = '#';
        while(pos[0] >= 0 && pos[1] >= 0 && pos[0] < SIZE && pos[1] < SIZE){
            if(map_obs[pos[0] + dir[dir_idx][0]][pos[1] + dir[dir_idx][1]] == '.'){
                pos[0] += dir[dir_idx][0];
                pos[1] += dir[dir_idx][1];
                if(pos[0] < 0 || pos[1] < 1 || pos[0] >= SIZE || pos[1] >= SIZE){
                    break;
                }
                if(record[pos[0]][pos[1]] == dir_idx){
                    count++;
                    break;
                }
                record[pos[0]][pos[1]] = dir_idx;
            }
            else if(map_obs[pos[0] + dir[dir_idx][0]][pos[1] + dir[dir_idx][1]] == '#'){
                dir_idx = (dir_idx+1)%4;
            }
            else{
                break;
            }
        }
    }
    

    printf("%d\n", count);

    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define SIZE 130

// int main() {
//     FILE *fp = fopen("input.txt", "r");
//     if (fp == NULL) {
//         printf("Error opening file!");
//         exit(-1);
//     }

//     int pos[2] = {0};
//     int start_pos[2] = {0};
//     char map[SIZE][SIZE] = {0};
//     char original_map[SIZE][SIZE] = {0};
//     char ch = 0;

//     // Read the map
//     for (int i = 0; i < SIZE; i++) {
//         for (int j = 0; j < SIZE; j++) {
//             ch = fgetc(fp);
//             if (ch == '.') {
//                 map[i][j] = '.';
//             } else if (ch == '#') {
//                 map[i][j] = '#';
//             } else if (ch == '^') {
//                 map[i][j] = '^';
//                 pos[0] = i;
//                 pos[1] = j;
//                 start_pos[0] = i;
//                 start_pos[1] = j;
//             }
//         }
//         fgetc(fp);
//     }
//     fclose(fp);

//     map[pos[0]][pos[1]] = '.';
//     memcpy(original_map, map, sizeof(map));

//     int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // Up, Right, Down, Left

//     int count = 0;

//     // Try placing an obstacle at every open position
//     for (int r = 0; r < SIZE; r++) {
//         for (int c = 0; c < SIZE; c++) {
//             if (original_map[r][c] != '.' || (r == start_pos[0] && c == start_pos[1])) {
//                 continue;
//             }

//             // Place the obstacle
//             char map_obs[SIZE][SIZE] = {0};
//             memcpy(map_obs, original_map, sizeof(original_map));
//             map_obs[r][c] = '#';

//             // Track visited states: position and direction
//             int visited[SIZE][SIZE][4] = {{{0}}};

//             // Reset guard position and direction
//             pos[0] = start_pos[0];
//             pos[1] = start_pos[1];
//             int dir_idx = 0;

//             while (pos[0] >= 0 && pos[1] >= 0 && pos[0] < SIZE && pos[1] < SIZE) {
//                 int new_x = pos[0] + dir[dir_idx][0];
//                 int new_y = pos[1] + dir[dir_idx][1];

//                 if (new_x < 0 || new_y < 0 || new_x >= SIZE || new_y >= SIZE) {
//                     break; // Guard exits the grid
//                 }

//                 if (map_obs[new_x][new_y] == '#') {
//                     // Turn right
//                     dir_idx = (dir_idx + 1) % 4;
//                 } else {
//                     // Move forward
//                     pos[0] = new_x;
//                     pos[1] = new_y;

//                     // Check if this state has been visited before
//                     if (visited[pos[0]][pos[1]][dir_idx] == 1) {
//                         count++;
//                         break; // Cycle detected
//                     }

//                     // Mark state as visited
//                     visited[pos[0]][pos[1]][dir_idx] = 1;
//                 }
//             }
//         }
//     }

//     printf("%d\n", count);
//     return 0;
// }
