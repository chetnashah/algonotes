

https://leetcode.com/problems/group-anagrams/

## approach 1: group by sorted unique representation as hashmap key

## approach 2: make a count string and use it as hash key

the hashable representation of our count will be a string delimited with `#` characters. 
For example, `abbccc` will be `#1#2#3#0#0#0...#0` where there are `26` entries total

