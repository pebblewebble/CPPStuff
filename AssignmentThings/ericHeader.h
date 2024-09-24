#include <array>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace eric {

// class Words_collection{
//   public:
//     int capacity = 20;
//     std::string* data;
//     int size;
//   Words_collection(){
//     data = new std::string[capacity];
//   }

//   void resize(){
//     capacity *=2;
//     std::string* newData = new std::string[capacity];
//     memcpy(newData,data,sizeof(data));
//     delete[] data;
//     data = newData;
//   }

//   void addWord(std::string word){
//     if(size==capacity){
//       resize();
//     }else{
//       data[size++]=word;
//     }
//   }

//   ~Words_collection(){
//     delete[] data;
//   }
// };

// Node class
class Node {
public:
  std::string data;
  Node *next;

  Node(const std::string &data) {
    this->data = data;
    this->next = nullptr;
  }
};

// Linked list class
class LinkedList {

public:
  Node *head;
  int size;
  LinkedList() {
    this->head = nullptr;
    size = 0;
  }

  void insertAtBeginning(const std::string &data) {
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
  }

  void insertAtEnd(const std::string &data) {
    Node *newNode = new Node(data);
    if (head == nullptr) {
      head = newNode;
      return;
    }
    Node *temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  void deleteAtBeginning() {
    if (head == nullptr) {
      return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
  }

  void deleteAtEnd() {
    if (head == nullptr) {
      return;
    }
    if (head->next == nullptr) {
      delete head;
      head = nullptr;
      return;
    }
    Node *temp = head;
    while (temp->next->next != nullptr) {
      temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
  }

  ~LinkedList() {
    while (head != nullptr) {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
  }
};

// NOTE there are words in both positive and negative that uses things like
// "+","-","*" so first thought
//  would be do it both the word being checked and the positive/negative but
//  there are cases where it's not beneficial such as the positive word "a+"
//  as it is not the same meaning as "a".
std::string removeSpecialCharacter(const std::string &s) {
  std::string result;
  for (char c : s) {
    if (std::isalpha(c) || c == '-' || c == '*' || c == '+') {
      result += c;
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
  // void lineSplit(std::string line, std::string delimiter) {
  std::stringstream data(line);
  eric::LinkedList list;
  std::string word;
  while (data >> word) {
    word = removeSpecialCharacter(word);
    if (!word.empty()) {
      list.insertAtEnd(word);
      // std::cout << word << std::endl;
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

  std::fstream &getFileStream() { return fileOutput; }

  // std::string* recordsToArray(){
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
  int totalMatchingWordCount = positiveWordCount + negativeWordCount;
  int rawSentimentScore = positiveWordCount - negativeWordCount;

  int minRawScore = -totalMatchingWordCount;
  int maxRawScore = totalMatchingWordCount;

  double normalizedScore =
      (double)(rawSentimentScore - minRawScore) / (maxRawScore - minRawScore);
  double sentimentScore = 1 + (4 * normalizedScore);
  return sentimentScore;
}

void simpleDisplay(Node *positiveWordsFound, Node *negativeWordsFound,
                   int positiveSize, int negativeSize, int sentimentScore) {
  cout << "Positive Words = " << positiveSize << endl;
  while (positiveWordsFound != nullptr) {
    cout << "     " << positiveWordsFound->data << endl;
    positiveWordsFound = positiveWordsFound->next;
  }
  cout << "\n" << endl;
  cout << "Negative Words = " << negativeSize << endl;
  while (negativeWordsFound != nullptr) {
    cout << "     " << negativeWordsFound->data << endl;
    negativeWordsFound = negativeWordsFound->next;
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
  double *sentimentScore;
  int *positiveWordCount;
  int *negativeWordCount;
  Node *positiveWordsFoundHead;
  Node *negativeWordsFoundHead;
};

int findMatchingWord(Node *reviewLineHead, Node *positiveWordList,
                     Node *negativeWordList,int display) {
  Node *traverse = reviewLineHead;
  Node *traversePositive = positiveWordList;
  Node *traverseNegative = negativeWordList;
  LinkedList positiveWordsFound;
  LinkedList negativeWordsFound;
  int positiveWordCount = 0;
  int negativeWordCount = 0;
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
      // cout<<traversePositive->data<<endl;
      // cout<<traverse->data<<endl;
      // cin>>test;
      positiveWordsFound.insertAtEnd(traverse->data);
      positiveWordCount++;
    }

    while (traverseNegative != nullptr &&
           traverseNegative->data < traverse->data) {
      traverseNegative = traverseNegative->next;
    }
    if (traverseNegative != nullptr &&
        traverse->data == traverseNegative->data) {
      // cout<<traverseNegative->data<<endl;
      // cout<<traverse->data<<endl;
      // cin>>test;
      negativeWordsFound.insertAtEnd(traverse->data);
      negativeWordCount++;
    }
    traverse = traverse->next;
  }

  double sentimentScore =
      calculateSentimentScore(positiveWordCount, negativeWordCount);
  // cout<<positiveWordCount<<endl;
  // cout<<negativeWordCount<<endl;

  matchingWordReturn answer;
  answer.sentimentScore = &sentimentScore;
  answer.positiveWordCount = &positiveWordCount;
  answer.negativeWordCount = &negativeWordCount;
  answer.positiveWordsFoundHead = positiveWordsFound.head;
  answer.negativeWordsFoundHead = negativeWordsFound.head;

  if(display!=2){
    simpleDisplay(positiveWordsFound.head, negativeWordsFound.head,
                  positiveWordCount, negativeWordCount, sentimentScore);
  }
  return sentimentScore;
}

void compareScore(int convertedScore, int csvSentimentScore) {
  cout << "\n" << endl;
  cout << "Sentiment Score (1-5) = " << convertedScore << endl;
  cout << "Rating given by user =" << csvSentimentScore << endl;
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
  cout << "\n\n\n"<<endl;
}

// Function to insert a node into the sorted linked list
void sortedInsert(Node **head_ref, Node *new_node) {
  Node *current;
  // Special case for the head end
  if (*head_ref == nullptr || (*head_ref)->data[0] >= new_node->data[0]) {
    new_node->next = *head_ref;
    *head_ref = new_node;
  } else {
    // Locate the node before the point of insertion
    current = *head_ref;
    while (current->next != nullptr &&
           current->next->data[0] < new_node->data[0]) {
      current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
  }
}

// Function to sort a linked list using insertion sort
void insertionSort(Node **head_ref) {
  Node *sorted = nullptr;    // Initially, the sorted list is empty
  Node *current = *head_ref; // Traverse the given linked list

  while (current != nullptr) {
    Node *next = current->next; // Store the next node
    // Insert current in sorted linked list
    sortedInsert(&sorted, current);
    // Update current
    current = next;
  }
  // Update the head_ref to point to the sorted list
  *head_ref = sorted;
}

void printList(Node *node) {
  while (node != nullptr) {
    std::cout << node->data << " -> ";
    node = node->next;
  }
  std::cout << "nullptr" << std::endl;
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

} // namespace eric
