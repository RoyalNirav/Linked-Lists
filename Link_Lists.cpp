
//
//  main.cpp
//  Linked List
//
//  Created by Nirav Patel on 4/2/18.
//  Copyright © 2018 Nirav Patel. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class Linked_List {
private:
    Node *head;
    Node *tail;
    
public:
    
    //Linked List Constructor
    Linked_List() {
        head = nullptr;
        tail = nullptr;
    }
    
    
    
    //Method to insert a node into the linked list
    void add_node(int value) {
        Node *temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        
        //Special Case
        if (head == nullptr) {
            head = temp;
            tail = temp;
            temp = nullptr;
            
        }
        
        //Insert a new node at the end of the list
        else {
            tail->next = temp;
            tail = temp;
        }
        
    }
    
    //Method to print out data in each link list
    void print_Linked_List() {
        Node * temp;
        temp = head;
        
        while (temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        
    }
    
    void insert_front(int value) {
        Node * temp = new Node;
        temp->data = value;
        temp->next = head;
        head = temp;
    }
    
    void insert_particular(int value, int location) {
        Node *current = head;
        Node *previous;
        Node * temp = new Node;
        temp->data = value;
        
        for (int i = 1; i < location; i++){
            previous = current;
            current = current->next;
            
        }
        
        previous->next = temp;
        temp->next = current;
    }
    
    void delete_at_front() {
        Node * temp;
        temp = head;
        head = head->next;
        delete temp;
        
    }
    
    void delete_at_end() {
        Node *previous;
        Node *current;
        
        current = head;
        
        while(current->next != nullptr) {
            previous = current;
            current = current->next;
        }
        
        tail = previous;
        previous->next = nullptr;
        delete current;
        
    }
    
    void delete_location(int location) {
        Node *previous;
        Node *current;
        current = head;
        
        for (int i = 1; i < location; i++) {
            previous = current;
            current = current->next;
        }
        
        previous->next = current->next;
        delete current;
    }
    
};

int main() {
    Linked_List s1;
    s1.add_node(1);
    s1.add_node(2);
    s1.add_node(3);
    s1.add_node(4);
    s1.add_node(5);
    s1.print_Linked_List();
    cout << "Insert Node in Front" << endl;
    s1.insert_front(4);
    s1.print_Linked_List();
    
    cout << "Insert Node in a particular location" << endl;
    s1.insert_particular(0, 3);
    s1.print_Linked_List();
    
    cout << "Delete Node at the Front" << endl;
    s1.delete_at_front();
    s1.print_Linked_List();
    
    cout << "Delete Node at the End" << endl;
    s1.delete_at_end();
    s1.print_Linked_List();
    
    cout << "Delete Node in a pacticular location" << endl;
    s1.delete_location(3);
    s1.print_Linked_List();
    
    
}
