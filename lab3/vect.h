#ifndef VECT_H
#define VECT_H

#include <string>
#include "vecterror.h"

template <class T>
class Vect
{
public:
    explicit Vect()
        : first(0), last(0) {}

    explicit Vect(size_t _n, const T& _v = T())
    {
        Allocate(_n);
        for (size_t i = 0; i < _n; ++i)
        {
            *(first + i) = _v;
        }
    }

    Vect(const Vect&); // конструктор копирования
    Vect& operator =(const Vect&); // операция присваивания

    ~Vect()
    {
        Destroy();
        first = 0;
        last = 0;
    }

    // установить отладочное имя
    void mark(std::string& name) { markName = name; }

    // получить отладочное имя
    std::string mark() const { return markName; }

    size_t size() const; // получить размер вектора

    T* begin() const { return first; } // получить указатель на 1-й элемент

    T* end() const { return last; } // получить указатель на элемент,
                                    // следующий за последним элементом
    T& operator[](size_t i); // операция индексирования

    void insert(T* _P, const T& _x); // вставка элемента в позицию _Р

    void push_back(const T& _х); // вставка элемента в конец вектора

    void pop_back(); // удаление элемента из конца вектора

    void show() const; // вывод в cout содержимого вектора

protected:
    void Allocate(size_t _n)
    {
        first = new T [_n * sizeof(T)];
        last = first + _n;
    }

    void Destroy()
    {
        for (T* p = first; p != last; ++p)
        {
            p->~T();
        }
        delete [] first;
    }

    T* first; // указатель на 1-й элемент
    T* last; // указатель на элемент, следующий за последним
    std::string markName;
};

// Конструктор копирования
template <class T>
Vect<T>::Vect(const Vect& other)
{
    size_t n = other.size();
    Allocate(n);
    for (size_t i = 0; i < n; ++i)
    {
        *(first + i) = *(other.first + i);
    }
    markName = std::string("Copy of ") + other.markName;
}

// Операция присваивания
template<class T>
Vect<T>& Vect<T>::operator =(const Vect& other)
{
    if (this == &other)
    {
        return *this;
    }
    Destroy();
    size_t n = other.size();
    Allocate(n);
    for (size_t i = 0; i < n; ++i)
    {
        *(first + i) = *(other.first + i);
    }
    return *this;
}

// Получение размера вектора
template<class T>
size_t Vect<T>::size() const
{
    if (first > last)
    {
        throw VectError();
    }
    return (0 == first ? 0 : last - first);
}

// Операция доступа по индексу
template<class T>
T& Vect<T>::operator[](size_t i)
{
    if (i < 0 || i > (size() - 1) )
    {
        throw VectRangeErr(0, last - first - 1, i);
    }
    return (*(first + i));
}

// Вставка элемента со значением _х в позицию _Р
template<class T>
void Vect<T>::insert(T* _P, const T& _x)
{
    size_t n = size() + 1; // новый размер
    T* new_first = new T [n * sizeof(T)];
    T* new_last = new_first + n;

    size_t offset = _P - first;
    for (size_t i = 0; i < offset; ++i)
    {
        *(new_first + i) = *(first + i);
    }

    *(new_first + offset) = _x;

    for (size_t i = offset; i < n; ++i)
    {
        *(new_first + i + 1) = *(first + i);
    }
    Destroy();
    first = new_first;
    last = new_last;
}

// Вставка элемента в конец вектора
template<class T>
void Vect<T>::push_back(const T& _x)
{
    if (! size())
    {
        Allocate(1);
        *first = _x;
    }
    else
    {
        insert(end(), _x);
    }
}

// Удаление элемента из конца вектора
template<class T>
void Vect<T>::pop_back()
{
    if (last == first)
    {
        throw VectPopErr();
    }
    T* p = end() - 1;
    p->~T();
    last--;
}

// Вывод в cout содержимого вектора
template<class T>
void Vect<T>::show() const
{
    std::cout << "\n===== Contents of " << markName << "=====" << std::endl;

    size_t n = size();
    for (size_t i = 0; i < n; ++i)
    {
        std::cout << *(first + i) << " ";
    }
    std::cout << std::endl;
}

#endif // VECT_H
