#ifndef FORWARD_LIST_FORWARD_TLIST_H
#define FORWARD_LIST_FORWARD_TLIST_H

#include "forward_tlist_node.h"
#include "forward_tlist_iterator.h"
#include <memory>

namespace tlib{
    template <typename T, typename Alloc>
    class forward_tlist{

    public:
        using allocator_type = Alloc;
        using value_type = typename Alloc::value_type;
        using pointer = typename Alloc::pointer;
        using reference = typename Alloc::reference;
        using const_reference = typename Alloc::const_reference;
        using size_type = typename Alloc::size_type;
        using difference_type = typename Alloc::difference_type;
        using forward_tlist_node = tlib::forward_tlist_node<value_type>;
        using node_pointer = tlib::forward_tlist_node<value_type> *;
        using iterator = tlib::forward_tlist_iterator<value_type, difference_type, pointer, reference>;

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
            auto new_element = __allocator.allocate(1);
            __allocator.construct(new_element, element);
            auto new_node = new forward_tlist_node(element, nullptr);
            new_node->next = __head;
            __head = new_node;
            __size++;
        }

        iterator begin() noexcept { return iterator(__head); }
        iterator end() noexcept { return iterator(nullptr); }

    private:
        size_type __size;
        allocator_type __allocator;
        node_pointer __head;
        node_pointer __tail;
    }; //class forward_tlist
} //namespace tlib

#endif //FORWARD_LIST_FORWARD_TLIST_H
