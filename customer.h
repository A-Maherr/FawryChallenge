#include "cart.h"
#include "product.h"
#include <iomanip>
#ifndef CUSTOMER_H
#define CUSTOMER_H

class customer {
    private:
        cart myCart;
        double balance = 0.0;
    public:
        customer(double n);   

        void addToCart(product* p, int quantity);
        
        void printCart() ;

    };


#endif 