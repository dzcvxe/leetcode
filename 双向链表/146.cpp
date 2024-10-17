class LRUCache {
public:
    struct node {
        int key, value;
        node* prev;
        node* next;
        node(int key, int value) {
            this->key = key;
            this->value = value;
            prev = NULL;
            next = NULL;
        }
    };
    node* head = NULL;
    node* tail = NULL;
    map<int, node*> mp;
    int cap, size = 0;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp[key] == NULL) {
                return -1;
        }
        int res = mp[key]->value;
        node* target = mp[key];
        if(target == head) {
            return res;
        }
        node* target_prev = target->prev;
        node* target_next = target->next;
        target_prev->next = target_next;
        if(target_next != NULL) {
            target_next->prev = target_prev;
        } else {
            tail = target_prev;
        }
        target->next = head;
        head->prev = target;
        head = target;
        return res;
    }
    
    void put(int key, int value) {
        if(head == NULL) {
            head = new node(key, value);
            tail = head;
            mp[key] = head;
            size++;
            return;
        }
        if(mp[key] != NULL) {
            node* target = mp[key];
            target->value = value;
            if(target == head) {
                return;
            }
            node* target_prev = target->prev;
            node* target_next = target->next;
            target_prev->next = target_next;
            if(target_next != NULL) {
                target_next->prev = target_prev;
            } else {
                tail = target_prev;
            }
            target->next = head;
            head->prev = target;
            head = target;
            return;
        }
        if(size < cap) {
            node* target = new node(key, value);
            target->next = head;
            head->prev = target;
            head = target;
            mp[key] = head;
            size++;
            return;
        }
        node* target = new node(key, value);
        target->next = head;
        head->prev = target;
        head = target;
        mp[key] = head;
        mp[tail->key] = NULL;
        tail->prev->next = NULL;
        tail = tail->prev;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */