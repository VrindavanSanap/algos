# symbols Σ = {a, b}
# language L = {words where a's come before b's}
# based on a video by numberphile

class DFA():
    # 5 tuple 
    # https://en.wikipedia.org/wiki/Deterministic_finite_automaton
    def __init__(self, Q, Sigma, delta, q0, F):
        # finite set of states
        self.Q = Q
        # finite set of symbols Σ 
        self.Sigma = Sigma
        # transition function 
        self.delta = delta
        # start state
        self.q0 = q0
        # set of final states
        self.F = F


    def run (self, w):
        q = self.q0
        while w!= "":
            q = self.delta[(q, w[0])]
            w = w[1:]
        return q in self.F

    def __repr__(self):
        return (f"DFA {self.Q}, \n\t {self.Sigma}, \n\t {self.delta}")

D0 = DFA({0, 1, 2}, {'a', 'b'}, {(0, 'a'):0, (0, 'b'):1, (1, 'a'): 2, (1, 'b'):1, (2, 'a'):2, (2, 'b'):2}, 0, {0,1})

print("aa", D0.run("aa"))
print("aabbb", D0.run("aabbb"))
print("ba", D0.run("ba"))
print("aba", D0.run("aba"))
print("", D0.run(""))


print(D0)
