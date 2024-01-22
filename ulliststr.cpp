#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
/*
bool ULListStr::empty() const
{
  if (size_==0){
    return true;
  }else{
    return false;
  }
}
*/

void ULListStr::push_back(const std::string& val) {

  if (tail_==nullptr) {
    tail_ = new Item;
    head_ = tail_;
  }
    if (tail_->last != ARRSIZE) {
        tail_->val[tail_->last] = val;
        tail_->last++;
    } else {
        Item* newNode = new Item;
        newNode->val[newNode->first] = val;
        newNode->last = 1;
        newNode->prev = tail_;
        newNode->next = nullptr;
        tail_->next = newNode;
        tail_ = newNode; 
    }
  size_++;
}

void ULListStr::pop_back() {
  if (tail_ == nullptr) return; // Empty list
  if (tail_->last > tail_->first) {
    tail_->last--;
  } else if (tail_->prev != nullptr) {
    Item* temp = tail_;
    tail_ = tail_->prev;
    tail_->next = nullptr;
    delete temp;
  } else {
    delete tail_;
    head_ = tail_ = nullptr;
  }
  size_--;
}

void ULListStr::push_front(const std::string& val) {
  if (head_ == nullptr) {
    head_ = new Item;
    tail_ = head_;
  }
  if (head_->first != 0) {
    head_->first--;
    head_->val[head_->first] = val;
  } else {
    Item *newNode = new Item;
    newNode->val[ARRSIZE - 1] = val;
    newNode->first = ARRSIZE - 1;
    newNode->last = ARRSIZE;
    newNode->next = head_;
    head_->prev = newNode;
    head_ = newNode;
  }
  size_++;
}


void ULListStr::pop_front() {
  if (head_ == nullptr) return; // Empty list
  if (head_->first < head_->last - 1) {
    head_->first++;
  } else if (head_->next != nullptr) {
    Item* temp = head_;
    head_ = head_->next;
    head_->prev = nullptr;
    delete temp;
  } else {
    delete head_;
    head_ = tail_ = nullptr;
  }
  size_--;
}

std::string const & ULListStr::back() const
{
  if (tail_->last == 0) {
    return tail_->prev->val[tail_->prev->last - 1];
  }
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  Item* current=head_;
  size_t index=0;
  while (current != nullptr) {
  if(index + current->last - current->first > loc){
    return &(current->val[loc - index + current->first]);
  }
  index += current->last - current->first;
  current = current->next;
}
return nullptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  /*while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }*/
  while (head_ != nullptr) {
        Item *temp = head_;
        head_ = head_->next;
        delete temp;
  }
  tail_ = NULL;
  size_ = 0;
}
