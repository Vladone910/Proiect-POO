#pragma once
#include <iostream>
#include <string>
#include <string.h>



using namespace std;

enum EventType { concert, movie, football_match, play, other };

class Event
{
private:
	char* eventName;
	EventType eventType;
	bool isOutside;
	char* location;
	string date;
	string hour;

public:
	Event() : eventName(nullptr), eventType(concert), isOutside(false), location(nullptr), date("01/01/2000"), hour("00:00") {
		
	}
	
	Event(const char* name, EventType eventType, bool outside, const char* loc, const string& d, const string& h)
		: eventType(eventType), isOutside(outside), date(d), hour(h) {
		eventName = new char[strlen(name) + 1];
		strcpy(eventName, name);

		location = new char[strlen(loc) + 1];
		strcpy(location, loc);
	}
	~Event() {
		delete[] eventName;
		delete[] location;
	}

    //getters
    const char* getEventName() const {
        return eventName;
    }

    EventType getEventType() const {
        return eventType;
    }

    bool getIsOutside() const {
        return isOutside;
    }

    const char* getLocation() const {
        return location;
    }

    const string& getDate() const {
        return date;
    }

    const string& getHour() const {
        return hour;
    }


    // Setters
    void setEventName(const char* name) {
        delete[] eventName;
        eventName = new char[strlen(name) + 1];
        strcpy(eventName, name);
    }

    void setEventType(EventType type) {
        eventType = type;
    }

    void setIsOutside(bool outside) {
        isOutside = outside;
    }

    void setLocation(const char* loc) {
        delete[] location;
        location = new char[strlen(loc) + 1];
        strcpy(location, loc);
    }

    void setDate(const string& d) {
        date = d;
    }

    void setHour(const string& h) {
        hour = h;
    }



	bool operator!();
	friend ostream& operator<<(ostream&, Event);
	friend istream& operator>>(istream&, Event&);
	friend ofstream& operator<<(ofstream&, Event);
	friend ifstream& operator>>(ifstream&, Event&);
};

 ostream& operator<<(ostream&, Event);
 istream& operator>>(istream&, Event&);
 ofstream& operator<<(ofstream&, Event);
 ifstream& operator>>(ifstream&, Event&);