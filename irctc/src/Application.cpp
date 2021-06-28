/*Sunanda Mandal
19CS10060*/
/************ C++ Headers ************************************/
#include <bits/stdc++.h>
using namespace std;
/************ PROJECT Headers ********************************/
// #include "classes.h"
// #include "statics.h"

// Test application for booking
//provided in section C
void BookingApplication() {
    // Bookings by different booking classes
    // <BookingClasses>::Type() returns the constant object of the respective type
    Booking b1(Station("Mumbai"), Station("Delhi"), Date(15, 2, 2021), ACFirstClass::Type());
    Booking b2(Station("Kolkata"), Station("Delhi"), Date(5, 3, 2021), AC2Tier::Type());
    Booking b3(Station("Mumbai"), Station("Kolkata"), Date(17, 3, 2021), FirstClass::Type());
    Booking b4(Station("Mumbai"), Station("Delhi"), Date(23, 3, 2021), AC3Tier::Type());
    Booking b5(Station("Chennai"), Station("Delhi"), Date(25, 4, 2021), ACChairCar::Type());
    Booking b6(Station("Chennai"), Station("Kolkata"), Date(7, 5, 2021), Sleeper::Type());
    Booking b7(Station("Mumbai"), Station("Delhi"), Date(19, 5, 2021), SecondSitting::Type());
    Booking b8(Station("Delhi"), Station("Mumbai"), Date(22, 5, 2021), SecondSitting::Type());

    // Output the bookings done where sBookings is the collection of bookings done
    vector<Booking*>::iterator it;
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it) {
        cout << *(*it);
    }
    return;
}

// Test application for booking
//developed own

void BookingApplication2(){
    //checking if all tyoe of booking classes working for particular pair of stations
    //because stations doesnt make much difference
    Booking b1(Station("Chennai"), Station("Delhi"), Date(15, 2, 2021), ACChairCar::Type());
    Booking b2(Station("Chennai"), Station("Delhi"), Date(5, 3, 2021), SecondSitting::Type());
    Booking b3(Station("Chennai"), Station("Delhi"), Date(17, 3, 2021), AC2Tier::Type());
    Booking b4(Station("Chennai"), Station("Delhi"), Date(23, 3, 2021), AC3Tier::Type());
    Booking b5(Station("Chennai"), Station("Delhi"), Date(25, 12, 2021), FirstClass::Type());
    Booking b6(Station("Chennai"), Station("Delhi"), Date(7, 10, 2021), Sleeper::Type());
    Booking b7(Station("Chennai"), Station("Delhi"), Date(19, 10, 2021), ACFirstClass::Type());

    Booking b8(Station("Kolkata"), Station("Bangalore"), Date(15, 2, 2021), ACChairCar::Type());
    Booking b9(Station("Kolkata"), Station("Bangalore"), Date(5, 3, 2021), SecondSitting::Type());
    Booking b10(Station("Kolkata"), Station("Bangalore"), Date(17, 3, 2021), AC2Tier::Type());
    Booking b11(Station("Kolkata"), Station("Bangalore"), Date(23, 3, 2021), AC3Tier::Type());
    Booking b12(Station("Kolkata"), Station("Bangalore"), Date(25, 12, 2021), FirstClass::Type());
    Booking b13(Station("Kolkata"), Station("Bangalore"), Date(7, 10, 2021), Sleeper::Type());
    Booking b14(Station("Mumbai"), Station("Bangalore"), Date(19, 10, 2021), ACFirstClass::Type());
    
    
    vector<Booking*>::iterator it;
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it) {
        cout << *(*it);
    }
    return;
}
