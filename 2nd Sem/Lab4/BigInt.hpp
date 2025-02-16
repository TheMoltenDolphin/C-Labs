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
			int size = std::max(m_size, other.m_size);
			if(m_nums[0]+other.m_nums[0] > 9)
			{
				size++;
			}
			int res[3];
			int mini = std::min(m_size, other.m_size);

			res[size-1] = 0;
			for(int i = 0; i < mini; i++)
			{
				int tmp = m_nums[m_size-i-1] + other.m_nums[other.m_size-i-1];
				res[size-i-1] += tmp % 10;
				res[size-i-2] = 0;
				res[size-i-2] += tmp / 10;
			}
			BigInt result = IntToStr(res, size);
			return result;
		}

		BigInt& operator+=(BigInt other)
		{
			*this = *this + other;
			return *this;
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
			return out;
		}

		friend std::ostream& operator << (std::ostream &os, const BigInt &migint);
		friend std::istream& operator >> (std::istream &in, BigInt &migint);

		int m_size;
		//std::string m_inp;
		int* m_nums;

	private:


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
	os << std::endl;
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