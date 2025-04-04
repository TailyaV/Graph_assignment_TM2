//taliyarial1@gmail.com
#pragma once
#include <iostream>

namespace graph{

//Class that represent a Node, the use of this class is for building linked list.
   
class Node{
    private:
        Node* next;
        int value;
        int dest;
    public:
        Node(): next(nullptr), value(0), dest(0){}
        Node(int x, Node* n = nullptr): next(n), value(x), dest(0){}
        Node(int x, int y): next(nullptr), value(x), dest(y){}
        Node* getNext()const{return this->next;} //Return the next node on the linked list.
        int getValue()const{return this->value;} //Return the value of the current node.
        int getDest()const{return this->dest;} //Return the dest value of the current node.

        friend class LinkedList;
        
};

//Class that represent a Linked List. uses for queue, priority queue and stack.
class LinkedList{
    private:
        Node* head;
    public:
        LinkedList():head(nullptr){} //Linked List constractor
        void addNode(Node* n);
        Node* removeLastNode();
        bool isEmpty();
        Node* removeFirstNode();
        Node* removePriority();
};

}