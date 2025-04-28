#pragma once
#include <utility>

template <class T>
class FunMarListNode {
public:
    T value;
    FunMarListNode* next;
public:
    FunMarListNode(const T& value_ = T{}, FunMarListNode<T>* next_ = nullptr) : value(value_), next(next_)  {}
    FunMarListNode(T&& value_, FunMarListNode<T>* next_ = nullptr) : value(std::move(value_)), next(next_) {}

    FunMarListNode(const FunMarListNode<T>& node) : value(node.value), next(nullptr) {}
    FunMarListNode(FunMarListNode<T>&& node) : value(std::move(node.value)), next(nullptr) {}
    
    ~FunMarListNode() {}
    
    T& getValue() { return value; }
    const T& getValue() const { return value; }

    void setValue(const T& value_) { value = value_; }
    void setValue(T&& value_) { value = std::move(value_); }
};

template <class T>
class FunMarList {
protected:
    FunMarListNode<T>* head;
public:
    FunMarList(FunMarListNode<T>* head_ = nullptr) : head(head_) {}
    FunMarList(const FunMarList<T>& list) {
        if (list.head == nullptr) {
            head = nullptr;
            return;
        }
        head = new FunMarListNode<T>(*list.head);
        FunMarListNode<T>* tailList = list.head->next;
        FunMarListNode<T>* tail = head;
        while (tailList != nullptr) {
            tail->next = new FunMarListNode<T>(*tailList);
            tail = tail->next;
            tailList = tailList->next;
        }
    }
    FunMarList(FunMarList&& list) noexcept : head(list.head) { list.head = nullptr; }
    
    FunMarList<T>& operator=(const FunMarList<T>& list) {
        if (this != &list) {
            FunMarListNode<T>* node = head;
            while (node != nullptr) {
                FunMarListNode<T>* next = node->next;
                delete node;
                node = next;
            }
            if (list.head == nullptr) {
                head = nullptr;
                return *this;
            }
            head = new FunMarListNode<T>(*list.head);
            FunMarListNode<T>* tailList = list.head->next;
            FunMarListNode<T>* tail = head;
            while (tailList != nullptr) {
                tail->next = new FunMarListNode<T>(*tailList);
                tail = tail->next;
                tailList = tailList->next;
            }
        }
        return *this;
    }
    FunMarList<T>& operator=(FunMarList<T>&& list) noexcept {
        if (this != &list) {
            std::swap(head, list.head);
        }
        return *this;
    }
    
    ~FunMarList() {
        FunMarListNode<T>* node = head;
        while (node != nullptr) {
            FunMarListNode<T>* next = node->next;
            delete node;
            node = next;
        }
        head = nullptr;
    }

    size_t size() const {
        size_t size = 0;
        FunMarListNode<T>* tail = head;
        while (tail != nullptr) {
            size++;
            tail = tail->next;
        }
        return size;
    }

    bool operator==(const FunMarList& list) const {
        if (head == list.head) { return true; }
        FunMarListNode<T>* tail = head;
        FunMarListNode<T>* tailList = list.head;
        while (tail != nullptr && tailList != nullptr) {
            if (tail->getValue() != tailList->getValue()) { return false; }
            tail = tail->next;
            tailList = tailList->next;
        }
        if (tail != nullptr || tailList != nullptr) { return false; }
        return true;
    }

    bool operator!=(const FunMarList& list) const {
        if (head == list.head) { return false; }
        FunMarListNode<T>* tail = head;
        FunMarListNode<T>* tailList = list.head;
        while (tail != nullptr && tailList != nullptr) {
            if (tail->getValue() != tailList->getValue()) { return true; }
            tail = tail->next;
            tailList = tailList->next;
        }
        if (tail != nullptr || tailList != nullptr) { return true; }
        return false;
    }

    class Iterator;
    class ObserverIterator {
    protected:
        FunMarListNode<T>* pointer;
    public:
        ObserverIterator(FunMarListNode<T>* head_ = nullptr) : pointer(head_) {}
        ObserverIterator(const ObserverIterator& iter) : pointer(iter.pointer) {}
        ObserverIterator(Iterator& iter);

        ~ObserverIterator() = default;

        ObserverIterator& operator=(const ObserverIterator& iter) { pointer = iter.pointer; return *this; }

        bool isAtList() const { return pointer != nullptr; }
        bool hasNext() const { return pointer != nullptr && pointer->next != nullptr; }
        void next() { if (pointer == nullptr) { throw "seg fault incoming"; } pointer = pointer->next; }

        const T& getValue() const { if (pointer == nullptr) { throw "seg fault incoming"; } return pointer->getValue(); }
    };
    
    ObserverIterator begin() const { return ObserverIterator(head); }

    class Iterator : public ObserverIterator {
    protected:
        using ObserverIterator::pointer;
    public:
        FunMarListNode<T>* getPointer() { return pointer; } // must not be used
        using ObserverIterator::ObserverIterator;

        using ObserverIterator::isAtList;
        using ObserverIterator::hasNext;
        using ObserverIterator::next;
    
        using ObserverIterator::getValue;

        T& getValue() { if (ObserverIterator::pointer == nullptr) { throw "seg fault incoming"; } return pointer->getValue(); }

        void setValue(const T& value) { if (pointer == nullptr) { throw "seg fault incoming"; } pointer->setValue(value); } 
        void setValue(T&& value) { if (pointer == nullptr) { throw "seg fault incoming"; } pointer->setValue(std::move(value)); }

        void leftMerge(Iterator& left, const T& value) {
            left.setValue(value);
            left.pointer->next = pointer->next;
            delete pointer;
            pointer = left.pointer;
        }
        void leftMerge(Iterator& left, T&& value) {
            left.setValue(std::move(value));
            left.pointer->next = pointer->next;
            delete pointer;
            pointer = left.pointer;
        }
        void rightMerge(const T& value) {
            setValue(value);
            auto toDelete = pointer->next;
            pointer->next = pointer->next->next;
            delete toDelete;
        }
        void rightMerge(T&& value) {
            setValue(std::move(value));
            auto toDelete = pointer->next;
            pointer->next = pointer->next->next;
            delete toDelete;
        }
    };
    
    Iterator begin() { return Iterator(head); }
};

template <typename T>
FunMarList<T>::ObserverIterator::ObserverIterator(typename FunMarList<T>::Iterator& iter)
    : pointer(iter.getPointer()) {}

template <class T>
class FunMarListGenerator {
protected:
    FunMarListNode<T>* head;
    FunMarListNode<T>* tail;
public:
    FunMarListGenerator() : head(nullptr), tail(nullptr) {}

    ~FunMarListGenerator() {
        FunMarListNode<T>* temp;
        while (head != nullptr) {
            temp = head->next;
            delete head;
            head = temp;
        }
        head = tail = nullptr;
    }
    
    void push(const T& value) {
        if (head != nullptr) {
            tail->next = new FunMarListNode<T>(value);
            tail = tail->next;
        }
        else {
            tail = head = new FunMarListNode<T>(value);
        }
    }

    void push(T&& value) {
        if (head != nullptr) {
            tail->next = new FunMarListNode<T>(std::move(value));
            tail = tail->next;
        }
        else {
            tail = head = new FunMarListNode<T>(std::move(value));
        }
    }
    
    FunMarList<T> generate() {
        FunMarList temp(head);
        head = tail = nullptr;
        return temp;
    }
};
