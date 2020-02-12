#include <iostream>
#include "List.h"
using namespace std;

//Atributes are initialized.
List::List()
{
	length = 0;
	head = nullptr;
	position = nullptr;
	maxItems = 100000000;
}

//Everyting in the list is deleted.
List::~List()
{
	makeEmpty();
}


void List::insertItem(itemType item_)
{
	//creates a pointer that will point at the node
	node* location;

	//checks to see if the list if full before inserting item.
	if (IsFull() == false)
	{
	 location = new node; //Allocates space and creates node.
	 location->item = item_; //Stores item in the node.
	 location->next = head; //Stores adress of the first node in next of the new node
	 head = location; //Store addres of the newly created node to head.
	 length++; //Length is increased.
	}
}

bool List::IsFull() 
{
	if (length == maxItems) //Checks to see if max is reached.
	{
		return true;
	}
	return false;
}

void List::makeEmpty()
{
	node* pointer;

	//Loop that runs through all items in a list and deletes them.
	while (head != NULL) //Goes untill head is pointing a nothing.
	{
		pointer = head; //Pointer points at first node.
		head = head->next; //Head moves to next node.
		delete pointer; //The node that pointer is pointing at is deleted.
	}
	length = 0; //Length set to zero.
	resetList();//Position is set to head.
}

node* List::search(itemType item_)
{
	if (head == nullptr) //If nothing is in the list, NULL is returned.
	{
		return nullptr;
	}
	else
	{
		node* pointer = head; //This is a helper pointer.
		bool found = false; //This is a helper bool.
		
		for (int i = 0; i < getLength(); i++)//Goes though all componets of loop.
		{
			if (pointer->item == item_) //If the item is found true is returned.
			{                           //and function is exited.
				found = true;
				break;
			}
			pointer = pointer->next; //If item is not found pointer points to next node.
		}
		if (found)
		{
			return pointer; //Pointer vaule is returned if it is found.
		}
		else
			return nullptr; //Otherwise nullptr is returned.
	}
}

void List::deleteItem(itemType item_)
{
	node* pointer1 = head; //Points before item being deleted.
	node* pointer2 = head->next; //Points at item being deleted.

	if (search(item_) != nullptr)//Checks to see if item is in list.
	{
		if(head->item == item_) //If the item located is in the head it is deleted 
		{                       //and head is moved to the next item in the list.
			head = head->next;
			delete pointer1;
		}
		else //For everything else besides head.
		{
			while (pointer2->item != item_)//Goes untill item is found.
			{                              //(moves both pointers through list)
				pointer1 = pointer1->next;
				pointer2 = pointer2->next;
			}

			pointer1->next = pointer2->next;//Before pointer points after thing being deleted.
			delete pointer2; //Item is deleted.
		}
		length--; //length of list is decreased.
	}
	else
	{
		cout << "\nThat item does not exist" << endl;
	}
}

relation List::comparedTo(itemType item1, itemType item2)
{
	relation relation_;//Holds one of the enum values.

	if (search(item1) != nullptr && search(item2) != nullptr)//Check to see if
	{                                                        //both items are in list.
		if (item1 == item2) //Returns EQUAL.
		{
			relation_ = EQUAL;
			return relation_ ;
		}
		else if (item1 < item2) //Returns LESS.
		{
			relation_ = LESS;
			return relation_;
		}
		else if (item1 > item2)//Returns GREATER.
		{
			relation_ = GREATER;
			return relation_;
		}
	}
	return NONE; //Returns NONE.
}

itemType List::getNextItem()
{
	if (position == nullptr)//If position points at null, position is set to head and
	{                       //the value is returned.
		position = head;
		return position->item;
	}
	else
	{
		if (position->next == nullptr) //If position points at null, position is set to head and                  //the value is returned.
		{                              //the value is returned.
			position = head;
			return position->item;
		}
		else //Position is moved to the next spot in the list and the vaule is returned.
		{
			position = position->next;
			return position->item;
		}
		
	}
}

bool List::setUnion(List List1_, List List2_)
{
	//makes sure nothing is in the new list that will be used for combining.
	if (head != nullptr)
	{
		return false;
	}
	else
	{
		List1_.resetList();
		List2_.resetList();
		while (List1_.position != nullptr)
		{
			if (search(List1_.position->item) != nullptr) //item is found (not added to new list)
			{
				List1_.position = List1_.position->next; //Moves on to next item
			}
			else //If there is a new item it is added to the list.
			{
				insertItem(List1_.position->item);
				List1_.position = List1_.position->next;
			}
		}
		while (List2_.position != nullptr) // Does same thing but with seconed input.
		{
			if (search(List2_.position->item) != nullptr) //item is found (not added to new list)
			{
				List2_.position = List2_.position->next;
			}
			else
			{
				insertItem(List2_.position->item);
				List2_.position = List2_.position->next;
			}
		}
		List1_.resetList(); //Resets positions of the component lists.
		List2_.resetList();
		return true;
	}
}
