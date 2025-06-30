#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  // io optimisation
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

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
    auto it = std::upper_bound(d.begin(), d.end(), s);
    // # of farms can visit
    int visitable = static_cast<int>(std::distance(it, d.end()));

    if (visitable >= v) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }

  return 0;
}