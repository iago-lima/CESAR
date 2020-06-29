#include <iostream>
#include <string>
#include <bits/stdc++.h> 


using namespace std;

struct Node{
	string message;
	struct Node* next;
};

void addNode(struct Node** hRef, string data){
	struct Node* newNode = new Node;

	newNode->message = data;
    newNode->next = (*hRef);
	*hRef = newNode;
}

void printList(struct Node *list){
	while(list != NULL){
		cout <<  list->message << "-> ";
		list = list->next;
	}
	cout << "NULL" << endl;
}

void deleteDuplicate(struct Node *list){
	unordered_set <string> aux;
	struct Node *current = list;
	struct Node *previous = NULL;

	while(current != NULL){
		string messageAux = current->message;
        
		if (aux.find(messageAux) == aux.end()){
		    aux.insert(messageAux);
			previous = current;
			
		}else{
		    previous->next = current->next;
		}
		current = current->next;
	}

}

int main(int argc, char const *argv[])
{
	struct Node* head = NULL;

	addNode(&head, "M1");
	addNode(&head, "M2");
	addNode(&head, "M3");
	addNode(&head, "M2");
	addNode(&head, "M4");
	addNode(&head, "M2");
	
	cout << "Lista antes da remoção" << endl << endl;
	printList(head);
	cout << "Lista antes da remoção" << endl << endl;
	deleteDuplicate(head);
	printList(head);
	
	return 0;
}