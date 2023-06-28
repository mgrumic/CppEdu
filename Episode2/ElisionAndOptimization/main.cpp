#include <iostream>
#include <vector>

using namespace std;

class A
{
public:
	A() { cout << __PRETTY_FUNCTION__ << endl; }
	A(int i) { cout << __PRETTY_FUNCTION__ << endl; }
	A(const A&) { cout << __PRETTY_FUNCTION__ << endl; }
	A& operator=(const A&) { cout << __PRETTY_FUNCTION__ << endl; return *this; }

	~A() { cout << __PRETTY_FUNCTION__ << endl; }
};

A getA()
{
	return A();
}

int main()
{
	A a = getA();

	cout << "===================================" << endl;

	vector<A> vec;
	vec.push_back(A());

	return 0;
}
