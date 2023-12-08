#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

bool isnumber(char ch){
  if (ch >= 48 && ch <= 57) return true;
  return false;
}

bool isSpecial(const char ch)
{
  if ((ch>=48 && ch<=57)||
    (ch>=65 && ch<=90)||
    (ch>=97 && ch<=122) || ch == '\n' || int(ch) == 0){
      return false;
  }
  return true;
}

void search_corners(
  vector<string> &engine, 
  vector<vector<int>> &engine_cpy, 
  int i, 
  int j
){
  if (
    (i > 0 && j > 0) && isnumber(engine[i-1][j-1])){
    engine_cpy[i-1][j-1] = 1;
  }
  if ((i > 0) && isnumber(engine[i-1][j])){
    engine_cpy[i-1][j] = 1;
  }
  if ((i > 0 && j < (engine[0].size()-1)) && isnumber(engine[i-1][j+1])){
    engine_cpy[i-1][j+1] = 1;
  }
  if ((j > 0) && isnumber(engine[i][j-1])){
    engine_cpy[i][j-1] = 1;
  }
  if ((j < (engine[0].size()-1)) && isnumber(engine[i][j+1])){
    engine_cpy[i][j+1] = 1;
  }
  if ((i < (engine.size()-1) && j > 0) && isnumber(engine[i+1][j-1])){
    engine_cpy[i+1][j-1] = 1;
  }
  if ((i < (engine.size()-1)) && isnumber(engine[i+1][j])){
    engine_cpy[i+1][j] = 1;
  }
  if ((i < (engine.size()-1) && j < (engine[0].size()-1)) && isnumber(engine[i+1][j+1])){
    engine_cpy[i+1][j+1] = 1;
  }
}

void process_engine(vector<string> &engine, vector<vector<int>> &engine_cpy){
  for (int i = 0; i < engine.size(); i++){
    for (int j = 0; j < engine[0].size(); j++){
      if ((!isnumber(engine[i][j])) && engine[i][j] != '.' && isSpecial(engine[i][j])){
        // cout << i << " , " << j << "--" << engine[i][j] << "--" << endl;
        search_corners(engine, engine_cpy, i, j);
      }
    }
  }
  string currnumber = "";
  bool numberscan = false;
  bool isPart = false;
  int totalConfig = 0;

  for (int i = 0; i < engine.size(); i++){
    for (int j = 0; j < engine[0].size(); j++){
      if (isnumber(engine[i][j])){
        if (!numberscan){
          numberscan = true;
        }
        if (engine_cpy[i][j] == 1) isPart = true;
        currnumber += engine[i][j];
      } else if (numberscan){
        if (isPart){
          cout << currnumber << endl;
          totalConfig += stoi(currnumber, 0, 10);
        }
        isPart = false;
        currnumber = "";
        numberscan = false;
      }
    }
  }
  // for (auto vec : engine_cpy){
  //   for (int k : vec){
  //     cout << k << ", ";
  //   }
  //   cout << endl;
  // }
  cout << totalConfig << endl;
}


void engine_schematic(const char * filepath){
  vector<string> engine;
  FILE* file = fopen(filepath, "r");
  if (file){
    int buffsz = 1024;
    char buff[buffsz];

    while (fgets(buff, buffsz, file)){
      string line = string(buff);
      engine.push_back(line);
    }
    vector<vector<int>> engine_cpy(
      engine.size(), 
      vector<int>(
        engine[0].size(), 
        0
      )
    );
    process_engine(engine, engine_cpy);

  } else {
    perror("Couldnt open file");

  }
  fclose(file);
}

int main(){
  const char * path = "inpday3.txt";
  engine_schematic(path);
  
  return 0;
}