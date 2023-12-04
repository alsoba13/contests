def slv1(matches_per_card):
    return sum([2**(matches-1) for matches in matches_per_card if matches > 0])

def slv2(matches_per_card):
    cnt = [1] * len(matches_per_card)
    for card, matches in enumerate(matches_per_card):
        for offset in range(1, matches+1):
            cnt[card+offset] += cnt[card]
    return sum(cnt)

matches_per_card = []
while True:
    try:
        winning_numbers, your_numbers = [set(int(num) for num in x.split(" ") if num != "") for x in input().split(": ")[1].split(" | ")]
        matches_per_card.append(sum([1 for your_number in your_numbers if your_number in winning_numbers]))
    except EOFError: break

print("Problem1: {}".format(slv1(matches_per_card)))
print("Problem2: {}".format(slv2(matches_per_card)))