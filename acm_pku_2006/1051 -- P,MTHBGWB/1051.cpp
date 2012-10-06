#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX = 30;
char charList[MAX];

string charToStr(char c)
{
	string str[] = {
		".-",
		"-...",
		"-.-.",
		"-..",
		".",
		"..-.",
		"--.",
		"....",
		"..",
		".---",
		"-.-",
		".-..",
		"--",
		"-.",
		"---",
		".--.",
		"--.-",
		".-.",
		"...",
		"-",
		"..-",
		"...-",
		".--",
		"-..-",
		"-.--",
		"--..",
		".-.-",//,
		"---.",//.
		"----",//?
		"..--"//_
	};

	int i;
	switch(c)
	{
	case ',': i = 26;
		break;
	case '.': i = 27;
		break;
	case '?': i = 28;
		break;
	case '_': i = 29;
		break;
	default: 
		i = c-'A';
	}
	return str[i];
}

char strToChar(string s)
{
	int i;
	for(i=0; i<MAX; i++)
	{
		if(charToStr(charList[i]) == s)
			return charList[i];
	}
	return '\0';
}

int main()
{
	int i;
	for(i=0; i<26; i++)
		charList[i] = (char)(i+'A');
	charList[26] = ',';
	charList[27] = '.';
	charList[28] = '?';
	charList[29] = '_';


	char c[128];
	int len[128];

	int count;
	int num = 0;
	cin>>count;
	while(num < count)
	{
		num++;

		cin>>c;
		int n = strlen(c);
		//cout<<n<<endl;

		string s = "";
		for(i=0; i<n; i++)
		{
			len[i] = charToStr(c[i]).length();
			//cout<<charToStr(c[i])<<"\t"<<len[i]<<endl;
			s += charToStr(c[i]);
		}
		//cout<<s<<endl<<endl;

		int end = 0;
		string substr;
		string reverseStr = "";
		char ch;

		for(i=n-1; i>=0; i--)
		{	
			//cout<<end<<"\t"<<len[i]<<endl;
			substr = s.substr(end, len[i]);
			end += len[i];
			ch = strToChar(substr);
			//cout<<substr<<"\t"<<ch<<endl;
			reverseStr += ch;
		}
		cout<<num<<": "<<reverseStr<<endl;

	}

	return 0;
}