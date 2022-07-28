//
// Created by Zhouzhou on 2022/7/24.
//
// traits in C++ by Example
#include <iostream>
#include <type_traits>

class CIntArray
{
    int a[10];
public:
    CIntArray()
    {
        for(auto i = 0 ; i < 10; i++)
            a[i] = i;
    }

    int Getsum(int times)
    {
        int sum = 0;
        for(auto i = 0; i < 10; i++)
            sum += a[i];
        return sum* times;
    }
};

class CFloatArray
{
    float f[10];
public:
    CFloatArray()
    {
        for(auto i = 1 ; i < 10; i++)
            f[i-1] = 1.0f / i ;
    }

    float Getsum(float times)
    {
        float sum = 0.0f;
        for(auto i = 0; i < 10; i++)
            sum += f[i];
        return sum* times;
    }
};
template<class T>
class NumTraits
{
};

template<>
class NumTraits<CIntArray>
{
public:
    typedef int resulttype;
    typedef int inputpara;

};

template<>
class NumTraits<CFloatArray>
{
public:
    typedef float resulttype;
    typedef float inputpara;

};

template<class T>
class CApply
{
public:
    typedef typename NumTraits<T>::resulttype result;
    typedef typename NumTraits<T>::inputpara input;
    result GetSum(T& obj, input in)
    {
        return obj.Getsum(in);
    }
};


int main()
{
    CIntArray   intary;
    CFloatArray fltary;
    CApply<CIntArray> c1;
    CApply<CFloatArray> c2;
    std::cout <<"3 plus of Int array is "<< c1.GetSum(intary, 3) << std::endl;
    std::cout <<"3 plus of float array is " << c2.GetSum(fltary, 3.2f) << std::endl;
    return 0;
}