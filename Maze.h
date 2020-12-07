#pragma once
#include "MCell.h"

class Maze
{
private:
	int n = 0;
	int m = 0;
	MCell* maze;
public:
	Maze(int n, int m);
	const MCell cell(int i, int j) const;
	bool hasConnection(int i1, int j1, int i2, int j2);
	bool makeConnection(int i1, int j1, int i2, int j2);
	void removeConnection(int i1, int j1, int i2, int j2);
	void printMaze();
	int get_length();
	int get_width();
};

