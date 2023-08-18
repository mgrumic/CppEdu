#include <iostream>
using namespace std;

class Parent
{
	public:
		virtual void speak()
		{
			cout << "Parent!" << endl;
		}
};

class Brother : public Parent
{
};

class Sister : public Parent
{
};

int main()
{
	// Static cast
	cout << "Static cast" << endl;
	{
		Parent p;
		Brother b;

		// Brother* pb = &p;
		// cout << pb << endl;
		
		Parent* pp = &b;
		cout << pp << endl;

		// Brother* pbb = pp;
		// cout << pbb << endl;

		Brother* pbb2 = static_cast<Brother*>(pp);
		cout << pbb2 << endl;

		Parent&& pr = static_cast<Parent&&>(p);
		p.speak();
		pr.speak();

	}

	// Dynamic cast
	cout << "Dynamic cast" << endl;
	{
		Parent parent;
		Brother brother;

		Parent* ppb = &brother;
		Brother* pbb = dynamic_cast<Brother*>(ppb);

		if (pbb != nullptr)
		{
			cout << pbb << endl;
		}
		else
		{
			cout << "Invalid pointer!" << endl;
		}
	}

	// Reinterpret cast
	cout << "Reinterpret cast" << endl;
	{
		Parent parent;
		Brother brother;
		Sister sister;

		Parent* ppb = &brother;
		// Sister* pbb = dynamic_cast<Sister*>(ppb);
		// Sister* pbb = static_cast<Sister*>(ppb);
		Sister* pbb = reinterpret_cast<Sister*>(ppb);

		if (pbb != nullptr)
		{
			cout << pbb << endl;
		}
		else
		{
			cout << "Invalid pointer!" << endl;
		}
	}
	
}
