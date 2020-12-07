#include "MTreeNode.h"

MTreeNode::MTreeNode(MTreeNode* parent)
{
	m_parent = parent;
	m_children = new MTreeNode*[2];
	if (parent != nullptr)
		m_distance = parent->m_distance + 1;
	else
		m_distance = 0;
}

int MTreeNode::get_i() const
{
	return m_i;
}

int MTreeNode::get_j() const
{
	return m_j;
}

const MTreeNode* MTreeNode::get_parent() const
{
	return m_parent;
}

MTreeNode* MTreeNode::get_child(int i) const
{
	return m_children[i];
}

bool MTreeNode::addChild(int i, int j)
{
	if (m_i < i) {
		m_children[0] = new MTreeNode(this);
		m_children[0]->m_i = i;
		m_children[0]->m_j = j;
	}
	else if (m_j < j) {
		m_children[1] = new MTreeNode(this);
		m_children[1]->m_i = i;
		m_children[1]->m_j = j;
	}
	return true;
}

MTreeNode* MTreeNode::hasChild(int i, int j)
{
	if (i > m_i)
		return m_children[0];
	else if (j > m_j)
		return m_children[1];

}

MTreeNode* MTreeNode::beginTree(int i, int j)
{
	MTreeNode* cur = m_parent;
	while (cur->m_parent !=nullptr)
		cur = cur->m_parent;
	return cur->m_parent;
}

int MTreeNode::get_distance() const
{
	return m_distance;
}

int MTreeNode::childCount() const
{
	int count = 0;
	if (m_children[0] != nullptr)
		count++;
	if (m_children[1] != nullptr)
		count++;
	return count;
}
