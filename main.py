from src.DiffieHellman import *
from src.RSA import *

def encrypt():
    #This function provides a menu to choose which encryption to use
    choice=int(input("Enter 0 to use Diffie Hellman and 1 to use RSA encryption"))
    if(choice==0):
        #calls function to use Diffie-Hellman encryption
        DHKey()
    elif(choice==1):
        #Calls function to use RSA encryption
        RSAkey()
    else:
        #Handles invalid inputs
        print("Input a valid choice")
        encrypt()

if __name__ =="__main__":
    encrypt()