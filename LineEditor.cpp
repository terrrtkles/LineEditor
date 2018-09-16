#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

int menu() {
    string command;
    int line = 0;
    string textEnd;

    while (true) {
        getline(cin, command);

        if (command.find("insert") != string::npos) {
            cout << "ok";
            if (command.find("end") != string::npos) {

                //insertEnd();
                cout << "insert end thing method" << endl;
                return 1;
            } else if (any_of(command.begin(), command.end(), ::isdigit)) { //any_of uses algorithm lib
                //insertAtLine();
                cout << "insert at line number method" << endl;
                return 2;
            }
            else {
                cout << "Invalid command, please try again." << endl;
            }
        }
        else if (command.find("delete") != string::npos) {
            line = atoi(command);
            //deleteAtIndex();
            return 3;
        }
        else if (command.find("edit") != string::npos) {
            //edit();
        }
        else if (command.find("print") != string::npos) {
            //print();
        }
        else if (command.find("search") != string::npos) {
            //search();
        }
        else if (command.find("quit") != string::npos) {
            return 0;
        }
        else {
            cout << "Invalid command, please try again." << endl;
        }
    }
}

int main(){

    int choice = menu();

    cout << choice << endl;

    return 0;
}
