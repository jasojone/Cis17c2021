/* 
 * File:   BNTnode.h
 * Modified:  from http://www.sanfoundry.com/cpp-program-implement-AVL-trees/
 * Created on May 23, 2021, 9:14 PM
 * Purpose:  An Binary Tree using an AVL balancing technique
 */

#ifndef AVLTREE_H
#define	AVLTREE_H

#include <iostream>
#include <cstdlib>
#include <queue>
#include <algorithm>

using namespace std;

#include "BNTnode.h"

template <typename T>
class AVLTree{
    public:
        BNTnode *root;                   //Root node
        int height(BNTnode *);           //Tree height
        int diff(BNTnode *);             //Difference of right/left subtrees
        BNTnode *rr_rotation(BNTnode *); //Right-Right rotation
        BNTnode *ll_rotation(BNTnode *); //Left-Left   rotation
        BNTnode *lr_rotation(BNTnode *); //Left-Right  rotation
        BNTnode *rl_rotation(BNTnode *); //Right-Left  rotation
        BNTnode* balance(BNTnode *);     //Balance subtrees with diff > 1
        BNTnode* insert(BNTnode *, int );//Insert and balance the tree
        BNTnode* delNode(BNTnode *, int);//Delete a node and balance 
        void display(BNTnode *, int);    //Funky display root left to right
        void inorder(BNTnode *);         //In order display
        void preorder(BNTnode *);        //Pre order display
        void postorder(BNTnode *);       //Post order display
        void levelOrder(BNTnode *);      //Level order display
        AVLTree(){root = NULL;}          //Constructor
};

//******************************************************************************
//                            Height of AVL Sub Trees
//******************************************************************************
template <typename T>
int AVLTree<T>::height(BNTnode *temp){
    int h = 0;
    if (temp != NULL){
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
 
//******************************************************************************
//                      Height Difference of AVL Sub Trees
//******************************************************************************
template <typename T>
int AVLTree<T>::diff(BNTnode *temp){
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}
 
//******************************************************************************
//                      Right-Right Rotations of Sub Trees
//******************************************************************************
template <typename T>
BNTnode *AVLTree<T>::rr_rotation(BNTnode *parent){
    BNTnode *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

//******************************************************************************
//                      Left-Left Rotations of Sub Trees
//******************************************************************************
template <typename T>
BNTnode *AVLTree<T>::ll_rotation(BNTnode *parent){
    BNTnode *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
 
//******************************************************************************
//                      Left-Right Rotations of Sub Trees
//******************************************************************************
template <typename T>
BNTnode *AVLTree<T>::lr_rotation(BNTnode *parent){
    BNTnode *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}
 
//******************************************************************************
//                      Right-Left Rotations of Sub Trees
//******************************************************************************
template <typename T>
BNTnode *AVLTree<T>::rl_rotation(BNTnode *parent){
    BNTnode *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}
 
//******************************************************************************
//                         Balancing of Sub Trees
//******************************************************************************
template <typename T>
BNTnode *AVLTree<T>::balance(BNTnode *temp){
    int bal_factor = diff (temp);
    if (bal_factor > 1){
        if (diff (temp->left) > 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
    }else if (bal_factor < -1){
        if (diff (temp->right) > 0)
            temp = rl_rotation (temp);
        else
            temp = rr_rotation (temp);
    }
    return temp;
}
 
//******************************************************************************
//                    Insert the Data into the Sub Trees
//******************************************************************************
template <typename T>
BNTnode *AVLTree<T>::insert(BNTnode *root, int value){
    if (root == NULL){
        root = new BNTnode;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }else if (value < root->data){
        root->left = insert(root->left, value);
        root = balance (root);
    }else if (value >= root->data){
        root->right = insert(root->right, value);
        root = balance (root);
    }
    return root;
}
//******************************************************************************
//                     Delete a node from the tree
//******************************************************************************
template <typename T>
BNTnode *AVLTree<T>::delNode(BNTnode *root, int x){
    //standard delete
    if (root == NULL)
        return root;
    //if x is smaller than root->data then it is in the left subTree
    if (x < root->data){
        root->left = delNode(root->left, x);
    }
    //if x is greater than root->data then it is in the right subTree
    else if (x < root->data){
        root->right = delNode(root->right, x);
    }
    //if x = root->data delete node
    else
    {
        //node with one or no child
        if ((root->left == NULL) || (root->right == NULL)){
            BNTnode *temp = root->left ? root->left : root->right;
            //no child
            if (temp == NULL){
                temp = root;
                root == NULL;
            }
            else //one child
                *root = *temp;
            
            free(temp);
        }
        else{
            //node with two children get the inOrder successor
            //(smallest in the right subTree)
            BNTnode* current = root;
            //loop down to find the leftMost leaf
            while (current->left != NULL)
                current = current->left;
            
            //copy the inOrder successors data to this node
            root->data = current->data;
            //delete the inOrder successor
            root->right = delNode(root->right, current->data);
        }
    }
    //if tree had one node
    if (root == NULL)
        return root;
    
    root = balance(root);
    
    return root;
}

 
//******************************************************************************
//                         Display all Sub Trees
//******************************************************************************
template <typename T>
void AVLTree<T>::display(BNTnode *ptr, int level){
    int i;
    if (ptr!=NULL){
        display(ptr->right, level + 1);
        cout<<endl;
        if (ptr == root)
        cout<<"R -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"     ";
        cout<<ptr->data;
        display(ptr->left, level + 1);
    }
}
 
//******************************************************************************
//                      In-order Output of Tree
//******************************************************************************
template <typename T>
void AVLTree<T>::inorder(BNTnode *tree){
    if (tree == NULL)
        return;
    inorder (tree->left);
    cout<<tree->data<<"  ";
    inorder (tree->right);
}

//******************************************************************************
//                      Pre-order Output of Tree
//******************************************************************************
template <typename T>
void AVLTree<T>::preorder(BNTnode *tree){
    if (tree == NULL)
        return;
    cout<<tree->data<<"  ";
    preorder (tree->left);
    preorder (tree->right);
}
 
//******************************************************************************
//                      Post-order Output of Tree
//******************************************************************************
template <typename T>
void AVLTree<T>::postorder(BNTnode *tree){
    if (tree == NULL)
        return;
    postorder ( tree ->left );
    postorder ( tree ->right );
    cout<<tree->data<<"  ";
}
//******************************************************************************
//                     Level-order Output of Tree
//******************************************************************************
template <typename T>
void AVLTree<T>::levelOrder(BNTnode *root){
    // Base Case
    if (root == NULL)  return;
 
    // Create an empty queue for level order traversal
    queue<BNTnode *> q;
 
    // Enqueue Root and initialize height
    q.push(root);
 
    while (q.empty() == false)
    {
        // Print front of queue and remove it from queue
        BNTnode *node = q.front();
        cout << node->data << " ";
        q.pop();
 
        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);
 
        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }

}
#endif	/* AVLTREE_H */