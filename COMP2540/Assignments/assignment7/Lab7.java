/*
Lab 7
COMP-2540
By: Lucas Sarweh
ID: 110042658 
*/

import java.util.Random;

public class Lab7 {
    /**
     * Heapify for a max heap
     * @param A The array representing a heap
     * @param i starting index
     * @param j end index
     * @return Number of comparisons
     */
    public static int heapify(int A[], int i, int j){
        // Hold numb of comparisons
        int comp = 0;
        // Holds index of largest child
        int k = 0;

        if((2 * i + 2) <= j){ // A[i] has two children
            // Set to index of larger value
            k = A[2 * i + 1] <= A[2 * i + 2] ? 2 * i + 2: 2 * i + 1;
        }else if(2 * i + 1 <= j){ // Theres only one child
            // Set to index of only child (Which is the largest)
            k = 2 * i + 1;
        }else{ // There are no children
            return 0;
        }

        if(A[i] < A[k]){
            // Exchange the two values
            int temp = A[i];
            A[i] = A[k];
            A[k] = temp;
        }
        ++comp;
        // recursion
        comp += heapify(A, k, j);
        return comp;
    }

    /**
     * Builds a heap using heapify for a maxheap
     * @param A An array representing a heap
     * @return The number of comparisons
     */
    public static int buildHeap(int A[]){
        // Number of comparisons
        int comp = 0;
        for(int i = (A.length / 2) - 1; i >= 0; --i){
            comp += heapify(A, i, A.length - 1);
        }
        return comp;
    }

    /**
     * Heapsort sorts a heap in ascending order
     * @param A The array representing a heap
     * @return The number of comparisons
     */
    public static int heapSort(int A[]){
        // Track comparisons
        int comp = 0;
        for(int i = A.length - 1; i >= 1; --i){
            // Exchange A[0], A[i]
            int temp = A[0];
            A[0] = A[i];
            A[i] = temp;
            comp += heapify(A, 0, i - 1);
        }
        return comp;
    }

    public static void main(String[] args){
        // Test array for part A
        int A[] = {4, 2, 1, 8, 6, 5, 10, 9, 11, 16};
        // Print number of comparisons and call heapify
        System.out.println("Number of comparisons: " + heapify(A, 0, 9));
        // Print heap
        System.out.print("A: ");
        for(int i : A){
            System.out.print(i + " ");
        }
        System.out.println("\n");

        // Test array for part B
        int B[] = {12, 10, 15, 19, 8, 7, 20};
        // Print number of comparisons and call buldHeap
        System.out.println("Number of comparisons: " + buildHeap(B));
        // Print heap
        System.out.print("B: ");
        for(int i : B){
            System.out.print(i + " ");
        }
        System.out.println("\n");

        // Test array for part C
        int C[] = new int[100];
        // Random number generator
        Random gen = new Random();
        // Populate array
        for(int i = 0; i < C.length; ++i){
            // Random number between 1 and 500
            C[i] = gen.nextInt(500) + 1;
        }
        // Print number of comparisons and call heapSort
        System.out.println("Number of comparisons: " + heapSort(C));
        // Print heap
        System.out.print("C: ");
        for(int i : C){
            System.out.print(i + " ");
        }
        System.out.println("\n");
    }
}