

## Approach 1 : Two stacks, one for pushing, another for dequeue

`Core idea`: 

`Push operation`: keep pushing items on first stack1.


`Deque Operation`: move all the items to second stack2, now the top element on second stack2 is actally front of queue(that should be dequeued), so pop and return it, re-arrange the remaining items back to stack1.

#### Push 1

<table>
<tr>
<td>
stack1:
| 1 |
| --- |
</td>
<td>
stack2:
||
| --- |
</td>
</tr>
</table>

#### Push 2

<table>
<tr>
<td>
stack1:
| 1 | 2 |
| --- | --- |
</td>
<td>
stack2:
||
| --- |
</td>
</tr>
</table>

#### Push 3

<table>
<tr>
<td>
stack1:
| 1 | 2 | 3 |
| --- | --- | --- |
</td>

<td>
stack2:
||
| --- |
</td>
</tr>
</table>

### Deque()

<table>
<tr>
<td>
stack1:
| 1 | 2 | 3 |
| --- | --- | --- |
</td>
<td>
stack2:
||
|---|
</td>
<td>
initial state
</td>
</tr>

<tr>
<td>
stack1:
| 1 | 2 |
| --- | --- |
</td>
<td>
stack2:
| 3 |
| --- |
</td>
<td>
pop from st1, push to st2
</td>
</tr>

<tr>
<td>
stack1:
| 1 |
| --- |
</td>
<td>
stack2:
| 3 | 2 |
| --- | --- |
</td>
<td>
pop from st1, push to st2
</td>
</tr>

<tr>
<td>
stack1:
| | 
| --- |
</td>

<td>
stack2:
| 3 | 2 | 1 |
| --- | --- | --- |
</td>
<td>
pop from st1, push to st2,
st1 now empty,
to return dequued element, pop from top of stack2: `1`
</td>
</tr>


<tr>
<td>
stack1:
| |
| --- |
</td>
<td>
stack2:
| 3 | 2 |
| --- | --- |
</td>
<td>
1 returned
</td>
</tr>


<tr>
<td>
stack1:
| 2 |
| --- |
</td>
<td>
stack2:
| 3 |
| --- |
</td>
<td>
moving items back to st1
</td>
</tr>

<tr>
<td>
stack1:
| 2 | 3 |
| --- | --- |
</td>

<td>
stack2:
| |
| --- |
</td>
<td>
We are done when st2 is empty
</td>
</tr>

</table>


#### push 9

<table>
<tr>
<td>
stack1:
| 2 | 3 | 9 |
| --- | --- | --- |
</td>
<td>
stack2:
||
| --- |
</td>
</tr>
</table>

### Code

```java
  public static class Queue {
    Stack<Integer> st1 = new Stack<>();
    Stack<Integer> st2 = new Stack<>();

    public void enqueue(Integer x) {
      st1.push(x);
    }
    public Integer dequeue() {
      while(!st1.empty()) {
        st2.push(st1.pop());
      }
      Integer ret = st2.pop();
      while(!st2.empty()) {
        st1.push(st2.pop());
      }
      return ret;
    }
  }
```

## Another

<table>
<tr><th>Table 1 Heading 1 </th><th>Table 1 Heading 2</th></tr>
<tr><td>

|Table 1| Middle | Table 2|
|--|--|--|
|a| not b|and c |

</td><td>

|b|1|2|3| 
|--|--|--|--|
|a|s|d|f|

</td></tr> </table>
