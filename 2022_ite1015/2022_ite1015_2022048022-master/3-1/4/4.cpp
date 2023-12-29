#include <iostream>

namespace first_space{
    void print(){
        std::cout << "Print from first space" << std::endl;
    }
}

namespace second_space{
    void print(){
        std::cout << "Print from second space" << std::endl;
    }
}

int main(){
    int a;
    std::cin >> a;
    if(a==1){
        first_space::print();
    }
    else second_space::print();
    return 0;
}
