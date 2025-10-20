/*
comenzamos con el nodo mas bajo que tiene algun hijo (index = length/2 -1   )

si el hijo mayor de ese nodo es mayor que el nodo padre, se intercambian con el swap entre esos fos nodos

si al hacer el swap alguno de los subarboeles deja de ser heap entonces en este momento se hace un swap en el sudarbol para convertirse en heap y asi sucesivavamente hasta que ya sea hape o se llegue a un subarbol vacio

asi se va haciendo con todos los nodos (index, index -1, index -2, ... 0)

12,60,72,70,56,32, 62, 92, 45, 30, 65 */ 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(const vector<int>& a) {
	for (size_t i = 0; i < a.size(); ++i) {
		if (i) cout << ", ";
		cout << a[i];
	}
	cout << '\n';
}


void heapify(vector<int>& a, int n, int i) {
	int largest = i; 
	int l = 2*i + 1; 
	int r = 2*i + 2; 

	if (l < n && a[l] > a[largest]) largest = l;
	if (r < n && a[r] > a[largest]) largest = r;

	if (largest != i) {
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}

int main() {
	vector<int> a = {12,60,72,70,56,32,62,92,45,30,65};

	cout << "Array inicial:\n";
	printArray(a);

	int n = (int)a.size();

	
	for (int i = n/2 - 1; i >= 0; --i) {
		cout << "\nHeapify en índice " << i << " (valor=" << a[i] << "):\n";
		heapify(a, n, i);
		printArray(a);
	}

	cout << "\nHeap final (max-heap):\n";
	printArray(a);

	return 0;
}
