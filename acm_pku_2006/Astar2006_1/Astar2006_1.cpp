#include<stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char* argv[])
{
	int a, b;

	ifstream fin;
	fin>>a>>b;
	cout<<a+b<<endl;

	//// read from the file specified in first argument
	//FILE *fp;
	//fp = fopen(argv[1], "r");
	//fscanf(fp, "%d%d", &a, &b);
	//fclose(fp);

	//// write to standard output
	//printf("%d", a+b);
	return 1;
}