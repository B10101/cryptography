import math
 
# Function to find the Floor
# of square root of a number
def sqrtF(x):
    # if x is less than 0
    if x < 0:
        raise ValueError("Negative argument.")
     
    # if x==0 or x==1
    if x == 0 or x == 1:
        return x
     
    y = x // 2
     
    # run a loop
    while y > x // y:
        y = (x // y + y) // 2
     
    return y
 
# function to find the Ceil
# of square root of a number
def sqrtC(x):
    y = sqrtF(x)
 
    if x == y * y:
        return y
    else:
        return y + 1
 
# Fermat factorisation
def FermatFactors(n):
    # if n%2 ==0 then return the factors
    if n % 2 == 0:
        return str(n // 2) + ", 2"
     
    # find the square root
    a = sqrtC(n)
     
    # if the number is a perfect square
    if a * a == n:
        return str(a) + ", " + str(a)
     
    # else perform factorisation
    while True:
        b1 = a * a - n
        b = sqrtF(b1)
         
        if b * b == b1:
            break
        else:
            a += 1
     
    return str(a - b) + ", " + str(a + b)
 
# Driver code
if __name__ == "__main__":
    N = "2419111"
 
    print(FermatFactors(int(N)))