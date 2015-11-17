#include <iostream>

using namespace std;

class stack {

private:
    int *arr;
    int size;
    int top;

public:
    //Declare CONSTRICTOR Function with Parameter
    stack(int cSize) {
        size = cSize;
        top = 0;
        arr = new int(size);
    }

    // CONSTRICTOR Overloading to set default Value
    stack(void) {
        size = 10;
        top = 0;
        arr = new int[size];
    }

    // Declare PUSH function
    void push(int data) {
        arr[top] = data;
        top++;
    }

    // Declare POP function
    int pop() {
        top--;
        return arr[top];

    }

    // Declare IS FULL function
    bool isFull() {
        // Check if Top = Size Stack is Full
        if (top >= size) {
            return true;
        } else {
            return false;
        }

    }

    // Declare IS EMPTY function
    bool isEmpty() {
        // Check if Top = 0 so Stack is Empty
        if (top <= 0) {
            return true;
        } else {
            return false;
        }

    }

    // Declare GET TOP Function
    int getTop() {
        return top;
    }

    // Declare Peak Function
    int peak() {
        return arr[top];
    }

    //Declare CLEAR Function
    void clear() {
        top = 0;
    }
};

class Queue {
private:
    int *pIntQueue;
    int size;
    int first;
    int last;
    int counter;

public:
    // CONSTRUCTOR
    Queue(int queSize) {
        size = queSize;
        first = last = counter = 0;
        pIntQueue = new int[size];
    }

    // CONSTRUCTOR With default value 10
    Queue(void) {
        size = 10;
        first = last = counter = 0;
        pIntQueue = new int[size];
    }

    // ENEQUE
    void enqueue(int data) {
        counter++;
        pIntQueue[last] = data;
        last = (last + 1) % size;
    }

    // DEQUE
    int deque(void) {
        int temp = pIntQueue[first];
        counter--;
        first = (first + 1) % size;
        return temp;

    }

    // IS FULL
    bool isFull(void) {
        if (counter == size) return true;
        else return false;

    }

    // IS Empty
    bool isEmpty(void) {
        if (counter == 0) return true;
        else return false;
    }

    // GET Counter
    bool getCount(void) {
        return counter;
    }

    // Get Front
    int getFront(void) {
        return pIntQueue[first];

    }

    // CLEAR
    void clear(void) {
        first = last = counter = 0;
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
    stack myStack;
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
