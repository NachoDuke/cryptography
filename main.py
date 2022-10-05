from src.DiffieHellman import *
from src.RSA import *

def encrypt():
    choice=int(input("Enter 0 to use Diffie Hellman and 1 to use RSA encryption"))
    if(choice==0):
        DHKey()
    elif(choice==1):
        RSAkey()
    else:
        print("Input a valid choice")
        encrypt()

if __name__ =="__main__":
    encrypt()