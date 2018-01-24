#ifndef LAB1_TESTS_HPP
#define LAB1_TESTS_HPP

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

#include "DoublyLinkedList.hpp"
#include "SequentialList.hpp"

class SequentialListTest
{
public:
    bool test1()
    {
        unsigned int capacity = 5;
        SequentialList list(capacity);
        
        ASSERT_TRUE(list.size() == 0)
        ASSERT_TRUE(list.capacity() == capacity)
        ASSERT_TRUE(list.empty() == true)
        ASSERT_TRUE(list.full() == false)
        for (int i = 0; i <4;i++)
            ASSERT_TRUE(list.insert_front(i));
        ASSERT_TRUE(list.insert(10,2));
        return true;
    }

    bool test2()
    {
        unsigned int capacity = 5;
        SequentialList list1(capacity);
        SequentialList list2(capacity);
        ASSERT_TRUE(list1.insert_front(100))
        ASSERT_TRUE(list2.insert_back(100))
    
        ASSERT_TRUE(list1.size() == list2.size() && list1.size() == 1)
        ASSERT_TRUE(list1.data_ != NULL)
        ASSERT_TRUE(list2.data_ != NULL)
        ASSERT_TRUE(list1.data_[0] == list2.data_[0] && list1.data_[0] == 100)
        return true;
    }

    bool test3()
    {
        unsigned int capacity = 5;
        SequentialList list(capacity);
        
        ASSERT_TRUE(list.insert_front(100))
        ASSERT_TRUE(list.insert_front(101))
        ASSERT_TRUE(list.remove_front())
        ASSERT_TRUE(list.remove_back())
        ASSERT_TRUE(list.search(100) == list.size_)
    
        
        for (int i = 0; i < capacity; i++) {
            ASSERT_TRUE(list.insert_back(i*100))
        }
        
        unsigned int idx = 3;
        ASSERT_TRUE(list.search(list.select(idx)) == idx)
        ASSERT_TRUE(list.select(capacity + 1) == list.select(capacity))
        ASSERT_TRUE(list.search(1000) == list.size())
        
        for (int i = 0; i < capacity; i++) {
            ASSERT_TRUE(list.select(i) == i*100 && list.data_[i] == i*100)
        }
        return true;
    }

};

class DoublyLinkedListTest
{
public:
    bool test1()
    {
        DoublyLinkedList list;
        ASSERT_TRUE(list.size() == 0)
        ASSERT_TRUE(list.empty() == true)
        ASSERT_TRUE(list.full() == false)
        ASSERT_TRUE(list.head_ == NULL)
        ASSERT_TRUE(list.tail_ == NULL)
        ASSERT_TRUE(list.insert_front(3))
        ASSERT_TRUE(list.insert_front(2))
        ASSERT_TRUE(list.insert_front(1))
        ASSERT_TRUE(list.insert(10,0))
        ASSERT_TRUE(list.search(10) == 0)
        ASSERT_TRUE(list.getNode(2)->value == list.search(2))
        ASSERT_TRUE(list.remove(1))
        ASSERT_TRUE(list.remove(1))
        ASSERT_TRUE(list.remove(1))
        ASSERT_TRUE(list.remove(0))

        return true;
    }

    bool test2()
    {
        DoublyLinkedList list1, list2;
    
        for (int i = 0; i <list1.capacity();i++)
            ASSERT_TRUE(list1.insert(i,0))
        
        for (int i = 0; i <list2.capacity();i++)
            ASSERT_TRUE(list2.insert(i,list2.size()))
                
        ASSERT_TRUE(list1.size() == list2.size())
        ASSERT_TRUE(list2.select(65512) == 65512)
        
        return true;
    }

    bool test3()
    {
        DoublyLinkedList list;
        
        ASSERT_TRUE(list.insert_front(100))
        ASSERT_TRUE(list.insert_front(101))
        ASSERT_TRUE(list.remove_front())
        ASSERT_TRUE(list.remove_back())
        ASSERT_TRUE(list.search(100) == list.size_)
        ASSERT_TRUE(list.head_ == NULL && list.tail_ == NULL)
        
        // List is [0, 100, ..., 400]
        const int num_elems = 5;
        for (int i = 0; i < num_elems; i++) {
            ASSERT_TRUE(list.insert_back(i*100))
        }
        
        unsigned int idx = 3;
        ASSERT_TRUE(list.search(list.select(idx)) == idx)
        ASSERT_TRUE(list.search(1000) == list.size_) 

        // Check that the list has the right values
        for (int i = 0; i < num_elems; i++) {
            ASSERT_TRUE(list.select(i) == i*100)
        }
        
        ASSERT_TRUE(list.head_->prev == NULL && list.tail_->next == NULL)
        
        
        return true;
    }

};


#endif
