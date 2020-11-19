//	Created by: Ze Lei and Jimmy Nguyen CSC340
#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& vec) {
    cout << "[Numbers in brackets] are unsorted" << endl;
    size_t n = vec.size();

    // One by one move boundary of unsorted subvec
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted vec
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (vec[j] < vec[min]) {
                min = j;
            }
        }

        // Swap the found minimum element with the first
        // element
        int temp = vec[min];
        vec[min] = vec[i];
        vec[i] = temp;

        cout << "Step " << (i + 1) << endl;
        for (int k = 0; k < vec.size(); k++) {
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
    cout << "[Numbers in brackets] are sorted" << endl;
    size_t n = vec.size();
    for (int i = 1; i < n; i++) {
        int key = vec[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = key;

        //print steps
        cout << "Step " << (i) << endl;
        cout << "[";
        for (int k = 0; k < vec.size(); k++) {
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
    cout << "Numbers with dots. have been switched" << endl;
    size_t n = vec.size();
    int l = 1;

    // Start with a big gap, then reduce the gap 
    for (int gap = n / 2; gap > 1; gap /= 2) {
        // Do a gapped insertion sort for this gap size. 
        // The first gap elements a[0..gap-1] are already 
        // in gapped order keep adding one more element 
        // until the entire vec is gap sorted 
        for (int i = gap; i < n; i++) {
            // store value 
            int temp = vec[i];

            // shift earlier gap-sorted elements up until 
            // the correct location for temp is found 
            int j;
            for (j = i; j >= gap && vec[j - gap] > temp; j -= gap) {
                vec[j] = vec[j - gap];
            }

            // put in correct location
            vec[j] = temp;

            cout << "Step " << l << endl;
            for (int k = 0; k < vec.size(); k++) {
                cout << vec[k];
                if (k == j) {
                    cout << ".";
                }
                if (k == i && j != i) {
                    cout << ".";
                }
                cout << " ";
            }
            cout << "\n";
            l++;
        }
    }
    cout << "---\nInsertion Portion" << endl;
    insertionSort(vec);
}

// Prints the vec
void printvec(vector<int>& vec) {
    size_t n = vec.size();
    for (std::vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
        std::cout << *i << ' ';
    }
    cout << "\n";
}

int main()
{
    vector<int> data = { 1, 8, 4, 0, 1, 1, 7, 6, 4, 6, 1, 7 };
    vector<int> copy1 = data;
    vector<int> copy2 = data;
    cout << "Selection Sort\n---" << endl;
    cout << "Unsorted vector:" << endl;
    printvec(data);
    selectionSort(data);
    cout << "Sorted vector" << endl;
    printvec(data);
    cout << "---\nInsertion Sort\n---" << endl;
    cout << "Unsorted vector:" << endl;
    printvec(copy1);
    insertionSort(copy1);
    cout << "Sorted vector" << endl;
    printvec(copy1);
    cout << "---\nShell Sort\n---" << endl;
    cout << "Unsorted vector:" << endl;
    printvec(copy2);
    shellSort(copy2);
    cout << "Sorted vector" << endl;
    printvec(copy2);
}
