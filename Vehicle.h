#include <iostream>

class Vehicle
{
    long int price;
    std::string typeofTS;
    std::string ownerName;
    long int priceoffuel;
    long int cons_per_km;

    public:
        Vehicle();
        Vehicle(long int price,std::string typeofTS,std::string ownerName,long int priceoffuel,long int cons_per_km);
        Vehicle(const Vehicle &other);
       ~Vehicle();

        long int getPrice() const
        {
            return price;
        }
        std::string getTypeofTS() const
        {
            return typeofTS;
        }
        std::string getOwnerName() const
        {
            return ownerName;
        }
        long int getFuelprice() const
        {
            return priceoffuel;
        }
        long int getCons_per_km() const
        {
            return cons_per_km;
        }

        void setPrice(long int Newprice)
        {
            this->price=Newprice;
        }
        void setTypeofTS(std::string NewtypeofTS)
        {
            this->typeofTS=NewtypeofTS;
        }
        void setOwnerName(std::string NewownerName)
        {
            this->ownerName=NewownerName;
        }
        void setFuelprice(long int Newpriceoffuel)
        {
            this->priceoffuel=Newpriceoffuel;
        }
        void setCons_per_km(long int Newcons_per_km)
        {
            this->cons_per_km=Newcons_per_km;
        }
        void setAllInfo(long int Newprice,std::string NewtypeofTS,std::string NewownerName,long int Newpriceoffuel,long int Newcons_per_km)
        {
            this->price=Newprice;
            this->typeofTS=NewtypeofTS;
            this->ownerName=NewownerName;
            this->priceoffuel=Newpriceoffuel;
            this->cons_per_km=Newcons_per_km;
        }

        void printPrice() const
        {
            std::cout << "Price: " << price << std::endl;
        }
        void printTypeofTS() const
        {
            std::cout << "TypeofTS: " << typeofTS << std::endl;
        }
        void printOwnerName() const
        {
            std::cout << "Owner's Name: " << ownerName << std::endl;
        }
        void printFuelprice() const
        {
            std::cout << "Fuel price: " << priceoffuel << std::endl;
        }
        void printCons_per_km() const
        {
            std::cout << "Consumption per km: " << cons_per_km << std::endl;
        }
        void printAll() const
        {
            std::cout << "Price: " << price << std::endl;
            std::cout << "TypeofTS: " << typeofTS << std::endl;
            std::cout << "Owner's Name: " << ownerName << std::endl;
            std::cout << "Fuel price: " << priceoffuel << std::endl;
            std::cout << "Consumption per km: " << cons_per_km << std::endl;
        }
};