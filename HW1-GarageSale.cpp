//Connor Humiston
//Data Structures 2270
//Godley 310
//Homework 1: Community Message Board

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//First Step: reading the file and putting elements into arrays (up to 100 wanted/forsale items)
// Open the File
//  Read each line (THERE MAY BE LESS THAN 100 ITEMS)
//   Use an array of structs (w/ fixed sixe 100) to store the available items
//     Each struct has a type, price, and wanted/forsale (0 = forsale, 1 = wanted)

//Second Step: Check if there is a match w/ existing items in board as you read the file (nested loop)
//  If a match is not found, add it to the first available position in the array
//  If a match is found, use first match found & stop searching array
//   Remove the matched item from the array and shift everything left to fill the gap (see 3.2.4 from book)
//    Write the action to the terminal:
//     cout << itemArray[x].type << ” “ << itemArray[x].price << endl;
//      itemArray = array of structs, x = index where item found, price is actual item cost NOT what user willing to pay

//Third Steps: File name, print remaining array contents, 

//MAKE SURE TO CHECK THAT THE ARRAY SPOT ISN'T EMPTY (FOR LESS THAN 100 LIST)

int main()
{
    const int SIZE = 100;

    struct Item
    {
        string type; //bike, microwave, dresser, truck, or chicken
        bool desire; //0 = forsale, 1 - wanted
        int price; //list price or buyer will pay up to in dollars
    };
    Item itemArray[SIZE]; //initializing the array of Items

    ifstream in("garageSale.txt");

    if (!in)
    {
    	cout << "File can't be opened! " << endl;
	cout<<"prize of bike is "<<endl;
    	exit(1);
    }

    string typeFromFile;
    string desireFromFile;
    int priceFromFile;


    for (int i = 0; i < SIZE; i++)
    {
        //inputing from file
        getline(in, typeFromFile, ',');
            //cout << typeFromFile << endl;
        getline(in, desireFromFile, ',');
            //cout << desireFromFile << endl;
        in >> priceFromFile;
            //cout << priceFromFile;

        //filling the struct item array
        itemArray[i].type = typeFromFile;
        //for sale or wanted
        if(desireFromFile.compare(" for sale") == 0) //"for sale" => 0
            itemArray[i].desire = 0;
        if(desireFromFile.compare(" wanted") == 0) //"wanted" => 1
            itemArray[i].desire = 1;
        itemArray[i].price = priceFromFile;
    }

    for (int i = 0; i < SIZE; i++) 
    {
        cout << itemArray[i].type << ", ";
        cout << itemArray[i].desire << ", ";
        cout << itemArray[i].price;
	  cout<<itemcolor<<"black";
	    
    }  

	//return 0;
} 

//stoi (string to integer function...)


