#pragma once
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Ticket {
private:
	int Ticket_ID;
	string category;
	int seat;
	int row;
	static float BASE_PRICE;

	Ticket() : Ticket_ID(0), category(" "), seat(0), row(0) {
	}

	
	Ticket(int Ticket_id, string catergory, int seat, int row) {
		this->Ticket_ID = Ticket_ID;
		this->category = category;
		this->seat = seat;
		this->row = row;
	}

	~Ticket() {}

	int getTicketID() {
		return this->Ticket_ID;
	}

	void setTicketID(int Ticket_ID) {
		this->Ticket_ID = Ticket_ID;
	}

	 string getCategory()  {
		return this->category;
	}

	void setCategory(string& category) {
		this->category = category;
	}

	int getSeat() {
		return this->seat;
	}

	void setSeat(int seat) {
		this->seat = seat;
	}

	void setRow(int row)
	{
		this->row = row;
	}

	int getRow() {
		return this->row = row;
	}


	static float getBasePrice() {
		return BASE_PRICE;
	}


	friend ostream& operator<<(ostream& os, Ticket& ticket);
	friend istream& operator>>(istream& is, Ticket& ticket);
};

ostream& operator<<(ostream& os, Ticket& ticket) {
	os << "Ticket ID: " << ticket.getTicketID() << "\n";
	os << "Category: " << ticket.getCategory() << "\n";
	os << "Seat: " << ticket.getSeat() << "\n";
	os << "Row: " << ticket.getRow() << "\n";
	return os;
}

 istream& operator>>(istream& is, Ticket& ticket) {
	 int id, s, r;
	 string cat;

	 cout << "Enter Ticket ID: ";
	 is >> id;
	 ticket.setTicketID(id);

	 cout << "Enter Category: ";
	 is >> cat;
	 ticket.setCategory(cat);

	 cout << "Enter Seat: ";
	 is >> s;
	 ticket.setSeat(s);

	 cout << "Enter Row: ";
	 is >> r;
	 ticket.setRow(r);

	return is;
}