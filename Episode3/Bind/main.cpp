#include <iostream>
#include <functional>

using namespace std;

class Test
{
public:
	Test(char* foo) : str(foo) {}
	int add(int a, int b, int c)
	{
		cout << str << endl;
		cout << a << ", " << b << ", " << c << endl;
		return a + b + c;
	}

private:
	std::string str;
};

void run(std::function<int(int, int)> f)
{
	cout << "run " << f(7, 3) << endl;
}

int main()
{
	Test test("KURCINA");
	auto calculator = std::bind(&Test::add, test, placeholders::_2, placeholders::_1, 5);

	cout << calculator(10, 11) << endl;
	run(calculator);
	return 0;
}
