

## A recursive sequence that shows up in many places like parenthesization, number of balanced BSTs etc

##

1, 2, 5, 14, ...

## REcurrence formula

$$ C_0 =  C_1 = 1$$

$$ C_n = \sum_{k=0}^{n-1} C_k * C_(n-1), n >= 2$$

## Code

