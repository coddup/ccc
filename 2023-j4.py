length = int(input())
line1 = input()
line2 = input()
list1 = [int(x) for x in line1.split(' ')]
list2 = [int(x) for x in line2.split(' ')]

i = 1
result = 0
if list1[0] + list2[0] == 1:
    result = 3
if list1[0] + list2[0] == 2:
    result = 4
even_odd_return = lambda num: 2 if num % 2 else 0

while i < length:

    if list1[i] + list1[i - 1] + list2[i] + list2[i - 1] == 4:
        result = result + even_odd_return(i)

    if list1[i] + list1[i - 1] + list2[i] + list2[i - 1] == 3:
        if list1[i] + list2[i] == 2:
            result = result + 2 + even_odd_return(i)
        if list1[i] + list2[i] == 1:
            result = result + 1

    if list1[i] + list1[i - 1] + list2[i] + list2[i - 1] == 2:
        if list1[i] + list2[i] == 2:
            result = result + 4 + even_odd_return(i)
        if abs(list1[i] + list1[i - 1] - list2[i] - list2[i - 1]) == 2:
            result = result + 1
        if abs(list1[i] + list2[i - 1] - list2[i] - list1[i - 1]) == 2:
            result = result + 3

    if list1[i] + list2[i] == 1 and list1[i - 1] + list2[i - 1] == 0:
        result = result + 3

    i = i + 1
print(result)
