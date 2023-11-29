#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Screen
{
public:
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos w, pos h) :witch(w),hign(h),contents(w*h,' ') {}
	Screen(pos w, pos h, char c) : witch(w),hign(h), contents(w*h,c) {}
	Screen& move(pos w, pos h) // 移动到指定光标
	{
		pos pow = h * witch;
		current = pow + w;
		return *this;
	}
	Screen& move(int num)//向后或向前移动光标
	{
		if (num < 0)
		{
			if (0 - num > current)
			{
				current = (pos)(num % (witch * hign) + current + witch * hign);
			}
			else
			{
				current = (pos)(num + current);
			}
		}
		else
			current = (num + current) % (witch * hign);
		return *this;
	}
	Screen& set(char c)
	{
		contents[current] = c;
		return *this;
	}
	Screen& set(pos w, pos h, char c)
	{
		contents[h * hign + w] = c;
		return *this;
	}
	Screen& display()
	{
		cout << contents;
		return *this;
	}

private:
	pos witch = 0;
	pos hign = 0;
	pos current = 0;
	string contents;

};

