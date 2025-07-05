#include "cart.h"
#include "product.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

cart::cart() {}

void cart::add(product* p, int quantity) {
    if (quantity <= 0) {
        throw invalid_argument("Quantity must be greater than zero.");
    }
    p->decrementQuantity(quantity);
    
    if(p->getCanShip()) {
        if(!containsShippingProduct) containsShippingProduct = true;
        shippingCost += (p->getWeight() * quantity) * 0.1; 
        bool found = false;
        for(auto& item : shippingItems) {
            if (item.first == p) {
                item.second += quantity;
                found = true;
                break;
            }
        }
        if (!found) {
            shippingItems.push_back(make_pair(p, quantity));
        }
    }

    for (auto& item : items) {
        if (item.first == p) {
            item.second += quantity;
            productsCost += p->getPrice() * quantity;
            return;
        }
    }
    
    productsCost += p->getPrice() * quantity;
    items.push_back(make_pair(p, quantity));
}

void cart::ShippingService() const {
    cout << "** Shipment notice **" << endl;
    double totalWeight = 0;

    for (auto& item : shippingItems) {
        product* p = item.first;
        int quantity = item.second;
        double weight = p->getWeight() * quantity;
        totalWeight += weight;

        cout << setw(2) << quantity << "x "
             << left << setw(15) << p->getName()
             << right << setw(6) << weight << "g" << endl;
    }

    cout << "Total package weight "
         << fixed << setprecision(1)
         << (totalWeight / 1000) << "kg" << endl;
}

void cart::printCart() const {
    if(items.empty()) {
        throw invalid_argument("Cart is empty.");
    }

    if(containsShippingProduct) ShippingService();

    cout << "** Checkout receipt **" << endl;

    for (auto& item : items) {
        product* p = item.first;
        int quantity = item.second;
        double cost = p->getPrice() * quantity;

        cout << setw(2) << quantity << "x "
             << left << setw(15) << p->getName()
             << right << setw(8) << fixed << setprecision(2) << cost << endl;
    }

    cout << "----------------------" << endl;

    cout << left << setw(15) << "Subtotal"
         << right << setw(10) << fixed << setprecision(2) << productsCost << endl;

    cout << left << setw(15) << "Shipping"
         << right << setw(10) << fixed << setprecision(2) << shippingCost << endl;

    cout << left << setw(15) << "Amount"
         << right << setw(10) << fixed << setprecision(2) << (productsCost + shippingCost) << endl;
}


double cart::getTotalCost() const {
    return productsCost + shippingCost;
}

void cart::clear() {
    items.clear();
    shippingItems.clear();
    productsCost = 0;
    shippingCost = 0;
    containsShippingProduct = false;
}