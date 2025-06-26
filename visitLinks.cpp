#include "stack_visitLinks_Application.cpp"
#include <iostream>
#include <fstream>

using namespace std;

class VisitLinks {
    StackLinkedlist BackStack; // for new links;
    StackLinkedlist FrontStack;// add previous link before deleting it
    string *arr;
    string currentUrl;
    int n;

    public:
    VisitLinks(string FileName) {
        cout << "Please insert the number of links that you want to visit: ";
        cin >> n;
        arr = new string[n];
        string fileName;
        ifstream file(FileName);
        if (!file.is_open()) {
            cout << "File could not be opened" << endl;
            exit(0);
        }
        int count = 0;
        bool isEmpty = true;

        while (file >> arr[count] && count < n) {
            isEmpty = false;
            count++;
        }
        file.close();

        if (isEmpty){
            cout << "The file is empty!" << endl;
            exit(0);
        }

        if (count < n) {
            cout << "The file contains " << count << " links, which is less than the " << n << " links you requested." << endl;
            n = count;
        }
    }
    void ReadUrl() {
        int count = 0;
        while (count < n) {
            if (!FrontStack.isEmpty()) {
                FrontStack.clear();
            }
           BackStack.push(arr[count]);
           currentUrl = arr[count];
           cout << "current Url: " << currentUrl << endl;
            cout << "Back Stack is [ ";
           BackStack.display();
            cout << "]\n";
            cout << "Front Stack is [ ";
            FrontStack.display();
            cout << "]" << endl;
            cout << endl;
           count++;

        }
    }

    void visitLinkManual(string url) {
        if (!FrontStack.isEmpty()) {
            FrontStack.clear();
        }
        BackStack.push(url);
        currentUrl = BackStack.peek();
        cout << " current Url: " << currentUrl << endl;
        cout << "Back Stack is [ ";
        BackStack.display();
        cout << "]\n";
    }

    void goBack() {
        if (BackStack.isEmpty()|| BackStack.StackSize() == 1) {
            cout << "There is no previous Url..\n";
        }else {
            FrontStack.push(currentUrl);
            BackStack.pop();
            currentUrl = BackStack.peek();
            cout << "current Url: " << currentUrl << endl;
            cout << "------------------------------------------------\n";
            cout << "Back Stack: [ ";
            BackStack.display();
            cout << " ]" << endl;
            cout << "-------------------------------------------------\n";
            cout << "Front Stack [ ";
            FrontStack.display();
            cout << " ]" << endl;
        }
    }

    void goFront() {
        if (FrontStack.isEmpty()) {
            cout << "You can't go forward.\n";
        }else {
            currentUrl = FrontStack.peek();
            FrontStack.pop();
            BackStack.push(currentUrl);
            cout << "current Url: " << currentUrl << endl;
            cout << "---------------------------------------------------\n";
            cout << "Back Stack: [ ";
            BackStack.display();
            cout << " ]" << endl;
            cout << "----------------------------------------------------\n";
            cout << "Front Stack [ ";
            FrontStack.display();
            cout << " ]" << endl;
        }
    }
};

