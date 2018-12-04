import java.math.BigInteger;

import static java.lang.StrictMath.max;

/**
 * Created by thesedays on 2017/11/21.
 */
public class Main {
    public static void main(String args[]){
        long ans = 0;
        for(int a = 1;a < 100;a++){
            for(int b = 1;b < 100;b++){
                BigInteger c = BigInteger.valueOf((long) a);
                BigInteger d = BigInteger.ONE;
                for(int i = 1;i <= b;i++){
                    d = d.multiply(c);
                }
                String tmp = d.toString();
                long ret = 0;
                for(int i = 0;i < tmp.length();i++){
                    ret += tmp.charAt(i) - '0';
                }
                ans = max(ans,ret);
            }
        }
        System.out.print(ans);
    }
}
