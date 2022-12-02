def slv(games, play):
    score = 0
    for i, j in games:
        score += play(i, j)
    return score

games = []
while True:
    try:
        games.append(input().rstrip().split(' '))
    except EOFError: break

PLAY = [
    [ 3, 6, 0 ],
    [ 0, 3, 6 ],
    [ 6, 0, 3 ],
]

print("Problem1: {}".format(slv(games, lambda i, j: PLAY[ord(i)-ord('A')][ord(j)-ord('X')] + ord(j)-ord('X') + 1)))
print("Problem2: {}".format(slv(games, lambda i, j: (ord(j)-ord('X')) * 3 + PLAY[ord(i)-ord('A')].index((ord(j)-ord('X')) * 3) + 1)))