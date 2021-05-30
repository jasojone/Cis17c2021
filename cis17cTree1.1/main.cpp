/* 
 * Modified:  from http://www.sanfoundry.com/cpp-program-implement-avl-trees/
 * Created on May 23, 2021, 9:14 PM
 * Purpose:  Example of using rotations to balance a tree
 */

//System Libraries
#include<iostream>
#include<algorithm>
using namespace std;
 
//User Libraries
#include "AVLTree.h"

//Global Constants

//Function Prototypes
void menu();

//Execution Begins Here!
int main(){
    int choice, item, size, x;
    AVLTree<int> avl;
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    do{
        menu();
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value to be inserted: ";
                cin>>item;
                avl.root = avl.insert(avl.root, item);
                break;
            case 2:
                cout<<"Enter number of elements to randomly fill the Tree: ";
                cin>>size;
                for (int i=0; i<size; i++){
                    int rNum = rand()%100+1; 
                    avl.root = avl.insert(avl.root, rNum);
                }
                break;
            case 3:
                if (avl.root == NULL){cout<<"Tree is Empty"<<endl;continue;}
                cout<<"Balanced AVL Tree:"<<endl;
                avl.display(avl.root,1);
                break;
            case 4:
                cout<<"Deleting Node: ";
                cin>>x;
                avl.root = avl.delNode(avl.root, x);
                break;
            case 5:
                cout<<"InOrder Traversal:"<<endl;
                avl.inorder(avl.root);
                cout<<endl;
                break;
            case 6:
                cout<<"PreOrder Traversal:"<<endl;
                avl.preorder(avl.root);
                cout<<endl;
                break;
            case 7:
                cout<<"PostOrder Traversal:"<<endl;
                avl.postorder(avl.root);    
                cout<<endl;
                break;
            case 8:
                cout<<"Breadth First/ LevelOrder Traversal:"<<endl;
                avl.levelOrder(avl.root);
                cout<<endl;
                break;
            default:
                cout<<"Exit Program"<<endl;
        }
    }while(choice>=0&&choice<=8);
    
    //Exit stage right!
    return 0;
}

void menu(){
    cout<<"\n---------------------"<<endl;
    cout<<"AVL Tree Implementation"<<endl;
    cout<<"\n---------------------"<<endl;
    cout<<"1.Insert Element into the tree"<<endl;
    cout<<"2.Randomly Fill the Tree with number of Elements"<<endl;
    cout<<"3.Display Balanced AVL Tree"<<endl;
    cout<<"4.Delete Node"<<endl;
    cout<<"5.InOrder Traversal"<<endl;
    cout<<"6.PreOrder Traversal"<<endl;
    cout<<"7.PostOrder Traversal"<<endl;
    cout<<"8.LevelOrder Traversal"<<endl;
    cout<<"9.Exit"<<endl;
    cout<<"Enter your Choice: ";
}