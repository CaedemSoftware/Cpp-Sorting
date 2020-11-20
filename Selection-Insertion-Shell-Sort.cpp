//	Created by: Ze Lei and Jimmy Nguyen CSC340
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& vec) {
	size_t n = vec.size();
	for (std::vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
		std::cout << *i << ' ';
	}
	cout << "\n";
}

void selectionSort(vector<int>& vec) {
	cout << "[Numbers in brackets] are unsorted" << endl;
	size_t n = vec.size();

	// move boundary of unsorted subvector
	for (size_t i = 0; i < n - 1; i++) {
		// find the minimum element in unsorted vector
		int min = i;
		for (size_t j = i + 1; j < n; j++) {
			if (vec[j] < vec[min]) {
				min = j;
			}
		}

		cout << "*** Iteration " << (i + 1) << " ***" << endl;
		cout << "smallest unsorted number: " << vec[min] << endl;
		// Swap the found minimum element with the first element of unsorted vector
		int temp = vec[min];
		vec[min] = vec[i];
		vec[i] = temp;
		//print vector
		for (size_t k = 0; k < vec.size(); k++) {
			cout << vec[k];
			cout << " ";
			if (k == i) {
				cout << "[";
			}
		}
		cout << "\b \b]" << endl;
	}
}

void insertionSort(vector<int>& vec) {
	cout << "[Numbers in brackets] are sorted\nNumbers greater than inserted number are moved one index higher" << endl;
	size_t n = vec.size();
	for (size_t i = 1; i < n; i++) {
		int insertee = vec[i];
		int j = i - 1;

		/* Move elements of vector[0..i-1], that are
		   greater than insertee, to one position ahead
		   of their current position */
		while (j >= 0 && vec[j] > insertee) {
			vec[j + 1] = vec[j];
			j = j - 1;
		}
		vec[j + 1] = insertee;

		cout << "*** Iteration " << i << " ***" << endl;
		cout << "Inserting: " << insertee << endl;
		cout << "[";
		//print vector
		for (size_t k = 0; k < vec.size(); k++) {
			cout << vec[k];
			if (k == i) {
				cout << "]";
			}
			cout << " ";
		}
		cout << "\n";
	}

}

void shellSort(vector<int>& vec) {
	cout << "Numbers with dots. are compared" << endl;
	size_t n = vec.size();
	int l = 1;

	// Start with the midpoint, then reduce the gap 
	for (int gap = n / 2; gap > 1; gap /= 2) {
	    cout << "*** gap is " << gap << " ***" << endl;
	    for (size_t i = gap; i < n; i++) {
			cout << "*** Iteration " << l << " ***" << endl;
	        int temp = vec[i];

	        // shift earlier gap-sorted elements up until 
	        // the correct location for temp is found 
	        int j;
	        for (j = i; j >= gap && vec[j - gap] > temp; j -= gap) {
	            cout << "swapping " << vec[j] << " and " << vec[j - gap] << endl;
	            vec[j] = vec[j - gap];
	        }
	        // put in correct location
	        vec[j] = temp;
	        

			//print vector
	        for (size_t k = 0; k < vec.size(); k++) {
	            cout << vec[k] << " ";
	            if (k == i - gap - gap) {
	                cout << "\u001B[32m\b.\u001B[0m";
	            }
	            if (k == i - gap) {
	                cout << "\u001B[32m\b.\u001B[0m";
	            }
	            if (k == i) {
	                cout << "\u001B[32m\b.\u001B[0m";
	            }
	            cout << " ";
	        }
	        cout << "\n";
	        l++;
	    }
	}
	cout << "---\nInsertion Portion" << endl;
	insertionSort(vec);
	//size_t n = vec.size();
	//for (int h = n / 2; h > 0; h = h / 2)
	//{
	//	cout << "gap is " << h << endl;
	//	for (size_t unsorted = h; unsorted < n; unsorted++)
	//	{
	//		int nextItem = vec[unsorted];
	//		int loc = unsorted;
	//		while ((loc >= h) && (vec[loc - h] > nextItem))
	//		{
	//			cout << "swapping " << vec[loc] << " and " << vec[loc - h] << endl;
	//			vec[loc] = vec[loc - h];
	//			loc = loc - h;
	//			printVector(vec);
	//		} // end while
	//		vec[loc] = nextItem;
	//	}  // end for
	//}  // end for
}

int main()
{
	cout << "* **********************************************" << endl
		<< "*** San Francisco State University" << endl
		<< "*** CSC 340 - Programming Methodology" << endl
		<< "*** Sorting Demonstration" << endl
		<< "* **********************************************" << endl;
	vector<int> data = { 1, 8, 4, 0, 1, 1, 7, 6, 4, 6, 1, 7 };
	vector<int> copy1 = data;
	vector<int> copy2 = data;
	cout << "---\nSelection Sort\n---" << endl;
	cout << "Unsorted vector:" << endl;
	printVector(data);
	selectionSort(data);
	cout << "Sorted vector:" << endl;
	printVector(data);
	cout << "---\nInsertion Sort\n---" << endl;
	cout << "Unsorted vector:" << endl;
	printVector(copy1);
	insertionSort(copy1);
	cout << "Sorted vector:" << endl;
	printVector(copy1);
	cout << "---\nShell Sort\n---" << endl;
	cout << "Unsorted vector:" << endl;
	printVector(copy2);
	shellSort(copy2);
	cout << "Sorted vector:" << endl;
	printVector(copy2);
}
