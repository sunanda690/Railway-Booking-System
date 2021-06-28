/*Sunanda Mandal
19CS10060*/

#ifndef __STATICS_H
#define __STATICS_H


#include <iostream>
using namespace std;
/************ PROJECT Headers ********************************/
#include "classes.h"


//loadfactor of various clases
const double ACFirstClass::sLoadFactor_ = 3.0;
const double AC2Tier::sLoadFactor_ = 2.0;
const double FirstClass::sLoadFactor_ = 2.0;
const double AC3Tier::sLoadFactor_ = 1.75;
const double ACChairCar::sLoadFactor_ = 1.25;
const double Sleeper::sLoadFactor_ = 1.0;
const double SecondSitting::sLoadFactor_ = 0.50;


//other static constants for computing fare
const double Booking::sBaseFarePerKM = 0.50;
const double Booking::sACSurcharge = 50;
const double Booking::sLuxuryTaxPercent = 0.25;
//initialize static vector to store all bookings
vector<Booking*> Booking::sBookings;
//initializing PNR series
unsigned int Booking::sBookingPNRSerial = 0;


#endif