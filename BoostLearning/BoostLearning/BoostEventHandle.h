#pragma once

class BoostEventHandle
{
private:
    static BoostEventHandle *pInstance;

public:
    ~BoostEventHandle();
    static void Entry();

private:
    BoostEventHandle();
    void SignalsTest();
};

