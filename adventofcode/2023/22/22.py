from collections import defaultdict
import sys

def intersect(p1,p2):
    return p1[0] in range(p2[0], p2[1]+1) or p1[1] in range(p2[0], p2[1]+1) or p2[0] in range(p1[0], p1[1]+1) or p2[1] in range(p1[0], p1[1]+1)

def parse_graph(pieces):
    graph = {i:[[],[]] for i in range(len(pieces))}
    pieces_by_z = defaultdict(list)
    pieces_by_z[0].append(0)
    for i in range(1,len(pieces)):
        while True:
            parents = [piece_id for piece_id in pieces_by_z[min(pieces[i][0])-1] if all((intersect(pieces[piece_id][0],(pieces[i][0][0]-1,pieces[i][0][1]-1)), intersect(pieces[piece_id][1],pieces[i][1]), intersect(pieces[piece_id][2],pieces[i][2])))]
            if parents:
                pieces_by_z[max(pieces[i][0])].append(i)
                graph[i][0] = parents
                for parent in parents: graph[parent][1].append(i)
                break
            pieces[i] = ((pieces[i][0][0]-1, pieces[i][0][1]-1),pieces[i][1],pieces[i][2])
    return graph

def count_desintegrating(removed_pieces, piece, graph):
    removed_pieces.add(piece)
    for son in graph[piece][1]:
        if all(parent in removed_pieces for parent in graph[son][0]):
            removed_pieces = count_desintegrating(removed_pieces, son, graph)
    return removed_pieces

graph = parse_graph(sorted([((0,0),(0,9),(0,9))] + [tuple((min(int(x),int(y)), max(int(x),int(y))) for x, y in zip(*[reversed(end.split(',')) for end in line.split('~')])) for line in sys.stdin.read().split('\n')]))
cnt = [len(count_desintegrating(set(), piece, graph))-1 for piece in graph]

print("Problem1: {}".format(sum(c == 0 for c in cnt)))
print("Problem2: {}".format(sum(cnt)))
