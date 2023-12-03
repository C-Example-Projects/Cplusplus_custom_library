#include <algorithm>

namespace lib {
    template <typename T>
    class vector {
    private: 
        T* mData;
        size_t mSize;
        size_t mCapacity;
    public: 
        vector() : mData(nullptr), mSize(0), mCapacity(0) {}

        ~vector() 
        {
            delete[] mData;
        }

        void push(const T& val)
        {
            if (mSize == mCapacity)
            {
                reserve(std::max(1, static_cast<int>(mCapacity) * 2));
            }

            mData[mSize++] = val;
        }

        void reserve(const int& capacity)
        {
            if (capacity > mCapacity)
            {
                T* newData = new T[capacity];

                if (mSize > 0)
                {
                    for (int i = 0; i < capacity; ++i)
                    {
                        newData[i] = mData[i];
                    }
                }

                delete[] mData;
                mData = newData;
                mCapacity = capacity;
            }
        }

        T size()
        {
            return mSize;
        }

        void pop()
        {
            T* newData = new T[--mSize];
            for (size_t i = 0; i < mSize; ++i)
            {
                newData[i] = mData[i];
            }
            delete[] mData;
            mData = newData;
        }

        void clear()
        {
            mSize = 0;
            mCapacity = 0;
            mData = nullptr;
        }

        T operator[](const size_t& index)
        {
            return mData[index];
        }
    };
}