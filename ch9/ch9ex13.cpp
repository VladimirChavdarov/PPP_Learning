#include "../PPP/PPP.h"

int main()
{
	ifstream ist{ "ch9/ex13.txt" };
	if (!ist)
		error("can't open file");

	int isspacecnt = 0;
	int isalphacnt = 0;
	int isdigitcnt = 0;
	int isxdigitcnt = 0;
	int isuppercnt = 0;
	int islowercnt = 0;
	int isalnumcnt = 0;
	int iscntrlcnt = 0;
	int ispunctcnt = 0;
	int isprintcnt = 0;
	int isgraphcnt = 0;

	char ch;
	while (ist.get(ch))
	{
		if (isspace(static_cast<unsigned char>(ch)))
			isspacecnt++;
		if (isalpha(static_cast<unsigned char>(ch)))
			isalphacnt++;
		if (isdigit(static_cast<unsigned char>(ch)))
			isdigitcnt++;
		if (isxdigit(static_cast<unsigned char>(ch)))
			isxdigitcnt++;
		if (isupper(static_cast<unsigned char>(ch)))
			isuppercnt++;
		if (islower(static_cast<unsigned char>(ch)))
			islowercnt++;
		if (isalnum(static_cast<unsigned char>(ch)))
			isalnumcnt++;
		if (iscntrl(static_cast<unsigned char>(ch)))
			iscntrlcnt++;
		if (ispunct(static_cast<unsigned char>(ch)))
			ispunctcnt++;
		if (isprint(static_cast<unsigned char>(ch)))
			isprintcnt++;
		if (isgraph(static_cast<unsigned char>(ch)))
			isgraphcnt++;
	}

	cout << "Whitespace: " << isspacecnt << endl;
	cout << "Letter: " << isalphacnt << endl;
	cout << "Digit: " << isdigitcnt << endl;
	cout << "Hex Digit: " << isxdigitcnt << endl;
	cout << "Upper Case: " << isuppercnt << endl;
	cout << "Lower Case: " << islowercnt << endl;
	cout << "Control Symbol: " << iscntrlcnt << endl;
	cout << "Punctuation Symbol: " << ispunctcnt << endl;
	cout << "Printable: " << isprintcnt << endl;
}