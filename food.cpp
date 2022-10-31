#include "food.h"

//Simranjit Bhella
//1/14/2021
//CS163
//The purpose of this file is to implement the functions from the ADT list class:
//int displaycuisine();
//int addfoodcart(foodcart & to_add);
//int displayfoodcartbycuisine(char & find_by);
//int displayfoodcartbytime(int & open, int & close);
//int displayallfoodcart();
//int removefoodcart(char & to_remove);
//As an ADT class, each function does not directly interact with the appliction (except for maybe the display functions).
//ALl functions besides constructor and destructor return 0 or 1 to announce failure or success.

//List Constructor
list::list() {
    cuisinehead = new cuisinenode();
}

//List Destructor
list::~list() {
    delete cuisinehead;
}

//Cuisinenode Constructor
cuisinenode::cuisinenode() {
    foodcarthead = new foodcartnode();
    cuisinename = NULL;

}

//Cuisinenode Destructor
cuisinenode::~cuisinenode() {
    if (cuisinename != NULL) {
        delete [] cuisinename;
    }
    cuisinename = NULL;
    delete foodcarthead;
}




//This function will add a cuisine name to a node in the cuisine linked list.
int list::addcuisine(char * to_add) {

    //If no data return 0 for error
    if (!to_add) {
        return 0;
    }

    //If the head of the LLL is not populated then fill it and return 1
    if (cuisinehead->cuisinename == nullptr) {
        cuisinehead->cuisinename = new char[strlen(to_add)+1]; //Dynamically allocated cuisine name
        strcpy(cuisinehead->cuisinename, to_add);
        return 1;
    }

    //Otherwise traverse until empty node and fill.
    cuisinenode *tmp = cuisinehead;
    cuisinenode *prev;
    while (tmp != nullptr) {
        //Return error if the cuisine name is already in the list.
        if (tmp->cuisinename) {
            if (strcmp(tmp->cuisinename, to_add) == 0) {
                return 0;
            }
        }
        prev = tmp;
        tmp = tmp->next;
    }
    //Once tmp is on an empty node, copy in the cuisine name
    cuisinenode *next = new cuisinenode();
    next->cuisinename = new char[strlen(to_add) + 1]; //Dynamically allocated cuisine name
    strcpy(next->cuisinename, to_add);
    prev->next = next;
}

//Iterative version of display function, no longer used
//This function will display all cuisine names directly to the program
//int list::displaycuisine() {
//    //If no data in the list return 0 for error
//    if (!cuisinehead) {
//        return 0;
//    }
//    cuisinenode *tmp = cuisinehead;
//    int count = 1;
//
//    //Traverse the whole list while outputting the cuisine names
//    while (tmp != nullptr) {
//        cout << "Cuisine " << count << ": " << tmp->cuisinename << endl;
//        tmp = tmp->next;
//        count +=1;
//    }
//    return 1;
//}

//Display function that calls recursive function
int list::displaycuisine() {
    int success = displaycuisineR(cuisinehead);
}


//Display all cuisines recursively
int list::displaycuisineR(struct cuisinenode * head) {

    //If no data in the list return 0 for error
    if (!cuisinehead) {
        return 0;
    }
    if (head != NULL) {
        cout << "Cuisine: " << head->cuisinename << endl;
        displaycuisineR(head->next);

    }

}

//Function to add foodcart
int list::addfoodcart(char * name, char * days, int opening, int closing, char * location, int rating, char * cuisine){
    if (!name || !cuisine) {
        return 0;
    }

    //Traverse until found node with matching cuisine name
    cuisinenode * cuisinetmp = cuisinehead;
    while (strcmp(cuisinetmp->cuisinename,cuisine) != 0) {
        cuisinetmp = cuisinetmp->next;
    }

    //If foodcarthead is not populated, fill all foodcart data members dynamically
    if(cuisinetmp->foodcarthead->this_foodcart.name == nullptr) {
        cuisinetmp->foodcarthead->this_foodcart.name = new char[strlen(name) + 1]; //Dynamically allocated cuisine name
        strcpy(cuisinetmp->foodcarthead->this_foodcart.name, name);

        cuisinetmp->foodcarthead->this_foodcart.days = new char[strlen(days) + 1]; //Dynamically allocated cuisine days
        strcpy(cuisinetmp->foodcarthead->this_foodcart.days, days);

        cuisinetmp->foodcarthead->this_foodcart.opening = opening;

        cuisinetmp->foodcarthead->this_foodcart.closing = closing;

        cuisinetmp->foodcarthead->this_foodcart.location = new char[strlen(location) + 1]; //Dynamically allocated cuisine location
        strcpy(cuisinetmp->foodcarthead->this_foodcart.location, location);

        cuisinetmp->foodcarthead->this_foodcart.rating = rating;

        return 1;
    }

    //Otherwise, Traverse until empty node then fill all foodcart data member dynamically
    foodcartnode *foodcarttmp = cuisinetmp->foodcarthead;
    foodcartnode *foodcartprev;
    while(foodcarttmp != nullptr) {
        foodcartprev = foodcarttmp;
        foodcarttmp = foodcarttmp->next;
    }

    //Fill data in new node
    foodcartnode * foodcartnext = new foodcartnode();
    foodcartnext->this_foodcart.name = new char[strlen(name) + 1]; //Dynamically allocated cuisine name
    strcpy(foodcartnext->this_foodcart.name, name);

    foodcartnext->this_foodcart.days = new char[strlen(days) + 1]; //Dynamically allocated cuisine days
    strcpy(foodcartnext->this_foodcart.days, days);

    foodcartnext->this_foodcart.opening = opening;

    foodcartnext->this_foodcart.closing = closing;

    foodcartnext->this_foodcart.location = new char[strlen(location) + 1]; //Dynamically allocated cuisine location
    strcpy(foodcartnext->this_foodcart.location, location);

    foodcartnext->this_foodcart.rating = rating;

    //Link up node to list
    foodcartprev->next = foodcartnext;
}

//Base display function to be used in other functions
int list::displayfoodcart(foodcart & print_foodcart) {
    cout << endl << "Name: " << print_foodcart.name << endl << "Days open: " << print_foodcart.days << endl << "Opens at: " << print_foodcart.opening << endl
         << "Closes at: " << print_foodcart.closing << endl << "Location: " << print_foodcart.location << endl << "Rating: " << print_foodcart.rating << endl;

}

//Display by food cart by cuisine function
int list::displayfoodcartbycuisine(char * find_by){
    if (!cuisinehead) {
        return 0;
    }

    //Find cuisine in list
    cuisinenode * cuisinetmp = cuisinehead;
    while (strcmp(cuisinetmp->cuisinename,find_by) != 0) {
        cuisinetmp = cuisinetmp->next;
        //Return 0 if cuisine name not in list
        if (cuisinetmp == nullptr) {
            return 0;
        }
    }

    //Traverse through sending each foodcart object to the display function
    foodcartnode *foodcarttmp = cuisinetmp->foodcarthead;
    while (foodcarttmp != nullptr) {
        displayfoodcart(foodcarttmp->this_foodcart);
        foodcarttmp = foodcarttmp->next;
    }
    return 1;
}



//Display foodcart by time
int list::displayfoodcartbytime(int & time){
    //If there is no list return error
    if (!cuisinehead) {
        return 0;
    }
    cuisinenode * cuisinetmp = cuisinehead;
    foodcartnode *foodcarttmp = cuisinetmp->foodcarthead;

    //Nested traversal, for each cuisine node traverse through the foodcart list and display all
    while (cuisinetmp != nullptr) {
        cout << endl << endl<< "Cuisine: " << cuisinetmp->cuisinename << endl;
        foodcarttmp = cuisinetmp->foodcarthead;
        while (foodcarttmp != nullptr) {
            //If the foodcart is open at the time requested then print
            if (foodcarttmp->this_foodcart.opening <= time and foodcarttmp->this_foodcart.closing >= time) {
                displayfoodcart(foodcarttmp->this_foodcart);
            }
            foodcarttmp = foodcarttmp->next;
        }

        cuisinetmp = cuisinetmp->next;
    }
    return 1;
}


//Display all foodcarts
int list::displayallfoodcart(){
    //If there is no list return error
    if (!cuisinehead) {
        return 0;
    }
    cuisinenode * cuisinetmp = cuisinehead;
    foodcartnode *foodcarttmp = cuisinetmp->foodcarthead;

    //Nested traversal, for each cuisine node traverse through the foodcart list and display all
    while (cuisinetmp != nullptr) {
        cout << endl << endl<< "Cuisine: " << cuisinetmp->cuisinename << endl;
        foodcarttmp = cuisinetmp->foodcarthead;
        while (foodcarttmp != nullptr) {
            displayfoodcart(foodcarttmp->this_foodcart);
            foodcarttmp = foodcarttmp->next;
        }

        cuisinetmp = cuisinetmp->next;
    }
    return 1;
}

int list::removefoodcart(char * to_remove) {
    //If there is no list return error
    if (!cuisinehead) {
        return 0;
    }

    cuisinenode * cuisinetmp = cuisinehead;
    foodcartnode *foodcarttmp = cuisinetmp->foodcarthead;
    foodcartnode *foodcartprev;

    //Nested traversal, for each cuisine node traverse through the foodcart list until node to delete has been found
    while (cuisinetmp != nullptr and strcmp(foodcarttmp->this_foodcart.name, to_remove) != 0) {
        cout << endl << endl<< "Cuisine: " << cuisinetmp->cuisinename << endl;
        foodcarttmp = cuisinetmp->foodcarthead;
        while (strcmp(foodcarttmp->this_foodcart.name, to_remove) != 0) {
            displayfoodcart(foodcarttmp->this_foodcart);
            foodcartprev = foodcarttmp;
            foodcarttmp = foodcarttmp->next;
        }

        cuisinetmp = cuisinetmp->next;
    }

    //set the last nodes next to the current nodes next then delete current node
    foodcartprev->next = foodcarttmp->next;
    delete cuisinetmp;

}