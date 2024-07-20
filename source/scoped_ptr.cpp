#include "include/scoped_ptr.h"

template<typename PtrType>
PtrType* ScopedPtr<PtrType>::operator->()
{
    return ptr;
}

template<typename PtrType>
PtrType& ScopedPtr<PtrType>::Base()
{
    return *ptr;
}

template<typename PtrType>
ScopedPtr<PtrType>::ScopedPtr(PtrType* ptr) : ptr(ptr) {}

template<typename PtrType>
ScopedPtr<PtrType>::~ScopedPtr() { delete ptr; }