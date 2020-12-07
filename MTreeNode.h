#pragma once

class MTreeNode
{
private:
	int m_i;
	int m_j;
	MTreeNode* m_parent;
	MTreeNode** m_children;
	int m_distance;
public:
	MTreeNode(MTreeNode* parent);
	int get_i() const;
	int get_j() const;
	const MTreeNode* get_parent() const;
	MTreeNode* get_child(int i) const;
	int get_distance() const;
	int childCount() const;
	bool addChild(int i, int j);
	MTreeNode* hasChild(int i, int j);
	MTreeNode* beginTree(int i, int j);
	friend class Maze;
};

