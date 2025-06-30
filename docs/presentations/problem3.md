---
title: 'problem 3: maximising productivity'
sub_title: usaco bronze bootstrap
author: drnfns
date: 2025-06-30
theme:
  name: catppuccin-mocha
---

<!-- jump_to_middle -->

# the problem

<!-- incremental_lists: true -->

- **goal:** bessie want to know if she can visit `V` farms.
- **condition:** she wakes up at time `S`.
- **challenge:** each farm closes at its own time `c_i`, and it takes a certain
  time `t_i` to get there.

<!-- end_slide -->

# core condition

<!-- column_layout: [1, 1] -->
<!-- column: 0 -->
<!-- jump_to_middle -->
<!-- alignment: center -->
<!-- pause -->

## arrival time at farm `i`

<!-- pause -->

```latex +render
$ t_i + S$
```

<!-- column: 1 -->
<!-- jump_to_middle -->
<!-- pause -->

## closing time at farm `i`

<!-- pause -->

```latex +render
$ c_i $
```

<!-- end_slide -->

# core condition, continued

<!-- alignment: center -->

## formula

<!-- pause -->

```latex +render
$ t_i + S < c_i $
```

<!-- pause -->

```latex +render
$ S < c_i - t_i $
```

<!-- pause -->

```latex +render
$ d_i = c_i - t_i $
```

<!-- pause -->

```latex +render
$ S < d_i $
```

<!-- end_slide -->

# solution 1

<!-- column_layout: [1, 1]-->
<!-- column: 0 -->

## walkthrough

<!-- incremental_lists: true -->

for each query `(S, V)`:

0. initialize a counter for visitable farms
1. loop through all `N` farms
2. for each farm, we check if `S < d_i`
3. if it is `true`, add `1` to the counter
4. after looping all `N` farms, check if the amount of visitable farms >= `V`

<!-- column: 1 -->

## pseudocode

```python
for (S, V) in Q:
  visitable_farms = 0
  for i from 1 to N:
    d_i = c[i] - t[i]
    if S < d_i:
      visitable_farms += 1
  if visitable_farms >= V:
    print("YES")
  else:
    print("NO")
```

<!-- end_slide -->

# solution, continued

<!-- alignment: center -->
<!-- jump_to_middle -->

## new steps

<!-- incremental_lists: true -->

1. **pre-process**: calculate all `d_i`, and sort them
2. **query**: use organized data to answer each query

<!-- end_slide -->

# solution, continued

<!-- pause -->

<!-- column_layout: [1, 1] -->
<!-- column: 0 -->

## pre-processing

<!-- incremental_lists: true -->

0. make a new array to store `d_i`s (`d_values`)
1. loop through all `N` farms and calculate `d_i`, and store in `d_values`
2. **sort** `d_values` in **ascending** order

## querying

for each query `(S, V)`:

1. use **binary search** to find the first element that is > `S`.
2. if it is at index `i`, then all elements from `i` to the end are visitable
3. check if `N - j` >= `V`.

<!-- column: 1 -->

## pseudocode

```python
# precompute
d_values = []
for i in 0 to N-1:
  d_i = c[i] - t[i]
  d_values.append(d_i)

d_values.sort()

for (S, V) in Q:
  index = binary_search_for_first_greater(d_values, S) # first d_i > S
  visitable = N - index # count visitable farms
  if visitable >= V:
    print("YES")
  else:
    print("NO")
```

<!-- end_slide -->
<!-- alignment: center -->
<!-- jump_to_middle -->

# thank you!
