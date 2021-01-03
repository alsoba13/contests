from collections import defaultdict
sol1 = 0
m = {}
lines = [input().rstrip() for _ in range(int(input()))]
for line in lines:
    ingredients = line.split('(')[0][:-1].split(' ')
    allergens = line.split('(')[1][9:-1].split(', ')
    for allergen in allergens:
        if allergen not in m:
            m[allergen] = set(ingredients)
        else:
            m[allergen] = m[allergen].intersection(set(ingredients))
for line in lines:
    ingredients = line.split('(')[0][:-1].split(' ')
    for ingredient in ingredients:
        if ingredient not in {b for a in m.values() for b in a}:
            sol1+=1
seen_ingredients = set()
sol2 = {}
while len(seen_ingredients) < len(m):
    for allergen in m:
        c = 0
        for ingredient in m[allergen]:
            if ingredient not in seen_ingredients:
                c += 1
                ingredient_ = ingredient
        if c == 1:
            seen_ingredients.add(ingredient_)
            sol2[allergen] = ingredient_
print(sorted(sol2))
print("Problem1: {}\nProblem2: {}".format(sol1, ','.join([sol2[a] for a in sorted(sol2)])))