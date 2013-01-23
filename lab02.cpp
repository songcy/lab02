#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Item
{
private:
  string name_;
  int qty_;
  double price_;
public:
  Item();
  Item(string name, int qty, double price);
  string getName() const;
  int getQty() const;
  double getPrice() const;
  void setName(string name);
  void setQty(int qty);
  void setPrice(double price);
};

Item::Item() 
{
  name_ = ""; qty_ = -1; price_ = -1; 
}

// Complete the Item class methods here
Item::Item(string name, int qty, double price)
{
  name_ = name;
	qty_ = qty;
	price_ = price;
}

string Item::getName() const
{
	return name_;
}

int Item::getQty() const
{
	return qty_;
}

double Item::getPrice() const
{
	return price_;
}

void Item::setName(string name)
{
	name_ = name;
}

void Item::setQty(int qty)
{
	qty_ = qty;
}

void Item::setPrice(double price)
{
	price_ = price;
}

// Prototypes
void printItems(const Item *items, const int len);
Item *readData(const char *filename, int &len);

// Accepts a data filename as a command line arguments
int main(int argc, char *argv[])
{
  if(argc < 2){
    cerr << "Please supply an input filename as a command line argument" << endl;
    return 1;
  }
  int len;
  Item *dataArray = readData(argv[1], len); 
  if(dataArray == NULL){
    cout << "Unable to open file: " << argv[1] << endl;
    return 1;	
  }
  cout << "Read " << len << " Items from the file: " << argv[1] << endl;
  printItems(dataArray, len);

  // Add a statement to deallocate the dataArray memory
  delete [] dataArray;
  return 0;
}

// Print Item information in a tabular format
void printItems(const Item *items, int len)
{
    cout << setw(15) << "Name";
    cout << setw(10) << "Qty";
    cout << setw(10) << "Price" << endl;
    
    for (int n = 0; n < len; n++)
    {
        cout << setw(15) << items[n].getName();
        cout << setw(10) << items[n].getQty();
        cout << setw(10) << setprecision(2) << items[n].getPrice() << endl;
    }
}


// Read Items from a datafile and store them in an array 
//  Return the address of the array and update the len
//  argument.
Item *readData(const char *filename, int &len)
{
  	string tname;
	int tqty;
	double tprice;
    
	ifstream myfile (filename);

    
    if (myfile.is_open())
    {
		myfile >> len;
        Item *itemArray = new Item[len];
        
        
            for (int i =0; i < len; i++)
            {
                myfile >> tname;
				itemArray[i].setName(tname);
                myfile >> tqty;
				itemArray[i].setQty(tqty);
                myfile >> tprice;
				itemArray[i].setPrice(tprice);
            }
	
        myfile.close();
        return itemArray;
    }
    else
        return NULL;
    
}
