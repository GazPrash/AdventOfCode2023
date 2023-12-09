#include<bits/stdc++.h>

using namespace std;

string string_partition(string line, char target){
  stringstream linestream(line);
  std::string segment;
  std::vector<std::string> seglist;
  while(getline(linestream, segment, target))
  {
    seglist.push_back(segment);
  }
  return seglist[1];
}

tuple<vector<int>, vector<int>> get_numbers(string line){
  vector<int> win_nums, your_nums;
  bool number_on = false;
  bool winning = true;
  string tempNum = "";

  for (char ch : line){
    if (ch == '|') winning = false;
    if (isdigit(ch)){
      if (number_on) tempNum += ch;
      else{
        number_on = true;
        tempNum = "";
        tempNum += ch;
      }
    } else if (number_on){
      int cardno = stoi(tempNum, 0, 10);
      if (winning){
        win_nums.push_back(cardno);
      } else your_nums.push_back(cardno);

      number_on = false;
      tempNum = "";
    }
  }
  // for (int k : win_nums){
  //   cout << k << ", ";
  // }
  // cout << "\n";
  // for (int k : your_nums){
  //   cout << k << ", ";
  // }

  return {win_nums, your_nums};
}

int total_scratchcards(tuple<vector<int>, vector<int>> card_num){
  vector<int> your_nums = get<1>(card_num);
  bool first_found = false;
  int score = 0;
  for (int n : get<0>(card_num)){
    if (find(your_nums.begin(), your_nums.end(), n) != your_nums.end()){
      if (!first_found){
        score++;
        first_found = true;
      }
      else score *= 2;
    }
  }
  return score;
}

void calculate_scratchcard(const char* path){
  int TotalPoints = 0;
  FILE * file = fopen(path, "r");
  if (file){
    int bfsz = 512;
    char buffer[bfsz];

    while (fgets(buffer, bfsz, file)){
      string line = string(buffer);
      string break_line = string_partition(line, ':');
      tuple<vector<int>, vector<int>> card_numbers = get_numbers(break_line);
      // card_numbers[0];
      // cout << game_points(card_numbers) << endl;
      TotalPoints += total_scratchcards(card_numbers);
    }
  } else{
    perror("Couldnt open file");
  }
  cout << TotalPoints << endl;
  fclose(file);
}


int main(){
  const char * path = "inpday4.txt";
  calculate_scratchcard(path);


  return 0;
}