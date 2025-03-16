#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define N 3

int board[N][N] = {
    {9, 0, 1},
    {2, 5, 0},
    {7, 0, 3}};

// int board[N][N] = {
//     {1, 2, 3, 4, 5, 6, 7, 8, 9},
//     {4, 5, 6, 7, 8, 9, 1, 2, 3},
//     {7, 8, 9, 1, 2, 3, 4, 5, 6},
//     {2, 3, 4, 5, 6, 7, 8, 9, 1},
//     {5, 6, 7, 8, 9, 1, 2, 3, 4},
//     {8, 9, 1, 2, 3, 4, 5, 6, 7},
//     {3, 4, 5, 6, 7, 8, 9, 1, 2},
//     {6, 7, 8, 9, 1, 2, 3, 4, 5},
//     {9, 1, 2, 3, 4, 5, 6, 7, 8}};


bool hasDuplicates(int arr[N],bool isrow, int index){
    int count[10];
    bool mark[N] = {false};
    memset(count,0,sizeof(count));
    for(int i = 0; i < N; i++){
        if (arr[i] < 1 || arr[i] > 9) continue; 
        count[arr[i]]++;
        if(count[arr[i]] > 1){
            mark[i] = true;
        }
    }

    for(int i = 0; i < N; i++){
        if(mark[i]){
            if(isrow){
                board[i][index] = 0;
            }
            else{
                board[index][i] = 0;
            }
        }
    }

    return false;
}


//problem in here
void check_columns(){
    for(int i = 0; i<N;i++){
        int column[N];
        for(int k = 0; k<N;k++){
            column[k] = board[i][k];
        }
        hasDuplicates(column,false,i);
    }
}

void check_rows(){
    for(int i = 0; i<N;i++){
        int rows[N];
        for(int k = 0; k<N;k++){
            rows[k] = board[k][i];
        }
        hasDuplicates(rows,true,i);
    }
}

void checkbox(int startrow, int startcol){
    bool seen[10] = {false}; 
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int num = board[startrow + i][startcol + j];
            
            if(num < 1 || num > 9) continue; 
            if(seen[num]){ 
                board[startrow + i][startcol + j] = 0;
            } else {
                seen[num] = true;
            }
        }
    }
}
//fix this

void isValidBoxes(){
    for(int row = 0; row<N; row+=3){
        for(int col = 0;col<N;col+=3){
            checkbox(row, col);
        }
    }
}

// bool isValidSudoku() {
//     return check_rows() && check_columns() && isValidBoxes();
// }

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// bool solveSudoku()

int main(){
    printBoard();
    //check for procedures
    isValidBoxes();
    check_rows();
    check_columns();
    //check for procedures
    printBoard();
}
//first validate each number, and return false if not
//if invalid, remove from, sudoku board
//fil numbers 1-9, check if valid every timesos
//If invalid, backtrack to the last number 



//Find the next empty cell (marked with 0).
//Try placing digits 1 to 9 in the cell.
//Check if placing a number is valid based on the Sudoku rules (no duplicate in the same row, column, or 3x3 subgrid).
//Recursively attempt to solve the rest of the board with this new placement.
//If a solution is not found, backtrack by resetting the cell to 0 and trying the next number.
//Terminate when the board is completely filled with valid numbers.