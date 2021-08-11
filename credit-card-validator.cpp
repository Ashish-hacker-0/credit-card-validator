#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

bool checkNumberString(string s){
    int length = s.length();
    for(int i=0;i<length;i++){
        if(s[i] < '0' || s[i] > '9'){
            return false;
        }
    }
    return true;
}

int main()
{
    string ccn;

    cout<<"To quit please enter 'exit' anytime."<<endl;

    while(true){

        cout<<"Please enter a credit card Number"<<endl;
        cin>>ccn;
        if(ccn=="exit"){
            break;
        }
        else if(!checkNumberString(ccn)){
            cout<<"Invalid Input"<<endl;
            continue;
        }

        int length = ccn.length();
        int doubleEvenSum = 0;
        for(int i=length-2;i>=0;i=i-2){
            int d = ((ccn[i]-48)*2);
            if(d>9){
                d=(d/10)+(d%10);
            }
            doubleEvenSum+=d;
        }

        for(int i= length-1;i>=0;i=i-2){
            doubleEvenSum += (ccn[i]-48);
        }

        cout<<(doubleEvenSum % 10 == 0 ? "Valid" : "Invalid")<<endl;

        continue;
    }
    return 0;
} // namespace std;

