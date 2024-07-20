#include "include/event.h"

void std::event::operator+=(FuncPtr f)
{
    Add(f);
}

void std::event::operator-=(FuncPtr f)
{
    Remove(f);
}

void std::event::Add(FuncPtr f)
{
    for (FuncPtr _f : functions)
    {
        if (_f == f)
        {
            // Already here
            return;
        }
    }
    functions.push_back(f);
}

void std::event::Remove(FuncPtr f)
{
    bool canRemove = false;

    for (FuncPtr _f : functions)
    {
        if (_f == f)
        {
            canRemove = true;
            break;
        }
    }

    if (canRemove)
        functions.remove(f);
}

void std::event::Invoke()
{
    for (FuncPtr f : functions)
    {
        f();
    }
}

void std::event::operator()()
{
    for (FuncPtr f : functions)
    {
        f();
    }
}

void std::event::Clear()
{
    functions.clear();
}

std::event::~event()
{
    functions.clear();
}