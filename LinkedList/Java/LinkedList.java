class Node<T> {
    T data;
    Node<T> next;
    Node<T> previous;
    public Node(){ }
    public Node(T value){
        this.data = value;
        this.next = null;
        this.previous = null;
    }
}
public class LinkedList<T>{
    private Node<T> head,tail;
    private int length;
    public LinkedList(){
        head = tail = null;
        length = 0;
    }
    public void insert_before(T value){
        Node<T> newNode = new Node<T>(value);
        if(head == null){
            head = tail = newNode;
        }
        else {
            head.previous = newNode;
            newNode.next = head;
            head = newNode;
        }
        length++;
    }
    public void insert_after(T value){
        Node<T> newNode = new Node<T>(value);
        if(head == null){
            head = tail = newNode;
        }
        else {
            newNode.previous = tail;
            tail.next = newNode;
            tail = newNode;
        }
        length++;
    }
    public void insert_at(T value,int position){
        Node<T> newNode = new Node<T>(value);
        if(head == null){
            head = tail = newNode;
        }
        else if(position > length || position < 1){
            System.out.println("Invalid position!");
            return;
        }
        else {
            Node<T> current = head;
            while (position > 0){
                current = current.next;
                position--;
            }
            current = current.previous;
            current.previous.next = newNode;
            newNode.previous = current.previous;
            current.previous = newNode;
            newNode.next = current;
        }
        length++;
    }
    public void remove_first(){
        if(head == null){
            System.out.println("Can't remove.List is empty.");
            return;
        }
        else if(length == 1){
            head = tail = null;
        }
        else {
            Node<T> temp = head.next;
            temp.previous = null;
            head.next = null;
            head = temp;
        }
        length--;
    }
    public void remove_last(){
        if(head == null){
            System.out.println("Can't remove.List is empty.");
            return;
        }
        else if(length == 1){
            head = tail = null;
        }
        else {
            Node<T> temp = tail.previous;
            temp.next = null;
            tail.previous = null;
            tail = temp;
        }
        length--;
    }
    public void remove_at(int position){
        if(head == null){
            System.out.println("Can't remove.List is empty.");
            return;
        }
        else if(position > length || position < 1){
            System.out.println("Invalid position!");
            return;
        }
        else if(position == length || length == 1){
            remove_last();
            return;
        }
        else {
            Node<T> current = head;
            while (current != null){
                current = current.next;
            }
            Node<T> temp1 = current.previous;
            Node<T> temp2 = current.next;
            temp1.next = temp2;
            temp2.previous = temp1;
            current.previous = current.next = null;
        }
        length--;
    }
    public int getLength(){
        return length;
    }
    public void printList(){
        Node<T> current = head;
        while (current != null){
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }
}
