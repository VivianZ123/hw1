#ifndef SPLIT_H
#define SPLIT_H

struct Node 
{
  int value;
  Node* next;

  Node(int val) : data(val),next(nullptr){}
};


void split(Node*& in, Node*& odds, Node*& evens);
void add_to_back(Node*& list, Node* node);


#endif
