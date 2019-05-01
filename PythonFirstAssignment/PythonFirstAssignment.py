from MyModule import isNumberPrime
from MyModule import Player

input = 5

try: 
    if (isNumberPrime(input) == False) : print("Skaičius nėra pirminis")
    else : print("Skaičius yra pirminis")
except Exception as ex:
    print(str(ex))