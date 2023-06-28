#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

class A
{
private:
	static const int SIZE = 101;
	int* m_pBuffer{nullptr};
public:
	A()
	{ 
		cout << __PRETTY_FUNCTION__ << endl;
		m_pBuffer = new int[SIZE]{};
		// memset(m_pBuffer, 0x00, SIZE * sizeof(int));
	}
	A(int i)
	{
		cout << __PRETTY_FUNCTION__ << endl;
		m_pBuffer = new int[SIZE]{};

		for(int i = 0; i < SIZE; i++)
		{
			m_pBuffer[i] = i;
		}
	}
	
	A(const A& orig)
	{
		cout << __PRETTY_FUNCTION__ << endl;
		m_pBuffer = new int[SIZE]{};
		memcpy(m_pBuffer, orig.m_pBuffer, SIZE * sizeof(int));
	}

	A& operator=(const A& orig)
	{
		cout << __PRETTY_FUNCTION__ << endl;
		if(m_pBuffer != nullptr)
		{
			delete [] m_pBuffer;
			m_pBuffer = nullptr;
		}

		m_pBuffer = new int[SIZE]{};
		memcpy(m_pBuffer, orig.m_pBuffer, SIZE * sizeof(int));
		return *this;
	}

	~A()
	{
		cout << __PRETTY_FUNCTION__ << endl;
		delete [] m_pBuffer;
	}
};

A getA()
{
	return A();
}

int main()
{
	A a = getA();
	A b = a;
	b = a;
	b = a;
	cout << "===================================" << endl;

	vector<A> vec;
	vec.push_back(A());
	
        cout << "===================================" << endl; 
 
        int val = 7; 
 
        int* pval1 = &val; 
        int* pval2 = &++val; 
 
        cout << *pval1 << " " << *pval2 << endl; 


	return 0;
}
