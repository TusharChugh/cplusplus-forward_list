#ifndef FORWARD_LIST_FORWARD_TLIST_NODE_H
#define FORWARD_LIST_FORWARD_TLIST_NODE_H

namespace tlib {
    //forward declare forward_list and iterator
    template<typename T> class forward_tlist;
    template<typename T> class forward_tlist_iterator;

    template<typename T>
    class forward_tlist_node {
        //Giving access to private members to forward_list<T> and forward_tlist_iterator<T>
        friend class forward_tlist<T>;
        friend class forward_tlist_iterator<T>;

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
