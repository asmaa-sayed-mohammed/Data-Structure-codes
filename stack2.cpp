#include<iostream>
using namespace std;

class stackUsingArray {
    public:
    int *arr;
    int length;
    int maxSize = 100;
    stackUsingArray() {
        arr = new int[maxSize];
        length = 0;
    }
    ~stackUsingArray() {
        delete[] arr;
        length = 0;
    }
    void clear() {
        delete[] arr;
        arr = new int[maxSize];
        length = 0;
    }
    bool isEmpty() {
        return length == 0;
    }
    void push(int value) {
        if (length >= maxSize) {
            cout << "Stack is full\n";
        }else {
            arr[length] = value;
            length++;
        }
    }
    int pop() {
        if (length == 0) {
            cout << "Stack is empty\n";
        }else {
            length--;
            return arr[length - 1];
        }
    }
    int top() {
        if (length == 0) {
            cout << "Stack is empty\n";
        }else {
            return arr[length - 1];
        }
    }

};

template<typename T>
struct node {
    T data;
    node *next;
};

template<typename T>
class stackUsingLinkedList {
    node<T> *head;
    int length;

    public:

    stackUsingLinkedList() {
        head = nullptr;
        length = 0;
    }

    ~stackUsingLinkedList() {
        clear();
    }

    void push(int value) {
        node<T> *newNode = new node<T>();
        newNode -> data = value;
        newNode -> next = nullptr;
        if (head == nullptr) {
            head = newNode;
        }else {
            newNode -> next = head;
            head = newNode;
        }
        length++;
    }

    T pop() {
        int deleted;
        if (length == 0) {
            cout << "Stack is empty\n";
            return 0;
        }else {
            T *temp = head;
            deleted = temp -> data;
            head = head -> next;
            delete temp;
            length--;
        }
        return deleted;
    }

    bool isEmpty() {
        if (length == 0) {
            return true;
        }else {
            return false;
        }
    }

    T top() {
        if (length == 0) {
            cout << "Stack is empty\n";
            return 0;
        }else {
            return head->data;
        }
    }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }
};

template<typename T>
class stackOperations : stackUsingLinkedList<T> {
    stackUsingLinkedList<char> s1;

    public:

    void bracketDelimiters(string sentence) {
        int length = sentence.length();
        for (int i = 0; i < length; i++) {
            if (sentence[i] == '(' || sentence[i] == '{' || sentence[i] == '[' || sentence[i] == '"' ) {
                s1.push(sentence[i]);
            }if (sentence[i] == '/') {
                if (sentence[i+1] == '*') {
                    s1.push('/');
                    s1.push('*');
                    i++;
                }else if (sentence[i+1] == '/') {
                    continue;
                }
            }
            if (sentence[i] == ')' ) {
                char ch = s1.top();
                if (ch == '(') {
                    s1.pop();
                }else {
                    cout << "failed.\n";
                    break;
                }
            }else if (sentence[i] == '}') {
                char ch = s1.top();
                if (ch == '{') {
                    s1.pop();
                }else {
                    cout << "failed.\n";
                    break;
                }
            }else if (sentence[i] == ']') {
                char ch = s1.top();
                if (ch == '[') {
                    s1.pop();
                }else {
                    cout << "failed.\n";
                    break;
                }
            }else if (sentence[i] == '"') {
                char ch = s1.top();
                if (ch == '"') {
                    s1.pop();
                }else {
                    cout << "failed.\n";
                    break;
                }
            }else if (sentence[i] == '*' && i + 1 < length && sentence[i+1] == '/') {
                char ch = s1.top();
                if (ch == '*') {
                    s1.pop();
                }else {
                    cout << "failed.\n";
                    break;
                }
                ch = s1.top();
                if (ch == '/') {
                    s1.pop();
                }else {
                    cout << "failed.\n";
                    break;
                }

            }
        }
    }

    string sumBigIntegers(string num1, string num2) {
        stackUsingLinkedList<int> s1, s2, result;
        string sum = 0;
        for (char ch : num1) {
            s1.push(ch - '0');
        }
        for (char ch : num2) {
            s2.push(ch - '0');
        }

        int carry = 0;
        while (!s1.isEmpty() || !s2.isEmpty() || carry != 0) {
            int dig1 = 0;
            int dig2 = 0;

            if (!s1.isEmpty()) {
                dig1 = s1.top();
                s1.pop();
            }if (!s2.isEmpty()) {
                dig2 = s2.top();
                s2.pop();
            }
            int total = dig1 + dig2 + carry;
            result.push(total % 10);
            carry = total / 10;
        }
        while (!result.isEmpty()) {

            sum += (result.top() + '0');
            result.pop();
        }
        return sum;
    }

    void evaluatePostfix(string s) {
        stackUsingLinkedList<int> s1;
        int dig1, dig2;
        for (char ch : s) {
            if (isdigit(ch)) {
                s1.push(ch - '0');
            }else if (ch == '+') {
                dig1 = s1.top();
                s1.pop();
                dig2 = s1.top();
                s1.pop();
                s1.push(dig2 + dig1);
            }else if (ch == '-') {
                dig1 = s1.top();
                s1.pop();
                dig2 = s1.top();
                s1.pop();
                s1.push(dig2 - dig1);
            }else if (ch == '*') {
                dig1 = s1.top();
                s1.pop();
                dig2 = s1.top();
                s1.pop();
                s1.push(dig2 * dig1);
            }else if (ch == '/') {
                dig1 = s1.top();
                s1.pop();
                dig2 = s1.top();
                s1.pop();
                s1.push(dig2 / dig1);
            }
        }
        int sum = s1.top();
        s1.pop();
        cout << sum << endl;
    }

    int precedences(char ch) {
        int precedence;
        if (ch == '*' || ch == '/') {
           precedence = 2; // Higher precedence
        }else if (ch == '+' || ch == '-') {
            precedence = 1; // Lower precedence
        }else {
            precedence = 0; // Not an operator
        }
        return precedence;
    }

    void infixToPostfix(string infix, stackUsingLinkedList<char> &s1) {
        string postfix = "";
        for (int i = 0; i < infix.length(); i++) {
            char ch = infix[i];
            // If it's a letter or number, add it directly to the postfix expression
            if (isalnum(ch)) {
                postfix += ch;
            }
            // Ignore spaces
            else if (ch == ' ') {
                continue;
            }
            else if (ch == '(') {
                s1.push(ch);
            }else if (ch == ')') {
                // Pop from stack to postfix until an opening bracket is found
                while (!s1.isEmpty() && s1.top() != '(') {
                    postfix += s1.top();
                    s1.pop();
                }
                s1.pop(); // to remove "("
            }
            else if (ch == '*' || ch == '/' || ch == '+' || ch == '-') {
                // If stack is empty, just push the operator
                if (s1.isEmpty()) {
                    s1.push(ch);
                }
                // If the top of stack has lower precedence, push current operator
                else {
                    if (precedences(s1.top()) < precedences(ch)) {
                        s1.push(ch);
                    }
                    // If top of stack has higher or equal precedence
                    else if (precedences(s1.top()) >= precedences(ch)) {
                        // Pop all higher or equal precedence operators from stack to postfix
                        while (!s1.isEmpty() && precedences(s1.top()) >= precedences(ch)) {
                            postfix += s1.top();
                            s1.pop();
                        }
                        // Push the current operator to the stack
                        s1.push(ch);
                    }
                }
            }
        }
        // After reading the whole infix expression,
        // pop any remaining operators from the stack to the postfix expression
        while (!s1.isEmpty()) {
            postfix += s1.top();
            s1.pop();
        }
    }

};