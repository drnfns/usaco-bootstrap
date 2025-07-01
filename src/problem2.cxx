#include <iostream>
#include <queue>
#include <string>
#include <vector>

// { time_of_emptiness, cow_index }
using Event = std::pair<long long, int>;

int main() {
  // io optimisation
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  // --- inputs ---
  long long n, m;
  std::cin >> n >> m;

  std::string s;
  std::cin >> s;

  std::vector<long long> a(n);
  long long total_milk = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    total_milk += a[i];
  }

  std::vector<int> target(n), inflow(n, 0);
  for (int i = 0; i < n; ++i) {
    target[i] = static_cast<int>((i + (s[i] == 'R' ? 1 : n - 1)) % n);
    inflow[target[i]]++;
  }

  std::priority_queue<Event, std::vector<Event>, std::greater<>> events;
  long long num_sinks = 0;
  for (int i = 0; i < n; ++i) {
    if (inflow[i] == 0)
      events.emplace(a[i], i);
    else if (inflow[i] == 2)
      num_sinks++;
  }

  // --- simulation ---
  long long total_loss = 0;
  long long current_time = 0;

  while (!events.empty()) {
    auto [t_empty, u] = events.top(); // u is the cow emptying
    events.pop();

    if (t_empty >= m) {
      events.emplace(t_empty, u);
      break;
    }

    // loss at sinks during the time until this event
    total_loss += num_sinks * (t_empty - current_time);
    current_time = t_empty;

    int v = target[u]; // v is the cow that u was supplying
    inflow[v]--;

    if (inflow[v] == 1) {
      // sink -> conveyor
      num_sinks--;
    } else if (inflow[v] == 0) {
      // conveyor -> drain
      events.emplace(current_time + a[v], v);
    }
  }

  // sinks keep losing milk until time M
  if (current_time < m) {
    total_loss += num_sinks * (m - current_time);
  }

  std::cout << total_milk - total_loss << "\n";

  return 0;
}
