#ifndef FORWARD_LIST_FORWARD_TLIST_ITERATOR_H
#define FORWARD_LIST_FORWARD_TLIST_ITERATOR_H

#include "forward_tlist_node.h"
#include <iterator>

namespace tlib {
    template <typename T, typename difference_type, typename pointer, typename reference>
    class forward_tlist_iterator : public std::iterator<std::forward_iterator_tag, T, difference_type, pointer, reference> {
        friend class forward_tlist<T, std::allocator<T>>;

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using forward_tlist_iterator_type = forward_tlist_iterator<value_type, difference_type, pointer, reference>;
        using node_pointer = tlib::forward_tlist_node<T> *;

        reference operator*() {
            return pointee->element;
        }

        const forward_tlist_iterator_type& operator++() {
            pointee = pointee->next;
            return *this;
        }

        bool operator!=(const forward_tlist_iterator_type& other) const {
            return pointee != other.pointee;
        };

        forward_tlist_iterator() { }

    private:
        forward_tlist_node<T> *pointee;
        explicit forward_tlist_iterator(node_pointer pointee): pointee(pointee) {}

    }; //class forward_tlist_iterator
} //namespace tlib

#endif //FORWARD_LIST_FORWARD_TLIST_ITERATOR_H
