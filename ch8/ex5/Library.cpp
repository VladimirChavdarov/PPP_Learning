#include "Library.h"

ISBN::ISBN(int n1, int n2, int n3, char x)
	: n1(n1), n2(n2), n3(n3), x(x)
{
	if (!IsIsbn())
		error("ISN was not valid! Exiting program...");
}

const string ISBN::ToString() const
{
	string s = "";
	// I have to do this instead of have it on one line because of Checked_String
	s += std::to_string(n1);
	s += "-";
	s += std::to_string(n2);
	s += "-";
	s += std::to_string(n3);
	s += "-";
	s += x;
	//
	return s;
}

bool ISBN::IsIsbn()
{
	return (isalpha(x) || isdigit(x));
}

bool operator==(const ISBN& a, const ISBN& b)
{
	return (a.n1 == b.n1 && a.n2 == b.n2 && a.n3 == b.n3 && a.x == b.x);
}

// ---------------------------------------

Book::Book(ISBN a_isbn, string a_title, string a_author, std::chrono::year_month_day a_copyright_date)
	: isbn(a_isbn), title(a_title), author(a_author), copyright_date(a_copyright_date)
{

}

bool operator==(const Book& a, const Book& b)
{
	return (a.GetISBN() == b.GetISBN());
}

bool operator!=(const Book& a, const Book& b)
{
	return !(a==b);
}

ostream& operator<<(ostream& os, const Book& a)
{
	return os <<
		a.GetTitle() << endl <<
		a.GetAuthor() << endl <<
		a.GetISBN().ToString() << endl;
}

bool operator==(const Patron& a, const Patron& b)
{
	return a.GetCardNumber() == b.GetCardNumber();
}

bool operator!=(const Patron& a, const Patron& b)
{
	return !(a == b);
}

// ---------------------------------------

Patron::Patron(string a_name, int a_card_number, double a_fees)
	: name(a_name), card_number(a_card_number), fees(a_fees)
{
}

void Patron::SetFee(double new_fee)
{
	fees = new_fee;
}

void Patron::AddFee(double fee_to_add)
{
	fees += fee_to_add;
}

void Patron::NullifyFeeSum()
{
	fees = 0;
}

// ---------------------------------------

const vector<Patron>& Library::GetDeptors() const
{
	vector<Patron> debtors;
	for (auto patron : patrons)
	{
		if (owes_fee(patron))
			debtors.push_back(patron);
	}
	return debtors;
}

void Library::AddBook(const Book& book_to_add)
{
	for (auto book : books)
	{
		if (book == book_to_add)
		{
			error("AddBook(): Book already exists!");
			return;
		}
	}
	books.push_back(book_to_add);
}

void Library::AddPatron(const Patron& patron_to_add)
{
	for (auto patron : patrons)
	{
		if (patron == patron_to_add)
		{
			error("AddPatron(): Patron already exists!");
			return;
		}
	}
	patrons.push_back(patron_to_add);
}

void Library::CheckOut(const Book& book, const Patron& patron, const std::chrono::year_month_day date)
{
	// find book
	int book_index = -1;
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i] == book)
		{
			book_index = i;
			break;
		}
	}
	if (book_index == -1)
		error("Library::CheckOut: Book not found!");
	//

	// find patron
	int patron_index = -1;
	for (int i = 0; i < patrons.size(); i++)
	{
		if (patrons[i] == patron)
		{
			patron_index = i;
			break;
		}
	}
	if (patron_index == -1)
		error("Library::CheckOut: Patron not found!");
	//

	if (owes_fee(patrons[patron_index]))
	{
		error("Library::CheckOut: Patron still owes fees!");
		return;
	}

	transactions.push_back(Transaction(books[book_index], patrons[patron_index], date));
	books[book_index].CheckOut();
}

void Library::SetFee(const Patron& patron, const double fee)
{
	for (int i = 0; i < patrons.size(); i++)
	{
		if (patrons[i] == patron)
		{
			patrons[i].AddFee(fee);
			return;
		}
	}
	error("Library::SetFee(): Patron not found!");
}
