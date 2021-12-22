import java.util.ArrayList;
import java.util.Map;
import java.util.TreeMap;

/*
Final Exam
Lucas Sarweh
ID: 110042658
COMP-2120
Dec 17 2021
*/

/**
 * This class stores polynomials
 */
public class Polynomial
{
    // Fields
    TreeMap<Integer, Integer> polymap;
    Integer degree;

    // Methods
    /**
     * No-arg constructor initializes the map
     */
    public Polynomial(){
        polymap = new TreeMap<Integer, Integer>();
        polymap.put(-1, 0);
        degree = -1;
    }

    /**
     * Initialize a polynomial with a single term
     * @param deg The degree of the term
     * @param coef The coefficiennt of the term
     */
    public Polynomial(int deg, int coef){
        try{
            if(deg < 0){
                throw new IllegalArgumentException("No degree less than 0");
            }
            polymap = new TreeMap<>();
            polymap.put(deg, coef);
            degree = deg;
        }catch(IllegalArgumentException e){

        }
    }

    /**
     * Make a polynomial from a given map
     * @param map The map of <Integer, Integer>
     */
    public Polynomial(TreeMap<Integer, Integer> map){
        degree = 0;
        polymap = new TreeMap<>();
        for (Map.Entry<Integer, Integer> i : map.entrySet()) {
            polymap.put(i.getKey(), i.getValue());
            if(degree < i.getKey()){
                degree = i.getKey();
            }
        }
    }

    /**
     * This copies a Polynomial to a new one
     * @param tocopy The Polynomial to copy
     */
    public Polynomial(Polynomial tocopy){
        degree = 0;
        polymap = new TreeMap<>();
        for(Map.Entry<Integer, Integer> i : tocopy.polymap.entrySet()){
            polymap.put(i.getKey(), i.getValue());
            if(degree < i.getKey()){
                degree = i.getKey();
            }
        }
    }

    /**
     * Add the Polynomial given to this Polynomial
     * @param newterms The Polynomial to add with
     */
    public void add(Polynomial newterms){
        boolean wasSet = false;
        ArrayList<Integer> keys = new ArrayList<>();
        for(Map.Entry<Integer, Integer> i : newterms.polymap.entrySet()){
            for(Map.Entry<Integer, Integer> j : polymap.entrySet()){
                if(i.getKey() == j.getKey()){
                    polymap.put(j.getKey(), j.getValue() + i.getValue());
                    wasSet = true;
                }
            }
            if(wasSet == false){
                keys.add(i.getKey());
            }
            wasSet = false;
        }
        for(Integer p : keys){
            polymap.put(p, newterms.polymap.get(p));
            if(degree < p){
                degree = p;
            }
        }
    }

    /**
     * Adds two Polynomials into a new one
     * @param first First Polynomial
     * @param second Second Polynomial
     * @return Added Polynomial
     */
    public static Polynomial add(Polynomial first, Polynomial second){
        Polynomial newpoly = new Polynomial(first);
        newpoly.degree = 0;
        for(Map.Entry<Integer, Integer> i : second.polymap.entrySet()){
            if(newpoly.polymap.get(i.getKey()) != null){
                newpoly.polymap.put(i.getKey(), i.getValue() + newpoly.polymap.get(i.getKey()));
            }else{
                newpoly.polymap.put(i.getKey(), i.getValue());
                if(newpoly.degree < i.getKey()){
                    newpoly.degree = i.getKey();
                }
            }
        }
        return newpoly;
    }

    /**
     * Subtracts an instance Polynomial from the given one
     * @param newterms The Polynomial to subtract from
     */
    public void subtract(Polynomial newterms){
        boolean wasSet = false;
        ArrayList<Integer> keys = new ArrayList<>();
        for(Map.Entry<Integer, Integer> i : newterms.polymap.entrySet()){
            for(Map.Entry<Integer, Integer> j : polymap.entrySet()){
                if(i.getKey() == j.getKey()){
                    polymap.put(j.getKey(), j.getValue() - i.getValue());
                    wasSet = true;
                }
            }
            if(wasSet == false){
                keys.add(i.getKey());
            }
            wasSet = false;
        }
        for(Integer p : keys){
            polymap.put(p, 0 - newterms.polymap.get(p));
            if(degree < p){
                degree = p;
            }
        }
    }

    /**
     * Subtracts the second Polynomial from the first
     * @param first First Polynomial
     * @param second Second polynomial
     * @return A new Polynomial from the two being subtracted
     */
    public static Polynomial subtract(Polynomial first, Polynomial second){
        Polynomial newpoly = new Polynomial(first);
        newpoly.degree = 0;
        for(Map.Entry<Integer, Integer> i : second.polymap.entrySet()){
            if(newpoly.polymap.get(i.getKey()) != null){
                newpoly.polymap.put(i.getKey(), newpoly.polymap.get(i.getKey()) - i.getValue());
            }else{
                newpoly.polymap.put(i.getKey(), 0 - i.getValue());
                if(newpoly.degree < i.getKey()){
                    newpoly.degree = i.getKey();
                }
            }
        }
        return newpoly;
    }

    public Polynomial multiply(Polynomial mult){
        Polynomial newpoly = new Polynomial(mult);
        for(Map.Entry<Integer, Integer> i : polymap.entrySet()){
            if(newpoly.polymap.get(i.getKey()) != null){
                newpoly.polymap.put(i.getKey(), newpoly.polymap.get(i.getKey()) * i.getValue());
            }else{
                newpoly.polymap.put(i.getKey(), i.getValue());
            }
        }
        return newpoly;
    }

    public Integer getDegree(){
        return degree;
    }

    public Integer coefficient(Integer key){
        return polymap.get(key);
    }

    public void changeCoefficient(int key, int val){
        if(polymap.get(key) != null){
            polymap.put(key, val);
        }
    }

    public void removeTerm(int key){
        if(polymap.get(key) != null){
            polymap.remove(key);
        }
    }

    public double evaluate(double x){
        double total = 0;
        for(Map.Entry<Integer, Integer> i : polymap.entrySet()){
            total += i.getValue() * (Math.pow(x, i.getKey()));
        }
        return total;
    }

    public int compareTo(Polynomial i){
        return 1;
    }

    public boolean equals(Polynomial e){
        if(e.polymap.size() == polymap.size()){
            return true;
        }
        return false;
    }

    public String toString(){
        String string = "P(x) = ";
        for(Map.Entry<Integer, Integer> i : polymap.entrySet()){
            string = string + i.getValue() + "x" + i.getKey();
        }
        return string;
    }
}