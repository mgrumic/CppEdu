#include <iostream>
#include <string>

int main()
{
    std::string a = "1234";
    std::cout << "main " << a << std::endl;
    auto func = [a = std::move(a)]() mutable {
        a.append("asdf");
        std::cout << "lambda " << a << std::endl;};
    func();
    std::cout << "main " << a << std::endl;
    func();
    return 0;
}
