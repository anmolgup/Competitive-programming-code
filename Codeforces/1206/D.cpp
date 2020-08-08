problem 580 D
The idea is the same as

Problem Source, Spoiler Warning
IOI 2019 Day 1 Split

First, we solve for star graph. Choose a constant 𝐶 in the range [N/3, N/2], then assign edge weights 1, 2, ..., C and (C+1), 2(C+1), ..., (N-1-C)(C+1).

How to solve for general graph? Root the tree at centroid. We claim that there exist a subset of children of the centroid so that their subtree sizes sum up to [N/3, 2N/3]. If one of the direct child of centroid has subtree size >= N/3, we're done. Otherwise, keep adding subtrees until the sum is >= N/3. Since each subtree size < N/3, total sum does not exist 2N/3.

Now, we use the same idea as star graph within these two sets and we're done.


The approach is simple compute for each bit i from 0 to 64, which all numbers have the i th bit set. Then if any of bit i have less than 2 numbers with that bit set, it will not affect and will not result to any connection. Otherwise if any of bit i have more than 2 elements, then the answer will be 3 always(take any 3 elements among those).

The case rises when we have bits with 2 entries. So maximum edges resulting from these bits will be 64. Considering these edges we can use out edge removal approach explained here :Find minimum weight cycle in an undirected graph

If no cycle then answer will be -1.


I did it this way- The maximum number in the input is 10^18 which can be represented in 64 bits. The minimum possible cycle can be of length 3. If we have the xth bit set in any 3 numbers, then we are done! (all 3 will be mutually connected because of non zero "and") There are at max 64 bits. => If we have more than 128 non zero numbers (By PHP) in the array, then we will get a cycle of length 3.

Now for <= 128 non zero numbers. We can check by actually making a graph. It will take O(m^2), which will be well within the bounds.


For div2,D If the number of non_zero numbers is more than or equal to 119 ,we can just output 3.（Pigeonhole Principle,think of each bit as a pigeonhole,and think of each non_zero number as a pigeon） If it is less than 119,we can just use Floyd algorithm,we can solve it in O(n^3).

This might be a little bit easier to understand.

https://codeforces.com/problemset/submission/1206/59043624


If there exist three number with common bit you got the answer. Else build the graph which contains only few edges. Find shortest cycle in it.