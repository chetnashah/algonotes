

## Approach 1 : Two stacks, one for pushing, another for dequeue

`Core idea`: 

`Push operation`: keep pushing items on first stack1. O(1) time


`Deque Operation`: - O(2 * n).
1. move all the items to second stack2, 
2. now the top element on second stack2 is actally front of queue(that should be dequeued), so pop and return it, 
3. re-arrange the remaining items back to stack1. complexity 

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
**dequeu operation** 1 returned
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
| -- | -- | -- |

</td>
<td>

stack2:
||
| -- |

</td>
</tr>
</table>

### Code

```java
  public static class Queue {
    Stack<Integer> st1 = new Stack<>();
    Stack<Integer> st2 = new Stack<>();

    public void enqueue(Integer x) {
      st1.push(x); // enqueue is simple push onto first stack
    }
    public Integer dequeue() {
      while(!st1.empty()) { // move all elements to st2
        st2.push(st1.pop());
      }
      Integer ret = st2.pop(); // pop from s2 for dequeue
      while(!st2.empty()) { // move all remaining elements back to st1 
        st1.push(st2.pop());
      }
      return ret;
    }
  }
```

## Better amortized O(1) approach - 

Amortized means single approach might take O(1) but n operations will take O(n).

Idea is similar: same behavior for enqueue, but different behavior for `dequeue`

1. `enqueue/push` - push elements on the first stack1.
2. `dequeue` - 
   1. if second stack2 is non empty, pop the top: O(1)
   2. if second stack2 is empty, move all items from stack1 to stack2. May be O(n) worst case. (but then next n dequeues will be trivial)

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

### Deque() - case stack2 was empty - moving all elements to stack2

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
**dequeu operation** 1 returned
</td>
</tr>

</table>


#### push 9

<table>
<tr>
<td>

stack1:
| 9 |
| -- |

</td>
<td>

stack2:
| 3 | 2 |
| -- | -- |

</td>
</tr>
</table>

#### Dequeue: Case stack2 non empty - dequeue is trivial, just pop the top

<table>
<tr>
<td>

stack1:
| 9 |
| -- |

</td>
<td>

stack2:
| 3 | 2 |
| -- | -- |

</td>
<td>
Dequeue is trivial, st2.pop() needs to happen
</td>
</tr>

<tr>
<td>

stack1:
| 9 |
| -- |

</td>
<td>

stack2:
| 3  |
| -- |

</td>
<td>
Dequeue operation returns: 2
</td>
</tr>

</table>

### Code

```java
class MyQueue {

    Stack<Integer> st1;
    Stack<Integer> st2;
    public MyQueue() {
        st1 = new Stack<>();
        st2 = new Stack<>();
    }
    
    public void push(int x) { // enqueue is trivial, push to st1
        st1.push(x);
    }
    
    public int pop() {
      if(st2.isEmpty()) { // case st2 is empty, move elements to st2 first
          moveElementsToS2();
      }
      return st2.pop(); // pop from top of st2
    }
    
    public int peek() {
        int ret;
        if(st2.empty()) {// case st2 is empty, move elements to st2 first
            moveElementsToS2();
        }
        return st2.peek();
    }
    
    private void moveElementsToS2(){
        // we come here only when there is stuff in st1, but st2 is empty
        while(!st1.isEmpty()) {// empty st1 
            st2.push(st1.pop());// move those items to st2
        }
    }
    
    public boolean empty() {
        return st1.size() == 0 && st2.size() == 0; 
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
```