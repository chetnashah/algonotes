
Useful for common prefix finding.
Also known as prefix tree
Trie is basically a tree with Sigma branches, where Sigma is the cardinality of alphabet.

### Why not other data structures?
The `set <string>` and the `hash tables` can only find in a dictionary words that match exactly with the single word that we are finding; 
the trie allow us to find words that have a single character different, a prefix in common, a character missing, etc.

### Root is always empty/0


### Representation of Node

Sigma = size of alphabet e.g. 26 for `a-z`
P = pattern to search in text
T = text

Can be represented by
1. array - an array of sigma pointers (can be null or point to other nodes), space O(T.Sigma), query = O(P). Charechters are implicitly defined by link index.
2. tree - 
3. hashtable - 

### Topcoder tutorial representation

```cpp
struct TrieNode {
    TrieNode* children[26];
    int count = 0;
    int prefixes = 0;
}
```


### Wikipedia tutorial representation
**Root node is empty string**

```java
class TrieNode {
    char c;// optional
    TrieNode edges[26];
    boolean isTerminal;
    String terminalValue;
}
```


### Errichto tutorial representation

2-d array based representation,
first index is nodeId, second index is char int value that matches,
and the overall value points to next node id.

```cpp
int root =0;
bool isTerminal[100000];// index is node-id
int nxt[100000][26];// first index is node-id

addWords(vector<string> words) {
    int N = 0;// node-id generation
    for(string s: words) {
        int node = 0; // adding of any new word starts from 0
        for (char c: s) {
            if(nxt[node][c-'a'] == 0) {
                nxt[node][c-'a'] = ++N;
            }
            node = nxt[node][c-'a'];// linkelist like next pointer manipulation
        }
        // after adding all chars, mark that nodeid terminal
        is_terminal[node] = true;
    }
}
```

### Tushar roy representation

```cpp
struct TrieNode{
    map<char, TrieNode> children;
    boolean endOfWord;
}
root = new TrieNode();
```

### GKCS representation

```java
class TrieNode {
    int terminating;
    TrieNode[] trieNodes;

    public TrieNode next(char c) {
        return trieNodes[c - 'a'];
    }
}
```

### Hackerrank representation

```java
class TrieNode {
    HashMap<Charachter, TrieNode> children;
    boolean isCompleteEnd;
}
```

### deleting nodes is tricky 
