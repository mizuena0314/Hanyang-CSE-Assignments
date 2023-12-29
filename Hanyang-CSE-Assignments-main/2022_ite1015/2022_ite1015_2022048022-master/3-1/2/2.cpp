#include <iostream>
#include <string>

int main(){
    std::string str1, str2;
    std::cin >> str1 >> str2;
    str1 += str2;
    std::cout << str1 << std::endl;
    std::cout << str1[0] << std::endl;
    std::cout << str1[str1.size()-1] << std::endl;
    return 0;
}
