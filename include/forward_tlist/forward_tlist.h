#ifndef FORWARD_LIST_FORWARD_TLIST_H
#define FORWARD_LIST_FORWARD_TLIST_H

#include "forward_tlist_node.h"
#include <memory>

namespace tlib{
    template <typename T, typename Alloc>
    class forward_tlist{
        using allocator_type = Alloc;
        using value_type = typename Alloc::value_type;
        using pointer = typename Alloc::pointer;
        using reference = typename Alloc::reference;
        using const_reference = typename Alloc::const_reference;
        using size_type = typename Alloc::size_type;
        using forward_tlist_node = tlib::forward_tlist_node<value_type>;
        using iterator = tlib::forward_tlist_iterator<value_type>;

    public:
        explicit forward_tlist(const allocator_type & alloc = allocator_type()):
                __allocator(alloc), __head(nullptr), __tail(nullptr), __size(0) {};

        ~forward_tlist() { delete __head; }
        bool empty() { return __head == nullptr; }
        size_type size() const;
        /**
         * Prepends the given element to the beginning of the container
         * No iterators are invalidated
         * @param element the value of the element to prepend
         */
        void push_front(const_reference element) {
            auto new_node = __allocator.allocate(1);
            __allocator.construct(new_node, element);
//            new_node->next = __head;
//            __head = new_node;
            __size++;
        }
        iterator begin() { return forward_tlist_iterator<T>(__head); }
        iterator end() { return forward_tlist_iterator<T>(nullptr); }

    private:
        size_type __size;
        allocator_type __allocator;
        pointer __head;
        pointer __tail;
    }; //class forward_tlist
} //namespace tlib

#endif //FORWARD_LIST_FORWARD_TLIST_H
