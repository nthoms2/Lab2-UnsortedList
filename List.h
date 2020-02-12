#ifndef List_H
#define List_H

#include<string>
using namespace std;

typedef int itemType; //Creates a specified type that will be used for the item being stored.
enum relation{LESS, GREATER, EQUAL,NONE};

// Creates the node for the linked list.
struct node
{
	itemType item;
	node* next;
};

//Class is created.
class List
{
public:
	//constuctor
	//precondition: None.
	//Postcondtion: Class is created.
	List();

	//deconstuctor
	//precondition: Class Is created.
	//Postcondtion: Class is destroyed.
	~List();

	//This function takes in an item and stores it in to the list and
	//then moves head to the front.
	//precondition: Item is given and list is not full.
	//Postcondtion: Item is located in list and head points at front of list.
	void insertItem(itemType item_);

	//Checks to see if the list holds the max amount of nodes.
	//precondition: maxLength is initialized and length is initialized.
	//Postcondtion: Bool is returned, determining full or not full.
	bool IsFull();

	//Gives value for length of list.
	//precondition: Length is initialized.
	//Postcondtion: Length is returned.
	int getLength() { return length; };

	//Empties list.
	//precondition: Class Is created.
	//Postcondtion: In components within the list are deleted.
	void makeEmpty();

	//Searches fro inputted item.
	//precondition: item is given
	//Postcondtion: Either position of the item or nullptr is returned.
	node* search(itemType item_);

	//Gets rid of item in list.
	//precondition: Item is inputted.
	//Postcondtion: Item is succesfully deleted and the list hooks back up together smoothly.
	void deleteItem(itemType item_);

	//Puts position at the location of head.
	//precondition: Head has a location.
	//Postcondtion: Head == Position.
	void resetList() { position = head; }

	//Compares two items within the list
	//precondition: Two items are given and they both need to be in the list.
	//Postcondtion: If both items are in the list, an enum that represents the comparison
	//is returned.
	relation comparedTo(itemType item1, itemType item2);

	//Changes position of position and returns the vaule in position->item.
	//precondition: Position is not null.
	//Postcondtion: Next item in the list is grabbed by position and the item vaule is
	//returned.
	itemType getNextItem();
	
	//Combines the contents of two lists.
	//precondition: Both class arguments exist and are excepted.
	//Postcondtion: Componets of each list are merged and the duplicates are not trasfered.
	bool setUnion(List List1_, List List2_);

private:
	node* head; //Points at the front of the list.
	node* position; //Points at current position in list.
	int length; //Length of the list.
	int maxItems; //Max number of items list can hold.

};

#endif