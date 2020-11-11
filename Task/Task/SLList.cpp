#include "SLList.h"


#include <iostream>
#include <list>

int SLList::getData() const
{
	return m_data;
}

void SLList::setData(int data) 
{
	m_data = data;
}

SLList* SLList::next() const
{
	return m_nextElem;
}

bool SLList::hasNext() const
{
	return m_nextElem != nullptr;
}

SLList* SLList::beginList(int data)
{
	SLList* next = new SLList();
	next->setData(data);
	return next;
}

SLList* SLList::addElement(int data)
{
	SLList* next = new SLList();
	next->setData(data);
	m_nextElem = next;
	return m_nextElem;
}

void SLList::removeNext()
{
	if (m_nextElem == nullptr)
		return;
	else
		m_nextElem->removeNext();
	delete m_nextElem;
	m_nextElem = nullptr;
}

SLList* SLList::FindByIndex(int index)
{
	SLList* curr = this;
	int count = 1;
	while (curr->hasNext())
	{
		count += 1;
		curr = curr->next();
	}

	if (index > count)
		return nullptr;
	index = count - index;
	curr = this;
	for (int i = 0; i < index; i++)
		curr = curr->next();
	return curr;
}
