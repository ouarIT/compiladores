import java.io.*;
import java.util.Stack;

public class Posfija {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String EI, auxEI, EPOS = "";
        Stack pila = new Stack();
        char actual;

        System.out.println("Funcion en Infijo:");
        EI = br.readLine();
        auxEI = EI;

        while (!auxEI.isEmpty()) {
            actual = auxEI.charAt(0);

            if (operador(actual)) {
                if (pila.isEmpty() || prioridad(actual) > prioridad(pila.lastElement().toString().charAt(0))
                        || actual == '(') {
                    pila.push(actual);
                } else {
                    while (!pila.isEmpty() && prioridad(actual) <= prioridad(pila.lastElement().toString().charAt(0))) {
                        EPOS += pila.lastElement().toString();
                        pila.pop();
                    }
                    pila.push(actual);
                }
            } else if (actual == ')') {
                while (pila.lastElement().toString().charAt(0) != '(') {
                    EPOS += pila.lastElement().toString();
                    pila.pop();
                }
                pila.pop();
            } else {
                EPOS += auxEI.charAt(0);
            }
            auxEI = auxEI.substring(1);
        }
        while (!pila.isEmpty()) {
            EPOS += pila.lastElement().toString();
            pila.pop();
        }
        System.out.println(EPOS);
    }

    public static boolean operador(char c) {
        if (c == '/' || c == '*' || c == '+' || c == '-' || c == '^' || c == '(')
            return true;
        else
            return false;
    }

    public static int prioridad(char c) {
        int pC = 0;
        if (c == '^')
            pC = 3;
        else if (c == '/' || c == '*')
            pC = 2;
        else if (c == '-' || c == '+')
            pC = 1;
        return pC;
    }
}