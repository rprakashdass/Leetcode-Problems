class Node {
public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int k, int v): key(k), value(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    int size;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> cache;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insertAtHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
public:
    LRUCache(int cap): capacity(cap), size(0) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    int get(int key) {
        if(cache.find(key) == cache.end()) {
            return -1;
        }
        Node* node = cache[key];
        remove(node);
        insertAtHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insertAtHead(node);
            node->value = value;
        } else {
            if(cache.size() == capacity) {
                Node* lru = tail->prev;
                remove(lru);
                cache.erase(lru->key);
                delete lru;
            }
            Node* node = new Node(key, value);
            insertAtHead(node);
            cache[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
