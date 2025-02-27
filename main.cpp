#include <iostream>
#include <cstdint>
#include"vector.hpp"


template<>
class MyVector<bool>
{
private:
    std::uint8_t* arr;
    size_t len;

    void set_bit(size_t bit_index)
    {
        arr[bit_index / 8] |= ((std::uint8_t)1 << (bit_index % 8));
    }

    void clear_bit(size_t bit_index)
    {
        arr[bit_index / 8] &= ((char)255 ^ ((char)1 << (bit_index % 8)));
    }

    bool get_bit(size_t index)
    {
        return arr[index / 8] & ((std::uint8_t)1 << (index % 8));
    }


public:
    MyVector<bool>() : arr(nullptr), len(0) {}

    // MyVector(size_t size, bool value)
    // {

    // }

    // MyVector<bool> operator=(MyVector<bool> other)
    // {

    // }

    bool operator[](size_t index)
    {
        return get_bit(index);
    }

    void push_back(bool value)
    {
        if ((len+1) % 8 == 1)
        {
            std::uint8_t* new_arr = new std::uint8_t[(len/8) + 1];

            for (int i = 0; i < (len/8); i++)
            {
                new_arr[i] = arr[i];
            }
            new_arr[len/8] = (std::uint8_t)value;

            len++;
            delete arr;
            arr = new_arr;
        }
        else
        {
            /// With IF?
            arr[len/8] |= ((std::uint8_t)value << (len % 8));
            len++;
        }
    }

    size_t size()
    {
        return len;
    }

    void insert(size_t index, bool value)
    {
        push_back(false);
        for(int i = len-1; i > index; i--)
        {
            if(get_bit(i-1)) {set_bit(i);}
            else {clear_bit(i);}
        }

        if(value) {set_bit(index);}
        else {clear_bit(index);}
    }

    void erase(size_t pos)
    {
        for(int i = pos; i < (len-1); i++)
        {
            if(get_bit(i+1)) set_bit(i);
            else clear_bit(i);
        }

        if((len-1) % 8 == 0)
        {
            std::uint8_t* new_arr = new std::uint8_t[len/8];

            for(int j = 0; j < (len/8); j++)
            {
                new_arr[j] = arr[j];
            }

            delete arr;
            arr = new_arr;
        }
        
        len--;
    }

    void erase(size_t first, size_t last)
    {
        // Redirecting
        if(last == first)
        {
            erase(last);
            return;
        }

        size_t new_len = len - (last - first + 1);


        for(int i = 0; (last + 1 + i) < len; i++)
        {
            if(get_bit(last + 1 + i)) set_bit(first + i);
            else clear_bit(first + i);
        }


        if(((len / 8) != (new_len / 8)) || (new_len % 8 == 0))
        {
            std::uint8_t* new_arr = new std::uint8_t[(new_len/8) + 1*(new_len % 8 != 0)];

            for(int i = 0; i < (new_len/8) + 1*(new_len % 8 != 0); i++)
            {
                new_arr[i] = arr[i];
            }

            delete arr;
            arr = new_arr;
        }
        len = new_len;
    }

};


using MyVectorBool = MyVector<bool>;

int main()
{
    MyVectorBool vec;
    vec.push_back(true);
    vec.push_back(false);
    vec.push_back(false);
    vec.push_back(true);
    vec.push_back(false);
    vec.push_back(false);
    vec.push_back(true);
    vec.push_back(false);
    vec.push_back(true);
    vec.push_back(false);


    vec.erase(0, 5);


    std::cout << "Vec: ";
    for(int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << '\n';

    return 0;
}

