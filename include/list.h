#include <iostream>

namespace lib {
    template <typename T>
    class list {
    private:
        struct Node {
            Node* prev;
            Node* next;
            T data;

            Node(const T& val) : data(val), prev(nullptr), next(nullptr) {}
        };
    
        Node* mHead;
        Node* mTail;
        size_t sizeOfList;

    public:
        list() : mHead(nullptr), mTail(nullptr), sizeOfList(0) {}

        void push_back(const T& val)
        {
            Node* node = new Node(val);
            if (empty())
            {
                mHead = mTail = node;
            }
            else 
            {
                mTail->next = node;
                node->prev = mTail;
                mTail = node;
            }
            ++sizeOfList;
        }

        void pop_back()
        {
            if (empty())
                return;

            if (sizeOfList == 1)
            {
                mHead = mTail = nullptr;
            }
            else 
            {
                Node* temp = mTail;
                mTail = mTail->prev;
                mTail->next = nullptr;
                delete temp;
            }

            --sizeOfList;
        }

        T back()
        {
            return mTail->data;
        }

        void push_front(const T& val)
        {
            Node* node = new Node(val);
            if (empty())
            {
                mHead = mTail = node;
            }
            else 
            {
                mHead->prev = node;
                node->next = mHead;
                mHead = node;
            }
            ++sizeOfList;
        }

        void pop_front()
        {
            if (empty())
                return;

            if (sizeOfList == 1)
            {
                mHead = mTail = nullptr;
            }
            else 
            {
                Node* temp = mHead;
                mHead = mHead->next;
                mHead->prev = nullptr;
                delete temp;
            }

            --sizeOfList;
        }

        T front()
        {
            return mHead->data;
        }

        size_t size()
        {
            return sizeOfList;
        }

        bool empty()
        {
            return sizeOfList == 0;
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
            sizeOfList = 0;
        }

        void insert(const int& position, const T& val)
        {
            if (sizeOfList < position)
                return;
            
            if (sizeOfList == position)
            {
                push_back(val);
                return;
            }

            if (position == 0)
            {
                push_front(val);
                return;
            }

            Node* temp = mHead;
            int count = 0;
            while (count < position)
            {
                if (count == position - 1)
                {
                    Node* newNode = new Node(val);
                    newNode->prev = mHead;
                    newNode->next = mHead->next;

                    mHead->next = newNode;
                    mHead->next->prev = newNode;

                    break;
                }
                mHead = mHead->next;
                count++;
            }
            mHead = temp;

            sizeOfList++;
        }

        class iterator {
        private: 
            Node* mCurrent;

        public:
            iterator(Node* node) : mCurrent(node) {}

            iterator& operator++()
            {
                mCurrent = mCurrent->next;
                return *this;
            }

            bool operator!=(const iterator& it)
            {
                return mCurrent != it.mCurrent;
            }

            T operator*()
            {
                return mCurrent->data;
            }
        };

        iterator begin()
        {
            return iterator(mHead);
        }

        iterator end()
        {
            return iterator(nullptr);
        }
    };
}