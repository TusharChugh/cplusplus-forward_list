#ifndef FORWARD_LIST_FORWARD_TLIST_NODE_H
#define FORWARD_LIST_FORWARD_TLIST_NODE_H

#include <memory>

namespace tlib {
    //forward declare forward_tlist and iterator
    template<typename T, typename Alloc = std::allocator<T>> class forward_tlist;
    template <typename T, typename difference_type, typename pointer, typename reference> class forward_tlist_iterator;

    template<typename T>
    class forward_tlist_node {
        using Alloc = std::allocator<T>;
        using allocator_type = Alloc;
        using value_type = typename Alloc::value_type;
        using pointer = typename Alloc::pointer;
        using const_pointer = typename Alloc::const_pointer;
        using reference = typename Alloc::reference;
        using const_reference = typename Alloc::const_reference;
        using size_type = typename Alloc::size_type;
        using difference_type = typename Alloc::difference_type;

        //Giving access to private members to forward_tlist<T> and forward_tlist_iterator<T>
        friend class forward_tlist<T, std::allocator<T>>;
        friend class forward_tlist_iterator<T, difference_type, pointer, reference>;
        friend class forward_tlist_iterator<T, difference_type, const_pointer , reference>;

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
