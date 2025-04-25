#pragma once


class Counter 
{
private:
    int counterResult_ = 0;

public:
    Counter(int initialInitValue);
    int getCounter();
    int counterPlus();
    int counterMinus();
};