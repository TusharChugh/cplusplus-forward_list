#ifndef FORWARD_LIST_FORWARD_TLIST_NODE_H
#define FORWARD_LIST_FORWARD_TLIST_NODE_H

#include <memory>

namespace tlib {
    //forward declare forward_tlist and iterator
    template<typename _T, typename _Alloc = std::allocator<_T>> class forward_tlist;
    template <typename _forward_tlist, typename _pointer, typename _reference> class forward_tlist_iterator;

    template<typename T>
    class forward_tlist_node {
        using _forward_tlist_type = forward_tlist<T, std::allocator<T>>;
        using _Alloc = typename _forward_tlist_type::allocator_type ;
        using value_type = typename _Alloc::value_type;
        using pointer = typename _Alloc::pointer;
        using const_pointer = typename _Alloc::const_pointer;
        using reference = typename _Alloc::reference;
        using const_reference = typename _Alloc::const_reference;
        using size_type = typename _Alloc::size_type;
        using difference_type = typename _Alloc::difference_type;


        //Giving access to private members to forward_tlist<T> and forward_tlist_iterator<T>
        friend class forward_tlist<T, std::allocator<T>>;
        friend class forward_tlist_iterator<_forward_tlist_type, typename _forward_tlist_type::pointer, typename _forward_tlist_type::reference>;
        friend class forward_tlist_iterator<_forward_tlist_type, typename _forward_tlist_type::const_pointer, typename _forward_tlist_type::const_reference>;

    private:
        /**
         * Constructor
         * @param element element of type T
         * @param next pointer to the next element of the list
         */
        forward_tlist_node(const T& element, forward_tlist_node<T> *next) : element(element), next(next) {}

        /**
         * Destructor
         */
        ~forward_tlist_node() { delete next; }

        //element of the node
        T element;
        //pointer to the next element of the list
        forward_tlist_node<T> *next;
    }; //class forward_tlist_node
} //namespace tlib


#endif //FORWARD_LIST_FORWARD_TLIST_NODE_H
