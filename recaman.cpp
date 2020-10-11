#include <iostream>
#include <vector>

bool valid(std::vector<int> v, int val);

int main(){
  int step = 1;
  int val = 0;
  std::vector<int> valprev;
  valprev.push_back(0);
  for(int i=0; i<20; i++){
    if(val-step<0 || valid(valprev, val-step)){
      val += step;
      valprev.push_back(val);
      step++;
    }
    else{
      val -= step;
      valprev.push_back(val);
      step++;
    }
    std::cout << val << " ";
  }
  std::cout << std::endl;
  return 0;
}

bool valid(std::vector<int> v, int val){
  for(int i=0; i<v.size(); i++){
    if(v[i] == val){
      return true;
    }
  }
  return false;
}
