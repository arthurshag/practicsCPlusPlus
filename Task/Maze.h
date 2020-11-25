#pragma once

class MCell
{
private:
	bool m_down = false;
	bool m_right = false;
public:
	bool get_right() const;
	bool get_down() const;
	friend class Maze;
};

class Maze
{
private:
	int n = 0;
	int m = 0;
	MCell* maze;
	void moveTo(int w);
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

