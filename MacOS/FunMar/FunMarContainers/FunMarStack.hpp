#pragma once

template <class T>
class FunMarStackNode {
public:
    FunMarStackNode* next;
    T value;
public:

    FunMarStackNode(T value_ = T{}, FunMarStackNode<T>* next_ = nullptr) : next(next_), value(value_) {}
    FunMarStackNode(const FunMarStackNode<T>& node) : next(nullptr), value(node.value) {}
    
    ~FunMarStackNode() {}

    T& getValue() { return value; }
};

template <class T>
class FunMarBuffer {
protected:
    size_t step;
    size_t amount;
    FunMarStackNode<T>* head;

    FunMarStackNode<T>* allocateMoreNodes() {
        // static char[sizeof(T)] zeroes = {};
        // static T emptyValue = *( (T*)( zeroes ));
        FunMarStackNode<T>* tail = nullptr;
        for (size_t i = 0; i < step; i++) {
            tail = new FunMarStackNode<T>(T{}, tail);
        }
        amount += step;
        return tail;
    }

    void deallocateNodes() {
        FunMarStackNode<T>* temp;
        for (size_t i = 0; i < step; i++) {
            temp = head->next;
            delete head;
            head = temp;
        }
        amount -= step;
    }
public:
    FunMarBuffer(size_t step_ = 3) : step(step_), amount(0) {
        head = allocateMoreNodes();
    }

    ~FunMarBuffer() {
        FunMarStackNode<T>* next;
        while (head != nullptr) {
            next = head->next;
            delete head;
            head = next;
        }
    }

    FunMarStackNode<T>* getNode() {
        if (head == nullptr) {
            head = allocateMoreNodes();
        }
        amount--;
        FunMarStackNode<T>* temp = head;
        head = head->next;
        temp->next = nullptr;
        return temp;
    }

    void returnNode(FunMarStackNode<T>* node) {
        amount++;
        node->next = head;
        head = node;
        if (amount >= 2 * step) {
            deallocateNodes();
        } 
    }
};

template <class T>
class FunMarStack {
private:
    FunMarStackNode<T>* head;
    FunMarBuffer<T> buffer;
public:
    FunMarStack() { head = nullptr; }
    FunMarStack(const FunMarStack<T>& stack) {
        if (stack.head == nullptr) {
            head = stack.head;
            return;
        }
        head = new FunMarStackNode<T>(*stack.head);
        FunMarStackNode<T>* ptr = stack.head;
        FunMarStackNode<T>* tail = head;
        while (ptr->next != nullptr) {
            tail->next = new FunMarStackNode<T>(*ptr->next);
            tail = tail->next;
            ptr = ptr->next;
        }
    }
    FunMarStack(FunMarStack&& obj) : head(obj.head) { obj.head = nullptr; }

    FunMarStack<T>& operator=(const FunMarStack<T>& obj) {
        if (this != &obj) {
            while (head != nullptr) {
                FunMarStackNode<T>* next = head->next;
                delete head;
                head = next;
            }
            head = new FunMarStackNode<T>(*obj.head);
            FunMarStackNode<T>* ptr = obj.head;
            FunMarStackNode<T>* tail = head;
            while (ptr->next != nullptr) {
                tail->next = new FunMarStackNode<T>(*ptr->next);
                tail = tail->next;
                ptr = ptr->next;
            }
        }
        return *this;
    }
    FunMarStack<T>& operator=(FunMarStack<T>&& obj) noexcept {
        if (this != &obj) {
            while (head != nullptr) {
                FunMarStackNode<T>* next = head->next;
                delete head;
                head = next;
            }
            head = obj.head;
            obj.head = nullptr;
        }
        return *this;
    }

    ~FunMarStack() {
        FunMarStackNode<T>* next;
        while (head != nullptr) {
            next = head->next;
            delete head;
            head = next;
        }
    }

    void push(const T& value) {
        FunMarStackNode<T>* temp = head;
        head = buffer.getNode();
        head->next = temp;
        head->getValue() = value;
    }
    void push(T&& value) {
        FunMarStackNode<T>* temp = head;
        head = buffer.getNode();
        head->next = temp;
        head->getValue() = std::move(value);
    }

    void pop() {
        if (head == nullptr) { throw "invalid operaton!"; }
        FunMarStackNode<T>* temp = head;
        head = head->next;
        buffer.returnNode(temp);
    }

    T& top() {
        return head->getValue();
    }
};