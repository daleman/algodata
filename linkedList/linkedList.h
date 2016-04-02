#ifndef _linked_list_H
#define _linked_list_H
#define nullptr 0

template <class T>
struct node{
	T data;
	node<T>* next_node;
};

template <class T>
class linked_list{

public:

	linked_list<T>();
	~linked_list<T>();
	void insert_value(T const &data);
	void delete_value(T const &data);
	node<T>* find(T const &data);
	bool is_empty();
	bool is_final_node(node<T>* node);
	void print_list();

private:
	node<T>* first_node;
	node<T>* last_node;
};


#include <iostream>
using namespace std;

template <class T>
linked_list<T>::linked_list(){
	first_node = nullptr;
	last_node = nullptr;
}

template <class T>
linked_list<T>::~linked_list(){

	node<T>* temporal_node = nullptr;	
	node<T>* current_node = nullptr;	
	
	if (first_node != nullptr){
		node<T>* current_node = first_node;
	}
	while(current_node != nullptr){
		node<T>* temporal_node = current_node->next_node;
		delete current_node;
		current_node = temporal_node;
	}
}

template <class T>
void linked_list<T>::insert_value(T const &value){
	
	
	// create the node with the value
	node<T>* new_node = new node<T>;
	new_node->data= value;
	
	// always my new_node is the first one and points to the old first
	
		node<T>* old_first_node = this->first_node;
		new_node->next_node = old_first_node;		
		this->first_node = new_node;
		
		if(is_final_node(first_node->next_node)){
			last_node = new_node;
		}		
	
}

template <class T>
bool linked_list<T>::is_empty(){
	
	bool is_empty = (first_node == nullptr) ? true : false;
		return is_empty;
}

template <class T>
bool linked_list<T>::is_final_node(node<T>* node){
	
	if(node == nullptr){ 
		return true;
	}else{
	return false;
	}
}

template <class T>
void linked_list<T>::delete_value(T const &data){

	if(is_empty()){
		return;
	}

	while (first_node->data == data){
		node<T>* old_next_node = first_node->next_node;
		delete first_node;
		first_node = old_next_node;
		if (first_node == nullptr){
			return;
		}
			
	}
	// deletes all nodes with value

	node<T>* current_node = first_node->next_node;
	node<T>* prev_node = first_node;
	while (!is_final_node(current_node)){
		
		if (current_node->data == data){
			node<T>* next_node = current_node->next_node;
			delete current_node;
			prev_node->next_node = next_node;
			current_node = current_node->next_node;
		}else{
			prev_node = prev_node->next_node;
			current_node = current_node->next_node;
		}
	}
	
	last_node = prev_node;

}

template <class T>
void linked_list<T>::print_list(){

	if(is_empty()){
		cout << "[ ]" << endl;
	}else{

	node<T>* current_node = first_node;

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

template <class T>
node<T>* linked_list<T>::find(T const &data){
	if(is_empty()){
		return nullptr;
	}
	
	node<T>* current_node = first_node;
	
	while(!is_final_node(current_node)){
		if(current_node->data == data){
			return current_node;
		}
		current_node = current_node->next_node;
	}
	
	return nullptr;
		

}









#endif

