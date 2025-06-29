#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  // io optimisation
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n, q;
  std::cin >> n >> q;

  std::vector<int> c(n), t(n), d(n);

  for (int i = 0; i < n; ++i) {
    std::cin >> c[i];
  }
  for (int i = 0; i < n; ++i) {
    std::cin >> t[i];
  }
  for (int i = 0; i < n; ++i) {
    d[i] = c[i] - t[i]; // precompute
  }

  // sort ascending
  std::sort(d.begin(), d.end());

  while (q--) {
    int v, s;
    std::cin >> v >> s;

    // index of the first d_i > s
    int i = std::upper_bound(d.begin(), d.end(), s) - d.begin();
    int visitable = n - i; // # of farms can visit

    if (visitable >= v) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }

  return 0;
}