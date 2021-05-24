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
int partition(int array[], int low, int high, ll &ops);
void quickSort(int array[], int low, int high, ll &ops);
void swap(int *a, int *b);

//Program Execution Begins Here
int main(int argc, char** argv) 
{
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    const int SIZE=5000;
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
        quickSort(array, 0, SIZE, ops);
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

void quickSort(int array[], int low, int high, ll &ops) 
{
    ops +=1;
  if (low < high) 
  {
      ops += 3;
      
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high, ops);

    // recursive call on the left of pivot
    quickSort(array, low, pi - 1, ops);

    // recursive call on the right of pivot
    quickSort(array, pi + 1, high, ops);
  }
}
// function to rearrange array (find the partition point)
int partition(int array[], int low, int high, ll &ops) 
{
    ops += 7;
    // select the rightmost element as pivot
    int pivot = array[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++) 
    {
        ops += 2;
        if (array[j] <= pivot) 
        {
        ops += 6;
        // if element smaller than pivot is found
        // swap it with the greater element pointed by i
        i++;

        // swap element at i with element at j
        swap(&array[i], &array[j]);
        } 
    }
    ops += 7;
    // swap pivot with the greater element at i
    swap(&array[i + 1], &array[high]);

    // return the partition point
    return (i + 1);
}
// function to swap elements
void swap(int *a, int *b) 
{
  int t = *a;
  *a = *b;
  *b = t;
}

void fillAry(int a[],int n,int hr,int lr)
{
    for(int indx=0;indx<n;indx++)
    {
        //a[indx]=rand()%(hr-lr+1)+lr;
        a[indx];
    }
}

