#include <iostream>
#include"vector.hpp"

template<>
class MyVector<bool>
{
private:
    char* arr;
    size_t len;

    void set_bit(size_t bit_index)
    {
        arr[bit_index / 8] |= ((char)1 << (bit_index % 8));
    }

    void clear_bit(size_t bit_index)
    {
        arr[bit_index / 8]  ;
    }



public:
    MyVector() : arr(nullptr), len(0) {}

    // MyVector(size_t size, bool value)
    // {

    // }

    // MyVector<bool> operator=(MyVector<bool> other)
    // {

    // }

    bool operator[](size_t index)
    {
        return arr[index / 8] & ((char)1 << (index % 8));
    }

    void push_back(bool value)
    {
        if ((len+1) % 8 == 1)
        {
            char* new_arr = new char[(len/8) + 1];

            for (int i = 0; i < (len/8); i++)
            {
                new_arr[i] = arr[i];
            }
            new_arr[len/8] = (char)value;

            len++;
            delete arr;
            arr = new_arr;
        }
        else
        {
            /// With IF?
            arr[len/8] |= ((char)value << (len % 8));
            len++;
        }
    }

    void insert(size_t index, bool value)
    {
        push_back(false);

    }



};



using MyVectorBool = MyVector<bool>;

int main()
{
    // MyVector<int> vec;

    // vec.push_back(1);
    // vec.push_back(2);
    // vec.push_back(3);
    // vec.push_back(4);

    // std::cout << '\n';
    // for(int i = 0; i < vec.size(); i++)
    // {
    //     std::cout << vec[i] << " ";
    // }

    std::cout << "Content:" << (char)true << "**";

    return 0;
}

