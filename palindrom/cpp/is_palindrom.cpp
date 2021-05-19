#include <iostream>
#include <string>
#include <algorithm>

// check if a input palindrom or not
bool is_palindrom (std::string n)
{
    std::string reversed_n = "";
    reversed_n.resize(n.size());
    std::reverse_copy(n.begin(), n.end(), reversed_n.begin());
    return (reversed_n.compare(n) == 0);
}

int main(void)
{
    std::string n = "";
    std::cout << "Target: ";
    std::cin >> n;

    bool result = is_palindrom(n);

    (result)? std::cout << n << " is palindrom" : std::cout << n << " is not palindrom";

    return 0;
}