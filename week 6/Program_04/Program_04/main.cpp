#include <iostream>

using namespace std;
#include "IntVector.h"

int main()
{
    //checking constructors
    IntVector test1;
    IntVector test2(3, 5);
    test1.print();
    test2.print();

    //checking size and capacity accessor
    cout << "Checking size and capacity for test1: " << endl;
    cout << "size: " << test1.size() << endl;
    cout << "capacity: " << test1.capacity() << endl;
    cout << "Checking size and capacity for test2: " << endl;
    cout << "size: " << test2.size() << endl;
    cout << "capacity: " << test2.capacity() << endl;

    //checking empty accessor
    if (test1.empty() == true)
    {
        cout << "its empty" << endl;
    }
    if (test1.empty() == false)
    {
        cout << "its not empty" << endl;
    }
    if (test2.empty() == true)
    {
        cout << "its empty" << endl;
    }
    if (test2.empty() == false)
    {
        cout << "its not empty" << endl;
    }

    //checking front accessor
    cout << endl;
    cout << "testing front()" << endl;
    cout << test2.front() << endl;


    //checking back accessor
    cout << endl;
    cout << "testing back()" << endl;
    cout << test2.back() << endl;

    //checking at accessor
    //cout << endl;
    //cout << test2.at(3) << endl;
    //
    //checking at mutator
    //cout << endl;
    //cout << "testing at()" << endl;
    //cout << test2.at(3) << endl;

    //checking push_back
    cout << "testing push_back" << endl;
    test2.push_back(1);
    test2.print();
    //checking insert
    //checking erase
    //checking resize
    //checking reserve
    //checking assign
    return 0;
}
