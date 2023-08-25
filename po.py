n = 759
liar = []
witness = 0
for a in range(2,n-1):
    if(pow(a,n-1,n)==1):
        liar.append(a)
for a in range(2,n-1):
    if(pow(a,n-1,n)!=1):
        witness = a
    break 
print("First fermat liar for n = 501 :",liar[0])
print("First fermat witness for n = 501 :",witness)
print("No. of fermat liars for n = 501 :",len(liar))