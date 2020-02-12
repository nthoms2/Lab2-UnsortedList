//Nolan Thoms
//Data Structures Spring 2020
//Due: 2/11/2020
//Lab 2: Unsorted Lists

#include <iostream>
#include "List.h"
using namespace std;



int main()
{
	//First list is created.
	List list1;
	//second class is created.
	List list2;
	//third class is created.
	List list3;
	
	list1.insertItem(1); //Items are being inserted.
	list1.insertItem(2);
	list1.insertItem(3);

	cout << list1.comparedTo(2, 3) << endl; //Relation is outputed.

	for (int i = 0; i < list1.getLength(); i++)
	{
		cout << list1.getNextItem() << endl; //Members in the list are displayed.
	}
	list1.makeEmpty();//List is emptied.

	list1.insertItem(1);//More items are added.
	list1.insertItem(2);

	for (int i = 0; i < list1.getLength(); i++)
	{
		cout << list1.getNextItem() << endl;
	}
	
	cout << list1.search(1) << endl;//Outputs pointer location of found item.

	list1.deleteItem(1);//Item is deleted.

	list1.resetList();
	for (int i = 0; i < list1.getLength(); i++)
	{
		cout << list1.getNextItem() << endl;
	}
	
	list2.insertItem(1); //Item is inserted into second list.

	list3.setUnion( list1, list2);//Lists are combined.

	for (int i = 0; i < list3.getLength(); i++)//Displays new list.
	{
		cout << list3.getNextItem() << endl;
	}

	return 0;
}
