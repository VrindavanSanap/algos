#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
using namespace std;
class DFA {
 private:
  unordered_set<int> Q;
  unordered_set<char> Sigma;
  map<pair<int, char>, int> delta;
  int q0;
  unordered_set<int> F;

 public:
  DFA(unordered_set<int> Q, unordered_set<char> Sigma,
      map<pair<int, char>, int> delta, int q0, unordered_set<int> F) {
    this->Q = Q;
    this->Sigma = Sigma;
    this->delta = delta;
    this->q0 = q0;
    this->F = F;
  }
  bool run(string w) {
    int q = this->q0;
    for (char c : w) {
      q = this->delta[{q, c}];
    }

    return F.contains(q);
  };
};

int main() {
  unordered_set<int> Q = {0, 1, 2};
  unordered_set<char> Sigma = {'a', 'b'};
  map<pair<int, char>, int> delta = {{{0, 'a'}, 0}, {{0, 'b'}, 1},
                                     {{1, 'a'}, 2}, {{1, 'b'}, 1},
                                     {{2, 'a'}, 2}, {{2, 'b'}, 2}};
  unordered_set<int> F = {0, 1};
  DFA D0(Q, Sigma, delta, 0, F);
  cout << format("aabbb {}\n", D0.run("aabbb"));
  cout << format("ba {}\n", D0.run("ba"));
  cout << format("aba {}\n", D0.run("aba"));
  cout << format(" {}\n", D0.run(""));
  return 0;
}