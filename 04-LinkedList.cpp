/*
 * STACK as Linked List push(addfirst), pop (deleteFirst), clear, Peek, isEmpty, getSize
 * QUEUE as Linked list
 * Compare Array And LinkedList
 * Access : Random direct Access
 * */
#include <iostream>

using namespace std;

struct student {
    int id;
    float GPA;
    char gender;
    student *next;
};

class linkedList {
private:
    student *first;
    student *last;
    int counter1;
    char counter2;

public:
    linkedList() {
        first = NULL, last = NULL;
    }

    student *read(void);

    void printAll(void);

    void addFirst();

    void addLast();

    void addIndex();

    void addSorted();

    void searchID();

    void deleteFirst(void);

    void deleteLast(void);

    void deleteIndex();

    void deleteID();

};

int main() {


    return 0;
}

student *linkedList::read(void) {

    student *kk;
    kk = new student;

    cout << "Enter Student ID " << endl;
    cin >> kk->id;
    cout << "Enter Student GPA " << endl;
    cin >> kk->GPA;
    cout << "Enter Student Gender " << endl;
    cin >> kk->gender;

    kk->next = NULL;
    return kk;
}

void linkedList::printAll(void) {

}

void linkedList::addFirst() {
    student *temp;
    temp = read();
    temp->next = first;
    first = temp;
}

void linkedList::addLast() {
    student *temp;

    if (first = NULL) {
        addFirst();
    } else {
        temp = first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = read();
    }
}

void linkedList::addIndex() {

}

void linkedList::addSorted() {

}

void linkedList::searchID() {

}

void linkedList::deleteFirst(void) {
    student *temp;
    if (first == NULL) { return; }
    temp = first;
    first = first->next;
    delete (temp);
}

void linkedList::deleteLast(void) {
    student *temp;
    if (first == NULL) { return; }
    else if (first->next == NULL) {
        deleteFirst();
        first = NULL;
    } else {
        temp = first;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete (temp->next);
        temp->next = NULL;
    }

}

void linkedList::deleteIndex() {
    student *temp, *temp2;
    int index;
    cout << "Enter Index" << endl;
    temp2 = first;
    if ((temp2 == NULL) || (index <= 1)) {
        return;
    }
    else {
        for (int k = 1; (k < index - 1) && (temp2->next != NULL); k++) {
            temp2 = temp2->next;
            temp = temp2->next;
            temp2->next = temp2->next->next;
            delete temp;
        }

    }

}

void linkedList::deleteID() {
    int ID;
    cout << "Enter ID "<<endl;
    cin >> ID;

    if(first->id==ID){deleteFirst();}
    else{
        student *temp1, *temp2;

    }


}
