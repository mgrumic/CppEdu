#include <iostream>

class A
{
public:
	A() : A("DEFAULT") { std::cout << __PRETTY_FUNCTION__ << std::endl; }
	A(const char* str) { std::cout << __PRETTY_FUNCTION__ << ": " << str << std::endl; }
};

int main()
{
	std::cout << "Delegating Constructor" << std::endl;
	A a1;
	A a2("NON DEFAULT");
	return 0;
}
