#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int menu(){
	string command;

    while (true) {
        getline(cin, command);

        if (command.find("insert") != string::npos) {
            cout << "ok";
            if (command.find("end") != string::npos) {
                cout << "insert end thing method" << endl;

                return 1;
            }

            else if (any_of(command.begin(), command.end(), :: isdigit)) { //any_of uses algorithm lib
                cout << "insert at line number method" << endl;
                return 2;
            }
            else {
                cout << "Invalid command, please try again." << endl;

            }

        }
    }

}

int main(){

    int choice = menu();

    cout << choice << endl;

    return 0;
}
