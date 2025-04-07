/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch (DONE!) and 3 that it won't.
*/

/*
---GRAMMAR---

Calculation:
	Statement
	Print
		";"
	Quit
		"q"
	Calculation Statement

Statement:
	Declaration
	Expression

Declaration:
	"let" Name "=" Expression

Name:
	letter
	letter Sequence
	"_" Sequence

Sequence:
	letter
	digit
	"_"
	letter Sequence
	digit Sequence
	"_" Sequence

Print:
	";"

Quit:
	"q"

Expression:
	Term
	Expression "+" Term
	Expression "-" Term


Term:
	Primary
	Term "*" Primary
	Term "/" Primary
	Term "%" Primary

Primary:
	Number
	"(" Expression ")"
	"-" Primary
	"+" Primary
	"sqrt(" Expression ")"
	"pow(" Expression "," Integer ")"
	Name
	Name "=" Expression

Number:
	floating-point-literal

Input comes from cin through the Token_stream called ts.
*/

#include "../PPP/PPP.h"
//#include "std_lib_facilities.h"

// Global Constants
const char let = 'L';           // declaration token
const char con = 'C';           // constant token
const char quit = 'q';          // t.kind==quit means that t is q quit Token
const char help = 'h';          // help token
const char calc_print = ';';    // t.kind==calc_print means that t is a print Token
const char number = '8';        // t.kind==number means that t is a number Token
const char name = 'a';          // name token
const char square_root = 's';   // square root token
const char power = 'p';         // power function token
const string declkey = "#";   // declaration keyword
const string conkey = "const";  // constant keyword
const string sqrtkey = "sqrt";  // keyword for square root
const string powkey = "pow";    // keyword for power function
const string quitkey = "exit";  // keyword to quit
const string helpkey = "help";  // keyword for help

//

struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) {}
	Token(char ch, double val) :kind(ch), value(val) {}
	Token(char ch, string n) :kind(ch), name(n) {}
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) {}

	Token get();
	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);
};

Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case ',':
		return Token(ch);
	case '#':	// drill 10: change "let" to "#"
	{
		return Token(let);
	}
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{
		cin.unget();
		double val;
		cin >> val;
		return Token(number, val);
	}
	default:
		if (isalpha(ch)) { // since we allow underscores, we need to remove the condition for discarding non-alphabet symbols
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
				s += ch;
			cin.unget();
			if (s == declkey) return Token(let);			// declaration keyword
			if (s == conkey) return Token(con);             // constant keyword
			if (s == sqrtkey) return Token(square_root);    // square root keyword
			if (s == powkey) return Token(power);           // power function keyword
			if (s == helpkey) return Token(help);           // help keyword
			if (s == quitkey) return Token(quit);			// quit keyword
			return Token(name, s);
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

struct Variable {
	string name;
	double value;
	bool is_const;
	Variable(string n, double v, bool a_is_const) :name(n), value(v), is_const(a_is_const) {}
};

class Symbol_table
{
public:
	double get(string s);
	void set(string s, double d);
	bool is_declared(string var);
	double declare(string var, double val, bool is_const);
private:
	vector<Variable> var_table;
};

double Symbol_table::get(string s)
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s) return var_table[i].value;
	error("get: undefined variable ", s);

	return 0.0;
}

void Symbol_table::set(string s, double d)
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s)
		{
			if (var_table[i].is_const)
				error(s, " is a constant");
			var_table[i].value = d;
			return;
		}
	error("set: undefined variable ", s);
}

bool Symbol_table::is_declared(string var)
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == var)
			return true;
	return false;
}

double Symbol_table::declare(string var, double val, bool is_const)
{
	if (is_declared(var))
		error(var, " declared twice");
	var_table.push_back(Variable(var, val, is_const));
	return val;
}

// Global read-write data
Token_stream ts;
Symbol_table st;
//

double expression();

double my_pow(double base, int expo)
{
	if (expo == 0)
		return 1; // everything to the power of 0 is 1.
	double result = 1;
	for (int i = 0; i < expo; i++)
		result *= base;
	return result;
}

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("'(' expected");
	}
	case '-':
		return -primary();
	case number:
		return t.value;
	case name:
	{
		Token t2 = ts.get(); //get the token after t while still keeping t.
		if (t2.kind == '=')
		{
			double d = expression();
			st.set(t.name, d);
			return d;
		}
		ts.unget(t2);
		return st.get(t.name);
	}
	case square_root:
	{
		t = ts.get();
		if (t.kind != '(')
			error("'(' expected");
		double d = expression();
		if (d < 0)
			error("can't perform square root on negative numbers");
		t = ts.get();
		if (t.kind != ')')
			error("')' expected");
		return sqrt(d);
	}
	case power:
	{
		t = ts.get();
		if (t.kind != '(')
			error("'(' expected");
		double d = expression();
		t = ts.get();
		if (t.kind != ',')
			error("',' expected");
		t = ts.get();
		if (t.kind != number)
			error("argument is not a number");
		int exponent = static_cast<int>(t.value);
		if(exponent != t.value) // check for a dccimal part
			error("argument is not an integer");
		t = ts.get();
		if (t.kind != ')')
			error("')' expected");
		return my_pow(d, exponent);
	}
	default:
		error("primary expected");
	}
}

double term()
{
	double left = primary();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration(bool is_const)
{
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (st.is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	st.declare(name, d, is_const);
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration(false);
	case con:
		return declaration(true);
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(calc_print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true)
		try
		{
			cout << prompt;
			Token t = ts.get();
			while (t.kind == calc_print)
				t = ts.get();
			if (t.kind == quit) return;
			ts.unget(t);
			cout << result << statement() << endl;
		}
		catch (runtime_error& e)
		{
			cerr << e.what() << endl;
			clean_up_mess();
		}
}

int main()

try {

	// predefine names:
	// note: crude
	st.declare("pi", 3.1415926535, true);
	st.declare("e", 2.7182818284, true);
	st.declare("k", 1000, true);
	//

	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}
