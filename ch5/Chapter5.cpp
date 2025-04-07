#include "../PPP/PPP.h"

// Version 0
//int main()
//{
//	cout << "Please enter an expression (+ or i): ";
//	int lval = 0;
//	int rval = 0;
//	char op = 0;
//	int res = 0;
//	cin >> lval >> op >> rval;
//
//	if (op == '+')
//		res = lval + rval;
//	else if (op == '-')
//		res = lval - rval;
//
//	cout << "Result: " << res << endl;
//	
//	return 0;
//}

// Version 1

//int main()
//{
//	cout << "Please enter expression (we can handle +, -, *, /)" << endl;
//	cout << "add x to end expression (e.g. 1+2*3x)" << endl;
//	int lval = 0;
//	int rval = 0;
//	cin >> lval;
//	if (!cin)
//		error("No first operand");
//
//	for (char op; cin >> op;)
//	{
//		if (op != 'x')
//			cin >> rval;
//		if (!cin)
//			error("No second operand!");
//		switch (op)
//		{
//		case '+':
//			lval += rval;
//			break;
//		case '-':
//			lval -= rval;
//			break;
//		case '*':
//			lval *= rval;
//			break;
//		case '/':
//			lval /= rval;
//			break;
//		default:
//			// no more operators. Print the result stored in lval.
//			cout << "Result: " << lval << endl;
//			break;
//		}
//	}
//	error("Bad expression");
//
//	return 0;
//}

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) {
    }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) {
    }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token get();            // get a Token
    void placeback(Token t);  // put a Token back
private:
    bool full{ false };      // is there a Token in the buffer?
    Token buffer = { '0' };           // where we store a 'placeback' Token
};

void Token_stream::placeback(Token t)
{
    if (full) error("placeback() into a full buffer");
    buffer = t;         // copy t to buffer
    full = true;        // buffer is now full
}

Token Token_stream::get()
{
    if (full) {
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;

    switch (ch) {
    case ';':       // for "print"
    case 'q':       // for "quit"
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
        return Token{ ch };   // let each character represent itself
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
        cin.putback(ch);
        double val;
        cin >> val;
        return Token{ '8', val };
    }
    default:
        error("Bad Token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;      // provides get() and putback()

//------------------------------------------------------------------------------

double expression();  // read and evaluate a Expression

//------------------------------------------------------------------------------

double term();        // read and evaluate a Term

//------------------------------------------------------------------------------

double primary()     // read and evaluate a Primary
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return d;
    }
    case '8':            // we use '8' to represent a number
        return t.value;  // return the number's value
    default:
        error("primary expected");
    }
}
//------------------------------------------------------------------------------

int main()
{
    try {
        double val = 0;
        while (cin)
        {
            Token t = ts.get();
            if (t.kind == 'q')
                break;
            if (t.kind == ';')
                cout << "=" << val << endl;
            else
                ts.placeback(t);
            val = expression();
        }
    }
    catch (exception& e) {
        cerr << e.what() << endl;
        return 1;
    }
    catch (...) {
        cerr << "exception \n";
        return 2;
    }

}

//------------------------------------------------------------------------------

double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token
    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.placeback(t);
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

double term()
{
    double left = primary();
    Token t = ts.get();     // get the next token

    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.placeback(t);
            return left;
        }
    }
}

//------------------------------------------------------------------------------