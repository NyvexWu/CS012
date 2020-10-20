#include <iostream>
using namespace std;

#include "IntList.h"

IntList::IntList()
{
	head = nullptr;
	tail = nullptr;
}
IntList::~IntList()
{
	while (head != nullptr)
	{
		IntNode* temp = head;
		head = head->next;
		delete temp;
	}
	head = nullptr;
}
void IntList::push_front(int value)
{
	IntNode *temp = new IntNode(value);
	temp->next = head;
	head = temp;
	if (tail == nullptr)
	{
		tail = head;
	}
}
void IntList::pop_front()
{
	if (head != nullptr)
	{
		IntNode* temp = head;
		head = head->next;
		delete temp;	
	}
	if (head == nullptr)
	{
		tail = nullptr;
	}
}
bool IntList::empty() const
{
	if (head == nullptr && tail == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
const int& IntList::front() const
{
	return head->data;
}
const int& IntList::back() const
{
	/*for (IntNode* currNode = head; currNode != nullptr; currNode = currNode->next)
	{
		tail->data = currNode->data;
	}*/
	return tail->data;	
}
ostream& operator<<(ostream& out, const IntList& list)
{
	if (list.empty() != true)
	{
		IntNode* currNode = list.head;
		out << currNode->data;
		for (currNode = currNode->next; currNode != nullptr; currNode = currNode->next)
		{
			out << " " << currNode->data;
		}
		
	}
	return out;
}