/*
Lab 5
COMP-2540
By: Lucas Sarweh
ID: 110042658 
*/

import java.util.Random;
import java.awt.Color;
import java.io.IOException;

/**
 * Lab assignment 5 from the University of Windsor
 * COMP-2540 class, 03/20/2022
 */
public class Lab5 {
    /**
     * This method performs insertion sort on an integer array
     * @param myarr Integer array to sort
     * @return The number of comparisons
     */
    public static int insertionSort(int myarr[]){
        // Track number of comparisons
        int comp = 0;
        // This assumes that the very first element will stay there,
        // Other elements will be insterted around it
        for(int i = 1; i < myarr.length; ++i){
            // The current value we are trying to sort is myarr[i]
            // We must use a temp variable because when shifting elements it
            // will get overwritten
            int curVal = myarr[i];
            // This will contain the index that we insert next to
            int j;
            // We must check all previous elements with the j index to insert it
            for(j = i - 1; j >= 0 && myarr[j] > curVal; --j){
                ++comp;
                // We must swap the elements
                int temp = myarr[j];
                myarr[j] = myarr[j + 1];
                myarr[j + 1] = temp;
            }

        }
        return comp;
    }

    /**
     * This method performs merge sort on an integer array
     * @param myarr The array to be sorted
     * @return The number of comparisons
     */
    public static int mergeSort(int myarr[]){
        int comp = 0;
        // Make sure it is able to be split
        if(myarr.length > 1){
            // Middle
            int middle = myarr.length / 2;
            // First partition
            int arr1[] = new int[middle];
            // Populate first half
            int i;
            for(i = 0; i < middle; ++i){
                arr1[i] = myarr[i];
            }
            // Second partition
            int arr2[] = new int[myarr.length - middle];
            // Populate second half
            for(int m = 0; i < myarr.length; ++i, ++m){
                arr2[m] = myarr[i];
            }
            // Recursion
            comp += mergeSort(arr1);
            comp += mergeSort(arr2);
            // Merge
            comp += merge(myarr, arr1, arr2);
        }
        // Do nothing array has one element
        return comp;
    }
    
    /**
     * Helper function used in mergeSort to merge two partitions
     * in sorted order
     * @param myarr Array partitions are written to
     * @param arr1 First partition
     * @param arr2 Second partition
     * @return The number of comparisons
     */
    private static int merge(int myarr[], int arr1[], int arr2[]){
        int comp = 0;
        // Size of partitions
        int n1 = arr1.length;
        int n2 = arr2.length;
        // Indicies
        int i = 0, j = 0, k = 0;
        // Compare while both have elements left
        while(i < n1 && j < n2){
            ++comp;
            // Arr1 contains the next element
            if(arr1[i] < arr2[j]){
                myarr[k] = arr1[i]; ++i;
            }else{ // Arr2 contains the next element
                myarr[k] = arr2[j]; ++j;
            }
            // Increment main array
            ++k;
        }
        // One runs out just add the non-empty one now
        // Arr1 not empty
        for(int m = i; m < n1; ++m){
            ++comp;
            myarr[k] = arr1[m]; ++k;
        }
        // Arr2 not empty
        for(int m = j; m < n2; ++m){
            ++comp;
            myarr[k] = arr2[m]; ++k;
        }
        return comp;
    }

    public static String stringIt(int array[]){
        String myString = "[ ";

        for(int item : array){
            myString = myString + item + " ";
        }
        myString += "]";
        return myString;
    }

    // Execution starts here
    public static void main(String[] args) throws IOException{
        // Make Random object
        Random myR = new Random();
        // Number of comparisons
        int c1 = 0;
        int c2 = 0;
        // Test for different sizes of n
        // In intervals of 500 starting at 500
        for(int n = 500; n <= 10000; n += 500){
            // New array of size n
            int I[] = new int[n];
            // Fill the array with random integers
            for(int i = 0; i < I.length; ++i){
                I[i] = myR.nextInt();
            }
            // Make a copy of the array
            int M[] = new int[I.length];
            for(int i = 0; i < M.length; ++i){
                M[i] = I[i];
            }
            // Call sorts and get # of comparisons
            c1 = insertionSort(I);
            c2 = mergeSort(M);
            // Print comparisons result of n value
            System.out.println("For N = " + n + ":\n" +
                                "Insertion sort comparisons: " + c1 + "\n" +
                                "Merge sort comparisons: " + c2 + "\n");
        }
        int compinsert[] = new int[10000];
        compinsert[0] = 0;
        int compmerge[] = new int[10000];
        compmerge[0] = 0;

        // Loop through 1 - 10000, this takes a minute (literally)
        for(int n = 1; n < 10000; ++n){
            int arrr[] = new int[n];
            for(int i = 0; i < arrr.length; ++i){
                arrr[i] = myR.nextInt();
            }
            int arrg[] = new int[n];
            for(int i = 0; i < arrg.length; ++i){
                arrg[i] = arrr[i];
            }
            compinsert[n] = insertionSort(arrr);
            compmerge[n] = mergeSort(arrg);
        }

        Plot.Data insert = Plot.data();
        Plot.Data merge = Plot.data();
        Plot.Data quad = Plot.data();
        Plot.Data nlogn = Plot.data();

        for(int x = 1; x < 10000; x++){
            insert.xy(x, compinsert[x]);
            merge.xy(x, compmerge[x]);
            quad.xy(x, x*x);
            nlogn.xy(x, x * (Math.log10(x) / Math.log10(2)));
        }

        Plot plot = Plot.plot(Plot.plotOpts().
                title("Lab 5 Question 4").
                legend(Plot.LegendFormat.BOTTOM)).
                    xAxis("x", Plot.axisOpts().range(1, 10000)).
                    yAxis("y", Plot.axisOpts().range(1, 30000000)).

                series("insertionsort", insert, Plot.seriesOpts().color(Color.BLACK)).
                series("mergesort", merge, Plot.seriesOpts().color(Color.BLUE).lineWidth(5)).
                series("y=x^2", quad, Plot.seriesOpts().color(Color.RED)).
                series("y=nlogn", nlogn, Plot.seriesOpts().color(Color.GREEN));

        plot.save("plot", "png");
    }
}
