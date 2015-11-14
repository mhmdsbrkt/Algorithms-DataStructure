using namespace std;
#include <iostream>

struct node {
    struct node *left, *right;
    int data;
};

class binary_search_tree {
private:
    struct node *root;
    int counter;
public:
    binary_search_tree() {
        root = NULL;
        counter = 0;
    }

    void insert_node(int num) {
        struct node *ptr;
        if (root == NULL) {
            root = new node;
            root->data = num;
            root->left = NULL;
            root->right = NULL;
        }
        else {
            ptr = root;
            if ((num < ptr->data) && (ptr->left != NULL)) ptr = ptr->left;
            else if (num > ptr->data) && (ptr->right != NULL)) ptr = ptr->right;
        }

    }

    bool search(int num) {

    }

    void delete_node(int num) {

    }

    void print_BFS(void) {

    }

    void print_DFS_inorder(void) {

    }

    void print_DFS_preorder(void) {

    }

    void print_DFS_postorder(void) {

    }

    int get_counter(void) {
        return counter;
    }

    void deleteTree(void) {

    }
};


