#include "linkedList.h"

int main(){

	linked_list list ;
	list.print_list();
	cout << "Inserto el 2 " << endl;
	list.insert_value(2);
	cout << "Inserto el 4 " << endl;
	list.insert_value(4);
	cout << "Inserto el 6 " << endl;
	list.insert_value(6);
	cout << "Inserto el 2 " << endl;
	list.insert_value(2);
	cout << "Inserto el 1 " << endl;

	list.insert_value(1);
	cout << "Inserto el 3 " << endl;
	list.insert_value(3);
	cout << "Inserto el 5 " << endl;
	list.insert_value(5);
	cout << "Inserto el 1 " << endl;
	list.insert_value(1);
	cout << "Imprimo " << endl;
	list.print_list();
	cout << "Borro los 2 " << endl;
	list.delete_value(2);
	cout << "Imprimo " << endl;
	list.print_list();
	cout << "Inserto el 1 " << endl;
	list.insert_value(1);
	cout << "Imprimo " << endl;
	list.print_list();
	cout << "Borro los 1 " << endl;
	list.delete_value(1);
	cout << "Imprimo " << endl;
	list.print_list();

	return 0;
}
