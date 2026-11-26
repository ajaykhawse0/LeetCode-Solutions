class LRUCache {
public:
struct Node{
    int key,val;
    Node*next,*prev;

    Node(int k,int v){
         key = k;
         val = v;
         prev = nullptr;
         next = nullptr;
    }
};

    int capacity;
    unordered_map<int,Node*>mpp;
    Node*head;
    Node*tail;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);;
        

        head->next = tail;
        tail->prev = head;


    }

    void addNewNode(int key,int val){
        Node*temp = head->next;
        Node*newNode =  new Node(key,val);
        newNode->next = temp;
        temp->prev = newNode;
        newNode->prev = head;
        head->next =  newNode;
    }
    void reAddNode(Node*newNode){
        Node*temp = head->next;
        
        newNode->next = temp;
        newNode->prev = head;
        temp->prev = newNode;
        head->next =  newNode;
    }
    void moveToFront(Node*node){
        //Deattach
         node->prev->next = node->next;
         node->next->prev = node->prev;

         //Attach after head

         Node*temp = head->next;
         head->next = node;
         node->next = temp;
         temp->prev = node;
         node->prev = head; 
    }
    void deleteNode(Node*delNode){
        Node*prevNode =  delNode->prev;
        Node*nextNode =  delNode->next;
        prevNode->next = nextNode;
        nextNode->prev =  prevNode;

        // delete delNode;

        return;
    }
    int get(int key) {
        if(mpp.count(key)){
            Node*resNode = mpp[key];

            moveToFront(resNode);

            return resNode->val;
        }

        return -1;
    }
    // int get(int key) {
    //     if(mpp.count(key)){
    //         Node*resNode = mpp[key];
    //         mpp.erase(key);

    //         deleteNode(resNode);
    //         reAddNode(resNode);

    //         mpp[key]=head->next;
    //         return resNode->val;
    //     }

    //     return -1;
    // }
    
    void put(int key, int value) {
        if(mpp.count(key)){
            //node key is already present remove it
            Node*existing = mpp[key];
            existing->val = value;
            moveToFront(existing);
            return ;
        }
        if(mpp.size()==capacity){
            //remove the node from last;
            Node * node = tail->prev;
            int Nodekey = node->key;
            mpp.erase(Nodekey);
            deleteNode(node);
        }

        addNewNode(key,value);
        mpp[key] = head->next;
    }
    // void put(int key, int value) {
    //     if(mpp.count(key)){
    //         //node key is already present remove it
    //         Node*existing = mpp[key];
    //         deleteNode(existing);
    //         mpp.erase(key);
    //     }
    //     if(mpp.size()==capacity){
    //         //remove the node from last;
    //         Node * node = tail->prev;
    //         int Nodekey = node->key;
    //         mpp.erase(Nodekey);
    //         deleteNode(node);
    //     }

    //     addNewNode(key,value);
    //     mpp[key] = head->next;
    // }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */