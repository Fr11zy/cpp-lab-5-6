#include <iostream>
#include <iomanip>
#include "Vehicle.h"

Vehicle::Vehicle():price(0),typeofTS(nullptr),ownerName(nullptr),priceoffuel(0),cons_per_km(0)
{
}

Vehicle::Vehicle(long int price,char* typeofTS,char* ownerName,long int priceoffuel,long int cons_per_km):
    price(price),typeofTS(typeofTS),ownerName(ownerName),priceoffuel(priceoffuel), cons_per_km(cons_per_km)
{
}

Vehicle::Vehicle(const Vehicle &other):
price(other.price),typeofTS(other.typeofTS),ownerName(other.ownerName),priceoffuel(other.priceoffuel), cons_per_km(other.cons_per_km)
{
}

Vehicle::~Vehicle()
{
}

size_t CountHowManyVehiclesUnderN(Vehicle owners[],size_t kol_owners,size_t N)
{
    size_t count=0;
    for (size_t i=0;i<kol_owners;++i)
    {
        if (owners[i].getPrice()<N)
        {
            count+=1;
        }
    }
    return count;
}

void findingPercentRatio(Vehicle owners[],size_t kol_owners)
{
    long int count1=0,count2=0,count3=0,count4=0;
    for (size_t i=0;i<kol_owners;++i)
    {
        if (owners[i].getTypeofTS()=="Car")
        {
            count1+=1;
        }
        else if (owners[i].getTypeofTS()=="Bike")
        {
            count2+=1;
        }
        else if (owners[i].getTypeofTS()=="ElectricBike")
        {
            count3+=1;
        }
        else if (owners[i].getTypeofTS()=="SpaceRocket")
        {
            count4+=1;
        }    
    }
    std::cout << "Cars: " << std::setprecision(2) << (double(count1)/double(kol_owners))*100 << "%" << std::endl;
    std::cout << "Bikes: " << std::setprecision(2) << (double(count2)/double(kol_owners))*100 << "%" << std::endl;
    std::cout << "Electric Bikes: " << std::setprecision(2) << (double(count3)/double(kol_owners))*100 << "%" << std::endl;
    std::cout << "Space Rockets: " << std::setprecision(2) << (double(count4)/double(kol_owners))*100 << "%" << std::endl;
}

void TypesofTSfromOnePerson(Vehicle owners[],size_t kol_owners,char* ownerName)
{
    for (size_t i=0;i<kol_owners;++i)
    {
        if (owners[i].getOwnerName()==ownerName)
        {
            std::cout << "Owner " << ownerName << " has " << owners[i].getTypeofTS() << std::endl;    
        }
    }
}

int main()
{
    Vehicle First;
    First.setAllInfo(300,"Bike","Diduk",0,200);
    Vehicle Second(1000,"Car","Andrew",200,20);
    Vehicle Third(2000000,"SpaceRocket","Diduk",10000,600);
    Vehicle Fourth(700,"ElectricBike","Stepan",150,100);
    Vehicle Fifth(First);
    Fifth.setAllInfo(600,"Bike","Ailon",0,100);

    Vehicle owners[]={First,Second,Third,Fourth,Fifth};
    std::cout << CountHowManyVehiclesUnderN(owners,5,800) << std::endl;
    findingPercentRatio(owners,5);
    TypesofTSfromOnePerson(owners,5,"Diduk");   
}