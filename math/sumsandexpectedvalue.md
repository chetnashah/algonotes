
## Random variable

An experiment/event that gives a real numbered output.

## Trick

Cn I make a large/composite random variable from smaller random variables?

## Indicator random variable

Most common random variable.
A random variable whose value is 1 if event occurs and 0 if event does not occur.

`E[I] = 1 * P(I=1) + 0 * P(I=0) = P(I)`

### Examplw: number of heads in N flips (sum of indicator random variables trick)

indicator random variable: `H = 1` if head was seen, `H = 0` if tails

Hi = 1 if i'th flip was a head

H = H1 + H2 + H3 + ... + Hn // Total heads random variable is a sum of individual event random variables

### Expected value (of a random variable)

Assuming all possible events in an experiment have a value,
It is average/estimated weighted (by probability) value of an experiment.

```
E(X) = P(x1) * X(x1) + P(x2) * X(x2) + ... (For all possible events x1, x2 ...)  
```

### Linearity of expectation

`E(X + Y) = E(X) + E(Y)` even if X,Y are dependent

### non-independent events case

Even though X, Y are dependent, it does not matter for linearity of expectation

### Product of expectations

If X,Y are independent,
`E(X * Y) = E(X) * E(Y)`


### IID random variables (Independent and identically distributed random variables)

`Independence`: 
e.g. two coin flips or two dice rolls are independent of each other, one does not affect the other
Real definition: P (A and B) = P(A) * P(B)

Two random variables X and Y are called independent if, for any outcomes a and b,
```
P(X = a and Y = b) = P(X = a) * P(Y = b).
```

### Probability trick: Atleast 1 event probability
Instead of calculating atleast 1 event probability, sometimes it is easier to calculate 1 - (No occurence probability)

### Example: Expected value of max of two dice

Denote outcomes (𝑋1,𝑋2) and 𝑍=max{𝑋1,𝑋2}. 
Then just use that the outcomes are independent and break the event "𝑍=𝑎" into 
"(𝑋1=𝑎 and 𝑋2≤𝑎) or (𝑋2=𝑎 and 𝑋1<𝑎)":

```
𝐸(𝑍)
    =(∑𝑎=1 to 6) 𝑎⋅𝑃(𝑍=𝑎)
    =(∑𝑎=1 to 6) 𝑎⋅(𝑃(𝑋1=𝑎 and 𝑋2≤𝑎)+𝑃(𝑋2=𝑎 and 𝑋1<𝑎))
    =(∑𝑎=1 to 6) 𝑎⋅(1/6⋅𝑎/6 + 1/6⋅(𝑎−1)/6)
    =161/36
```

Other way, draw a 2-d table with X1 and X2, and plot the cell values with Max(x1, x2)
then collect all cells with each probability of 1/36.
