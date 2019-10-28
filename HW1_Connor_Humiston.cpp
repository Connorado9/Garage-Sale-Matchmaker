//Connor Humiston
//Data Structures 2270
//Godley 310
//Homework 1: Community Message Board

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Item
{
    string type; //bike, microwave, dresser, truck, or chicken
    bool desire; //0 = forsale, 1 - wanted
    int price; //list price or buyer will pay up to in dollars
};

void deleteArrayElement(struct Item* array, int index, int numElements)
{
    if(numElements >= 2)
    {
        for (int i = index; i <= numElements - 2; i++)
        {
            array[i] = array[i+1];
        }
        numElements = numElements - 1;
    }
    else
    {
        cout << "Sorry! Not enough items in the message board!" << endl;
    }
    
}

int main(int argc, char* argv[])
{
    const int SIZE = 100;

    //Reading file name from the terminal command line
    string fileName = argv[1];

    Item itemArray[SIZE]; //initializing the array of Items

    for(int i = 0; i < SIZE; i++) //filling the array with None's and 0's
    {
        itemArray[i].type = "None.";
        itemArray[i].desire = 0;
        itemArray[i].price = 0;
    }

    //Reading the File:
    ifstream in(fileName);
    if (!in)
    {
    	cout << "File can't be opened! " << endl;
    	exit(1);
    }

    cout << "\nItems Sold:";

    string typeFromFile;
    string desireFromFile;
    int booleanDesire;
    int priceFromFile;
    int itemsSold = 0;
    int indexCount = 0;

    while (getline(in, typeFromFile, ','))
    //for (int i = 0; i < SIZE; i++)
    {
        //inputing from file
        //getline(in, typeFromFile, ',');
        getline(in, desireFromFile, ',');
            if(desireFromFile.compare(" for sale") == 0) //"for sale" => 0
                booleanDesire = 0;
            if(desireFromFile.compare(" wanted") == 0) //"wanted" => 1
                booleanDesire = 1;
        in >> priceFromFile;

        bool found = false;

        //checking for matches in the array
        for (int j = 0; j < SIZE; j++) //looping 100 times through array
        {
            if(typeFromFile == itemArray[j].type) //if the current type matches anything from the array
            {
                if(booleanDesire == 0 && itemArray[j].desire == 1)  //if type from file is for sale(0) and another is wanted
                {
                    if(priceFromFile <= itemArray[j].price) //and the for sale item is less than or equal to what another is willing to pay
                    {
                        //this item is a match (same type, is for sale and someone is willing to pay for it)
                        deleteArrayElement(itemArray, j, SIZE); //delete the element from the array and shift to fill gap
                        cout << typeFromFile << " " << priceFromFile;
                        found = true;
                        itemsSold++;
                        break; //stop searching the array
                    }
                    else //otherwise, they are of same type, but prices do not line up so we add to array (below)
                    {
                        //this item is not a match so we add it to the next unused position in the array
                        found = false; //still
                    }
                }
                else if(booleanDesire == 1 && itemArray[j].desire == 0) //if item wanted(1) and another is for sale in array (still same type)
                {
                    if(priceFromFile >= itemArray[j].price) //and if the wanted item is willing to pay more than or same as list price
                    {
                        //this item is a match (same type, is wanted and someone is selling it for less)
                        cout << typeFromFile << " " << itemArray[j].price;
                        deleteArrayElement(itemArray, j, SIZE); //delete the for sale element from the array and shift to fill gap
                        found = true;
                        itemsSold++;
                        break; //stop searching the array
                    }
                    else //otherwise, they are of same type, but prices do not match up so we add to the itemArray
                    {
                        //this item is not a match so we add it to the next unused position in the array
                        found = false; //still
                    }
                }
            }
            else //if the type does not match with anything in the array so we add it to the first unused position
            {
                found = false; //still
            }
        }

        if(found == false) //if there are no matches, fill first open space
        {
            while (indexCount < SIZE && (itemArray[indexCount].type.compare("None.") != 0)) //counting occupied spaces
            {
                indexCount++;
            }
            itemArray[indexCount].type = typeFromFile; //adding the unmatched item to the next available position
            itemArray[indexCount].desire = booleanDesire;
            itemArray[indexCount].price = priceFromFile;
        }
    }

    cout << "\n" << "\nItems remaining in the message board after reading all lines in the file: " << endl;
    for (int i = 0; i < indexCount; i++) 
    {
        if(itemArray[i].type.compare("None.") != 0)
        {
            cout << itemArray[i].type << ", ";
            if(itemArray[i].desire == 0) //"for sale" => 0
                cout << "for sale, ";
            if(itemArray[i].desire == 1) //"wanted" => 1
                cout << "wanted, ";
            cout << itemArray[i].price;
        }
    } 
    cout << "\n";
} 


