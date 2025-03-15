#include <iostream>
template<typename Type>
class Matrix{

private:

    size_t m_collum;
    size_t m_row;
    Type** m_elem;


public:

    Matrix() : m_elem(nullptr), m_collum(0), m_row(0) {}

    Matrix(size_t cols, size_t rows, Type fill_item = Type()) : m_collum(cols), m_row(rows), m_elem(new Type*[rows])
    {
        for(size_t i = 0; i < m_row; i++)
        {
            m_elem[i] = new Type[cols];
        }
        fill(fill_item);
    }

    Matrix(const Matrix& inp)
    {
        m_collum = inp.m_collum;
        m_row = inp.m_row;
        m_elem = new Type*[m_row];
        for(size_t i = 0; i < m_row; i++)
        {
            m_elem[i] = new Type[m_collum];
        }
        for(size_t i = 0; i < m_row; i++)
        {
            for(size_t j = 0; j < m_collum; j++)
            {
                m_elem[i][j] = inp.m_elem[i][j];
            }
        }
    }

    ~Matrix()
    {
        if (m_elem != nullptr)
            for(size_t i = 0; i < m_row; i++)
                delete[] m_elem[i];
           delete[] m_elem;
    }

    Matrix& operator=(const Matrix& inp)
    {
        if (this == &inp)
            return *this;
        if (m_elem != nullptr)
            for(size_t i = 0; i < m_row; i++)
                delete[] m_elem[i];
        delete[] m_elem;
        m_collum = inp.m_collum;
        m_row = inp.m_row;
        m_elem = new Type*[m_row];
        for(size_t i = 0; i < m_row; i++)
        {
            m_elem[i] = new Type[m_collum];
        }
        for(size_t i = 0; i < m_row; i++)
        {
            for(size_t j = 0; j < m_collum; j++)
            {
                m_elem[i][j] = inp.m_elem[i][j];
            }
        }
        return *this;
    }

    Matrix operator+(const Matrix& inp)
    {
        if (m_row != inp.m_row || m_collum != inp.m_collum)
        {
            std::cout << "Матрицы разных размеров" << std::endl;
            return *this;
        }
        for(size_t i = 0; i < m_row; i++)
        {
            for(size_t j = 0; j < m_collum; j++)
            {
                m_elem[i][j] += inp.m_elem[i][j];
            }
        }
        return *this;
    }

    Matrix& operator+=(const Matrix& inp)
    {
        return *this + inp;
    }

    Matrix operator*(const Matrix& inp)
    {
        if(m_collum != inp.m_row)
        {
            return *this;
        }
        for(size_t i = 0; i < m_row; i++)
        {
            for(size_t j = 0; j < inp.m_collum; j++)
            {
                m_elem[i][j] = 0;
                for(size_t k = 0; k < m_collum; k++)
                {
                    m_elem[i][j] += m_elem[i][k] * inp.m_elem[k][j];
                }
            }
        }
        return *this;
    }

    Matrix& operator*=(const Matrix& inp)
    {
        return *this * inp;
    }

    Matrix& operator++()
    {
        for(int i = 0; i < m_row; i++)
        {
            for(int j = 0; j < m_collum; j++)
            {
                m_elem[i][j]++;
            }
        }
        return *this;
    }

    void fill(Type value)
    {
        if(m_row == 0 || m_collum == 0)
            return;
        if (m_elem == nullptr)
        {
            m_elem = new Type*[m_row];
            for(size_t i = 0; i < m_row; i++)
            {
                m_elem[i] = new Type[m_collum];
            }
        }
        for(size_t i = 0; i < m_row; i++)
        {
            for(size_t j = 0; j < m_collum; j++)
            {
                m_elem[i][j] = value;
            }
        }
    }

    int det()
    {   
        if(m_collum == 0 || m_row == 0 || m_collum != m_row || m_elem == nullptr)
        {
            return -1;
        }
        if(m_collum == 1)
        {
            return m_elem[0][0];
        }
        if(m_collum == 2)
        {
            return m_elem[0][0] * m_elem[1][1] - m_elem[0][1] * m_elem[1][0];
        }
        if(m_collum == 3)
        {
            return m_elem[0][0] * (m_elem[1][1] * m_elem[2][2] - m_elem[1][2] * m_elem[2][1]) -
                   m_elem[0][1] * (m_elem[1][0] * m_elem[2][2] - m_elem[1][2] * m_elem[2][0]) +
                   m_elem[0][2] * (m_elem[1][0] * m_elem[2][1] - m_elem[1][1] * m_elem[2][0]);
        }
    }

    Type* operator[](size_t i)
    {
        return m_elem[i];
    }

    bool empty()
    {
       return m_row == 0 && m_collum == 0;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
    {
        for(size_t i = 0; i < matrix.m_row; i++)
        {
            for(size_t j = 0; j < matrix.m_collum; j++)
            {
                os << matrix.m_elem[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Matrix& matrix)
    {
        for(size_t i = 0; i < matrix.m_row; i++)
        {
            for(size_t j = 0; j < matrix.m_collum; j++)
            {
                is >> matrix.m_elem[i][j];
            }
        }
        return is;
    }
};

