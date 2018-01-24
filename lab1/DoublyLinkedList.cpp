#include "DoublyLinkedList.hpp"
#include <iostream>

DoublyLinkedList::Node::Node(DataType data)
{
	value = data;
	prev = NULL;
	next = NULL;
}

DoublyLinkedList::DoublyLinkedList()
{
	head_ = NULL;
	tail_ = NULL;
	size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
	while (head_ != NULL)
	{
		Node * temp_ = head_->next;
        head_->prev = NULL;
		delete head_;
		head_ = temp_;
	}
	tail_ = NULL;
}

bool DoublyLinkedList::empty() const
{
	if (size_ == 0)
		return true;
	return false;
}

unsigned int DoublyLinkedList::size() const
{
	return size_;
}

void DoublyLinkedList::print() const
{
    if (empty())
    {
        std:: cout << "[]";
        return;
    }
	std::cout << "[";
	Node* curr = head_;
	for (int i = 0; i < size_; i++)
	{
        if (i != size_-1)
        {
            std::cout << curr->value << ",";
            curr = curr->next;
        }
        else
            std::cout << curr->value;
	}
    std::cout << "]";
}

bool DoublyLinkedList::insert_front(DataType value)
{
	return insert(value,0);
}

bool DoublyLinkedList::remove_front()
{
	return remove(0);
}

bool DoublyLinkedList::insert_back(DataType value)
{
	return insert(value,size_);
}

bool DoublyLinkedList::remove_back()
{
	return remove(size_ - 1);
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
	if (!full() && size_ >= 0 && index >= 0 && index <= size_)
	{
        if (empty())
        {
            head_ = new Node(value);
            tail_ = head_;
        }
		else if (index == 0)
		{
			Node *temp_ = head_;
			head_ = new Node(value);
			head_->next = temp_;
			temp_->prev = head_;
		}
		else if (index == size_)
		{
			Node *temp_ = tail_;
			tail_ = new Node(value);
			tail_->prev = temp_;
			temp_->next = tail_;
		}
		else
		{
			Node *temp_ = new Node(value);
            Node *temp2_ = getNode(index-1);
			temp_->next = temp2_;
			temp_->prev = temp2_->prev;
			temp2_->prev->next = temp_;
			temp2_->prev = temp_;
		}
		size_ ++;
		return true;
	}
	return false;
}

bool DoublyLinkedList::remove(unsigned int index)
{
	if (!empty() && index >= 0 && index < size_)
	{
        if (size_ == 1)
        {
            delete head_;
            head_ = NULL;
            tail_ = NULL;
        }
		else if (index ==0)
		{
			Node *temp2_ = head_;
			head_->next->prev = NULL;
			head_ = head_->next;
			delete temp2_;
			temp2_ = NULL;
		}
		else if (index == size_ - 1)
		{
			Node *temp2_ = tail_;
			tail_->prev->next = NULL;
			tail_ = tail_->prev;
			delete temp2_;
			temp2_ = NULL;
		}
		else
		{
            Node *temp2_ = getNode(index);
			temp2_->prev->next = temp2_ ->next;
			temp2_->next->prev = temp2_ ->prev;
			delete temp2_;
			temp2_ = NULL;
		}
		size_--;
		return true;
	}
	return false;
}

unsigned int DoublyLinkedList::search(DataType value) const
{
    if (empty())
        return NULL;
    Node *temp2_ = head_;
    for (int j = 0; j < size_; j++)
    {
        if (temp2_->value == value)
            return j;
        temp2_ = temp2_->next;
    }
	return size_;
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
    return getNode(index)->value;
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
	if (index >=0 && index <= size_-1)
	{
		Node *temp2_ = head_;
		for (int j = 1; j <= index; j++)
		{
			temp2_ = temp2_->next;
		}
		temp2_->value = value;
		return true;
	}
	return false;
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
	Node *temp2_ = head_;
    if (index != 0 && index > 0 && index < size_)
    {
        for (int j = 1; j <= index; j++)
        {
            temp2_ = temp2_->next;
        }
    }
	return temp2_;
}

bool DoublyLinkedList::full() const
{
	if (size_ < CAPACITY)
		return false;
	return true;
}

unsigned int DoublyLinkedList::capacity() const
{
	return CAPACITY;
}
