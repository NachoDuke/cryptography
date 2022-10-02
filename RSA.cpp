#include "RSA.h"


int RSAkey(){
    //First person chooses 2 primes
    int primeLowerLimit=10;
    int primeUpperLimit=100;

    int p1=getPrime(primeLowerLimit,primeUpperLimit);
    int p2=getPrime(primeLowerLimit,primeUpperLimit);


    long long int n=p1*p2;
    long long int phi=(p1-1)*(p2-1) ;      //totient

    int a=2;
    while(true){
        if(gcd(phi,a)==1){
            break;
        }
        else{
            a++;
        }
    }

    //we have chosen an a such that gcd(a,phi)=1

    //The second person now chooses the secret key x
    int x=35;

    cout<<"The public channel contains n "<<n<<"a "<<a<<endl;
    cout<<p1<<" "<<p2<<" "<<phi<<endl;
    long long int exp=pow(x,a);
    long long int encryptedKey=fmod(exp,n);

    //The second person sends encryptedKey

    cout<<"encryptedKey is added to the public channel "<<encryptedKey<<endl;

    //getting the secret key x from the information the first person has

    int k=2;        //a constant
    double decrypt=(1+phi*k)/a;
    long long int key=pow(encryptedKey,decrypt);
    key=fmod(key,n);
    cout<<key;
}