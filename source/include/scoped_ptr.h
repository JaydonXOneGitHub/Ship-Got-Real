#ifndef SCOPED_PTR
#define SCOPED_PTR

template<typename PtrType>
class ScopedPtr
{
private:
    PtrType* ptr;

public:
    PtrType* operator->();

    PtrType& Base();

    explicit ScopedPtr(PtrType* ptr);
    ScopedPtr(const ScopedPtr&) = delete;
    ScopedPtr(const ScopedPtr&&) = delete;
    ~ScopedPtr();
};

template<typename PtrType>
PtrType& operator*(const ScopedPtr<PtrType>& scopedPtr)
{
    return scopedPtr.Base();
}

#endif