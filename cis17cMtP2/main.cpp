//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;
typedef long long ll;

//Function Prototypes Here
void fillAry(int [],int,int,int);
ll bublSrt(int [],int);

//Program Execution Begins Here
int main(int argc, char** argv) 
{
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    const int SIZE=2500;
    int *array = new int[SIZE];
    int lowRng=0,highRng=SIZE;
    int loopCnt = 1000;
    ll operations = 0LL;
    //double beg = time(0);
    //double end = time(0);
    //clock_t t;
    
    //Start time
    //t = clock() - t;
    //double time_taken = ((double)t)/CLOCKS_PER_SEC;
    time_point<system_clock> start, end;
    duration<float> t = duration<float>::zero();
        
    //Loop through the array 1000 times
    for(int i = 0; i < loopCnt; ++i) 
    {
        fillAry(array,SIZE,highRng,lowRng);
        start = system_clock::now();
        //t = clock();
        //beg = time(0);
        operations += bublSrt(array,SIZE);
        //end = time(0);
        //t = clock() - t;
        t += system_clock::now() - start;
    }
    //Output operations
    cout<<"Array Size:      "<<SIZE<<endl;
    cout<<"Loop Count:      "<<loopCnt<<endl;
    cout<<"Operations:      "<<operations / loopCnt<<endl;
    cout<<"Average Time:    "<<t.count() / loopCnt<<" Seconds"<<endl;
    //cout<<"Average Time:    "<<time_taken / loopCnt<<" Seconds"<<endl;
    //cout<<"Average Time:    "<<(end-beg) / loopCnt<<" Seconds"<<endl;
    
    //Exit
    delete [] array;
    return 0;
}
ll bublSrt(int a[],int n)
{
    //Keep looping and comparing until no swaps are left
    ll ops = 0LL;
    bool swap;
    do
    {
        swap=false;
        //Check the list and Swap when necessary
        for(int i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1])
            {
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swap=true;
                ops += 10;
            }
        }
    }while(swap);
    return ops;
}
void fillAry(int a[],int n,int hr,int lr)
{
    for(int indx=0;indx<n;indx++)
    {
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}