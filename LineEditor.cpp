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
    Node* tail = new Node;

    tail->data = text;
    tail->next = NULL;

    //if the linked list is empty, then the last is the head
    if (head == NULL){
        head = tail;
    }
    else{
        Node* temp = new Node;
        temp = head;

        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = last; //establishes the actual last node
    }
}

void insertAtLine(int lineNum, string text){
    Node* temp = head;
    Node* prev = head;
    //instantiate the begin of the list with 1 and iterate through to the wanted line number
    while(temp != NULL) {
        for (int i = 1; i <= lineNum; i++) {
            if(i == lineNum){
                temp->data = text;
                //do the moving nodes thing
                if(temp == head){
                    Node* move = NULL;
                    move->data = text;
                    move->next = head;
                    head = move;
                }
                else if{temp->next == NULL){ //if line is the tail
                    Node* lastOfMove = NULL;
                    Node* tail = head;
                    lastOfMove->data = text;
                    lastOfMove->next = NULL; //because it is last node
                    if(head == NULL){
                        head = lastOfNode;
                        return;
                    }
                    while(tail->next != NULL){
                        tail = tail->next;
                    }
                    tail->next = lastOfNode;
                    return;
                }
                else{ //when the line is neither the head or tail
                    Node* moveOver = NULL;
                    moveOver->data = text;
                    moveOver->next = prev->next;
                    prev->next = moveOver;
                }
                return;
            }
            else{
                temp = temp->next;

                //when there is a previous that exists aka when temp isn't head
                if(i >= 2) {
                    prev = prev->next;
                }
            }
        }
    }
}

void deleteAtIndex(int lineNum){
    Node* curr = head;

    for(int i = 1; i <= lineNum; i++) {

        if (i == lineNum) {
            curr->data = curr->next->data; //Move the head->next->data to the head->data

            temp = curr->next; //store address of new next

            curr->next = curr->next->next; //disconnect the old links

            return;
        }
        else{

            curr = curr->next;
        }
    }
}

    // if text is not in head, then find the previous node
    Node *prev = head;
    while(prev->next != NULL && prev->next != temp) {
        prev = prev->next;
    }

    //checks that there is a previous for any node
    if(prev->next == NULL) {
        printf("Given text does not exist. Please reenter your command.");
        return;
    }
    prev->next = prev->next->next; //delete node
}

void edit(int lineNum, string text){
    Node* temp = head;

    //instantiate the begin of the list with 1 and iterate through to the wanted line number
    while(temp != NULL) {
        for (int i = 1; i <= lineNum; i++) {
            if(i == lineNum){
                temp->data = text;
                break;
            }
            else{
                temp = temp->next;
            }
        }
    }
}

void print(){
    Node* curr = head;
    int listSize = 1;
    while(curr != NULL){
        cout << listSize << ". " << curr->data << endl;
        listSize++;
        curr = curr->next;
    }
}

void search(string text){
    Node* curr = head;
    int listSize = 1;
    for(int i = 0; i < listSize; i++) {
        if(curr == NULL){
            cout << "text does not exist" << endl;
            return;
        }
        else if (curr->data == text) {
            cout << listSize << " " << text << endl;
            return;
        }
        else{
            curr = curr->next;
            listSize++;
        }
    }
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
            deleteAtIndex(lineInt);
        }
        else if (command.find("edit") != string::npos) {
            edit(lineInt, command.substr(firstQuote, secondQuote));
        }
        else if (command.find("print") != string::npos) {
            print();
        }
        else if (command.find("search") != string::npos) {
            int firstQuote = command.find(delimiter) //finds the first quotation mark
            int secondQuote = command.find(delimiter, firstQuote + 1) //finds the second quotation mark
            search(command.substr(firstQuote, secondQuote));
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
