/* 
 * File:   main
 * Author: Jason Emerson
 * Created on March 12th, 2017 9:38 PM
 * Purpose: Assignment 2 Menu
 */

//System Libraries
#include <iostream> //Input/Output Objects
#include <iomanip> //Formatting
using namespace std;

//Global Constants

//Function Prototypes
//**Functions for each problem below each individual problem**
void Menu();
int getN();
void def(int);
void problem1();
void selSort(int *,int);
void avg(int *,int);
void problem2();
void problem3();
void problem4();
void arrSelectSort(int *[], int);
void showArray(const int [], int);
void showArrPtr(int *[], int);
void problem5();
void deSort(int *[], int);
void problem6();
void rev(int *,int *,int);
void problem7();
int *expand(int *,int);
void problem8();
int *filAray(int);
void prntAray(int *,int,int);
float mean(int [],int);
float median(int [],int);
void sort(int *,int *,int);
int maxFreq(int *,int);
int *mode(int [],int,int);
void destroy(int *);

//Execution Begins Here
int main(int argc, char** argv) {
    int choice;
    do{
        Menu();
        choice=getN();
        switch(choice){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        case 7:    problem7();break;
        case 8:    problem8();break;
        default:   def(choice);}
    }while(choice>=1&&choice<=8);
    return 0;
}

void Menu(){
    cout<<"Menu for the Assignment 1"<<endl;
    cout<<"Type 1 for 9.2 (Test Scores #1)"<<endl;
    cout<<"Type 2 for 9.3 (Drop Lowest Score)"<<endl;
    cout<<"Type 3 for 9.4 (Test #2)"<<endl;
    cout<<"Type 4 for 9.6 (Case Study Modification #1)"<<endl;
    cout<<"Type 5 for 9.7 (Case STudy Modification #2)"<<endl;
    cout<<"Type 6 for 9.10 (Reverse Array)"<<endl;
    cout<<"Type 7 for 9.11 (Array Expander)"<<endl;
    cout<<"Type 8 for Mean, Median, and Mode problem"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){
    int size,test;
    cout<<"Enter number of test scores: ";
    cin>>size;
    //Allocate
    int *array=new int[size];
    //Enter Test Scores
    for(int i=0;i<size;i++){
        cout<<"Test Score: ";
        cin>>test;
        *(array+i)=test;
    }
    //Sort Ascending Order
    selSort(array,size);
    //Display Sorted List
    cout<<"Sorted List: ";
    for(int i=0;i<size;i++){
        cout<<*(array+i)<<" ";
    }
    cout<<endl;
    //Display Averages
    avg(array,size);
    //Un-Allocate
    delete []array;
    cout<<endl;
}

void selSort(int *a,int n){
    int minInd;
    int minElem;
    for(int i=0;i<(n-1);i++){
        minInd=i;
        minElem=*(a+i);
        for(int j=i+1;j<n;j++){
            if(*(a+j)<minElem){
                minElem=*(a+j);
                minInd=j;
            }
        }
        *(a+minInd)=*(a+i);
        *(a+i)=minElem;
    }
}

void avg(int *a,int n){
    //Declare average
    int tot=0;
    float avg;
    for(int i=0;i<n;i++){
        tot=tot+a[i];
    }
    //Format
    cout<<setprecision(2)<<fixed;
    avg=tot/n;
    cout<<"Average: "<<avg<<endl;
}

void problem2(){
    int size,test,tot=0;
    float avg;
    cout<<"Enter number of test scores: ";
    cin>>size;
    //Allocate
    int *array=new int[size];
    //Enter Test Scores
    for(int i=0;i<size;i++){
        cout<<"Test Score: ";
        cin>>test;
        *(array+i)=test;
    }
    //Sort Ascending Order
    selSort(array,size);
    //Display Sorted List without lowest score
    cout<<"Sorted List: ";
    for(int i=1;i<size;i++){
        cout<<*(array+i)<<" ";
    }
    cout<<endl;
    //Calculate and Display Average
    for(int i=1;i<size;i++){
        tot=tot+array[i];
    }
    //Format
    cout<<setprecision(2)<<fixed;
    avg=tot/(size-1);
    cout<<"Average: "<<avg<<endl;
    //Un-Allocate
    delete []array;
    cout<<endl;
}

void problem3(){
    int size,test;
    char name[100];
    //Allocate
    int *atest=new int[size];
    char *astu=new char[100];
    int *btest=new int[size];
    char *bstu=new char[100];
    cout<<"How many tests did the students take? ";
    cin>>size;
   //Enter Name
    cout<<"Enter first students name: ";
    cin>>astu;
    for(int i=0;i<size;i++){
        cout<<"Test Score: ";
        cin>>*(atest+i);
    }
    //Sort Ascending Order
    selSort(atest,size);
    //Enter Name
    cout<<"Enter second students name: ";
    cin>>bstu;
    for(int i=0;i<size;i++){
        cout<<"Test Score: ";
        cin>>*(btest+i);
    }
    //Sort Ascending Order
    selSort(btest,size);
    //Display Sorted List
    cout<<astu<<endl;
    for(int i=0;i<size;i++){
        cout<<*(atest+i)<<" ";
    }
    cout<<endl;
    //Display Sorted List
    cout<<bstu<<endl;
    for(int i=0;i<size;i++){
        cout<<*(btest+i)<<" ";
    }
    cout<<endl;
    //Un-Allocate
    delete []atest;
    delete []astu;
    delete []btest;
    delete []bstu;
    cout<<endl;
}

void problem4(){
    int NUM_DONATIONS;
    cout<<"Enter the number of donations: ";
    cin>>NUM_DONATIONS;
    int *donations=new int[NUM_DONATIONS];

    for(int i=0;i<NUM_DONATIONS;i++){
        cout<<"Enter Donation (Value): ";
        cin>>*(donations+i);
    }

   // An array of pointers to int.
   int *arrPtr[NUM_DONATIONS];

   // Each element of arrPtr is a pointer to int. Make each
   // element point to an element in the donations array.
   for (int count = 0; count < NUM_DONATIONS; count++)
      arrPtr[count] = &donations[count];

   // Sort the elements of the array of pointers.
   arrSelectSort(arrPtr, NUM_DONATIONS);

   // Display the donations using the array of pointers. This
   // will display them in sorted order.
   cout << "The donations, sorted in ascending order are: \n";
   showArrPtr(arrPtr, NUM_DONATIONS);

   // Display the donations in their original order.
   cout << "The donations, in their original order are: \n";
   showArray(donations, NUM_DONATIONS);
   delete []donations;
   cout<<endl;
}

void arrSelectSort(int *arr[], int size)
{
   int startScan, minIndex;
   int *minElem;

   for (startScan = 0; startScan < (size - 1); startScan++)
   {
      minIndex = startScan;
      minElem = arr[startScan];
      for(int index = startScan + 1; index < size; index++)
      {
         if (*(arr[index]) < *minElem)
         {
            minElem = arr[index];
            minIndex = index;
         }
      }
      arr[minIndex] = arr[startScan];
      arr[startScan] = minElem;
   }
}

void showArray(const int arr[], int size)
{
   for (int count = 0; count < size; count++)
      cout << arr[count] << " ";
   cout << endl;
}

void showArrPtr(int *arr[], int size)
{
   for (int count = 0; count < size; count++)
      cout << *(arr[count]) << " ";
   cout << endl;
}

//Taken from the book to use to modify
void problem5(){
    const int NUM_DONATIONS = 15;  // Number of donations

   // An array containing the donation amounts.
   int donations[NUM_DONATIONS] = {5,  100, 5,  25, 10,
                                   5,  25,  5,  5,  100,
                                   10, 15,  10, 5,  10 };

   // An array of pointers to int.
   int *arrPtr[NUM_DONATIONS];

   // Each element of arrPtr is a pointer to int. Make each
   // element point to an element in the donations array.
   for (int count = 0; count < NUM_DONATIONS; count++)
      arrPtr[count] = &donations[count];

   // Sort the elements of the array of pointers.
   deSort(arrPtr, NUM_DONATIONS);

   // Display the donations using the array of pointers. This
   // will display them in sorted order.
   cout << "The donations, sorted in descending order are: \n";
   showArrPtr(arrPtr, NUM_DONATIONS);

   // Display the donations in their original order.
   cout << "The donations, in their original order are: \n";
   showArray(donations, NUM_DONATIONS);
   cout<<endl;
}

void deSort(int *arr[], int size){
    int startScan, minIndex;
    int *minElem;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minElem = arr[startScan];
        for(int index = startScan + 1; index < size; index++)
        {
           if (*(arr[index]) > *minElem)
           {
              minElem = arr[index];
              minIndex = index;
           }
        }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minElem;
    }
}

void problem6(){
    //Declaration of Variables
    const int SIZE=10;
    //Fill the array
    int *array=filAray(SIZE);
    int *brray=new int[SIZE];
    rev(array,brray,SIZE);
    prntAray(array,SIZE,10);
    prntAray(brray,SIZE,10);
    delete [] array;
    delete [] brray;
}

void rev(int *a,int *b,int n){
    for(int i=0;i<n;i++){
        b[9-i]=a[i];
    }
}

void problem7(){
    const int SIZE=10;
    int siz=SIZE*2;
    int *array=filAray(SIZE);
    //Expand
    int *brray=expand(array,siz);
    prntAray(array,SIZE,10);
    prntAray(brray,siz,10);
    delete [] array;
    delete [] brray;
}

int *expand(int *a,int n){
    int size;
    size=n/2;
    cout<<size;
    int *brray=new int[n];
    for(int i=0;i<size;i++){
        brray[i]=a[i];
    }
    for(int j=n;j<n;j++){
        brray[j]=0;
    }
    return brray;
}

void problem8(){
    //Declare variables
    int size;
    cout<<"What is the length of the array ";
    cin>>size;
    int brray[size];
    int maxF;
    //Fill the array with 0-9
    int *array=filAray(size);
    //Print the array
    prntAray(array,size,10);
    mean(array,size);
    median(array,size);
    //Copy and Sort the copied array
    sort(array,brray,size);
    //What is the max frequency
    maxF=maxFreq(brray,size);
    cout<<"Max Frequency: "<<maxF<<endl;
    mode(brray,size,maxF);
    destroy(array);
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

void destroy(int *a){
    delete [] a;
    cout<<endl;
    cout<<endl;
}

int *mode(int b[],int n,int max){
    //Declare variable
    int count=0,temp=b[1];
    cout<<"Mode: ";
    for(int i=0;i<n-1;i++){
        if(b[i]==temp){
            count++;
            if(count==max){
                cout<<b[i];
                count=0;
                temp=b[i+1];
            }
        }
        if(b[i]==!temp){
            count=0;
            temp=b[i+1];
        }
    }
}

//Requires sorted array for an input
int maxFreq(int *b,int n){
    //Declare counters
    int count=1,max=1;
    //Loop and compare
    for(int i=1;i<n;i++){
        if(b[i-1]==b[i]){
            count++;
            if(count>max)max=count;
        }else{
            count=1;
        }
    }
    return max;
}

void sort(int *a,int *b,int n){
    //Make a copy
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Sort the copied array
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(b[i]>b[j]){
                int temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
}

float median(int a[],int n){
    for(int i=0;i<n;i++){
        if(i==n/2){
            cout<<"Median: "<<a[i]<<endl;
        }
    }
}

float mean(int a[],int n){
    //Declare variable and counter
    float tot=0,me;
    //Format
    cout<<setprecision(2)<<fixed;
    for(int i=0;i<n;i++){
        tot=tot+a[i];
    }
    me=tot/n;
    cout<<"Mean: "<<me<<endl;
}

void prntAray(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}

//Repetitive Count with 1 digit elements
int *filAray(int n){
    //Allocate memory
    int *a=new int[n];
    //Fill array
    for(int i=0;i<n;i++){
        *(a+i)=i%10;
    }
    return a;
}