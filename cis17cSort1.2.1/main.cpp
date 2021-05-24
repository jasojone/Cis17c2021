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
int shellSort(int arr[], int n, ll &ops);
void swap(int *a, int *b);

//Program Execution Begins Here
int main(int argc, char** argv) 
{
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    const int SIZE=1000;
    int *array = new int[SIZE];
    //int n = sizeof(array) / sizeof(array[0]);
    int lowRng=0,highRng=SIZE;
    int loopCnt = 1000;
    ll ops = 0;
    
    //start time
    time_point<system_clock> start, end;
    duration<float> t = duration<float>::zero();
        
    //Loop through the array 1000 times
    for(int i = 0; i < loopCnt; ++i) 
    {
        fillAry(array,SIZE,highRng,lowRng);
        start = system_clock::now();
        shellSort(array, SIZE, ops);
        //operation += selSort(array,SIZE);
        t += system_clock::now() - start;
    }
    
    //Output operations
    cout<<"Array Size:      "<<SIZE<<endl;
    cout<<"Loop Count:      "<<loopCnt<<endl;
    cout<<"Operations:      "<<ops / loopCnt<<endl;
    cout<<"Average Time:    "<<t.count() / loopCnt<<" Seconds"<<endl;
    
    //Exit
    delete [] array;
    return 0;
}

int shellSort(int arr[], int n, ll &ops)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        ops += 5;
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            ops += 9;
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
 
            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;           
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                ops += 12;
                arr[j] = arr[j - gap];
            }
            ops += 3;
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}

void fillAry(int a[],int n,int hr,int lr)
{
    for(int indx=0;indx<n;indx++)
    {
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}

