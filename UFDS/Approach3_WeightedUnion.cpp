#include <bits/stdc++.h>
using namespace std;

// While performing union
// connect the set with size less
// to the set with greater size

class UFDS {
  vector<int> par, size;
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
    size = vector<int>(n);

    for (int i=0; i<n; i++) {
      par[i] = i;
      size[i] = 1;
    }
  }

  bool find(int a, int b) {
    return root(a) == root(b);
  }

  // weighted union
  void union_set(int a, int b) {
    int root_a = root(a);
    int root_b = root(b);

    if (size[root_a] < size[root_b]) {
      par[root_a] = par[root_b];
      //    b
      //   /
      //  a
      
      // Now, size of b has increased
      size[root_b] += size[root_a];
    } else {
      par[root_b] = par[root_a];
      size[root_a] += size[root_b];
    }
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