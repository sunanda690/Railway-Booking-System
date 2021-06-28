/*Sunanda Mandal
19CS10060*/


#ifndef __CLASSES_H
#define __CLASSES_H

#include<iostream>
using namespace std;


/**********************DATE CLASS************************/
char monthNames[][4] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
char dayNames[][10] = { "Monday", "Tuesday", "Wednesday", "Thursday",
                            "Friday", "Saturday", "Sunday" };
class Date {
    enum Month { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
    enum Day { Mon, Tue, Wed, Thr, Fri, Sat, Sun };
    typedef unsigned int UINT;
    UINT date_; Month month_; UINT year_;
public:
    Date(UINT d, UINT m, UINT y) : 
        date_(d), month_((Month)m), year_(y){};
    //parameter passed is const as there should be any in place modification
    Date(const Date& d) : 
        date_(d.date_), month_(d.month_), year_(d.year_){};
    //parameter passed is const as there should be any in place modification
    Date& operator=(const Date& d) { 
        date_ = d.date_; month_ = d.month_; year_ = d.year_;
        return *this;
    }
    ~Date() {};
    //output streaming poerator for UDT Date
    friend ostream& operator <<(ostream& rOs, const Date& rFrom) {
        rOs<< rFrom.date_ << "/" << monthNames[rFrom.month_ - 1] << "/" << rFrom.year_;
        return rOs;
    }
    void UnitTestDate();
};


/**********************CLASS STATION*********************/
class Station
{
private:
    //name is private because the class itself needs to access it and will not be modified later 
    const string name_;
    // operator is blocked(made private) as there are are only five unique stations
    // and they should not be duplicated.
    Station& operator=(const Station& station) {};
public:
    Station(string name): 
        name_(name){};
    Station(const Station& station): name_(station.name_){};
    //returns the name of the station 
    //function taken as const to ensure name is not changed
    const string& GetName() const {
        return name_;
    }
    //function description is given later as we are calling a member function of the railways class
    //even foward declaration of railways will not be enough as the railways class will be incomplete
    int GetDistance(const Station& toStation);
    //output streaming poerator for UDT Station
    friend ostream& operator <<(ostream& rOs, const Station& station){
        rOs<<station.name_;
        return rOs;
    }
    //destructor
    ~Station(){};
    void UnitTestStation();
};


/******************************CLASS RAILWAYS*********************************/
// forward declaration
// class Station;
class Railways {
private:
    //ctor does not need parameters as the data members will be hard coded
    //beacuse no. of station = 5 and distance between them will not change in future(assumption)
    //private to singleton class ctor can not be called from outside
    Railways();
    //copy constructor blocked
    Railways(const Railways& railways){};
    //destructor defined later
    ~Railways();
    //copy assignment operator blocked
    Railways& operator=(const Railways& railways) {};
    //static because we will need to refer to this throughout the program
    //private beacause of encapsulation (we will only access these through data members)
    // List of Stations as name-Station pairs
    static map<const string, const Station*> sStations;
    // List of dists as <Station, Station>-dist pairs
    static map<pair<const Station*, const Station*>, int> sDistStations;
public:
    // Singletone Railways named IndianRailways
    static const Railways& IndianRailways() {
        // Local static singletone object
        // Gets instantiated on the first call and cleaned up after main()
        static const Railways indianRailways;
        return indianRailways;
    }
    // Gets the dist between two Stations
    int GetDistance(const Station& fromStation, const Station& toStation) const;
    // Gets the Station instance in sStations of a given station name
    const Station* GetStation(const string& name) const;
    //output streaming operator that all the station name pairwise distances
    friend ostream& operator<<(ostream& rOs,const Railways& railways){
        //iterate through sStations
        map<const string, const Station*>::iterator it;
        rOs<<"\nStations: \n";
        for (it=railways.sStations.begin(); it!=railways.sStations.end();it++)
        {
            rOs<<*(it->second)<<" ";
        }
        //iterate through sDistStations
        map<pair<const Station*, const Station*>, int>::iterator dist_it;
        rOs<<"\nDistance b/w pair of Stations: \n";
        for (dist_it=railways.sDistStations.begin(); dist_it!=railways.sDistStations.end();dist_it++)
        {
            rOs<<*(dist_it->first.first)<<" "<<*(dist_it->first.second)<<" : "<<(dist_it->second)<<"\n";
        }
    }
    void UnitTestRailways();
};

//initialize static objects
map<const string, const Station*> Railways::sStations;
map<pair<const Station*, const Station*>, int> Railways::sDistStations;

// ***** Implementation of Railways******
Railways::Railways() {
     // cout<<"Railways constructor called"; //to check sigletone
    //as railways is singletone class data members sStations and sDistStations are build only once 
    // and used throughout the program(static member)
    sStations["Mumbai"] = new Station("Mumbai"); // Dynamically created, needs deletion
    sStations["Delhi"] = new Station("Delhi");
    sStations["Bangalore"] = new Station("Bangalore");
    sStations["Kolkata"] = new Station("Kolkata");
    sStations["Chennai"] = new Station("Chennai");
    sDistStations[make_pair(sStations["Mumbai"], sStations["Delhi"])] = 1447;
    sDistStations[make_pair(sStations["Mumbai"], sStations["Bangalore"])] = 981;
    sDistStations[make_pair(sStations["Mumbai"], sStations["Kolkata"])] = 2014;
    sDistStations[make_pair(sStations["Mumbai"], sStations["Chennai"])] = 1338;
    sDistStations[make_pair(sStations["Delhi"], sStations["Bangalore"])] = 2150;
    sDistStations[make_pair(sStations["Delhi"], sStations["Kolkata"])] = 1472;
    sDistStations[make_pair(sStations["Delhi"], sStations["Chennai"])] = 2180;
    sDistStations[make_pair(sStations["Bangalore"], sStations["Kolkata"])] = 1871;
    sDistStations[make_pair(sStations["Bangalore"], sStations["Chennai"])] = 350;
    sDistStations[make_pair(sStations["Kolkata"], sStations["Chennai"])] = 1659;

    // cout << "Railways created" << endl << endl;
}

Railways::~Railways() {
    // Cleans up the Stations created
    map<const string, const Station*>::iterator it;
    for (it = sStations.begin(); it != sStations.end(); ++it)
        delete it->second;
        // cout << "Railways destroyed" << endl;
}
    
const Station* Railways::GetStation(const string& name) const{
    // Looks for a Station with matching name
    map<const string, const Station*>::iterator it;
    for (it = sStations.begin(); it != sStations.end(); ++it)
        if (it->first == name)
            return it->second;
}

int Railways::GetDistance(const Station& fromStation, const Station& toStation) const{
    //for two given stations returns distance between them
    int dist = 0;
    // Get the Stations
    const Station* psStation = GetStation(fromStation.GetName());
    const Station* pdStation = GetStation(toStation.GetName());
    // Get the dist between the Stations 
    map<pair<const Station*, const Station*>, int>::iterator dist_it;
    dist_it = sDistStations.find(make_pair(psStation, pdStation));
    if (dist_it == sDistStations.end()) {
        //seraching for the pair in reverse order
        dist_it = sDistStations.find(make_pair(pdStation, psStation));
    }
    dist = dist_it->second;
    return dist;
}

//Getdistance member function of Station class
int Station::GetDistance(const Station& toStation){
    return Railways::IndianRailways().GetDistance(*this,toStation);
}

/**********************CLASS PASSANGER***************/
class Passanger
{
    //all  members are currently private as we don't specify the requirements yet
    const string name_;
    const string aadharNo_;
    const Date dob_;
    const string gender_;
    string mobileNo_; //mobile no can change
    const string category_;
public:
    Passanger();
    ~Passanger();
    //currentnly not using so not declared
    friend ostream& operator<<(ostream& rOs,const Passanger& passanger){};
};


/***************************CLASS BOOKINGCLASS******************/
//abstract base class
class BookingClass
{
protected:
    // static double sLoadFactor_;
    //luxury status can change later : non-const
    bool luxury_;//luxury(true)/ordinary(false) status
    //these 3 members can not be changed in future but they needs to be modified by derived classes..so declared non-const
    //but protected so that can not be modified instead of the constructor
    bool ac_;//AC(true)/NON_AC(false) status
    bool seating_;//sitting(true)/berth(false) status
    int tiers_;
    //abstract class object cannot be made .. constructor made protected
    BookingClass(bool luxury, bool ac){
        luxury_ = luxury;
        ac_ = ac;
    }
public:
    //needs to overloaded for each derived concrete class
    virtual double GetLoadFactor() const =0;
    virtual string GetName()const=0;
    //returns status sitting/berth
    bool IsSitting() const{
        return seating_;
    }
    // returns staus AC/non-AC
    bool IsAC() const{
        return ac_;
    }
    // returns no. of tiers
    int GetNumberOfTiers() const{
        return tiers_;
    }
    // returns status luxury/ordinary
    bool IsLuxury() const{
        return luxury_;
    }
    //virtual destructor to support polymorphis hierarchy and avoid memory leakage
    virtual ~BookingClass() = 0;
    //output streaming for Bookingclass class
    friend ostream& operator<<(ostream& rOs, const BookingClass& b){
        rOs<<b.GetName()<<"\n";
        rOs<<"\t:Mode: ";
        if (b.IsSitting()) rOs<<"Sitting";
        else rOs<<"Sleeping";
        rOs<<"\n\t:Comfort: ";
        if (b.IsAC()) rOs<<"AC";
        else rOs<<"Non-AC";
        rOs<<"\n\t:Bunks: "<<b.GetNumberOfTiers();
        rOs<<"\n\t:Luxury: ";
        if (b.IsLuxury()) rOs<<"Yes";
        else rOs<<"No";
        return rOs;
    }
    
};
BookingClass::~BookingClass(){};

//subclass of BookingClass if it sitting...abstract class
class SeatBookingClass : public BookingClass{
protected:
    //abstract class object cannot be made .. constructor made protected
    SeatBookingClass(bool luxury, bool ac) : BookingClass(luxury,ac){
        seating_ = true;
        tiers_ = 0;
    } 
public:
    //virtual destructor to support polymorphis hierarchy and avoid memory leakage
    virtual ~SeatBookingClass()=0;
};
SeatBookingClass:: ~SeatBookingClass(){};

//subclass of BookingClass if it berth..abstract class
class BerthBookingClass : public BookingClass{
protected:
    //abstract class object cannot be made .. constructor made protected
    BerthBookingClass(bool luxury, bool ac) : BookingClass(luxury,ac){
        seating_ = false;
    } 
public:
    //virtual destructor to support polymorphis hierarchy and avoid memory leakage
    virtual ~BerthBookingClass()=0;
};
BerthBookingClass::~BerthBookingClass(){};

//subclass of Berth if it is 2 tier..abstract class
class Berth2Tier:public BerthBookingClass{
protected:
    //abstract class object cannot be made .. constructor made protected
    Berth2Tier(bool luxury, bool ac) : BerthBookingClass(luxury,ac){
        tiers_ = 2;
    } 
public:
    //virtual destructor to support polymorphis hierarchy and avoid memory leakage
    virtual ~Berth2Tier()=0;
    
};
Berth2Tier::~Berth2Tier(){};

//subclass of Berth if it is 3 tier..abstract class
class Berth3Tier : public BerthBookingClass{
protected:
    //abstract class object cannot be made .. constructor made protected
    Berth3Tier(bool luxury, bool ac) : BerthBookingClass(luxury,ac){
        tiers_ = 3;
    } 
public:
    //virtual destructor to support polymorphis hierarchy and avoid memory leakage
    virtual ~Berth3Tier()=0;
    
};
Berth3Tier::~Berth3Tier(){};

//**************concrete class
class ACChairCar : public SeatBookingClass{
    //static as this varieble is used througout the program
    //const throughout a run 
    // can be changed at instantiation point
    static const double sLoadFactor_;
    //private to singleton class ctor can not be called from outside
    ACChairCar() : SeatBookingClass(false,true){};
public:
    //sigleton that represents ACchaircar type
    static const BookingClass& Type(){
        //local static constant object
        //cfreated only once
        static const ACChairCar acChairCar;
        return acChairCar;
    }
    double GetLoadFactor() const{
        return sLoadFactor_;
    }
    string GetName()const {
        return "ACChairCar";
    }
    
    ~ACChairCar(){};
    void UnitTestACChairCar();
};

//**************concrete class
class SecondSitting : public SeatBookingClass{
    static const double sLoadFactor_;
    //private to singleton class ctor can not be called from outside
    SecondSitting() : SeatBookingClass(false,false){};
public:
    //sigleton that represents ACchaircar type
    static const BookingClass& Type(){
        static const SecondSitting secondSitting;
        return secondSitting;
    }
    double GetLoadFactor() const{
        return sLoadFactor_;
    }
    string GetName()const {
        return "SecondSitting";
    }
    
    ~SecondSitting(){};
    void UnitTestSecondSitting();
};

//**************concrete class
class ACFirstClass: public Berth2Tier{
    static const double sLoadFactor_;
    //private to singleton class ctor can not be called from outside
    ACFirstClass() : Berth2Tier(true,true){};
public:
    static const BookingClass& Type(){
        static const ACFirstClass acFirstClass;
        return acFirstClass;
    }
    double GetLoadFactor() const{
        return sLoadFactor_;
    }
    string GetName()const {
        return "ACFirstClass";
    }
    
    ~ACFirstClass(){};
    void UnitTestACFirstClass();
};

//**************concrete class
class AC2Tier : public Berth2Tier{
    static const double sLoadFactor_;
    //private to singleton class ctor can not be called from outside
    AC2Tier() : Berth2Tier(false,true){};
public:
    static const BookingClass& Type(){
        static const AC2Tier ac2Tier;
        return ac2Tier;
    }
    double GetLoadFactor() const{
        return sLoadFactor_;
    }
    string GetName()const {
        return "AC2Tier";
    }
    
    ~AC2Tier(){};
    void UnitTestAC2Tier();
};

//**************concrete class
class FirstClass : Berth2Tier{
    static const double sLoadFactor_;
    //private to singleton class ctor can not be called from outside
    FirstClass(): Berth2Tier(true,false){};
public:
    static const BookingClass& Type(){
        static const FirstClass firstClass;
        return firstClass;
    }
    double GetLoadFactor() const{
        return sLoadFactor_;
    }
    string GetName()const {
        return "FirstClass";
    }
    
    ~FirstClass(){};
    void UnitTestFirstClass();
};

//**************concrete class
class AC3Tier : public Berth3Tier{
    static const double sLoadFactor_;
    //private to singleton class ctor can not be called from outside
    AC3Tier() : Berth3Tier(false,true){};
public:
    static const BookingClass& Type(){
        static const AC3Tier ac3Tier;
        return ac3Tier;
    }
    double GetLoadFactor() const{
        return sLoadFactor_;
    }
    string GetName()const {
        return "AC3Tier";
    }
    
    ~AC3Tier(){};
    void UnitTestAC3Tier();
};

//**************concrete class
class Sleeper : Berth3Tier{
    static const double sLoadFactor_;
    //private to singleton class ctor can not be called from outside
    Sleeper() : Berth3Tier(false,false){};
public:
    static const BookingClass& Type(){
        static const Sleeper sleeper;
        return sleeper;
    }
    double GetLoadFactor() const{
        return sLoadFactor_;
    }
    string GetName()const {
        return "Sleeper";
    }
    
    ~Sleeper(){};
    void UnitTestSleeper();
};


/*******************************CLASS BOOKING*********************/
class Booking
{
private:
    //static PNR as this will be initialized only only and keep on updating on every call
    //private because once instactiated  should not accessed/ changed runtime outside the class
    static unsigned int sBookingPNRSerial;
    const static double sBaseFarePerKM;
    const static double sACSurcharge;
    const static double sLuxuryTaxPercent;
    //blocked copy ctor
    // Booking(const Booking& booking){};
    //blocked copy assignment operator
    Booking& operator=(const Booking& booking){};
protected:
    //once booking is done this attributes cannot be changed
    const Station fromStation_, toStation_;
    const Date date_;
    const BookingClass& bookingClass_;
    const int PNR_=0;
    //as fare rates can change due the change in farerates
    int fare_;
    bool bookingStatus_ = true;
    string bookingMessage_ = "BOOKING SUCCEEDED";
    // const Passanger passanger_;
public:
    //stores all the bookings done till now
    //vector of point will be delted explicitely inside dtor
    static vector<Booking*> sBookings;
    Booking(const Station& fromStation,const Station& toStation,const Date& date,const BookingClass& bookingClass,const Passanger* passanger = NULL) :
        PNR_(++sBookingPNRSerial),
        fromStation_(fromStation),
        toStation_(toStation),
        date_(date),
        bookingClass_(bookingClass)
    { 
        //fare is computed and stored in the sttribute 
        fare_ = ComputeFare();
        // cout<<"\nFare:"<<fare;
        //add current booking to the list
        sBookings.push_back(this);
    }
    //virtual for future extension
    virtual int ComputeFare(){
        //local  variable
        double fareTemp;
        //base fare = dist*basefarerate
        fareTemp = Railways::IndianRailways().GetDistance(fromStation_,toStation_) * sBaseFarePerKM;
        //loaded fare = basefare*loadfactor
        fareTemp *= bookingClass_.GetLoadFactor();
        //add acsurcharge
        if (bookingClass_.IsAC())
        {
            fareTemp += sACSurcharge;
        }
        //add luxury tax
        if (bookingClass_.IsLuxury())
        {
            fareTemp *= (1+sLuxuryTaxPercent);
        }
        //rouding off fare to closest integer
        return round(fareTemp);
    }
    //ouput streaming to print all the details of a particlar booking
    friend ostream& operator<<(ostream& rOs,const Booking& booking){
        rOs<<"\n"<<booking.bookingMessage_<<endl;
        rOs<<"PNR Number = "<<booking.PNR_<<endl;
        rOs<<"From Station = "<<booking.fromStation_<<endl;
        rOs<<"To Station = "<<booking.toStation_<<endl;
        rOs<<"Travel Date = "<<booking.date_<<endl;
        rOs<<"Travel Class = "<<booking.bookingClass_<<endl;
        rOs<<"Fare = "<<booking.fare_<<endl;
    }
    virtual ~Booking();
    void UnitTestBooking();
    
};
Booking::~Booking(){
    //sleanup bookings created
    vector<Booking*>::iterator it;
    for (it=sBookings.begin(); it!=sBookings.end();it++)
    {
        delete *it;
    }
}

#endif
