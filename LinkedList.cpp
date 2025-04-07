//taliyarial1@gmail.com
#include <iostream>
#include "LinkedList.hpp"

using namespace graph;

//Function that add a new Node n for the Linked list.
void LinkedList::addNode(Node* n){
    if(this->head == nullptr){
        this->head = n;
        n->next = nullptr;
    }
    else{
    n->next = this->head;
    this->head = n;
    }
}

//Function that remove the last Node from the Linked list uses for queue.
Node* LinkedList::removeLastNode(){
    Node* curr = this->head;
    Node* prev = this->head;
    if(head == nullptr){
        return NULL;
    }
    else if (head->next  == nullptr){
        head = nullptr;
        return curr;
    }
    else{
        curr = head->next;
        while (curr->next != nullptr){
            prev = curr;
            curr = curr->next;
        }
        if(curr->next == nullptr){
            prev->next = nullptr;
        }
    }
    return curr;
}

//Function that check if the Linked List is empty, if empty returns true.
bool LinkedList::isEmpty(){
    if(this->head == nullptr){
        return true;
    }
    return false;
}

//Function that remove the first Node from the Linked list uses for stack.
Node* LinkedList::removeFirstNode(){
    if(head->next == nullptr){
        Node* n = head;
        head = nullptr;
        return n;
    }
    else{
        Node* n = head;
        head = head->next;
        return n;
    }
}


//Function that remove the Node that contain the minimal value from the Linked list uses for priority queue.
Node* LinkedList::removePriority(){
    Node* curr1 = this->head;
    Node* minNode = this->head;
    while (curr1 != nullptr){
        if(curr1->dest < minNode->dest){
            minNode = curr1;
        }
        curr1 = curr1->next;
    }
    Node* curr = this->head;
    Node* prev = this->head;
    if(head == nullptr){
        return NULL;
    }
    else if (head->next  == nullptr){
        head = nullptr;
        return curr;
    }
    else if(curr->dest == minNode->dest){
        head = curr->next;
        return minNode;
    }
    else{
        curr = head->next;
        while (curr->dest != minNode->dest)
        {
            prev = curr;
            curr = curr->next;
        }
        if(curr->dest == minNode->dest){
            prev->next = curr->next;
            }
        }
    return minNode;
}