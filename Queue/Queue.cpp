#include<iostream>

using namespace std;

template<class T>
class Node {
public:
    T data;
    Node<T> *next;
    Node<T> *prev;
    Node(T data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

template<class T>
class Queue {
private:
    Node<T> *front;
    Node<T> *rear;
    int size;
public:
    Queue() {
        front = NULL;
        rear = NULL;
        size = 0;
    }
    void enqueue(T data) {
        Node<T> *newNode = new Node<T>(data);
        if (front == NULL) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        size++;
    }
    T dequeue() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return 0;
        } else {
            T data = front->data;
            Node<T> *temp = front;
            front = front->next;
            delete temp;
            size--;
            return data;
        }
    }
    int getSize() {
        return size;
    }

    ~Queue() {
        Node<T> *temp = front;
        while (temp != NULL) {
            front = front->next;
            delete temp;
            temp = front;
        }
    }
};

int main(){
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    return 0;
}