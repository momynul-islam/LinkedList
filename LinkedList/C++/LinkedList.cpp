#include <iostream>
#include "LinkedList.h"

using namespace std;

template <class T>
Node<T>::Node(T value){
    this->data = value;
    this->next = NULL;
    this->previous = NULL;
}

template <class T>
LinkedList<T>::LinkedList()
{
    this->head = NULL;
    this->tail = NULL;
    this->length = 0;
}

template <class T>
void LinkedList<T>::insert_before(T value){
    Node<T> *newNode = new Node<T>(value);
    if(head == NULL){
        this->head = newNode;
        this->tail = newNode;
    }
    else{
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }
    length++;
}

template <class T>
void LinkedList<T>::insert_after(T value){
    Node<T> *newNode = new Node<T>(value);
    if(head == NULL){
        this->head = newNode;
        this->tail = newNode;
    }
    else{
        newNode->previous = tail;
        tail->next = newNode;
        newNode->next = NULL;
        tail = newNode;
    }
    length++;
}

template <class T>
void LinkedList<T>::insert_at(T value,int position){
    Node<T> *newNode = new Node<T>(value);
    if(head == NULL){
        this->head = newNode;
        this->tail = newNode;
    }
    else{
        Node<T> *current = head;
        while(position--){
            current = current->next;
        }
        current = current->previous;
        current->previous->next = newNode;
        current->previous = newNode;
        newNode->next = current;
    }
    length++;
}

template <class T>
void LinkedList<T>::remove_first(){
    if(head == NULL){
        cout << "Can't remove.List is empty" <<endl;
        return;
    }
    else if(head->next == NULL){
        head = NULL;
        tail = NULL;
    }
    else{
        Node<T> *temp = head->next;
        temp->previous = NULL;
        head = temp;
    }
    length--;
}

template <class T>
void LinkedList<T>::remove_last(){
    if(tail == NULL){
        cout << "Can't remove.List is empty" <<endl;
        return;
    }
    else if(length == 2){
        tail = NULL;
        head->next = NULL;
        tail = head;
    }
    else{
        Node<T> *temp = tail->previous;
        tail->previous = NULL;
        tail = temp;
        tail->next = NULL;
    }
    length--;
}

template <class T>
void LinkedList<T>::remove_at(int position){
    if(tail == NULL || head == NULL){
        cout << "Can't remove.List is empty" <<endl;
        return;
    }
    else if(position > length || position < 1){
        cout << "Invalid position!" <<endl;
        return;
    }
    else if(position == 1){
        remove_first();
        return;
    }
    else if(position == length){
        remove_last();
        return;
    }
    else{
        Node<T> *current = head;
        while(position--){
            current = current->next;
        }
        Node<T> *temp_pre = current->previous;
        Node<T> *temp_nex = current->next;
        temp_pre->next = temp_nex;
        temp_nex->previous = temp_pre;
    }
    length--;
}

template <class T>
void LinkedList<T>::printList(){
    Node<T> *current = head;
    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template <class T>
int LinkedList<T>::getLength(){
    return length;
}
