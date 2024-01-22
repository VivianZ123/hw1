

#include "split.h"
//#include <iostream>
//using namespace std;

void add(Node*& list, Node* node);

void split(Node*& in, Node*& odds, Node*& evens)
{
  if(in == nullptr){ 
    return;
  }
  Node* nextNode = in->next;
  in->next=nullptr;
  if(in->value%2==0){
    add(evens,in);
  }else{
    add(odds,in);
  }
  split(nextNode, odds, evens);
  in=nullptr;
}

void add(Node*& list, Node* node)
{
  if(list==nullptr){
    list=node;
  }else{
    add(list->next, node);
  }
}

