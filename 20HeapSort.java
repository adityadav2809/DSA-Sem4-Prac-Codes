/*Implement the Heap sort algorithm implemented in Java demonstrating heap data 
structure with modularity of programming language*/

public class HeapSort {

    // Method to perform Heap Sort
    public void sort(int arr[]) {
        int n = arr.length;  

        // Build max heap
        for(int i = n/2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // Extract elements from the heap one by one
        for(int i = n - 1; i > 0; i--) {
            // Move current root to end
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            // Call heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }

    // Method to heapify a subtree rooted at index i
    void heapify(int arr[], int n, int i) {
        int largest = i;    // Initialize largest as root
        int left = 2 * i + 1;    // Left child
        int right = 2 * i + 2;    // Right child
        
        // If left child is larger than root
        if(left < n && arr[largest] < arr[left]) {
            largest = left;
        }
        
        // If right child is larger than largest so far
        if(right < n && arr[largest] < arr[right]) {
            largest = right;
        }
        
        // If largest is not root
        if(largest != i) {
            int temp = arr[largest];
            arr[largest] = arr[i];
            arr[i] = temp;
            
            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }
    
    // Main method to test HeapSort
    public static void main(String args[]) {
        int arr[] = {12, 11, 13, 5, 6, 7};
        int n = arr.length;
        
        // Create an instance of HeapSort class
        HeapSort obj = new HeapSort();
        
        // Call sort method
        obj.sort(arr);
        
        // Print the sorted array
        System.out.print("Sorted Array : ");
        for(int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}

/*Here's the algorithm for the Heap sort algorithm implemented in Java:

1. **Define a HeapSort class**:
   - Define a public class named `HeapSort`.

2. **Define a sort method**:
   - Create a method named `sort` that takes an integer array `arr[]` as input.
   - Initialize `n` as the length of the array.
   - Build a max heap by calling the `heapify` method starting from the last non-leaf node down to the root.
   - Extract elements from the heap one by one by swapping the root with the last element of the heap and reducing the size of the heap.
   - After each extraction, call `heapify` on the remaining heap to maintain the heap property.

3. **Define a heapify method**:
   - Create a method named `heapify` that takes an integer array `arr[]`, an integer `n` representing the size of the heap, and an integer `i` representing the index of the current node.
   - Initialize `largest` as the current node.
   - Calculate the indices of the left and right children of the current node.
   - Compare the values of the current node with its left and right children, and update `largest` if necessary.
   - If `largest` is not equal to `i`, swap the values at indices `largest` and `i`, and recursively call `heapify` on the subtree rooted at `largest`.

4. **Define the main method**:
   - Create a `main` method.
   - Declare an integer array `arr[]` with initial values.
   - Get the length of the array.
   - Create an instance of the `HeapSort` class.
   - Call the `sort` method on the array.
   - Print the sorted array.

5. **End**.

This algorithm demonstrates the Heap sort algorithm in Java, utilizing a max heap data structure for sorting.*/
