main: main.o product.o cart.o customer.o
	g++ main.o product.o cart.o customer.o -o main
main.o: main.cpp product.h cart.h
	g++ -c main.cpp
customer.o: customer.cpp customer.h cart.h product.h
	g++ -c customer.cpp
cart.o: cart.cpp cart.h product.h
	g++ -c cart.cpp
product.o: product.cpp product.h
	g++ -c product.cpp
clean:
	rm -f *.o main
