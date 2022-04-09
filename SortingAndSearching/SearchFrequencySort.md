

### Idea: `Move first heuristics`: most frequently searched item is found near head of list

Everytime an element an element is searched and found, it is moved to head of list.
Assumption: we have search probabilities of items.

This would result in almost constant time searches if 1st element is searched 50% of the time, 2nd element 25% ...

Similarly we can have `move last heuristics`, i.e. move to last after every successful search

