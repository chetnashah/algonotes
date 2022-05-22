

## Approach1: Try pushing and popping things on/off stack

We can keep pushing things on stack, and popping stuff when seen again.
If at the end of traversal, we have empty stack, then we have a palindrome.

Issue with this approach: middle element might be single or double.
single middle element has some edge cases.

## Approach2: reverse a linked list and compare: extra O(N) space

reversed linked list would be a clone of original list.

## Approach3: find middle of linked list, reverse second half and compare

Find middle of linked list using slow/fast pointers as mentioned [here](FindMiddleOfALinkedList.md),
Then reverse second half of linked list as mentioned [here](ReverseLinkedList.md).

### List iteration, node comparision cases:

`Case 1` : Now if both nodes are non-null and have same data, return true.
`Case 2`: if one of the nodes is non-null and other is null, return true (because this might be odd length list and middle element is always considered a palindrome in itself)
`Case 3`: both nodes are non-null, but different data, return false;
