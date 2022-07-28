//
// Created by Zhouzhou on 2022/7/25.
//
// itator in stl by example
#include <iostream>
#include <iterator>

int main(int argc, char * argv[])
{
    std::cout<<"Please input data(like 111 222 333): :";
    std::istream_iterator<int> a(std::cin);

    std::istream_iterator<int> b;
    while(1)
    {
        std::cout << *a << std::endl;
        a++;
        if(a == b)
        {
            break;
        }
    }
    return 0;
}