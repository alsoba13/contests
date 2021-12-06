def f(num_cups, iterations, multiply=False):
    circle=[int(c) for c in "562893147"]
    while(len(circle)<num_cups):
        circle.append(len(circle)+1)
    m = [0] * (len(circle)+1)
    for i in range(1, len(circle)):
        m[circle[i-1]] = circle[i]
    m[circle[-1]] = circle[0]
    i_current = circle[0]
    for _ in range(iterations):
        aux = m[i_current]
        m[i_current] = m[m[m[m[i_current]]]]
        extracted = {aux, m[aux], m[m[aux]]}
        previous_i = (i_current-2)%num_cups+1
        while previous_i in extracted:
            previous_i = (previous_i-2)%num_cups+1
        m[m[m[aux]]] = m[previous_i]
        m[previous_i] = aux
        i_current = m[i_current]
    return m
circle_s1, circle_s2 = f(9,100), f(1000000, 10000000)
sol1, i = [], 1
while circle_s1[i] != 1:
    sol1.append(circle_s1[i])
    i = circle_s1[i]
print("Problem1: {}\nProblem2: {}".format(''.join([str(n) for n in sol1]), circle_s2[1]*circle_s2[circle_s2[1]]))
