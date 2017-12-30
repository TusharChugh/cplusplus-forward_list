#ifndef FORWARD_LIST_FORWARD_TLIST_H
#define FORWARD_LIST_FORWARD_TLIST_H

#include "forward_tlist_node.h

namespace tlib{
    template <typename T>
    class forward_tlist{
    public:
        forward_tlist(): head(nullptr), tail(nullptr) {};
        ~forward_tlist() { delete head; }
        bool empty() { return head == nullptr; }
        void push_back(const T& element) {

        }

        iterator begin() { return mylist_iterator<T>(head); }
        iterator end() { return mylist_iterator<T>(NULL); }
        
    private:
        forward_tlist_node *head;
        forward_tlist_node *tail;
    };
}

#endif //FORWARD_LIST_FORWARD_TLIST_H
