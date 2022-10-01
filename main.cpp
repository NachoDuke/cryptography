#include <iostream>
#include "generatePrime.cpp"
using namespace std;

int main(int argc, char**argv){
    cout<<"Enter the lower and upper limits"<<endl;
    int low,high;
    cin>>low>>high;
    if(low>high){
        cout<<"The lower bound is more than the upper Bound, exiting."<<endl;
    }
    else{
        int* primes=getPrimes(low,high);
        int index=0;
        while(primes[index]!=-1){
            cout<<primes[index]<<endl;
            index++;
        }
    }
}