#include "gtest/gtest.h"
#include "../src/mymap.h"

TEST(mymap, Milestone3) {
    mymap<int, int> test;
    map<int, int> correct;
    for(int i = 0; i < 10000; i++) {
        // randomize key and val
        int k = rand()%10000;
        int v = rand()%10000;
        test.put(k, v);
        correct[k] = v;
    }
    stringstream ss;
    for (int key : test) {
        // it does work like this
        ss << "key: " << key << " value: " << test[key] << endl;
    }
    // loop should be in order
    ASSERT_EQ(test.toString(), ss.str());
}

TEST(mymap, Milestone4){
    // Clear
    mymap<int,int> m;
    for (int i=0;i<3;i++) {
        int x = rand()%1000;
        m.put(x, x);
        EXPECT_NE(m.Size(), 0);
    }
    m.clear();
    ASSERT_EQ(m.Size(), 0);

    // Copy
    mymap<int,int> m1;
    for (int i=0;i<5;i++) {
        int x = rand()%1000;
        m1.put(x, x);
    }
    mymap<int,int> m2 = m1;
    ASSERT_EQ(m2.Size(), m1.Size());
    ASSERT_EQ(m2.toString(), m1.toString());
}