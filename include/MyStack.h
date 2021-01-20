// Copyright [2020] <Olesya Nikolaeva>

#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template <typename  T>
class MyStack {
 private:
    T *stack;
    int max;
    int topindex;

 public:
    explicit MyStack(int size) {
        max = size;
        topindex = -1;
        stack = new T[size];
    }
    MyStack(const MyStack &stack) {
        this->max = stack.max;
        this->topindex = stack.topindex;
        this->stack = new T[this->max];
        for (int i = 0; i < this->max; ++i)
            this->stack[i] = stack.stack[i];
    }
    ~MyStack() {
        delete[] stack;
        max = 0;
        topindex = -1;
    }
    T get() const {
        return stack[topindex];
    }
    T pop() {
        return stack[topindex--];
    }
    void push(T arg) {
        if (topindex < max - 1) {
            topindex++;
            stack[topindex] = arg;
        }
    }
    bool isFull() const {
        if (topindex >= max - 1)
            return true;
        return false;
    }
    bool isEmpty() const {
        if (topindex == -1)
            return true;
        return false;
    }
    int getIndex() const {
        return topindex;
    }
};

#endif  // INCLUDE_MYSTACK_H_
