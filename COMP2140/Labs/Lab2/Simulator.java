public class Simulator {
    public static boolean run ( DFA dfa , String input ) {
        // you need to fill in the missing part here .
        String s = dfa.startState;
        int i = 0;
        char c;
        while(i < input.length()){
            c = input.charAt(i++);
            s = move(s, c);
        }
        if(dfa.finalStates.contains(s)){
            return true;
        }
        return false;
    }

    public static String move(String current_state, char next_char){
        String next_state = DFA.transitions.get(current_state + "_" + next_char);
        return next_state;
    }
}
