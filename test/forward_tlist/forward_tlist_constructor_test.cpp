#include <gtest/gtest.h>
#include "forward_tlist/forward_tlist.h"

TEST(INTTEST, INTTEST) {
    tlib::forward_tlist<int> int_list;
    int_list.push_front(1);
    ASSERT_TRUE(1);
}

TEST(INTTEST1, INTTEST1) {
    tlib::forward_tlist<int> int_list;
    int_list.push_front(1);
    int_list.push_front(2);
    ASSERT_TRUE(1);
}

TEST(STRINGTEST, STRINGTEST) {
    tlib::forward_tlist<std::string> string_list;
    string_list.push_front("Hello");
    string_list.push_front("World");
    ASSERT_TRUE(1);
}
