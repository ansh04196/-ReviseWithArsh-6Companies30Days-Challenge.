class LRUCache {
public:
    struct CacheNode {
        int key, value;
        CacheNode *prev, *next;

        CacheNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    CacheNode *head, *tail;
    unordered_map<int, CacheNode *> cache;

    LRUCache(int initialCapacity) {
        capacity = initialCapacity;
        head = new CacheNode(-1, -1);
        tail = new CacheNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(CacheNode *node) {
        CacheNode *prevNode = node->prev;
        CacheNode *nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void addNodeToFront(CacheNode *node) {
        CacheNode *nextNode = head->next;
        head->next = node;
        node->next = nextNode;
        node->prev = head;
        nextNode->prev = node;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1; // Key not found
        }

        CacheNode *address = cache[key];
        int value = address->value;

        // Move the accessed node to the front
        deleteNode(address);
        addNodeToFront(address);

        return value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key exists, update the value and move to the front
            CacheNode *existingNode = cache[key];
            deleteNode(existingNode);
            addNodeToFront(existingNode);
            head->next->value = value;
        } else {
            if (cache.size() == capacity) {
                // Evict the least recently used node
                cache.erase(tail->prev->key);
                deleteNode(tail->prev);
            }

            // Add the new node to the front
            addNodeToFront(new CacheNode(key, value));
            cache[key] = head->next;
        }
    }
};
