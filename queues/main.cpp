#include <iostream>
#include "customer.h"
#include <queue>
int main() {
    std::queue<customer> customers;

    customer customer1, customer2, customer3, customer4, customer5;
    customer temp;

    customer1.setId(111);
    customer1.setFirstName("Aldous");
    customer1.setLastName("Huxley");

    customer2.setId(115);
    customer2.setFirstName("Victor");
    customer2.setLastName("Hugo");

    customer3.setId(77);
    customer3.setFirstName("Ilber");
    customer3.setLastName("Ortayli");

    customer4.setId(34);
    customer4.setFirstName("Panait");
    customer4.setLastName("Istrati");

    customer5.setId(346);
    customer5.setFirstName("George");
    customer5.setLastName("Orwell");

    customers.push(customer1);
    customers.push(customer2);
    customers.push(customer3);
    customers.push(customer4);
    customers.push(customer5);


    while (!customers.empty())
    {
     temp=customers.front();
     std::cout<<"Customer Checked Out - "<<temp.getId()<<" - "<<temp.getFirstName()<<" "<<temp.getLastName()<<std::endl;
     customers.pop();
    }
    std::cout<<"No customer left...";
}
