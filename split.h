#ifndef SPLIT_H
#define SPLIT_H

struct Node 
{
  int value;
  Node* next;

  Node(int val, Node* nextNode = nullptr) : value(val), next(nextNode) {}
};

void split(Node*& in, Node*& odds, Node*& evens);


#endif
