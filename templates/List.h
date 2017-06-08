#pragma once

#include <xutility>

template<class T>
class List;

template<class T>
struct ListNode
{
    T Data;
    ListNode<T>* Next = nullptr;

    ListNode(T const& data) : Data(data)
    {
    };
};


template<class T>
class Iterator
{
    typedef ListNode<T> Node;
    Node* m_node;
public:
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef const T& reference;
    typedef const T* pointer;
    typedef size_t size_type;
    typedef std::forward_iterator_tag iterator_category;

    Iterator(Node* node) : m_node(node){};

    Iterator& operator++()
    {
        if (m_node)
        {
            m_node = m_node->Next;
        }
        return *this;
    }

    T& operator*()
    {
        return m_node->Data;
    }

    bool operator==(Iterator<T> const& rhs) const
    {
        return m_node == rhs.m_node;
    }

    bool operator!=(Iterator<T> const& rhs) const
    {
        return !(*this == rhs);
    }

    template<class T> friend class List;
};

template<class T>
class List
{
    typedef ListNode<T> Node;
    template<class T> friend class Iterator;

    Node* m_head = nullptr;

private:
    Node* GetLastNode()
    {
        if (!m_head)
        {
            return nullptr;
        }

        Node* result = m_head;
        while (result->Next)
        {
            result = result->Next;
        }
        return result;
    }

public:
    typedef Iterator<T> iterator;

    List() = default;

    List(std::initializer_list<T> const& list)
    {
        Node* prev = nullptr;
        for (T const& val : list)
        {
            Node* newNode = new Node(val);
            if (prev)
            {
                prev->Next = newNode;
            }
            else
            {
                m_head = newNode;
            }
            prev = newNode;
        }
    }

    iterator begin()
    {
        return iterator(m_head);
    }

    iterator end()
    {
        return iterator(nullptr);
    }

    iterator insert(iterator position, T const& value)
    {
        if (position.m_node)
        {
            Node* newNode = new Node(position.m_node->Data);
            newNode->Next = position.m_node->Next;
            position.m_node->Data = value;
            position.m_node->Next = newNode;
        }
        else
        {
            Node* newNode = new Node(value);
            Node* lastNode = GetLastNode();
            if (lastNode)
            {
                lastNode->Next = newNode;
            }
            else
            {
                m_head = newNode;
            }
            position.m_node = newNode;
        }
        return position;
    }

    iterator erase(iterator position)
    {
        if (position.m_node)
        {
            Node* nextNode = position.m_node->Next;
            if (nextNode)
            {
                position.m_node->Data = nextNode->Data;
                position.m_node->Next = nextNode->Next;
                delete nextNode;
            }
            else
            {
                if (position.m_node == m_head)
                {
                    m_head = nullptr;
                }
                else
                {
                    Node* curNode = m_head;
                    while (curNode->Next != position.m_node)
                    {
                        curNode = curNode->Next;
                    }
                    curNode->Next = nullptr;
                }
                delete position.m_node;
                position.m_node = nullptr;
            }
        }
        return position;
    }

    void clear()
    {
        Node* curNode = m_head;
        while (curNode)
        {
            Node* tmpNode = curNode;
            curNode = curNode->Next;
            delete tmpNode;
        }
        m_head = nullptr;
    }

    ~List()
    {
        clear();
    }
};