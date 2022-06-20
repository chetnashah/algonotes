
##

https://leetcode.com/problems/construct-k-palindrome-strings/

##

## Base case: string length must be atleast equal to K(we will have single letter as palindromes), otherwise return 0


## Case k < str.length()

### Create a frequency map

### Observation: number of odd occuring charachters should not exceed k

Proof: there can be at max one odd occuring char per palindrome,
if we more than k chars with odd frequency in frequency map, we need to make more than k palindromes.


### In all other cases k palindromes can be formed

## TODO code

