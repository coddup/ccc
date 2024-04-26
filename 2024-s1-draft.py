N=int(input())
hat_numbers = []
for i in range(N):
    hat_num = int(input())
    hat_numbers.append(hat_num)
result=0
for i in range(N//2):
    if hat_numbers[i] == hat_numbers[i+N//2]:
        result+=2
print(result)
