/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ScoreTree.h
 * Author: Jason
 *
 * Created on May 31, 2021, 12:38 PM
 */

#ifndef SCORETREE_H
#define SCORETREE_H

struct Node
{
    int score;
    string name;
    Node *left;
    Node *right;

    Node(int fScore, string fName)
    {
        score = fScore;
        name = fName;
        left = NULL;
        right = NULL;
    }

    void insert(Node *player)
    {
        if (player->score < this->score)
        {
            if (this->left == NULL)
            {
                this->left = player;
            }
            else
            {
                this->left->insert(player);
            }
        }
        else
        {
            if (this->right == NULL)
            {
                this->right = player;
            }
            else
            {
                this->right->insert(player);
            }
        }
    }
};

class ScoreTree
{
private:
    Node* root;
public:
    ScoreTree()
    {
        root = NULL;
    }
    void insert(int score, string name)
    {
        if (root == NULL)
        {
            root = new Node(score, name);
        }
        else
        {
            Node* player = new Node(score, name);
            root->insert(player);
        }
    }
    //Node* getRoot()
    //{
    //    return root;
    //}
    void printScoreRecords()
    {
        printScoreRecords(root);
    }
    void printScoreRecords(Node* root)
    {
        if (root == NULL)
            return;
        printScoreRecords(root->left);
        cout << "Name: " << root->name << "\nScore:  " << root->score << endl <<endl;
        printScoreRecords(root->right);
    }
};


#endif /* SCORETREE_H */

