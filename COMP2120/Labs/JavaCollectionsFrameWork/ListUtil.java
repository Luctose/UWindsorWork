/*
Lab 10 (Java Collections FrameWork)
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Wed Dec 08 2021
*/

import java.util.LinkedList;
/**
 * This class supplies a utility method to reverse the entries in a linked list.
*/
public class ListUtil
{
    /**
    Reverses the elements in a linked list
    @param strings the linked list to reverse
    */
    public static void reverse(LinkedList<String> strings)
    {
        // Complete this static method based on its JavaDoc comment.
        // Keep track of string being swapped
        String str;
        // Loop through the list
        for(int i = 0; i < strings.size() / 2; i++){
            // Store current element
            str = strings.get(i);
            // Set current element to its reflection
            strings.set(i, strings.get(strings.size() - i - 1));
            // Set its reflection to element we stored
            strings.set(strings.size() - i - 1, str);
        }
    }
}