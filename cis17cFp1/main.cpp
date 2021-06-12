/*
 * File:   main.cpp
 * Author: Jason
 *
 * Created on June 6, 2021, 9:28 PM
 */
#include "HashMap.h"

using namespace std;

/*
 * 2=ABC 3=DEF 4=GHI 5=JKL 6=MNO 7=PQRS 8=TUV 9=WXYZ
 */

string initialGen() {
    string initials = "";

    for (int i = 0; i < 3; i++) {
        initials += (rand() % 26 + 65);
    }
    return initials;
}

int pnpHash(string inits) {

    string initsToNum = "";
    for (int i = 0; i < 3; i++) {
        if (inits[i] >= 65 && inits[i] <= 67) {
            initsToNum += "2";
        }
        else if (inits[i] >= 68 && inits[i] <= 70) {
            initsToNum += "3";
        }
        else if (inits[i] >= 71 && inits[i] <= 73) {
            initsToNum += "4";
        }
        else if (inits[i] >= 74 && inits[i] <= 76) {
            initsToNum += "5";
        }
        else if (inits[i] >= 77 && inits[i] <= 79) {
            initsToNum += "6";
        }
        else if (inits[i] >= 80 && inits[i] <= 83) {
            initsToNum += "7";
        }
        else if (inits[i] >= 84 && inits[i] <= 86) {
            initsToNum += "8";
        }
        else if (inits[i] >= 85 && inits[i] <= 90) {
            initsToNum += "9";
        }
    }
    return stoi(initsToNum);
}

int main(int argc, char** argv) {
    
    //srand(time(NULL));
    srand(static_cast<unsigned int>(time(0)));
    const int SIZE = 512;

    MyHashMap *hashMap = new MyHashMap();
    map<int, int> collisions;
    //hashMap->put(635, "MEL");
    //hashMap->put(635, "MDJ");
    //hashMap->put(635, "MEL");

    string tmpInit;
    int tmpInitNums;

    for (int i = 0; i < SIZE; i++) 
    {
        tmpInit = initialGen();
        tmpInitNums = pnpHash(tmpInit);
        hashMap->put(tmpInitNums, tmpInit);
    }
    
    collisions = hashMap->getCollisions();

    for (map<int, int>::iterator it = collisions.begin(); it != collisions.end(); ++it) 
    {
        if (it->first <= 1)
            cout << it->first << " Elements   " << it->second << " times " << setprecision(3) << fixed <<((double)it->second / (double)512)*100 << "%\n";
        else
            cout << it->first << " Collisions " << it->second << " times " << ((double)it->second / (double)512)*100 << "%\n";
    }
    return 0;
}
// still need to calculate the expected 