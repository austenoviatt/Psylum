//main for testing load

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>

void loadGame(std::string filename);

int main() {
  loadGame("testSave.csv");

  return 0;
}

std::string headers;

void loadGame(std::string filename) {
  std::ifstream saveFile;
  saveFile.open(filename);

  if(!saveFile.fail()){
    //getline(saveFile, headers);
    //std::cout << "These are the headers: " << headers << std::endl;



    std::string line, cell;
    std::vector<std::string> rowVec;
    int rowCount = 1;

    while(!saveFile.eof()) {
      //saveFile >> line;
      getline(saveFile, line);
      //std::cin >> (saveFile, line);
      std::stringstream s(line);
      int cellCount = 1;
      rowVec.clear();

      while(s >> std::ws) {
        if (s.peek() == '"') {
          s >> quoted(cell);
          std::string discard;
          std::getline(s, discard, ',')
        } else {
          getline(s, cell, ',');
        }
        rowVec.push_back(cell);
      }
      std::cout << "Row" << rowCount;
      for(int i = 1; i <= rowVec.size(); i++) {
        std::cout << "|Cell" << i << ": " << rowVec[i-1];
      }



      std::cout << line << std::endl;
   //   std::cout << saveFile.eof();
//   std::cin >> ignore.
      rowCount++;
    }
  } else std::cout << "Error: File doesn't exist!";
}
