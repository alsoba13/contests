n = int(input())
sol1 = sol2 = 0
for i in range(0, n):
    inputs = input().rstrip().split(' ')
    n1, n2, letter, password = [int(inputs[0].split('-')[0]), int(inputs[0].split('-')[1]), inputs[1][0], inputs[2]]
    sol1 += n1 <= password.count(letter) <= n2
    sol2 += (password[n1-1] == letter and password[n2-1] != letter) or (password[n1-1] != letter and password[n2-1] == letter)
print("Problem1: {}\nProblem2: {}".format(sol1, sol2))