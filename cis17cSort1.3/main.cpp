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
void merge(int arr[], int l, int m, int r, ll &ops );
void mergeSort(int arr[],int l,int r, ll &ops);
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
        mergeSort(array, 0, SIZE, ops);
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

// Merge two subarrays L and M into arr
void merge(int arr[], int l, int m, int r, ll &ops)
{
    ops += 16;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
    {
        ops += 9;
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        ops += 16;
        R[j] = arr[m + 1 + j];
    }
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2) {
        ops += 3;
        if (L[i] <= R[j]) {
            ops + 8;
            arr[k] = L[i];
            i++;
        }
        else {
            ops += 5;
            arr[k] = R[j];
            j++;
        }
        ops += 1;
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        ops += 7;
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        ops += 7;
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[],int l,int r, ll &ops)
{
    if(l>=r)
    {
        return;//returns recursively
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m,ops);
    mergeSort(arr,m+1,r,ops);
    merge(arr,l,m,r,ops);
}

void fillAry(int a[],int n,int hr,int lr)
{
    for(int indx=0;indx<n;indx++)
    {
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}

