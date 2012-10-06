/**
 *描述：栈
 *		List classes
 *作者：04软件工程4班 罗胜舟
 *学号：200433125181
 *最后更新：2006年3月6日
**/

#include "predefine.h"
//----------------------------------------------------------------
//栈
template <class Elem>
class Stack//Stack abstract class
{
	virtual void clear() = 0;
	virtual bool push(const Elem &item) = 0;
	virtual bool pop(Elem &it) = 0;
	virtual bool topValue(Elem &it) const = 0;
	virtual int length() const = 0;
};
//----------------------------------------------------------------
template <class Elem>
class AStack: public Stack<Elem>//Array-based stack implementaion
{
private:
	int size;
	int top;
	Elem *listArray;
public:
	AStack(int sz = DefaultListSize)
	{
		size = sz;
		top = 0;
		listArray = new Elem[sz];
	}
	~AStack()
	{
		delete [] listArray;
	}
	void clear()
	{
		top = 0;
	}
	bool push(const Elem &item)
	{
		if(top == size)
			return false;
		else
		{
			listArray[top++] = item;
			return true;
		}
	}
	bool pop(Elem &it)
	{
		if(top == 0)
			return false;
		else
		{
			it = listArray[--top];
			return true;
		}
	}
	bool topValue(Elem &it)const
	{
		if(top == 0)
			return false;
		else
		{
			it = listArray[top-1];
			return true;
		}
	}
	int length()const
	{
		return top;
	}
};
//----------------------------------------------------------------
template <class Elem>
class DAStack: public Stack<Elem>//Double array-based stack implementaion
{
private:
	int size;
	int top, topB;
	Elem *listArray;
public:
	DAStack(int sz = DefaultListSize)
	{
		size = sz;
		topB = top = 0;
		listArray = new Elem[sz];
	}
	~DAStack()
	{
		delete [] listArray;
	}
	void clear()
	{
		top = 0;
	}
	void clearB()
	{
		topB = 0;
	}
	void clearBoth()
	{
		topB = topA = 0;
	}
	bool push(const Elem &item)
	{
		if(top == size)
			return false;
		else
		{
			listArray[top++] = item;
			return true;
		}
	}
	bool pushB(const Elem &item)
	{
		if(topB == size)
			return false;
		else
		{
			listArray[size-1-topB++] = item;
			return true;
		}
	}
	bool pop(Elem &it)
	{
		if(top == 0)
			return false;
		else
		{
			it = listArray[--top];
			return true;
		}
	}
	bool popB(Elem &it)
	{
		if(topB == 0)
			return false;
		else
		{
			it = listArray[size-1-(--topB)];
			return true;
		}
	}
	bool topValue(Elem &it)const
	{
		if(top == 0)
			return false;
		else
		{
			it = listArray[top-1];
			return true;
		}
	}
	bool topValueB(Elem &it)const
	{
		if(topB == 0)
			return false;
		else
		{
			it = listArray[size-topB];
			return true;
		}
	}
	int length()const
	{
		return top;
	}
	int lengthB()const
	{
		return topB;
	}
};
//----------------------------------------------------------------
