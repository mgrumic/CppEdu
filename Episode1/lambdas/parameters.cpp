#include <iostream>
#include <string>
#include <functional>

void functorCaller(void (*lambda)(const std::string&,int)) {
    lambda("functorCaller", 123);
}

void functionalCaller(const std::function<void(const std::string&, int)>& lambda) {
    lambda("functionalCaller", 456);
}

template<typename T>
void templateCaller(T lambda) {
    lambda("templateCaller", 789);
}

int main()
{
    auto empty = [](){};
    auto alsoEmpty = []{};
    auto noParameters = [] {std::cout << "empty" << std::endl;};
    noParameters();

    auto parameterLambda = [](const std::string& caller, int number){std::cout << caller << " number = " << number << std::endl;};
    // void (*parameterLambda)(const std::string&,int) = [](const std::string& caller, int number){std::cout << caller << " number = " << number << std::endl;};

    functorCaller(parameterLambda);
    functionalCaller(parameterLambda);
    templateCaller(parameterLambda);
    return 0;
}

