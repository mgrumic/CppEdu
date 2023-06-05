#include <iostream>

class Test
{
public:
    void run() {
        int val{0};
        auto valid = [this, val] { m_private++;/*val++*/; std::cout << "val=" << val << " m_private=" << m_private << std::endl;};
        valid();

        //auto invalid = [val] { std::cout << "val=" << val << " m_private=" << m_private << std::endl;};
        // invalid();
    }

private:
    int m_private{1};
};

int main()
{
    Test t;
    t.run();
    return 0;
}
