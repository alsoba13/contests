import random
import math
import numpy as np

# Those are just some simulations I ran to figure out things

def myRandom():
    return random.uniform(-3, 3)


def sigma(x):
    return 1/(1+math.exp(-x))


def simulateQ(Q):
    c = 0
    for i in range(100):
        p = sigma(myRandom()-Q)
        if random.random()<p:
            c+=1
    return c

for kk in range(0,50):
    P = [myRandom() for i in range(100)]
    Q = [myRandom() for i in range(10000)]
    for j in range(10000):
        if random.random()<0.50: print('1', end='')
        else:
            p = sigma(P[0]-Q[j])
            if random.random()<p: print('1', end='')
            else: print('0', end='')
    print('')
    for i in range(1,100):
        for j in range(10000):
            p = sigma(P[i]-Q[j])
            if random.random()<p: print('1', end='')
            else: print('0', end='')
        print()
"""def simulateP(P):
    c = 0
    for i in range(10000):
        p = sigma(P-myRandom())
        if random.random()<p:
            c+=1
    return c

grid = np.linspace(-3,3,61)

sols = []
for point in grid:
    sample = []
    for i in range(0,100):
        sample.append(simulateP(point))
    sols.append(np.mean(sample))

for x,y in zip(grid, sols):
    print("(",x,",",y,")")


def simulateP2(P):
    c = 5000
    for i in range(5000):
        p = sigma(P-myRandom())
        if random.random()<p:
            c+=1
    return c
"""
