#include <iostream>
#include "product.h"
#include <string>
#include <stdexcept>
using namespace std;

product::product(string n, double p, int q, bool s, double w, bool ex, int exp) {
    name = n;
    price = p;
    quantity = q;
    canShip = s;
    weight = w;
    canExpire = ex;
    expiresIn = exp;
}

string product::getName() const {
    return name;
}

void product::decrementQuantity(int amount) {
    if(canExpire && expiresIn == 0){ // Assuming products that are expired cannot have a negative expiresIn value
        throw invalid_argument("Product: " + getName() +  " has expired and cannot be sold.");
    }
    if(amount > quantity) {
        throw invalid_argument("Product: " + getName() + " is out of stock." + " Only " + to_string(quantity) + " are left.");
    }
    quantity -= amount;
}

double product::getPrice() const {
    return price;
}

bool product::getCanShip() const {
    return canShip;
}

double product::getWeight() const {
    return weight;
}