#include<stdio.h>
int main(int argc, char* argv[])
{
	int a, b;

	// read from the file specified in first argument
	FILE *fp;
	fp = fopen(argv[1], "r");
	fscanf(fp, "%d%d", &a, &b);
	fclose(fp);

	// write to standard output
	printf("%d", a+b);
	return 1;
}
