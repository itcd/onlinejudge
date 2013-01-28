#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>

template<class T>
class Tree
{
public:
	int numberOfComparisons;

	Tree(void)
	{
		root = NULL;
		numberOfComparisons = 0;
	}

	~Tree(void)
	{
		if (root)
		{
			deleteNodes(root);
			cout<<"Tree deleted."<<endl;
			root = NULL;
		}
	}

	// add student to list
	void add(T *new_flight)
	{
		T *p, *pp;
		int r;

		//
		// insert into alphabetically ordered tree
		//
		if (root == NULL) {
			root = new_flight;
		} else {
			//cout <<"in else"<<endl;
			p = root;   //current
			pp = NULL; //parent pointer
			while (p) {
				pp = p;

				//r = (new_flight->flightNumber).compare(p->flightNumber);
				r = new_flight->cmp(p);

				if (r > 0 )
				{
					//cout <<"going right" <<endl;
					p = p->right;
				}
				else 
				{
					//cout <<"going left" <<endl;
					p = p->left;
				}
			}

			if (r > 0) 
			{
				pp->right = new_flight; 

			} else {
				pp->left = new_flight;
			}
		}
	}

	// write to file
	void write(string filename)
	{
		ofstream out(filename);

		if (out.fail()) {
			cout << "unable to open " << filename << endl;
			return;
		}

		write(root, out);
	}

	void write(T *p, ofstream &out)
	{
		if (p)
		{
			write(p->left, out);

			//out << left << setw(16) << p->lastName; 
			//out << setw(16) << p->firstName;
			//out << setfill('0') << right << setw(8) << p->id << setfill(' ');
			//out << setw(4) << p->mark;
			//out << endl;

			out << p->to_string();

			write(p->right, out);
		}
	}

	T* FindStudent (string f, string l)
	{
		T s;
		s.firstName = f;
		s.lastName = l;
		numberOfComparisons = 0;
		return FindStudent(root, s);
	}

	T *FindStudent(T *current, T &target)
	{
		if (current)
		{
			numberOfComparisons++;
			if (target.cmp(current) < 0)
			{
				return FindStudent(current->left, target);
			} 
			else
			{
				if (target.cmp(current) > 0)
				{
					return FindStudent(current->right, target);
				} 
				else
				{
					cout << "Number Of Comparisons made:" << numberOfComparisons << endl;
					return current;
				}
			}
		} 
		else
		{
			cout<<"Not found!"<<endl;
			cout << "Number Of Comparisons made:" << numberOfComparisons << endl;
			return NULL;
		}
	}

private:
	T *root;				// head of list

	void deleteNodes(T *current)
	{
		if (current)
		{
			deleteNodes(current->left);
			deleteNodes(current->right);
			delete current;
		}
	}
};
