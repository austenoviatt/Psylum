//main for testing load

#include <string>
#include <iostream>
#include <fstream>

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
    getline(saveFile, headers);
    std::cout << "These are the headers: " << headers << std::endl;



    std::string line;

    while(!saveFile.eof()) {
      saveFile >> line;
      //getline(saveFile, line);
      //std::cin >> (saveFile, line);

      std::cout << line << std::endl;
   //   std::cout << saveFile.eof();
//   std::cin >> ignore.
    }
  } else std::cout << "Error: File doesn't exist!";
}
