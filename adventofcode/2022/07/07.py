def slv(graph, init_function, f):
    sol_so_far = init_function(graph[1])
    for subdirectory in graph[0]:
        sol_so_far = f([sol_so_far, slv(graph[0][subdirectory], init_function, f)])
    return sol_so_far

def read_graph(lines, i, graph):
    while i < len(lines):
        line, i = lines[i].split(' '), i+1
        if line[1] == 'ls':
            while i < len(lines) and lines[i][0] != '$':
                line, i = lines[i].split(' '), i+1
                if line[0] == 'dir':
                    if line[0] not in graph[0]: graph[0][line[1]] = [{}, 0]
                else:
                    graph[1] += int(line[0])
        else: 
            if line[2] == '..': return i, graph[1]
            else: 
                i, subdirectories_size = read_graph(lines, i, graph[0][line[2]])
                graph[1] += subdirectories_size
    return i, graph[1]

lines = []
while True:
    try: lines.append(input().rstrip())
    except EOFError: break
graph = [{'/': [{}, 0]}, 0]
read_graph(lines, 0, graph)

print("Problem1: {}".format(slv(graph, lambda x: x if x <= 100000 else 0, sum)))
print("Problem2: {}".format(slv(graph, lambda x: x if x >= graph[1]-40000000 else graph[1], min)))