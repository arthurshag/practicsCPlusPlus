// Task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "SLList.h"

SLList* createSLList()
{
	SLList* list = new SLList();
	list->setData(rand() % 6);
	SLList* second = list->addElement(rand() % 6);
	for (int i = 0; i < 8; i++)
		second = second->addElement(rand() % 6);
	return list;
}

void removeD(SLList* list, int curr)
{
	SLList* next = list;
	while (next->hasNext())
	{
		next = next->next();
		if (next->getData() == curr)
		{
			if (next->hasNext()) {
				list->m_nextElem = next->next();
				delete next;
				next = list;
				continue;
			}

			delete next;
		}

		list = next;
	}
}

void removeDuplicates(SLList* list)
{
	SLList* next = list;
	while (next->hasNext())
	{
		int curr = next->getData();
		removeD(next, curr);
		next = next->next();
	}
}

void printSLList(const SLList* list)
{
	std::cout << list->getData() << " ";
	while (list->hasNext())
	{
		list = list->next();
		std::cout << list->getData() << " ";
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SLList* list = createSLList();
	printSLList(list);
	std::cout << "\n";
	std::cout << "3 элемент с конца (отсчёт ведётся с единицы) " << list->FindByIndex(3)->getData();
	std::cout << "\n";
	std::cout << "Удаляю дубликаты";
	removeDuplicates(list);
	std::cout << "\n";
	printSLList(list);
	std::cout << "\n";
	std::cout << "3 элемент с конца (отсчёт ведётся с единицы) " << list->FindByIndex(3)->getData();
}
