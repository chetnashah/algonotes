
## Remove duplicates (all occurrences) in linked list

### With O(N) space, with hashmap

create a hashmap with key as int and value is count of those nodes in list.

Do one more linear iteration on the linkedlist, this time consulting the hashmap, and remove the node while iterating if count is greater than 1 in hashmap.

### With O(N) space, two sets - seen and duplicates, two pass iteration

First pass - Iterate and keep putting in `seen` set, if encountered already seen, put it also in `duplicates` set.
Second pass - This time during iteration, remove nodes which are present in `duplicates` set.

## Code

https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list/

