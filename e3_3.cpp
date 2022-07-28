//
// Created by Zhouzhou on 2022/7/25.
//
// iterator in stl by example 3
#include <iostream>
#include <iterator>

int main(int argc, char * argv[])
{
    std::cout<<"output iteractor show: ";
    std::ostream_iterator<int>myout(std::cout, "\n");
    * myout = 1;
    myout ++;
    * myout = 2;
    myout ++;
    * myout = 3;

    return 0;
}

