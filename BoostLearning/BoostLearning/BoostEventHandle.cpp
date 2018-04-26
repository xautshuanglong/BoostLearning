#include "BoostEventHandle.h"

#include <iostream>
#include <boost/signal.hpp>

BoostEventHandle* BoostEventHandle::pInstance = nullptr;

void CommonGlobalFunc()
{
    std::cout << "Hello, world 0!" << std::endl;
}

void CommonGlobalFunc1()
{
    std::cout << "Hello, world 1!" << std::endl;
}

void CommonGlobalFunc2(int a, int b, int c, int d, int e, int f, int g, int h, int j, int k)
{
    std::cout << "Hello, world! 10 parameters" << std::endl;
}

BoostEventHandle::BoostEventHandle()
{}

BoostEventHandle::~BoostEventHandle()
{}

void BoostEventHandle::Entry()
{
    std::cout << std::endl << "--------------------- BoostEventHandle ---------------------" << std::endl;
    pInstance = new BoostEventHandle();

    pInstance->SignalsTest();
}

void BoostEventHandle::SignalsTest()
{
    boost::signal<void()> sig;
    sig.connect(CommonGlobalFunc);
    sig.connect(CommonGlobalFunc1);
    sig();

    boost::signal<void(int, int, int, int, int, int, int, int, int, int)> sig10;
    sig10.connect(CommonGlobalFunc2);
    sig10(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
}
