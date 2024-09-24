#include "ericHeader.h"
#include <array>
#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace eric;
using namespace std;
using namespace chrono;
int main() {
  eric::files reviews = eric::files("tripadvisor_hotel_reviews.csv");
  // eric::files reviews=eric::files("test.csv");
  // Read words and sort them based on alphabetic
  // store them according to the first alphabet using hashmap
  // key : alphabet
  // value : dynamic array or linked list?
  std::fstream &reviewsFileStream = reviews.getFileStream();

  eric::files positiveWordsFile = eric::files("positive-words.txt");
  std::fstream &positiveWordsFileStream = positiveWordsFile.getFileStream();
  eric::LinkedListSentimentWords positiveWords =
      eric::LinkedListSentimentWords();

  eric::files negativeWordsFile = eric::files("negative-words.txt");
  std::fstream &negativeWordsFileStream = negativeWordsFile.getFileStream();
  eric::LinkedListSentimentWords negativeWords =
      eric::LinkedListSentimentWords();

  // Probably iterate through positive-words.txt and store them into
  // positiveWords as a 2d array I'll do a linked list implementation first

  std::string word;
  while (std::getline(positiveWordsFileStream, word)) {
    positiveWords.addWord(word);
  }

  while (std::getline(negativeWordsFileStream, word)) {
    negativeWords.addWord(word);
  }

  // User CLI?
  std::cout << "╔═════════════════════════════════════════════════════════════════╗\n";
  std::cout << "║ ██╗    ██╗███████╗██╗      ██████╗ ██████╗ ███╗   ███╗███████╗  ║\n";
  std::cout << "║ ██║    ██║██╔════╝██║     ██╔════╝██╔═══██╗████╗ ████║██╔════╝  ║\n";
  std::cout << "║ ██║ █╗ ██║█████╗  ██║     ██║     ██║   ██║██╔████╔██║█████╗    ║\n";
  std::cout << "║ ██║███╗██║██╔══╝  ██║     ██║     ██║   ██║██║╚██╔╝██║██╔══╝    ║\n";
  std::cout << "║ ╚███╔███╔╝███████╗███████╗╚██████╗╚██████╔╝██║ ╚═╝ ██║███████╗  ║\n";
  std::cout << "║  ╚══╝╚══╝ ╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝  ║\n";
  std::cout << "╚═════════════════════════════════════════════════════════════════╝\n";
  std::cout << "1. Choose a line to compare\n";
  std::cout << "2. Check Linked List Speed\n";
  std::cout << "3. Check Linked List Speed with Display Output\n";
  std::cout << "   *Note: It compares every line\n";
  // std::cout << "4. "

  int option;
  std::cin>>option;
  if(option>3 || option<1){
    std::cout<<"Number not appropriate, default to 2"<<endl;
    option=2;
  }
  int chosenLine=-1;

  if(option==1){
    std::cout << "Please enter the line number:\n";
    std::cin >> chosenLine; 
  }else{
    std::cout << "Please wait as the program runs. Usually takes 46 seconds\n"<<endl;
  }


  bool skipHeader = true;
  // bool skipHeader = false;
  int lineCount = 0;
  std::string line;
  auto start = high_resolution_clock::now();

  //PROGRESS BAR CODE

  float progress = 0.0;
  int barWidth = 67;
  while (std::getline(reviewsFileStream, line)) {
    // Some files have a header that you might want to skip the first line
    if (!skipHeader) {
      
    //PROGRESS BAR CODE

    std::cout << "[";
    int pos = barWidth * progress;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) std::cout << "=";
        else if (i == pos) std::cout << ">";
        else std::cout << " ";
    }
    std::cout << "] " << int(progress * 100.0) << " %\r";
    std::cout.flush();

    progress += 1.0/20490.0;

    // The substring numbers used is to remove the unnecessary commas and
    // stuff
    int csvSentimentScore = std::stoi(line.substr(line.length() - 1, line.length()));
    line = line.substr(1, line.length() - 6);
    eric::LinkedList list = eric::lineSplit(line, ", ");
    // std::cout << line << std::endl;
    // printList(list.head);
    eric::mergeSort(&list.head);
    // insertionSort(&list.head);
    // printList(list.head);

    // cin>>line;
    if(chosenLine==-1 || chosenLine==lineCount+1){
      double score = eric::findMatchingWord(list.head, positiveWords.data.head,
                                          negativeWords.data.head,option);

      int convertedScore = int(score);

      if(option!=2){
        eric::compareScore(convertedScore, csvSentimentScore);
      }
      if(chosenLine==lineCount+1){
        break;
      }
    }

    // std::cin >> line;
    // cout<<lineCount<<endl;
    lineCount++;
    }
    skipHeader=false;
  }

  // reviews.recordsToArray(true);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  if(chosenLine==-1){
    cout << "Time taken: " << duration.count() << " microseconds" << endl;
  }
  cout << "End of program" << endl;
}
