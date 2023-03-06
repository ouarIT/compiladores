import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StringReader;

public class Binario {

    private int preanalisis;
    private StringReader sr;

    public Binario() {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String cad;
        try {
            cad = br.readLine();
            sr = new StringReader(cad);
            preanalisis = sr.read();
        } catch (IOException e) {
            System.out.println("Ecepcion de E/S : " + e);
        }
    }

    public int B() // B -> D B'
    {
        int valorD = -1, valorB = -1;
        valorD = D();
        valorB = Bp(valorD);
        return valorB;
    }

    public int Bp(int valorH) // B' -> D B'
    {
        int valorD = -1, valorB = -1;
        if (preanalisis == '0' || preanalisis == '1') {
            valorD = D();
            valorB = Bp((valorH * 2) + valorD);
        } else
            valorB = valorH;
        return valorB;
    }

    public int D() // D -> 0 | 1
    {
        int valorD = -1;
        if (preanalisis == '0') {
            try {
                empareja('0');
                valorD = 0;
            } catch (Exception e) {
            }
        } else if (preanalisis == '1') {
            try {
                empareja('1');
                valorD = 1;
            } catch (Exception e) {
            }
        } else {
            throw new Error("Error de sintaxis << Bit >>");
        }
        return valorD;
    }

    public void empareja(char c) throws Exception {
        if (c == preanalisis) {
            preanalisis = sr.read();
        } else {
            throw new Error("Error << Empareja >>");
        }
    }

    public static void main(String[] args) {
        Binario pred = new Binario();
        int result = -1;
        System.out.println("--- Predictivo Binario ---");
        result = pred.B();
        System.out.println("Resultado: " + result);
    }
}
