#include <iostream>
#include <iomanip>
#include "Vehicle.h"

Vehicle::Vehicle():price(0),typeofTS(""),ownerName(""),priceoffuel(0),cons_per_km(0)
{
}

Vehicle::Vehicle(long int price,std::string typeofTS,std::string ownerName,long int priceoffuel,long int cons_per_km):
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

size_t CountHowManyVehiclesBelowN(Vehicle owners[],size_t kol_owners,size_t N)
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

void findingPercentRatio(Vehicle owners[],std::string TypesOFTS[],int kol_owners)
{
    double counts[kol_owners]{0};
    for (int i=0;i<kol_owners;++i)
    {
        for (int j=0;j<kol_owners;++j)
        {
            if (TypesOFTS[i]==owners[j].getTypeofTS())
            {
                counts[i]+=1;
            }
        }
    }
    for (int i=0;i<kol_owners;++i)
    {
        std::cout << TypesOFTS[i] << ": " << std::setprecision(2) << (counts[i])/double(kol_owners)*100 << "%" << std::endl;
    }
}

void TypesofTSfromOnePerson(Vehicle owners[],size_t kol_owners,std::string ownerName)
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
    Fifth.setAllInfo(600,"Monowheel","Ailon",0,100);
    Fifth.printAll();
    std::cout << std::endl;
    std::string TypesOFTS[5]{"Bike","Car","SpaceRocket","ElectricBike","Monowheel"};
    Vehicle owners[]={First,Second,Third,Fourth,Fifth};
    std::cout << "Enter the price threshold:  ";
    int N_price;
    std::cin >> N_price;
    std::cout << std::endl;
    std::cout << "Vehicle which price below " << N_price << ": "<< CountHowManyVehiclesBelowN(owners,5,N_price) << std::endl;
    findingPercentRatio(owners,TypesOFTS,5);
    TypesofTSfromOnePerson(owners,5,"Diduk");   
}