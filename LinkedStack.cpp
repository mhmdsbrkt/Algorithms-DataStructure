#include <iostream>

using namespace std;
struct student{
    int id;
    student *next;
};

class linked_stack{
private:
    student *top;
    int counter;
public:
    linked_stack() {
        top=NULL;
        counter=0;
    }

    void push (int num){
        student *temp;
        temp=new student;
        temp->id= num;
        temp->next=top;
        top= temp;
        counter++;
    }

    int pop (void){
        student *temp;
        int num;
        temp=top;
        num = top->id;
        top=top->next;
        delete temp;
        counter--;
        return num;
    }

    int getSize(void){
        return counter;
    }

    bool isEmpty(void){
        if (counter==0){
            return true;
        } else {
            return false;
        }
    }

    int peek (void){
        return top->id;
    }
};
int main() {
    int k;
    linked_stack odd;
    linked_stack even;

    for (k=1; k<=10;k++){
        if (k%2==0){
            even.push(k);
        } else {
            odd.push(k);
        }
    }

    cout << "Odd Peek " << odd.peek()<<endl;
    cout << "ODD NUMBERS" << endl;
    while (odd.isEmpty()== false){
        cout << odd.pop()<<"\t" ;

    }

    cout << "\n\nEven Peek " << even.peek()<<endl;
    cout << "EVEN NUMBERS" << endl;
    while (even.isEmpty()== false){
        cout << even.pop()<<"\t" ;

    }
    return 0;
}
