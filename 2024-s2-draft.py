def check_adjacency_requirements(mydata):
    if len(mydata) < 2:
        return True
    for i in range(len(mydata) - 1):
        if mydata.count(mydata[i]) != 1 and mydata.count(mydata[i+1]) != 1:
            return 'F'
        if mydata.count(mydata[i]) == 1 and mydata.count(mydata[i+1]) == 1:
            return 'F'
    return 'T'


line1=input()
T=line1.split()[0]
N=line1.split()[1]

for i in range(int(T)):
    data=input()
    print(check_adjacency_requirements(data))
