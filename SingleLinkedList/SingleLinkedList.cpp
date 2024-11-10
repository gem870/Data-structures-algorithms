

#include <iostream>
#include <chrono>
using namespace std;

class Node {
public:                        // ---------> This is the Node class where all Nodes are generated. 
    int value;
    Node* next;
    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList {
private:                       // ---------> This is the LinkedList class where all Nodes are connected. 
    Node* head;
    Node* tail;
    int length;

public:

    LinkedList(int value) {    // ---------> This is the LinkedList constructor where all Nodes are created. 
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~LinkedList() {           // ---------> This is the LinkedList distractor where all Nodes are deleted. 
        Node* temp = head;
        while (head != nullptr)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printNodes() {     // ---------> This funtion prints out Node. 
        cout << "\n";        
        cout << "::::::::::::::::: Node  Printer :::::::::::::::::" << endl << endl;
        Node* temp = head;
        while (temp)
        {
            cout << "::: Node value: " << temp->value << endl;
            temp = temp->next;
        }
    }

    void prepend(int value) {   // ---------> This funtion add a new Node at the head or front of the linkedList. 
        Node* newNode = new Node(value); 
        if (length == 0) {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void deleteFirst() {     // ---------> This funtion deletes Node at the head or front of the linkedList. 
        if (length == 0) return;
        Node* temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
        }
        delete temp;
        length--;
    }

    void append(int value) {      // ---------> This funtion add new Node at the tail or end of the linkedList.
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void deleteLast() {     // ---------> This funtion delete the last Node at the tail or end of the linkedList.
        if (length == 0) return;
        Node* temp = head;
        Node* prev = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            while (temp->next)
            {
                prev = temp;
                temp = temp->next;
            }
            tail = prev;
            tail->next = nullptr;
            
        }
        delete temp;
        length--;
    }

    Node* getIndex(int index) {    // ---------> This funtion provides the index of a particular Node.
        if (index < 0 || index >= length) return nullptr;
        Node* temp = head;
        for (size_t i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp;
    }

    bool setValue(int index, int value) {       // ---------> This funtion set or change the value of a particular Node.
        Node* nodeIndex = getIndex(index);
        if (nodeIndex != nullptr) {
            nodeIndex->value = value;
            return true;
        }
        return false;
    }

    bool insertNode(int index, int value) {     // ---------> This funtion insert Node on a particular index.
        if (index < 0 || index > length) return false;
        if (index == 0) {
            prepend(value);
            return true;
        }
        if (index == length) {
            append(value);
            return true;
        }
        Node* newNode = new Node(value);
        Node* nodeIndex = getIndex(index - 1);
        newNode->next = nodeIndex->next;
        nodeIndex->next = newNode;
        length++;
        return true;
    }

    void deleteNode(int index) {         // ---------> This funtion delete Node on a particular index.
        if (index < 0 || index >= length) return;
        if (index == 0) {
            return deleteFirst();
        }
        if (index == length - 1) {
            return deleteLast();
        }
        Node* prev = getIndex(index - 1);
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        length--;
    }

    void reverseNode() {        // ---------> This funtion reverse the linked list.
        Node* temp = head;
        head = tail;
        tail = temp;
        Node* after = temp->next;
        Node* prev = nullptr;
        for (size_t i = 0; i < length; i++)
        {
            after = temp->next;
            temp->next = prev;
            prev = temp;
            temp = after;
        }
    }



};

int main()
{
    auto startTime = chrono::high_resolution_clock::now();
    LinkedList* ll  = new LinkedList(20);
    ll->prepend(30);
    ll->prepend(40);
    ll->prepend(50);

    ll->append(30);
    ll->append(60);
    ll->append(70);

    ll->insertNode(2, 400);
    ll->insertNode(0, 4000);
    ll->insertNode(1, 500);
    ll->insertNode(1, 500);
    ll->insertNode(1, 500);

    ll->deleteNode(1);
    ll->deleteNode(0);
    ll->deleteNode(0);
    ll->deleteNode(0);

    ll->printNodes();

    ll->reverseNode();
    ll->printNodes();



    auto stopTime = chrono::high_resolution_clock::now();
    chrono::duration<double> timeComplexity = stopTime - startTime;
    cout << "\n \n";
    cout << ":::::::::::::: TIME COMPLEXITY ::::::::::::::" << endl;
    cout << ":::::: -> " << timeComplexity.count() << "ms" << endl;
}


