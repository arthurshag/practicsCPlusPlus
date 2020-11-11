#pragma once

class SLList
{
private:
	int m_data;
public:
	SLList* m_nextElem;
	int getData() const;
	void setData(int data);
	SLList* next() const;
	bool hasNext() const;
	static SLList* beginList(int data);
	SLList* addElement(int data);
	void removeNext();
	SLList* FindByIndex(int index);
};
