#include <vector>
#include <utility>
#include "product.h"
#ifndef CART_H
#define CART_H

using namespace std;

class cart {
private:
    vector<pair<product*, int>> items;
    vector<pair<product*, int>> shippingItems;
    double productsCost = 0;
    double shippingCost = 0;
    bool containsShippingProduct = false;
public:
    cart(); 

    void add(product* p, int quantity);

    void printCart() const;

    double getTotalCost() const;

    void ShippingService() const;

    void clear();
};

#endif