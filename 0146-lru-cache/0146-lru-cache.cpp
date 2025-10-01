class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k1, int v1){
            key=k1;
            value=v1;
        }
    };
class LRUCache {
public:
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int, Node*> mpp;
    int cap;

    void deleteNodeFromBack(Node* nodeToDelete){
        Node* prevNode = nodeToDelete->prev;
        Node* nextNode = nodeToDelete->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void addNodeToFront(Node* nodeToAdd){
        Node* nextNode = head->next;
        head->next = nodeToAdd;
        nodeToAdd->prev=head;
        nodeToAdd->next = nextNode;
        nextNode->prev = nodeToAdd;
    }

    LRUCache(int capacity) {
        cap=capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            //found key
            Node* foundNode=mpp[key];
            int ans = foundNode->value;
            mpp.erase(key);
            //move to the front
            deleteNodeFromBack(foundNode);
            addNodeToFront(foundNode);
            mpp[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* existingNode = mpp[key];
            mpp.erase(key);   
            deleteNodeFromBack(existingNode);
        }
        if(mpp.size()==cap){
            //max reached, delete the last used node
            mpp.erase(tail->prev->key);
            deleteNodeFromBack(tail->prev);
        }
        addNodeToFront(new Node(key,value));
            mpp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */