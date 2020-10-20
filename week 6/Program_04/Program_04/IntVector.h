
#include<iostream>

using namespace std;

class IntVector
{
 private:
	 unsigned sz;
	 unsigned cap;
	 int* data;
 public:
	IntVector();
	IntVector(unsigned size, int value = 0);
	~IntVector();
	unsigned size() const;
	unsigned capacity() const;
	bool empty() const;
	const int& at(unsigned) const;
	int& at(unsigned);
	void insert(unsigned, int);
	void erase(unsigned);
	const int& front() const;
	int& front();
	const int& back() const;
	int& back();
	void assign(unsigned, int);
	void push_back(int);
	void pop_back();
	void clear();
	void resize(unsigned size, int value = 0);
	void reserve(unsigned);
	//testing harness
	void print();
private:
	void expand();
	void expand(unsigned);
};
