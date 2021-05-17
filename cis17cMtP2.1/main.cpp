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
ll selSort(int [],int);

//Program Execution Begins Here
int main(int argc, char** argv) 
{
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    const int SIZE=8000;
    int *array = new int[SIZE];
    int lowRng=0,highRng=SIZE;
    int loopCnt = 1000;
    ll operation = 0LL;
    
    //start time
    time_point<system_clock> start, end;
    duration<float> t = duration<float>::zero();
        
    //Loop through the array 1000 times
    for(int i = 0; i < loopCnt; ++i) 
    {
        fillAry(array,SIZE,highRng,lowRng);
        start = system_clock::now();
        selSort(array,SIZE);
        operation += selSort(array,SIZE);
        t += system_clock::now() - start;
    }
    
    //Output operations
    cout<<"Array Size:      "<<SIZE<<endl;
    cout<<"Loop Count:      "<<loopCnt<<endl;
    cout<<"Operations:      "<<operation / loopCnt<<endl;
    cout<<"Average Time:    "<<t.count() / loopCnt<<" Seconds"<<endl;
    
    //Exit
    delete [] array;
    return 0;
}

ll selSort(int a[],int n)
{
    //Loop and declare variables
    int indx,min;
    ll ops = 4;
    for(int pos=0;pos<n-1;pos++)
    {
        //Find the smallest in the list, swap after finding
        min=a[pos];indx=pos;
        ops += 7;
        for(int i=pos+1;i<n;i++)
        {
            ops += 3;
            if(a[i]<min){
                min=a[i];
                indx=i;
                ops += 3;
            }
            ops += 4;
        }
        //Perform the swap
        a[indx]=a[pos];
        a[pos]=min;
        ops += 9;
    }
    return ops;
}

void fillAry(int a[],int n,int hr,int lr)
{
    for(int indx=0;indx<n;indx++)
    {
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}