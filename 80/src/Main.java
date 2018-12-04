import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;
import java.math.RoundingMode;

import static java.lang.StrictMath.sqrt;

/**
 * Created by thesedays on 2017/11/27.
 */
public class Main {
    static Boolean[] vis = new Boolean[105];
    static public void main(String[] args){
        for(int i = 1;i <= 100;i++) vis[i] = false;
        for(int i = 1;i <= 10;i++) vis[i * i] = true;
        int ans = 0;
        for(int i = 1;i <= 100;i++){
            if(vis[i] == true) continue;
            BigInteger a = BigInteger.valueOf((int) sqrt(i));
           // System.out.println(a);
            BigInteger n = BigInteger.valueOf(i);
            for(int j = 1;j <= 99;j++){
                n = n.multiply(BigInteger.valueOf(100));
                BigInteger tmp = a.multiply(BigInteger.valueOf(10));
                for(int k = 0;k < 10;k++){
                    BigInteger tmp1 = tmp.add(BigInteger.valueOf(k));
                    if(tmp1.multiply(tmp1).compareTo(n) != 1){
                        a = tmp1;
                    }
                }
            }
            String s = a.toString();
            for(int j = 0;j < 100;j++){
                ans += (s.charAt(j) - '0');
            }
        }
        System.out.println(ans);
    }
}
