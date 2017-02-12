//
//  main.cpp
//  HackerRank in a String!
//
//  Created by soham harnale on 2/11/17.
//  Copyright © 2017 Soham Harnale. All rights reserved.
//

#include <iostream>
using namespace std;

string mainstr = "hackerrank";

int main() {
    int testcases, where;
    string str;
    bool *visited;
    cin>>testcases;
    visited = new bool[mainstr.length()];
    for(int i=0; i<testcases; i++) {
        where =0;
        cin>>str;
        for(int z=0; z<mainstr.length(); z++)
            visited[z] = false;
        for(int j=0; j<mainstr.length(); j++) {
            
            for(int k=((where==0) ? 0 : where+1); k<str.length(); k++) {
                if(str[k] == mainstr[j]) {
                    where = k;
                    visited[j] = true;
                    break;
                }
                else
                    continue;
            }
        }
        bool flag = true;
        for(int i=0; i<mainstr.length(); i++) {
            if(visited[i] == true)
                continue;
            else {
                cout<<"NO"<<endl;
                flag = false;
                break;
                
            }
        }
        if(flag)
            cout<<"YES"<<endl;
    }
    return 0;
    
}