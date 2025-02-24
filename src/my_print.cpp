#include <iostream>
#include <string_view>

int my_print(std::string_view format) {
    std::cout << format;
    return 0;
}
