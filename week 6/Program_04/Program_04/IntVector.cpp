#include<iostream>
#include <stdexcept>

using namespace std;
#include "IntVector.h"

IntVector::IntVector()
{
	sz = 0;
	cap = 0;
	data = nullptr;
}

IntVector::IntVector(unsigned size, int value)
{
	sz = size;
	cap = size;
	data = new int[size];

	for (unsigned int i = 0; i < sz; i++)
	{
		data[i] = value;
	}
}

IntVector::~IntVector()
{
	delete[] data;
}

void IntVector::expand()
{
	if (cap == 0)
	{
		cap = 1;
	}
	else
	{
		cap = cap * 2;
	}
	int* temp = new int[cap];

	for (unsigned int i = 0; i < sz; i++)
	{
		temp[i] = data[i];
	}
	data = temp;
}

void IntVector::expand(unsigned amount)
{
	cap = cap + amount;
	int* temp = new int[cap];

	for (unsigned int i = 0; i < sz; i++)
	{
		temp[i] = data[i];
	}
	data = temp;
}

unsigned IntVector::size() const
{
	return sz;
}

unsigned IntVector::capacity() const
{
	return cap;
}

bool IntVector::empty() const
{
	if (sz == 0)
	{
		return true;
	}
	return false;
}

const int& IntVector::at(unsigned index) const
{
	if (index >= sz)
	{
		throw out_of_range("IntVector::at_range_check");
	}
	else
	{
		return data[index];
	}
}


int& IntVector::at(unsigned index)
{
	if (index >= sz)
	{
		throw out_of_range("IntVector::at_range_check");
	}
	else
	{
		return data[index];
	}
}

void IntVector::insert(unsigned index, int value)
{
	if (cap == 0)
	{
		expand(1);
	}
	else if(cap == sz)
	{
		expand();
	}
	sz = sz + 1;
	if (index >= sz)
	{
		throw out_of_range("IntVector::insert_range_check");
	}
	else
	{
		for (unsigned int i = sz-1; i > index; i--)
		{
			data[i] = data[i-1];
		}
		data[index] = value;
	}

}

void IntVector::erase(unsigned index)
{
	if (index >= sz)
	{
		throw out_of_range("IntVector::erase_range_check");
	}
	else 
	{
		for (unsigned int i = index; i < sz-1; i++)
		{
			data[i] = data[i + 1];
		}
		sz = sz - 1;
	}
}

const int& IntVector::front() const
{
	return data[0];
}

int& IntVector::front()
{
	return data[0];
}

const int& IntVector::back() const
{
	return data[sz-1];
}

int& IntVector::back()
{
	return data[sz - 1];
}

void IntVector::assign(unsigned n, int value)
{
	unsigned int increaseCap;
	increaseCap = cap * 2;
	if(n > cap)
	{
		if (cap == 0)
		{
			expand(n - cap);
		}
		else if (increaseCap > n)
		{	
			expand();
		}
		else
		{
			expand(n-cap);
		}
	}

	sz = n;
	for (unsigned int i = 0; i < sz; i++)
	{
		data[i] = value;
	}

}

void IntVector::push_back(int value)
{
	if (sz == cap)
	{
		expand();
	}
	sz = sz + 1;
	data[sz - 1] = value;
}

void IntVector::pop_back()
{
	sz = sz - 1;
}

void IntVector::clear()
{
	sz = 0;
}

void IntVector::resize(unsigned size, int value)
{
	unsigned int increaseCap;
	increaseCap = cap * 2;
	if (size < sz)
	{
		sz = size;
	}
	if (size > sz)
	{
		if (size > cap)
		{
			if (cap == 0)
			{
				expand(size - cap);
			}
			else if (increaseCap > size)
			{
				expand();
			}
			else
			{
				expand(size - cap);
			}
		}
		for (unsigned int i = sz; i < size; i++)
		{
			data[i] = value;
		}
		sz = size;
	}
	
}

void IntVector::reserve(unsigned n)
{
	if (n > cap)
	{
		expand(n-cap);
	}
}


//testing harness
void IntVector::print()
{
	cout << sz << " " << cap << endl;
	for (unsigned int i = 0; i < sz; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}
