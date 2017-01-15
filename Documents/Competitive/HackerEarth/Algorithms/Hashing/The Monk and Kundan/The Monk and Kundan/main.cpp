//
//  main.cpp
//  The Monk and Kundan
//
//  Created by soham harnale on 1/15/17.
//  Copyright © 2017 Soham Harnale. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string initial = "abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int findHash(char *c) {
    char temp1 = *c;
    int temp = int(temp1);
    int hash;
    
    
    if(temp>=97 && temp <= 122) {
        hash = temp - 97;
        return hash;
    }
    else if(temp >=48 && temp <= 57) {
        if(temp == 48)
            return 35;
        else {
            hash = temp - 23;
            return hash;
        }
        
    }
    else {
        hash = temp - 29;
        return hash;
    }
    
}

int findAns(char *p) {
    int ans = 0, index, hash;
    
    for(char *i = p, index =0; *i; i++, index++) {
        hash = findHash(i);
        ans += index + hash;
    }
    
    return ans;
}



int main() {
    char input[1000], *p;
    int testcases;
    int elements = 0, ans = 0;
    
    cin >> testcases;
    cin.ignore();
   
    for(int i=0; i<testcases; ++i){
        
        cin.getline(input, sizeof(input));
        p = strtok(input, " ");
        while(p != NULL) {
            ans += findAns(p);
            p  = strtok(NULL, " ");
            elements++;
        }
        cout<<ans*elements<<endl;
        elements = 0; ans = 0;
       
        
    }
    
    
    return 0;
}

/* SPLITTING CHARACTER ARRAY
 cin.getline(input, sizeof(input));
 p = strtok(input, " ");
 while(p != NULL) {
 cout<<p<<endl;
 p  = strtok(NULL, " ");
 }
*/