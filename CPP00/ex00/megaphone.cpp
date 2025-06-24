#include <iostream>
#include <string>
#include <cctype>

int main(int ac, char **av) {
    if (ac == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; av[i]; i++) {
        std::string str = av[i];
        for (size_t j = 0; j < str.length(); j++) {
            std::cout << static_cast<char>(std::toupper(str[j]));
        }
    }
    std::cout << std::endl;
    return 0;
}