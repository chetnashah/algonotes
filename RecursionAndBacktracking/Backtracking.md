
## resources

https://www.youtube.com/watch?v=Zq4upTEaQyM

https://www.topcoder.com/blog/generating-permutations/

https://labuladong.gitbook.io/algo-en/iii.-algorithmic-thinking/detailsaboutbacktracking

http://ruslanledesma.com/2016/06/17/why-does-heap-work.html

https://www.youtube.com/watch?v=0hDwNjtJBrs

##

Backtracking is a multi-tree traversal problem. The key is to do some operations at the positions of pre-order traversal and postorder traversal.

Backtracking is basically a depth first search (for loop + recursion) on an implicit graph of configurations.


Three key things:

1. Path: the selection that have been made.
2. Selection List: the selection you can currently make. (this makes the tree possible)
3. End Condition: the condition under which you reach the bottom of the decision tree, and can no longer make a selection.

## Pattern

```py
result = []
def backtrack(Path, Seletion List ):
    if meet the End Conditon: # e.g. Path length is full
        result.add(Path)
        return

    for seletion in Seletion List:
        if(invalid usecase):
            early return or continue?
        else :
            select
            backtrack(Path, Seletion List)
            deselect
```

## Permutations

Idea: Remove each element from the n elements one at a time, 
then append it to the (n-1)! remaining permutations.

```java
public String swap(String a, int i, int j) {
  char temp;
  char[] charArray = a.toCharArray();
  temp = charArray[i];
  charArray[i] = charArray[j];
  charArray[j] = temp;
  return String.valueOf(charArray);
}
/**
This function does permutations from index idx to N inclusive.
*/
private void backtrack(String s, int idx, int N) {
  if (idx == N)
    System.out.println(s);
  else {
    for (int i = idx; i <= N; i++) {// for loop for choices
      s = swap(s, idx, i);// fix one thing i.e. ith index, and recurse on the rest in next statement
      backtrack(s, idx + 1, N);// recurse
      s = swap(s, idx, i);// has to be reset/unselected ith index to original for future rounds
    }
  }
}

void solve() {
  String s = ”ABC”;
  int N = s.length;
  backtrack(s, 0, N - 1);
}
```

## Heap's algorithm for lexicographic permutations

```java
 public void heaps_algorithm(int[] a, int n) {
     if(n == 1) {
         // (got a new permutation)
         System.out.println(Arrays.toString(a));
         return;
     }
     for(int i = 0;i > (n - 1);i++) {
         heaps_algorithm(a, n-1);
         // always swap the first when odd,
         // swap the i-th when even
         if(n % 2 == 0) swap(a, n-1, i);
         else swap(a, n-1, 0);
     }
     heaps_algorithm(a, n-1);
 }
```

## N Queens

For N = 4, there are 2 solutions.
For N = 8, there are 92 solutions.