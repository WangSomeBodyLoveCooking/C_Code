#coding=UTF-8
#九九乘法表
#for循环方式



for i in range(1, 10):
    for j in range(1, i+1):
        print(f'{j}*{i} = {i*j}', end = '    ')
    print('')
print('--'*20)

#C语言
# int i = 1;
# int j = 1;
# for(;i <= 9;i++)
# {
#     for(;j <= i;j++)
#     {
#         printf("%d*%d=%d\t", j, i, i*j);
#     }
#     printf("\n");
# }



num1 = 1
num2 = 1
while num1 <= 9:
    while num2 <= num1:
        print(f'{num2}*{num1}={num1*num2}', end = '    ')
        num2 += 1
    print('-'*20)
    num2 = 1
    num1 += 1
