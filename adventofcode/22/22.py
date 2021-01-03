from collections import deque
def playGame1(deck1, deck2):
    while len(deck1) and len(deck2):
        if deck1[0] > deck2[0]:
            deck1.append(deck1[0])
            deck1.append(deck2[0])
        else:
            deck2.append(deck2[0])
            deck2.append(deck1[0])
        deck1.popleft()
        deck2.popleft()
    return deck1, deck2, [2, 1][len(deck1) > 0]

def playGame2(deck1, deck2):
    decks1, decks2 = [], []
    while len(deck1) and len(deck2):
        if deck1 in decks1 or deck2 in decks2:
            return deck1, deck2, 1
        decks1.append(deque(deck1))
        decks2.append(deque(deck2))
        c1, c2 = deck1.popleft(), deck2.popleft()
        if c1 <= len(deck1) and c2 <= len(deck2):
            _, _, winner = playGame2(deque(list(deck1)[:c1]), deque(list(deck2)[:c2]))
            if winner == 1:
                deck1.append(c1)
                deck1.append(c2)
            else:
                deck2.append(c2)
                deck2.append(c1)
        else:
            if c1 > c2:
                deck1.append(c1)
                deck1.append(c2)
            else:
                deck2.append(c2)
                deck2.append(c1)
    return deck1, deck2, [2, 1][len(deck1) > 0]
    
def sum_mult(deck1, deck2, winner):
    return sum([(i+1)*deck1[len(deck1)-1-i] for i in range(len(deck1))]) + sum([(i+1)*deck2[len(deck2)-1-i] for i in range(len(deck2))])

n = int(input().rstrip())
_, deck1 = input(), [int(input()) for i in range(n)]
_, _, deck2 = input(), input(), [int(input()) for i in range(n)]
print("Problem1: {}\nProblem2: {}".format(sum_mult(*playGame1(deque(deck1), deque(deck2))), sum_mult(*playGame2(deque(deck1), deque(deck2)))))