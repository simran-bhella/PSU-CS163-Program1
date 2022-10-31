#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//Simranjit Bhella
//1/11/2021
//CS163
//The purpose of this code is to set up the structs and classes required for the foodcart program.
//These include the food cart struct with various info on the foodcarts,
//and the foodcartnode and cuisinenode structs.The cuisinenode class has a foodcartnode object as one of its private data members,
//and the footcartnode has the foodcart object as one of its private data members. All character arrays are to be dynamically allocated.

//This is the foodcart struct with various info on a foodcart.
struct foodcart {
    char * name;
    char * days;
    int opening;
    int closing;
    char * location;
    int rating;
};

//This is the foodcartnode struct, its data includes a foodcart object and a next pointer.
struct foodcartnode {
    foodcart this_foodcart;
    foodcartnode * next;
};

//This is the cuisinenode struct, its data includes a foodcartnode object, a cuisine name, and a next pointer.
struct cuisinenode {
    cuisinenode();//Constructor
    ~cuisinenode();//Destructor

    foodcartnode * foodcarthead;
    char * cuisinename;
    cuisinenode * next;

};

class list {
    public:
        list(); //List class constructor
        ~list(); //List class destructor
        int addcuisine(char * to_add); //Function to add a cuisine by passing in name
        int displaycuisine(); //Function called from front end to call the recursive display function
        int displaycuisineR(struct cuisinenode *head); //Function to display all cuisines recursively
        int addfoodcart(char * name, char * days, int opening, int closing, char * location, int rating, char * cuisine); //Function to add a foodcart by passing in a foodcart object
        int displayfoodcart(foodcart & foodcart); //Function to display a foodcart, used in other display functions
        int displayfoodcartbycuisine(char * find_by); //Function to display all foodcarts by cuisine
        int displayfoodcartbytime(int & time); //Function to display all foodcarts open at a certain time.
        int displayallfoodcart(); //Function to display all foodcarts
        int removefoodcart(char * to_remove); //Function to remove a foodcart
    private:
        cuisinenode * cuisinehead;
};
