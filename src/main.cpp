#include <iostream>
#include "./my_printf.hpp"
#include "./my_print.hpp"

int main() {
    std::cout << "my_printf:" << std::endl;
    my_printf("Hello, %d/%i %s (%f %%)!\n", 10, 19, "worlds", 52.63);
    std::cout << "my_print:" << std::endl;
    my_print("Hello, {}/{} {} ({} %)!\n", 10, 19, "worlds", 52.63);
}
