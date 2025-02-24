#include <iostream>
#include "./my_printf.hpp"

int main() {
    std::cout << "my_printf:" << std::endl;
    my_printf("Hello, %d/%i %s (%f %%)!\n", 10, 19, "worlds", 52.63);
}
