#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node<T> *prev;
    Node(T data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

template <class T>
class Stack
{
private:
    Node<T> *top;
    int size;

public:
    Stack()
    {
        top = NULL;
        size = 0;
    }

    void push(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (top == NULL)
        {
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top->prev = newNode;
            top = newNode;
        }
        size++;
    }
    T pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        else
        {
            T data = top->data;
            Node<T> *temp = top;
            top = top->next;
            delete temp;
            size--;
            return data;
        }
    }
    T peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        else
        {
            return top->data;
        }
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    ~Stack()
    {
        Node<T> *temp = top;
        while (temp != NULL)
        {
            top = top->next;
            delete temp;
        }
    }
};

int main()
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << s.peek() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    
    return 0;
}