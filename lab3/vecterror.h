#ifndef VECTERROR_H
#define VECTERROR_H

#include <iostream>

class VectError
{
public:
    VectError() {}

    virtual void ErrMsg() const
    {
        std::cerr << "Error with Vect object.\n";
    }
};

class VectRangeErr : public VectError
{
public:
    VectRangeErr(int _min, int _max, int _actual)
        : min(_min)
        , max(_max)
        , actual(_actual)
    {}

    void ErrMsg() const
    {
        std::cerr << "Error of index: ";
        std::cerr << "possible range:" << min
                  << " - " << max << " . ";
        std::cerr << "actual index: " << actual << std::endl;
    }
private:
    int min, max;
    int actual;
};

class VectPopErr : public VectError
{
public:
    void ErrMsg() const
    {
        std::cerr << "Error of pop\n";
    }
};

#endif // VECTERROR_H
