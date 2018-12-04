import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by thesedays on 2017/11/27.
 */
public class Main {
    static BigInteger[] x = new BigInteger[205],y = new BigInteger[205];
    public static void main(String[] args){
        x[0] = BigInteger.valueOf(2);
        y[0] = BigInteger.valueOf(0);
        x[1] = BigInteger.valueOf(4);
        y[1] = BigInteger.valueOf(3);
        BigInteger four = BigInteger.valueOf(4);
        for(int i = 2;i <= 200;i++){
            x[i] = x[i - 1].multiply(four).subtract(x[i - 2]);
            y[i] = y[i - 1].multiply(four).subtract(y[i - 2]);
        }
        BigInteger n;
        int T;
        Scanner in = new Scanner(System.in);
        T = in.nextInt();
        while(T-->0){
            n = in.nextBigInteger();
            for(int i = 1;i <= 200;i++){
                if(x[i].compareTo(n) != -1){
                    System.out.println(x[i]);
                    break;
                }
            }
        }
    }
}
