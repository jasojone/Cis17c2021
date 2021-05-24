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
void heapify(int arr[], int n, int i, ll &ops);
void heapSort(int arr[], int n, ll &ops);
void swap(int *a, int *b);

//Program Execution Begins Here
int main(int argc, char** argv) 
{
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    const int SIZE=10000;
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
        heapSort(array, SIZE, ops);
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

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i, ll &ops)
{
    ops += 13;
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
    {
        ops += 7;
        largest = l;
    }
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
    {
        ops += 7;
        largest = r;
    }
    
    // If largest is not root
    if (largest != i) 
    {
        ops += 3;
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest, ops);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n, ll &ops)
{
    ops += 3;
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        ops += 5;
        heapify(arr, n, i, ops);
    }
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        ops += 7;
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0, ops);
    }
}

void fillAry(int a[],int n,int hr,int lr)
{
    for(int indx=0;indx<n;indx++)
    {
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}

