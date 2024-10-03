#include "ericHeader.h"
#include <array>
#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

//An idea, if we halved the positive and negative words, since the review is sorted,
// once it reaches the half point, we start to only check with half instead
// We can probably use a reference of allPositiveWords and add inside findMatchingWord 
// function instead of reiterating again to add into it

using namespace eric;
using namespace std;
using namespace chrono;
int main() {

  //Opening the files
  eric::files reviews = eric::files("tripadvisor_hotel_reviews.csv");
  std::fstream &reviewsFileStream = reviews.getFileStream();

  eric::files positiveWordsFile = eric::files("positive-words.txt");
  std::fstream &positiveWordsFileStream = positiveWordsFile.getFileStream();
  eric::LinkedListSentimentWords positiveWords =
      eric::LinkedListSentimentWords();
  eric::LinkedListSentimentWords positiveWordsHalf =
      eric::LinkedListSentimentWords();

  eric::files negativeWordsFile = eric::files("negative-words.txt");
  std::fstream &negativeWordsFileStream = negativeWordsFile.getFileStream();
  eric::LinkedListSentimentWords negativeWords =
      eric::LinkedListSentimentWords();
  eric::LinkedListSentimentWords negativeWordsHalf =
      eric::LinkedListSentimentWords();


  // Storing sentiment words into a linked list first
  // I manually determined the half way point
  // positive halfway point is 1003
  // negative halfway point is 2391
  std::string word;
  int count=0;
  while (std::getline(positiveWordsFileStream, word)) {
    count++;
    if(count<1003){
        positiveWords.addWord(word);
    }else{
      positiveWordsHalf.addWord(word);
    }
  }
  count=0;
  while (std::getline(negativeWordsFileStream, word)) {
    count++;
    if(count<2391){
      negativeWords.addWord(word);
    }else{
      negativeWordsHalf.addWord(word);
    }
  }

  // while (std::getline(positiveWordsFileStream, word)) {
  //   positiveWords.addWord(word);
  // }
  // while (std::getline(negativeWordsFileStream, word)) {
  //     negativeWords.addWord(word);
  // }


  // User CLI?
  std::cout << "╔═════════════════════════════════════════════════════════════════╗\n";
  std::cout << "║                ██████╗ ███████╗████████╗██████╗                 ║\n";
  std::cout << "║                ██╔══██╗██╔════╝╚══██╔══╝██╔══██╗                ║\n";
  std::cout << "║                ██║  ██║███████╗   ██║   ██████╔╝                ║\n";
  std::cout << "║                ██║  ██║╚════██║   ██║   ██╔══██╗                ║\n";
  std::cout << "║                ██████╔╝███████║   ██║   ██║  ██║                ║\n";
  std::cout << "║                ╚═════╝ ╚══════╝   ╚═╝   ╚═╝  ╚═╝                ║\n";
  std::cout << "║                                                                 ║\n";
  std::cout << "║            ██████╗  █████╗ ██████╗ ████████╗     ██╗            ║\n";
  std::cout << "║            ██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝    ███║            ║\n";
  std::cout << "║            ██████╔╝███████║██████╔╝   ██║       ╚██║            ║\n";
  std::cout << "║            ██╔═══╝ ██╔══██║██╔══██╗   ██║        ██║            ║\n";
  std::cout << "║            ██║     ██║  ██║██║  ██║   ██║        ██║            ║\n";
  std::cout << "║            ╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝        ╚═╝            ║\n";
  std::cout << "║                                                                 ║\n";
  std::cout << "║ ██████╗ ██████╗  ██████╗ ██╗   ██╗██████╗      █████╗ ██████╗   ║\n";
  std::cout << "║ ██╔════╝ ██╔══██╗██╔═══██╗██║   ██║██╔══██╗    ██╔══██╗██╔══██╗ ║\n";
  std::cout << "║ ██║  ███╗██████╔╝██║   ██║██║   ██║██████╔╝    ███████║██████╔╝ ║\n";
  std::cout << "║ ██║   ██║██╔══██╗██║   ██║██║   ██║██╔═══╝     ██╔══██║██╔══██╗ ║\n";
  std::cout << "║ ╚██████╔╝██║  ██║╚██████╔╝╚██████╔╝██║         ██║  ██║██████╔╝ ║\n";
  std::cout << "║  ╚═════╝ ╚═╝  ╚═╝ ╚═════╝  ╚═════╝ ╚═╝         ╚═╝  ╚═╝╚═════╝  ║\n";
  std::cout << "╚═════════════════════════════════════════════════════════════════╝\n"; 
  std::cout << "1. Choose a line to compare score\n";
  std::cout << "2. Check Linked List Speed\n";
  std::cout << "3. Check Linked List Speed with Display Output\n";
  std::cout << "   *Note: It compares every line\n";

  //USER OPTIONS
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
    std::cout << "Please wait as the program runs. Usually takes 23 seconds\n"<<endl;
  }

  bool skipHeader = true;
  int lineCount = 0;
  std::string line;
  auto start = high_resolution_clock::now();
  //Variables to do analysis later
  int totalPositiveWords=0;
  int totalNegativeWords=0;
  eric::LinkedList allWordsFound;
  eric::LinkedList calculatedScores;
  eric::LinkedList csvScores;

  while (std::getline(reviewsFileStream, line)) {
    // Some files have a header that you might want to skip the first line
    if (!skipHeader) {
    
    if(chosenLine==lineCount+1){
      //Show the user their chosen line
      std::cout<<line<<endl;
      std::cout<<"\n"<<endl;
    }

    // The substring numbers used is to remove the unnecessary commas and
    // stuff
    int csvSentimentScore = std::stoi(line.substr(line.length() - 1, line.length()));
    //Removes the csv score and unncessary commas
    line = line.substr(1, line.length() - 6);
    //Split into a linked list
    eric::LinkedList list = eric::lineSplit(line, ", ");
    // printList(list.head);
    eric::mergeSort(&list.head);
    // printList(list.head);

    //If a user wants a specific line, we can skip all these unncessary comparison
    //until we reached the desired line
    if(chosenLine==-1 || chosenLine==lineCount+1){
      //Finds the matching positive AND negative words, calculates it, and returns them
      //The reason why I did the calculation within this function call is because
      //It would seem mandatory in conjuction when finding matching words

      // matchingWordReturn result = eric::findMatchingWord(list.head, positiveWords.data.head,
                                          // negativeWords.data.head,option);
      matchingWordReturn result = eric::findMatchingWord(list.head,positiveWords.data.head,negativeWords.data.head,positiveWordsHalf.data.head,negativeWordsHalf.data.head,positiveWords.data.tail,negativeWords.data.tail,&allWordsFound,option);

      //Convert double to int
      int convertedScore = int(result.sentimentScore);
      //For Analysis later
      totalPositiveWords+=result.positiveWordCount;
      totalNegativeWords+=result.negativeWordCount;

      //We traverse the positive and negative words we found to add to the overall
      //list so we have do an overall analysis later
      // Node *positiveTraverse = result.positiveWordsFound.head;
      // while(positiveTraverse!=nullptr){
      //   allWordsFound.insertAtEnd(positiveTraverse->data);
      //   positiveTraverse=positiveTraverse->next;
      // }
      // //Same as above
      // Node *negativeTraverse = result.negativeWordsFound.head;
      // while(negativeTraverse!=nullptr){
      //   allWordsFound.insertAtEnd(negativeTraverse->data);
      //   negativeTraverse=negativeTraverse->next;
      // }

      //If user has chosen the option without display output
      if(option!=2){
        eric::compareScore(convertedScore, csvSentimentScore);
      }
      if(chosenLine==lineCount+1){
        //If it has reached the user's desired line, just break out after all operations
        break;
      }
      // adding the scores to highlight the trends later on
      calculatedScores.insertAtEnd(to_string(convertedScore));
      csvScores.insertAtEnd(to_string(csvSentimentScore));
    }

    lineCount++;
    }
    skipHeader=false;
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<seconds>(stop - start);
  //If the user did not choose the first option, then display the speed, since
  //if we're only analyzying a single line, the speed wouldn't really matter?
  if(chosenLine==-1){
    cout << "Time taken: " << duration.count() << " seconds" << endl;
  }

  std::cout<<"Would you like to see summary of overall reviews?(1/0)\n*Too much words to actually see the top in output if comparing all lines"<<endl;
  std::cin>>option;

  if(option==1){
    std::cout<<"Total Reviews = "<<lineCount+1<<endl;
    std::cout<<"Total Count of Positive Words = "<<totalPositiveWords<<endl;
    std::cout<<"Total Count of Negative Words = "<<totalNegativeWords<<endl;
    std::cout<<"\n"<<endl;
    std::cout<<"Frequency of each word used in overall reviews, listed in ascending order based on frequency:"<<endl;
    std::cout<<"\n"<<endl;

    printFrequencyInAscendingOrder(allWordsFound.head);
    if(chosenLine==-1){
      //Don't show this overall stats becuz user only chose one line to do analysis
      quarterlyAverage(calculatedScores.head,calculatedScores.size,"Calculated");
      distributionPercentage(calculatedScores.head);
    }
  }

  cout << "End of program" << endl;
}
