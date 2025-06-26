#include <iostream>
#include <fstream>
#include "visitLinks.cpp"
using namespace std;

int main() {
    cout << "Welcome to my program :)\n";
    cout << "insert the name of the file which contains your links..\n";
    string fileName;
    cin >> fileName;
    VisitLinks v1(fileName);
    v1.ReadUrl();
    while (true) {
        cout << "which function do you want to use?\n";
        cout << "1. visit new link without file(insert the name by your self)\n";
        cout << "2. go back.\n";
        cout << "3. go front.\n";
        cout << "4. exit\n";
        string choice;
        cin >> choice;
        if (choice == "1") {
            string Url;
            cout << "Please insert the url of your link.\n";
            cin >> Url;
            v1.visitLinkManual(Url);
        }else if (choice == "2") {
            v1.goBack();

        }else if (choice == "3") {
            v1.goFront();

        }else if (choice == "4") {
            cout << "Thank you for using my program.\n";
            exit(0);
        }else {
            cout << "Please enter a valid choice\n";
        }
        cout << "Do you want to continue?\n";
        cout << "1. Yes\n";
        cout << "2. No\n";
        cin >> choice;
        if (choice == "1") {
            continue;
        }else if (choice == "2") {
            cout << "Thank you for using my program.\n";
            exit(0);
        }
    }
}

