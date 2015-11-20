#include <iostream>

using namespace std;

class Stack {
private:
    node **arr;
    int top, size;
public:
    Stack(int cSize) {
        size = cSize;
        top = 0;
        arr = new node *[size];
    }

    Stack(void) {
        size = 30;
        top = 0;
        arr = new node *[size];
    }

    bool isfull(void) { return (top == size); }

    bool isempty() { return (top == 0); }

    void push(node *addr) {
        arr[top] = addr;
        top++;
    }

    node *pop(void) {
        top--;
        return arr[top];
    }

    node *peak(void) { return arr[top - 1]; }

    int stack_max_size(void) { return size; }

    int number_of_elements(void) { return top; }

    void clear_stack(void) { top = 0; }
};

class Queue {
private:
    node **arr;
    int front, rear, size;
public:
    Queue(int cSize) {
        size = cSize;
        front = 0;
        rear = 0;
        arr = new node *[size];
    }

    Queue(void) {
        size = 30;
        front = 0;
        rear = 0;
        arr = new node *[size];
    }

    bool isfull(void) { return ((rear + 1) % size == front); }

    bool isempty() { return (front == rear); }

    void enque(node *addr) {
        arr[rear] = addr;
        rear = (rear + 1) % size;
    }

    node *deque(void) {
        node *t;
        t = arr[front];
        front = (front + 1) % size;
        return t;
    }

    node *peak(void) { return arr[front]; }

    int queue_max_size(void) { return size; }

    int number_of_elements(void) { return (rear - front + size) % size; }

    void clear_queue(void) {
        front = 0;
        rear = 0;
    }
};


struct node {
    node *left;
    node *right;
    int data;
};

node *makeNewNode(int data) {
    node *newNode = new node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;

};

void insert(node *nodeAddress, int newData) {
    if (newData < nodeAddress->data) {
        if (nodeAddress->left != NULL) {
            insert(nodeAddress->left, newData);
        }
        else {
            nodeAddress->left = makeNewNode(newData);
        }
    }
    else if (newData > nodeAddress->data) {
        if (nodeAddress->right != NULL) {
            insert(nodeAddress->right, newData);
        }
        else {
            nodeAddress->right = makeNewNode(newData);
        }

    }
}

void printBFS(node *root) {
    if (root == NULL) {
        cout << "Empty";
        return;
    }
    Queue newQueue;
    newQueue.enqueue(root);
    while (!newQueue.isEmpty()) {
        root = newQueue.deque();
        cout << root->data << "\t";
        if (root->left != NULL) {
            newQueue.enqueue(root->left);
        }
        if (root->right != NULL) {
            newQueue.enqueue(root->right);
        }
    }

}

void printPreOrder(node *root) {

    if (root == NULL) {
        cout << "Empty Tree";
        return;
    }
    Stack myStack;
    myStack.push(root);
    while (!myStack.isEmpty()) {
        root = myStack.pop();
        cout << root->data << "\t";
        if (root->left != NULL) { myStack.push(root->left); }
        if (root->right != NULL) { myStack.push(root->right); }

    }

}


void printPreOrder2(node *root) {
    if (root == NULL) {
        cout << "Empty Tree";
        return;
    }
    cout << root->data << "\t";
    if (root->left != NULL) { printPreOrder2(root->left); }
    if (root->right != NULL) { printPreOrder2(root->right); }
}

void printPostOrder(node *root) {
    if (root == NULL) {
        cout << "Empty Tree";
        return;
    }
    if (root->left != NULL) { printPostOrder(root->left); }
    if (root->right != NULL) { printPostOrder(root->right); }
    cout << root->data << "\t";

}

void printInOrder(node *root) {
    if (root == NULL) {
        cout << "Empty Tree";
        return;
    }
    if (root->left != NULL) { printInOrder(root->left); }
    cout << root->data << "\t";
    if (root->right != NULL) { printInOrder(root->right); }
}

int search(node *dNode, int key) {
    if (dNode == NULL) {
        cout << "Empty Tree Not Founded";
        return 0;
    } else {
        if (key == dNode->data) {
            cout << key << " Founded";
            return 1;
        } else if (key < dNode->data) {
            return search(dNode->left, key);

        } else {
            return search(dNode->right, key);

        }

    }


}

int main() {
    node *root;
    root = makeNewNode(5);
    insert(root, 3);
    insert(root, 8);
    insert(root, 4);
    insert(root, 3);
    insert(root, 7);
    insert(root, 9);
    insert(root, 1);
    insert(root, 2);

    return 0;
}
