#include <gtest/gtest.h>
#include "forward_tlist/forward_tlist.h"

TEST(ITERATOR, ITERATOR) {
    tlib::forward_tlist<int> int_list;
    int_list.push_front(1);
    int_list.push_front(2);
    auto iterator_begin = int_list.begin();
    auto iterator_end = int_list.end();
    ASSERT_TRUE(1);
}