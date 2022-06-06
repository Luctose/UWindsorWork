/*
Lab 6
COMP-2540
By: Lucas Sarweh
ID: 110042658 
*/

import java.awt.Color;
import java.io.IOException;

public class Lab6 {
    /**
     * This traverses an array as if it were imitating a binary tree
     * and prints it's values using pre order
     * @param arr The array with stored values
     * @param index The index to start printing at
     */
    public static void preOrderPrint(int arr[], int index){
        // Make sure it's not empty
        if(arr.length == 0){
            return;
        }
        System.out.print(arr[index] + " ");

        if(2 * index + 1 < arr.length){
            
            preOrderPrint(arr, 2 * index + 1);
        }
        if(2 * index + 2 < arr.length){
            
            preOrderPrint(arr, 2 * index + 2);
        }        
    }

    /**
     * preOrderPrint overload that automatically calls with index 0
     * because java compiler is dumb dumb and has no default params
     * @param arr The array with stored values
     */
    public static void preOrderPrint(int arr[]){
        preOrderPrint(arr, 0);
    }

    /**
     * This traverses an array as if it were imitating a binary tree
     * and prints it's values using in order
     * @param arr The array with stored values
     * @param index The index to start printing at
     */
    public static void inOrderPrint(int arr[], int index){
        if(arr.length == 0){
            return;
        }
        if(2 * index + 1 < arr.length){
            
            inOrderPrint(arr, 2 * index + 1);
        }
        System.out.print(arr[index] + " ");
        if(2 * index + 2 < arr.length){
            
            inOrderPrint(arr, 2 * index + 2);
        }
    }

    /**
     * inOrderPrint overload that automatically calls with index 0
     * because java compiler is dumb dumb and has no default params
     * @param arr The array with stored values
     */
    public static void inOrderPrint(int arr[]){
        inOrderPrint(arr, 0);
    }

    /**
     * This traverses an array as if it were imitating a binary tree
     * and prints it's values using post order
     * @param arr The array with stored values
     * @param index The index to start printing at
     */
    public static void postOrderPrint(int arr[], int index){
        if(arr.length == 0){
            return;
        }
        if(2 * index + 1 < arr.length){
            
            postOrderPrint(arr, 2 * index + 1);
        }
        if(2 * index + 2 < arr.length){
            
            postOrderPrint(arr, 2 * index + 2);
        }
        System.out.print(arr[index] + " ");
    }

    /**
     * postOrderPrint overload that automatically calls with index 0
     * because java compiler is dumb dumb and has no default params
     * @param arr The array with stored values
     */
    public static void postOrderPrint(int arr[]){
        postOrderPrint(arr, 0);
    }

    public static void getCoords(int arr[], int coords[][], int index, int size, int depth){
        if(arr.length == 0){
            return;
        }
        if(2 * index + 1 < arr.length){
            ++depth;
            getCoords(arr, coords, 2 * index + 1, size, depth);
        }
        System.out.print(arr[index] + " ");
        coords[size][0] = size;
        coords[size][1] = depth;
        ++size;
        if(2 * index + 2 < arr.length){
            ++depth;
            getCoords(arr, coords, 2 * index + 2, size, depth);
        }
        --depth;
    }

    public static void getCoords(int arr[], int coords[][]){
        getCoords(arr, coords, 0, 0, 0);
    }

    public static void main(String[] args) throws IOException{
        // Declare array being simulated as binary tree
        int array[] = new int[10];
        // Populate 0 - 9
        for(int i = 0; i < 10; ++i){
            array[i] = i;
        }
        System.out.print("Pre Order: ");
        preOrderPrint(array);
        System.out.print("\nIn Order: ");
        inOrderPrint(array);
        System.out.print("\nPost Order: ");
        postOrderPrint(array);
        System.out.println("");

        // Store coords
        int coords[][] = new int[array.length][2];
        getCoords(array, coords);

        Plot.Data graph = Plot.data();

        for(int i = 0; i < coords.length; ++i){
            graph.xy(coords[i][0], coords[i][1]);
        }

        Plot plot = Plot.plot(Plot.plotOpts().
                title("Lab 6 Part B").
                legend(Plot.LegendFormat.BOTTOM)).
                    xAxis("x", Plot.axisOpts().range(0, 10)).
                    yAxis("y", Plot.axisOpts().range(0, 5)).

                series("Graph", graph, Plot.seriesOpts().color(Color.BLACK));
        
        plot.save("plot", "png");
    }
}