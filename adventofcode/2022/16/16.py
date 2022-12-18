# Self timed: * 01:08:43 | ** 01:52:01
from collections import defaultdict
def do_dp(rates, relevant_nodes, distances, bitmask, time_left): 
    dp = [defaultdict(lambda: defaultdict(int)) for _ in range(time_left+1)]
    dp[0][0]["AA"] = 0
    for t in range(time_left-1):
        for state in dp[t]:
            for start_node in dp[t][state]:
                for end_node in relevant_nodes:
                    if end_node == 'AA' or start_node == end_node: continue
                    new_state = state|((1<<relevant_nodes[end_node])&bitmask)
                    if new_state != state:
                        distance = distances[start_node][end_node]
                        if t+distance+1 in range(time_left+1):
                            value = dp[t][state][start_node]+(time_left-(t+distance+1))*rates[end_node]
                            dp[t+distance+1][new_state][end_node] = max(value, dp[t+distance+1][new_state][end_node])
    ans = max([dp[t][state][node] for t in range(time_left+1) for state in dp[t] for node in dp[t][state]])
    return ans

def slv1(rates, relevant_nodes, distances):
    all_nodes_bitmask = sum([1<<bit for bit in range(len(relevant_nodes)-1)])
    return do_dp(rates, relevant_nodes, distances, all_nodes_bitmask, 30)

def slv2(rates, relevant_nodes, distances):
    ans = 0
    for bitmask in range(2**(len(relevant_nodes)-2)):
        elephant = do_dp(rates, relevant_nodes, distances, bitmask, 26)
        me = do_dp(rates, relevant_nodes, distances, ~bitmask, 26)
        ans = max(elephant+me, ans)
    return ans

def bfs(start, end, graph):
    visited = set(start)
    q = [(start, 0)]
    while len(q)>0:
        node, distance = q.pop(0)
        if node == end: return distance
        for nb in graph[node]:
            if nb not in visited:
                visited.add(nb)
                q.append((nb, distance+1))

rates, tunnels, relevant_nodes = {}, {}, {'AA':-1}
while True:
    try: 
        line = input().rstrip().replace("Valve ", "").split("; ")
        node, rate = line[0].split(" has flow rate=")
        rates[node] = int(rate)
        tunnels[node] = line[1].replace("s", "").strip("tunnel lead to valve ").split(", ")
        if rate != '0': relevant_nodes[node] = len(relevant_nodes)-1
    except EOFError: break

distances = {start_node: {end_node: bfs(start_node, end_node, tunnels) for end_node in relevant_nodes} for start_node in relevant_nodes}
print("Problem1: {}".format(slv1(rates, relevant_nodes, distances)))
print("Problem2: {}".format(slv2(rates, relevant_nodes, distances)))