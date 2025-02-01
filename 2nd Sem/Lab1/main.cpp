#include "main.h"
#include <algorithm>

struct Node
{
	int data;
	Node* prev;
	Node* next;
};

void AddBack(Node* sent, int data)
{
	Node* p  = new Node;
	p->data = data;
	p->next = sent;
	p->prev = sent->prev;
	sent->prev->next = p;
	sent->prev = p;
}

void print(Node* sent)
{
	Node* p = sent->next;
	while (p != sent)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

void clear(Node* sent)
{
	Node* p = sent->next;
	while (p != sent)
	{
		Node* temp = p;
		p = p->next;
		delete temp;
	}
}

int firstNum(int num)
{
	while(num >= 10)
	{
		num /= 10;
	}
	return num;
}

void swap(Node* a, Node* b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

bool IsSimple(int inp)
{
	if(inp == 1)
	{
		return true;
	}
	for(int i = 2; i <= ((int)sqrt(inp) + 1); i++)
	{
		if(inp % i == 0)
		{
			return false;
		}
	}
	return true;
}

void Duplicate10(Node* sent)
{
	Node* p = sent->next;
	while (p != sent)
	{
		if (p->data % 10 == 0)
		{
			Node* temp = new Node;
			temp->data = p->data;
			temp->next = p->next;
			temp->prev = p;
			p->next->prev = temp;
			p->next = temp;
			p = temp->next;
		}
		else
		{
			p = p->next;
		}
	}
}

void RemoveSimple(Node* sent)
{
	Node* p = sent->next;
	while (p != sent)
	{
		if (IsSimple(p->data))
		{
			Node* temp = p;
			p->prev->next = p->next;
			p->next->prev = p->prev;
			p = p->prev;
			delete temp;
		}
		p = p->next;	
	}
}

int EndCount(Node* sent, int num)
{
	int count = 0;
	Node* p = sent-> next;
	while(p != sent)
	{	
		if((p->data)%10 == num)
		{
			count++;
		}
		p = p->next;
	}
	return count;
}



void SortByFirstDigit(Node* sent)
{
	Node* p = sent->next;
	while(p != sent)
	{
		Node* q = p->next;
		while(q != sent)
		{
			if(firstNum(p->data) < firstNum(q->data))
			{
				swap(p, q);
			}
			q = q->next;
		}
		p = p->next;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Node* sent = new Node;
	sent->next = sent;
	sent->prev = sent;
	int n;
	std::cin >> n;
	int inp;
	for(int i = 0; i < n; i++)
	{
		std::cin >> inp;
		AddBack(sent, inp);
	}
	//std::cout << EndCount(sent, 2) << " " << EndCount(sent, 4) << std::endl;
	if((EndCount(sent, 2) + EndCount(sent, 4)) >= 3)
		SortByFirstDigit(sent);
	else
	{
		RemoveSimple(sent);
		Duplicate10(sent);
	}
	print(sent);
	clear(sent);
	delete sent;
}