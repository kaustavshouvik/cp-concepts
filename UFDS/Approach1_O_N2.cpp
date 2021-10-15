#include <bits/stdc++.h>
using namespace std;

class UFDS {
  vector<int> par;
  int n;

  public:
  UFDS(int N) {
    n = N;
    par = vector<int>(n);

    for (int i=0; i<n; i++) {
      par[i] = i;
    }
  }

  // Finds if a and b are
  // in the same set
  bool find(int a, int b) {
    return par[a] == par[b];
  }

  // Unions two sets
  // (Set containing 'a') U (set containing 'b')
  void union_set(int a, int b) {
    // already in the same set
    if (find(a, b)) return;
  
    // To union two sets
    // Find the parent of set a
    int par_a = par[a];
    int par_b = par[b];

    // Replace all occurrence of par_a
    // with par_b

    for (int i=0; i<n; i++) {
      if (par[i] == par_a) {
        par[i] = par_b;
      }
    }
  }

  // Initially: 0 1 2 3 4 5
  
  // union(0, 1)
  // -> 1 1 2 3 4 5

  // union(1, 2)
  // -> 2 2 2 3 4 5

  // union(1, 4)
  // par_a = 2
  // par_b = 4
  // -> 4 4 4 3 4 5
};

int main() {
  int n = 10;

  UFDS ufds(n);

  int t;
  cin >> t;

  while (t--) {
    cout << "\n1. find(a, b)\n2. union_set(a, b)\n\n";
    int op;
    cin >> op;

    int a, b;
    if (op == 1) {
      cin >> a >> b;

      if (ufds.find(a, b)) {
        cout << "Same set!\n";
      } else {
        cout << "Different set!\n";
      }
    } else {
      cin >> a >> b;

      ufds.union_set(a, b);
    }
  }

  return 0;
}