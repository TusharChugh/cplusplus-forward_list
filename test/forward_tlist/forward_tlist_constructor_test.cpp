#include <gtest/gtest.h>
#include "forward_tlist/forward_tlist.h"

TEST(LISTINPUTSIZE, LISTOUTPUTSIZE) {
    tlib::forward_tlist<int> int_list;
    int_list.push_front(1);
    ASSERT_TRUE(1);
}
