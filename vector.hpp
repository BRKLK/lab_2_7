#ifndef VEC_HPP
#define VEC_HPP


template <typename T>
class MyVector
{
private:
    T* arr;
    int len;
    int cap;
    int nextPowerOfTwo(int n);

public:
    MyVector();
    MyVector(int n, T value);
    MyVector(MyVector& other);
    ~MyVector();
    int size() const;
    int capacity() const;
    int& operator[](int index);
    void resize(int new_size, int value = 0);
    void reserve(int new_cap);
    void shrink_to_fit();
    void push_back(T value);
    void insert(int index, T value);
    void erase(int pos);
    void erase(int first, int last);
    int& front();
    int& back();
    bool empty();

};

#endif