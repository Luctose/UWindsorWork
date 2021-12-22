/*
Lab 10 (Java Collections FrameWork)
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Wed Dec 08 2021
*/

import java.util.ArrayList;

/**
 * Utility class provides static methods to manipulate ArratList's
 */
public final class ArrayListUtil
{
    // Static methods only

    /**
     * Reverse an ArrayList of Integer
     * @param list The ArrayList to be reversed
     */
    public static void reverseArray(ArrayList<Integer> list){
        // Keep track of GenericArrayType being swapped
        Integer num;
        // Loop through list
        for(int i = 0; i < list.size() / 2; i++){
            // Store current element
            num = list.get(i);
            // Set current element to its reflection
            list.set(i, list.get(list.size() - i - 1));
            // Set its reflection to element we stored
            list.set(list.size() - i - 1, num);
        }
    }

    /**
     * Give a copy of an ArrayList reversed
     * @param list List to reverse
     * @return Copy of reversed list
     */
    public static ArrayList<Integer> GiveReverseArray(ArrayList<Integer> list){
        // Declare the reverse copy
        ArrayList<Integer> revList = new ArrayList<Integer>();
        // Loop through each element of the list in reverse
        for(int i = list.size() - 1; i >= 0; i--){
            // Add the items
            revList.add(list.get(i));
        }
        // Return reversed list copy
        return revList;
    }
}