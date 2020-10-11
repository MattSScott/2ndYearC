#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

#define width 1000
#define height 400
#define resolution 20
#define rows (width / resolution)
#define cols (height / resolution)
#define iterations 200

int countNeighbours(int array[cols][rows], int x, int y);

int main(){
  srand(time(NULL));

  int grid[cols][rows];
  int next[cols][rows];

  for(int i=0; i<cols; i++){
    for(int j=0; j<rows; j++){
      grid[i][j] = rand() % 2;
    }
  }

  for(int i=0; i<cols; i++){
    for(int j=0; j<rows; j++){
      if(grid[i][j] == 0){
        std::cout << "  ";
      }
      else{
        std::cout << " * ";
      }
    }
    std::cout << std::endl;
  }

  int n = 0;

  while(n < iterations){

  system ("sleep 0.1");
  system ("clear");

  for(int i=0; i<cols; i++){
    for(int j=0; j<rows; j++){
      if(countNeighbours(grid, i, j) > 3 || countNeighbours(grid, i, j) < 2){
        if(grid[i][j] == 1){
          next[i][j] = 0;
        }
        else{
          next[i][j] = grid[i][j];
        }
      }

      else if(countNeighbours(grid, i, j) == 3){
        if(grid[i][j] == 0){
          next[i][j] = 1;
        }
        else{
          next[i][j] = grid[i][j];
        }
      }
      else{
        next[i][j] = grid[i][j];
      }
    }
  }

  for(int i=0; i<cols; i++){
    for(int j=0; j<rows; j++){
      if(next[i][j] == 0){
        std::cout << "  ";
      }
      else{
        std::cout << " * ";
      }
    }
    std::cout << std::endl;
  }
  n++;

  for(int i=0; i<cols; i++){
    for(int j=0; j<rows; j++){
        grid[i][j] = next[i][j];
      }
    }
  }

  return 0;
}

int countNeighbours(int array[cols][rows], int x, int y){
  int sum = 0;
  for(int i=-1; i<2; i++){
    for(int j=-1; j<2; j++){
      int xx = (x + i + cols) % cols;
      int yy = (y + j + rows) % rows;
      sum+=array[xx][yy];
    }
  }
  return (sum - array[x][y]);
}
