//
//  main.cpp
//  FileHandling
//
//  Created by soham harnale on 10/23/16.
//  Copyright © 2016 Soham Harnale. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Phonebook {
    char name[30];
    long num;
public:
    
    void readdata() {
        cout<<"Enter name:"; cin>>name;
        cout<<"Enter code:"; cin>>num;

    }
    
    void writedata() {
        cout<<name<<" : "<<num<<" "<<endl;
    }
};

int main() {
    int op;
    char cont;
    fstream file;
    file.open("PHONEBOOk.bak", ios::ate | ios::in | ios::out | ios::binary);
    Phonebook p[2];
    cout<<"Initialising with 3 numbers"<<endl;
    for(int i=0; i<3; i++) {
        p[i].readdata();
        file.write((char*) &p[i], sizeof(p[i]));
    }

    cout<<"The numbers entered are:"<<endl;
    for(int i=0; i<3; i++) {
        file.read((char*) &p[i], sizeof(p[i]));
        p[i].writedata();
    }
    do {
        cout<<"1. Add number"<<endl;
        cout<<"2. Display"<<endl;
        cout<<"3. Count"<<endl;
        cout<<"4. Modify"<<endl;
        cout<<"Do what?"<<endl;
        cin>>op;
        switch(op) {
            case 1:
                Phonebook temp;
                temp.readdata();
                file.write((char*) &temp, sizeof(temp));
                break;
            case 1:
                Phonebook temp;
                temp.readdata();
                file.write((char*) &temp, sizeof(temp));
                break;
            case 2:
                file.seekg(0, ios::end);
                int last;
                last = file.tellg();
                int n = last/sizeof(temp);
                for(int i=0; i<n; i++) {
                    file.read((char*) &p[i], sizeof(p[i]));
                    p[i].writedata();
                }
                
                break;
            case 3:
                file.seekg(0, ios::end);
                last = file.tellg();
                n = last/sizeof(temp);
                cout<<"The count is:"<<endl;
                break;
            case 4:
                int pos;
                cout<<"Enter the position of the member to be updated"<<endl;
                cin>>pos;
                int location = (pos-1) * sizeof(temp);
                file.seekp(location);
                cout<<"Enter the new details of the member"<<endl;
                temp.readdata();
                file.write((char*) &temp, sizeof(temp));
                break;
            
            
            
                
        }
        cout<<"Continue?"<<endl;
        cin>>cont;
    } while(cont =='y' || cont =='Y');
    file.close();
    return 0;
}
