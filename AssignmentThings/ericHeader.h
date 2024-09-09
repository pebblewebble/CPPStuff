#include <array>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace eric {



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
  LinkedList() { this->head = nullptr; }

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

  std::fstream& getFileStream(){
    return fileOutput;
  }

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

  // Array seems to hard to implement for lineSplit cause we do not know the
  // initial size, and recreating array everytime and copying the elements to
  // new array is probably bad, so linked list might be best
  // furthermore, we probably dont need random access anyways since we're
  // gonna check the words one by one sequentially

};

int findPositiveMatch(std::string word){
//
}

} // namespace eric
