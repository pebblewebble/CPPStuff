#include <array>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

namespace eric {
// Node class
class Node {
public:
  std::string data;
  int frequencyCount;
  Node *next;

  Node(const std::string &data) {
    this->data = data;
    this->frequencyCount = 1;
    this->next = nullptr;
  }
};

// Linked list class
class LinkedList {

public:
  Node *head;
  Node *tail;
  int size;
  LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    size = 0;
  }

  void insertAtBeginning(const std::string &data) {
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    if(tail==nullptr){
      tail=head;
    }
    size++;
  }

  void insertAtEnd(const std::string &data) {
    Node *newNode = new Node(data);
    if (head == nullptr) {
      head = newNode;
      tail = newNode;
    }else{
      tail->next=newNode;
      tail = newNode;
    }
    size++;
  }

  void insertAtEnd(Node *node) {
      if (node == nullptr) return; 
      insertAtEnd(node->data); 
  }

  void deleteAtBeginning() {
    if (head == nullptr) {
      return;
    }
    Node *temp = head;
    head = head->next;
    if(head==nullptr){
      tail=nullptr;
    }
    delete temp;
    size--;
  }

  void deleteAtEnd() {
    if (head == nullptr) {
      return;
    }
    if (head->next == nullptr) {
      delete head;
      head = nullptr;
      tail=nullptr;
      size--;
      return;
    }
    Node *temp = head;
    while (temp->next != tail) {
      temp = temp->next;
    }
    delete tail;
    tail = temp;
    tail->next = nullptr;
    size--;
  }

  ~LinkedList() {
    while (head != nullptr) {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
  }
};

void printList(Node *node) {
  while (node != nullptr) {
    std::cout << node->data << " -> ";
    node = node->next;
  }
  std::cout << "nullptr" << std::endl;
}

// NOTE there are words in both positive and negative that uses things like
// "+","-","*" so first thought
//  would be do it both the word being checked and the positive/negative but
//  there are cases where it's not beneficial such as the positive word "a+"
//  as it is not the same meaning as "a".
std::string removeSpecialCharacter(const std::string &s) {
  //lastWasAlpha thing is to check special cases such as "good.you" as seen in line 4388
  //probably worsen performance by alot :(
  std::string result;
  bool lastWasAlpha = false;
  for (char c : s) {
    if (std::isalpha(c) || c == '-' || c == '*' || c == '+') {
      result += c;
      lastWasAlpha = true;
    }else if(lastWasAlpha&&c=='.'){
      result +=' ';
      lastWasAlpha=false;
    }
  }
  return result;
}
// Array seems to hard to implement for lineSplit cause we do not know the
// initial size, and recreating array everytime and copying the elements to
// new array is probably bad, so linked list might be best
// furthermore, we probably dont need random access anyways since we're
// gonna check the words one by one sequentially
eric::LinkedList lineSplit(std::string line, std::string delimiter) {
  std::stringstream data(line);
  eric::LinkedList list;
  std::string word;
  while (data >> word) {
    word = removeSpecialCharacter(word);
    std::stringstream secondData(word);
    while(secondData>>word){
      if(!word.empty()){
        list.insertAtEnd(word);
      }
    }
  }
  return list;
}

class LinkedListSentimentWords {
public:
  LinkedList data;
  int size = 0;
  LinkedListSentimentWords() { size = 0; }

  void addWord(const std::string &word) {
    data.insertAtEnd(word);
    size++;
  }
};

class files {
private:
  std::fstream fileOutput;

public:
  files(std::string fileName) {
    fileOutput.open(fileName, std::ios::in);
    if (!fileOutput.is_open()) {
      std::cout << "File could not open." << std::endl;
    } else {
      std::cout << "File opened." << std::endl;
    }
  }
  ~files() {
    if (fileOutput.is_open()) {
      fileOutput.close();
      std::cout << "File is successfully closed" << endl;
    }
  }

  std::fstream &getFileStream() { 
    return fileOutput; 
  }

  void recordsToArray(bool skipHeader) {
    std::string line;
    while (std::getline(fileOutput, line)) {
      // Some files have a header that you might want to skip the first line
      if (!skipHeader) {
        // The substring numbers used is to remove the unnecessary commas and
        // stuff
        line = line.substr(1, line.length() - 6);
        lineSplit(line, ", ");
        std::cout << line << std::endl;
        std::cin >> line;
      }
      skipHeader = false;
    }
  }
};

double calculateSentimentScore(int positiveWordCount, int negativeWordCount) {
  if(positiveWordCount==0&&negativeWordCount==0){
    //neutral
    return 3;
  }
  //Based on the given assignment
  int totalMatchingWordCount = positiveWordCount + negativeWordCount;
  int rawSentimentScore = positiveWordCount - negativeWordCount;

  int minRawScore = -totalMatchingWordCount;
  int maxRawScore = totalMatchingWordCount;

  double normalizedScore =
      (double)(rawSentimentScore - minRawScore) / (maxRawScore - minRawScore);
  double sentimentScore = 1 + (4 * normalizedScore);
  return sentimentScore;
}

void simpleDisplay(const Node *positiveWordsFound,const Node *negativeWordsFound,
                   int positiveSize, int negativeSize, int sentimentScore) {
  //Not much logic, just displaying things
  cout << "Positive Words = " << positiveSize << endl;
  const Node* tempPositive = positiveWordsFound;
  while (tempPositive != nullptr) {
      cout << "     " << tempPositive->data << endl;
      tempPositive = tempPositive->next;
  }
  cout << "\n" << endl; 

  cout << "Negative Words = " << negativeSize << endl;
  const Node* tempNegative = negativeWordsFound;
  while (tempNegative != nullptr) {
      cout << "     " << tempNegative->data << endl;
      tempNegative = tempNegative->next;
  }
  cout << "\n" << endl;

  string grade;
  if (int(sentimentScore) == 4 || int(sentimentScore) == 5) {
    grade = "Postiive";
  } else if (int(sentimentScore) == 2 || int(sentimentScore) == 1) {
    grade = "Negative";
  } else if (int(sentimentScore) == 3) {
    grade = "Neutral";
  } else {
    grade = "Error";
  }

  cout << "Sentiment Score (1-5) is " << sentimentScore
       << ", thus the rating should be equal to " << int(sentimentScore) << " ("
       << grade << ").";
}

struct matchingWordReturn {
  double sentimentScore;
  int positiveWordCount;
  int negativeWordCount;
  LinkedList positiveWordsFound;
  LinkedList negativeWordsFound;
};

matchingWordReturn findMatchingWord(Node *reviewLineHead, Node *positiveWordList,
                     Node *negativeWordList,int display) {
  Node *traverse = reviewLineHead;
  matchingWordReturn answer;
  Node *traversePositive = positiveWordList;
  Node *traverseNegative = negativeWordList;
  answer.positiveWordCount = 0;
  answer.negativeWordCount = 0;
  int test;

  while (traverse != nullptr) {
    Node *traversePositive = positiveWordList;
    Node *traverseNegative = negativeWordList;
    while (traversePositive != nullptr &&
           traversePositive->data < traverse->data) {
      traversePositive = traversePositive->next;
    }
    if (traversePositive != nullptr &&
        traversePositive->data == traverse->data) {

      answer.positiveWordsFound.insertAtEnd(traverse->data);
      answer.positiveWordCount++;
    }

    while (traverseNegative != nullptr &&
           traverseNegative->data < traverse->data) {
      traverseNegative = traverseNegative->next;
    }
    if (traverseNegative != nullptr &&
        traverse->data == traverseNegative->data) {
   
      answer.negativeWordsFound.insertAtEnd(traverse->data);
      answer.negativeWordCount++;
    }
    traverse = traverse->next;
  }

  answer.sentimentScore =
      calculateSentimentScore(answer.positiveWordCount, answer.negativeWordCount);
  //cout<<answer.sentimentScore<<endl;
  // cout<<positiveWordCount<<endl;
  // cout<<negativeWordCount<<endl;

  if(display!=2){
    simpleDisplay(answer.positiveWordsFound.head, answer.negativeWordsFound.head,
                  answer.positiveWordCount, answer.negativeWordCount, answer.sentimentScore);
  }
  return answer;
}

void compareScore(int convertedScore, int csvSentimentScore) {
  cout << "\n" << endl;
  cout << "Sentiment Score (1-5) = " << convertedScore << endl;
  cout << "Rating given by user = " << csvSentimentScore << endl;
  cout << "\n" << endl;
  cout << "Analysis Output:\n" << endl;
  if (convertedScore != csvSentimentScore) {
    cout << "User's subjective evaluation does not match the sentiment score "
            "provided by the analysis. There is an inconsistency between the "
            "sentiment score generated by the analysis and the user's "
            "evaluation of the sentiment."
         << endl;
  } else {
    cout << "User's subjective evaluation matches the sentiment score provided "
            "by the analysis. There is a consistency between the sentiment "
            "score generated by the analysis and the user's evaluation of the "
            "sentiment."
         << endl;
  }
  cout << "\n"<<endl;
}

Node *merge(Node *left, Node *right) {
  if (!left)
    return right;
  if (!right)
    return left;

  if (left->data[0] <= right->data[0]) {
    left->next = merge(left->next, right);
    return left;
  } else {
    right->next = merge(left, right->next);
    return right;
  }
}

void frontBackSplit(Node *source, Node **frontRef, Node **backRef) {
  Node *fast;
  Node *slow;
  if (!source || !source->next) {
    *frontRef = source;
    *backRef = nullptr;
    return;
  }
  slow = source;
  fast = source->next;
  while (fast) {
    fast = fast->next;
    if (fast) {
      slow = slow->next;
      fast = fast->next;
    }
  }
  *frontRef = source;
  *backRef = slow->next;
  slow->next = nullptr;
}

void mergeSort(Node **headRef) {
  Node *head = *headRef;
  Node *left;
  Node *right;
  if (!head || !head->next)
    return;

  frontBackSplit(head, &left, &right);
  mergeSort(&left);
  mergeSort(&right);
  *headRef = merge(left, right);
}

Node *split(Node *head) {
    Node *fast = head;
    Node *slow = head;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        if (fast != nullptr) {
            slow = slow->next;
        }
    }

    // Split the list into two halves
    Node *temp = slow->next;
    slow->next = nullptr;
    return temp;
}

Node *mergeInt(Node *first, Node *second) {
    if (first == nullptr) return second;
    if (second == nullptr) return first;

    if (first->frequencyCount < second->frequencyCount) {
        first->next = mergeInt(first->next, second);
        return first;
    } else if (first->frequencyCount == second->frequencyCount) {
        first->next = mergeInt(first->next, second);
        return first; 
    } else {
        second->next = mergeInt(first, second->next);
        return second;
    }
}

Node *mergeSortInt(Node *head) {
  
    //Base case: if the list is empty or has only one node, 
    //it's already sorted
    if (head == nullptr || head->next == nullptr)
        return head;

    //Split the list into two halves
    Node *second = split(head);

    //Recursively sort each half
    head = mergeSortInt(head);
    second = mergeSortInt(second);

    //Merge the two sorted halves
    return mergeInt(head, second);
}

void printFrequencyList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " = " << current->frequencyCount << " times" << std::endl;
        current = current->next;
    }
}

void printMinFrequencyWords(Node* head) {
    if (head == nullptr) return;

    std::cout<<"Minimum used words in the reviews: ";
    Node* current = head;
    int min = head->frequencyCount;
    //Continue printing as long as it's the minimum frequency count
    while (current != nullptr) {
        if (current->frequencyCount == min) {
            if(current!=head){
              std::cout<<", ";  
            }
            std::cout<<current->data;
        }else{
          //Once it's not the min, just break out
          break;
        }
        current = current->next;
    }
    std::cout<<endl;
}

void printMaxFrequencyWords(Node* head) {
    int maxCount = head->frequencyCount;
    Node* current = head;

    //Find the max
    while (current != nullptr) {
        if (current->frequencyCount > maxCount) {
            maxCount = current->frequencyCount;
        }
        current = current->next;
    }

    bool hasMaxWords = false;
    current = head; 

    cout << "Maximum used words in the reviews: ";
    //Print if max
    while (current != nullptr) {
        if (current->frequencyCount == maxCount) {
            if (hasMaxWords) {
                cout << ", "; 
            }
            cout << current->data;
            hasMaxWords = true; 
        }
        current = current->next;
    }

    if (!hasMaxWords) {
        cout << "None"; 
    }
    
    cout << endl; 
}

void printFrequencyInAscendingOrder(Node* allWordsFoundHead) {
    LinkedList frequencyList; 
    Node* current = allWordsFoundHead;

    while (current != nullptr) {
        //Check if the word already exists in the frequencyList
        Node* frequencyNode = frequencyList.head;
        while (frequencyNode != nullptr && frequencyNode->data != current->data) {
            frequencyNode = frequencyNode->next;
        }

        //If the word does not exists, add it
        if (frequencyNode == nullptr) {              
            frequencyList.insertAtEnd(current->data);    
        } else {
          //Word exists, increment frequency count
            frequencyNode->frequencyCount++;     
            // cout<<frequencyNode->data<<endl;      
            // cout<<frequencyNode->frequencyCount<<endl;
        }
        current = current->next;                       
    }

    // printList(frequencyList.head);   

    frequencyList.head = mergeSortInt(frequencyList.head);      

    // printList(frequencyList.head);     

    printFrequencyList(frequencyList.head);

    printMinFrequencyWords(frequencyList.head);
  
    printMaxFrequencyWords(frequencyList.head);
}

void quarterlyAverage(Node* calculatedScoresHead,int size,string mode){
  //if mode is true then we're calculating for "Calculated" score
  std::cout<<"\n"<<endl;
  Node* calculatedTraverse=calculatedScoresHead;
  int count=0;
  int currentTotal=0;
  while(calculatedTraverse!=nullptr){
    count++;
    currentTotal+=stoi(calculatedTraverse->data);

    if(count==int(size*.25)){
      std::cout<<"Q1 Average "<<mode<<" Score: "<<int(currentTotal/count)<<endl;
    }
    if(count==int(size*.50)){
      std::cout<<"Q2 Average "<<mode<<" Score: "<<int(currentTotal/count)<<endl;
    }
    if(count==int(size*.75)){
      std::cout<<"Q3 Average "<<mode<<" Score: "<<int(currentTotal/count)<<endl;
    }
    if(count==size){
      std::cout<<"Q4 Average "<<mode<<" Score: "<<int(currentTotal/count)<<endl;
    }
    calculatedTraverse=calculatedTraverse->next;
  }
}

void distributionPercentage(Node* calculatedScoresHead){
  std::cout<<"\n"<<endl;
  Node* calculatedTraverse=calculatedScoresHead;
  int count=0;
  int positiveReviewCount=0;
  int negativeReviewCount=0;
  int neutralReviewCount=0;
  //Add them to their respective groups based on the score
  while(calculatedTraverse!=nullptr){
    count++;
    if(calculatedTraverse->data=="5"||calculatedTraverse->data=="4"){
      positiveReviewCount++;
    }else if(calculatedTraverse->data=="2"||calculatedTraverse->data=="1"){
      negativeReviewCount++;
    }else{
      neutralReviewCount++;
    }
    calculatedTraverse=calculatedTraverse->next;
  }
  std::cout << "Percentage of Positive Review: " 
          << std::fixed << std::setprecision(2) 
          << (positiveReviewCount / static_cast<double>(count)) * 100 
          << "% Number of Positive Review: " << positiveReviewCount << std::endl;
  std::cout << "Percentage of Negative Review: " 
          << std::fixed << std::setprecision(2) 
          << (negativeReviewCount / static_cast<double>(count)) * 100 
          << "% Number of Negative Review: " << negativeReviewCount << std::endl;
  std::cout << "Percentage of Neutral Review: " 
          << std::fixed << std::setprecision(2) 
          << (neutralReviewCount / static_cast<double>(count)) * 100 
          << "% Number of Neutral Review: " << neutralReviewCount << std::endl;
}

} // namespace eric
