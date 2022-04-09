X = 2
Y = 3

def swapWithXOR(X, Y):
    X = X ^ Y
    Y = X ^ Y
    X = X ^ Y
    print(X)
    print(Y)

def swapWithAddSub(X, Y):
    X = X + Y
    Y = X - Y
    X = X - Y
    print(X)
    print(Y)

swapWithAddSub(2, 5)