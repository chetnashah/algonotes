
#include <algorithm>
#include <iostream>

void permuteStuff() {
    
    int i, n = 8, p[8] = { 0,1,2,3,4,5,6,7};
    do {
        for(int i=0;i<8; i++) {
            std::cout << p[i] << " ";
        }
        std::cout << std::endl;
    } while (std::next_permutation(p, p+n));
}

int main() {
    permuteStuff();    
    return 0;
}