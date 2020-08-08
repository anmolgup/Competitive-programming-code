F : See all consecutive permutation elements in p and if they're inverted in q then add an interval indicating that this interval must have all equal elements	or kosaraju's
[10:27 PM] dumb cow: yeah alex
[10:27 PM] dumb cow: now every element in permutation q that occurs between x and y has to have the same character
[10:28 PM] dumb cow: let dp[i] denote the leftmost index in permutation q that the string index q[i] has to be equal to
[10:29 PM] dumb cow: dp[i]=i if all active intervals at index i in permutation q start at i itself, otherwise dp[i]=dp[i-1]
[10:31 PM] dumb cow: an interval, as I said, is of the form l = x and r = y where x occurs after y in permutation p but before in permutation q, and their occurrence is consecutive in p.
[10:32 PM] dumb cow: it's a good exercise to prove why it is sufficient to consider consecutive and not all such pairs