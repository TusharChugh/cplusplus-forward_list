#ifndef FORWARD_LIST_FORWARD_TLIST_ITERATOR_H
#define FORWARD_LIST_FORWARD_TLIST_ITERATOR_H

#include "forward_tlist_node.h"
#include <iterator>

namespace tlib {
    template <typename T>
    class forward_tlist_iterator : public std::iterator<std::forward_iterator_tag, T> {
    friend class forward_tlist<T>;

    public:
        T& operator*();
        const forward_tlist_iterator<T>& operator++();
        bool operator!=(const forward_tlist_iterator<T>& other) const;

    private:
        forward_tlist_node<T> *pointee;
        forward_tlist_iterator(forward_tlist_node<T> *pointee): pointee(pointee) {}

    }; //class forward_tlist_iterator
} //namespace tlib

#endif //FORWARD_LIST_FORWARD_TLIST_ITERATOR_H
