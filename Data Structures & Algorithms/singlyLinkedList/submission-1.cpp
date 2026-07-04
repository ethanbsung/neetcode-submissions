class Node {
public:
    int val;
    Node* next;
    Node(int val) : val(val), next(nullptr) {}
    Node(int val, Node* next) : val(val), next(next) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = new Node(-1);
        tail = head;
    }

    int get(int index) {
        Node* temp = head->next;
        int current = 0;
        while (temp != nullptr) {
            if (current == index) {
                return temp->val;
            }
            temp = temp->next;
            current++;
        }
        return -1;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head->next;
        head->next = newNode;
        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }
    
    void insertTail(int val) {
        Node* newNode = new Node(val);
        tail->next = newNode;
        tail = tail->next;
    }

    bool remove(int index) {
        Node* temp = head;
        int i = 0;
        while (i < index && temp != nullptr) {
            temp = temp->next;
            i++;
        }
        if (temp != nullptr && temp->next != nullptr) {
            if (temp->next == tail) {
                tail = temp;
            }
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            return true;
        }
        return false;
    }

    vector<int> getValues() {
        Node* temp = head->next;
        vector<int> v;
        while (temp != nullptr) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        
        
        return v;

    }
};
