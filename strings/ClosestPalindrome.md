
https://leetcode.com/problems/find-the-closest-palindrome/

##

Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.

The closest is defined as the absolute difference minimized between two integers.

##

Example 1:
```
Input: n = "123"
Output: "121"
```
Example 2:
```
Input: n = "1"
Output: "0"
Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.
```

Constraints:
```
1 <= n.length <= 18
n consists of only digits.
n does not have leading zeros.
n is representing an integer in the range [1, 10^18 - 1].
```

## Brute force approach

Keep incrementing/decrementing number in both directions, and check if palindrome.
Unfortunately this is not possible since limits are 10^18

## Observations

### You cannot return the same number

### It is fine to use digits not in original string

### Idea: try to makes second half same as first half

Why is this a valid strategy? because changing anything in the first half means moving away a lot from the original number.

#### Some edge case: 10000 -> 9999, 10001: here we must select the smaller one: 9999

### Another edge case: if number itself is palindrome, there is no point making first half same as second half, since it is already there.

Even length case: e.g. "123321"
Split into two half, increment/decrement the last digit in first half(so that we increment minimally), and see the differences.
For `123321` -> `123 | 321`
Two options: `124 | 421`
or `122 | 221`

Odd length palindrome input e.g. `12321`
Here the answer is simpler, decrement middle char and we have the answer.
i.e. `12221`
But what if middle char is 0?
e.g. `10001` -> ? TODO

#### Interesting test case: 11 -> 9 is closest palindrome

#### Base case: single digit input n -> return n-1.

