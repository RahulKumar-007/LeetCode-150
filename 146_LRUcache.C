/*



   Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.



Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4


Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
*/



class LRUCache {
public:
    // declaring our data structures
    class Node {
    public:
        int key;
        int val;
        Node *prev;
        Node *next;

        Node (int key, int val) {
            this->key = key;
            this->val = val;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node *head = nullptr;
    Node *tail = nullptr;

    unordered_map <int, Node*> map;
    int cap;
    int currSize = 0;

// functions
    LRUCache(int capacity) {
        cap = capacity;
    }

    void pushToEnd (Node *node) {
        if (node == tail) return;
        if (node == head) {
            head = node->next;
        }
        else {
            node->prev->next = node->next;
        }
        node->next->prev = node->prev;
        node->next = nullptr;
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    void deleteLRUnode () {
        Node *temp = head->next;
        map.erase(head->key);
        delete head;
        if (!temp) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = temp;
        }
        currSize--;
        return;
    }

    void addToEnd (Node *node) {
        map[node->key] = node;
        if (!tail) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        currSize++;
    }


// main functions to be implemented

    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        Node *curr = map[key];
        pushToEnd (curr);

        return curr->val;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            Node *curr = map[key];
            curr->val = value;
            pushToEnd(curr);
        }
        else {
            Node *newnode = new Node (key, value);
            if (currSize == cap) {
                deleteLRUnode();
            }
            addToEnd(newnode);
        }
    }
};
