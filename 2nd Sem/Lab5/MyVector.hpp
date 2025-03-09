#include <iostream>
class MyVector{

private:

    int* m_arr;
    size_t m_size;
    size_t m_cap;

public:

    MyVector() : m_arr(nullptr), m_size(0), m_cap(0) {}

    MyVector(size_t InpSize) : m_arr(new int[InpSize]), m_size(InpSize), m_cap(InpSize) {}

    MyVector(const MyVector& inp)
    {
        m_size = inp.m_size;
        m_cap = inp.m_cap;
        m_arr = new int[m_cap];
        for(int i = 0; i < m_size; i++)
        {
            m_arr[i] = inp.m_arr[i];
        }
    }

    ~MyVector()
    {
        if (m_arr != nullptr)
           delete[] m_arr;
    }

    int* GetM_arr()
    {
        return m_arr;
    }

    int* SetM_arr(int* input)
    {
        delete[] m_arr;
        m_arr = input;
    }

    size_t size()
    {
        return m_size;
    }

    size_t capacity()
    {
        return m_cap;
    }

    void reserve(size_t input)
    {
        if(m_size < input)
        {
            m_cap = input;
            int* tmp = new int[m_cap];
            for(int i = 0; i < m_size; i++)
            {
                tmp[i] = m_arr[i];
            }
            delete[] m_arr;
            m_arr = tmp;
        }
    }

    void shrink_to_fit()
    {
        m_cap = m_size;
        int* tmp = new int[m_cap];
        for(int i = 0; i < m_size; i++)
            tmp[i] = m_arr[i];
        delete[] m_arr;
        m_arr = tmp;
    }

    void push_back(int value)
    {
        if(m_size+1 < m_cap)
        {
            m_arr[m_size] = value;
            m_size++;
            return;
        } 

        m_cap = m_cap*2 + 1;

        int* tmp = new int[m_cap];
        for(int i = 0; i < m_size; i++)
            tmp[i] = m_arr[i];
        tmp[m_size] = value;
        m_size++;
        delete[] m_arr;
        m_arr = tmp;
    }

    int& operator[](size_t input)
    {
        return m_arr[input];
    }

    int& front()
    {
        return m_arr[0];
    }   

    int& back()
    {
        return m_arr[m_size-1];
    }

    bool empty()
    {
       return m_size == 0;
    }

    void resize(size_t input, int value = 0)
    {
        if(input > m_size)
        {
            m_cap = input;
            int* tmp = new int[m_cap];
            for(int i = 0; i < m_size; i++)
                tmp[i] = m_arr[i];
            for(int i = m_size; i < input; i++)
                tmp[i] = value;
            delete[] m_arr;
            m_arr = tmp;
            m_size = input;
        }
        else
        {
            m_size = input;
        }
    }

    void erase(size_t input)
    {
        if(input >= m_size)
            return;
        int* tmp = new int[m_cap-1];
        int k = 0;
        for(int i = 0; i < m_cap-1; i++)
        {
            if(i == input)
                k++;
            tmp[i] = m_arr[i+k];
        }
        std::swap(m_arr, tmp);
        m_size--;
        m_cap--;
        delete[] tmp;

    }

    void insert(size_t pos, int amount = 1, int value = 0)
    {
        if(pos >= m_size)
            return;
        int* tmp = new int[m_cap+amount];
        int k = 0;
        for(size_t i = 0; i < m_size+amount; i++)
        {
            if(i == pos)
            {
                for(int j = 0; j < amount; j++)
                {
                    tmp[i+j] = value;
                }
                k = amount;
            }
            tmp[i+k] = m_arr[i];
        }
        std::swap(m_arr, tmp);
        m_cap += amount;
        m_size += amount;
        delete[] tmp;
    }
};