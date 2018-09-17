#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct Node {
    string data;
    node *next;
}
//insert text at end of linked list
void insertEnd(string text){

}

void insertAtLine(int lineNum, string text){

}

void deleteAtIndex(int lineNum, string text){
    Node* head = head;
    Node* temp = NULL;
    //set temp's data to the text that wants to be deleted
    temp->data = text;

    //if text is found in head
    if(head->data == temp) {
        if(head->next == NULL) {
            cout << "This is the last line of text so it cannot be deleted." << endl;
            return;
        }

        head->data = head->next->data; //Move the head->next->data to the head->data

        temp = head->next; //store address of new next

        head->next = head->next->next; //disconnect the old links

        return;
    }

    // if text is not in head, then find the previous node
    struct Node *prev = head;
    while(prev->next != NULL && prev->next != temp) {
        prev = prev->next;
    }

    //checks that there is a previous for any node
    if(prev->next == NULL) {
        printf("Given text does not exist. Please reenter your command.");
        return;
    }

    prev->next = prev->next->next; //delete node

    return;
}

void edit(int lineNum, string text){
    Node* temp = head;
    //find address of lineNum

    while(head != NULL) {
        for (int = 1; i < lineNum; i++) {
            temp = temp->next;
        }

    }
    temp->data = text;

}

void print(){
    Node* head = head;
    int listSize = 1;
    while(head != NULL){
        cout << listSize << ". " << head->data << endl;
        listSize++;
    }
}

void search(){

}

/*int menu() {
    string command;
    int line = 0;
    string delimiter = "\"";
    string textEnd;

    while (true) {
        cin >> command;

        if (command.find("insert") != string::npos) {
            cout << "ok";
            if (command.find("end") != string::npos) {
                //parse string for the text
                int firstQuote = command.find(delimiter); //finds the first quotation mark
                int secondQuote = command.find(delimiter, firstQuote + 1); //finds the second quotation mark
                insertEnd(command.substr(firstQuote, secondQuote));
                cout << "insert end thing method" << endl;
                return 1;
            } else if (any_of(command.begin(), command.end(), ::isdigit)) { //any_of uses algorithm lib
                //checks for a number
                string line;
                size_t found = command.find_first_of("0123456789");
                while(found != string::npos){
                    for(int = 0; i < command.length(); i++) {
                        line[i];
                        found = command.find_first_of("0123456789", found + 1);
                    }
                }

                int lineInt = atoi(line);

                //text string
                int firstQuote = command.find(delimiter) //finds the first quotation mark
                int secondQuote = command.find(delimiter, firstQuote + 1) //finds the second quotation mark
                insertAtLine(lineInt, command.substr(firstQuote, secondQuote));

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
}*/

int main(){

//    int choice = menu();
    Node* curr = head;
    int gg = 70;
    for(int i = 0; i < 5; i++){
        curr->data = gg;
        curr = curr->next;
        gg++;
    }
    insertEnd("what is life");
    insertAtLine(3,"line 3");
    edit(5, "peekaboo");


    return 0;
}
