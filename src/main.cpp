#include <iostream>
#include <string>
#include <boost/filesystem.hpp>
#include <any>

int main() {
    std::cout << "Hello, " << std::endl;

    boost::filesystem::ofstream f("smile");
    f << "Smile :)";

    std::cout << "World!" << std::endl;

    std::any a {13};

    try {
        std::cout << std::any_cast<int>(a) << std::endl;
    }
    catch(std::bad_any_cast) {
        std::cout << "cannot cast variable \"a\" to int" << std::endl;
    }

    try {
        std::cout << std::any_cast<std::string>(a) << std::endl;
    }
    catch(std::bad_any_cast) {
        std::cout << "cannot cast variable \"a\" to string" << std::endl;
    }

    return 0;
}