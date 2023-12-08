#include<bits/stdc++.h>
using namespace std;

// globals
int RED = 12, GREEN = 13, BLUE = 14;
int TOTAL = RED + GREEN + BLUE;

bool match_numbers(std::string line){
  bool stats_on = false;
  unordered_map<char, int> numbers_map;
  std::string possible_number = "";
  bool cont_number = false;
  for (char k : line){
    if (stats_on){
      if (k >= 48 && k <= 57){
        cont_number = true;
        possible_number += k;
      } else{
        if (cont_number){

        }
      }
    }
    if (k == ':'){
      stats_on = true;
      continue;
    }
  }
}

void verify_sets(const char * input_path){
  FILE * file = fopen(input_path, "r");
  if (file){
    int buffersz = 512;
    char Buffer[buffersz];

    while (fgets(Buffer, buffersz, file)){
      std::string line = string(Buffer);
    }

  } else {
    perror("Couldnt open file");
  }

  
}

int main(){
  
  return 0;
}