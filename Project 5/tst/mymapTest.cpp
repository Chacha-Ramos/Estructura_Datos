// File that tests thoroughly each function from
// the header file mymap
// Each test case has their description and
// what functions or functionalities are 
// checking
#include "gtest/gtest.h"
#include "../src/mymap.h"

// Test case1
// Check put, get, Size, [] and contains
TEST(mymap, case1) {
    mymap<int, int> m;
    int key, value;
    map <int, int> m1;
    vector<int> keys;
    srand(time(NULL));
    // First check for unique keys
    for(int i=0; i<1000; i++) {
        do  {
            key = rand()%1000;
            value = rand()%1000;
            // Check unique keys
        } while ((m.contains(key)));
        m.put(key, value);
        m1[key] = value;
        keys.push_back(key);
        // Check size
        EXPECT_EQ(i+1, m.Size());
    }
    // Check that normal map has the same values
    // as mymap using [], get and contains
    for(int i=0; i<1000; i++) {
       EXPECT_EQ(m1[keys.at(i)], m[keys.at(i)]);
       EXPECT_EQ(m1[keys.at(i)], m.get(keys.at(i)));
       EXPECT_TRUE(m.contains(keys.at(i)));
    }

    // Keys that do not exist
    m1.clear();
    m.clear();
    keys.clear();
    for(int i=0; i<100; i++) {
        do  {
            key = rand()%1000;
            value = rand()%1000;
            //  Unique keys
        } while ((m.contains(key)));
        m.put(key, value);
        m1[key] = value;
        keys.push_back(key);
        // Check size of map
        EXPECT_EQ(i+1, m.Size());
    }
    // Check that keys do not exist using contains,
    // and []
    for(int i=0; i<100; i++) {
        EXPECT_FALSE(m.contains((i+1)*-1));
        EXPECT_EQ(0, m[(i+1)*-1]);
    }

    // Duplicate keys
    m1.clear();
    m.clear();
    keys.clear();
    vector<int> values;
    for(int i=0; i<100; i++) {
        // Make sure that the keys are duplicates
        key = (i+1)%10;
        value = rand()%1000;
        m.put(key, value);
        m1[key] = value;
        // Check that the values are being updated
        // if the keys are duplicates
        // using [], get and contains
        EXPECT_EQ(m1[key], m[key]);
        EXPECT_EQ(value, m1[key]);
        EXPECT_EQ(m1[key], m.get(key));
        EXPECT_TRUE(m.contains(key));
    }
}

// Test case2
// Check foreach, begin(), order is correct
TEST(mymap, case2) {
    mymap<int, int> test;
    map<int, int> correct;
    int firstKey, firstValue;
    srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        // randomize key and val
        int k = rand()%1000;
        int v = rand()%1000;
        if (i==0) {
            firstKey = k;
            firstValue = v;
        }
        test.put(k, v);
        correct[k] = v;
    }
    stringstream ss;
    // Check for each is working properly
    for (int key : test) {
        // Creates stringstream to compare in
        // the future tostring()
        ss << "key: " << key <<" value: " << test[key] << endl;
    }
    // Check tostring() is functioning
    ASSERT_EQ(test.toString(), ss.str());
}

// Test case3
// Check equal operator, size, tostring,
// tovector, ==
TEST(mymap, case3) {
    mymap<int, int> m;
    int key, value;
    map <int, int> m1;
    vector<int> keys;
    srand(time(NULL));
    for(int i=0; i<1000; i++) {
        do  {
            key = rand()%1000;
            value = rand()%1000;
            // Unique keys
        } while ((m.contains(key)));
        m.put(key, value);
        m1[key] = value;
        keys.push_back(key);
        EXPECT_EQ(i+1, m.Size());
    }

    stringstream ss;
    // Check for each works properly
    for (int key : m) {
        // Builds stringstream to check tostring()
        ss << "key: " << key <<" value: " << m[key] << endl;
    }
    ASSERT_EQ(m.toString(), ss.str());

    // To vector
    m.clear();
    vector<pair<int,int>> v;
    int arr [100];
    for (int i=0;i<100;i++) {
        arr[i] = i;
        m.put(arr[i], arr[i]);
        // Creates vector to compare with toVector()
        v.emplace_back(i,i);
    }
    // Checks that both vectors are equal
    ASSERT_EQ(m.toVector(), v);
    m.clear();
    v.clear();
    // Builds vector but now backwards
    for (int i=99;i>=0;i--) {
        arr[i] = i;
        // inserting i as value, therefore each key
        // has a unique value too
        m.put(arr[i], arr[i]);
        v.emplace_back(99-i,99-i);
    }
    // Check that both vectors are the same
    ASSERT_EQ(m.toVector(), v);

    // Check ==
    for (int i=0;i<99;i++) {
        // Since they have unique incrementing values
        // then i != i+1
        EXPECT_FALSE(m[i]==m[i+1]);
    }
}

// Helper function to test copy constructor
void copyConstructor(mymap<int, int> other, mymap<int, int> &curr){
    curr = other;
}

// Test case4
// Check clear, size, toString, tovector,
// Copy operator, copy constructor
TEST(mymap, case4) {
    mymap<int, int> m;
    int key, value;
    map <int, int> m1;
    vector<int> keys;
    srand(time(NULL));
    for(int i=0; i<1000; i++) {
        do  {
            key = rand()%1000;
            value = rand()%1000;
            // Unique keys
        } while ((m.contains(key)));
        m.put(key, value);
        m1[key] = value;
        keys.push_back(key);
        // Check size
        EXPECT_EQ(i+1, m.Size());
    }

    stringstream ss;
    // Check for each
    for (int key : m) {
        // Builds stringstream to check tostring()
        ss << "key: " << key <<" value: " << m[key] << endl;
    }
    ASSERT_EQ(m.toString(), ss.str());

    // To vector
    m.clear();
    vector<pair<int,int>> v;
    int arr [100];
    for (int i=0;i<100;i++) {
        arr[i] = i;
        m.put(arr[i], arr[i]);
        v.emplace_back(i,i);
    }
    ASSERT_EQ(m.toVector(), v);
    m.clear();
    v.clear();
    for (int i=99;i>=0;i--) {
        arr[i] = i;
        m.put(arr[i], arr[i]);
        v.emplace_back(99-i,99-i);
    }
    ASSERT_EQ(m.toVector(), v);

    // Check ==
    for (int i=0;i<99;i++) {
        EXPECT_FALSE(m[i]==m[i+1]);
    }
    // Copy operator
    mymap<int, int> m2 = m;
    // Both maps should have the same size
    EXPECT_EQ(m2.Size(), m.Size());
    // Check that m2 has the same keys as in m
    for (int e: m2) {
        EXPECT_TRUE(m.contains(e));
    }
    // Check that m2 has the same keys and values
    for (int i=99;i>=0;i--) {
        EXPECT_EQ(m2.get(i), m[i]);
    }
    // Clear maps
    m2.clear();
    // Check that the size is 0
    EXPECT_EQ(m2.Size(), 0);
    // Check copy Constructor using a function
    copyConstructor(m, m2);
    // Both maps should have the same size
    EXPECT_EQ(m2.Size(), m.Size());
    // Check that m2 has the same keys
    for (int e: m2) {
        EXPECT_TRUE(m.contains(e));
    }
    // Check that m2 has the same values and keys
    for (int i=99;i>=0;i--) {
        EXPECT_EQ(m2.get(i), m[i]);
    }
}

// Test case5 to check rebalance function
// NOTE: Rebalance function is not done
// So there is nothing to check here
TEST(mymap, case5) {
    mymap<int, int> m;
    for (int i=0; i < 3; i++) {
        m.put(i, i);
    }
    cout << m.checkBalance() << endl;
    m.clear();
    for (int i=0; i < 10; i++) {
        m.put(i, i);
    }
    cout << m.checkBalance() << endl;
}