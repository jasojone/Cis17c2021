/*
 * File:   main.cpp
 * Author: Jason
 *
 * Created on June 6, 2021, 9:28 PM
 */
#include "HashMap.h"
#include "AVLTree.h"

using namespace std;

/*
 * 2=ABC 3=DEF 4=GHI 5=JKL 6=MNO 7=PQRS 8=TUV 9=WXYZ
 */
string initialGen();
int pnpHash(string inits);
void testPerformce(vector<pair<int, string>>& input, MyHashMap* hashMap, AVLTree<int>& avlTree, int SIZE);

int main(int argc, char** argv) {

    //srand(time(NULL));
    srand(static_cast<unsigned int>(time(0)));
    const int SIZE = 512;

    MyHashMap* hashMap = new MyHashMap();
    AVLTree<int> avlTree;
    vector<pair<int, string>> input;

    string tmpInit;
    int tmpInitNum;

    for (int i = 0; i < SIZE; i++)
    {
        //cout << tmpInit << endl;
        tmpInit = initialGen();
        tmpInitNum = pnpHash(tmpInit);
        hashMap->put(tmpInitNum, tmpInit);
        avlTree.root = avlTree.insert(avlTree.root, tmpInitNum, tmpInit);
        input.push_back(make_pair(tmpInitNum, tmpInit));
    }

    testPerformce(input, hashMap, avlTree, SIZE);

    return 0;
}

void testPerformce(vector<pair<int, string>>& input, MyHashMap* hashMap, AVLTree<int>& avlTree, int SIZE)
{
    map<int, int> collisions = hashMap->getCollisions();

//    for (int i = 0; i < 30; i++)
//    {
//        int rIdx = rand() % input.size();
//
//        int hashSpeed = hashMap->search(input[rIdx].first, input[rIdx].second);
//        int avlSpeed = avlTree.search(avlTree.root, input[rIdx].first, input[rIdx].second);
//
//        cout << "Finding inits " << input[rIdx].second << " with phone pad code " << input[rIdx].first << endl;
//        cout << "HashMap Traversal count: " << hashSpeed << endl;
//        cout << "AVL Tree Traversal count: " << avlSpeed << endl << endl;
//    }
    
    float tSum = 0;
    for(int i = 0; i < input.size(); i++)
    {
         tSum += avlTree.search(avlTree.root, input[i].first, input[i].second);
    }
    float hSum = 0;
    int counter = 0;
    map<int, int>::iterator it = collisions.begin();
    
    for (it; it != collisions.end(); ++it) 
    {
        if (counter >= 2) {
            hSum += it->first * it->second;
        }
        counter++;
    }
    it--;

    cout << "The height for the AVL tree is: " << log2(512) << endl;
    cout << "The depth for the AVL tree is: " << log2(512)-1 << endl;
    cout << "The maximum depth for the hash map: " << it->first << endl;
    cout << "The average tree Traversal: " << (tSum/SIZE) << endl;
    cout << "The average hash Traversal: " << (hSum/SIZE)<< endl;
    //avlTree.display(avlTree.root, 1);
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
    //cout << initsToNum << endl;
    return stoi(initsToNum);
}

string initialGen() {
    string initials = "";

    for (int i = 0; i < 3; i++) {
        initials += (rand() % 26 + 65);
    }
    return initials;
}