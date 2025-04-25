#include "Counter.h"


Counter::Counter(int initialInitValue) 
{
    counterResult_ = initialInitValue;
};

int Counter::getCounter() 
{
    return counterResult_;
};

int Counter::counterPlus() 
{
    return ++counterResult_;
};

int Counter::counterMinus() 
{
    return --counterResult_;
};