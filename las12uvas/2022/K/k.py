from random import randint
for i in range(100):
   n = randint(2,700000)
   c = randint(2,n)
   print(n, c)
   print(" ".join([str(randint(1,100)) for i in range(n)]))