// who: <George Hanna - ghanna5>
// what: <Definition of the Buckets functions>
// why: <Bucket Data Structure (Lab 5)>
// when: <October 30, 2022>

#include <stdexcept>

#include "bucket.h"

Bucket::Bucket() : Bucket{DEFAULT_SIZE} { }

Bucket::Bucket(size_t initSize)
    : currentSize{initSize}, store{new double*[initSize]{ }} { }

void Bucket::clear()
{
    for (size_t i = 0; i < count; ++i)
    {
        delete store[i];
        store[i] = nullptr;
    }
   
    count = 0;
}

size_t Bucket::size()
{
    return count;
}

bool Bucket::empty()
{
    return count == 0;
}

void Bucket::add(double val)
{
    if(count == currentSize)
        resize();

    store[count++] = new double{val};
}

void Bucket::resize()
{
    size_t newSize{currentSize * RESIZE_FACTOR};

    double** newStore{new double*[newSize]};
    for (size_t i = 0; i < count; ++i)
        newStore[i] = store[i];

    delete[] store;
    store = newStore;  
}

double Bucket::remove()
{
    double rtnVal;

    if(empty()) throw std::runtime_error("Remove on empty bucket");

    rtnVal = *store[--count];
    delete store[count];
    store[count] = nullptr;
    return rtnVal;
}

bool Bucket::remove(double val)
{
    size_t i;
    if(empty()) throw std::runtime_error("Remove on empty bucket");

    for (i = 0; i < count; ++i)
        if(*store[i] == val) break;

    if(i >= count) return false;

    delete store[i];
    store[i] = store[--count];
    store[count] = nullptr;
   
    return true;
}