#include <iostream>

using namespace std;

template <class T>
class Node
{
private:
    T m_data;
    Node<T> *m_next;
    Node<T> *m_prev;

public:
    Node(T data) : m_data(data), m_next(nullptr), m_prev(nullptr) {}
    T getData()
    {
        return m_data;
    }
    void setData(T data)
    {
        m_data = data;
    }
    Node<T> *getNext()
    {
        return m_next;
    }
    void setNext(Node<T> *next)
    {
        m_next = next;
    }
    Node<T> *getPrev()
    {
        return m_prev;
    }
    void setPrev(Node<T> *prev)
    {
        m_prev = prev;
    }
};

template <class T>
class DoubleLinkedList
{
private:
    Node<T> *m_head;
    Node<T> *m_tail;
    int m_size;

public:
    DoubleLinkedList() : m_head(), m_tail(), m_size(0) {}
    void add(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (m_head == nullptr)
        {
            m_head = newNode;
            m_tail = newNode;
        }
        else
        {
            m_tail->setNext(newNode);
            newNode->setPrev(m_tail);
            m_tail = newNode;
        }
        m_size++;
    }
    void remove(T data)
    {
        Node<T> *current = m_head;
        while (current != nullptr)
        {
            if (current->getData() == data)
            {
                if (current == m_head)
                {
                    m_head = current->getNext();
                }
                else if (current == m_tail)
                {
                    m_tail = current->getPrev();
                }
                else
                {
                    current->getPrev()->setNext(current->getNext());
                    current->getNext()->setPrev(current->getPrev());
                }
                delete current;
                m_size--;
                return;
            }
            current = current->getNext();
        }
    }

    Node<T> *getHead()
    {
        return m_head;
    }

    Node<T> *getTail()
    {
        return m_tail;
    }

    int getSize()
    {
        return m_size;
    }

    ~DoubleLinkedList()
    {
        Node<T> *current = m_head;
        while (current != nullptr)
        {
            Node<T> *temp = current;
            current = current->getNext();
            delete temp;
        }
    }

    void print()
    {
        Node<T> *current = m_head;
        while (current != nullptr)
        {
            cout << current->getData() << " ";
            current = current->getNext();
        }
        cout << endl;
    }

    void printReverse()
    {
        Node<T> *current = m_tail;
        while (current != nullptr)
        {
            cout << current->getData() << " ";
            current = current->getPrev();
        }
        cout << endl;
    }
};

int main()
{
    DoubleLinkedList<int> list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);

    list.print();
    list.printReverse();
    return 0;
}