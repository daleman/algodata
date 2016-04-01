#ifndef _linked_list_H
#define _linked_list_H
#include <iostream>
using namespace std;

#define nullptr 0

struct node{
	int data;
	node* next_node;
};

class linked_list{

public:

	linked_list();
	~linked_list();
	void insert_value(int data);
	void delete_value(int data);
	node* find(int value);
	bool is_empty();
	bool is_final_node(node* node);
	void print_list();

private:
	node* first_node;
};




#endif

