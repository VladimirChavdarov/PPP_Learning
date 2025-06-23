#pragma once
#include <chrono>
#include "../../PPP/PPP.h"

class ISBN
{
public:
	ISBN() {};
	ISBN(int n1, int n2, int n3, char x);

	const string ToString() const;
	bool IsIsbn();

	int n1 = 0, n2 = 0, n3 = 0;
	char x = '0';
};

bool operator==(const ISBN& a, const ISBN& b);

// ----------------------------------------------

class Book
{
	enum Genre {
		fiction = 0, nonfiction, periodical, biography, children
	};

public:
	Book() {};
	Book(ISBN isbn, string title, string author, std::chrono::year_month_day copyright_date);

	const ISBN GetISBN() const { return isbn; }
	const string GetTitle() const{ return title; }
	const string GetAuthor() const{ return author; }
	const std::chrono::year_month_day GetCopyrightDate() const { return copyright_date; }
	const Genre GetGenre() const { return genre; }
	const bool GetIsCheckedOut() const { return is_checked_out; }

	void CheckOut() { is_checked_out = true; }
	void CheckIn() { is_checked_out = false; }

private:
	ISBN isbn;
	string title;
	string author;
	std::chrono::year_month_day copyright_date = 2000y/1/1d;
	Genre genre = Genre::fiction;
	bool is_checked_out = false;
};

bool operator==(const Book& a, const Book& b);
bool operator!=(const Book& a, const Book& b);
ostream& operator<<(ostream& os, const Book& a);

// ----------------------------------------------

class Patron
{
public:
	Patron() {};
	Patron(string name, int card_number, double fees);

	const string GetName() const { return name; }
	const int GetCardNumber() const { return card_number; }
	const double GetFees() const { return fees; }

	void SetFee(double new_fee);
	void AddFee(double fee_to_add);
	void NullifyFeeSum();


private:
	string name;
	int card_number;
	double fees;
};

bool owes_fee(const Patron& patron)
{
	return patron.GetFees() > 0.0;
}

bool operator==(const Patron& a, const Patron& b);
bool operator!=(const Patron& a, const Patron& b);

// ----------------------------------------------

class Library
{
	struct Transaction
	{
		Transaction() {};
		Transaction(Book a_book, Patron a_patron, std::chrono::year_month_day a_date)
			: book(a_book), patron(a_patron), date(a_date)
		{};

		Book book;
		Patron patron;
		std::chrono::year_month_day date = 2000y/1/1;
	};

public:
	Library() {};
	Library(vector<Book> a_books, vector<Patron> a_patrons, vector<Transaction> a_transactions)
		: books(a_books), patrons(a_patrons), transactions(a_transactions)
	{};

	const vector<Book>& GetBooks() const { return books; }
	const vector<Patron>& GetPatrons() const { return patrons; }
	const vector<Transaction>& GetTransactions() const { return transactions; }
	const vector<Patron>& GetDeptors() const;

	void AddBook(const Book& book_to_add);
	void AddPatron(const Patron& patron_to_add);
	void CheckOut(const Book& book, const Patron& patron, const std::chrono::year_month_day date);
	void SetFee(const Patron& patron, const double fee);

private:
	vector<Book> books;
	vector<Patron> patrons;
	vector<Transaction> transactions;
};