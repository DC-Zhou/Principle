//
// Created by Zhouzhou on 2022/7/23.
//
// C++ STL  and Applcation
// ch2-1 Dy Array
#include <stdio.h>
template <class T>
class MyArray
{
private:
    int m_nTotalSize;
    int m_nValidSize;
    T* m_pData;
public:
    MyArray(int nSize = 3)
    {
        m_pData = new T[nSize];
        m_nTotalSize = nSize;
        m_nValidSize = 0;
    }
    void add(T value) {
        if (m_nValidSize < m_nTotalSize)
        {
            m_pData[m_nValidSize] = value;
            m_nValidSize++;
        }
        else
        {
            int i = 0;
            T* tmpData  = new T[m_nTotalSize];
            for(auto i = 0; i < m_nTotalSize; i++)
            {
                tmpData[i] = m_pData[i];
            }
            delete [] m_pData;
            m_nTotalSize *= 2;
            for(auto i = 0;i < m_nTotalSize; i++)
            {
                m_pData[i] = tmpData[i];
            }
            delete [] tmpData;
            m_pData[m_nValidSize] = value;
            m_nValidSize++;
        }
    }

    int GetSize()
    {
        return m_nValidSize;
    }
    T Get(int pos)
    {
        return m_pData[pos];
    }
    virtual ~MyArray()
    {
        if(m_pData != NULL)
        {
            delete []m_pData;
            m_pData = NULL;
        }
    }
};

int main()
{
    MyArray<int> obj;
    obj.add(1);
    obj.add(2);
    obj.add(3);
    obj.add(4);
    obj.add(5);
    for(auto i = 0; i < obj.GetSize(); i++)
    {
        printf("Array is : %d\n", obj.Get(i));
    }
    return 0;
}