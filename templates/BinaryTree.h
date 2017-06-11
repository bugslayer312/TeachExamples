#pragma once

template<class T>
class Tree;

template<class T>
struct TreeNode
{
    T Data;
    TreeNode<T>* Parent = nullptr;
    TreeNode<T>* Left = nullptr;
    TreeNode<T>* Right = nullptr;
    
    TreeNode(T const& data) : Data(data)
    {
    };
    
    TreeNode<T>* Min()
    {
        TreeNode<T>* result = this;
        while (result->Left)
        {
            result = result->Left;
        }
        return result;
    }
    TreeNode<T>* Max(Node* node)
    {
        Node* result = node;
        while (result->Right)
        {
            result = result->Right;
        }
        return result;
    }
};

enum class IteratorPosition
{
    Begin,
    End
};

template <class T>
class TreeIterator
{
    typedef TreeNode<T> Node;

private:
    Node* m_root = nullptr;
    Node* m_node = nullptr;
    bool m_beforeFirst = false;
    
    TreeIterator(Node* rootNode, IteratorPosition position): m_root(rootNode)
    {
        if (!m_root)
        {
            return;
        }
        
        if (position == IteratorPosition::Begin)
        {
            m_node = m_root->Min();
        }
    };
    
public:
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef const T& reference;
    typedef const T* pointer;
    typedef size_t size_type;
    typedef std::bidirectional_iterator_tag iterator_category;
    
    TreeIterator& operator++()
    {
        if (m_root)
        {
            if (!m_node)
            {
                if (m_beforeFirst)
                {
                    m_node = m_root->Min();
                }
            }
            else if (m_node->Right)
            {
                m_node = m_node->Right->Min();
            }
            else
            {
                Node* beforeNext = m_node;
                while (beforeNext->Parent)
                {
                    if (beforeNext->Parent->Left == beforeNext)
                    {
                        break;
                    }
                    beforeNext = beforeNext->Parent;
                }
                m_node = beforeNext->Parent;
            }
        }
        if (!m_node)
        {
            m_beforeFirst = false;
        }
        return *this;
    }
    
    TreeIterator& operator--()
    {
        if (m_root)
        {
            if (!m_node)
            {
                if (!m_beforeFirst)
                {
                    m_node = m_root->Max();
                }
            }
            else if (m_node->Left)
            {
                m_node = m_node->Left->Max();
            }
            else
            {
                Node* afterPrev = m_node;
                while (afterPrev->Parent)
                {
                    if (afterPrev->Parent->Right == afterPrev)
                    {
                        break;
                    }
                    afterPrev = afterPrev->Parent;
                }
                m_node = afterPrev->Parent;
            }
        }
        if (!m_node)
        {
            m_beforeFirst = true;
        }
        return *this;
    }
    
    T const& operator*()
    {
        return m_node->Data;
    }
    
    bool operator==(Iterator<T> const& rhs) const
    {
        return m_node == rhs.m_node && m_beforeFirst == rhs.m_beforeFirst;
    }
    
    bool operator!=(Iterator<T> const& rhs) const
    {
        return !(*this == rhs);
    }

    friend class Tree<T>;
};

template<class T>
class Tree
{
    typedef TreeNode<T> Node;

private:
    Node* m_root = nullptr;

    Node* InsertValue(Node* root, T const& value)
    {
        if (root->Data == value)
        {
            return root;
        }
        if (value < root->value)
        {
            if (root->Left)
            {
                return InsertValue(root->Left, value);
            }
            else
            {
                Node* newNode = new Node(value);
                newNode->Parent = root;
                root->Left = newNode;
                return newNode;
            }
        }
        // value > root->value
        if (root->Right)
        {
            return InsertValue(root->Right, value);
        }
        else
        {
            Node* newNode = new Node(value);
            newNode->Parent = root;
            root->Right = newNode;
            return newNode;
        }
    }
    
    Node* FindRecursive(Node* node, T const& value)
    {
        if (!node)
        {
            return nullptr;
        }
        if (root->Data == value)
        {
            return root;
        }
        return FindRecursive(root->Data < value ? root->Left : root->Right);
    }

public:
    typedef TreeIterator<T> iterator;
    Tree() = default;
    
    List(std::initializer_list<T> const& list)
    {
        for (T const& val : list)
        {
            insert(val);
        }
    }
    
    iterator begin()
    {
        return iterator(m_root, IteratorPosition::Begin);
    }
    
    iterator end()
    {
        return iterator(m_root, IteratorPosition::End);
    }
    
    iterator insert(T const& value)
    {
        if (!m_root)
        {
            m_root = new Node(value);
            return iterator(m_root, IteratorPosition::Begin);
        }
        iterator result(m_root, IteratorPosition::End);
        result->m_node = InsertValue(m_root, value);
        return result;
    }
    
    iterator erase(iterator position)
    {
        Node* toDelete = position->m_node;
        if (toDelete)
        {
            Node* forReplace = nullptr;
            if (toDelete->Left && toDelete->Right)
            {
                Node* next = toDelete->Right->Min();
                toDelete->Data = std::move(next->Data);
                toDelete = next;
                Node* forReplace = toDelete->Right;
            }
            else
            {
                ++position;
                if (toDelete->Left)
                {
                    forReplace = toDelete->Left;
                }
                else if (toDelete->Right)
                {
                    forReplace = toDelete->Right;
                }
            }
            if (toDelete->Parent)
            {
                if (toDelete->Parent->Left == toDelete)
                {
                    toDelete->Parent->Left = forReplace;
                }
                else
                {
                    toDelete->Parent->Right = forReplace;
                }
            }
            else
            {
                m_root = forReplace;
            }
            if (forReplace)
            {
                forReplace->Parent = toDelete->Parent;
            }
            delete [] toDelete;
        }
        return position;
    }
    
    iterator find(T const& value) const
    {
        iterator result(m_root, IteratorPosition::End);
        result->m_node = FindRecursive(m_root, value);
        return result;
    }
};