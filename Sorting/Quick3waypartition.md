
## Resources
https://algs4.cs.princeton.edu/23quicksort/
https://leetcode.com/problems/sort-colors/solution/

## Quick 3 way parition also known as dutch national flag problem

case 1:
`el[i] = middle element` -> `i++`

case 2:
`el[i] < middleElement` -> `swap(i,lo); i++, lo++`.

case 3:
`el[i] > middleElement` -> `swap(i, hi); hi--`

## termination conidition

`if i > hi: return`
or 
`while i <= hi: ...`

## An array with total 3 items repeated multiple time (to be done in O(n) via partition)

e.g.
`[2,0,2,1,1,0]` -> `[0,0,1,1,2,2]`

## implementation

```py
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        lo = i = 0
        hi = len(nums) - 1
        
        while True:
            if (nums[i] == 1): # i is increased only when 1 is found
                i = i+1
            elif (nums[i] < 1): # both lt and i need to be increased when 0 is found
                nums[lo], nums[i] = nums[i], nums[lo] 
                lo = lo+1
                i = i+1
            elif (nums[i]>1): # right pointer needs to be decreased when 2 is found
                nums[hi], nums[i] = nums[i], nums[hi]
                hi = hi - 1
                
            if(i > hi):
                return
```

### is it stable?



