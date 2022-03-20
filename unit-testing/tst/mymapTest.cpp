#include    "gtest/gtest.h"
#include "../src/mymap.h"

TEST(mymap, Calculate) {
    mymap<int, string> t1;
    EXPECT_EQ(t1.Size(), 0);
    t1[4] = "hello world";
    EXPECT_EQ(t1.Size(), 1);
    EXPECT_EQ(t1.contains(4), true);
    EXPECT_EQ(t1.get(4), "hello world");
}
