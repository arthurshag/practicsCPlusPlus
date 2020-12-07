#include <iostream>
#include "Maze.h"
#include "MTreeNode.h"

void Recurse(Maze* maze, int x, int y, MTreeNode* curr_tree_node)
{
	if (maze->hasConnection(x,y,x+1,y))
	{
		curr_tree_node->addChild(x + 1, y);
		Recurse(maze, x + 1, y, curr_tree_node->get_child(0));
	}
	if (maze->hasConnection(x, y, x, y + 1))
	{
		curr_tree_node->addChild(x, y + 1);
		Recurse(maze, x, y + 1, curr_tree_node->get_child(1));
	}
}


int main()
{
	Maze* maze = new Maze(5, 5);
	int y = 0;
	for (int i = 0; i < maze->get_width(); i++)
	{
		for (int j = y; j < maze->get_length() - 1; j++)
			maze->makeConnection(j, y, j+1, y);
		y++;
	}

	int x = 0;
	for (int j = 0; j < maze->get_length(); j++)
	{
		if (j == 1 && j == 0)
		{
			for (int i = 0; i < maze->get_width() - 1; i++)
				maze->makeConnection(x, i, x, i + 1);
			x++;
			continue;
		}
		for (int i = x - 1; i < maze->get_width() - 1; i++)
			maze->makeConnection(x, i, x, i + 1);
		x++;
	}
	maze->printMaze();
	MTreeNode* tree = new MTreeNode(nullptr);
	MTreeNode* curr;
	Recurse(maze, 0, 0, tree);
	x = 0;
	for (int i = 0; i < maze->get_width(); i++) {
		curr = tree;
		y = x;
		for (int z = x; z < y + x + 1;z++) {
			std::cout << z << " ";
		}
		if(i != maze->get_width() - 1)
			tree = curr->get_child(0)->get_child(1);
		for (int j = x+1; j < maze->get_width(); j++) {
			curr = curr->get_child(0);
			std::cout << curr->get_distance() << " ";
		}
		x++;
		std::cout << "\n";
		
	}
}