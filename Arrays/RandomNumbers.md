
https://www.geneseo.edu/~baldwin/reference/random.html

## Using Math.random()

`Math.random()` - **inclusive of 0.0 but exclusive of 1.0 (i.e. strictly less than 1.0)**. Returns a double value with a positive sign, greater than or equal to 0.0 and less than 1.0. Returned values are chosen pseudorandomly with (approximately) uniform distribution from that range.

```java
// get random numbers from 0 to 50 inclusive
int random = (int )(Math.random() * (50 + 1));
```

## Using Random class in java

An instance of this class is **used to generate a stream of pseudorandom numbers**.

`If two instances of Random are created with the same seed, and the same sequence of method calls is made for each, they will generate and return identical sequences of numbers`

```java
int max = 50;
int min = 1;

Random rand = new Random(); 
int value = rand.nextInt(50); 
```
This will give value from 0 to 49.

For `1 to 50`: `rand.nextInt((max - min) + 1) + min`;

