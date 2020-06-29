#include <iostream>
#include <string>

using namespace std;

class Node{
	public:
	string value;
	int id;
	Node* next;
};

void addNode(Node** hRef, string data, int id){
    struct Node* newNode = new Node;

	newNode->value = data;
	newNode->id = id;
    newNode->next = (*hRef);
	(*hRef) = newNode;
}

void appendNode(Node** hRef, string data, int id){
	Node* newNode = new Node;
	
	Node *last = *hRef;

	newNode->value = data;
	newNode->id = id;
    newNode->next = NULL;
    
	if (*hRef == NULL)  
    {  
        *hRef = newNode; 
        return;
    }
    
    while (last->next != NULL){  
        last = last->next;
    }
    last->next = newNode;  

}

void printList(Node *list){
	while(list != NULL){
		cout <<  "label: " << list->value << " id: " << list->id << endl;
		list = list->next;
	}
	cout << "NULL" << endl;
}

int getLength(Node *list){
	 Node *listAux = list;
	int count = 0;

	while(listAux != NULL){
		count++;
		listAux = listAux->next;
	}
	return count;
}


string intersectionNode(int diffLength, Node *list1, Node *list2){
	int count = 0;
	Node *auxL1 = list1;
	Node *auxL2 = list2;

	while(count < diffLength){
		if(auxL1 == NULL){
			return "";
		}
		auxL1 = auxL1->next;
		count++;
	}

	while(auxL1 != NULL && auxL2 != NULL){
		if(auxL1->id == auxL2->id){
			return auxL1->value;
		}
		auxL1 = auxL1->next;
		auxL2 = auxL2->next;
	}
	return "";

}

string getNode(Node *list1, Node *list2){
	int lengthL1 = getLength(list1);
	int lengthL2 = getLength(list2);
	int diffLength = 0;

	if(lengthL1 > lengthL2){
		diffLength = lengthL1 - lengthL2;
		return intersectionNode(diffLength, list1, list2);
	}else{
		diffLength = lengthL2 - lengthL1;
		return intersectionNode(diffLength, list2, list1);
	}

}

int main(int argc, char const *argv[]){
	Node* list1 = NULL;

	addNode(&list1, "N1", 1);
	appendNode(&list1, "N2", 2);
	appendNode(&list1, "N3", 3);
	appendNode(&list1, "N4", 4);
	appendNode(&list1, "N5", 5);
	appendNode(&list1, "N6", 6);

	Node* list2 = NULL;

	addNode(&list2, "N7", 7);
    appendNode(&list2, "N3", 3);
	appendNode(&list2, "N4", 4);
	appendNode(&list2, "N5", 5);
	appendNode(&list2, "N6", 6);

	string node = getNode(list1,list2);

 	if (node.empty()){
 		cout << "A lista não contém interseção" << endl;
 	}else{
 		cout << "O nó de interseção da lista é: " << node << endl;
 	}
	
	
	return 0;
}