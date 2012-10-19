http://www.careercup.com/question?id=11534280
Solution :-
scan the string from left to right
if all the occurences are either all even or all odd, then the minimm length to which it can reduce is 2
else minimum length is 1.
(1) String contains only one kind of characters, or more precisely, the string contains k identical characters and nothing else. Clearly, no reduction is poosible and the minimum length is k.

(2) String contains 2 or 3 kinds of characters. Then if all the counts are even or all the counts are odd, the minimum string possible has length 2, otherwise we can reduce it to 1.

Proof (of 2):
With every reduction, the count of 2 characters decreases by 1, and the count of the third character increases by 1. So if all counts are even before reduction, all counts will be odd after reduction, and if allcounts are odd before, they will all be even after. So, for such strings, the shortest possible string we can get is (0, 0, 2) or (cc) or (bb) or (aa). All even counts. This proves that we can't do any better than (0, 0, 2).
Now, are we guaranteed that we can always get to (0,0,2) for the all-odd, all-even strings and to (0,0,1) for the other strings? YES! We just have to be smart about which pairs we reduce. For example, if our string is aaaaaaabc we can either reduce ab or bc. Reducing bc would mean no more reduction so we don't want to do that! So the algorithm to reach minimum string is this -- always reduce a pair that contains a character with maximum count. It does not matter which pair, just that the max count character be reduced. This will eventually result in a string of length 1 or 2 depending on the initial counts.
String Reduction (25 Points)

Given a string consisting of a,b and c's, we can perform the following operation: Take any two adjacent distinct characters and replace it with the third character. For example, if 'a' and 'c' are adjacent, they can replaced with 'b'. What is the smallest string which can result by applying this operation repeatedly?

Input:
The first line contains the number of test cases T. T test cases follow. Each case contains the string you start with.

Output:
Output T lines, one for each test case containing the smallest length of the resultant string after applying the operations optimally.

Constraints:
1 <= T <= 100
The string will have at most 100 characters.

Sample Input:
3
cab
bcab
ccccc

Sample Output:
2
1
5

Explanation:
For the first case, you can either get cab -> cc or cab -> bb, resulting in a string of length 2.
For the second case, one optimal solution is: bcab -> aab -> ac -> b. No more operations can be applied and the resultant string has length 1.
For the third case, no operations can be performed and so the answer is 5.
