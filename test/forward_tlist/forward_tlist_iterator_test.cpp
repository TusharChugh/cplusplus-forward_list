#include <gtest/gtest.h>
#include "forward_tlist/forward_tlist.h"
#include <forward_list>

TEST(ITERATOR, ITERATOR) {
    tlib::forward_tlist<int> int_list;
    int_list.push_front(1);
    int_list.push_front(2);
    auto iterator_begin = int_list.begin();
    auto iterator_end = int_list.end();
    ASSERT_EQ(*iterator_begin, 2);
    ASSERT_EQ(*iterator_end, NULL);
}

TEST(CONST_ITERATOR, CONST_ITERATOR) {
    tlib::forward_tlist<int> int_list;
    int_list.push_front(1);
    int_list.push_front(2);
    auto iterator_begin = int_list.begin();
    auto iterator_end = int_list.end();
    ASSERT_EQ(*iterator_begin, 2);
    ASSERT_EQ(*iterator_end, NULL);
}

TEST(ITERATOR_PLUS, ITERATOR_PLUS) {
    tlib::forward_tlist<int> int_tlist;
    int_tlist.push_front(1);
    int_tlist.push_front(2);

    std::forward_list<int> int_list;
    int_list.push_front(1);
    int_list.push_front(2);

    tlib::forward_tlist<int>::iterator tlist_iterator = int_tlist.begin();
    std::forward_list<int>::iterator list_iterator;
    for(list_iterator = int_list.begin();
        tlist_iterator != int_tlist.end() && list_iterator != int_list.end(); ++tlist_iterator, ++list_iterator) {
        ASSERT_EQ(*tlist_iterator, *list_iterator);
    }
}

TEST(AUTO_ITERATOR, AUTO_ITERATOR_AU_Test) {
    tlib::forward_tlist<int> int_tlist;
    int_tlist.push_front(1);
    int_tlist.push_front(2);

   for(auto element: int_tlist) {
       std::cout<<element<<" ";
   }std::cout<<std::endl;
}
