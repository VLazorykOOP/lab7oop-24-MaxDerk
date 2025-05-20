#include <iostream>
template<typename T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };
    Node* head;
    Node* tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    ~LinkedList()
    {
        Node* current = head;
        while (current)
        {
            Node* tmp = current->next;
            delete current;
            current = tmp;
        }
    }
    void push_back(const T& value)
    {
        Node* newNode = new Node(value);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    class Iterator
    {
    private:
        Node* current;
    public:
        Iterator(Node* node) : current(node) {}
        T& operator*()
        {
            return current->data;
        }
        Iterator& operator++()
        {
            if (current) current = current->next;
            return *this;
        }
        bool operator!=(const Iterator& other) const
        {
            return current != other.current;
        }
    };
    Iterator begin()
    {
        return Iterator(head);
    }
    Iterator end()
    {
        return Iterator(nullptr);
    }
};
int main()
{
    LinkedList<int> list;
    list.push_back(5);
    list.push_back(10);
    list.push_back(15);
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    return 0;
}