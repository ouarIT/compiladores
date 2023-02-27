import java.io.*;

public class Predictivo {
    private int preanalisis;
    private StringReader sr;

    public Predictivo() {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String cad;
        try {
            cad = br.readLine();
            sr = new StringReader(cad);
            preanalisis = sr.read();
        } catch (IOException e) {
            System.out.println("Excepcion de E/S : " + e);
        }
    }

    public void expr() // E -> TE'
    {
        System.out.println("--- Llama a T ---");
        term();
        System.out.println("--- Llama a E' ---");
        exprp();
    }

    public void exprp() // E' -> +TE' | -TE'
    {
        System.out.println("--- Entra a E' ---");
        if (preanalisis == '+') {
            try {
                System.out.println("--- Entra al simbolo '+' ---");
                empareja('+');
                term();
                exprp();
            } catch (Exception e) {
            }
        } else if (preanalisis == '-') {
            try {
                System.out.println("--- Entra al simbolo '-' ---");
                empareja('-');
                term();
                exprp();
            } catch (Exception e) {
            }
        }
    }

    public void term() // T -> FT'
    {
        System.out.println("--- Llama a F ---");
        exp();
        System.out.println("--- Llama a T' ---");
        termp();
    }

    public void termp() // T' -> *FT' | /FT'
    {
        System.out.println("--- Entra a T' ---");
        if (preanalisis == '*') {
            try {
                System.out.println("--- Entra al simbolo '*' ---");
                empareja('*');
                exp();
                termp();
            } catch (Exception e) {
            }
        } else if (preanalisis == '/') {
            try {
                System.out.println("--- Entra al simbolo '/' ---");
                empareja('/');
                exp();
                termp();
            } catch (Exception e) {
            }
        }
    }

    public void exp() // F -> ( E ) | N
    {
        System.out.println("--- Entra a F ---");
        if (preanalisis == '(') {
            try {
                System.out.println("--- Abre simbolo '(' ---");
                empareja('(');
                expr();
                empareja(')');
                System.out.println("--- Cierra simbolo ')' ---");
            } catch (Exception e) {
            }
        } else {
            System.out.println("--- Llamada a N ---");
            digito();
        }
    }

    public void digito() {
        if (preanalisis == '0') {
            try {
                empareja('0');
            } catch (Exception e) {
            }
        } else if (preanalisis == '1') {
            try {
                empareja('1');
            } catch (Exception e) {
            }
        } else if (preanalisis == '2') {
            try {
                empareja('2');
            } catch (Exception e) {
            }
        } else if (preanalisis == '3') {
            try {
                empareja('3');
            } catch (Exception e) {
            }
        } else if (preanalisis == '4') {
            try {
                empareja('4');
            } catch (Exception e) {
            }
        } else if (preanalisis == '5') {
            try {
                empareja('5');
            } catch (Exception e) {
            }
        } else if (preanalisis == '6') {
            try {
                empareja('6');
            } catch (Exception e) {
            }
        } else if (preanalisis == '7') {
            try {
                empareja('7');
            } catch (Exception e) {
            }
        } else if (preanalisis == '8') {
            try {
                empareja('8');
            } catch (Exception e) {
            }
        } else if (preanalisis == '9') {
            try {
                empareja('9');
            } catch (Exception e) {
            }
        } else {
            throw new Error("Error de sintaxis << Digito >>");
        }
    }

    public void empareja(char c) throws Exception {
        System.out.println("--- Entra empareja ---");
        System.out.println("<< Elemento: " + c + " >>");
        if (c == preanalisis) {
            preanalisis = sr.read();
        } else {
            throw new Error("Error << Empareja >>");
        }
    }

    public static void main(String[] args) {
        Predictivo pred = new Predictivo();
        System.out.println("--- Llamada a E ---");
        pred.expr();
    }
}