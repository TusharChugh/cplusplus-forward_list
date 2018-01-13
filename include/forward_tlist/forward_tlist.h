#ifndef FORWARD_LIST_FORWARD_TLIST_H
#define FORWARD_LIST_FORWARD_TLIST_H

#include "forward_tlist_node.h"
#include "forward_tlist_iterator.h"
#include <memory>

namespace tlib{
    template <typename _T, typename _Alloc>
    class forward_tlist{

    public:
        using allocator_type = _Alloc;
        using value_type = typename _Alloc::value_type;
        using size_type = typename _Alloc::size_type;
        using difference_type = typename _Alloc::difference_type;
        using reference = typename _Alloc::reference;
        using const_reference = typename _Alloc::const_reference;
        using pointer = typename _Alloc::pointer;
        using const_pointer = typename _Alloc::const_pointer;
        using list_type = forward_tlist<_T, _Alloc>;
        using iterator = tlib::forward_tlist_iterator<list_type, pointer, reference >;
        using const_iterator = tlib::forward_tlist_iterator<list_type, const_pointer, const_reference>;

        using _forward_tlist_node = tlib::forward_tlist_node<value_type>;
        using _node_pointer = tlib::forward_tlist_node<value_type> *;

        explicit forward_tlist(const allocator_type& alloc = allocator_type()): _allocator(alloc) { init(); };

        ~forward_tlist() { delete _head; }
        bool empty() { return _head == nullptr; }
        size_type size() const { return _size; }

        /**
         * Prepends the given element to the beginning of the container
         * No iterators are invalidated
         * @param element the value of the element to prepend
         */
        void push_front(const_reference element) {
            auto new_node = create_node(element);
            new_node->next = _head;
            _head = new_node;
            _size++;
        }

        iterator make_iterator(_node_pointer &node) {
            return iterator(node);
        }

        const_iterator make_iterator(const _node_pointer &node) const noexcept {
            return const_iterator(node);
        }

        iterator begin() noexcept { return make_iterator(_head); }
        iterator end() noexcept { return make_iterator(_tail); }

        const_iterator cbegin() const noexcept { return make_iterator(_head);  }
        const_iterator cend() const noexcept { return make_iterator(_tail); }

        allocator_type get_allocator() const {_allocator ; }

    private:

        size_type _size;
        allocator_type _allocator;
        _node_pointer _head;
        _node_pointer _tail;

        void init() {
            _head = create_node(value_type{});
            _tail = _head;
            _size = 0;
        }

        _node_pointer create_node(const_reference element) {
            auto new_element = _allocator.allocate(1);
            _allocator.construct(new_element, element);
            auto new_node = new _forward_tlist_node(element, nullptr);
            return new_node;
        }
    }; //class forward_tlist
} //namespace tlib

#endif //FORWARD_LIST_FORWARD_TLIST_H
