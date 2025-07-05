#include "product.h"
#include "customer.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    // products follow the format: product(name, price, quantity, canShip, weight (gm), canExpire, expiresIn (days) )

    product Cheese("Cheese", 5.0, 50, true, 200, true, 30);
    product Laptop("Laptop", 1500, 10, true, 500);
    product Biscuits("Biscuits", 2.0, 100, true, 100, true, 60);
    product TV("TV", 1000, 5, true, 1000);
    product Milk("Milk", 1.0, 200, true, 500, true, 0); // Milk is expired
    product MobileScratchCard("Mobile Scratch Card", 10.0, 100, false);
    
    // Test Case 1: Cart is Empty, expecting an exception
    customer c1(1000);
    try {
        c1.printCart();
    } catch (const invalid_argument& e) {
        cout << "Test Case 1: " << e.what() << endl;
    }

    // Test Case 2: Customer has insufficient balance, expecting an exception
    customer c2(1);
    try {
        c2.addToCart(&Cheese, 1);
        c2.printCart();
    } catch (const invalid_argument& e) {
        cout << "Test Case 2: " << e.what() << endl;
    }

    //Test Case 3: One product is out of stock or expired, expecting an exception
    customer c3(100);
    try {
        c3.addToCart(&Milk, 1);
        c3.printCart();
    } catch (const invalid_argument& e) {
        cout << "Test Case 3.1: " << e.what() << endl;
    }

    try {
        c3.addToCart(&TV, 6);
        c3.printCart();
    } catch (const invalid_argument& e) {
        cout << "Test Case 3.2: " << e.what() << endl;
    }

    // Test Case 4: Adding a mix of products that require shipping and those that do not, expecting a successful cart print
    customer c4(3000); 
    try {
        c4.addToCart(&Cheese, 2);
        c4.addToCart(&Laptop, 1);
        c4.addToCart(&Biscuits, 5);
        c4.addToCart(&TV, 1);
        c4.addToCart(&MobileScratchCard, 10);
        c4.printCart();
    } catch (const invalid_argument& e) {
        cout << "Test Case 4: " << e.what() << endl;
    }
    
    // Test Case 5: Only adding products that do not require shipping, expecting a successful cart print without a shipment notice
    try {
        customer c5(500);
        c5.addToCart(&MobileScratchCard, 5);
        c5.printCart();
    } catch (const invalid_argument& e) {
        cout << "Test Case 5: " << e.what() << endl;
    }

    // Test Case 6: Adding a product with quantity 0, expecting it not to be added to the cart, expecting an exception
    try {
        customer c6(100);
        c6.addToCart(&Cheese, 0); 
        c6.printCart();
    } catch (const invalid_argument& e) {
        cout << "Test Case 6: " << e.what() << endl;
    }

    // Test Case 7: Adding a product with a given quantity, then adding the same product with a different quantity, expecting the quantities to be summed
    try {
        customer c7(1000);
        c7.addToCart(&Cheese, 2);
        c7.addToCart(&Cheese, 3); // Should sum up to 5
        c7.printCart();
    } catch (const invalid_argument& e) {
        cout << "Test Case 7: " << e.what() << endl;
    }
    

    return 0;
}