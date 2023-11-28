
template <typename T>
class List {
private:
    struct Node {
        Node* prev;
        Node* next;
        T data;

        Node(const T& val) : data(val), prev(nullptr), next(nullptr) {}
    };

    Node* mHead;
    Node* mTail;
    std::size_t mSize;

public:
    List() : mHead(nullptr), mTail(nullptr), mSize(0) {}

    bool empty() const 
    {
        return mSize == 0;
    }

    void push(const T& val)
    {
        Node* newNode = new Node(val);
        if (empty())
        {
            mHead = mTail = newNode;
        }
        else
        {
            mTail->next = newNode;
            newNode->prev = mTail;
            mTail = newNode;
        }
        mSize++;
    }

    void clear()
    {
        while (mHead != nullptr)
        {
            Node* temp = mHead;
            mHead = mHead->next;
            delete temp;
        }
        mTail = nullptr;
        mSize = 0;
    }

    class Iterator {
    private: 
        Node* mCurrent;
    public:
        Iterator(Node* node) : mCurrent(node) {}

        Iterator& operator++()
        {
            mCurrent = mCurrent->next;
            return *this;
        }

        T operator*()
        {
            return mCurrent->data;
        }

        bool operator!=(const Iterator& other)
        {
            return mCurrent != other.mCurrent;
        }

        Iterator next(std::size_t step)
        {
            Iterator result = *this;
            for (std::size_t i = 0; i < step && result.mCurrent != nullptr; ++i)
            {
                ++result;
            }
            return result;
        }
    };

    Iterator begin()
    {
        return Iterator(mHead);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }
};