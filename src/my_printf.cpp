#include <cstdarg>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>

int my_printf(const char *format, ...) {
    std::string_view view(format);
    va_list args;
    va_start(args, format);
    size_t start = 0;
    size_t end = 0;
    size_t len = 0;
    while (view[end] != '\0') {
        if (view[end] == '%') {
            size_t diff = end - start;
            std::cout << view.substr(start, diff);
            len += diff;
            start = end + 2;
            char end_char = view[++end];
            if (end_char == '\0') {
                start = end;
            } else if (end_char == 's') {
                const char *str = va_arg(args, const char *);
                std::string_view str_view(str);
                std::cout << str_view;
                len += str_view.length();
            } else if (end_char == 'd' || end_char == 'i') {
                int num = va_arg(args, int);
                std::string num_str = std::to_string(num);
                std::cout << num_str;
                len += num_str.length();
            } else if (std::string_view("fFeEgGaA").find(end_char) !=
                       std::string_view::npos) {
                double num = va_arg(args, double);
                std::ostringstream oss;
                oss << num;
                std::string num_str = oss.str();
                std::cout << num_str;
                len += num_str.length();
            } else if (end_char == '%') {
                std::cout << '%';
                len++;
            } else {
                break;
            }
        }
        end++;
    }
    std::cout << view.substr(start, end - start);
    va_end(args);
    return len;
}
