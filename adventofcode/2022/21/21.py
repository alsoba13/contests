inv = {'*': '/', '/': '*', '+': '-', '-': '+'}

def eval_if_known(tree, node, unknown = ''):
    if node == unknown: return False
    if type(tree[node]) == list:
        son1 = eval_if_known(tree, tree[node][0], unknown)
        son2 = eval_if_known(tree, tree[node][2], unknown)
        if son2 == False and tree[node][1] in '/': print(node)
        if son1 == False or son2 == False: return False
        tree[node] = int(eval("{}{}{}".format(son1, tree[node][1], son2)))
    return tree[node]

def eval_tree_equal_to(tree, node, equal_to):
    if type(tree[node]) != list: return equal_to
    son1 = eval_if_known(tree, tree[node][0], 'humn')
    son2 = eval_if_known(tree, tree[node][2], 'humn')
    op = tree[node][1]
    if son2 == False:
        tree[node] = tree[node][::-1]
        if op in '+*': son2, son1 = son1, son2
        else: equal_to, son1, op, son2 = son1, son2, inv[op], equal_to
    return eval_tree_equal_to(tree, tree[node][0], int(eval("{}{}{}".format(equal_to, inv[op], son2))))

def slv2(tree):
    tree['root'][1] = '-'
    return eval_tree_equal_to(tree, 'root', 0)

def slv1(tree):
    return eval_if_known(tree, 'root')

lines = []
while True:
    try: lines.append(input().rstrip())
    except EOFError: break

tree = {id: int(op) if op.isdigit() else [nb for nb in op.split(' ')] for id, op in map(lambda x: x.split(': '), lines)}
print("Problem1: {}".format(slv1(tree.copy())))
print("Problem1: {}".format(slv2(tree.copy())))