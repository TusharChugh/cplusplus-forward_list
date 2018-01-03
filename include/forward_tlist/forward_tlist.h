#ifndef FORWARD_LIST_FORWARD_TLIST_H
#define FORWARD_LIST_FORWARD_TLIST_H

#include "forward_tlist_node.h"
#include <memory>

namespace tlib{
    template <typename T, typename allocator>
    class forward_tlist{
        using allocator_type = allocator;
        using iterator = tlib::forward_tlist_iterator<T>;
        using value_type = typename allocator::value_type;
        using pointer = typename allocator::pointer;
        using reference = typename allocator::reference;
        using const_reference = typename allocator::const_reference;
        using size_type = typename allocator::size_type;
        using forward_tlist_node = tlib::forward_tlist_node<T>;

    public:
        explicit forward_tlist(const allocator_type & alloc = allocator_type ()):
                __allocator(alloc), __head(nullptr), __tail(nullptr), __size(0) {};
        ~forward_tlist() { delete __head; }
        bool empty() { return __head == nullptr; }
        size_type size() const;
        /**
         * Prepends the given element to the beginning of the container
         * No iterators are invalidated
         * @param element the value of the element to prepend
         */
        void push_front(const T& element);
        iterator begin() { return forward_tlist_iterator<T>(__head); }
        iterator end() { return forward_tlist_iterator<T>(nullptr); }

    private:
        size_type __size;
        allocator_type __allocator;
        forward_tlist_node *__head;
        forward_tlist_node *__tail;
    }; //class forward_tlist
} //namespace tlib

#endif //FORWARD_LIST_FORWARD_TLIST_H
