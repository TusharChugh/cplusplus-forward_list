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
        using const_iterator = tlib::forward_tlist_iterator<value_type, difference_type, const pointer, reference>;

        explicit forward_tlist(const allocator_type & alloc = allocator_type());

        ~forward_tlist() { delete __head; }
        bool empty() { return __head == nullptr; }
        size_type size() const;

        /**
         * Prepends the given element to the beginning of the container
         * No iterators are invalidated
         * @param element the value of the element to prepend
         */
        void push_front(const_reference element);

        iterator make_iterator(node_pointer &node) {
            return iterator(node);
        }

        const_iterator make_iterator(const node_pointer &node) {
            return const_iterator(node);
        }

        iterator begin() noexcept { return make_iterator(__head); }
        iterator end() noexcept { return make_iterator(__tail); }



        const_iterator cbegin() const noexcept { return make_iterator(__head);  }
        const_iterator cend() const noexcept { return make_iterator(__tail); }

    private:
        size_type __size;
        allocator_type __allocator;
        node_pointer __head;
        node_pointer __tail;

        void init();

        decltype(auto) create_node(const_reference element);
    }; //class forward_tlist
} //namespace tlib

#endif //FORWARD_LIST_FORWARD_TLIST_H
