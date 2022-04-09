# from math import math

import math

def binPow(a, n):
    if(n == 0):
        return 1
    if(n == 1):
        return a
    result = binPow(a, math.floor(n/2))
    if (n % 2 == 1):
        return a * result * result
    else:
        return result * result

def binPowBitScan(a, n): 
    result = 1 # we will pick some exponents (corresponding to set bits) and keep multiplying to this
    weight = a # number corresponding to each position in digit representation, has to be squared each loop
    while(n > 0):
        if(n & 1): # include the exponentiation, if bin representation has 1
            result = result * weight # pick and mult with existing result
        weight = weight * weight # exponentiation weight for each position
        n >>= 1 # shift bitwise right and update
    return result

assert binPowBitScan(3, 1) == binPow(3, 1)
assert binPowBitScan(3, 2) == 9

print(binPow(3, 60))
print(binPowBitScan(3, 60))