// .cpp files contain code definitions for methods that have been declared
// in the according .hpp file. The skeleton has been set up here for you.
// That is, the methods have been initiated, and your mission, should you 
// choose to accept it (which you should for marks), is to fill in each method
// with the appropriate code.
//
// A note about the "::" syntax: generally, this means "the thing on the right
// belongs to the thing on the left." So, SequentialList::empty() means the method
// empty() belongs to the class SequentialList. This allows empty() to access (and
// potentially change) the member variables in class SequentialList.

#include "SequentialList.hpp"
#include <iostream>

// This is the constructor.
SequentialList::SequentialList(unsigned int cap)
{
    data_ = new DataType (cap);
    size_ = 0;
    capacity_ = cap;
}

SequentialList::~SequentialList()
{
    delete []data_;
    data_ = NULL;
}

bool SequentialList::empty() const
{
    if (size_ == 0)
        return true;
    return false;
}

unsigned int SequentialList::size() const
{
    return size_;
}

unsigned int SequentialList::capacity() const
{
    return capacity_;
}

bool SequentialList::full() const
{
    if (size_ == capacity_)
        return true;
    return false;
}

void SequentialList::print() const
{
    if (empty())
    {
        std::cout << "[]";
        return;
    }
    std::cout << "[";
    for (int i = 0; i < size_; i++)
    {
        std:: cout << data_[i];
        if (i != size_-1)
            std:: cout << ",";
    }
    std::cout << "]";
}

// NOTE on inserts: do NOT grow the array if we reach capacity. Simply return false.
bool SequentialList::insert_front(DataType val)
{
    return insert(val,0);
}

bool SequentialList::remove_front()
{
    return remove(0);
}

bool SequentialList::insert_back(DataType val)
{
    return insert(val,size_);
}

bool SequentialList::remove_back()
{
    return remove(size_-1);
}

bool SequentialList::insert(DataType val, unsigned int index)
{
    if (full() || index > size_ || index < 0)
        return false;
    if (index == size_)
    {
        data_[index] = val;
        size_++;
        return true;
    }
    int count = size_;
    while (count > index)
    {
        data_[count] = data_[count-1];
        count--;
    }
    data_[count] = val;
    size_++;
    return true;
}

bool SequentialList::remove(unsigned int index)
{
    if (empty())
        return false;
    int count = index;
    while (count < size_)
    {
        data_[count] = data_[count+1];
        count++;
    }
    size_--;
    return true;
}

unsigned int SequentialList::search(DataType val) const
{
    int count = 0;
    while (data_[count] != val && count < size_)
        count++;
    return count;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
    if (index < size_ && index >= 0)
        return data_[index];
    return data_[size_-1];
}

bool SequentialList::replace(unsigned int index, DataType val)
{
    if (empty())
        return false;
    data_[index] = val;
    return true;
}
