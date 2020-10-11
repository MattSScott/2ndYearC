#include <iostream>
#include <vector>

using namespace std;

void printMat(vector< vector<float> > v);
void switchRows(vector< vector<float> >& v, int index);
void reduceRows(vector< vector<float> >& v, int index);
void reduceMatrix(vector< vector<float> >& v);
float deter(vector< vector<float> > v);

int main(){
  float input;
  int size;
  vector< vector<float> > v;

  cout << "enter size of matrix" << endl;
  cin >> size;

  for(int i=0; i<size; i++){
    vector<float> tmp;
    for(int j=0; j<size; j++){
      cin >> input;
      tmp.push_back(input);
    }
    v.push_back(tmp);
  }
  reduceMatrix(v);
  printMat(v);
  cout << deter(v) << endl;
}

void printMat(vector< vector<float> > v){
  cout << endl;
  for(int i=0; i<v.size(); i++){
    for(int j=0; j<v[i].size(); j++){
      cout << v[i][j] << '\t';
    }
    cout << endl;
  }
  cout << endl;
}

void switchRows(vector< vector<float> >& v, int index){
  if(v[index][index] == 0){
    for(int i=index+1; i<v.size(); i++){
      if(v[i][index]){
        vector<float> tmp = v[i];
        v[i] = v[index];
        v[index] = tmp;
        break;
      }
    }
  }
}

void reduceRows(vector< vector<float> >& v, int index){
  float piv = v[index][index];
  for(int i=index+1; i<v.size(); i++){
    if(v[i][index]){
      float fac = v[i][index] / piv;
      v[i][index] = 0;
      for(int j=index+1; j<v[i].size(); j++){
        float pivnum = v[index][j];
        v[i][j] -= fac * pivnum;
      }
    }
  }
}

void reduceMatrix(vector< vector<float> >& v){
  for(int i=0; i<v.size(); i++){
    switchRows(v, i);
    reduceRows(v, i);
    //printMat(v); //shows full steps
  }
}


float deter(vector< vector<float> > v){
  float sum = 1.0;
  for(int i=0; i<v.size(); i++){
    sum*=v[i][i];
  }
  return sum;
}
