#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr() //setting values to null and size to 0
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr() //clearning destructor
{
  clear();
}

bool ULListStr::empty() const //empty if size is 0
{
  return size_ == 0;
}

size_t ULListStr::size() const //jsut returnin size 
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val) //void push back functon
{

  if(head_ == nullptr && tail_ == nullptr) //checks if head and tail are null then makes new item
  {
      Item* newItem = new Item();
      tail_ = newItem; //set tail and head to the single nde
      head_ = newItem;
      newItem->val[newItem->last] = val; //set val
      newItem->last++; //update last
      ++size_; //increment size
    
  }
  else if (tail_->last >= ARRSIZE) //if the last value of tail is larger than arraaysize
  {
      Item* newItem = new Item(); 
    //add a new item
      tail_->next = newItem;
      newItem->prev = tail_;
      tail_ = newItem;
    

    newItem->last = 1; // set the last value to 1 (starting at front)
    newItem->val[newItem->last - 1] = val; // set the value
    //newItem->last++;
    size_++;
    
  }
 else
  {
    tail_->val[tail_->last] = val;
    tail_->last++; //idk i just want to make it go next
    size_++; //incrementing size 
  }
}



void ULListStr::pop_back() //void pop back to delete the last value
{
  if (empty()) //edge case, if totally empty
  {
    return;
  }

  if (tail_->last > tail_->first) //if there is space
  {
    tail_->last--; //just regularly pop back
    --size_;
  }
  else if (tail_->last - tail_->first == 0) //if there is no space
  {
    if (head_ == tail_) //and if there  is only one node
    {
      delete tail_;
      tail_ = nullptr;
      head_ = nullptr;
      size_--;
    }
    else
    {
      Item* temp = tail_->prev; //delete the old node
      if (temp != nullptr) //use temp
      {
        temp->next = nullptr;
      }
      delete tail_;
      tail_ = temp;
      size_--;
    }
  }
}



void ULListStr::push_front(const std::string& value) //pushing values toward the front
{
  if (head_ == nullptr && tail_ == nullptr) //if the head and last are at the same
  {
    Item* newItem = new Item(); //new item to make at the head
    newItem->last = 1;
    head_ = newItem;
    tail_ = newItem;
    newItem->val[newItem->last - 1] = value; //add the value
    ++size_; //increment size
  }
  else if (head_->first == 0) //if the first val is at 0
  {
    Item* newItem = new Item(); //add a new item
    newItem->last = 1; //add one for last
    newItem->val[newItem->last - 1] = value; //update value
    
    newItem->next = head_; //change pointes
    head_->prev = newItem;
    head_ = newItem;

    ++size_;
  }
  else
  {
    head_->first--; //decremet and update value
    head_->val[head_->first] = value;
    ++size_;
  }
}



void ULListStr::pop_front() //delete teh front value
{
  if (empty()) //if the list is empty
  {
    return;
  }

  if (head_->first < head_->last - 1) //if there is space (more than 1)
  {
    head_->first++;
    --size_; //decrmenet
  }
  else //if not....
  {
    if (head_ == tail_) //if only one
    {
      delete head_; //delete head and just set all to null
      head_ = nullptr;
      tail_ = nullptr;
      size_--; //decrement size
    }
    else
    {
      Item* temp = head_->next; //make a new temp
      if (temp != nullptr) //change pointesr
      {
        temp->prev = nullptr;
      }
      delete head_;
      head_ = temp;
      size_--; //decrment size
    }
  }
}


std::string const & ULListStr::back() const //just return a refernce to where the tail's last is
{
  if(empty())
  {
    return NULL;
  }
  else
  {
    return tail_->val[tail_->last-1]; //reference to last
  }
}

std::string const & ULListStr::front() const
{
  if(empty())
  {
    return NULL; //of mpme. return null
  }
  else
  {
    return head_->val[head_->first]; //reference to last
  }

}



// std::string* ULListStr::getValAtLoc(size_t loc) const
// {
// size_t count = 0;
// for(int i = head_->first; i < size_; i++)
//   {
//     if(count == loc)
//     {
//       return val[count];
//     } 
//     else
//     {
//       count++;
//     }
//     if (loc > 10 || loc < 0 ) 
//     {
//     return NULL;
//     }
//   }
// }


std::string* ULListStr::getValAtLoc(size_t loc) const //getting value at any node 
{
//size_t count = 0;
//go through every node 
Item* temp = head_; 
//int where = 0;

while(temp != NULL) //allowing to go through everything
{
  //find pos
  size_t size_at = temp->last - temp->first; //elements between the list
  if(loc < size_at)
  {
    size_t newIndex = temp->first + loc;
    return &(temp->val[newIndex]);
  }
  else{
    loc -= size_at; //decremt the size 
    temp = temp->next;
  }
}
return nullptr; //if nothing else, reutnr nulllptr
}

//getvalatloc is for any location within any node
//if given loc = a value, if it's between the front and



//--------------------------------------------------------------------------------------//

void ULListStr::set(size_t loc, const std::string& val) //already wirttein functions, jsut sets the location with stirng alvue
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc) //getts the location ptr
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr; //returns a pointer loc
}

std::string const & ULListStr::get(size_t loc) const //return s apointers 
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr; //return ptr
}

void ULListStr::clear() //clears everyhting
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
