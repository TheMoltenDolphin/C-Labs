#include <iostream>
template<typename Type = int, int N = 0, int M = 0>
class Matrix{

private:

    Type** m_elem;
    size_t m_row;
    size_t m_collum;


public:

    Matrix() : m_row(N), m_collum(M), m_elem(nullptr)
    {
        m_elem = new Type*[m_row];
        for(size_t i = 0; i < m_row; i++)
        {
            m_elem[i] = new Type[m_collum];
        }
        fill();
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

    int GetRow() const
    {
        return m_row;
    }

    int GetCollum() const
    {
        return m_collum;
    }

    Type** GetElem()
    {
        return m_elem;
    }


    Matrix operator+(const Matrix& inp)
    {
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
        *this = *this + inp;
        return *this;
    }

    template<int P>
    Matrix<Type, N, P> operator*(Matrix<Type, M, P>& inp)
    {
        Matrix<Type, N, P> result;
        for(size_t i = 0; i < N; i++)
        {
            for(size_t j = 0; j < P; j++)
            {
                result.GetElem()[i][j] = 0;
                for(size_t k = 0; k < M; k++)
                {
                    result.GetElem()[i][j] += m_elem[i][k] * inp.GetElem()[k][j];
                }
            }
        }
        return result;
    }

    template<int P>
    Matrix<Type, N, P>& operator*=(Matrix<Type, M, P>& inp)
    {
        *this = *this * inp;
        return (*this);
    }

    Matrix operator++(Type)
    {
        for(size_t i = 0; i < m_row; i++)
        {
            for(size_t j = 0; j < m_collum; j++)
            {
                m_elem[i][j]++;
            }
        }
        return *this;
    }

    void fill(Type value = Type())
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
    
    template<int P = N, typename std::enable_if<P == M && P != 0 && P < 4, int>::type = 0>
    Type det()
    {   
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
