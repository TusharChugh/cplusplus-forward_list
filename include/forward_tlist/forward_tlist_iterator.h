#ifndef FORWARD_LIST_FORWARD_TLIST_ITERATOR_H
#define FORWARD_LIST_FORWARD_TLIST_ITERATOR_H

#include "forward_tlist_node.h"
#include <iterator>

namespace tlib {
    template <typename T, typename difference_type, typename pointer, typename reference>
    class forward_tlist_iterator : public std::iterator<std::forward_iterator_tag, T, difference_type, pointer, reference> {
        friend class forward_tlist<T, std::allocator<T>>;

        using forward_tlist_iterator_base = std::iterator<std::forward_iterator_tag, T, difference_type, pointer, reference>;

    public:
        using node_pointer = forward_tlist_iterator_base *;
        T& operator*();
        const forward_tlist_iterator_base& operator++();
        bool operator!=(const forward_tlist_iterator_base& other) const;

    private:
        forward_tlist_iterator_base *pointee;
        explicit forward_tlist_iterator(node_pointer pointee): pointee(pointee) {}

    }; //class forward_tlist_iterator
} //namespace tlib

#endif //FORWARD_LIST_FORWARD_TLIST_ITERATOR_H
