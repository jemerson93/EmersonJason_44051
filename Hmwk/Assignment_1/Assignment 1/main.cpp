/*
 * File:   main.cpp
 * Author: Jason Emerson
 * Created on March 6, 2017, 8:32 PM
 * Purpose : Menu for assignments
 */

//System Libraries
#include <iostream> //Input/Output Objects
#include <iomanip> //Formatting
#include <cstdlib> //Random Generator
#include <ctime>  //Time

using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const int NUMDAYS=30;
const int NMONTHS=3;

//Function prototypes
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();
float tempCnv(float);
float tempCnv(float,float,float,float,float);
void selectionSort(string[],int);
int binarySearch(string[],string);
void fillAry(char [][NUMDAYS],int);
void prntAry(char [][NUMDAYS],int);
void prntAry(int [][NMONTHS]);
void calcAry(char [][NUMDAYS],int [][NMONTHS]);
void rainy(int [][NMONTHS]);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int menuItm;    //Choice from menu
    
    //Loop until users exits
    do{
    
        //Prompt for problem for user input
        cout<<"1.  Type 1  for Gaddis_8thEd_Chap3_Prob12"<<endl;
        cout<<"2.  Type 2  for Gaddis_8thEd_Chap3_Prob13"<<endl;
        cout<<"3.  Type 3  for Gaddis_8thEd_Chap4_Prob1"<<endl;
        cout<<"4.  Type 4  for Gaddis_8thEd_Chap4_Prob7"<<endl;
        cout<<"5.  Type 5  for Gaddis_8thEd_Chap4_Prob10"<<endl;
        cout<<"6.  Type 6  for Gaddis_8thEd_Chap5_Prob11"<<endl;
        cout<<"7.  Type 7  for Gaddis_8thEd_Chap6_Prob7"<<endl;
        cout<<"8.  Type 8  for Gaddis_8thEd_Chap7_Prob6"<<endl;
        cout<<"9.  Type 9  for Gaddis_8thEd_Chap8_Prob7"<<endl;
        cout<<"10. Type 10 for Gaddis_8thEd_Chap8_Prob1"<<endl;
        cout<<"11. Type 11 to exit the program"<<endl;
        cin>>menuItm;

        //Go to the Problem
        switch(menuItm){
            case 1:
                problem1();
                break;
            case 2:
                problem2();
                break;
            case 3:
                problem3();
                break;
            case 4:
                problem4();
                break;
            case 5:
                problem5();
                break;
            case 6:
                problem6();
                break;
            case 7:
                problem7();
                break;
            case 8:
                problem8();
                break;
            case 9:
                problem9();
                break;
            case 10:
                problem10();
                break;
            default:
                break;
        }//End the Switch/Case
    }while(menuItm>0&&menuItm<=10);//Ends the Do-While Loop

    //Exit Program
    return 0;
}

void problem1(){
    //Declaration of Variables
    float celsius; //Celsius Input
    float fahrht; //Fahrenheit Output

    //Input Values
    cout<<"Please enter the degrees in Celsius."<<endl;
    cin>>celsius;
    
    //Process Values
    fahrht=(celsius*9.0)/5.0+32; //Conversion from Celsius to Fahrenheit
    
    //Display Outputs
    cout<<"The Celsius of "<<celsius<<" is "<<fahrht<<" degrees Fahrenheit"<<endl;

    //Exit Program
}

void problem2(){
    //Declaration of Variables
    float dollar;
    float yen=113.81;
    float euro=.9435;

    //Input Values
    cout<<"Please enter the dollar amount in US dollars."<<endl;
    cin>>dollar;
    
    //Process Values
    float euroConv=dollar*euro;
    float yenConv=dollar*yen;
    
    //Display Outputs
    cout<<"The Euro conversion is: "<<fixed<<setprecision(2)<<euroConv<<" Euro"<<endl;
    cout<<"The Yen conversion is: "<<fixed<<setprecision(2)<<yenConv<<" Yen"<<endl;

    //Exit Program
}

void problem3(){
    //Declaration of Variables
    short a, b, c, d;

    //Input Values
    cout<<"Enter the first number"<<endl;
    cin>>a;
    
    cout<<"Enter the second number"<<endl;
    cin>>b;
    
    cout<<"Enter the third number"<<endl;
    cin>>c;
    
    cout<<"Enter the fourth number"<<endl;
    cin>>d;
    
    //Process Values
    cout<<"The first two numbers in order are ";
    if(a>b)
        cout<<a<<","<<b<<endl;
    else
        cout<<b<<","<<a<<endl;
    
    cout<<"The first three numbers in order are ";
    if((a>=b)&&(b>=c))
        cout<<a<<","<<b<<","<<c<<endl;
    else if((a>=c)&&(c>=b))
        cout<<a<<","<<c<<","<<b<<endl;
    else if((b>=a)&&(a>=c))
        cout<<b<<","<<a<<","<<c<<endl;
    else if((b>=c)&&(c>=a))
        cout<<b<<","<<c<<","<<a<<endl;
    else if((c>=b)&&(b>=a))
        cout<<c<<","<<b<<","<<a<<endl;
    else if((c>=a)&&(a>=b))
        cout<<c<<","<<a<<","<<b<<endl;
    
    cout<<"All numbers in order are ";
    if((a>=b)&&(b>=c)&&(c>=d))
        cout<<a<<","<<b<<","<<c<<","<<d<<endl;
    else if((a>=b)&&(b>=c)&&(d>=c))
        cout<<a<<","<<b<<","<<d<<","<<c<<endl;
    else if((a>=c)&&(c>=b)&&(b>=d))
        cout<<a<<","<<c<<","<<b<<","<<d<<endl;
    else if((a>=c)&&(c>=b)&&(b>=d))
        cout<<a<<","<<c<<","<<d<<","<<b<<endl;
    else if((a>=d)&&(d>=b)&&(b>=c))
        cout<<a<<","<<d<<","<<b<<","<<c<<endl;
    else if((a>=d)&&(d>=c)&&(c>=b))
        cout<<a<<","<<d<<","<<c<<","<<b<<endl;
    else if((b>=a)&&(a>=c)&&(c>=d))
        cout<<b<<","<<a<<","<<c<<","<<d<<endl;
    else if((b>=a)&&(a>=d)&&(d>=c))
        cout<<b<<","<<a<<","<<d<<","<<c<<endl;
    else if((b>=c)&&(c>=a)&&(a>=d))
        cout<<b<<","<<c<<","<<a<<","<<d<<endl;
    else if((b>=c)&&(c>=d)&&(d>=a))
        cout<<b<<","<<c<<","<<d<<","<<a<<endl;
    else if((b>=d)&&(d>=a)&&(a>=c))
        cout<<b<<","<<d<<","<<a<<","<<c<<endl;
    else if((b>=d)&&(d>=c)&&(c>=a))
        cout<<b<<","<<d<<","<<c<<","<<a<<endl;
    else if((c>=a)&&(a>=b)&&(b>=d))
        cout<<c<<","<<a<<","<<b<<","<<d<<endl;
    else if((c>=a)&&(a>=d)&&(d>=b))
        cout<<c<<","<<a<<","<<d<<","<<b<<endl;
    else if((c>=b)&&(b>=a)&&(a>=d))
        cout<<c<<","<<b<<","<<a<<","<<d<<endl;
    else if((c>=b)&&(b>=d)&&(d>=a))
        cout<<c<<","<<b<<","<<d<<","<<a<<endl;
    else if((c>=d)&&(d>=a)&&(a>=b))
        cout<<c<<","<<d<<","<<a<<","<<b<<endl;
    else if((c>=d)&&(d>=b)&&(b>=a))
        cout<<c<<","<<d<<","<<b<<","<<a<<endl;
    else if((d>=a)&&(a>=c)&&(c>=b))
        cout<<d<<","<<a<<","<<c<<","<<b<<endl;
    else if((d>=a)&&(a>=b)&&(b>=c))
        cout<<d<<","<<a<<","<<b<<","<<c<<endl;
    else if((d>=b)&&(b>=a)&&(a>=c))
        cout<<d<<","<<b<<","<<a<<","<<c<<endl;
    else if((d>=b)&&(b>=c)&&(c>=a))
        cout<<d<<","<<b<<","<<c<<","<<a<<endl;
    else if((d>=c)&&(c>=a)&&(a>=b))
        cout<<d<<","<<c<<","<<a<<","<<b<<endl;
    else if((d>=c)&&(c>=b)&&(b>=a))
        cout<<d<<","<<c<<","<<b<<","<<a<<endl;
    
    //Display Outputs

    //Exit Program
}

void problem4(){
    //Declaration of Variables
    float sec, mins, hours, days; //Precise amount of minutes, hours, and days

    //Input Values
    cout<<"How many seconds?"<<endl;
    cin>>sec;
    
    //Process Values
    mins=sec/60;
    hours=sec/3600;
    days=sec/86400;
    
    //Display Outputs
    if (sec>=86400)                                            //Displays in days
        cout<<sec<<" seconds equals "<<days<<" days"<<endl;
    else if (sec>=3600)                                        //Displays in hours
        cout<<sec<<" seconds equals "<<hours<<" hours"<<endl;
    else if (sec>=60)                                          //Displays in minutes
        cout<<sec<<" seconds equals "<<mins<<" minutes"<<endl;
    else if (sec>=0)                                           //Displays in seconds
        cout<<sec<<" seconds equals "<<sec<<" seconds"<<endl;

    //Exit Program
}

void problem5(){
    //Declaration of Variables
    int month, year; //Month and year declaration

    //Input Values
        //Input Month
    cout<<"Please enter a month number."<<endl;
    cin>>month;
    
        //Input year
    cout<<"Please enter a year."<<endl;
    cin>>year;
    
    //Display Outputs
    switch(month){
        case 1:
            cout<<"There are 31 days in January "<<year<<endl;
            break;
        case 2:
            if(year%400==0){
                cout<<"There are 29 days in February "<<year<<endl;
            }else if(year%100!=0&&year%4==0){
                cout<<"There are 29 days in February "<< year<<endl;
            }else{
                cout<<"There are 28 days in February "<< year<<endl;
            }
            break;
        case 3:
            cout<<"There are 31 days in March "<< year<<endl;
            break;
        case 4:
            cout<<"There are 30 days in April "<< year<<endl;
            break;
        case 5:
            cout<<"There are 31 days in May "<< year<<endl;
            break;
        case 6:
            cout<<"There are 30 days in June "<< year<<endl;
            break;
        case 7:
            cout<<"There are 31 days in July "<< year<<endl;
            break;
        case 8:
            cout<<"There are 31 days in August "<< year<<endl;
            break;
        case 9:
            cout<<"There are 30 days in September "<< year<<endl;
            break;
        case 10:
            cout<<"There are 31 days in October "<< year<<endl;
            break;
        case 11:
            cout<<"There are 30 days in November "<< year<<endl;
            break;
        case 12:
            cout<<"There are 31 days in December "<< year<<endl;
            break;
    }

    //Exit Program
}

void problem6(){
    //Declaration of Variables
    float popinc, pPopinc;      //Daily population increase and Daily population increase in percent
    unsigned short numDays,     //Number of days to test
                   pop,         //Population
                   inPop;       //the increase of population of that day

    //Input Values
     cout << "Input the percentage growth per day (no negatives) :" << endl;
    cin >> pPopinc;
    while (pPopinc < 0){
        cout << "Input the growth again :" << endl;
        cin >> pPopinc;
    }
    popinc = pPopinc / 100;
    
    cout << "Input the starting population (greater than or equal two):" << endl;
    cin >> pop;
    while (pop < 2){
        cout << "Starting population to small re-input the population (>=2):" << endl;
        cin >> pop;
    }
    
    cout << "Input the the number of dates to test (>=1):" << endl;
    cin >> numDays;
    while (numDays < 1){
        cout << "Input a number that is equal to or greater than or equal to one:" << endl;
        cin >> pPopinc;
    }
    
    //Process Values
    cout << "The population of day 1 is " << pop << " Organisms" << endl;
    
    for (int i=2; i<=numDays; i++){
        inPop = pop * popinc;
        pop = inPop + pop;
        cout << "The population of day " << i << " is " << pop << " Organisms"  << endl;
    }

    //Exit Program
}

void problem7(){
    //Declaration of Variables
    float f1=32.0f,f2=212.0f,c1=0.0f,c2=100.0f;
    int begF=0,endF=250;

    //Process Values
    cout<<"Degree F   Degree C   Degree C"<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    for(int degF=begF;degF<=endF;degF++){
        cout<<setw(6)<<degF
            <<setw(12)<<tempCnv(degF)
            <<setw(11)<<tempCnv(degF,f1,f2,c1,c2)<<endl;
    }
    
    //Exit Program
}

float tempCnv(float f){
    return (f-32.0f)*5/9;
}

float tempCnv(float f,float f1,float f2,float c1,float c2){
    return c1+(f-f1)*(c2-c1)/(f2-f1);
}

void problem8(){
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declaration of Variables
    char weather[NMONTHS][NUMDAYS];
    int stat[NMONTHS][NMONTHS]={};

    //Input Values
    fillAry(weather,NMONTHS);
    
    //Display Output
    prntAry(weather,NMONTHS);
    
    //Process Values
    calcAry(weather,stat);
    
    //Display Output
    prntAry(stat);
    rainy(stat);

    //Exit Program
}

void rainy(int stat[][NMONTHS]){
    int sum=stat[0][0],low=stat[0][0],high=stat[0][0];
    float avg;
    for(int months=1;months<NMONTHS;months++){
        sum+=stat[months][0];
        if(high<stat[months][0])high=stat[months][0];
        if(low>stat[months][0])low=stat[months][0];
    }
    avg=1.0f*sum/NMONTHS;
    cout<<endl;
    cout<<"The total rainy days   = "<<sum<<endl;
    cout<<"The average rainy days = "<<avg<<endl;
    cout<<"The highest rainy days = "<<high<<endl;
    cout<<"The lowest rainy days  = "<<low<<endl;
}

void calcAry(char weather[][NUMDAYS],int stat[][NMONTHS]){
    for(int months=0;months<NMONTHS;months++){
        for(int days=0;days<NUMDAYS;days++){
            if(weather[months][days]=='R'){
                stat[months][0]++;
            }else if(weather[months][days]=='C'){
                stat[months][1]++;
            }else{
                stat[months][2]++;
            }
        }
    }
}

void fillAry(char weather[][NUMDAYS],int nMonths){
    //Declare an array of values
    char type[]={'R','C','S'};
    //Fill the array
    for(int days=0;days<NUMDAYS;days++){
        for(int months=0;months<nMonths;months++){
            weather[months][days]=type[rand()%3];
        }
    }
}

void prntAry(int stat[][NMONTHS]){
    //Declare another array
    char month[][7]={"  June","  July","August"};
    //Print the data out
    cout<<endl;
    cout<<"        R   C   S"<<endl;
    for(int months=0;months<NMONTHS;months++){
        cout<<month[months];
        for(int data=0;data<NMONTHS;data++){
            cout<<setw(3)<<stat[months][data]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void prntAry(char weather[][NUMDAYS],int nMonths){
    //Print the data out
    cout<<endl;
    for(int months=0;months<nMonths;months++){
        for(int days=0;days<NUMDAYS;days++){
            cout<<weather[months][days]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void problem9(){
    //Declaration of Variables
    const int SIZE=20; //Size of array (20 names))
    string names[SIZE]={"Collins,Bill","Smith,Bart","Allen,Jim",
                             "Griffin,Jim","Stamey,Marty","Rose,Geri",
                             "Taylor,Terri","Johnson,Jill",
                             "Allison,Jeff","Looney,Joe","Wolfe,Bill",
                             "James,Jean","Weaver,Jim","Pore,Bob",
                             "Rutherford,Greg","Javens,Renee",
                             "Harrison,Rose","Setzer,Cathy",
                             "Pike,Gordon","Holland,Beth"};
    string name;

    //Selection Sort
    selectionSort(names,SIZE);
    
    //Name to Search
    cout<<"What is the name you are attempting to search for?"<<endl;
    cout<<"Please enter in the format of Last,First"<<endl;
    cin>>name;
   
    //Search for name and Display if Found or Not
    int nameF=binarySearch(names,name);
    
    if(nameF==-1){
        cout<<"Sorry, we are unable to locate the name you listed in our list."<<endl;
    }
    else{
        cout<<"Name Found: "<<names[nameF]<<endl;
    }

    //Exit Program
}

void selectionSort(string names[],int j){
    //Declaration of Variables
    int minInd;
    string name;
    
    //Process Values
    for(int i=0;i<(j-1);i++){
        minInd=i; //Minimum
        name=names[i];
        for(int k=i+1;k<j;k++){
            if(names[k]<name){
                name=names[k];
                minInd=k;
            }
        }
        names[minInd]=names[i];
        names[i]=name;
    }
    
}

int binarySearch(string names[],string j){
    //Declaration of Variables
    short pos=-1; //Position
    int first=0; //First Element
    int last=21-1; //Last Element
    int middle; //Middle
    bool found=false; //Set to false while not found
    
    //Process Values
    do{
        middle=(first+last)/2; //Calculate the mid point
        if(names[middle]==j){
            //found=true;
            pos=middle;
            return pos;
        }
        else if(names[middle]>j)last=middle-1;
        else first=middle+1;
    }while(found==false&&first<=last);
    return -1;
}

void problem10(){
    //Declaration of Variables
    const int SIZE=18;
        //Account Numbers Below
    int accounts[SIZE]={5658845,4520125,7895122,8777541,8451277,1302850,8080152,
                     4562555,5552012,5050552,7825877,1250255,1005231,6545231,
                     3852085,7576651,7881200,4581002};
    int accNum; //Account Number Being Input
    bool found=false; //Exit Loop

    //Input Values
    cout<<"Please input the Account Number:"<<endl;
    cin>>accNum;
    
    //Simple Linear Search
    for(int i=1;i<18&&found==false;i++){
        if(accNum==accounts[i])found=true;
    }
    
    //Display Outputs
    if(found==true)cout<<"Number is valid"<<endl;
    else{
        cout<<"Number is invalid"<<endl;
    }

    //Exit Program
}
