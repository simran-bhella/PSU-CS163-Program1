#include "food.h"

//Simranjit Bhella
//1/18/2021
//CS163
//The purpose of this code is to have a testing application for the ADT that is built in food.h with the defined functions in food.cpp.
//In this code under function main, this testing takes place through a dummy application with a user nav menu that allows for the testing of different functions.

int main() {

    list food;
    foodcart object;
    int SIZE = 100;
    char name[SIZE];
    char days[SIZE];
    int opening {0};
    int closing {0};
    char location[SIZE];
    int rating {0};


    char cuisine_adding_to[SIZE];
    char to_add[SIZE];
    char matching_cuisine[SIZE];
    char to_remove[SIZE];
    int search_time {0};
    int loop = 0;
    int menu {0};


    //Menu loop
    do {
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Please choose an option below: " << endl;
        cout << "[1] Add a cuisine to the list" << endl;
        cout << "[2] Add a foodcart to the list" << endl;
        cout << "[3] Display all cuisines" << endl;
        cout << "[4] Display all foodcarts" << endl;
        cout << "[5] Display foodcarts open at a certain time" << endl;
        cout << "[6] Display foodcarts from a certain cuisine" << endl;
        cout << "[6] Remove a foodcart from the list" << endl;
        cout << "[Anything Else] Quit the program" << endl << endl;
        cin >> menu;
        cin.ignore(100, '\n');

            //if user wants to add a cuisine
        if (menu == 1) {
            cout << "Please enter a cuisine name: ";
            cin.get(to_add, SIZE, '\n');
            cin.ignore(100, '\n');
            int addcuisinestatus = food.addcuisine(to_add);

            if (!addcuisinestatus) {
                cout << "Adding cuisine failed" << endl;
            }
            //if user wants to add a foodcart
        } else if (menu == 2) {

            cout << "Please enter which cuisine you would like to add this foodcart too: ";
            cin.get(cuisine_adding_to, SIZE, '\n');
            cin.ignore(100, '\n');

            cout << "Please enter the name of the foodcart: ";
            cin.get(name, SIZE, '\n');
            cin.ignore(100, '\n');

            cout << "Please enter the days that the foodcart are open (i.e. Monday, Wednesday, Friday): ";
            cin.get(days, SIZE, '\n');
            cin.ignore(100, '\n');

            cout << "Please enter the time the foodcart opens: ";
            cin >> opening;
            cin.ignore(100, '\n');

            cout << "Please enter the time the foodcart closes: ";
            cin >> closing;
            cin.ignore(100, '\n');

            cout << "Please enter the location of the foodcart: ";
            cin.get(location, SIZE, '\n');
            cin.ignore(100, '\n');

            cout << "Please enter your rating of the foodcart out of 10: ";
            cin >> rating;
            cin.ignore(100, '\n');

            int addfoodcartstatus = food.addfoodcart(name, days, opening, closing, location, rating, cuisine_adding_to);

            if (!addfoodcartstatus) {
                cout << "Adding foodcart failed" << endl;
            }
        }

            //if user wants to display all cuisines;
        else if (menu == 3) {
            int displaycuisinestatus = food.displaycuisine();

            if (!displaycuisinestatus) {
                cout << "Displaying cuisines failed" << endl;


            }
        }

            //if user wants to display all foodcarts
        else if (menu == 4) {
            int displayallfoodcartstatus = food.displayallfoodcart();

            if (!displayallfoodcartstatus) {
                cout << "Displaying all foodcarts failed" << endl;
            }
        }

            //if user wants to display foodcarts by time
        else if (menu == 5) {
            cout << "Please enter the time: ";
            cin >> search_time;
            cin.ignore(100, '\n');
            cout << "Here's what's open: " << endl;
            int displayfooddcartbytimestatus = food.displayfoodcartbytime(search_time);

            if (!displayfooddcartbytimestatus) {
                cout << "Displaying foodcarts by time failed" << endl;
            }
        }


            //if user wants to display foodcarts by cuisine
        else if (menu == 6) {
            cout << "What cuisine would you like to see all foodcarts for? Enter the cuisine name: ";
            cin.get(matching_cuisine, 100, '\n');
            cin.ignore(100, '\n');
            int displayfoodcartbycuisinestatus = food.displayfoodcartbycuisine(matching_cuisine);

            if (!displayfoodcartbycuisinestatus) {
                cout << "Displating foodcarts by cuisine failed" << endl;
            }

        }

        //If user wants to remove a foodcart
        else if (menu == 7) {
            cout <<"What foodcart would you like to remove? Enter the foodcart name: ";
            cin.get(to_remove, 100, '\n');
            cin.ignore(100, '\n');
            int removefoodcartstatus = food.removefoodcart(to_remove);

            if (!removefoodcartstatus) {
                cout << "Removing foodcart failed" << endl;
            }


        }
        //If anything else then change quite loop
        else {
            loop = 1;
        }
    } while (loop != 1);


}