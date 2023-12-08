#include<iostream>
#include<fstream>
#include<string>
using namespace std;


int calc_digs(const std::string line){
  string sumliteral = "";
  string actualdigs = "**"; 
  for (char k : line){
    if (k >= 48 && k <= 57){
      sumliteral += k;
    }
  }
  actualdigs[0] = sumliteral[0];
  actualdigs[1] = sumliteral[sumliteral.size() -1];
  int value = stoi(actualdigs, 0, 10);
  // cout << value << endl;
  return value;
}

void decode_value(const char* path, const char* out){
  FILE* file = fopen(path, "r");
  long summ = 0;
  if (file){
    const int bufferSize = 256;
    char buffer[bufferSize];
    
    while (fgets(buffer, bufferSize, file)){
      std::string bufStr = string(buffer);
      summ += calc_digs(bufStr);
    }
    cout << summ << endl;
    fclose(file);

  } else {
    perror("File couldn't be found");
  }

}

int main(){
  const char* path = "input_day1.txt";
  const char* outpath = "output_day1.txt";
  if (path == outpath) perror("Provide a different path for writing output!");
  decode_value(path, outpath);
  
  return 0;
}
