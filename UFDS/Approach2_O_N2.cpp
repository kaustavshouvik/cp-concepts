#include <bits/stdc++.h>
using namespace std;

// Concept of root:
// A special element having parent as itself
// --> par[a] = a

// Every set will have a root element

// Union(a, b)
// This will connect a -> b
// par[a] = b

class UFDS {
  vector<int> par;
  int n;
  
  // Find the root of
  // the current set
  int root(int a) {
    while (par[a] != a) {
      a = par[a];
    }

    return a;
  }

  public:
  UFDS(int N) {
    n = N;
    par = vector<int>(n);

    for (int i=0; i<n; i++) {
      par[i] = i;
    }
  }

  bool find(int a, int b) {
    return root(a) == root(b);
  }

  void union_set(int a, int b) {
    int root_a = root(a);
    int root_b = root(b);

    // The other way around
    // doesn't make any difference

    par[root_a] = root_b;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("error.txt", "w", stderr);
  freopen("output.txt", "w", stdout);
  #endif

  int n = 10;

  UFDS ufds(n);

  int t;
  cin >> t;

  while (t--) {
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