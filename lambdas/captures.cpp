#include <iostream>


int main()
{
    int number{5};
    auto captureByValue = [number] {std::cout << "captureByValue number=" << number << std::endl;};
    auto captureByReference = [&number] { std::cout << "captureByReference number=" << number << std::endl;};

    int anotherNumber{6};

    auto allByValue = [=] { std::cout << "allByValue number=" << number << " another=" << anotherNumber << std::endl;};
    auto allByReference = [&] { std::cout << "allByReference number=" << number << " another=" << anotherNumber << std::endl;};

    auto mixedCapture = [=, &number] {number = 3; std::cout << "mixedCapture number changed to " << number << std::endl;};
     // auto invalidMixedCapture = [&, &number] {number = 3; std::cout << "number changed to " << number << std::endl;};
    // auto modifyCaptureByValue = [number] {number++; std::cout << "captureByValue number=" << number << std::endl;};

    captureByValue();
    captureByReference();
    mixedCapture();
    std::cout << std::endl;
    allByValue();
    allByReference();

    number = 10;
    std::cout << std::endl << "number changed to " << number << std::endl << std::endl;

    captureByValue();
    captureByReference();
    return 0;
}