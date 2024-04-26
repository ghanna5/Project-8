// who: <George Hanna - ghanna5>
// what: <Declaration of the bucket>
// why: <Bucket Data Structure (Lab 5)>
// when: <October 30, 2022>

// include guard
#include <cstddef>

#ifndef bucket_H
#define bucket_H

#define DEFAULT_SIZE 10
#define RESIZE_FACTOR 2

class Bucket
{
public:
    Bucket();
    Bucket(size_t);

    //add: adds double to the bucket
    void add(double);
    //remove(): removes and returns an arbitrary value
    double remove();
    //bool remove(double): removes and returns true if the value exists or false otherwise
    bool remove(double);
    //empty(): returns true if empty or false otherwise
    bool empty();
    //size(): returns the qty of doubles restored
    size_t size();
    //clear(): clears the bucket
    void clear();
private:
    double** store;
    size_t currentSize;
    size_t count;

    void resize();
};

#endif