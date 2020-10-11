#include <iostream>
#include <string>

using namespace std;

int decipher(string n){
  if(n.length() == 1){
    return 1;
  }
  else if(n.length() == 2 && stoi(n)<=26){
    return 2;
  }
  else if(n.length() == 2 && stoi(n)>26){
    return 1;
  }
  else{
    int count = 1;
    for(int i=2; i<n.length(); i++){
      count+= (decipher(n.substr(0,i)) * decipher(n.substr(i, n.length()-i)));
    }
    return count;
  }
}

int main(){
  string s = "1234";
  cout << decipher(s) << endl;
  // for(int i=1; i<s.length(); i++){
  //   cout << s.substr(0,i) << " " << s.substr(i, s.length()-i) << endl;
  // }
  return 0;
}
