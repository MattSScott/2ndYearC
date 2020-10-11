#include <iostream>
#include <cmath>

#define SIZE 100
#define INDENT 10
#define JULX 0.1
#define JULY 0.1

struct complex{
  float real;
  float imag;

  float mag(){
    return std::sqrt(this->real*this->real + this->imag*this->imag);
  }

  bool equal(complex c){
    if(real == c.real && imag == c.imag){
      return true;
    }
    return false;
  }
};

complex mult(complex c1, complex c2){
  complex result = {c1.real*c2.real - c1.imag*c2.imag, c1.real*c2.imag + c1.imag*c2.real};
  return result;
}

// std::string mandelbrot(complex z){
//   int steps = 0;
//   while(z.mag() < 100){
//     z = mult(z,z);
//     steps++;
//     if(steps == 10 || z.equal(mult(z,z))){
//       return "STABLE";
//     }
//   }
//   return "UNSTABLE IN " + std::to_string(steps) + " STEP(S)";
// }

bool mandelbrot(complex c){
  complex z = {JULX,JULY};
  for(int i=0; i<100; i++){
    z = mult(z,z);
    z.real+=c.real;
    z.imag+=c.imag;
    if(z.mag() > 100){
      return false;
    }
    else if(z.equal(mult(z,z))){
      return true;
    }
  }
  return true;
}


int main(){

 int grid[SIZE+1][2*SIZE+1];

  for(int i=-SIZE/2; i<=SIZE/2; i++){
    for(int j=-(SIZE+INDENT); j<=SIZE-INDENT; j++){
      complex z = {j*0.02, i*0.02};
      if(mandelbrot(z)){
        grid[i+SIZE/2][j+SIZE+INDENT] = 1;
      }
      else{
        grid[i+SIZE/2][j+SIZE+INDENT] = 0;
      }
    }
  }

  for(int i=-SIZE/2; i<=SIZE/2; i++){
    for(int j=-(SIZE+INDENT); j<=SIZE-INDENT; j++){
      if(grid[i+SIZE/2][j+SIZE+INDENT]){
        std::cout << '*';
      }
      else{
        std::cout << ' ';
      }
    }
    std::cout << std::endl;
  }

  return 0;
}
