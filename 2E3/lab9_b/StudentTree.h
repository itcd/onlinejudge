#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include "StudentNode.h"

class StudentTree
{
public:
	int numberOfComparisons;

	StudentTree(void)
	{
		root = NULL;
		numberOfComparisons = 0;
	}

	~StudentTree(void)
	{
		if (root)
		{
			deleteNodes(root);
			cout<<"Tree deleted."<<endl;
			root = NULL;
		}
	}

	// add student to list
	void add(StudentNode *new_flight)
	{
		StudentNode *p, *pp;
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

	void write(StudentNode *p, ofstream &out)
	{
		if (p)
		{
			write(p->left, out);

			out << left << setw(16) << p->lastName; 
			out << setw(16) << p->firstName;
			out << setfill('0') << right << setw(8) << p->id << setfill(' ');
			out << setw(4) << p->mark;
			out << endl;

			write(p->right, out);
		}
	}

	StudentNode* FindStudent (string f, string l)
	{
		StudentNode s;
		s.firstName = f;
		s.lastName = l;
		numberOfComparisons = 0;
		return FindStudent(root, s);
	}

	StudentNode *FindStudent(StudentNode *current, StudentNode &target)
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
	StudentNode *root;				// head of list

	void deleteNodes(StudentNode *current)
	{
		if (current)
		{
			deleteNodes(current->left);
			deleteNodes(current->right);
			delete current;
		}
	}
};
