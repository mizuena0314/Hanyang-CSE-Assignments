#include <iostream>
#include <string>

int add(int a, int b){
    return (a+b);
}

std::string add(std::string a, std::string b){
    std::string res = a+'-'+b;
    return res;
}

float add(float a, float b= 0.9){
    return (a+b);
}

int main(){
    int num1, num2;
    std::string str1, str2;
    float f1;
    std::cin >> num1 >> num2;
    std::cin >> str1 >> str2;
    std::cin >> f1;
    
    std::cout << add(num1, num2) << std::endl;
    std::cout << add(str1, str2) << std::endl;
    std::cout << add(f1) << std::endl;
    return 0;
}
