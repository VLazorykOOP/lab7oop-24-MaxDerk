#include <iostream>
template <typename T, int MaxSize>
class Stack
{
private:
    T data[MaxSize];
    int topIndex;
public:
    Stack() : topIndex(-1) {}
    bool push(const T& value)
    {
        if (isFull())
            return false;
        data[++topIndex] = value;
        return true;
    }
    bool pop()
    {
        if (isEmpty())
            return false;
        --topIndex;
        return true;
    }
    T top() const
    {
        if (isEmpty())
            throw "Stack is empty";
        return data[topIndex];
    }
    bool isEmpty() const
    {
        return topIndex == -1;
    }
    bool isFull() const
    {
        return topIndex == MaxSize - 1;
    }
    int size() const
    {
        return topIndex + 1;
    }
};
int main()
{
    Stack<int, 5> s;
    s.push(10);
    s.push(20);
    s.push(30);
    while (!s.isEmpty())
    {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << "\n";
    return 0;
}