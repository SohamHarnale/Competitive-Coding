//
//  main.cpp
//  Day of the Programmer
//
//  Created by soham harnale on 2/20/17.
//  Copyright © 2017 Soham Harnale. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    bool leap = false, julian = false, greg = false;
    int year, sum=0, days, i;
    cin>>year;
    
    //Special Case: 1918
    if(year==1918) {
        cout<<"27.07.1918";
        return  0;
        /*for(i=0; i<8; i++) {
            if(i==1) {
                sum += 14;
                continue;
            }
            else if(i%2==0 || i==7) sum = sum + 31;
            //else if(i==1) sum += 29;
            else sum = sum + 30;
        }
        days = 256 - sum;*/
        
    }
    
    //Julian?
    if(year > 1700 && year <= 1917) {
        julian = true;
        if(year%4==0) leap = true;
        else leap = false;
    }
    //Gregorian?
    else if(year > 1918) {
        greg = true;
        if(year%400 == 0 || (year%4==0 && year%100 != 0)) leap = true;
        else leap = false;
    }
    //Julian subcases
    if(julian) {
        if(leap) {
            for(i=0; i<8; i++) {
                if(i%2==0 || i==7) sum = sum + 31;
                else if(i==1) sum += 29;
                else sum = sum + 30;
            }
        }
        if(!leap) {
            for(i=0; i<8; i++) {
                if(i%2==0 || i==7) sum = sum + 31;
                else if(i==1) sum += 28;
                else sum = sum + 30;
            }
        }
    }
    
    //Gregorian subcases
    else if(greg) {
        if(leap) {
            for(i=0; i<8; i++) {
                if(i%2==0 || i==7) sum = sum + 31;
                else if(i==1) sum += 29;
                else sum = sum + 30;
            }
        }
        if(!leap) {
            for(i=0; i<8; i++) {
                if(i%2==0 || i==7) sum = sum + 31;
                else if(i==1) sum += 28;
                else sum = sum + 30;
            }
        }
    }
    days = 256-sum;
    cout<<days<<".09"/*<<i+1<<*/<<"."<<year;
    return 0;
}