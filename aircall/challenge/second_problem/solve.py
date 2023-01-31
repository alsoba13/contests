def gcd(a, b):
    if b == 0: return a
    return gcd(b, a%b)

def evaluate(is_P, numbers):
    if is_P:
        b, a = [int(i) for i in numbers[0].split("/")]
        for num in numbers[1:]:
            d, c = [int(i) for i in num.split("/")]
            a, b = a*d+b*c, b*d
            a, b = a/gcd(a, b), b/gcd(a, b)
        return "{}/{}".format(int(b), int(a))
    else: 
        a, b = [int(i) for i in numbers[0].split("/")]
        for num in numbers[1:]:
            c, d = [int(i) for i in num.split("/")]
            a, b = a*d+b*c, b*d
            a, b = int(a/gcd(a, b)), int(b/gcd(a, b))
        return "{}/{}".format(int(a), int(b))

def read_number(exp, i):
    number = 0
    while exp[i].isdigit():
        number = number*10 + int(exp[i])
        i+=1
    return "{}/1".format(number), i-1

def read_token(exp, i):
    assert(exp[i]=='(')
    i+=1
    assert(exp[i] in 'PS')
    if exp[i] == 'P':
        is_P = True
    else:
        is_P = False
    i+=2
    values = []
    while i < len(exp) and exp[i] != ')':
        if exp[i] == ' ': i+=1
        if exp[i] == '(':
            number, i = read_token(exp, i)
        else:
            number, i = read_number(exp, i)
        values.append(number)
        i+=1
    return evaluate(is_P, values), i

n = int(input())
for case in range(n):
    exp = input().rstrip(" ")
    #print(exp)
    sol = read_token(exp, 0)[0]
    if sol[-2:] == '/1':
        sol = sol[:-2]
    print(sol)