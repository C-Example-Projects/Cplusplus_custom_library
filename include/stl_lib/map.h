namespace lib {
    template <typename K, typename V>
    class map {
    private:
        struct Node {
            K key;
            V value;
            Node* next;
            Node(const K& k, const V& v) : key(k), value(v), next(nullptr) {}
        };
        Node* mHead;
        size_t mSize;
    
    public:
        map() : mHead(nullptr), mSize(0) {}

        ~map()
        {
            delete mHead;
        }

        void clear()
        {
            while (mHead->next != nullptr)
            {
                mHead = mHead->next;
            }
            mHead = nullptr;
            mSize = 0;
        }

        void push(const K& key, const V& value)
        {
            Node* newNode = new Node(key, value);
            if (empty())
            {
                mHead = newNode;
                mSize++;
                return;
            }

            if (key < mHead->key)
            {
                newNode->next = mHead;
                mHead = newNode;
            }
            else 
            {
                Node* currentNode = mHead;
                while (currentNode->next != nullptr && currentNode->next->key <= key)
                {
                    currentNode = currentNode->next;
                    if (currentNode->key == key)
                    {
                        currentNode->value = value;
                        delete newNode;
                        return;
                    }
                }

                newNode->next = currentNode->next;
                currentNode->next = newNode;
            }
            mSize++;
        }

        V operator[](const K& key)
        {
            if (mHead->key == key)
            {
                return mHead->value;
            }


            Node* current = mHead;
            do 
            {   
                current = current->next;
            } 
            while(current != nullptr && current->key != key);
            if (current != nullptr && current->key == key)
            {
                return current->value;
            }
            
            return V();
        }

        bool contains(const K& key)
        {
            if (mHead->key == key)
            {
                return true;
            }


            Node* current = mHead;
            do 
            {   
                current = current->next;
            } 
            while(current != nullptr && current->key != key);
            if (current != nullptr && current->key == key)
            {
                return true;
            }

            return false;
        }

        void erase(const size_t& pos)
        {
            if (pos > mSize)
                return; 
                
            Node* current = mHead;
            if (pos == 0)
            {
                mHead = mHead->next;
                delete current;
            }
            else 
            {
                int count = 1;
                do 
                {
                    if (count == pos)
                    {
                        Node* temp = current->next;
                        current->next = current->next->next;
                        delete temp;
                        break;
                    }
                    current = current->next;
                    count++;
                }
                while (current != nullptr);
            }
            --mSize;
        }

        bool empty()
        {
            return mSize == 0;
        }

        size_t size()
        {
            return mSize;
        }

        class iterator {
        private:
            Node* mCurrent;
        public:
            iterator(Node* node) : mCurrent(node) {}

            bool operator!=(const iterator& it)
            {
                return mCurrent != it.mCurrent;
            }

            iterator operator++()
            {
                mCurrent = mCurrent->next;
                return *this;
            }

            K first()
            {
                return mCurrent->key;
            }

            V second()
            {
                return mCurrent->value;
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