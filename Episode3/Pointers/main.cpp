#include <iostream>
#include <memory>

using namespace std;

class Test
{
public:
	Test() {
		cout << "created" << endl;
	}

	void greet() {
		cout << "Hello" << endl;
	}

	~Test() {
		cout << "destroyed" << endl;
	}
};

class Temp
{
	public:
		Temp() : pTest(new Test[3]) {}
	private:
		unique_ptr<Test[]> pTest;
};


int main()
{
#if 0
	{
		unique_ptr<Test[]> pTest(new Test[3]);

		pTest[1].greet();
	}
	Temp t;
#else
	// shared_ptr<Test> pTest1(new Test);
	shared_ptr<Test> pTest2(nullptr);
	
	{
		shared_ptr<Test> pTest1 = make_shared<Test>();
		
		pTest2 = pTest1;
	}

#endif

        cout << "Finished" << endl;
	return 0;
}
