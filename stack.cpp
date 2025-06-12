#include <iostream>
#include <vector>
using namespace std;
template<typename T>

//=======================================================================

class Stack_array {
private:
    T arr[100];
    // Last is the index of last element in the array
    // we initialize it with -1
    // the first index in stack has index 0 so is the index = -1 it's mean that the stack is empty
    int last = -1;
public:

    bool isEmpty() {
        if (last == -1) {
            return true;
        }
        else {
            return false;
        }
    }

    void push(T data) {
        last++;
        arr[last] = data;
    }

    void pop() {
        last--;
    }

    T top() {
        T top = arr[last];
        return top;
    }

    void clear() {
        last = -1;
        cout << "Stack cleared!\n";
    }

    void display() {
        for (int i = last; i >= 0; i--) {
           cout << arr[i] << " ";
        }
        cout << "\n";
    }

};

//=======================================================================

class Stack_linkedList {
    struct node {
        int data;
        node *next = NULL;
    };
    node *top = NULL;

    public:
    void push(int data) {
        node *newNode = new node;
        newNode->data = data;

        if (top == NULL) {
            top = newNode;
        }
        else {
            newNode->next = top;
            top = newNode;
        }
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
        }else {
            node *del = top;
            top = top->next;
            delete del;
        }
    }

    void clear() {
        while (top-> next != NULL) {
            pop();
        }
        cout << "Stack cleared!\n";
    }

    void peek() {
        int current = top->data;
        cout << current << "\n";
    }

    void isEmpty() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
        }else {
            cout << "Stack is not empty" << endl;
        }
    }
    void display() {
        node *print = top;
        while (print != NULL) {
            cout << print->data << " ";
            print = print->next;
        }
        cout << "\n";
    }
};

//=======================================================================

class Stack_vector {
    vector<int> arr;
    int size = -1;
    public:
    void push(int data) {
        arr.push_back(data);
        size++;
    }

    void pop() {
        arr.pop_back();
        size--;
    }

    void top() {
        int current = arr[0];
        cout << current << "\n";
    }

    void clear() {
        arr.clear();
        size = 0;
        cout << "Stack cleared!\n";
    }

    void isEmpty() {
        if (size == -1) {
            cout << "Stack is empty" << endl;
        }
        else {
            cout << "Stack is not empty" << endl;
        }
    }

    void display() {
        for (int i = size; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

//=======================================================================

class check_brackets {
    Stack_array<char> stack;
    string input = "(iam asmaa), {this is my name},";
public:
    void check() {
        for (char ch : input) {
          if (ch == '(' || ch == '{' || ch == '[') {
              stack.push(ch);
          }else if (ch == ')' || ch == '}' || ch == ']') {
              if (stack.isEmpty()) {
                  cout << "not balanced" << endl;
                  exit(0);
              }else {
                  char ch2 = stack.top();
                  if (
                      (ch2 == '(' && ch == ')') ||
                      (ch2 == '{' && ch == '}') ||
                      (ch2 == '[' && ch == ']')
                      ) {
                      stack.pop();
                  }else {
                      cout << "not balanced" << endl;
                      exit(0);
                  }
              }
          }
        }

        if (stack.isEmpty()) {
            cout << "Balanced\n";
        }
        else {
            cout << "not balanced\n";
        }
    }
};

//=======================================================================

class postfix {
    Stack_array<int> stack;
    string x = "3 4 4 * + 5 8 * 4 / - 3 +";
    public:
    void evaluate(){
        for (int i = 0; i < x.length(); i++) {
            char ch = x[i];
            if (ch == ' ') {
                continue;
            }else if (isdigit(ch)) {
                stack.push(ch - '0');
            }else if ((ch == '*') || (ch == '+') || (ch == '-') || (ch == '/')) {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                if (ch == '*') {
                    stack.push(a * b);
                }else if (ch == '+') {
                    stack.push(a + b);
                }else if (ch == '-') {
                    stack.push(a - b);
                }else if (ch == '/') {
                    stack.push(a / b);
                }
            }
        }
        cout << stack.top() << "\n";
    }
};

int main() {

    cout << 13 % 10;
    return 0;
}

//// Disadvantages fo implementing stack using array:

/*
  1 - you can't remove the element when you want to pop any element you can ignore it only, so it isn't an optimizing way for mrmory.
  2 - has a static size you can't change it
  3-  it's more possible to have overflow if you exceed the size of array
  4- not flexibility
*/

//// Disadvantage for implementing stack using vector

/*
  it uses more memory than array(but less memory than linked list)
*/

//// Disadvantage for implementing stack using single linked list

/*
 1 - it uses more memory than vector and array because of using pointers.
 2 - it wants more coding.
 3 - more difficult in implementing it.
*/

