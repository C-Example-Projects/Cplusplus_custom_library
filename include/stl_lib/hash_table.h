#include <vector>
#include <utility>

namespace lib {
    template <typename K, typename V>
    class hashtable {
    private: 
        static const size_t TABLE_SIZE = 100;
        using Node = std::pair<K, V>;
        std::vector<std::vector<Node>> mTable;

        size_t hash(const K& key)
        {
            return std::hash<K>{}(key) % TABLE_SIZE;
        }

    public:
        hashtable() : mTable(TABLE_SIZE) {}

        void insert(const K& key, const V& value)
        {
            size_t index = hash(key);
            mTable[index].push_back(std::make_pair(key, value));
        }

        bool find(const K& key, V& result)
        {
            size_t index = hash(key);
            for (const auto& node : mTable[index])
            {
                if (node.first == key)
                {
                    result = node.second;
                    return true;
                }
            }
            return false;
        }

        void remove(const K& key) {
            size_t index = hash(key);

            auto it = mTable[index].begin();
            while (it != mTable[index].end()) {
                if (it->first == key) {
                    it = mTable[index].erase(it);
                } else {
                    ++it;
                }
            }
            //mTable[index].remove_if([key](const Node& node) { return node.first == key; });
        }

        void display() const {
            for (size_t i = 0; i < TABLE_SIZE; ++i) {
                std::cout << "Bucket " << i << ": ";
                for (const auto& node : mTable[i]) {
                    std::cout << "(" << node.first << ", " << node.second << ") ";
                }
                std::cout << std::endl;
            }
        }
    };
}