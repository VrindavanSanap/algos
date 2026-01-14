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
bool is_leaf_node(int grid[9][9]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (grid[i][j] == 0) {
        return false;
      }
    }
  }
  return true;
}
void print_grid(int grid[9][9]) {
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

bool is_valid(int grid[9][9]) {
  // returns true if the given grid is valid

  // check 9 rows
  for (int row_i = 0; row_i < 9; row_i++) {
    bool boxes[9] = {false};
    for (int box_i = 0; box_i < 9; box_i++) {
      int val = grid[row_i][box_i] - 1;
      if (val != -1) {
        if (boxes[val] == true) {
          return false;
        } else {
          boxes[val] = true;
        }
      }
    }
  }

  // check 9 columns
  for (int col_i = 0; col_i < 9; col_i++) {
    bool boxes[9] = {false};
    for (int box_i = 0; box_i < 9; box_i++) {
      int val = grid[box_i][col_i] - 1;
      if (val != -1) {
        if (boxes[val] == true) {
          return false;
        } else {
          boxes[val] = true;
        }
      }
    }
  }

  // check 9 boxes
  for (int offset_i = 0; offset_i < 9; offset_i += 3) {
    for (int offset_j = 0; offset_j < 9; offset_j += 3) {
      bool boxes[9] = {false};
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

          int val = grid[offset_i + i][offset_j + j] - 1;
          if (val != -1) {
            if (boxes[val] == true) {
              return false;
            } else {
              boxes[val] = true;
            }
          }
        }
      }
    }
  }
  return true;
}
void get_first_empty(int grid[9][9], int *row, int *col) {
  for (int row_i = 0; row_i < 9; row_i++) {
    bool found = false;
    for (int col_i = 0; col_i < 9; col_i++) {
      if (grid[row_i][col_i] == 0) {
        found = true;
        *row = row_i;
        *col = col_i;
        break;
      }
    }
    if (found) {
      break;
    }
  }
}
void solve(int grid[9][9]) {
  if (is_leaf_node(grid)) {
    if (is_valid(grid)) {
      print_grid(grid);
      fflush(stdout);
      exit(0);
      return;
    }
  }
  if (!is_valid(grid)) {
    return;
  }

  int row_i, col_i;
  get_first_empty(grid, &row_i, &col_i);
  for (int i = 1; i <= 9; i++) {
    grid[row_i][col_i] = i;
    solve(grid);
  }
  grid[row_i][col_i] = 0;
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