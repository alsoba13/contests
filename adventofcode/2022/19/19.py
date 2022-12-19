from collections import defaultdict
from functools import reduce

def robots_produce(elements, robots):
    return [element+elements_generated for element, elements_generated in zip(elements, robots)]

def create_robot(robots, robot_to_create):
    robots[robot_to_create]+=1
    return robots

def new_state(elements, robots):
    return tuple((element,robot) for element,robot in zip(elements, robots))

def slv(blueprints, time):
    sol = []
    for blueprint in blueprints:
        states = set()
        states.add(new_state([0,0,0,0], [0,0,0,1]))
        for _ in range(time):
            new_states = set()
            for state in sorted(states, reverse=True)[:1000]:
                elements, robots = [list(i) for i in zip(*state)]
                # A state for not creating any robot:
                elements_increased = robots_produce(elements, robots)
                new_states.add(new_state(elements_increased, robots))
                # A state for creating a robot of every possible type
                for robot_to_create in blueprint:
                    elements_left = elements.copy()
                    for quantity_needed, element_needed in blueprint[robot_to_create]:
                        elements_left[element_needed]-=quantity_needed
                    if all([element_left>=0 for element_left in elements_left]):
                        elements_increased = robots_produce(elements_left, robots)
                        robots_increased = create_robot(robots.copy(), robot_to_create)
                        new_states.add(new_state(elements_increased, robots_increased))
            states = new_states
        sol.append(max([state[0][0] for state in states]))
    return sol
            
blueprints = []
name_to_id = {name: i for i, name in enumerate(["geode","obsidian","clay","ore"])}
while True:
    try:
        blueprint = defaultdict(list)
        for instruction in input().rstrip().rstrip('.').split(": ")[1].split(". "):
            element, howto = instruction.split("Each ")[1].split(" robot costs ")
            for part in howto.split(" and "):
                q, e = part.split(" ")
                blueprint[name_to_id[element]].append((int(q), name_to_id[e]))
        blueprints.append(blueprint)
    except EOFError: break
print("Problem1: {}".format(sum([(i+1)*ans for i, ans in enumerate(slv(blueprints, 24))])))
print("Problem2: {}".format(reduce(lambda x,y: x*y, slv(blueprints[:3], 32))))