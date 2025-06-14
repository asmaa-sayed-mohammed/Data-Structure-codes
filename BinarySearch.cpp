
#include <iostream>
#include <queue>
using namespace std;

//// playlists to study and understand the tree:

/*
 * Adel Naseem --> Arabic there is some videos without coding
 * Hard-code -->Arabic with trace the code
 * mycodeschool --> English without trace the code
 */

//// Introduction to Binary tree

/*the basic difference between BT and GT :
 * BT must have at most 2 children for each node but GT can have any number of children for each node
 */
//=============================================================================================================

//// complete binary tree:
/*
 * all levels except the last level are completely filled and all nodes are left as possible
 * -------------------------------------------------------------------------------------------------
 * if we start leve as 0, 1, 2 , ... :
 * we can say that max number of nodes in each level is 2*i (i is the number of level)
 * -------------------------------------------------------------------------------------------------
 * but if we start number of levels as 1, 2, 3, 4, ...
 * so we can say that the max number of nodes in level is 2*(i - 1)
 * --------------------------------------------------------------------------------------------------------
 * if we have n as a number of node so we can say that the height of tree is:
 * floor(log n to base 2)
 */
//=============================================================================================================

//// Perfect binary tree:
/*
 * all levels in the tree are completely full no exception for the last level
 * ----------------------------------------------------------------------------
 * max number of nodes in the tree(height of the tree = h):
 * = 2*0 + 2*1 + 2*2 + 2*3 +....... + 2*h
 * = (2*(h+1)) - 1
 * or:
 * = 2*1 + 2*2 + 2*3 + 2*4 +..............+ 2*h
 * = (2*h) - 1
 */

/// Binary Search Tree
/*
 * all nodes in left subtree must be less than the root and all elements in right subtree must be greater than the root.
 * ---------------------------------------------------------------------------------------------------------------------
 * complexity of search, insertion and deletion:
 * ---------------------------------------------
 * in average case (the tree is balanced):
 * insertion, deletion and search: o(log n to base 2)
 * --------------------------------
 * in worst case(each node has only one child it will be like the linked list):
 * insertion, deletion and search: o(n)
 */
//====================================================================================================================
//// implementation of BST
//---------------------------

struct Node {
    int data;
    Node *left;
    Node *right;
};

class BST_Operations {
public:
    // create the root to access the tree
     Node *root = nullptr;
        queue<Node*> q;
    void insertion(int data) {
        // create a new node and let data = data from function and left, right = null
        Node *newNode = new Node();
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        // create a new pointer to trace on tree
        Node *current = root;
        // if tree is empty (root = null) let root = newNode
        if (root == nullptr) {
            root = newNode;
        }else {
            //loop through the tree until you find a true position
            while (true) {
                // if data < current value and there is no left child let the left child = new node
                if (current -> left == nullptr && data < current -> data) {
                    current->left = newNode;
                    break;
                }
                // if data > current value and there is no right child let the right child = new node
                else if (current -> right == nullptr && data > current -> data) {
                    current->right = newNode;
                    break;
                }
                // if the data < current data and there is a left child update the current pointer to be the left child
                else if (current -> left != nullptr && data < current -> data) {
                    current = current -> left;
                }
                // if the data > current data and there is a right child update the current pointer to be the right child
                else if (current -> right != nullptr && data > current -> data) {
                    current = current -> right;
                }
            }
        }
    }
    ///find the maximum node in binary search tree
    // the maximum node will be in the right as far as possible
    Node *maxNode(Node *node) {
        node = root;
        while (node != nullptr) {
            node = node -> right;
        }
        return node;
    }
    ///find the minimum node in binary search tree
    // the minimum node will be in the left as far as possible
    void minNode(Node *node) {
        node = root;
        while (node != nullptr) {
            node = node -> left;
        }
        cout << node -> data;
    }
    /// find the height of tree
    // the height is the most depth of node we can calculate it as the maximum between the left and right subtree + 1
    int findHeight(Node *node) {
        if (node == nullptr) {
            return -1;
        }else {
            int left = findHeight(node->left);
           int right = findHeight(node->right);
            return max(left, right) + 1;
        }
    }
    /// traverse the tree
    // breadth-first (print each level)
    void breadthFirst(Node *root) {
        if (root == nullptr) {
            cout << "Empty Tree";
        }else {
            q.push(root);
            Node *current = root;
            while (!q.empty()) {
                current = q.front();
                cout << current -> data;// to count the number of nodes you can make a variable which increase after each print
                q.pop();
                if (current -> left != nullptr) {
                    q.push(current -> left);
                }
                if (current -> right != nullptr) {
                    q.push(current -> right);
                }
            }
        }
    }

    // inorder(left -> visit -> right)
    void inorder(Node *root) {
        inorder(root->left);
        cout << root -> data;
        inorder(root->right);
    }

    // preorder(visit -> left -> right)
    void preorder(Node *root) {
        cout << root -> data;
        preorder(root->left);
        preorder(root->right);
    }

    // post order(left -> right -> visit)
    void postorder(Node *node) {
        postorder(node->left);
        postorder(node->right);
        cout << node -> data;
    }

    //// search for node using its value
    // using breadth-first
    Node* search(int value, Node* root) {
        while (!q.empty()) {
            q.pop();
        }
        if (root == nullptr) {
            cout << "Empty Tree";
        }else {
            q.push(root);
            Node *current = root;
            while (!q.empty()) {
                current = q.front();
                if (current -> data == value) {
                    cout << current -> data;
                    return current;
                    break;
                }else {
                    q.pop();
                    if (current -> left != nullptr) {
                        q.push(current -> left);
                    }
                    if (current -> right != nullptr) {
                        q.push(current -> right);
                    }
                }
            }
        }
    }

    //// delete node from the tree using its value

    /* to find the explanation of this code you can go to hard-code playlist
     *to find explanation of the logic of deletion you can visit Adel naseem or mycodeschool playlistz
     * you can use findMin in right part (successor) instead of predecessor
     */
    Node *deleteNode(int value, Node *root) {
        if (root == nullptr) {
            cout << "Empty Tree";
        }
        else if (value < root -> data) {
            root->left = deleteNode(value, root->left);
        }
        else if (value > root -> data) {
            root->right = deleteNode(value, root->right);
        }
        else {
            if (root -> left == nullptr && root -> right == nullptr) {
                delete root;
                root = nullptr;
            }
            else if (root -> right == nullptr) {
                Node *temp = root->left;
                delete root;
                return temp;
            }else if (root -> left == nullptr) {
                Node *temp = root->right;
                delete root;
                return temp;
            }else {
                Node *predecessor = maxNode(root -> left);
                root->data = predecessor -> data;
                root->left = deleteNode(predecessor -> data, root->left);
            }
        }
        return root;
    }
};
