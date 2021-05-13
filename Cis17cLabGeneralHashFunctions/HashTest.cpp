/*
 **************************************************************************
 *                                                                        *
 *           General Purpose Hash Function Algorithms Test                *
 *                                                                        *
 * Author: Arash Partow - 2002                                            *
 * URL: http://www.partow.net                                             *
 * URL: http://www.partow.net/programming/hashfunctions/index.html        *
 *                                                                        *
 * Copyright notice:                                                      *
 * Free use of the General Purpose Hash Function Algorithms Library is    *
 * permitted under the guidelines and in accordance with the most current *
 * version of the Common Public License.                                  *
 * http://www.opensource.org/licenses/cpl1.0.php                          *
 *                                                                        *
 **************************************************************************
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <list>
#include <iterator>
#include <algorithm>
#include <iomanip>
#include "GeneralHashFunctions.h"

using namespace std;
string linSrch(string* ,int SIZE, string);
void selSort(string* a,int n);
string  binSrch(string* a,int n, string val);
string* fillary(int n,int wordsz);
void fillarySearchQ(string* ary, int n, string* rAry, int m);
string* arrayCopy(string*, int size);
void hasher(string* a, list<string>* b, int n);
int searchHash(list<string>* b, int n, string key);

int main(int argc, char* argv[])
{
    srand(static_cast<unsigned int>(time(0)));

    // The size of the array  
    const int SIZE = 50000;
    // The search query size 
    const int QSIZE = 50;
    // The size of the loop count for searches
    const int TSIZE = 100000;
    const int LSIZE = 1000;
    
    
    

    
    string* randWords = fillary(SIZE, 20);
    string* randWords2 = arrayCopy(randWords, SIZE);
    string* randWords3 = arrayCopy(randWords, SIZE);
    
    string searchQuery[QSIZE];
    fillarySearchQ(searchQuery, QSIZE, randWords, SIZE);
//    for (int i = 25; i < 50; i++ )
//    {
//        searchQuery[i] = "JasonLovesCPlusPlus";
//    }
    
    
    list<string>* hashList = new list<string>[SIZE]; 
    
    //cout << "Searching for key:  " << key << endl;
    double beg = time(0);
    // for loop for 10,000 then time it
    //cout << "Linear search :" << endl;
    for (int i = 0; i < LSIZE; i++)
    {
        for (int j = 0; j < QSIZE; j++)
        {
            linSrch(randWords, SIZE, searchQuery[j]);
        }
    }
    double end = time(0);
    //cout<<"For N = " << SIZE <<" Linear Search Takes " << setprecision(9) << 
    //      ((end-beg)/LSIZE)/QSIZE<<" Seconds " << "for " << LSIZE << " Searches" <<endl;
    cout << ((end-beg)/LSIZE)/QSIZE << endl;
    //selSort(randWords2, SIZE);
    sort(randWords2, randWords2 + SIZE );
    
    //cout << "Binary search :" << endl; 
    beg = time(0);
    // 1,000,000 times to search for 50 keys
    for (int i = 0; i < TSIZE; i++ )
    {
        for (int j = 0; j < QSIZE; j++)
        {
            //binSrch(randWords2, SIZE, searchQuery[j]);
            binary_search(randWords2, randWords2 + SIZE, searchQuery[j]);
        }
    }
    end = time(0);
   // cout<<"For N = " << SIZE <<" Binary Search Takes " << setprecision(9) << 
    //      ((end-beg)/TSIZE)/QSIZE<<" Seconds " << "for " << TSIZE << " Searches" <<endl;
    cout << ((end-beg)/TSIZE)/QSIZE << endl;
    hasher(randWords3, hashList, SIZE);
    
   // cout << "Hash search :" << endl; 
    beg = time(0);
    for (int i = 0; i < TSIZE; i++)
    {
        for (int j = 0; j < QSIZE; j++)
        {
            searchHash(hashList, SIZE, searchQuery[j]);
        }
    }
    end = time(0);
    //cout<<"For N = " << SIZE <<" Hash Search Takes " << setprecision(9) << 
    //      ((end-beg)/TSIZE)/QSIZE<<" Seconds " << "for " << TSIZE << " Searches" <<endl;
   cout << ((end-beg)/TSIZE)/QSIZE << endl;
//   cout << "Key:     " <<key<<endl;
//   cout << "Key:     " << endl;
//   cout << " 1. RS-Hash Function Value:   " <<setw(15)<< RSHash(key)<<endl;
//   cout << " 2. JS-Hash Function Value:   " <<setw(15)<< JSHash(key)   <<endl;
//   cout << " 3. PJW-Hash Function Value:  " <<setw(15)<< PJWHash(key)  <<endl;
//   cout << " 4. ELF-Hash Function Value:  " <<setw(15)<< ELFHash(key)  <<endl;
//   cout << " 5. BKDR-Hash Function Value: " <<setw(15)<< BKDRHash(key) <<endl;
//   cout << " 6. SDBM-Hash Function Value: " <<setw(15)<< SDBMHash(key) <<endl;
//   cout << " 7. DJB-Hash Function Value:  " <<setw(15)<< DJBHash(key)  <<endl;
//   cout << " 8. DEK-Hash Function Value:  " <<setw(15)<< DEKHash(key)  <<endl;
//   cout << " 9. FNV-Hash Function Value:  " <<setw(15)<< FNVHash(key)  <<endl;
//   cout << "10. BP-Hash Function Value:   " <<setw(15)<< BPHash(key)   <<endl;
//   cout << "11. AP-Hash Function Value:   " <<setw(15)<< APHash(key)   <<endl;

   return 0;
}

string linSrch(string* a,int SIZE, string val)
{
    for(int indx = 0; indx < SIZE; indx++){
        if(val == a[indx])return a[indx];
    }
    return "";
}

void selSort(string* a,int n)
{
    //Loop and declare variables
    int indx;
    string min;
    for(int pos=0;pos<n-1;pos++)
    {
        //Find the smallest in the list, swap after finding
        min = a[pos];indx = pos;
        for(int i=pos+1;i<n;i++){
            if(a[i]<min){
                min=a[i];
                indx=i;
            }
        }
        //Perform the swap
        a[indx] = a[pos];
        a[pos]=min;
    }
}

string  binSrch(string* a,int n, string val)
{
    //Initialize end points which are indexes
    int lowEnd=0;
    int highEnd=n-1;
    //Loop until value found not indexes
    do{
        int middle=(highEnd+lowEnd)/2;
        if(val==a[middle])return a[middle];
        else if(val>a[middle])lowEnd=middle+1;
        else highEnd=middle-1;
    }while(lowEnd<=highEnd);
    
    //Not found
    return NULL;
}

string* fillary(int n,int wordsz)
{
    string* ary = new string[n];
    string word;
    char letter;
    for(int i = 0; i < n; i++){
        for(int j = 0; j<wordsz; j++)
        {
            if(j == 0)letter = rand()%25+65;
            else letter = rand()%25+97;
            word+=letter;
        }
        ary[i] = word;
        word = "";
    }
 return ary;
}
   
void fillarySearchQ(string* ary, int n, string* rAry, int m)
{
    for(int i = 0; i < n/2; i++)
    {
        ary[i] = "I Love C Plus Plus";
    }
    for (int i = n/2; i < n; i++)
    {
        ary[i] = rAry[rand()%m];
    }
}

string* arrayCopy(string* orig, int size)
{
    string* copy=new string[size];
    
    for (int i = 0; i < size; i++)
    {
        copy[i] = orig[i];
    }
    return copy;
}

void hasher(string* a, list<string>* b, int n)
{
    for (int i = 0; i < n; i++)
    {
        b[RSHash(a[i])%n].push_back(a[i]);
    }
}

int searchHash(list<string>* b, int n, string key)
{
    list<string>::iterator it = find(b[RSHash(key)%n].begin(), b[RSHash(key)%n].end(), key);
    if (it == b[RSHash(key)%n].end())
        return -1;
    return distance(b[RSHash(key)%n].begin(), it);
}
