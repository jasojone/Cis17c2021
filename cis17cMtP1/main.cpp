//Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

//Function Prototypes
void fillAry(int [],int,int,int);
int  linSrch(int [],int, int);


int main(int argc, char** argv) 
{
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    const int SIZE=1000000;
    int *array = new int[SIZE];
    int lowRng=0,highRng=SIZE;
    int loopCnt = 10000;
    int answer = 0;
    double beg = time(0);
    double endd = time(0);
    
    //Finish initializing the rest of the array
    fillAry(array,SIZE,highRng,lowRng);

    
    // Start time
    beg = time(0);
    auto start = high_resolution_clock::now();
    
    //Test the linear search by looping randomly chosen values
    for(int i = 0; i < loopCnt; ++i) 
    {
        int value=rand()%(highRng-lowRng+1)+lowRng;
        answer += linSrch(array,SIZE,value);
    }
    // End time 
    endd = time(0);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    //Output results
    cout<<"Array Size:      "<<SIZE<<endl;
    cout<<"Loop Count:      "<<loopCnt<<endl;
    cout<<"Operations:      "<<answer / loopCnt<<endl;
    cout<<"Average Time:    "<<(endd-beg) / loopCnt<<" Seconds"<<endl;
    cout<<"Average Time:    "<<duration.count() / loopCnt<<" Micro Seconds"<<endl;
    
    //Exit
    delete [] array;
    return 0;
}
int  linSrch(int a[],int n, int val)
{
  
    int ops = 0;
    
    //Loop until value found
    for(int indx=0;indx<n;indx++)
    {
        if(val==a[indx])return ops;
        ops += 5;
    }
    //Not found
    return ops;
}

void fillAry(int a[],int n,int hr,int lr)
{
    for(int indx=0;indx<n;indx++)
    {
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}