#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

#define RES 12;

int main(){
  int grid[30][30];

  for(int i=0; i<30; i++){
    for(int j=0; j<30; j++){
      grid[i][j] = 0;
    }
  }

  int r = 8;

  float increment = 2*M_PI / RES;

  for(float theta = 0; theta<2*M_PI; theta+=increment){
    int x = round(r * cos(theta)) + 15;
    int y = round(r * sin(theta)) + 15;
    grid[x][y] = 1;
  }

  for(int j=0; j<30; j++){
    for(int i=0; i<30; i++){
      if(grid[i][j]){
        cout << "*";
      }
      else{
        cout << "  ";
      }
    }
    cout << endl;
  }


  return 0;
}
