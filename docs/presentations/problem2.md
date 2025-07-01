---
title: 'problem 2: milk exchange'
sub_title: usaco bronze bootstrap
author: drnfns
date: 2025-06-30
theme:
  name: catppuccin-mocha
---

# problem summary

<!-- pause -->

## given

<!-- incremental_lists: true -->

- `N` cows in a circle
- each cow passes 1 litre of milk left (`'L'`) or right (`'R'`) per minute
- each cow has max milk capacity: `a_i`
- transfers are simultaneous
- after `M` minutes, output total milk left

<!-- end_slide -->

# idea

most cows preserve their milk, and we only need to track who loses milk

<!-- pause -->

classify cows by inflow:

<!-- incremental_lists: true -->

- **sinks** (`inflow == 2`): spills 1 litre per min
- **conveyors** (`inflow == 1`): stable until input dries up
- **drains** (`inflow == 0`): loses 1 litre per min instantly

<!-- end_slide -->

# strategy

should we simulate every minute?

<!-- pause -->

no.

<!-- pause -->

instead:

- only simulate moments when cows run out of milk with events
- use `priority_queue` to track the next emptiness

<!-- end_slide -->

# algorithm

<!-- pause -->

## precompute

- compute the `targets` array, which shows who each cow passes to
- count `inflow` for each cow

<!-- pause -->

## queue events:

- if `inflow[i] == 0`: cow `i` drains in `a[i]` mins;
- if `inflow[i] == 2`: count as a **sink**

<!-- pause -->

## simulate:

- pop event (the earliest empty cow)
- calculate `total_loss += num_sinks * (t_empty - current_time)`
- react to new drain if `inflow` hits `0`

<!-- pause -->

## final calculation

after all events are calculated, or time `M` is reached:

- if there are still time left, **sinks** still spill.
  `total_loss += num_sinks × (M - current_time)`
- amount of milk remaining: `total_initial_milk - total_loss`

<!-- end_slide -->

# summary

- identify who loses milk
- use `priority_queue` for fast event simulation
- calculate `output = total - loss`

<!-- end_slide -->

# simulation code

```c++
  while (!events.empty()) {
    auto [t_empty, u] = events.top(); 
    events.pop();

    if (t_empty >= m) {
      events.emplace(t_empty, u);
      break;
    }

    total_loss += num_sinks * (t_empty - current_time);
    current_time = t_empty;

    int v = target[u]; 
    inflow[v]--;

    if (inflow[v] == 1) {
      num_sinks--;
    } else if (inflow[v] == 0) {
      events.emplace(current_time + a[v], v);
    }
  }

  if (current_time < m) {
    total_loss += num_sinks * (m - current_time);
  }
```
