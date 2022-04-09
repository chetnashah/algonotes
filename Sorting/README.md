

### Swapping variables using XOR

Do xor betwe `X` and `Y` three times
in the order of `X,Y,X`
```py
X = 2
Y = 3
X = X ^ Y
Y = X ^ Y
X = X ^ Y
print(X)
print(Y)
```

### Swapping variables with addition and substraction
one addition and two substraction between X and Y
in the order of `X, Y, X`
```py
def swapWithAddSub(X, Y):
    X = X + Y
    Y = X - Y
    X = X - Y
    print(X)
    print(Y)
```