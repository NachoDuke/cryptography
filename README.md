# cryptography

## Major Files (Basic Encryption & Decryption Algorithms):

### main.py
This file allows users to choose a secure and private key and send an encrypted message between 2 parties. It gives them the freedom to use either the RSA or the DIffie Hellman encryption-decryption systems. 

### DiffieHellman.py
This file contains a function DHKey() which implements the Diffie Hellman algorithm to establish a private key between 2 parties. 

### RSA.py
This file contains a function RSAkey() which implements the RSA encryption algorithm to establigh a private key between 2 parties.

### MillerRabin.py
This file contains a function isPrime(n) which is used to check whether n is a prime number or not. As the name of the file suggests, the algorithm used is the Miller Rabin primality test. The test is called for 10 iterations but this number can be modified.

### generatePrimes.py:
This file contains a functions that can be used to generate lists of prime numbers eiher less than a given number or in a given range. These functions will be uesd when creating and exchanging secret keys, as prime numbers are of immense importance during those steps.

The file also contains functions to calculate the greatest common divisor or 2 numbers and to carry out fast modular exponentiation.

It also contains a function used to check whether a given number is a generator of a given prime number.
