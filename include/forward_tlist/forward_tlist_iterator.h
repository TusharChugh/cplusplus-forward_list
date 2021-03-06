#ifndef FORWARD_LIST_FORWARD_TLIST_ITERATOR_H
#define FORWARD_LIST_FORWARD_TLIST_ITERATOR_H

#include "forward_tlist_node.h"
#include <iterator>

namespace tlib {
    template <typename _forward_tlist_t, typename _pointer, typename _reference>
    class forward_tlist_iterator : public std::iterator<
            std::forward_iterator_tag,
            typename _forward_tlist_t::value_type,
            typename _forward_tlist_t::difference_type,
            _pointer,
            _reference> {

    public:
        using value_type = typename _forward_tlist_t::value_type;
        using difference_type = typename _forward_tlist_t::difference_type;
        using reference = typename _forward_tlist_t::reference;
        using const_reference = typename _forward_tlist_t::const_reference ;
        using pointer = typename _forward_tlist_t::pointer;
        using const_pointer = typename _forward_tlist_t::const_pointer;
        using iterator_category = std::forward_iterator_tag;

        using link_type = tlib::forward_tlist_node<value_type> *;
        using iterator_base = forward_tlist_iterator<_forward_tlist_t, _pointer, _reference>;

        friend class forward_tlist<value_type, typename _forward_tlist_t::allocator_type>;

        reference operator*() {
            return (*_pointee).element;
        }

        forward_tlist_iterator& operator++() {
            _pointee = (link_type)((*_pointee).next);
            return *this;
        }

        forward_tlist_iterator operator++(int) {
            forward_tlist_iterator _temp = *this;
            return ++*this, _temp;
        }

        bool operator==(const iterator_base& other) const {
            return _pointee == other._pointee;
        };

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
