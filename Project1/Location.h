#pragma once
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Location
{
private:
    int* seatsPerRow;
    const unsigned int Max_No_Rows;
    const unsigned int Max_No_Seats;

public:
   
    Location(unsigned int rows, unsigned int maxSeatsPerRow) : Max_No_Rows(rows), Max_No_Seats(maxSeatsPerRow){
    
        seatsPerRow = new int[Max_No_Rows];
        for (unsigned int i = 0; i < Max_No_Rows; ++i){
            seatsPerRow[i] = maxSeatsPerRow;
        }
    }

    ~Location(){
    
        delete[] seatsPerRow;
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
};