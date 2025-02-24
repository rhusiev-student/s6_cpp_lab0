#ifndef INCLUDE_MY_PRINT_HPP_
#define INCLUDE_MY_PRINT_HPP_

#include <iostream>
#include <string_view>

int my_print(std::string_view format);

template <typename First, typename... Rest>
int my_print(std::string_view format, First first, Rest... rest) {
    auto pos = format.find("{}");
    if (pos == std::string_view::npos) {
        std::cout << format;
        return 0;
    }
    std::cout << format.substr(0, pos) << first;
    return my_print(format.substr(pos + 2), rest...);
}

#endif // INCLUDE_MY_PRINT_HPP_
