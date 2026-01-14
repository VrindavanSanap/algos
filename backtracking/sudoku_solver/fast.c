// Created by Vrindavan Sanap
//
// sudoku_solver
// This program solves sudoku puzzles using backtracking
// which uses recurrsion, and DFS
// Based on https://youtu.be/G_UYXzGuqvM (Python Sudoku Solver - Computerphile
//

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void print_grid(int grid[9][9]){
  for (int row_i = 0; row_i < 9; row_i++) {
    if (row_i % 3 == 0 && row_i != 0) {
      printf("------ ");
      printf("------ ");
      printf("------ \n");
    }

    for (int col_i = 0; col_i < 9; col_i++) {
      if (col_i % 3 == 0 && col_i != 0) {
        printf("| ");
      }
      if (grid[row_i][col_i] != 0) {
        printf("%d ", grid[row_i][col_i]);
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }
 
}
bool possible (int grid[9][9], int row, int col, int value){


  // check rows
  for (int col_i = 0; col_i < 9; col_i++) {
    if (grid[row][col_i] == value) {
      return false;
    }
  }

  // check columns
  for (int row_i = 0; row_i < 9; row_i++) {
    if (grid[row_i][col] == value) {
      return false;
    }
  }

  // check boxes
  int box_row_i = (row / 3) * 3;
  int box_col_i = (col / 3) * 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (grid[box_row_i + i][box_col_i + j] == value) {
        return false;
      }
    }
  }

  return true;
}
void solve(int grid[9][9]){
  for (int row_i = 0; row_i< 9;row_i++){
    for (int  col_j= 0; col_j< 9;col_j++){
      if (grid[row_i][col_j] == 0){
        for (int val_i = 1;val_i<=9; val_i++){
          if (possible(grid, row_i, col_j, val_i)){
            grid[row_i][col_j] = val_i;
            solve(grid);
            grid[row_i][col_j] = 0;
          }
        }
      return;
      }
    }
  }
  print_grid(grid);
  exit(0);

}
int main() {
  int grid[9][9] = {
      {0, 0, 0, 8, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 4, 3},
      {5, 0, 0, 0, 0, 0, 0, 0, 0},

      {0, 0, 0, 0, 7, 0, 8, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0},
      {0, 2, 0, 0, 3, 0, 0, 0, 0},

      {6, 0, 0, 0, 0, 0, 0, 7, 5}, {0, 0, 3, 4, 0, 0, 0, 0, 0},
      {0, 0, 0, 2, 0, 0, 6, 0, 0},
  };
  print_grid(grid);
  solve(grid);
  printf("sudoku solver\n");
  return 0;
}