//
//  main.cpp
//  Mind Palaces
//
//  Created by soham harnale on 1/17/17.
//  Copyright © 2017 Soham Harnale. All rights reserved.
//

#include <iostream>
using namespace std;


int main() {
    int rows, columns, key, queries;
    cin>>rows>>columns;
    int arr[rows][columns];
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            cin>>arr[i][j];
        }
    }
    cin>>queries;
    for(int k=0; k<queries; k++) {
        cin>>key;
        int l = rows-1; int m= 0;
        int temp;
        bool found = false;
        while(l>=0 && m < columns) {
            temp = arr[l][m];
            if(key == temp) {
                cout<<l<<" "<<m<<endl;
                found = true;
                break;
            }
            else if(key<temp) {
                l=l-1;
            }
            else if(key>temp) {
                m=m+1;
            }
        }
        if(found == false)
            cout<<-1<<" "<<-1<<endl;
    }
    
}