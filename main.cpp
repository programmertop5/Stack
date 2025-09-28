#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    Stack<int> stack(2);

    cout << "--- Pushing elements into the stack ---" << endl;
    for (int i = 1; i <= 5; i++) {
        cout << "Pushing " << i << "..." << endl;
        stack.push(i);
        cout << "Current stack: ";
        stack.print();
        cout << endl;
    }

    cout << "----- Stack Information ----" << endl;
    cout << "Top element: " << stack.top() << endl;
    cout << "Number of elements: " << stack.size() << endl;

    if (stack.empty()) {
        cout << "Is the stack empty? Yes" << endl;
    }
    else {
        cout << "Is the stack empty? No" << endl;
    }

    cout << "\n --- Popping elements from the stack  --- " << endl;
    while (!stack.empty()) {
        cout << "Top element: " << stack.top() << endl;
        stack.pop();
        cout << "Stack after pop: ";
        stack.print();
        cout << endl;
    }

    cout << "The stack is now empty!" << endl;

    return 0;
}
