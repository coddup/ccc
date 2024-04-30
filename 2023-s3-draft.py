import sys

list_len=int(input())
list_a=input().split(' ')
list_b=input().split(' ')

i=0
last_a_pos=0
path_l=[]
path_r=[]
while i<list_len:
    b_value=list_b[i]
    b_start=i
    b_end=i
    j=i
    while j+1<list_len and b_value==list_b[j+1]:
        b_end=j+1
        j=j+1
    k=last_a_pos
    while k<list_len and b_value!=list_a[k]:
        k=k+1
    a_pos=k
    if a_pos==list_len:
        print('NO')
        sys.exit()
    last_a_pos=a_pos
    if a_pos>=b_end and a_pos !=b_start:
        path_l.append('L ' +str(b_start)+' '+str(a_pos))
    if a_pos<=b_start and a_pos !=b_end:
        path_r.append('R ' +str(a_pos)+' '+str(b_end))
    if b_start < a_pos < b_end:
        path_l.append('L ' +str(b_start)+' '+str(a_pos))
        path_r.append('R ' +str(a_pos)+' '+str(b_end))
    i=b_end+1

print('YES')
print(len(path_l)+len(path_r))
path_r.reverse()
for l in path_l:
    print(l)
for r in path_r:
    print(r)
