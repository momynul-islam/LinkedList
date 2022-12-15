#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class Node{
public:
    T data;
    Node<T> *next;
    Node<T> *previous;
    Node<T> ();
    Node<T> (T value);
};

template <class T>
class LinkedList
{
    private:
        Node<T> *head,*tail;
        int length;
    public:
        LinkedList<T>();
        void insert_before(T value);
        void insert_after(T value);
        void insert_at(T value,int position);
        void remove_first();
        void remove_last();
        void remove_at(int position);
        int getLength();
        void printList();
};

#endif // LINKEDLIST_H
