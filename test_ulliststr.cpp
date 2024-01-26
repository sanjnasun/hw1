#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr test1; //checking for push back
    test1.push_back("a"); 
    if(test1.get(0) == "a") cout << "correct" << endl;
    else cout << "wrong" << endl; //checking for wrong output
    cout << test1.get(0) << endl;



    ULListStr testPushBack; //push back for empty strings
    testPushBack.push_back("");
    testPushBack.push_back("");
    testPushBack.push_back("");
    if(testPushBack.get(0) == "") cout << "work" << endl;
    else cout << "n0" << endl;
    if(testPushBack.get(1) == "") cout << "work1" << endl;
    else cout << "n1" << endl;
    if(testPushBack.get(2) == "") cout << "work2" << endl;
    else cout << "n2" << endl;

    ULListStr what;
    what.push_back("value"); //tring push back adn push front, then popping back twice t see
    what.push_front("no");
    what.pop_back(); //popping/deleteing last
    cout << what.get(0) << endl; //checking first val
    what.pop_back();
    cout << what.get(9)  << endl;

    for(int i = 0; i < 5; i++) //adding five a atime for front, then popping
    {
        what.push_front("hola");
    }

    what.get(2);
    what.pop_front();


    ULListStr item;

    item.push_back(""); //empty input
    item.get(0);


    ULListStr suff;
    suff.pop_back(); //empty list, seeing if pop_back will respond


    ULListStr am;
    am.push_front("A");
    am.push_back("b");
    am.push_back("c");
    am.push_back("d");
    am.push_front("e");
    for(int i = 0; i < 4; i++) //updating beyond the bounds
    {
        am.push_front("");
    }
    for(int i = 0; i < 9; i++)
    {
        am.pop_front();
    }
    cout << what.get(0) << endl; //checking every single value
    cout << what.get(1) << endl;
    cout << what.get(2) << endl;
    cout << what.get(3) << endl;
    cout << what.get(4) << endl;
    cout << what.get(5) << endl;
    cout << what.get(6) << endl;
    cout << what.get(7) << endl;
    cout << what.get(8) << endl;
    cout << what.get(9) << endl;
    







}
