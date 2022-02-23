/*
Lab 1
COMP-2540
By: Lucas Sarweh
ID: 110042658 
*/

2. Check the correctness of the algorithm for the following values of m and n:
(m, n): (14, 21) (56, 32) (63, 99) (210, 54) (1240, 735)

(14, 21): 14 % 21 = 14, 21 % 14 = 7, 14 % 7 = 0 -> gcd(14, 21) = 7

(56, 32): 56 % 32 = 24, 32 % 24 = 8, 24 % 8 = 0 -> gcd(56, 32) = 8

(63, 99): 63 % 99 = 63, 99 % 63 = 36, 63 % 36 = 27, 36 % 27 = 9, 27 % 9 = 0 -> gcd(63, 99) = 9

(210, 54): 210 % 54 = 48, 54 % 48 = 6, 48 % 6 = 0 -> gcd(210, 54) = 6

(1240, 735): 1240 % 735 = 505, 735 % 505 = 230, 505 % 230 = 45, 230 % 45 = 5, 45 % 5 = 0 -> gcd(1240, 735) = 5

5. So … looking at the graph you generated, what observations can you make? In
particular, what do you notice about the relationship between the two curves (e.g., no apparent relationship,
intersecting, not intersecting, one always greater, always equal, etc.)? Can you find a bounding formula y = f(n)
that is better than y = 2*ceil(log(n))?

I can see that y=2*ceil(log(n)) (Assuming it's base 2) is always greater than maxIterations[n]. So I can say that for the worst case
m for a given n, maxIterations[n] is O(2*ceil(log(n))). A better bounding formula would be y = 2 * ln(x) (The natural logarithm).