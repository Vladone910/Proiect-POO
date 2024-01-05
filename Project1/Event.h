#pragma once
#include <iostream>
#include <string>
#include <string.h>



using namespace std;

enum EventType { concert, movie, football_match, play, other };

class Event
{
protected:
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
		strcpy_s(eventName, strlen(name) + 1, name);

		location = new char[strlen(loc) + 1];
		strcpy_s(location, strlen(loc) + 1, loc);
	}
	~Event() {
		delete[] eventName;
		delete[] location;
	}

    Event(const Event& other) : eventType(other.eventType), isOutside(other.isOutside),
        date(other.date), hour(other.hour) {
    
        if (other.eventName != nullptr) {
            eventName = new char[strlen(other.eventName) + 1];
            strcpy_s(eventName, strlen(other.eventName) + 1, other.eventName);
        }
        else {
            eventName = nullptr;
        }

     
        if (other.location != nullptr) {
            location = new char[strlen(other.location) + 1];
            strcpy_s(location, strlen(other.location) + 1, other.location);
        }
        else {
            location = nullptr;
        }
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
        strcpy_s(eventName, strlen(name) + 1, name);
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
        strcpy_s(location, strlen(loc) + 1, loc);
    }

    void setDate(const string& d) {
        date = d;
    }

    void setHour(const string& h) {
        hour = h;
    }


    char operator[](int index) const {
        if (eventName != nullptr && index >= 0 && index < strlen(eventName)) {
            return eventName[index];
        }
        return '\0'; 
    }

    explicit operator bool()const {
        return eventName != nullptr;
    }
    bool operator !() const{
        return eventName == nullptr;
    }


	friend ostream& operator<<(ostream& os, const Event& event);
	friend istream& operator>>(istream&, Event&);
	friend ofstream& operator<<(ofstream&, Event);
	friend ifstream& operator>>(ifstream&, Event&);
};

ostream& operator<<(ostream& os, const Event& event) {
    os << "Event Name: " << event.getEventName() << "\n"
        //<< "Event Type: " << event.getEventType() << "\n"
       // << "Is Outside: " << event.getIsOutside() << "\n"
        << "Location: " << event.getLocation() << "\n"
        << "Date: " << event.getDate() << "\n"
        << "Hour: " << event.getHour() << "\n";
    return os;
}
 istream& operator>>(istream&, Event&);
 ofstream& operator<<(ofstream&, Event);
 ifstream& operator>>(ifstream&, Event&);