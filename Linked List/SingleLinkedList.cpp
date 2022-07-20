#include <iostream>

using namespace std;

template <class T>
class Node
{
private:
    T m_data;
    Node<T> *m_next;

public:
    Node(T data) : m_data(data), m_next(nullptr) {}

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
};

template <class T>
class LinkedList
{
private:
    Node<T> *m_head;
    Node<T> *m_tail;
    int m_size;

public:
    LinkedList() : m_head(), m_tail(), m_size(0) {}
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
            m_tail = newNode;
        }
        m_size++;
    }

    void remove(T data)
    {
        Node<T> *current = m_head;
        Node<T> *previous = nullptr;
        while (current != nullptr)
        {
            if (current->getData() == data)
            {
                if (previous == nullptr)
                {
                    m_head = current->getNext();
                }
                else
                {
                    previous->setNext(current->getNext());
                }
                m_size--;
                delete current;
                return;
            }
            previous = current;
            current = current->getNext();
        }
    }

    Node<T> *getHead()
    {
        return m_head;
    }

    int getSize()
    {
        return m_size;
    }

    ~LinkedList()
    {
        Node<T> *current = m_head;
        while (current != nullptr)
        {
            Node<T> *temp = current;
            current = current->getNext();
            delete temp;
        }
    }
};

template<class T>
ostream& operator<<(ostream &out, LinkedList<T> &list)
{
    Node<T> *current = list.getHead();
    while (current != nullptr)
    {
        out << current->getData() << " ";
        current = current->getNext();
    }
    return out;
}

int main()
{
    LinkedList<int> list;
    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);
    cout << list << endl;

    return 0;
}