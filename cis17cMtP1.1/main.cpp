//Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;


//Function Prototypes
void fillAry(int [],int,int,int);
int  binSrch(int [],int, int);


int main(int argc, char** argv) 
{
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    const int SIZE=100000000;
    int *array = new int[SIZE];
    int lowRng=0,highRng=SIZE;
    int loopCnt = 1000000;
    int operations = 0;
    //double beg = time(0);
    //double endd = time(0);
    clock_t t;
        
    //Finish initializing the rest of the array
    fillAry(array,SIZE,highRng,lowRng);
    
    //Start time
    t = clock();
    //beg = time(0);
    //auto start = high_resolution_clock::now();
    
    //Test the binary search by looping randomly chosen values
    for(int i = 0; i < loopCnt; ++i) 
    {
        int value=rand()%(highRng-lowRng+1)+lowRng;
        operations += binSrch(array,SIZE,value);
    }
    
    // End time 
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    //endd = time(0);
    //auto stop = high_resolution_clock::now();
    //auto duration = duration_cast<microseconds>(stop - start);
    
    //Output
    cout<<"Array Size:      "<<SIZE<<endl;
    cout<<"Loop Count:      "<<loopCnt<<endl;
    cout<<"Operations:      "<<operations / loopCnt<<endl;
    cout<<"Average Time:    "<<time_taken / loopCnt<<" Seconds"<<endl;
   // cout<<"Average Time:    "<<(endd-beg) / loopCnt<<" Seconds"<<endl;
   // cout<<"Average Time:    "<<duration.count() / loopCnt<<" Micro Seconds"<<endl;

    //Exit
    delete [] array;
    return 0;
}
int  binSrch(int a[],int n, int val)
{
    //Declare the Variables 
    int lowEnd=0;
    int highEnd=n-1;
    int ops = 3;
    
    //Loop until value found not indexes
    do
    {
        int middle=(highEnd+lowEnd)/2;
        ops += 12;
        if(val==a[middle])return ops;
        else if(val>a[middle])lowEnd=middle+1;
        else highEnd=middle-1;
    }while(lowEnd<=highEnd);
    
    //Not found
    return ops;
}

void fillAry(int a[],int n,int hr,int lr)
{
    for(int indx=0;indx<n;indx++){
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}
