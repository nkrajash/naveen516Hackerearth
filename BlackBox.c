/*
BLACKBOX-2
All Tracks  Math  Problem

Tag(s): Medium

Vivek was roaming around in the electronics shop, where he saw a box called as BlackBox. He was intrigued by its function, so he bought it. 
It's functionality states that for given integer input N<=1000  - it outputs the sum of all the digits in factorial of N (N).

Now Vivek wants to extend its functionality for large numbers. So, he wants you to write a program that can check the correctness of the BlackBox .

INPUT :

The first line of the input contains a single integer T ( the number of test cases ). Next T lines of input contains an integer N .

OUTPUT :

For each test case, print the sum of all digits in the factorial of the corresponding input integer.

Constraints
1<=T<=1000
0<=N<=10^3

SAMPLE INPUT 
5
1
2
3
4
5
SAMPLE OUTPUT 
1
2
6
6
3

Explanation
for test 1, N=1 , factorial of N=1 , sum of digits = 1. for test 2, N=2 , factorial of N=2 , sum of digits = 2. for test 3, N=3 , factorial of N=6 , sum of digits = 6. 
for test 4, N=4 , factorial of N=24 , sum of digits = 6. for test 5, N=5 , factorial of N=120 , sum of digits = 3.


