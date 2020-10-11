#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define order 3
int main(){
  srand(time(NULL));
  vector<vector<string> > ngrams;
  //string phrase = "callyman gets gassed, you know that callyman gets gash";
  string phrase = "Windmills are the greatest threat in the US to both bald and golden eagles. Media claims fictional ‘global warming’ is worse.";

  for(int i=0; i<=phrase.length()-order; i++){
    bool found = false;
    string word = phrase.substr(i, order);
    for(int j=0; j<ngrams.size(); j++){
      if(word == ngrams[j][0]){
        found = true;
        ngrams[j].push_back(phrase.substr(i+order, 1));
        break;
      }
    }
    if(!found){
      vector<string> tmp;
      tmp.push_back(word);
      tmp.push_back(phrase.substr(i+order, 1));
      ngrams.push_back(tmp);
    }
  }

  string curr = phrase.substr(0, order);
  string result = curr;

  for(int i=0; i<1000; i++){
      for(int j=0; j<ngrams.size(); j++){
        if(ngrams[j][0] == curr){
          int randind = (rand() % (ngrams[j].size() - 1)) + 1;
          result+=ngrams[j][randind];
          curr = result.substr(result.length()-order, order);
          break;
        }
      }
  }

  cout << result << endl;

}
