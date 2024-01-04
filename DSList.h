#ifndef DSLIST_H
#define DSLIST_H

/**
 * @brief Singly-linked list that uses position
 *
 * Implement all described functions and provide a test program using CATCH2
 *
 * @tparam Object
 */
template <typename Object>

class DSList
{
private:
    /**
     * @brief The nested Node data structure
     *
     * struct is in C++ a class with all public members
     */
    struct Node
    {
        Object data;
        Node *next;

        Node(const Object &d = Object{}, Node *n = nullptr)
            : data{d}, next{n} {};
    };

    Node *head;
    // Node *tail;
    // Node *current;

public:
    // You need to implement at least:
    // Default constructor
    DSList()
    {
        head = nullptr;
    }
    // Rule-of-3
    DSList &operator=(const DSList &x)
    {
        clear();

        Node* temp;
        temp = x.head->next;

        Node *h = new Node;
        h->data = x.head->data;
        h->next = x.head->next;

        while(temp->next != nullptr)
        {
            Node *n = new Node(temp->data, temp->next);
            temp = temp->next;
        }

        Node *tail = new Node(temp->data, nullptr);
    }

    DSList(const DSList &x)
    {
        Node* temp;
        temp = x.head->next;

        if(x.head == nullptr)
        {
            head = nullptr;
            return;
        }
        Node *h = new Node;

        h->data = x.head->data;
        head = h;

        while(temp->next != nullptr)
        {
            Node *n = new Node(temp->data);
            temp = temp->next;
            h->next = n;
            h = n;
        }
    }

    ~DSList()
    {
        clear();
    }

    // size
    size_t size()
    {

        Node *n;
        n = head;
        size_t len = 0;
        while (n != nullptr)
        {
            ++len;
            n = n->next;
        }

        return len;
    }
    // is the list empty?
    bool empty()
    {
        return (head == nullptr);
    }
    // clear the whole list
    void clear()
    {
        while (!empty())
            pop_front();
    }

    // find an element with a specific value (and return the position. First element in list is pos 0). Not found returns -1.
    Object find(int x)
    {
        int count = 0;
        Node *n;
        n = head;

        if(head == nullptr)
        {
            throw std::runtime_error("No value available for List");
        }
        if(head->data == x)
            return 0;

        while(n->next != nullptr)
        {
            if(n->data = x)
                return count;

            n = n->next;
            ++count;
        }

        throw std::runtime_error("No value available for List");
        
    }

    // insert at the beginning of the list (push_front).
    void push_front(Object x)
    {
        Node *n = new Node(x, head);
        head = n;
    }
    // insert at the end of the list (push_back).
    void push_back(Object x)
    {
        Node *n = new Node(x, nullptr);

        Node *temp;
        temp = head;
        if (head == nullptr)
        {
            head = n;
            return;
        }

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
    // remove the first element(pop_front)
    void pop_front()
    {
        Node *n = head;
        if (head == nullptr)
            return;
        head = head->next;
        delete n;
    }
    // remove the last1 element (pop_back)
    void pop_back()
    {
        Node *n = head;
        if (head == nullptr)
            return;
        else if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        while (n->next->next != nullptr)
        {
            n = n->next;
        }
        delete n->next;
        n->next = nullptr;
    }

    //peek front value without deleting it
    const Object &front()
    {
        Node *n = head;
        if (head == nullptr)
            throw std::runtime_error("No value available for List");
     
        return head->data;
    }
};

#endif
