from functools import cmp_to_key

hand_order = [[1,1,1,1,1], [1,1,1,2], [1,2,2], [1,1,3], [2,3], [1,4], [5]]

def compare(hand1, hand2, card_order):
    c = hand_order.index(hand1[0])-hand_order.index(hand2[0])
    if c != 0: return c
    for c1, c2 in zip(hand1[1], hand2[1]):
        if c1 == c2: continue
        return card_order.index(c1) - card_order.index(c2)
    return 0

def jokerize(rank, hand, bid):
    jokers = rank.pop(rank.index(hand.count("J"))) if hand.count("J") else 0
    rank, greater = (rank[:-1], rank[-1]) if len(rank)>0 else ([], 0)
    return (rank + [greater + jokers], hand, bid)

def slv(hands, card_order):
    hands.sort(key=cmp_to_key(lambda a, b: compare(a, b, card_order)))
    return sum([(i+1)*(bid) for i,(_,_,bid) in enumerate(hands)])

hands = []
while True:
    try: 
        line = input().rstrip().split(" ")
        hands.append([sorted([line[0].count(c) for c in set(line[0])]), line[0], int(line[1])])
    except EOFError: break

print("Problem1: {}".format(slv(hands, '23456789TJQKA')))
print("Problem2: {}".format(slv([jokerize(*hand) for hand in hands], 'J23456789TQKA')))