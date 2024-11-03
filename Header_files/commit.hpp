#ifndef COMMIT_HPP
#define COMMIT_HPP

#include <iostream>
#include <string>

using namespace std;

class Node {
  public:
    string key;
    string value;
    Node* next;

    Node(const string& key, const string& value) : key(key), value(value), next(nullptr) {}

    // Getter for the key
    string getKey() const {
      return key;
    }
};


class Commit {
private:
  Node* head;

public:
  Commit() : head(nullptr) {}

  ~Commit() {
    while (head) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
  }

  void add(const string& key, const string& value) {
    Node* newNode = new Node(key, value);
    newNode->next = head;
    head = newNode;
  }

  void printList() const {
    Node* current = head;
    while (current) {
      cout << current->key << " -> " << current->value << endl;
      current = current->next;
    }
  }

  int get_Length() const {
    int length = 0;
    Node* current = head;
    while (current) {
      length++;
      current = current->next;
    }
    return length;
  }

  void removeLastCommit() {
    if (!head) return;

    Node* toDelete = head;
    head = head->next;
    delete toDelete;
  }

  Node* get_head() const {
    return head;
  }
};

#endif
