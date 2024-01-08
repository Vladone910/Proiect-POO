#pragma once
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Location
{
protected:
    int* seatsPerRow;
    const unsigned int Max_No_Rows;
    const unsigned int Max_No_Seats;

public:
   
    Location() : Max_No_Rows(100), Max_No_Seats(200){
    
       seatsPerRow = new int[Max_No_Rows];
    }


    Location(unsigned int rows, unsigned int maxSeatsPerRow) : Max_No_Rows(rows), Max_No_Seats(maxSeatsPerRow){
    
        seatsPerRow = new int[Max_No_Rows];
        for (unsigned int i = 0; i < Max_No_Rows; ++i){
            seatsPerRow[i] = maxSeatsPerRow;
        }
    }

    ~Location(){
    
        delete[] seatsPerRow;
    }


    Location(const Location& other) : Max_No_Rows(other.Max_No_Rows), Max_No_Seats(other.Max_No_Seats)
    {
        seatsPerRow = new int[Max_No_Rows];
        for (unsigned int i = 0; i < Max_No_Rows; ++i)
        {
            seatsPerRow[i] = other.seatsPerRow[i];
        }
    }

    void displayInfo() const {
    
    cout << "Location Information:\n"
    << "Number of Rows: " << Max_No_Rows << "\n"
    << "Maximum Seats per Row: " << Max_No_Seats << "\n"
    << "Seats per Row:" << seatsPerRow << "\n";

    for (unsigned int i = 0; i < Max_No_Rows; ++i){    
           cout << " " << seatsPerRow[i];
        }

       cout << "\n";
    }

  
    unsigned int getNoOfRows() const {
    
        return Max_No_Rows;
    }

    unsigned int getMaxNoSeats() const {
    
        return Max_No_Seats;
    }

  
    int getSeatsInRow(unsigned int row) const {
    
        if (row < Max_No_Rows) {
        
            return seatsPerRow[row];
        }
        else {
        
            throw exception ("Invalid row number.");
            
        }
    }


    void setSeatsInRow(unsigned int row, int seats)
    {
        if (row < Max_No_Rows && seats >= 0 && seats <= Max_No_Seats)
        {
            seatsPerRow[row] = seats;
        }
        else
        {
            throw exception ("Invalid row number or seats value.\n");
        }
    }

    Location& operator=(const Location& loc){
    
        if (this != &loc) {

            if (seatsPerRow != nullptr) {

                delete[] seatsPerRow;
            }


            if (loc.seatsPerRow != nullptr) {

                this->seatsPerRow = new int[Max_No_Rows];

                for (unsigned int i = 0; i < Max_No_Rows; ++i) {

                    this->seatsPerRow[i] = loc.seatsPerRow[i];
                }
            }
         
            else {

                this->seatsPerRow = nullptr;
            }
        }
            
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Location& loc);


    virtual void showLocation() const = 0;


};

class ConcreteLocation : public Location{
protected:

    string location;

public:

    ConcreteLocation() {
        location = location;
    }
    ConcreteLocation(string location) {
        this->location = location;
    }

    void showLocation() const override {
        cout << endl << "The location is in Eastern Europe";
    }
};

  ostream& operator<<(ostream& os, const Location& loc) {
    os << "Number of Rows: " << loc.Max_No_Rows << "\n";
    os << "Maximum Seats per Row: " << loc.Max_No_Seats << "\n";
    os << "Seats per Row:" << loc.seatsPerRow << "\n";

    for (unsigned int i = 0; i < loc.Max_No_Rows; ++i)
    {
        os << " " << loc.seatsPerRow[i];
    }
    return os;
}