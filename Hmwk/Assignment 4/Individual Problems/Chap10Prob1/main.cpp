/* 
 * File:   main.cpp
 * Author: Jason Emerson
 * Created on April 5th, 2017, 1:10 PM
 * Purpose: Chapter 10, Problem 1
 */

//System Libraries Here
#include <iostream>
#include <cstring>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int strLen(char *,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=50;
    char string[SIZE];
    int total;
    
    //Input or initialize values Here
    cout<<"Please input a string. Do not add any spaces."<<endl;
    cin>>string;
    
    //Process/Calculations Here
    total=strLen(string,SIZE);
    
    //Output Located Here
    cout<<endl;
    cout<<"There are "<<total<<" characters in this string."<<endl;

    //Exit
    return 0;
}

int strLen(char *array,int n){
    //Declaration of Variables
    int count;
    //String character counter
    count=strlen(array);
    return count;
}

