#include <iostream>
#include <set>
using namespace std;
// Function to check if a given row is valid. It will return:
// -1 if the row contains an invalid value
// 0 if the row contains repeated values
// 1 is the row is valid.
int valid_row(int row, int board
  [][9]){
  set<int> s;
  for(int i = 0; i < 9; i++){
    // Checking for values outside 0 and 9; 
    // 0 is considered valid because it 
    // denotes an empty cell.
    // Removing zeros and the checking for values and
    // outside 1 and 9 is another way of doing 
    // the same thing.
    if(board
      [row][i] < 0 || board
    [row][i] > 9){
      cout<<"Invalid value"<<endl;
      return -1;
    }
    else
    { //Checking for repeated values.
      if(board
        [row][i] != 0){
        if(s.insert(board
          [row][i]).second == false){
          return 0;
        }
      }
    }
  }
  return 1;
}
// Function to check if a given column is valid. It will return:
// -1 if the column contains an invalid value
// 0 if the column contains repeated values
// 1 is the column is valid.
int valid_col(int col, int board
  [][9]){
  set<int> s;
  for(int i = 0; i < 9; i++){
    // Checking for values outside 0 and 9; 
    // 0 is considered valid because it 
    // denotes an empty cell.
    // Removing zeros and the checking for values and
    // outside 1 and 9 is another way of doing 
    // the same thing.
    if(board
      [i][col] < 0 || board
    [i][col] > 9){
      cout<<"Invalid value"<<endl;
      return -1;
    }
    else
    { // Checking for repeated values.
      if(board
        [i][col] != 0){
        if(s.insert(board
          [i][col]).second == false){
          return 0;
        }
      }
    }
  }
  return 1;
}
// Function to check if all the subsquares are valid. It will return:
// -1 if a subsquare contains an invalid value
// 0 if a subsquare contains repeated values
// 1 if the subsquares are valid.
int valid_subsquares(int board
 [][9]){
  for(int row = 0; row < 9; row = row + 3){
    for(int col = 0; col < 9; col = col + 3){
        set<int> s;
        for(int r = row; r < row + 3; r++){
          for(int c = col; c < col + 3; c++){
            // Checking for values outside 0 and 9; 
            // 0 is considered valid because it 
            // denotes an empty cell.
            // Removing zeros and the checking for values and
            // outside 1 and 9 is another way of doing 
            // the same thing.
            if(board
              [r][c] < 0 || board
            [r][c] > 9){
              cout<<"Invalid value"<<endl;
              return -1;
            }
            else{
              // Checking for repeated values
              if(board
                [r][c] != 0){
                if(s.insert(board
                  [r][c]).second == false){
                  return 0;
                }
              } 
            }
          }
        }    
    }
  }
  return 1;
}
//Function to check if the board invalid.
void valid_board(int board
 [][9]){
  for(int i = 0; i < 9; i++){
    int res1 = valid_row(i, board
      );
    int res2 = valid_col(i, board
      );
    // If a row or a column is invalid, then the board is invalid.
    if(res1 < 1 || res2 < 1){
      cout<<"The board is invalid"<<endl;
      return;
    }
  }
  // if any one the subsquares is invalid, then the board is invalid.
  int res3 = valid_subsquares(board
    );
  if(res3 < 1){
    cout<<"The board is invalid"<<endl;
  }
  else{
    cout<<"The board is valid"<<endl;
  }
}
// Function to print the board.
void print_board(int board
  [] [9]){
  for( int row = 0; row < 9; row++){
    cout<<"[";
    for(int col = 0; col < 9; col++){
      cout<<board
      [row][col]<<", ";
    }
    cout<<"]"<<endl;
  }
}
int main() {
  // A valid board.
  int board [9][9] = {
  {1, 4, 7, 0, 0, 0, 0, 0, 3},
  {2, 5, 0, 0, 0, 1, 0, 0, 0},
  {3, 0, 9, 0, 0, 0, 0, 0, 0},
  {0, 8, 0, 0, 2, 0, 0, 0, 4},
  {0, 0, 0, 4, 1, 0, 0, 2, 0},
  {9, 0, 0, 0, 0, 0, 6, 0, 0},
  {0, 0, 3, 0, 0, 0, 0, 0, 9},
  {4, 0, 0, 0, 0, 2, 0, 0, 0},
  {0, 0, 1, 0, 0, 8, 0, 0, 7},
  };
  print_board(board);
  valid_board(board);
  // An invalid board, the first row contains repeated values.
  int board2 [9][9] = {
  {1, 4, 4, 0, 0, 0, 0, 0, 3},
  {2, 5, 0, 0, 0, 1, 0, 0, 0},
  {3, 0, 9, 0, 0, 0, 0, 0, 0},
  {0, 8, 0, 0, 2, 0, 0, 0, 4},
  {0, 0, 0, 4, 1, 0, 0, 2, 0},
  {9, 0, 0, 0, 0, 0, 6, 0, 0},
  {0, 0, 3, 0, 0, 0, 0, 0, 9},
  {4, 0, 0, 0, 0, 2, 0, 0, 0},
  {0, 0, 1, 0, 0, 8, 0, 0, 7},
  };
  print_board(board2);
  valid_board(board2);
  return 0;
}