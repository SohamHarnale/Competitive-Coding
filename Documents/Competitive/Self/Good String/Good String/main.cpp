//
//  main.cpp
//  Good String
//
//  Created by soham harnale on 1/20/17.
//  Copyright © 2017 Soham Harnale. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Initialize(int count[]) {
    for(int i=0; i<150; i++) {
        count[i] =0;
    }
}

/*void display(vector<char> &v1) {
    vector<char>::iterator it;
    for(it = v1.begin(); it != v1.end(); it++) {
        cout<<*it<<endl;
    }
}
*/

int Hash(char ch) {
    int ascii = int(ch);
    return ascii;
}

int main() {
    vector<char> v1;
    vector<char>::iterator it;
    int count[150], temp2;
    Initialize(count);
    string input;
    int hash, toDec=0;
    cin>>input;
    for(int i=0; input[i] != '\0'; i++) {
        v1.push_back(input[i]);
    }
    for(it = v1.begin(); it != v1.end(); it++) {
        char temp = *it;
        hash = Hash(temp);
        count[hash]++;
    }
    for(int j=0;j<150; j++) {
        if(count[j] == 0 || count[j] == 1) {
            continue;
        }
        else {
            temp2 = count[j] -1;
            toDec += temp2;
        }
    }
    cout<<toDec;
    return 0;
}
