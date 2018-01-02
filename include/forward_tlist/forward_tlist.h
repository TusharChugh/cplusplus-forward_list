#ifndef FORWARD_LIST_FORWARD_TLIST_H
#define FORWARD_LIST_FORWARD_TLIST_H

#include "forward_tlist_node.h"
#include <cstddef>
#include <memory>

namespace tlib{
    template <typename T, typename allocator>
    class forward_tlist{
        using allocator_type = allocator;
        using iterator = tlib::forward_tlist_iterator<T>;
        using value_type = typename allocator::value_type;
    public:
        forward_tlist(): head(nullptr), tail(nullptr), size_(0) {};
        ~forward_tlist() { delete head; }
        bool empty() { return head == nullptr; }
        std::size_t size() const;
        /**
         * Prepends the given element to the beginning of the container
         * No iterators are invalidated
         * @param element the value of the element to prepend
         */
        void push_front(const T& element);
        iterator begin() { return forward_tlist_iterator<T>(head); }
        iterator end() { return forward_tlist_iterator<T>(nullptr); }

    private:
        std::size_t size_;
        forward_tlist_node<T> *head;
        forward_tlist_node<T> *tail;
    }; //class forward_tlist
} //namespace tlib

#endif //FORWARD_LIST_FORWARD_TLIST_H
