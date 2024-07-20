#pragma once

#include <list>
#include <functional>

typedef void(*FuncPtr)();

namespace std
{
    class event
    {
    private:
        std::list<FuncPtr> functions;

    public:
        void operator+=(FuncPtr f);

        void operator-=(FuncPtr f);

        void Add(FuncPtr f);

        void Remove(FuncPtr f);

        void Invoke();

        void operator()();

        void Clear();

        ~event();
    };
}
