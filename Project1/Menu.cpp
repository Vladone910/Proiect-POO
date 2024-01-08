#include <iostream>
#include <string>
#include <string.h>
#include "Event.h"
#include "Ticket.h"
#include "Location.h"

using namespace std;


int main() {


    Event e1("Dinamo vs FCSB", football_match, true, "National Arena", "2024-01-05", "19:30");
    Event e2("Piesa de teatru", concert, false, "TNB", "2024-02-15", "17:30");

   
    Ticket t1(101, "sports", 25, 7);
    Ticket t2(102, "concert", 30, 5);

    TicketGenerator t3(104, "sports", 37, 8, true);


  
    ConcreteLocation c1("Romania");

     c1.showLocation();

	cout << endl << "       TICKETING APPLICATION       ";
	cout << endl << "Choose from the following options: ";

	int option;
	
		cout << endl << "( 1 ) See the list of events";
		cout << endl << "( 2 ) Buy a ticket";
		cout << endl << "( 3 ) Validate a ticket";
		cout << endl << "( 4 ) Close the application\n" << endl;

		cin >> option;
	
        switch (option) {
        case 1:
            cout << endl << "The events are:";
            cout << endl << e1;
            cout << endl << e2;
            break;

        case 2:
            cout << endl << "Buying a ticket:";
            cout << endl << "Row: ";
            int row;
            cin >> row;
            cout << endl << "Seat: ";
            int seat;
            cin >> seat;

             t3.Generate();
             t3.serialize();
           

            cout << endl << "Ticket created! ";
            break;

        case 3:
            cout << endl << "Validating a ticket:";
           
            cout << endl << "Write the id of the ticket: ";
            int id;
            cin >> id;
            
            t1.deserialize();

            break;

        case 4:
            cout << endl << "Closing the application:";
            break;

        default:
            cout << endl << "Error: Invalid option. Please choose 1, 2, 3, or 4.";
            break;
        }

       

}