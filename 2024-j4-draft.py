line1=input()
line2=input()
l1=len(line1)
l2=len(line2)
i=0
j=0
goodkeys=set()
silly=''
wrong=''
quiet='-'
while i< l1 and j<l2:
    if line1[i]==wrong:
        quiet=silly
        silly=''
        wrong=''
        i+=1
        continue
    if line1[i]==quiet:
        i+=1
        continue
    if line1[i]==line2[j]:
        goodkeys.add(line1[i])
        i+=1
        j+=1
    elif line2[j] not in goodkeys:
        silly=line1[i]
        wrong=line2[j]
        i += 1
        j += 1
    else:
        quiet=line1[i]
        i += 1
if i<l1 and i==j:
    quiet=line1[i]


print(silly,wrong)
print(quiet)
