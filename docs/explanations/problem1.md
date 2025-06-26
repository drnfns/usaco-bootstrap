# problem 1 proof

## definitions

let $S$ be the number of stones ($1 \leq S \leq 10^{10^5}$). a "move" is to
subtract a **palindrome** $p$ where $p \in \mathbb{N}$.

### terms

- **palindrome**: a number that reads the same backwards and forwards, but
  **leading zeros are not allowed**.
- **winning position**: has a number of stones where the current player can make
  a move that forces a win
- **losing position**: no matter what move the current player makes, the other
  player will be in a **winning position**.

### relationships

1. a position is a **winning position** if there exists at least one valid move
   to a **losing position**.
2. a position is a **losing position** if all valid moves lead to **winning
   position**.
3. when $S = 0$, it is a **losing position**.

## claim

### theorem

for any number of stones $S > 0$:

$$
S \in \text{winning} \iff S \not \equiv 0 \pmod{10}
$$

$$
S \in \text{losing} \iff S \equiv 0 \pmod{10}
$$

#### lemma

any natural number **palindrome** $p$ is not divisible by $10$.

$$
\forall p \in \mathbb{N},\space \text{palindrome}(p) \Rightarrow p \not \equiv 0 \pmod{10}
$$

_proof of lemma_: a number is divisible by $10$ if and only if its last digit is
$0$. for a number $p$ to be a **palindrome**, its string of digits must read the
same forwards and backwards; and according to that definition, if the last digit
is $0$, the first digit must also be $0$. however, in the definition, it states
that leading zeros are not allowed. therefore, a positive **palindrome** cannot
have $0$ as its first digit, and thus cannot have $0$ as its last digit. this
means $p$ cannot be a multiple of $10$. $\blacksquare$

### proof of theorem

proof using _strong induction_ on $S$.

#### base case

checking small values:

- if $S \in \{1, 2, 3, \dots, 9\}$, the player can remove all $p \equiv S$
  stones, since any single digit is a **palindrome**.
- if $S = 10$, the player cannot remove all $S$ stones, since it is not a
  **palindrome** (by our lemma). they will have to remove $p$ stones so that
  $S = 10 - p$, where $S \in \{1, 2, 3, \dots, 9\}$. according to our lemma and
  the case above, the next player can remove all $p \equiv S$ stones, putting
  the current player at a **losing position**.
- if $S < 10$, the player can remove all $S$ stones, since it is a valid
  **palindrome**, putting them in a **winning position**.

#### inductive hypothesis

assume that for all integers $k$ such that $0 < k < S$, our theorem holds --
where $k$ is a **losing position** _if and only if_ $k \equiv 0 \pmod{10}$.

#### inductive step

we consider two cases:

##### case 1: $S \equiv 0 \pmod{10}$

we want to show that any move to $S$ is a **losing position**, so we must show
that any valid move from $S$ leads to a **winning position**.

let the current player remove $p$ stones, where $p$ is a **palindrome** and
$p \le S$. the new number of stones are now $S' = S - p$.

we know that:

1. $S \equiv 0 \pmod{10}$ by the case definition; and
2. $p \not \equiv 0 \pmod{10}$ by our lemma.

so the new number of stones $S' \pmod{10}$ is:

$$
\begin{aligned}
S' \pmod{10} &= (S-p) \pmod{10} \\
             &= (0 - (p \pmod{10})) \pmod{10} && \text{(substitution)} \\
\end{aligned}
$$

since $p \pmod{10} \in \{1, 2, 3, \dots, 9\}$, it follows that
$S'\pmod{10} \not= 0$. therefore, any move from $S$ results in a new pile $S'$
which is not a multiple of $10$. since $p > 0$, we have $S' < S$.

by our inductive hypothesis, any such $S'$ is a **winning position**. since
every possible move from $S$ leads to a **losing position**, $S$ must be a
**losing position**.

##### case 2: $S \not \equiv 0 \pmod{10}$

we want to show that some move from $S$ leads to a **winning position**, so we
must show there exists _at least one_ move from $S$ to a **losing position**

assume the player chooses to move $p$ stones, where $p = S \pmod{10}$. the move
should satisfy these requirements:

- since $S \not \equiv 0 \pmod{10}$, $p$ will be an integer from $1$ to $9$
- $p \in \{1, 2, 3, \dots, 9\}$, which is a **palindrome** according to our
  definition
- $p = S \pmod{10} \le 9 < S$ for $S > 10$. if $S < 10$, $p = S$ is also a valid
  move.

the new number of stones will be:

$$
\begin{aligned}
S' &= S - p \\
   &= S - (S \pmod{10}) && \text{(substitution)} \\
\end{aligned}
$$

by that definition, $S'$ is now also divisible by $10$.

$$
\begin{aligned}
S'           &= S - (S \pmod{10}) \\
S' \pmod{10} &= S - (S \pmod{10}) \pmod{10} \\
(S \pmod{10}) - (S \pmod{10})) &= 0 \pmod{10} && \text{(subtraction)} \\
\end{aligned}
$$

since $p > 0$, we have $S' < S$. by our inductive hypothesis, this new position
$S'$ is a **losing position**.

we have found a move from $S$ to a **losing position**, which means $S$ is an
**winning position**. this proves the claim for this case.

## conclusion

both cases hold, so by the principle of strong induction, our theorem is true
for all natural numbers.

the first player wins if the starting number of stones $S$ is not a multiple of
$10$. the next player wins if $S$ is a multiple of $10$.

since a number ending in $0$ is exactly when $S \pmod{10} = 0$, the winning
strategy is simply to check if the last digit of $S$ is 0. $\blacksquare$
