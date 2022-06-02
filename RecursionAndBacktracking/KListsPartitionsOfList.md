


PArtition a given list into K nonempty sub-lists

Note this is different than K non empty subsets because order is preserved in sublists.

e.g.
3-partitions of `[1,2,3,4]` are:
`[1,2],[3],[4]`,
`[1],[2,3],[4]`,
`[1],[2],[3,4]`

### code

```java
public class Main {
    public static void main(String[] args) {
        List<Integer> list = new ArrayList<Integer>();
        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);
        list.add(5);
        list.add(6);
        List<List<Integer>> state = new ArrayList<>();
        int k = 2;
        printKParitions(state, list, k, 0, list.size() - 1);
    }
    
    static void printKParitions(List<List<Integer>> state, List<Integer> original, int k, int start, int end) {
        // System.out.println(" state = " +state + " start = "+ start + " end = "+end);
        if(state.size() == k-1) {
            // state list + original[start..end] = k sized partitioning
            ArrayList<Integer> thisList = new ArrayList<>();
            for(int i=start; i<=end;i++) {
             thisList.add(original.get(i));
            }

            List<List<Integer>> ans = new ArrayList<>();
            ans.addAll(state);
            ans.add(thisList);
            System.out.println("ans = " + ans);
        }
        
        for(int m=start+1;m<=end;m++) {
            List<Integer> first = new ArrayList<>();
            for(int j=start;j<m;j++) {
                first.add(original.get(j));
            }
            state.add(first);
            printKParitions(state, original, k, m, end);
            state.remove(first);
        }
    }   
}
```


