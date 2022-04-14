#include<iostream>
#include<stdio.h>

const int N = 4;
// N is the number of queens to place
// starting with 4
int grid[N][N];

int cnt = 0;

void printBoard()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N;j++) {
			std::cout<<grid[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	cnt++;
}

// since we are filling row by row only need to check above
bool isValid(int r, int c, int grid[N][N]){
	// std::cout << "isValid got r = " << r  << " c = " << c <<std::endl;
	// check rows above
	for(int i=0;i<r; i++){
		if(grid[i][c] == 1){
			return false;
		}
	}
	// check left diagonal above
	for(int i=r-1; i>=0; i--){// starting from row above all the way to 0th row
		int diff = r - i;
		if(r - diff >= 0 && r - diff < N) {
			if(c-diff >=0 && c-diff < N) {
				if(grid[r-diff][c-diff] == 1) {
					return false;
				}
			}
		}
	}

	// check other diagonal above
	for(int i=r-1; i>=0; i--){// starting from row above all the way to 0th row
		int diff = r - i;
		if(r - diff >= 0 && r - diff < N) {
			if(c+diff >=0 && c+diff < N) {
				if (grid[r-diff][c+diff] == 1) {
					return false;
				}
			}
		}
	}

	return true;
}

// r = current row to fill
void solve(int r, int grid[N][N]){
	if(r == N){// no more queens to place we have crossed number of rows (0-indexed)
		std::cout << "a solution: " << std::endl;
		printBoard();
		return;
	}
	
	for(int c=0;c<N;c++){ // for each possible column in this row
		if(isValid(r,c,grid) == false){
			// std::cout << "early return because were trying to place [r][c] in " << r << " " <<c << std::endl;
			// printBoard();
			// early return
			continue;
		}
		grid[r][c] = 1;// select step for valid candidates
		solve(r+1, grid);// recurse post selection
		grid[r][c] = 0;// un-select for other rounds
	}
}

int main(){
	int T;
	// scanf("%d",&T);
	
	// int rowStart, colStart;
	// for(int i = 0; i<T; i++){
	// 	scanf("%d", &rowStart);
	// 	scanf("%d", &colStart);
	// 	solve(0,grid);
	// }
	for(int i=0;i<N;i++) {
		for(int j = 0; j < N; j++) {
			grid[i][j] = 0;
		}
	}
	solve(0, grid);
	std::cout << "number of solutions :: " << cnt << std::endl;
	return 0;
}
