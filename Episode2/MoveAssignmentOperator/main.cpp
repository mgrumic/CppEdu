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
		m_pBuffer = new int[SIZE]{};
		// memset(m_pBuffer, 0x00, SIZE * sizeof(int));
	}
	A(int i)
	{
		m_pBuffer = new int[SIZE]{};

		for(int i = 0; i < SIZE; i++)
		{
			m_pBuffer[i] = i;
		}
	}
	
	A(const A& orig)
	{
		m_pBuffer = new int[SIZE]{};
		memcpy(m_pBuffer, orig.m_pBuffer, SIZE * sizeof(int));
	}

	A& operator=(const A& orig)
	{
		if(m_pBuffer != nullptr)
		{
			delete [] m_pBuffer;
			m_pBuffer = nullptr;
		}

		m_pBuffer = new int[SIZE]{};
		memcpy(m_pBuffer, orig.m_pBuffer, SIZE * sizeof(int));
		return *this;
	}
	
	A(A&& other)
	{
		cout << __PRETTY_FUNCTION__ << endl;
		m_pBuffer = other.m_pBuffer;
		other.m_pBuffer = nullptr;
	}

	A& operator=(A&& orig)
	{
		cout << __PRETTY_FUNCTION__ << endl;
		if (m_pBuffer != nullptr)
		{
			delete [] m_pBuffer;
			m_pBuffer = nullptr;
		}

		m_pBuffer = orig.m_pBuffer;
		orig.m_pBuffer = nullptr;

		return *this;
	}

	~A()
	{
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
	
	vector<A> vec;
	vec.push_back(A());
	
	a = getA();

	return 0;
}
