//
// Created by Zhouzhou on 2022/7/23.
//
// C++ STL  and Applcation
// ch1-1
#include <stdio.h>
namespace mycompany
{
    void func()
    {
        printf("Hello, from my company! ");
    }
};

namespace yourcompany
{
    void func()
    {
        printf("Hello, from your company!");
    }
};

using namespace mycompany;

int main()
{
    printf("This is C-Style file ! \n");
    func();
    printf("\n");
    yourcompany::func();
    printf("end!\n");
    return 0;
}