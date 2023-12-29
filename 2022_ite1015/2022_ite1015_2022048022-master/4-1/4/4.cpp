#include <iostream>

void getSumDiff(int a, int b, int& sum, int& diff)
{
    sum = (a+b);
    diff = (a-b);
}

int main(void)
{
    int a, b, sum, diff;
    std::cin >> a >> b;
    getSumDiff(a,b,sum,diff);
    std::cout << "sum:" << sum << std::endl;
    std::cout << "diff:" << diff << std::endl;
    return 0;
}
