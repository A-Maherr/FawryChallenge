#include <iostream> 
#include <string>
#ifndef PRODUCT_H
#define PRODUCT_H



using namespace std;

class product {
    private:
        string name; 
        double price; 
        int quantity; 
        bool canShip; 
        double weight;     
        bool canExpire; 
        int expiresIn;    
    public:
        product(string n, double p, int q, bool s = true, double w = 0, bool ex = true, int exp = 7);

        string getName() const;

        void decrementQuantity(int amount = 1);

        double getPrice() const;

        bool getCanShip() const;

        double getWeight() const;
};

        
#endif