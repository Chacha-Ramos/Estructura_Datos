// mymap.h
// Author: Salvador Tranquilino-Ramos
// Header file that creates the implementation of a map
// using threaded self-balanced binary search trees
#pragma once

#include <iostream>
#include <sstream>

using namespace std;

template<typename keyType, typename valueType>
class mymap {
 private:
    struct NODE {
        keyType key;  // used to build BST
        valueType value;  // stored data for the map
        NODE* left;  // links to left child
        NODE* right;  // links to right child
        int nL;  // number of nodes in left subtree
        int nR;  // number of nodes in right subtree
        bool isThreaded;
    };
    NODE* root;  // pointer to root node of the BST
    int size;  // # of key/value pairs in the mymap

    //
    // iterator:
    // This iterator is used so that mymap will work with a foreach loop.
    //
    struct iterator {
     private:
        NODE* curr;  // points to current in-order node for begin/end

     public:
        iterator(NODE* node) {
            curr = node;
        }

        keyType operator *() {
            return curr -> key;
        }

        bool operator ==(const iterator& rhs) {
            return curr == rhs.curr;
        }

        bool operator !=(const iterator& rhs) {
            return curr != rhs.curr;
        }

        bool isDefault() {
            return !curr;
        }

        //
        // operator++:
        //
        // This function should advance curr to the next in-order node.
        // O(logN)
        //
        iterator operator++() {
            if (curr->isThreaded) {
                curr = curr->right;
            } else {
                curr = curr->right;
                while (curr->left != nullptr) {
                    curr = curr->left;
                }
            }
            return iterator(curr);
        }
    };

 public:
    //
    // default constructor:
    //
    // Creates an empty mymap.
    // Time complexity: O(1)
    //
    mymap() {
        // sets root to null
        root = nullptr;
        // Size to 0
        size = 0;
    }

    //
    // copy constructor:
    //
    // Constructs a new mymap which is a copy of the "other" mymap.
    // Sets all member variables appropriately.
    // Time complexity: O(nlogn), where n is total number of nodes in threaded,
    // self-balancing BST.
    //
    mymap(const mymap& other) {
        // Creates the root node
        root = new NODE;
        root->key = other.root->key;
        root->value = other.root->value;
        root->isThreaded = other.root->isThreaded;
        root->left = nullptr;
        root->right = nullptr;
        size = 1;
        // Then copies everything else
        _copyTree(other.root);
    }

    // Receives the root other root node
    void _copyTree(NODE * otherNode) {
        // Since is recursive, the base case is
        // when the current node is null
        if(otherNode != nullptr){
            // Insert every node to root in preorder traversal
            this->put(otherNode->key, otherNode->value);
            if (otherNode->left != nullptr) {
                _copyTree(otherNode->left);
            }
            // If is not threaded to prevent infinite loops
            if (!otherNode->isThreaded) {
                if (otherNode->right != nullptr) {
                    _copyTree(otherNode->right);
                }
            }
        }
    }
    //
    // operator=:
    //
    // Clears "this" mymap and then makes a copy of the "other" mymap.
    // Sets all member variables appropriately.
    // Time complexity: O(nlogn), where n is total number of nodes in threaded,
    // self-balancing BST.
    //
    mymap& operator=(const mymap& other) {
        // if the map is not empty
        if (root != nullptr) {
            this->clear();
        }
        // Creates the root node
        root = new NODE;
        root->key = other.root->key;
        root->value = other.root->value;
        root->isThreaded = other.root->isThreaded;
        root->left = nullptr;
        root->right = nullptr;
        size = 1;
        // Copies everything else from other tree
        _copyTree(other.root);
        return *this;
    }
    // Helper recursive function that receives a root node
    // And deletes every node from the tree
    void _deleteTree(NODE * current) {
        // If the current node is not NULL
        if (current != nullptr) {
            // Get left and right node
            NODE * cLeft = current->left;
            NODE * cRight = (current->isThreaded) ? nullptr : current->right;
            // Recursive in post-order traversal
            _deleteTree(cLeft);
            _deleteTree(cRight);
            // If the current is not the root
            // then delete the node
            if (current != root) {
                delete current;
            }
        }
    }
    // clear:
    //
    // Frees the memory associated with the mymap; can be used for testing.
    // Time complexity: O(n), where n is total number of nodes in threaded,
    // self-balancing BST.
    //
    void clear() {
        if (root != nullptr) {
            // Delete every node except the root
            _deleteTree(root);
            // Then delete the root
            delete root;
            // and set it to nullptr
            root = nullptr;
        }
        // and set size to 0
        size = 0;
    }

    //
    // destructor:
    //
    // Frees the memory associated with the mymap.
    // Time complexity: O(n), where n is total number of nodes in threaded,
    // self-balancing BST.
    //
    ~mymap() {
        if (root != nullptr) {
            // Delete every node that is not the root
            _deleteTree(root);
            // Delete the root
            delete root;
            // And set it to NULL
            root = nullptr;
        }
    }

    //
    // put:
    //
    // Inserts the key/value into the threaded, self-balancing BST based on
    // the key.
    // Time complexity: O(logn + mlogm), where n is total number of nodes in the
    // threaded, self-balancing BST and m is the number of nodes in the
    // sub-tree that needs to be re-balanced.
    // Space complexity: O(1)
    //
    void put(keyType key, valueType value) {
        // base case when the tree is empty
        if (root == nullptr) {
            root = new NODE;
            root->key = key;
            root->value = value;
            root->left = nullptr;
            root->right = nullptr;
            root->nL = 0;
            root->nR = 0;
            root->isThreaded = true;
            size++;
        } else {
            // Helper variables
            NODE * prev;
            NODE * current = root;
            // While you dont reach the end
            while (current != nullptr) {
                // Store previous node
                prev = current;
                // Go to the left subtree
                if (key < current->key) {
                    current->nL++;
                    current = current->left;
                // Go to right subtree
                } else if (key > current->key) {
                    current->nR++;
                    current = (current->isThreaded) ? nullptr : current->right;
                // Else it means you found it
                } else {
                    // Update value with new value
                    current->value = value;
                    return;
                }
            }
            // Increase size since you are inserting
            // a new node
            size++;
            // Creates new node and sets variables to
            // default values
            current = new NODE;
            current->key = key;
            current->value = value;
            current->left = nullptr;
            current->nL = 0;
            current->nR = 0;
            current->isThreaded = true;
            // Check where in the tree is going to
            // be inserted
            if (key < prev->key) {
                // Move left and right pointers
                // to make it threaded
                current->right = prev;
                prev->left = current;
            } else {
                // Move left and right pointers
                // to make it threaded
                prev->isThreaded = false;
                current->right = prev->right;
                prev->right = current;
            }
        }
    }

    //
    // contains:
    // Returns true if the key is in mymap, return false if not.
    // Time complexity: O(logn), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    bool contains(keyType key) {
        NODE * current = root;
        // Until you reach the end
        while (current != nullptr) {
            // Go to the left subtree
            if (key < current->key) {
                current = current->left;
            // Go to right subtree
            } else if (key > current->key) {
                current = (current->isThreaded) ? nullptr : current->right;
            } else {
                // Else you found it, return true
                return true;
            }
        }
        // You did not find it, return false
        return false;
    }

    //
    // get:
    //
    // Returns the value for the given key; if the key is not found, the
    // default value, valueType(), is returned (but not added to mymap).
    // Time complexity: O(logn), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    valueType get(keyType key) {
        NODE * current = root;
        // Until you reach the end of the tree
        while (current != nullptr) {
            // Go to the left subtree
            if (key < current->key) {
                current = current->left;
            // Go to right subtree
            } else if (key > current->key) {
                current = (current->isThreaded) ? nullptr : current->right;
            } else {
                // Else you found it, return that value
                return current->value;
            }
        }
        // You did not find it, return default
        // valueType()
        return valueType();
    }

    //
    // operator[]:
    //
    // Returns the value for the given key; if the key is not found,
    // the default value, valueType(), is returned (and the resulting new
    // key/value pair is inserted into the map).
    // Time complexity: O(logn + mlogm), where n is total number of nodes in the
    // threaded, self-balancing BST and m is the number of nodes in the
    // sub-trees that need to be re-balanced.
    // Space complexity: O(1)
    //
    valueType operator[](keyType key) {
        valueType value = get(key);
        if (!contains(key)) {
            put(key, valueType());
            return valueType();
        }
        return value;
    }

    //
    // Size:
    //
    // Returns the # of key/value pairs in the mymap, 0 if empty.
    // O(1)
    //
    int Size() {
        return size;
    }

    //
    // begin:
    //
    // returns an iterator to the first in order NODE.
    // Time complexity: O(logn), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    iterator begin() {
        NODE * curr = root;
        // Go all the way to the left
        while (curr->left != nullptr) {
            curr = curr->left;
        }
        // Return the left most node iterator
        return iterator(curr);
    }

    //
    // end:
    //
    // returns an iterator to the last in order NODE.
    // this function is given to you.
    // 
    // Time Complexity: O(1)
    //
    iterator end() {
        return iterator(nullptr);
    }

    //
    // toString:
    //
    // Returns a string of the entire mymap, in order.
    // Format for 8/80, 15/150, 20/200:
    // "key: 8 value: 80\nkey: 15 value: 150\nkey: 20 value: 200\n
    // Time complexity: O(n), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    string toString() {
        stringstream ss;
        _buildString(root, ss);
        return (ss.str());
    }

    // Helper function that builds tree's string recursively
    void _buildString(NODE * current, ostream & out) {
        if (current != nullptr) {
            NODE * cLeft = current->left;
            NODE * cRight = (current->isThreaded) ? nullptr : current->right;
            // Traverses the tree recursively in-order
            _buildString(cLeft, out);
            // Prepares ostream with key and value
            out << "key: " << current->key << " value: " << current->value << endl;
            _buildString(cRight, out);
        }
    }

    // Helper function that builds a vector of
    // pairs recursively from the tree
    void _buildVector(NODE * current, vector <pair<keyType, valueType> > & out) {
        if (current != nullptr) {
            NODE * cLeft = current->left;
            NODE * cRight = (current->isThreaded) ? nullptr : current->right;
            // Traverses the tree recursively in-order
            _buildVector(cLeft, out);
            // Creates pair from current node
            pair<keyType, valueType> pairs;
            pairs.first = current->key;
            pairs.second = current->value;
            // Pushes back current pair to vector
            out.push_back(pairs);
            _buildVector(cRight, out);
        }
    }
    //
    // toVector:
    //
    // Returns a vector of the entire map, in order.  For 8/80, 15/150, 20/200:
    // {{8, 80}, {15, 150}, {20, 200}}
    // Time complexity: O(n), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    vector<pair<keyType, valueType> > toVector() {
        vector<pair<keyType, valueType> > tree;
        _buildVector(root, tree);
        return tree;
    }
    // Helper function that builds a vector of
    // NODE* recursively from the tree
    void _buildVectorNode(NODE * current, vector <NODE*> & out) {
        if (current != nullptr) {
            NODE * cLeft = current->left;
            NODE * cRight = (current->isThreaded) ? nullptr : current->right;
            // Traverses the tree recursively in-order
            _buildVectorNode(cLeft, out);
            // Pushes back current NODE* to vector
            out.push_back(current);
            _buildVectorNode(cRight, out);
        }
    }
    // Creates a vector of NODE* from the tree
    vector<NODE *> toVectorNode() {
        vector<NODE *> tree;
        // Call helper function
        _buildVectorNode(root, tree);
        return tree;
    }
    // Checks the balance using Seesaw formula
    void SeesawBalance (NODE * &current) {
        // Gets the left part of the formula
        int comparisonLeft = max(current->nL, current->nR);
        // Gets the right part of the formula
        int comparisonRight = (2*min(current->nL, current->nR)) +1;
        // Applies formula
        if (comparisonLeft > comparisonRight) {
            vector <NODE*> n;
            NODE * newNode;
            // Builds a vector of NODE*
            _buildVectorNode(current, n);
            // Calls helper function to rebalance tree
            newNode = _rebalance(n);
            current = newNode;
        }
    }
    // Creates an ostream with keys, nL and nR
    void _buildBalance(NODE * current, ostream & out) {
        if (current != nullptr) {
            // Check if the tree is balanced
            SeesawBalance(current);
            NODE * cLeft = current->left;
            NODE * cRight = (current->isThreaded) ? nullptr : current->right;
            out << "key: " << current->key << ", nL: " << current->nL << ", nR: " << current->nR << endl;
            // Traverses the tree recursively pre-order
            _buildBalance(cLeft, out);
            _buildBalance(cRight, out);
        }
    }
    //
    // checkBalance:
    //
    // Returns a string of mymap that verifies that the tree is properly
    // balanced.  For example, if keys: 1, 2, 3 are inserted in that order,
    // function should return a string in this format (in pre-order):
    // "key: 2, nL: 1, nR: 1\nkey: 1, nL: 0, nR: 0\nkey: 3, nL: 0, nR: 0\n";
    // Time complexity: O(n), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    string checkBalance() {
        stringstream ss;
        _buildBalance(root, ss);
        return (ss.str());
    }

    NODE* _buildRebalance(vector<NODE*> v, int leftRight, int ending, int &counter, bool threads) {
        if(leftRight == ending) {
            return nullptr;
        }
        NODE* merge;
        NODE* nLeft;
        NODE* nRight;
        int mid = (leftRight+ending)/2;
        merge = v[mid];
        merge->nL = 0;
        merge->nR = 0;
        merge->isThreaded = false;
        merge->left = nullptr;
        merge->right = nullptr;
        nLeft = _buildRebalance(v, leftRight, mid, counter, false);
        if(nLeft != nullptr) {
            merge->left = nLeft;
        }
        nRight = _buildRebalance(v, mid+1, ending, counter, true);
        if(nRight != nullptr) {
            merge->right = nRight;
        } else {
            merge->isThreaded = true;
            if (threads) {
                merge->right = v[leftRight-1];
            } else {
                merge->right = v[ending];
            }

        }
        return merge;
    }
    // Helper function that rebalances tree
    // NOTE: Function not complete
    // to be done in the far, far, far, far
    // far, far, far future
    NODE* _rebalance(vector <NODE*> v) {
        if (v.size() == 0 || v.size() == 1) {
            return nullptr;
        }
        int left = 0;
        int right = v.size();
        int mid = ((right-1) - left)/2;
        int counter = 0;
        NODE * cRoot = v[mid];
        cRoot->left = _buildRebalance(v, left, mid, counter, false);
        cRoot->right = _buildRebalance(v, mid+1, right, counter, true);

        // SABEEHA IS A BITCH -> also this is where you call the function to update the values of NL and NR
        // cRoot is the new subtree that is balanced, so only need to traverse and set nL and nR
        cRoot->nL = (cRoot->left->nL + cRoot->left->nR)+1;
        cRoot->nR = (cRoot->right->nL + cRoot->right->nR)+1;

        return cRoot;
    }

};
