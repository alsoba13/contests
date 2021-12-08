class Submarine:
    def __init__(self):
        self.d = self.h = 0
    def do_action(self, direction, number):
        if direction[0] == 'u': self.up(number)
        elif direction[0] == 'd': self.down(number)
        else: self.forward(number)
    def get_result(self):
        return self.d * self.h
class WrongSubmarine(Submarine):
    def up(self, number):
        self.d -= number
    def down(self, number):
        self.d += number
    def forward(self, number):
        self.h += number
class CorrectSubmarine(Submarine):
    def __init__(self):
        super().__init__()
        self.aim = 0
    def up(self, number):
        self.aim -= number
    def down(self, number):
        self.aim += number
    def forward(self, number):
        self.h += number
        self.d += self.aim * number

def slv(actions, submarine):
    for direction, number in actions:
        submarine.do_action(direction, number)
    return submarine.get_result()

actions = []
while True:
    try:
        direction, number = input().split(' ')
        actions.append((direction, int(number)))
    except EOFError: break
print("Problem1: {}".format(slv(actions, WrongSubmarine())))
print("Problem2: {}".format(slv(actions, CorrectSubmarine())))