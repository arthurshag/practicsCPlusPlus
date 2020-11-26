#include <iostream>
#include "Maze.h"


int main()
{
	Maze* maze = new Maze(15, 15);
	int step = 1;
	int x = maze->get_length() - 1;
	int y = maze->get_width();
	y = 0;
	x = 1;
	while (true)
	{
		int i = y;
		for (; i < y + step; i++)
			maze->makeConnection(x, i, x, i + 1);
		if (y == maze->get_width())
			break;
		y = i;
		i = x;
		for (; i < x + step; i++)
			maze->makeConnection(i, y, i + 1, y);
		x = i;
		if (x == maze->get_length())
			break;
	}

	maze->printMaze();
}