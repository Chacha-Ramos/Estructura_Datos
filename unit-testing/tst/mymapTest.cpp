#include    "gtest/gtest.h"
#include "../src/mymap.h"

TEST(mymap, Calculate) {
    mymap<int, string> t1;
    for (int i = 0; i < 10; i++) {
        t1.put(i, "a");
    }
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(t1[i], "A");
    }
    for (int i = 10; i < 20; i++) {
        EXPECT_FALSE(t1.contains(i));
    }
}