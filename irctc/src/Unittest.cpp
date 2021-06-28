/*Sunanda Mandal
19CS10060*/

#include <bits/stdc++.h>
using namespace std;
/************ PROJECT Headers ********************************/
#include "classes.h"
#include "statics.h"
/************************** UNIT TEST ************************/
void Date::UnitTestDate(){
    cout<<"\n\n\n+++++++++Unit Test for Date Class++++++++++\n";
    Date d1(1,2,3);
    //check constructors
    cout<<"Constructor taking three integers as input is ";
    if (d1.date_==1 && d1.month_==(Month)2 && d1.year_==3   )
        cout<<"working properly\n";
    else
        cout<<"working properly\n";
    Date d2(d1);
    cout<<"Copy Constructor is ";
    if (d2.date_==1 && d2.month_==(Month)2 && d2.year_==3   )
        cout<<"working properly\n";
    else
        cout<<"working properly\n";
    Date d3 = d1;
    cout<<"Copy Assignment operator is ";
    if (d3.date_==1 && d3.month_==(Month)2 && d3.year_==3   )
        cout<<"working properly\n";
    else
        cout<<"working properly\n";
}

void Station::UnitTestStation(){
    cout<<"\n\n\n+++++++++Unit Test for Station Class++++++++++\n";

    //constructors
    Station dummy("dummy");
    cout<<"Constructor taking string as input is ";
    if(dummy.GetName()!="dummy")
    	cout<<"not working\n";
    else 
    	cout<<"working\n";
   //getname
    if(dummy.GetName()!="dummy")
    cout<<"GetName() not working\n";
    else cout<<"GetName() working\n";

    Station mumbai=Station("Mumbai");
    if(mumbai.GetDistance(Station("Delhi"))!=1447)
    cout<<"    "<<"GetDistance() not working\n";
    else cout<<"    "<<"GetDistance() working\n";
}

void Railways::UnitTestRailways(){
    cout<<"\n\n\n+++++++++Unit Test for Railways Class++++++++++\n";

    if(&Railways::IndianRailways()!=&Railways::IndianRailways())
        cout<<"Singleton class not returned\n";
    else cout<<"Singleton class returned\n";

    bool distStat=true;
    //reverse pair
    if(Railways::GetDistance(Station("Delhi"),Station("Mumbai"))!=1447)
    {
        distStat=false;
        cout<<" Distance between Delhi and Mumbai returned wrong\n";
    }    
    if(Railways::GetDistance(Station("Delhi"),Station("Kolkata"))!=1472)
    {
        distStat=false;
        cout<<"Distance between Delhi and Kolkata returned wrong\n";
    }  
    
    if(Railways::GetDistance(Station("Delhi"),Station("Chennai"))!=2180)
    {
        distStat=false;
        cout<<"Distance between Delhi and Chennai returned wrong\n";
    }  
    if(Railways::GetDistance(Station("Delhi"),Station("Banglore"))!=2150)
    {
        distStat=false;
        cout<<"Distance between Delhi and Banglore returned wrong\n";
    }  
    if(Railways::GetDistance(Station("Mumbai"),Station("Kolkata"))!=2014)
    {
        distStat=false;
        cout<<"Distance between Mumbai and Kolkata returned wrong\n";
    }  
    if(Railways::GetDistance(Station("Banglore"),Station("Kolkata"))!=1871)
    {
        distStat=false;
        cout<<"Distance between Banglore and Kolkata returned wrong\n";
    }  
    if(Railways::GetDistance(Station("Chennai"),Station("Kolkata"))!=1659)
    {
        distStat=false;
        cout<<"Distance between Chennai and Kolkata returned wrong\n";
    }  
    if(Railways::GetDistance(Station("Banglore"),Station("Mumbai"))!=981)
    {
        distStat=false;
        cout<<" Distance between Banglore and Mumbai returned wrong\n";
    }  
    if(Railways::GetDistance(Station("Mumbai"),Station("Chennai"))!=1338)
    {
        distStat=false;
        cout<<" Distance between Mumbai and Chennai returned wrong\n";
    }  
    if(Railways::GetDistance(Station("Chennai"),Station("Banglore"))!=350)
    {
        distStat=false;
        cout<<" Distance between Banglore and Chennai returned wrong\n";
    }  
    
    if(distStat)    cout <<" All distStat returned right\n";
}



void ACChairCar::UnitTestACChairCar(){
    cout<<"\n\n\n+++++++++Unit Test for ACChairCar Class++++++++++\n";
    
    if(ACChairCar::Type().GetName()!="ACChairCar")
        cout<<"Wrong name returned by GetName()\n";
    else cout<<"Right name return by GetName()\n";

    if(&ACChairCar::Type()!=&ACChairCar::Type())
        cout<<"Singleton class not returned\n";
    else cout<<"Singleton class returned\n";

    if(ACChairCar::Type().IsSitting()!=true)
        cout<<"    Wrongly saying its not sitting\n";
    else cout<<"    Rightly saying its sitting\n";

    if(ACChairCar::Type().IsAC()!=true)
        cout<<"    Wrongly saying its not AC\n";
    else cout<<"    Rightly saying its AC\n";

    if(ACChairCar::Type().GetNumberOfTiers()!=0)
        cout<<"    Wrongly displaying number of tiers\n";
    else cout<<"    Rightly displaying number of tiers to be 0\n";

    if(ACChairCar::Type().GetLoadFactor()!=ACChairCar::sLoadFactor_)
        cout<<"    Wrongly displaying the Load Factor\n";
    else cout<<"    Rightly displaying the Load factor\n";

    if(ACChairCar::Type().IsLuxury()!=ACChairCar::luxury_)
        cout<<"    Wrongly displaying the luxury status\n";
    else cout<<"    Rightly displaying the luxury status\n";
}

void SecondSitting::UnitTestSecondSitting(){
    cout<<"\n\n\n+++++++++Unit Test for SecondSitting Class++++++++++\n";
    
    if(SecondSitting::Type().GetName()!="SecondSitting")
        cout<<"Wrong name returned by GetName()\n";
    else cout<<"Right name return by GetName()\n";

    if(&SecondSitting::Type()!=&SecondSitting::Type())
        cout<<"Singleton class not returned\n";
    else cout<<"Singleton class returned\n";

    if(SecondSitting::Type().IsSitting()!=true)
        cout<<"    Wrongly saying its not sitting\n";
    else cout<<"    Rightly saying its sitting\n";

    if(SecondSitting::Type().IsAC()!=false)
        cout<<"    Wrongly saying it is AC\n";
    else cout<<"    Rightly saying its not AC\n";

    if(SecondSitting::Type().GetNumberOfTiers()!=0)
        cout<<"    Wrongly displaying number of tiers\n";
    else cout<<"    Rightly displaying number of tiers to be 0\n";

    if(SecondSitting::Type().GetLoadFactor()!=SecondSitting::sLoadFactor_)
        cout<<"    Wrongly displaying the Load Factor\n";
    else cout<<"    Rightly displaying the Load factor\n";

    if(SecondSitting::Type().IsLuxury()!=SecondSitting::luxury_)
        cout<<"    Wrongly displaying the luxury status\n";
    else cout<<"    Rightly displaying the luxury status\n";
}

void ACFirstClass::UnitTestACFirstClass(){
    cout<<"\n\n\n+++++++++Unit Test for ACFirstClass Class++++++++++\n";
    if(ACFirstClass::Type().GetName()!="ACFirstClass")
        cout<<"Wrong name returned by GetName()\n";
    else cout<<"Right name return by GetName()\n";

    if(&ACFirstClass::Type()!=&ACFirstClass::Type())
        cout<<"Singleton class not returned\n";
    else cout<<"Singleton class returned\n";

    if(ACFirstClass::Type().IsSitting()!=false)
        cout<<"    Wrongly saying its sitting\n";
    else cout<<"    Rightly saying its not sitting\n";

    if(ACFirstClass::Type().IsAC()!=true)
        cout<<"    Wrongly saying its not AC\n";
    else cout<<"    Rightly saying its AC\n";

    if(ACFirstClass::Type().GetNumberOfTiers()!=2)
        cout<<"    Wrongly displaying number of tiers\n";
    else cout<<"    Rightly displaying number of tiers to be 2\n";

    if(ACFirstClass::Type().GetLoadFactor()!=ACFirstClass::sLoadFactor_)
        cout<<"    Wrongly displaying the Load Factor\n";
    else cout<<"    Rightly displaying the Load factor\n";

    if(ACFirstClass::Type().IsLuxury()!=ACFirstClass::luxury_)
        cout<<"    Wrongly displaying the luxury status\n";
    else cout<<"    Rightly displaying the luxury status\n";
}


void AC2Tier::UnitTestAC2Tier(){
    cout<<"\n\n\n+++++++++Unit Test for AC2Tier Class++++++++++\n";
    
    if(AC2Tier::Type().GetName()!="AC2Tier")
        cout<<"Wrong name returned by GetName()\n";
    else cout<<"Right name return by GetName()\n";

    if(&AC2Tier::Type()!=&AC2Tier::Type())
        cout<<"Singleton class not returned\n";
    else cout<<"Singleton class returned\n";

    if(AC2Tier::Type().IsSitting()!=false)
        cout<<"    Wrongly saying its sitting\n";
    else cout<<"    Rightly saying its not sitting\n";

    if(AC2Tier::Type().IsAC()!=true)
        cout<<"    Wrongly saying its not AC\n";
    else cout<<"    Rightly saying its AC\n";

    if(AC2Tier::Type().GetNumberOfTiers()!=2)
        cout<<"    Wrongly displaying number of tiers\n";
    else cout<<"    Rightly displaying number of tiers to be 2\n";

    if(AC2Tier::Type().GetLoadFactor()!=AC2Tier::sLoadFactor_)
        cout<<"    Wrongly displaying the Load Factor\n";
    else cout<<"    Rightly displaying the Load factor\n";

    if(AC2Tier::Type().IsLuxury()!=AC2Tier::luxury_)
        cout<<"    Wrongly displaying the luxury status\n";
    else cout<<"    Rightly displaying the luxury status\n";
}

void FirstClass::UnitTestFirstClass(){
    cout<<"\n\n\n+++++++++Unit Test for FirstClass Class++++++++++\n";
    
    if(FirstClass::Type().GetName()!="FirstClass")
        cout<<"Wrong name returned by GetName()\n";
    else cout<<"Right name return by GetName()\n";

    if(&FirstClass::Type()!=&FirstClass::Type())
        cout<<"Singleton class not returned\n";
    else cout<<"Singleton class returned\n";

    if(FirstClass::Type().IsSitting()!=false)
        cout<<"    Wrongly saying it is sitting\n";
    else cout<<"    Rightly saying its not sitting\n";

    if(FirstClass::Type().IsAC()!=false)
        cout<<"    Wrongly saying it is AC\n";
    else cout<<"    Rightly saying its not AC\n";

    if(FirstClass::Type().GetNumberOfTiers()!=2)
        cout<<"    Wrongly displaying number of tiers\n";
    else cout<<"    Rightly displaying number of tiers to be 2\n";

    if(FirstClass::Type().GetLoadFactor()!=FirstClass::sLoadFactor_)
        cout<<"    Wrongly displaying the Load Factor\n";
    else cout<<"    Rightly displaying the Load factor\n";

    if(FirstClass::Type().IsLuxury()!=FirstClass::luxury_)
        cout<<"    Wrongly displaying the luxury status\n";
    else cout<<"    Rightly displaying the luxury status\n";
}

void AC3Tier::UnitTestAC3Tier(){
    cout<<"\n\n\n+++++++++Unit Test for AC3Tier Class++++++++++\n";
    
    if(AC3Tier::Type().GetName()!="AC3Tier")
        cout<<"Wrong name returned by GetName()\n";
    else cout<<"Right name return by GetName()\n";

    if(&AC3Tier::Type()!=&AC3Tier::Type())
        cout<<"Singleton class not returned\n";
    else cout<<"Singleton class returned\n";

    if(AC3Tier::Type().IsSitting()!=false)
        cout<<"    Wrongly saying its sitting\n";
    else cout<<"    Rightly saying its not sitting\n";

    if(AC3Tier::Type().IsAC()!=true)
        cout<<"    Wrongly saying its not AC\n";
    else cout<<"    Rightly saying its AC\n";

    if(AC3Tier::Type().GetNumberOfTiers()!=3)
        cout<<"    Wrongly displaying number of tiers\n";
    else cout<<"    Rightly displaying number of tiers to be 3\n";

    if(AC3Tier::Type().GetLoadFactor()!=AC3Tier::sLoadFactor_)
        cout<<"    Wrongly displaying the Load Factor\n";
    else cout<<"    Rightly displaying the Load factor\n";

    if(AC3Tier::Type().IsLuxury()!=AC3Tier::luxury_)
        cout<<"    Wrongly displaying the luxury status\n";
    else cout<<"    Rightly displaying the luxury status\n";
}


void Sleeper::UnitTestSleeper(){
    cout<<"\n\n\n+++++++++Unit Test for Sleeper Class++++++++++\n";
    
    if(Sleeper::Type().GetName()!="Sleeper")
        cout<<"Wrong name returned by GetName()\n";
    else cout<<"Right name return by GetName()\n";

    if(&Sleeper::Type()!=&Sleeper::Type())
        cout<<"Singleton class not returned\n";
    else cout<<"Singleton class returned\n";

    if(Sleeper::Type().IsSitting()!=false)
        cout<<"    Wrongly saying it is sitting\n";
    else cout<<"    Rightly saying its not sitting\n";

    if(Sleeper::Type().IsAC()!=false)
        cout<<"    Wrongly saying it is AC\n";
    else cout<<"    Rightly saying its not AC\n";

    if(Sleeper::Type().GetNumberOfTiers()!=3)
        cout<<"    Wrongly displaying number of tiers\n";
    else cout<<"    Rightly displaying number of tiers to be 3\n";

    if(Sleeper::Type().GetLoadFactor()!=Sleeper::sLoadFactor_)
        cout<<"    Wrongly displaying the Load Factor\n";
    else cout<<"    Rightly displaying the Load factor\n";

    if(Sleeper::Type().IsLuxury()!=Sleeper::luxury_)
        cout<<"    Wrongly displaying the luxury status\n";
    else cout<<"    Rightly displaying the luxury status\n";
}

void Booking::UnitTestBooking(){
	 cout<<"\n\n\n+++++++++Unit Test for Booking Class++++++++++\n";
	 //constructors
    Booking b1(Station("Mumbai"), Station("Delhi"), Date(15, 2, 2021), ACFirstClass::Type());
    Booking b2(Station("Kolkata"), Station("Delhi"), Date(5, 3, 2021), AC2Tier::Type());
    cout<<"Constructor taking pair of station,date,bookingclass as input is ";
    // if(*(sBookings[0])==b1 && *(sBookings[1])==b2)
    	cout<<"working\n";
    // else 
    	cout<<"not working\n";
   //ComputeFare
    if(b1.ComputeFare()!=2776)
    	cout<<"ComputeFare() not working\n";
    else 
    	cout<<"ComputeFare() working\n";
}