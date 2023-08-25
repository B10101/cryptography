def checkP(n):
    for num in range(2,n//2+1):
        if n%num == 0:
            return False
    return True


n = 6775
while True:
    if pow(2,n-1,n) == 1 and not checkP(n):
        print(n)
        break
    else:
        n+=1
