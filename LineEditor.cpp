#include "LineEditorHeader.h"
#include <iostream>
#include <string>

using namespace std;


int menu(){
    char command[40];
    cin >> command;


    if(command.substr(0,6) == "insert") {
        if (command.substr(6, 9) == "end") {
            cout << "insert end thing method" << endl;
            return 1;
        }
        //space before the line number

        if (isdigit(command[7])){
            cout << "insert at line number method" << endl;
            return 2;
        }

    }

}

int main(){

    int choice = menu();

    cout << choice << endl;

    return 0;
}
