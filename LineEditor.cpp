#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct Node {
    string data;
    Node* next;
};
//insert text at end of linked list
Node* insertEnd(Node* head, string text){

    Node* temp = head;

    Node* tail = new Node();

    tail->data = text;
    tail->next = nullptr;
    //if the linked list is empty, then the last is the head
    if (head == nullptr){

        head = tail;
        cout << "added" << head->data << endl;
        return head;
    }
    else{

        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = tail; //establishes the actual last node

        cout << "added as not nulll" << endl;

        return head;
    }
}

Node* insertAtLine(Node* head, int lineNum, string text){
    Node* temp = head;
    Node* prev = head;
    Node* lastOfMove = new Node();
    lastOfMove->data = text;
    //instantiate the begin of the list with 1 and iterate through to the wanted line number
    while(temp != nullptr) {
        for (int i = 1; i <= lineNum; i++) {
            cout << "going inside loop" << endl;
            if(i == lineNum){
                //do the moving nodes thing
                if(temp == head){

                    lastOfMove->next = head;
                    head = lastOfMove;
                    cout << "first" << endl;
                    return head;
                }
                else if(temp->next == nullptr){ //if line is the tail

                    Node* tail = head;

                    lastOfMove->next = nullptr; //because it is last node
                    if(head == nullptr){
                        head = lastOfMove;

                        return head;
                    }
                    while(tail->next != nullptr){
                        tail = tail->next;
                    }
                    tail->next = lastOfMove;
                    cout << "second" << endl;
                    return head;
                }
                else{ //when the line is neither the head or tail
                    Node* moveOver = new Node();
                    moveOver->data = text;
                    moveOver->next = prev->next;
                    prev->next = moveOver;
                }
                cout << "third" << endl;
                return head;
            }
            else{
                temp = temp->next;

                //when there is a previous that exists aka when temp isn't head
                if(i >= 3) {
                    prev = prev->next;
                }
            }
        }
    }
    return head;
}

Node* deleteAtIndex(Node* head, int lineNum){
    Node* curr = head;

    if(head == nullptr){
        return head;
    }
    for(int i = 0; curr != nullptr && i < lineNum; i++) {
        curr = curr->next;
        cout << "found it" << endl;
    }
    if(curr == nullptr || curr->next == nullptr){
        return head;
    }
    Node* temp = curr->next->next;
    free(curr->next); //delete node
    curr->next = temp;
    cout << "transfer complete" << endl;
    return head;
}

void edit(Node* head, int lineNum, string text){
    Node* temp = head;

    //instantiate the begin of the list with 1 and iterate through to the wanted line number
    while(temp != nullptr) {
        for (int i = 1; i <= lineNum; i++) {
            if(i == lineNum){
                temp->data = text;
                return;
            }
            else{
                temp = temp->next;
            }
        }
    }
}

void print(Node* head){
    Node* curr = head;
    int listSize = 1;

        while (curr != nullptr) {
            cout << listSize << ". " << curr->data << endl;
            listSize++;
            curr = curr->next;
            if(curr == nullptr){
                return;
            }
        }

        cout << "list is empty" << endl;

}

void search(Node* head, string text){

    Node* curr = head;
    int listSize = 1;
    for(int i = 0; i < listSize; i++) {
        if(curr == nullptr){
            cout << "not found" << endl;
            free(curr);
            return;
        }
        else if (curr->data == text) {
            cout << listSize << " " << text << endl;
            free(curr);
            return;
        }
        else{
            curr = curr->next;
            listSize++;
        }
    }
}

int main(){
    int choice = 0;
    Node* head = nullptr;
    while(choice != 7) {
        string command;

        string delimiter = "\"";
        string textEnd;

        getline(cin, command);

        //check string size

        if (command.find("insert") != string::npos) {
            if (command.find("End") != string::npos) {
                //parse string for the text
                unsigned int firstQuote = command.find(delimiter); //finds the first quotation mark
                unsigned int secondQuote = command.find(delimiter, firstQuote + 1); //finds the second quotation mark
                cout << command.substr(firstQuote, secondQuote) << " is read" << endl;
                head = insertEnd(head, command.substr(firstQuote, secondQuote));
                choice = 1;
                cout << "insert end works" << endl;

            }
                //insert at line
            else if (any_of(command.begin(), command.end(), ::isdigit)) { //any_of uses algorithm lib
                //checks for a number
                string line;
                size_t found = command.find_first_of("0123456789");
                while (found != string::npos) {
                    for (int i = 0; i < 2; i++) {
                        line[i] = command[found];
                        found = command.find_first_of("0123456789", found + 1);
                    }
                }

                int lineInt = stoi(line);

                //text string
                unsigned int firstQuote = command.find(delimiter); //finds the first quotation mark
                unsigned int secondQuote = command.find(delimiter, firstQuote + 1); //finds the second quotation mark
                head = insertAtLine(head, lineInt, command.substr(firstQuote, secondQuote));
                choice = 2;
                cout << "insert at line works" << endl;
            } else {
                cout << "Invalid insert command" << endl;
            }
        } else if (command.find("delete") != string::npos) {
            if (any_of(command.begin(), command.end(), ::isdigit)) { //any_of uses algorithm lib
                //checks for a number
                cout << "delete dloop" << endl;
                string line;
                unsigned int found = command.find_first_of("0123456789");
                //FIX FIND THE NUMBER
                cout << found << endl;
                line.at(0) = command.at(found);
                if (any_of(command.begin() + found, command.end(), ::isdigit)){
                    found = command.find_first_of("0123456789");
                    line.at(1) = command.at(found);
                }
                cout << line << endl;
                int lineInt = stoi(line);
                cout << lineInt << "caught" << endl;
                head = deleteAtIndex(head, lineInt);
                choice = 3;
            }
        } else if (command.find("edit") != string::npos) {
            //checks for a number
            string line;
            size_t found = command.find_first_of("0123456789");

            while (found != string::npos) { //when are are still numbers
                for (int i = 0; i < 2; i++) {
                    line[i] = command[found];
                    found = command.find_first_of("0123456789", found + 1);

                }
            }

            int lineInt = stoi(line);

            //text string
            unsigned int firstQuote = command.find(delimiter); //finds the first quotation mark
            unsigned int secondQuote = command.find(delimiter, firstQuote + 1); //finds the second quotation mark
            edit(head, lineInt, command.substr(firstQuote, secondQuote));
            choice = 4;
        } else if (command.find("print") != string::npos) {
            print(head);
            choice = 5;
        } else if (command.find("search") != string::npos) {
            unsigned int firstQuote = command.find(delimiter); //finds the first quotation mark
            unsigned int secondQuote = command.find(delimiter, firstQuote + 1); //finds the second quotation mark
            search(head, command.substr(firstQuote, secondQuote));
            choice = 6;
        } else if (command.find("quit") != string::npos) {
            choice = 7;
        } else {
            cout << "Invalid command, please try again." << endl;
        }
    }

    return 0;
}
