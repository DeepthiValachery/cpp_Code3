/*
		Full Name	:	Deepthi Valachery
		Student ID	:	[Redacted]
		Course code	:	COMP1602
		Course name	:	Computer Programming II
		Assignment	:	3
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int WIDTH = 15;
const int HEIGHT = 15;

//implement Coordinate struct

struct Coordinate{
	int x;	//height
	int y;	//width
};

//implement functions

void seedGrid (int grid[][WIDTH], Coordinate seed[], int seedSize){
	//accepts grid, seed array containing the coordinates of the initially live cells using Coordinate struct and array size
	//modify the grid to set the specified cells as live (1)
	for (int i=0; i<seedSize; i++) {
		for (int j=0; j<HEIGHT; j++) {
			for (int k=0; k<WIDTH; k++) {
				if (seed[i].x == j && seed[i].y == k) {
					grid[j][k] = 1;
				}
			}
		}
	}
}

int countLiveNeighbors(int grid[][WIDTH], int x, int y){
	//accepts grid and coordinates and then return the number of live neighbors
	int count = 0;
	if (y>0 && grid[x][y-1] == 1){	//checks top neighbor
		count++;
	}
	if (y<HEIGHT && grid[x][y+1] == 1){	//checks bottom neighbor
		count++;
	}	
	if (x>0 && grid[x-1][y] == 1){	//checks left neighbor
		count++;
	}
	if (x<WIDTH && grid[x+1][y] == 1){	//checks right neighbor
		count++;
	}	
    return count;
}

void updateGrid(int grid[][WIDTH], int newGrid[][WIDTH]){
	//accepts grid and new grid and then update the new grid based on the rules of the cellular automaton
	for (int i=0; i<HEIGHT; i++){
		for (int j=0; j<WIDTH; j++){
			int count = countLiveNeighbors(grid, i, j);
			if (grid[i][j] == 1){
				if (count<2 || count>3){
					newGrid[i][j] = 0;
				}else {
					newGrid[i][j] = 1;
				}
			}
			else if (grid[i][j] == 0){
				if (count == 3){
					newGrid[i][j] = 1;
				}
			}

		}
	}
}

void displayGrid(int grid[][WIDTH]){
	//accepts grid and then display it on the console using '*' for live cells and ' ' (space) for dead cells
	for(int i=0; i<HEIGHT; i++){
		for(int j=0; j<WIDTH; j++){
			if(grid[i][j] == 1){
				cout << "*";
			}
			else if (grid[i][j] == 0){
				cout << " ";
			}
		}
		cout << endl;
	}
}

void copyGrid(int src[][WIDTH], int dest[][WIDTH]){
	//accepts the given parameters and copy the contents of the source grid to the destination grid
	for(int i=0; i<HEIGHT; i++){
		for(int j=0; j<WIDTH; j++){
			dest[i][j] = src[i][j];
		}
	}
}

void invertRandomCells(int grid[][WIDTH], int numCells){
	//accepts grid and a number of cells to invert
	//It should randomly invert the specified number of cells.
	for (int i=0; i<numCells; i++){
		int rows = rand() % HEIGHT;
		int cols = rand() % WIDTH;
		if (grid[rows][cols] == 1){
			grid[rows][cols] = 0;
		}else{
			grid[rows][cols] = 1;
		}
	}
}

int main() {
    srand(time(0));

    int grid[HEIGHT][WIDTH] = {0};
    int newGrid[HEIGHT][WIDTH];
  
    // Uncomment when functions are implemented
    Coordinate seed[] = {{7, 7}, {7, 8}, {8, 7}, {8, 8}, {6, 6}, {6, 7}, {6, 8}, {9, 6}, {9, 7}, {9, 8}};

    seedGrid(grid, seed, 10);

    int iterations = 10;

    for (int i = 0; i < iterations; ++i) {
    	cout << "--------------------------------" << endl;
    	//system ("cls");
        displayGrid(grid);
        updateGrid(grid, newGrid);
        invertRandomCells(newGrid, 5); // Invert 5 random cells every generation
        copyGrid(newGrid, grid);
    }
    
    return 0;
}
