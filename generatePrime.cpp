#include "generatePrime.h"

/**
 * @brief This function is used to return a list of all prime numbers in between the two specified bounds. It is inclusive of both bounds. It works by using a segmented sieve. It adds -1 as the last element of the array as a sentinel character to know when the end of the array has been reached.
 * 
 * @param[in] lowerBound As the name suggests, the lower bound.
 * @param[in] upperBound As the name suggests, the upper bound.
 * @param[out] primes The list of all primes in between the specified bounds, followed by -1.
 * @return The list containing all primes in between the bounds - type(integer array) 
 */
int* getPrimes(int lowerBound,int upperBound){
    if(upperBound<2){
        int* arr=new int[1];
        arr[0]=-1;
        return arr;
    }
    int* primeList=sieve(sqrt(upperBound));     //this contains a list of all primes less than sqrt(upperBound)
    //return primeList;
    if(lowerBound<2){
        lowerBound=2;
    }
    int len=upperBound-lowerBound+1;
    bool* prime=new bool[len];      
    for(int i=0;i<len;i++){
        prime[i]=true;
    }
    int index=0;
    while(primeList[index]!=-1){
        int p=primeList[index];
        int factor=lowerBound/p;
        int multiple=p*2;
        while(multiple<=upperBound){
            if(multiple>=lowerBound){
                prime[multiple-lowerBound]=false;
            }
            multiple=multiple+p;
        }
        index++;
    }
    int k=upperBound/log10(upperBound);
    int* primes=new int[k];
    int counter=0;
    for(int i=0;i<len;i++){
        if(prime[i]){
            primes[counter]=i+lowerBound;
            counter++;
        }
    }
    primes[counter]=-1;
    return primes;
    
}

/**
 * @brief This function implements the sieve of Eratosthenes. It is an optimized way to find all the primes less than a specified number.
 * 
 * @param[in] num The number less than which we need all primes.
 * @param[out] primes The list of all primes less than num , followed by -1.
 * @return The list containing all primes less than the specified number - type(integer array) 
 */
int* sieve(int num){
    if(num<2){
        int* arr=new int[1];
        arr[0]=-1;
        return arr;
    }
    else{
        int length=num-1;
        int sqr=sqrt(num);
        bool* prime=new bool[length];
        for(int i=0;i<length;i++){
            prime[i]=true;
        }
        for(int p=2;p<=sqr;p++){
            if(!prime[p-2]){
                continue;
            }
            else{
                int multiple=2*p;
                while(multiple<=num){
                    prime[multiple-2]=false;
                    multiple=multiple+p;
                }
            }
        } 
        int k=num/log10(num);
        int* primes=new int[k];
        int counter=0;
        for(int i=0;i<length;i++){
            if(prime[i]){
                primes[counter]=i+2;
                counter++;
            }
        }
        primes[counter]=-1;
        return primes;
    }
}

int getPrime(int lowerBound,int upperBound){
    int* primes=getPrimes(lowerBound,upperBound);
    int index=0;
    srand(time(0));
    while(primes[index]!=-1){
        index++;
    }
    int i=rand()%index;
    return primes[i];
}


int gcd(int a, int b){
    int temp;
    while(true){
        temp=a%b;
        if(temp==0){
            break;
        }
        else{
            a=b;
            b=temp;
        }
    }
    return b;
}