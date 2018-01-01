#ifndef FORWARD_LIST_FORWARD_TLIST_H
#define FORWARD_LIST_FORWARD_TLIST_H

#include "forward_tlist_node.h"

namespace tlib{
    template <typename T>
    class forward_tlist{
        using iterator = tlib::forward_tlist_iterator<T>;
    public:
        forward_tlist(): head(nullptr), tail(nullptr) {};
        ~forward_tlist() { delete head; }
        bool empty() { return head == nullptr; }
        void push_back(const T& element) {

        }

        iterator begin() { return forward_tlist_iterator<T>(head); }
        iterator end() { return forward_tlist_iterator<T>(nullptr); }

    private:
        forward_tlist_node<T> *head;
        forward_tlist_node<T> *tail;
    };
}

#endif //FORWARD_LIST_FORWARD_TLIST_H
