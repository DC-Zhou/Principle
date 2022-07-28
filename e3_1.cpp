//
// Created by Zhouzhou on 2022/7/25.
//
// iterator in stl
#include <iostream>

template<typename T>
struct Unit
{
    T value;
    Unit * next;
};

template<typename  T>
class MyLink
{
    Unit<T> * head;
    Unit<T> * tail;
    Unit<T> * prev;
public:
    MyLink()
    {
        head = tail = prev = nullptr;
    }
    void Add(T& value)
    {
        Unit<T> * u= new Unit<T> ();
        u->value = value;
        u->next = nullptr;
        if(head == nullptr)
        {
            head = u;
            prev = u;
        }
        else
        {
            prev->next = u;
            prev = u;
        }
        tail = u->next;
    }

    Unit<T> * Begin()
    {
        return head;
    }

    Unit<T> * End()
    {
        return tail;
    }

    virtual ~MyLink()
    {
        if(head != nullptr)
        {
            Unit<T> * prev = head;
            Unit<T> * next = nullptr;
            while(prev != tail)
            {
                next = prev -> next;
                delete prev;
                prev = next;

            }
        }
    }
};

template<typename Init>
class LinkIterator
{
    Init * init;
public:
    LinkIterator(Init * init)
    {
        this->init = init;
    }
    bool operator != (LinkIterator& it)
    {
        return this->init != it.init;
    }
    void operator++(int)
    {
        init = init->next;
    }
    Init operator* ()
    {
        return * init;
    }
};

template<typename  T>
std::ostream& operator<<(std::ostream& os, Unit<T> s)
{
    os << s.value;
    return os;
}

template<typename Init>
void display(Init start, Init end)
{
    std::cout<<std::endl;
    for (Init mid = start; mid != end; mid++)
        std::cout << *mid<< std::endl;
    std::cout<<std::endl;
}

int main()
{
    int m = 0;
    MyLink<int> ml;
    for(auto i = 0; i < 5; i++)
    {
        m = i + 1;
        ml.Add(m);
    }
    LinkIterator<Unit<int>> start(ml.Begin());
    LinkIterator<Unit<int>> end(ml.End());
    display(start, end);

    return 0;
}