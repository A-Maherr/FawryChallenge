#include "cart.h"
#include "product.h"
#include "customer.h"
#include <iomanip>

customer::customer(double n) : balance(n), myCart() {}

void customer::addToCart(product* p, int quantity) {
    myCart.add(p, quantity);
}

void customer::printCart() {
    if (myCart.getTotalCost() > balance) {
        throw invalid_argument("Insufficient balance to buy items in the cart.");
    } 
    balance -= myCart.getTotalCost();
    myCart.printCart();
    cout << "Customer balance: " << right << setw(9) << balance << endl;
    myCart.clear();
}

