#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

#define GRIDSZ 40
#define RES 40

int main(){

  int grid[GRIDSZ][GRIDSZ][GRIDSZ];

  for(int i=0; i<GRIDSZ; i++){
    for(int j=0; j<GRIDSZ; j++){
      for(int k=0; k<GRIDSZ; k++){
      grid[i][j][k] = 0;
    }
  }
}

  int r = GRIDSZ/4;

  float iinc = M_PI / RES;
  float pinc = 2*M_PI / RES;

  for(float phi =0; phi<2*M_PI; phi+=pinc){
  for(float theta = 0; theta<M_PI; theta+=iinc){
    int x = round(r * sin(theta) * cos(phi)) + GRIDSZ/2;
    int y = round(r * sin(theta) * sin(phi)) + GRIDSZ/2;
    int z = round(r * cos(theta)) + GRIDSZ/2;
    grid[x][y][z] = 1;
  }
}

for(int k=0; k<GRIDSZ; k++){
  for(int j=0; j<GRIDSZ; j++){
    for(int i=0; i<GRIDSZ; i++){
      if(grid[i][j][k]){
        cout << "*";
      }
      else{
        cout << "  ";
      }
    }
    cout << endl;
  }
}

  // for(int i=0; i<GRIDSZ; i++){
  //   for(int i=0; i<GRIDSZ; i++){
  //     for(int j=0; j<GRIDSZ; j++){
  //       cout << grid[i][j][k];
  //     }
  //   }
  // }



  return 0;
}
