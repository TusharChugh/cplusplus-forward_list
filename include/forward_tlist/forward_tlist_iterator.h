#ifndef FORWARD_LIST_FORWARD_TLIST_ITERATOR_H
#define FORWARD_LIST_FORWARD_TLIST_ITERATOR_H

#include "forward_tlist_node.h"
#include <iterator>

namespace tlib {
    template <typename _T, typename _difference_type, typename _pointer, typename _reference>
    class forward_tlist_iterator : public std::iterator<std::forward_iterator_tag, _T, _difference_type, _pointer, _reference> {
        friend class forward_tlist<_T, std::allocator<_T>>;
        using iterator_base = forward_tlist_iterator<_T, _difference_type, _pointer, _reference>;

    public:
        using value_type = typename iterator_base::value_type;
        using pointer = typename iterator_base::pointer;
        using difference_type = typename iterator_base::difference_type;
        using reference = typename iterator_base::reference;

        using const_pointer = const value_type*;
        using const_reference = const value_type&;
        using iterator_category = std::forward_iterator_tag;

        using mutable_iterator = forward_tlist_iterator<value_type, difference_type, value_type*, reference&>;
        using link_type = tlib::forward_tlist_node<value_type> *;


        reference operator*() {
            return (*_pointee).element;
        }

        forward_tlist_iterator& operator++() {
            _pointee = (link_type)((*_pointee).next);
            return *this;
        }

        bool operator!=(const iterator_base& other) const {
            return _pointee != other._pointee;
        };

        forward_tlist_iterator() { }
        ~forward_tlist_iterator() = default;

    private:
        link_type _pointee;
        explicit forward_tlist_iterator(const link_type& pointee): _pointee(pointee) { }
//        explicit forward_tlist_iterator(const mutable_iterator& pointee): _pointee(pointee) { }

    }; //class forward_tlist_iterator
} //namespace tlib

#endif //FORWARD_LIST_FORWARD_TLIST_ITERATOR_H
