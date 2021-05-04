/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jason
 *
 * Created on May 4, 2021, 1:24 AM
 */
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    freopen("input1.txt", "r", stdin); 
    string s;
    int nonComment = 0, comment = 0, total = 0, emptyLine = 0;
    while(getline(cin, s)){
        bool first = 1;
        bool isComment = 0;
        int blank = 0;
        for(int i = 0; i < s.length(); i++){
            if(isspace(s[i])){
                blank++;
                continue;
            }
            if(i && s[i] == '/' && s[i-1] == '/')
                isComment = 1;
            if(i && s[i] == '*' && s[i-1] == '/')
                isComment = 1;
            if(i && s[i] == '/' && s[i-1] == '*')
                isComment = 1;
            if(first && s[i] == '*')
                isComment = 1;
            first = 0;
        }
        total++;
        if(blank == s.length()){
            emptyLine++;
            continue;
        }
        if(isComment)
            comment++;
        else
            nonComment++;
    }
    //freopen("output.txt", "w", stdout); 
    cout<<"Total number of lines: "<<total<<endl;
    cout<<"Number of comments: "<<comment<<endl;
    cout<<"Number of regular lines: "<<nonComment<<endl;
    cout<<"Number of blank lines: "<<emptyLine<<endl;
    return 0;
}

