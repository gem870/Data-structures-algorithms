#include <iostream>
#include <chrono>
using namespace std;

class Node {                   // ------>> Here is the Node class, where all Nodes are generated.
public:
    int value;
    Node* next;
    Node* prev;

    Node(int value) {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {     // ------->> Here is Doubly Linked List class that create edges or connection between Nodes.
private:
    Node* head;
    Node* tail;
    int length;

public:
    DoublyLinkedList(int value) {    // ------->> Here is the constructor where new Nodes are created.
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~DoublyLinkedList() {      // -------->> Here is the distractor that deletes all Nodes once the class is deleted.
        Node* temp = head;
        while (temp) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printNodes() {     //---------->> The function that prints values associated with each Node.
        cout << "\n\n";
        cout << ":::::::::::::::: Doubly Linked List ::::::::::::::::" << endl;
        Node* temp = head;
        while (temp) {
            cout << ":::: Node value: " << temp->value << endl;
            temp = temp->next;
        }
    }

    void append(int value) {    // ------->> The function that adds a new Node at the end or the tail of the d_linked list.
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;  
            tail = newNode;
        }
        length++;
    }

    void deleteLast() {   // ------->> This function deletes the last Node from the tail in the doubly linked list.
        if (length == 0) return;
        Node* temp = tail;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }
    void prepend(int value) {   // ------->>  The function that adds a new Node at the beginning or the head of the d_linked list.
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }
    void deleteFirst() {    // ------->> This function deletes the first Node from the head in the doubly linked list.
        if (length = 0) return;
        Node* temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        length--;
    }

    Node* getIndex(int index) {  // ------>> This function provides the index of a particular Node.
        if (index < 0 || index >= length) return nullptr;
        Node* temp = head;
        if (index < length / 2) {
            for (size_t i = 0; i < index; i++)
            {
                temp = temp->next;
            }return temp;
        }
        else
        {
            temp = tail;
            for (size_t i = length - 1; i > index; i--)
            {
                temp = temp->prev;
            }
            return temp;
        }
    }

    bool setValue(int index, int value) {   // ------>> This function changes the value of a particular Node.
        Node* nodeIndex = getIndex(index);
        if (nodeIndex != nullptr) {
            nodeIndex->value = value;
            return true;
        }
        return false;
    }

    bool insertNewNode(int index, int value) {  // ------>> This function creaates and insert a new Node at any provided index.
        if (index < 0 || index > length) return false;
        Node* newNode = new Node(value);
        if (index == 0) {
            prepend(value);
            return true;
        }
        if (index == length) {
            append(value);
            return true;
        }
        Node* nodeIndex = getIndex(index - 1);
        newNode->prev = nodeIndex;
        newNode->next = nodeIndex->next;
        nodeIndex->next->prev = newNode;
        nodeIndex->next = newNode;
        length++;
        return true;
    }

    void deleteNode(int index) {     // ------>> This function delete Node at any provided index.
        if (index < 0 || index >= length) return;
        if (index == 0) {
            deleteFirst();
            return;
        }
        if (index == length - 1) {
            deleteLast();
            return;
        }
         
        Node* temp = getIndex(index);
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
        length--;
        return;
    }

};


int main() {
    auto startTime = chrono::high_resolution_clock::now();

    DoublyLinkedList* Dll = new DoublyLinkedList(10);
    Dll->append(40);
    Dll->append(50);
    Dll->prepend(50);
    Dll->prepend(60);
    Dll->prepend(30);
    Dll->setValue(3,40);
    cout << Dll->getIndex(3)->value << endl;
    Dll->insertNewNode(0, 100);
    Dll->insertNewNode(5, 400);
    Dll->deleteNode(2);
    Dll->deleteNode(4);
    
   
    Dll->printNodes();
    auto endTime = chrono::high_resolution_clock::now();
    chrono::duration<double> timeComplexity = endTime - startTime;
    cout << "\n\n::::::::::::: TIME COMPLEXITY :::::::::::::" << endl;
    cout << "::: Time: " << timeComplexity.count() * 1000 << " ms" << endl;

    delete Dll; // Free dynamically allocated memory for Dll
}
