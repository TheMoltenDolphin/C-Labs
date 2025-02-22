#pragma once
#include "main.h"
#include <string>
class BigInt
{
	public:

		BigInt()
		{
			m_size = 0;
			m_nums = nullptr;
		}

		BigInt(std::string inp)
		: m_size(inp.length()), m_nums(new short[m_size])
		{
			for(short i = 0; i < m_size; i++)
				m_nums[i] = inp[i]-48;
		}

		BigInt(const BigInt& tmp) : BigInt(IntToStr(tmp.m_nums, tmp.m_size)) {}

		BigInt& operator=(BigInt other)
		{
			swap(*this, other);
			return *this;
		}

		BigInt operator+(const BigInt& other)
		{
			short size = std::max(m_size, other.m_size)+1;
			short* res = new short[size] {0};
			short mini = std::min(m_size, other.m_size);

			for(short i = 0; i < mini; i++)
			{
				short tmp = m_nums[m_size-i-1] + other.m_nums[other.m_size-i-1];
				res[size-i-1] += tmp % 10;
				res[size-i-2] += tmp / 10;
			}
			if (m_size > other.m_size)
				for(short i = mini; i < size; i++)
					res[size-i] = m_nums[size-i];
	
			else if (m_size < other.m_size)
				for(short i = mini; i < size; i++)
					res[size-i] = other.m_nums[size-i];
		
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
			short size = m_size + other.m_size;
			short mini = std::min(m_size, other.m_size);
			short* res = new short[size] {0};
			for(int i = 0; i < m_size; i++)
				for(int j = 0; j < other.m_size; j++)
				{
					res[size-i-j-1] += m_nums[m_size-i-1] * other.m_nums[other.m_size-j-1];
					res[size-i-j-2] += res[size-i-j-1] / 10;
					res[size-i-j-1] %= 10;
				}
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
			unsigned short IsTrue = ((m_size < other.m_size) * !(m_size > other.m_size) == 1 ? 1 : 2);
			if (IsTrue == 1)
				return true;
			if (IsTrue == 2)
				for(short i = 0; i < m_size; i++)
					if (m_nums[i] < other.m_nums[i])
						return true;
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

		std::string IntToStr(short* inp, short n)
		{
			std::string out = "";
			for(short i = 0; i < n; i++)
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

		short m_size;
		//std::string m_inp;
		short* m_nums;

		void swap(BigInt& a, BigInt& b)
		{
			std::swap(a.m_size, b.m_size);
			std::swap(a.m_nums, b.m_nums);
		}

};

std::ostream& operator << (std::ostream &os, const BigInt &migint)
{
	for(short i = 0; i < migint.m_size; i++)
		os << migint.m_nums[i];
	return os;
}

std::istream& operator >> (std::istream &in, BigInt &migint)
{	
	std::string inp;
	in >> inp;
	if(migint.m_nums == nullptr)
	{
		migint.m_size = inp.length();
		migint.m_nums = new short[migint.m_size];
		for(short i = 0; i < migint.m_size; i++)
			migint.m_nums[i] = inp[i]-48;
	}
	else
		std::cerr << "Object is not empty!";
	return in;
}