#include <iostream>
#include <cstdlib>
#include "Grid.h"
#include <time.h>
using namespace std;

// build 1 x 1 grid with mover in only square, facing east
Grid::Grid() {
	cout << "Object is constructed" << endl;
	row = 1;
	col = 1;
	mover_row = 0;
	mover_col = 0;
	mover_dir = EAST;
	maze[mover_row][mover_col] = '>';
	path_maze[mover_row][mover_col] = '>';
	toggle = ON;
	wall = OFF;
}

// build grid with r rows, c cols, // blocks around edge with random exit and random mover position and direction
Grid::Grid(int r, int c) {
	cout << "Object is constructed" << endl;
	if(r < 3)	row = 3;
	else if(r > MAX_SIZE)	row = MAX_SIZE;
	else	row = r;

	if(c < 3)	col = 3;
	else if(c > MAX_SIZE)	col = MAX_SIZE;
	else	col = c;

	srand((unsigned)time(NULL));
	mover_row = rand() % (row-2) + 1;    // prevent mover on the block
	mover_col = rand() % (col-2) + 1;
	mover_dir = rand() % 4;

	toggle = ON;
	wall = ON;
	
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			if(i == 0 || i == row-1 || j == 0 || j == col-1) {
				maze[i][j] = '#';
				path_maze[i][j] = '#';
			}
			else {
				maze[i][j] = '.';
				path_maze[i][j] = '.';
			}
		}
	}

	if(mover_dir == NORTH) {
		maze[mover_row][mover_col] = '^';
		path_maze[mover_row][mover_col] = '^';
	}
	else if(mover_dir == WEST) {
		maze[mover_row][mover_col] = '<';
		path_maze[mover_row][mover_col] = '<';
	}
	else if(mover_dir == SOUTH) {
		maze[mover_row][mover_col] = 'v';
		path_maze[mover_row][mover_col] = 'v';
	}
	else if(mover_dir == EAST) {
		maze[mover_row][mover_col] = '>';
		path_maze[mover_row][mover_col] = '>';
	}

	exit_dir = rand() % 4;
	if(exit_dir == NORTH) {
		exit_row = 0;
		exit_col = rand() % (col-2) + 1;
	}
	else if(exit_dir == WEST) {
		exit_row = rand() % (row-2) + 1;
		exit_col = 0;
	}
	else if(exit_dir == SOUTH) {
		exit_row = row - 1;
		exit_col = rand() % (col-2) + 1;
	}
	else if(exit_dir == EAST) {
		exit_row = rand() % (row-2) + 1;
		exit_col = col - 1;
	}	
	maze[exit_row][exit_col] = '.';
	path_maze[exit_row][exit_col] = '.';
		
}

// build empty grid with r rows, c cols, and mover at row mr, col mc, and facing direction d
Grid::Grid(int r, int c, int mr, int mc, int d) {
	cout << "Object is constructed" << endl;
	if(r < 3)	row = 3;
	else if(r > MAX_SIZE)	row = MAX_SIZE;
	else	row = r;

	if(c < 3)	col = 3;
	else if(r > MAX_SIZE)	col = MAX_SIZE;
	else	col = c;

	if(mr <= 0)	mover_row = 1;
	else if(mr >= MAX_SIZE)    mover_row = MAX_SIZE - 1;
	else	mover_row = mr;

	if(mc <= 0)	mover_col = 1;
	else if(mc >= MAX_SIZE)    mover_col = MAX_SIZE - 1;
	else	mover_col = mc;


	mover_dir = d;
	toggle = ON;
	wall = ON;


        for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			if(i == 0 || i == row-1 || j == 0 || j == col-1) {
				maze[i][j] = '#';
				path_maze[i][j] = '#';
	                }
	                else {
	                        maze[i][j] = '.';
	                        path_maze[i][j] = '.';
	                }										                }
	}

	if(d == NORTH) {
		maze[mover_row][mover_col] = '^';
		path_maze[mover_row][mover_col] = '^';
	}
	else if(d == WEST) {
		maze[mover_row][mover_col] = '<';
		path_maze[mover_row][mover_col] = '<';
	}
	else if(d == SOUTH) {
		maze[mover_row][mover_col] = 'v';
		path_maze[mover_row][mover_col] = 'v';
	}
	else if(d == EAST) {
		maze[mover_row][mover_col] = '>';
		path_maze[mover_row][mover_col] = '>';
	}

	srand((unsigned)time(NULL));
	exit_dir = rand() % 4;
	if(exit_dir == NORTH) {
		exit_row = 0;
		exit_col = rand() % (col-2) + 1;
	}
	else if(exit_dir == WEST) {
		exit_row = rand() % (row-2) + 1;
		exit_col = 0;
	}
	else if(exit_dir == SOUTH) {
		exit_row = row - 1;
		exit_col = rand() % (col-2) + 1;
	}
	else if(exit_dir == EAST) {
		exit_row = rand() % (row-2) + 1;
		exit_col = col - 1;
	}	
	maze[exit_row][exit_col] = '.';
	path_maze[exit_row][exit_col] = '.';

}


Grid::~Grid() {
	cout << "Object is destructed" << endl;
}

// move forward s spaces, if possible
bool Grid::Move(int s) {
	if(s <= 0) {
		cout << "Invalid input (negative move)" << endl;
		return false;
	}

	int count = 0;
	int path_row[50] = {0};
	int path_col[50] = {0};

	int temp_row = mover_row;
	int temp_col = mover_col;
	for(int i = 0; i < s; i++) {
		if(mover_dir == NORTH)    temp_row--;
		else if(mover_dir == WEST)     temp_col--;
		else if(mover_dir == SOUTH)    temp_row++;
		else if(mover_dir == EAST)     temp_col++;

		if(temp_row < 0 || temp_col < 0 || temp_row >= MAX_SIZE || temp_col >= MAX_SIZE) {
			cout << "Invalid input (out of boundary)" << endl;
			return false;
		}
		else if(maze[temp_row][temp_col] == '#') {
			cout << "Invalid input (encounter block)" << endl;
			return false;
		}

		path_row[count] = temp_row;
		path_col[count] = temp_col;
		count++;
	}

	// path
	for(int i = 0; i < count - 1; i++) {
	        path_maze[path_row[i]][path_col[i]] = ' ';
	}

	// old position
	if(maze[mover_row][mover_col] == '@') {
		maze[mover_row][mover_col] = '0';
		path_maze[mover_row][mover_col] = '0';
	}
	else {
		maze[mover_row][mover_col] = '.';
		path_maze[mover_row][mover_col] = ' ';
	}

	// new position
	if(maze[temp_row][temp_col] == '0') {
		maze[temp_row][temp_col] = '@';
		path_maze[temp_row][temp_col] = '@';
	}
	else if(maze[temp_row][temp_col] == '.') {
		if(mover_dir == NORTH) {
			maze[temp_row][temp_col] = '^';
			path_maze[temp_row][temp_col] = '^';
		}
		else if(mover_dir == WEST) {
			maze[temp_row][temp_col] = '<';
			path_maze[temp_row][temp_col] = '<';
		}
		else if(mover_dir == SOUTH) {
			maze[temp_row][temp_col] = 'v';
			path_maze[temp_row][temp_col] = 'v';
		}
		else if(mover_dir == EAST) {
			maze[temp_row][temp_col] = '>';
			path_maze[temp_row][temp_col] = '>';
		}
	}

	// store new position
	mover_row = temp_row;
	mover_col = temp_col;

	return true;
}

// toggle whether or not moved path is shown
void Grid::TogglePath() {
	if(toggle == ON)
		toggle = OFF;
	else if(toggle == OFF)
		toggle = ON;
}

// turn the mover to the left
void Grid::TurnLeft() {
	mover_dir++;
	mover_dir %= 4;

	if(maze[mover_row][mover_col] == '@')
		return;

	if(mover_dir == NORTH) {
		maze[mover_row][mover_col] = '^';
		path_maze[mover_row][mover_col] = '^';
	}
	else if(mover_dir == WEST) {
		maze[mover_row][mover_col] = '<';
		path_maze[mover_row][mover_col] = '<';
	}
	else if(mover_dir == SOUTH) {
		maze[mover_row][mover_col] = 'v';
		path_maze[mover_row][mover_col] = 'v';
	}
	else if(mover_dir == EAST) {
		maze[mover_row][mover_col] = '>';
		path_maze[mover_row][mover_col] = '>';
	}
}

// put down an item at the mover's position
void Grid::PutDown() {
	maze[mover_row][mover_col] = '@';
	path_maze[mover_row][mover_col] = '@';
}

// put down an item at (r, c), if possible
bool Grid::PutDown(int r, int c) {
	if(r >= MAX_SIZE || c >= MAX_SIZE)	return false;

	if(mover_row == r && mover_col == c) {   // place on the mover location
		maze[r][c] = '@';
		path_maze[r][c] = '@';
		return true;
	}
	else if(maze[r][c] == '.') {
		maze[r][c] = '0';
		path_maze[r][c] = '0';
		return true;
	}

	return false;
}

// pick up item at current position
bool Grid::PickUp() {
	if(maze[mover_row][mover_col] == '@') {
        	if(mover_dir == NORTH) {
			maze[mover_row][mover_col] = '^';
                        path_maze[mover_row][mover_col] = '^';
                }
                else if(mover_dir == WEST) {
                        maze[mover_row][mover_col] = '<';
                        path_maze[mover_row][mover_col] = '<';
		}
	 	else if(mover_dir == SOUTH) {
		        maze[mover_row][mover_col] = 'v';
		        path_maze[mover_row][mover_col] = 'v';
		}
		else if(mover_dir == EAST) {
		        maze[mover_row][mover_col] = '>';
		        path_maze[mover_row][mover_col] = '>';
		}

		return true;
	}

	return false;
}

// put a block at (r, c), if possible
bool Grid::PlaceBlock(int r, int c) {
	if(r >= MAX_SIZE || c >= MAX_SIZE)	return false;
	if(r == exit_row && c == exit_row)	return false;

	if(maze[r][c] == '.' && r < row && c < col) {
		maze[r][c] = '#';
		path_maze[r][c] = '#';
		return true;
	}

	return false;
}

// grow the grid by gr rows, gc columns
void Grid::Grow(int gr, int gc) {
	if(gr < 0 || gc < 0) {
		cout << "Invalid input (negative grow)" << endl;	
		return;
	}
	int old_row = row;
	int old_col = col;

	row += gr;
	col += gc;
	
	if(row >= MAX_SIZE) {
		cout << "Invalid input (row out of boundary)" << endl;
		row = MAX_SIZE;
	}
	if(col >= MAX_SIZE) {
		cout << "Invalid input (column out of boundary)" << endl;
		col = MAX_SIZE;
	}

	for(int i = old_row; i < row; i++) {
		for(int j = old_col; j < col; j++) {
			maze[i][j] = '.';
			path_maze[i][j] = '.';
		}
	}

	for(int i = 0; i < old_row; i++) {
		for(int j = old_col; j < col; j++) {
			maze[i][j] = '.';
			path_maze[i][j] = '.';
		}
	}

	for(int i = old_row; i < row; i++) {
		for(int j = 0; j < old_col; j++) {
			maze[i][j] = '.';
			path_maze[i][j] = '.';
		}
	}

	for(int i = old_row-1; i < row; i++) {
		maze[i][0] = '#';
		path_maze[i][0] = '#';
	}
	for(int j = old_col-1; j < col; j++) {
		maze[0][j] = '#';
		path_maze[0][j] = '#';
	}

	for(int i = 1; i < old_row; i++) {
		maze[i][old_col-1] = '.';
		path_maze[i][old_col-1] = '.';
	}
	for(int j = 1; j < old_col; j++) {
		maze[old_row-1][j] = '.';
		path_maze[old_row-1][j] = '.';
	}
		
	for(int i = 0; i < row; i++) {
		maze[i][col-1] = '#';
		path_maze[i][col-1] = '#';
	}
	for(int j = 0; j < col; j++) {
		maze[row-1][j] = '#';
		path_maze[row-1][j] = '#';
	}

	srand((unsigned)time(NULL));

	if(wall == ON) {     // Constructors which have argument		
		if(exit_dir == EAST) {
			exit_col = col - 1;
			maze[exit_row][exit_col] = '.';
			path_maze[exit_row][exit_col] = '.';
		}
		else if(exit_dir == SOUTH) {
			exit_row = row - 1;
			maze[exit_row][exit_col] = '.';
			path_maze[exit_row][exit_col] = '.';
		}
	}
	else if(wall == OFF) {         // Constructor without argument
		maze[mover_row][mover_col] = '#';
		path_maze[mover_row][mover_col] = '#';

		// Set the mover to (1, 1)
		mover_row = 1;
		mover_col = 1;
		maze[mover_row][mover_col] = '>';
		path_maze[mover_row][mover_col] = '>';

		exit_dir = rand() % 4;
		if(exit_dir == NORTH) {
			exit_row = 0;
			exit_col = rand() % (col-2) + 1;
		}
		else if(exit_dir == WEST) {
			exit_row = rand() % (row-2) + 1;
			exit_col = 0;
		}
		else if(exit_dir == SOUTH) {
			exit_row = row - 1;
			exit_col = rand() % (col-2) + 1;
		}
		else if(exit_dir == EAST) {
			exit_row = rand() % (row-2) + 1;
			exit_col = col - 1;
		}
		maze[exit_row][exit_col] = '.';
		path_maze[exit_row][exit_col] = '.';	

		wall = ON;
	}
}

// display the grid on screen
void Grid::Display() const {
	cout << "The Grid:" << endl;

	if(toggle == ON) {
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				if(j == 0)	cout << path_maze[i][j];
				else	cout << " " << path_maze[i][j];
			}
			cout << endl;
		}
	}
	else if(toggle == OFF) {
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				if(j == 0)	cout << maze[i][j];
				else	cout << " " << maze[i][j];
			}
			cout << endl;
		}
	}
	cout << endl;
}

// Accessors
// check to see if space in front of mover is clear
bool Grid::FrontIsClear() const {
	int front_row, front_col;

	if(mover_dir == NORTH) {
		front_row = mover_row - 1;
		front_col = mover_col;
 	}
	else if(mover_dir == WEST) {
		front_row = mover_row;
 		front_col = mover_col - 1;
	}
	else if(mover_dir == SOUTH) {
		front_row = mover_row + 1;
		front_col = mover_col;
	}
	else if(mover_dir == EAST) {
		front_row = mover_row;
		front_col = mover_col + 1;
	}

	if(front_row < 0 || front_col < 0 || front_row >= MAX_SIZE || front_col >= MAX_SIZE)
		return false;
	else if(maze[front_row][front_col] == '#')
		return false;
	else
		return true;
}

// check to see if space to right of mover is clear
bool Grid::RightIsClear() const {
	int right_row, right_col;
        if(mover_dir == NORTH) {
		right_row = mover_row;
		right_col = mover_col + 1;
	}
        else if(mover_dir == WEST) {
                right_row = mover_row - 1;
                right_col = mover_col;
        }
        else if(mover_dir == SOUTH) {
                right_row = mover_row;
                right_col = mover_col - 1;
        }
        else if(mover_dir == EAST) {
                right_row = mover_row + 1;
                right_col = mover_col;
        }

	if(right_row < 0 || right_col < 0 || right_row >= MAX_SIZE || right_col >= MAX_SIZE)
                return false;
        else if(maze[right_row][right_col] == '#')
                return false;
        else
                return true;

}

// return row of the mover
int Grid::GetRow() const { return mover_row; }

// return column of the mover
int Grid::GetCol() const { return mover_col; }

// return number of rows in the grid
int Grid::GetNumRows() const { return row; }

// return number of columns in the grid
int Grid::GetNumCols() const { return col; }




