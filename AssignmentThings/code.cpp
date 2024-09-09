#include "ericHeader.h"
#include <array>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace eric;
using namespace std;
int main() {
  eric::files reviews=eric::files("tripadvisor_hotel_reviews.csv"); 
  //Read words and sort them based on alphabetic
  //store them according to the first alphabet using hashmap 
  // key : alphabet
  // value : dynamic array or linked list?
  std::fstream& reviewsFileStream=reviews.getFileStream();
  eric::files positiveWords = eric::files("positive-words.txt");
  bool skipHeader = true;
  std::string line;
  int lineCount = 0;

  while (std::getline(reviewsFileStream, line)) {
      // Some files have a header that you might want to skip the first line
      if (!skipHeader) {
        // The substring numbers used is to remove the unnecessary commas and
        // stuff
        line = line.substr(1, line.length() - 6);
        eric::LinkedList list = eric::lineSplit(line, ", ");
        std::cout << line << std::endl;

        Node *traverse = list.head; 

        while(traverse!=nullptr){
          std::cout<<traverse->data<<endl;
          traverse=traverse->next;
        }

        std::cin >> line;


        lineCount++;
      }
      skipHeader = false;
  }

  reviews.recordsToArray(true);
  cout<<"End of program"<<endl;
}
