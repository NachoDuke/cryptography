from src.MillerRabin import *
from src.generatePrime import *

def RSAkey():
    #first party choosing 2 primes
    print("Choosing 2 random 4 digit primes")
    p=getPrime(1000,10000)
    q=getPrime(1000,10000)

    n=p*q

    #calculating carmichael's totient function
    ln=(p-1)*(q-1)
    ln=int(ln/gcd(p-1,q-1))

    while(True):
        e=random.randint(2,ln-1)
        if(gcd(e,ln)==1):
            break
    for i in range(1,ln):
        if((e*i)%ln==1):
            d=i

    #Printing the information shared on the public channel
    print("The first party publicly shares n: ",n)
    print("The first party publicly shares e: ",e)

    while(True):
        m=int(input("The second party chooses a message m. Enter an integer less than n to act as the message"))
        if(m<n and m>0):
            break

    #encrypting the message given by the second party
    c=modPower(m,e,n)

    print("The second party publicly shares the encrypted message: ",c)

    #decryption by first party
    originalMessage=modPower(c,d,n)

    if(m==originalMessage):
        #Success
        print("Success!!")
    else:
        #Failure
        print("Something went wrong!")



    

