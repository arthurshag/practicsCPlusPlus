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