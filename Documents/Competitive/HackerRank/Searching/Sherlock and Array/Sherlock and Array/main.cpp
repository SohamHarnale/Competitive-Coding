//
//  main.cpp
//  Sherlock and Array
//
//  Created by soham harnale on 2/17/17.
//  Copyright © 2017 Soham Harnale. All rights reserved.
//

#include <iostream>
using namespace std;


int main() {
    int testcases, *array, size, numl=0, numr=0;
    cin>>testcases;
    for(int k=0; k<testcases; k++) {
        cin>>size;
        if(size==1) {
            cout<<"NO";
            break;
        }
        array = new int[size];
        for(int j=0; j<size; j++) cin>>array[j];
        int i=0; int j=size-1;
        numl = array[i];
        numr = array[j];
        while(i<size) {
            
            
            if(numl == numr && j-i == 2/*&& i != 0 && j!= size -1*/) {
                    cout<<"YES"<<endl;
                    break;
            }
            
            else if(numl > numr) {
                numr = numr + array[j-1];
                j = j-1;
                continue;
            }
            else if(numl < numr) {
                numl = numl + array[i+1];
                i=i+1;
                continue;
            }
            else {
                cout<<"NO"<<endl;
                break;
            }
            
            
        }
    }
    return 0;
}
