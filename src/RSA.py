from src.MillerRabin import *
from src.generatePrime import *

def RSAkey():
    print("Choosing 2 random 5 digit primes")
    p=getPrime(100,1000)
    q=getPrime(100,1000)

    n=p*q

    ln=(p-1)*(q-1)
    ln=int(ln/gcd(p-1,q-1))

    while(True):
        e=random.randint(2,ln-1)
        if(gcd(e,ln)==1):
            break
    for i in range(1,ln):
        if((e*i)%ln==1):
            d=i

    print("The first party publicly shares n: ",n)
    print("The first party publicly shares e: ",e)

    while(True):
        m=int(input("The second party chooses a message m. Enter an integer less than n to act as the message"))
        if(m<n and m>0):
            break

    c=modPower(m,e,n)

    print("The second party publicly shares the encrypted message: ",c)

    #decryption by first party
    originalMessage=modPower(c,d,n)

    if(m==originalMessage):
        print("Success!!")
    else:
        print("Something went wrong!")



    

