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
		}
		BigInt(std::string inp)
		: m_size(inp.length()+1), m_nums(new int[m_size])
		{
			for(int i = 0; i < m_size-1; i++)
			{
				m_nums[i] = inp[i]-48;
			}
		}
		BigInt(const BigInt& other) : BigInt(IntToStr(other.m_nums, other.m_size)) {}
		BigInt& operator=(BigInt tmp)
		{
			swap(*this, tmp);
			return *this;
		}

		std::string IntToStr(int* inp, int n)
		{
			std::string out = "";
			for(int i = 0; i < n-1; i++)
			{
				out += std::to_string(inp[i]);
			}
			return out;
		}
		~BigInt()
		{
			if(m_nums != nullptr)
				delete[] m_nums;
		}
		char print()
		{
			
		}
		char GetValue() const
		{
			return (char)m_nums[1];
		}
		void Setup(BigInt inp)
		{
			swap(*this, inp);

		}
		friend std::ostream& operator << (std::ostream &os, const BigInt &bigint);
		friend std::istream& operator >> (std::istream &in, BigInt &bigint);
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

std::ostream& operator << (std::ostream &os, const BigInt &bigint)
{	
	for(int i = 0; i < bigint.m_size-1; i++)
		os << bigint.m_nums[i];
		os << std::endl;
	return os;
}

std::istream& operator >> (std::istream &in, BigInt &bigint)
{	
	std::string inp;
	in >> inp;
	if(bigint.m_nums == nullptr)
	{
		
		bigint.m_size = inp.length()+1;
		bigint.m_nums = new int[bigint.m_size];
		for(int i = 0; i < bigint.m_size-1; i++)
		{
			bigint.m_nums[i] = inp[i]-48;
		}
	}
	else
	{
		std::cerr << "Object is not empty!";
	}
	return in;
}