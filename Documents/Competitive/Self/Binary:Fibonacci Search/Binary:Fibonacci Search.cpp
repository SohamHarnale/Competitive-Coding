/*
 * Name: Soham Harnale
 * Roll No: SE202061
 */


#include<iostream>
using namespace std;
int n;
class cSearch{
private:
    int Roll[20];
    int KEY;
public:
    void Accept();
    int Sequen();
    int Sentinel();
    int BinarySearch();
    int FiboSearch();
    int Fibo(int);
};

void cSearch::Accept(){
    cout<<"Enter the total no. of students:"<<endl;
    cin>>n;
    cout<<"Enter the Roll Numbers:"<<endl;
    for(int i=0;i<n;i++){
        cin>>Roll[i];
    }
    cout<<"Enter the Roll No. to be searched:"<<endl;
    cin>>KEY;
}

int cSearch::Fibo(int a){
    int res;
    if(a==1){
        return 0;
    }
    else if(a==2){
        return 1;
    }
    res=Fibo(a-1) + Fibo(a-2);

    return res;
}

int cSearch::Sequen(){
    int i=-1;
    do{
        i++;
        if(Roll[i]==KEY){
            return 1;
        }
    }while(Roll[i]!=KEY && i<n);

    return 0;
}

int cSearch::Sentinel(){
    Roll[n]=KEY;
    int i=0,k;
    while(Roll[i]!=KEY){
        if(Roll[i]==KEY){
            k=i;
        }
        i++;
    }
    if(i<n){
        return 1;
    }
    else{
        return 0;
    }

}

int cSearch::BinarySearch(){
    int l=0, h=n-1;
    int MID;
    do{
        MID=(l+h)/2;
        if(KEY<Roll[MID]){
            h=MID-1;
        }
        else if(KEY>Roll[MID]){
            l=MID+1;
        }
        else if(KEY==Roll[MID]){
            return 1;
        }
    }while(KEY!=Roll[MID] && l<=h);

    return 0;
}

int cSearch::FiboSearch(){
    int k=0,MID,p,q;
    int i=1;
    while(n>=Fibo(i)){
        i++;
        k=i;
    }
    p=Fibo(k-2);
    q=Fibo(k-3);
    MID=n-p+1;
    do{
        if(KEY<Roll[MID]){
            if(q==0){
                return 0;
            }
            else{
                MID=MID-q;
                int temp;
                temp=p-q;
                p=q;
                q=temp;

            }
        }
        else if(KEY>Roll[MID]){
            if(p==1){
                return 0;
            }
            else{
                MID=MID+q;
                p=p-q;
                q=q-p;
            }
        }

    }while(KEY!=Roll[MID]);
    return 1;
}

int main(){
    cSearch s;
    char ch;
    int cho,res;
    do{

        cout<<"Enter the choice of search to be performed:"<<endl;
        cout<<"1. Sequential Search"<<endl;
        cout<<"2. Sentinel Search"<<endl;
        cout<<"3. Binary Search"<<endl;
        cout<<"4. Fibonacci Search"<<endl;
        cin>>cho;
        s.Accept();
        switch(cho){
            case 1:
                res=s.Sequen();
                if(res==1){
                    cout<<"Yes, the student attended the program! :)"<<endl;
                }
                else{
                    cout<<"No, the student didn't attend the program! :("<<endl;
                }
                break;
            case 2:
                res=s.Sentinel();
                if(res==1){
                    cout<<"Yes, the student attended the program! :)"<<endl;
                }
                else{
                    cout<<"No, the student didn't attend the program! :("<<endl;
                }
                break;
            case 3:
                res=s.BinarySearch();
                if(res==1){
                    cout<<"Yes, the student attended the program! :)"<<endl;
                }
                else{
                    cout<<"No, the student didn't attend the program! :("<<endl;
                }
                break;
            case 4:
                res=s.FiboSearch();
                if(res==1){
                    cout<<"Yes, the student attended the program! :)"<<endl;
                }
                else{
                    cout<<"No, the student didn't attend the program! :("<<endl;
                }
                break;

            default:
                cout<<"ERROR!"<<endl;
                break;

        }

        cout<<"Do you wish to continue? (y/n)"<<endl;
        cin>>ch;
    }while(ch=='y' || ch=='Y');


    return 0;
}

/* OUTPUT
 
 Enter the choice of search to be performed:
 1. Sequential Search
 2. Sentinel Search
 3. Binary Search
 4. Fibonacci Search
 1
 Enter the total no. of students:
 4
 Enter the Roll Numbers:
 1
 4
 6
 2
 Enter the Roll No. to be searched:
 6
 Yes, the student attended the program! :)
 Do you wish to continue? (y/n)
 y
 Enter the choice of search to be performed:
 1. Sequential Search
 2. Sentinel Search
 3. Binary Search
 4. Fibonacci Search
 2
 Enter the total no. of students:
 4
 Enter the Roll Numbers:
 1
 8
 6
 4
 Enter the Roll No. to be searched:
 8
 Yes, the student attended the program! :)
 Do you wish to continue? (y/n)
 y
 Enter the choice of search to be performed:
 1. Sequential Search
 2. Sentinel Search
 3. Binary Search
 4. Fibonacci Search
 3
 Enter the total no. of students:
 4
 Enter the Roll Numbers:
 1
 2
 4
 7
 Enter the Roll No. to be searched:
 2
 Yes, the student attended the program! :)
 Do you wish to continue? (y/n)
 y
 Enter the choice of search to be performed:
 1. Sequential Search
 2. Sentinel Search
 3. Binary Search
 4. Fibonacci Search
 4
 Enter the total no. of students:
 4
 Enter the Roll Numbers:
 1
 8
 5
 0
 Enter the Roll No. to be searched:
 3
 No, the student didn't attend the program! :(
 Do you wish to continue? (y/n)
 n
 Program ended with exit code: 0 */



