/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */



void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

//BASE CASES- if in is null
  if(in == NULL) //setting them to null if have't already if going to basecase
  {
    odds = NULL;
    evens = NULL;
    return; //returning to end
  }

  //if the value can be divisible by 2, then add to the even list
  if((in-> value % 2) == 0)
  {
    evens = new Node(in-> value, evens); //ew for the evens list
    split(in->next, odds, evens->next); //move forward with the even and in list
  }
  else //if it's odd, use the odd merge with recursion
  {
    odds = new Node(in->value, odds); //make a new for odds list
    split(in->next, odds->next, evens); //splitting it by going with teh next node of in, and using the newest node of odd
  } 



  delete in; //after everything is over, delete in, and then set it equal to NULL
  in = NULL;
}

/* If you needed a helper function, write it here */
// void pop_back(Node*& in)


//hello