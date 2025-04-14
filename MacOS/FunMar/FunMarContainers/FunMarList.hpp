#pragma once

template <class T>
class FunMarListNode {
public:
    FunMarListNode* next;
    T value;
public:
    
    FunMarListNode(T value_ = T{}, FunMarListNode<T>* next_ = nullptr) : next(next_), value(value_) {}
    FunMarListNode(const FunMarListNode<T>& node) : next(nullptr), value(node.value) {}
    
    ~FunMarListNode() {}
    
    T& getValue() { return value; }
};

template <class T>
class FunMarList {
protected:
    FunMarListNode<T>* head;
public:
    FunMarList(FunMarListNode<T>* head_ = nullptr) : head(head_) {}
    FunMarList(const FunMarList<T>& list) {
        if (list.head == nullptr) {
            head = list.head;
            return;
        }
        head = new FunMarListNode<T>(*list.head);
        FunMarListNode<T>* ptr = list.head;
        FunMarListNode<T>* tail = head;
        while (ptr->next != nullptr) {
            tail->next = new FunMarListNode<T>(*ptr->next);
            tail = tail->next;
            ptr = ptr->next;
        }
    }
    FunMarList(FunMarList&& obj) : head(obj.head) { obj.head = nullptr; }
    
    FunMarList<T>& operator=(const FunMarList<T>& obj) {
        if (this != &obj) {
            while (head != nullptr) {
                FunMarListNode<T>* next = head->next;
                delete head;
                head = next;
            }
            head = new FunMarListNode<T>(*obj.head);
            FunMarListNode<T>* ptr = obj.head;
            FunMarListNode<T>* tail = head;
            while (ptr->next != nullptr) {
                tail->next = new FunMarListNode<T>(*ptr->next);
                tail = tail->next;
                ptr = ptr->next;
            }
        }
        return *this;
    }
    FunMarList<T>& operator=(FunMarList<T>&& obj) noexcept {
        if (this != &obj) {
            while (head != nullptr) {
                FunMarListNode<T>* next = head->next;
                delete head;
                head = next;
            }
            head = obj.head;
            obj.head = nullptr;
        }
        return *this;
    }
    
    ~FunMarList() {
        FunMarListNode<T>* next;
        while (head != nullptr) {
            next = head->next;
            delete head;
            head = next;
        }
    }
    
    class Iterator {
    public:
        FunMarListNode<T>* pointer;
    public:
        Iterator(FunMarListNode<T>* head_ = nullptr) : pointer(head_) {}
        Iterator operator=(const Iterator& iter) { pointer = iter.pointer; return *this; }
        const Iterator operator=(const Iterator& iter) const { pointer = iter.pointer; return *this; }
        
        bool isAtList() const { return pointer != nullptr; }
        bool hasNext() const { return pointer->next != nullptr; }
        void next() { pointer = pointer->next; }
        
        T& getValue() { return pointer->getValue(); }
        const T& getValue() const { return pointer->getValue(); }
    };
    
    Iterator begin() { return Iterator(head); }
    const Iterator begin() const { return Iterator(head); }
};

template <class T>
class FunMarListGenerator {
protected:
    FunMarListNode<T>* head;
    FunMarListNode<T>* tail;
public:
    FunMarListGenerator() {}
    ~FunMarListGenerator() {}
    
    void push(T value) {
        if (head != nullptr) {
            tail->next = new FunMarListNode<T>(value);
            tail = tail->next;
        }
        else {
            tail = head = new FunMarListNode<T>(value);
        }
    }
    
    FunMarList<T> generate() {
        FunMarList temp(head);
        head = tail = nullptr;
        return temp;
    }
};
