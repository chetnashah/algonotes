
Useful for common prefix finding.
Also known as prefix tree/trie.
A `prefix` string is basically a substring of original string that includes the first charachter.
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

**Note** nodes typically dont have identity/values, it is the edges/references offset that are important to be tracked (which implicitly represent trie edges).
Nodes might have terminal state that must be tracked.

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

2-d array based representation, `int nxt[N][A]` where `N` are nodeids and `A` is size of alphabet.
first index is nodeId, second index is char int value that matches,
and the overall value points to next node id.

i.e `nxt[nodeId][edgeChar] = ++N`, note nodes are for convinience, edgeChar matter as they form actual strings.
The tree is rooted at `nodeId = 0;`
Note if `nxt[nodeId][edgeChar] == 0` means that edgeChar does not exist at that nodeId.

```cpp
int root =0;
bool isTerminal[100000];// index is node-id
int nxt[100000][26];// first index is node-id
// or int nxt[N][A] where N is number of nodes, and A is size of alphabet

addWords(vector<string> words) {
    int N = 0;// node-id generation
    for(string s: words) {
        int node = 0; // adding of any new word starts from 0
        for (char c: s) {
            if(nxt[node][c-'a'] == 0) {
                nxt[node][c-'a'] = ++N;// create nodeID if does not exist via edge pointing
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

    TrieNode getNext(char c) {
        return children[c-'a'];
    }
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

    public TrieNode getNext(char c) {
        return children[c - 'a'];
    }
}
```

### deleting nodes is tricky 
