#ifndef STACK_H
#define STACK_H

#include "vect.h"

template <class T>
class Stack
{
public:

    Stack() // конструктор
    {}

    bool empty()
    {
        return (0 == m_vec.size()); // если размер нашего стека равен 0, то он пуст
    }

    size_t size()
    {
        return m_vec.size(); // возвращает количество элементов нашего стека
    }

    T top()
    {
        //  возвращаем верхний элемент
        return m_vec[m_vec.size() - 1];
    }

    void push(const T& item)
    {
        m_vec.push_back(item); // добавляем в стек новый элемент
    }

    void pop()
    {
        //  снимаем верхний элемент
        m_vec.pop_back();
    }

private:

    Vect<T> m_vec;
};

#endif // STACK_H
