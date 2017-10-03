#include <iostream>
#include <boost/filesystem.hpp>

int main() {
    std::cout << "Hello, World!" << std::endl;

    boost::filesystem::ofstream f("smile");

    std::cout << "Hello, World!" << std::endl;

    return 0;
}