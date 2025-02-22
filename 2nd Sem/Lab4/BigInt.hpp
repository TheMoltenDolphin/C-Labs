#pragma once
#include "main.h"
#include <string>
class BigInt
{
	public:

		BigInt()
		{
			m_size = 0;
			//m_inp = "";
			m_nums = nullptr;
			std::cout << "Empty constructor" << std::endl;
		}

		BigInt(std::string inp)
		: m_size(inp.length()), m_nums(new int[m_size])
		{
			for(int i = 0; i < m_size; i++)
			{
				m_nums[i] = inp[i]-48;
			}
		}

		BigInt(const BigInt& tmp) : BigInt(IntToStr(tmp.m_nums, tmp.m_size)) {}

		BigInt& operator=(BigInt other)
		{
			swap(*this, other);
			return *this;
		}

		BigInt operator+(const BigInt& other)
		{
			int size = std::max(m_size, other.m_size)+1;
			int* res = new int[size] {0};
			int mini = std::min(m_size, other.m_size);

			for(int i = 0; i < mini; i++)
			{
				int tmp = m_nums[m_size-i-1] + other.m_nums[other.m_size-i-1];
				res[size-i-1] += tmp % 10;
				res[size-i-2] += tmp / 10;
			}
			if (m_size > other.m_size)
			{
				for(int i = mini; i < size; i++)
				{
					res[size-i] = m_nums[i];
				}
			}
			else if (m_size < other.m_size)
			{
				for(int i = mini; i < size; i++)
				{
					res[size-i] = other.m_nums[size-i];

				}
			}
			// for(int i = 0; i < size; i++)
			// {
			// 	std::cout << res[i];
			// }
			BigInt result = IntToStr(res, size);
			delete[] res;
			return result;
		}


		BigInt& operator+=(BigInt other)
		{
			*this = *this + other;
			return *this;
		}
		
		BigInt operator*(const BigInt& other)
		{
			int size = m_size + other.m_size;
			int mini = std::min(m_size, other.m_size);
			int* res = new int[size] {0};
			for(int i = 0; i < m_size; i++)
			{
				for(int j = 0; j < other.m_size; j++)
				{
					res[size-i-j-1] += m_nums[m_size-i-1] * other.m_nums[other.m_size-j-1];
					res[size-i-j-2] += res[size-i-j-1] / 10;
					res[size-i-j-1] %= 10;
				}
			}
			// for(int i = 0; i < size; i++)
			// {
			// 	std::cout << res[i];
			// }
			BigInt result = IntToStr(res, size);
			delete[] res;
			return result;
		}

		BigInt& operator*=(BigInt other)
		{
			*this = *this * other;
			return *this;
		}

		bool operator<(BigInt& other)
		{			
			int IsTrue = (m_size < other.m_size) ?  1 : ((m_size > other.m_size) ? 2 : 3);
			if (IsTrue == 1)
				return true;
			if (IsTrue == 3)
				for(int i = 0; i < m_size; i++)
				{
					if (m_nums[i] < other.m_nums[i])
					{
						return true;
					}
				}
			return false;
		}

		bool operator>(BigInt& other)
		{
			return !(*this < other) * !(*this==other);
		}
	
		bool operator==(BigInt& other)
		{
			return (!(*this < other) * !(other < *this));
		}

		bool operator!=(BigInt& other)
		{
			return !(*this == other);
		}

		~BigInt()
		{
			if(m_nums != nullptr)
				delete[] m_nums;
		}

		std::string IntToStr(int* inp, int n)
		{
			std::string out = "";
			for(int i = 0; i < n; i++)
			{
				out += std::to_string(inp[i]);
			}
			if (out[0] == '0')
			{
				out.erase(0,1);
			}
			return out;
		}

		friend std::ostream& operator << (std::ostream &os, const BigInt &migint);
		friend std::istream& operator >> (std::istream &in, BigInt &migint);



	private:

		int m_size;
		//std::string m_inp;
		int* m_nums;
		void swap(BigInt& a, BigInt& b)
		{
			std::swap(a.m_size, b.m_size);
			std::swap(a.m_nums, b.m_nums);
		}

};

std::ostream& operator << (std::ostream &os, const BigInt &migint)
{
	for(int i = 0; i < migint.m_size; i++)
	{
		os << migint.m_nums[i];
	}
	return os;
}

std::istream& operator >> (std::istream &in, BigInt &migint)
{	
	std::string inp;
	in >> inp;
	if(migint.m_nums == nullptr)
	{
		
		migint.m_size = inp.length()+1;
		migint.m_nums = new int[migint.m_size];
		for(int i = 0; i < migint.m_size; i++)
		{
			migint.m_nums[i] = inp[i]-48;
		}
	}
	else
	{
		std::cerr << "Object is not empty!";
	}
	return in;
}