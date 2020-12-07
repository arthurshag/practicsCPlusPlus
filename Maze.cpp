#include "Maze.h"
#include <algorithm>
#include <iostream>

Maze::Maze(int n, int m)
{
	this->maze = new MCell[n * m];
	this->n = n;
	this->m = m;
}

const MCell Maze::cell(int i, int j) const
{
	return maze[i + m * j];
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2)
{
	if (i2 > i1)
		maze[i1 + j1 * m].m_right = true;
	else if (i1 > i2)
		maze[i2 + j2 * m].m_right = true;
	else if (j1 > j2)
		maze[i2 + j2 * m].m_down = true;
	else if (j2 > j1)
		maze[i1 + j1 * m].m_down = true;
	return true;
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2)
{
	if (i2 > i1)
		return maze[i1 + j1 * m].get_right();
	else if (i1 > i2)
		return maze[i2 + j2 * m].get_right();
	else if (j1 > j2)
		return maze[i2 + j2 * m].get_down();
	else if (j2 > j1)
		return maze[i1 + j1 * m].get_down();
	return false;
}

void Maze::removeConnection(int i1, int j1, int i2, int j2)
{
	if (i2 > i1)
		maze[i1 + j1 * m].m_right = false;
	else if (i1 > i2)
		maze[i2 + j2 * m].m_right = false;
	else if (j1 > j2)
		maze[i2 + j2 * m].m_down = false;
	else if (j2 > j1)
		maze[i1 + j1 * m].m_down = false;
}

void Maze::printMaze()
{
	int x = 0;
	for (int i = 0; i < n * m; i++)
	{
		if ( i < n)
		{
			if (maze[i].get_down() && maze[i].get_right())
				std::cout << char(218) << " ";
			else if (maze[i].get_down() && maze[i - 1].get_right())
				std::cout << char(191) << " ";
			else if (maze[i].get_right() && maze[i - 1].get_right())
				std::cout << char(196) << " ";
			else if (maze[i].get_down() && maze[i - m].get_down())
				std::cout << char(179) << " ";
			else if (maze[i].get_right() && maze[i - m].get_down())
				std::cout << char(192) << " ";
			else
				std::cout << "0 ";
		}
		else if (i == (n*m - n -1))
			std::cout << char(191) << " ";
		else if (maze[i].get_down() && maze[i].get_right() && maze[i - 1].get_right() && maze[i-m].get_down()) 
			std::cout << char(167) << " ";
		else if (maze[i].get_down() && maze[i].get_right() && maze[i - 1].get_right())
			std::cout << char(194) << " ";
		else if (maze[i].get_down() && maze[i].get_right() && maze[i - m].get_down())
			std::cout << char(195) << " ";
		else if (maze[i].get_down() && maze[i - 1].get_right() && maze[i - m].get_down())
			std::cout << char(180) << " ";
		else if (maze[i].get_right() && maze[i - 1].get_right() && maze[i - m].get_down())
			std::cout << char(193) << " ";
		else if (maze[i].get_down() && maze[i].get_right()) 
			std::cout << char(218) << " ";
		else if (maze[i].get_down() && maze[i - 1].get_right())
			std::cout << char(191) << " ";
		else if (maze[i].get_right() && maze[i - 1].get_right())
			std::cout << char(196) << " ";
		else if (maze[i].get_down() && maze[i - m].get_down())
			std::cout << char(179) << " ";
		else if (maze[i].get_right() && maze[i - m].get_down())
			std::cout << char(192) << " ";
		else if (maze[i - 1].get_right() && maze[i - m].get_down())
			std::cout << char(217) << " ";
		else
			std::cout << "0 ";
		if (i != 0 and (i + 1) % n == 0)
			std::cout << "\n";
	}

	std::cout << "\n";

	
}

int Maze::get_length()
{
	return n;
}

int Maze::get_width()
{
	return m;
}