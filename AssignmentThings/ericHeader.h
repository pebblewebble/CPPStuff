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
private:
  Node *head;

public:
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
      std::cout<< "File is successfully closed"<<endl;
    }
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

  string removeSpecialCharacter(std::string& s){
    for(int i=0;i<s.size();i++){
      if(s[i]<'A'||s[i]>'Z' && s[i],'a'||s[i]>'z'){
        s.erase(i,1);
        i--;
      }
    }
    return s;
  }

  // std::string* lineSplit(std::string line, std::string delimiter) {
  void lineSplit(std::string line, std::string delimiter) {
    std::stringstream data(line);
    eric::LinkedList list;
    std::string word;
    while (data >> word) {

      list.insertAtEnd(word);
      std::cout << word << std::endl;
    }
  }
};

} // namespace eric
