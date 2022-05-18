

## Approach 1 : Two stacks, one for pushing, another for dequeue

`Core idea`: 

Push operation: keep pushing items on first stack1
Deque Operation: move all the items to second stack2, now the top element on second stack2 is actally front of queue(that should be dequeued), so pop and return it, re-arrange the remaining items back to stack1.

#### Push 1

stack1:
| 1 |
| --- |

stack2:
||
| --- |


#### Push 2

stack1:
| 1 | 2 |
| --- | --- |

stack2:
||
| --- |

#### Push 3
stack1:
| 1 | 2 | 3 |
| --- | --- | --- |

stack2:
||
| --- |

### Deque()

stack1:
| 1 | 2 | 3 |
| --- | --- | --- |

stack2:
||
|---|

|
v

stack1:
| 1 | 2 |
| --- | --- |

stack2:
| 3 |
| --- |

|
v

stack1:
| 1 |
| --- |

stack2:
| 3 | 2 |
| --- | --- |

|
v

stack1:
| | 
| --- |

stack2:
| 3 | 2 | 1 |
| --- | --- | --- |

|
v

to return dequued element,pop from top of stack2: `1`

stack1:
| |
| --- |

stack2:
| 3 | 2 |
| --- | --- |

1 returned

|
v

now move all items back to stack1

stack1:
| 2 |
| --- |

stack2:
| 3 |
| --- |

|
v

stack1:
| 2 | 3 |
| --- | --- |

stack2:
| |
| --- |

#### push 9

stack1:
| 2 | 3 | 9 |
| --- | --- | --- |

stack2:
||
| --- |


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

