#include <iostream>
#include "linkedList.h"
using namespace std;


linked_list::linked_list(){
	first_node = nullptr;
}

linked_list::~linked_list(){

	node* temporal_node = nullptr;	
	node* current_node = nullptr;	
	
	if (first_node != nullptr){
		node* current_node = first_node;
	}
	while(current_node != nullptr){
		node* temporal_node = current_node->next_node;
		delete current_node;
		current_node = temporal_node;
	}
}


void linked_list::insert_value(int value){
	
	
	// create the node with the value
	node* new_node = new node;
	new_node->data= value;
	
	// always my new_node is the first one and points to the old first
	
		node* old_first_node = this->first_node;
		new_node->next_node = old_first_node;		
		this->first_node = new_node;		
	
}


bool linked_list::is_empty(){
	
	bool is_empty = (first_node == nullptr) ? true : false;
		return is_empty;
}

bool linked_list::is_final_node(node* node){
	
	if(node == nullptr){ 
		return true;
	}else{
	return false;
	}
}


void linked_list::delete_value(int data){

	if(is_empty()){
		return;
	}

	while (first_node->data == data){
		node* old_next_node = first_node->next_node;
		delete first_node;
		first_node = old_next_node;
		if (first_node == nullptr){
			return;
		}
			
	}
	// deletes all nodes with value

	node* current_node = first_node->next_node;
	node* prev_node = first_node;
	while (!is_final_node(current_node)){
		
		if (current_node->data == data){
			node* next_node = current_node->next_node;
			delete current_node;
			prev_node->next_node = next_node;
			current_node = current_node->next_node;
		}else{
			prev_node = prev_node->next_node;
			current_node = current_node->next_node;
		}
	}

}

void linked_list::print_list(){

	if(is_empty()){
		cout << "[ ]" << endl;
	}else{

	node* current_node = first_node;

	while(current_node != nullptr){
		cout << "[ addr: " << current_node 
			 << " | value: " << current_node->data 
			 << " | next: " << current_node->next_node 
			 << " ]-->";
		current_node = current_node->next_node;
	}
	cout << "NULL" << endl;
	}
}

node* linked_list::find(int value){
	if(is_empty()){
		return nullptr;
	}
	
	node* current_node = first_node;
	
	while(!is_final_node(current_node)){
		if(current_node->data == value){
			return current_node;
		}
		current_node = current_node->next_node;
	}
	
	return nullptr;
		

}





























