#include <iostream>
#include <string>

void solve() {
  std::string s; // stones
  std::cin >> s;

  // if the last digit is 0, the position is losing
  // otherwise, it is winning
  if (s.back() == '0') {
    std::cout << "E" << std::endl;
  } else {
    std::cout << "B" << std::endl;
  }
}

int main() {
  int tc; // test count
  std::cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}
