/**
 * Created by thesedays on 2017/11/21.
 */
import java.math.BigDecimal;
import java.math.BigInteger;

public class Main {
    static BigInteger cal(int n){
        BigDecimal a = BigDecimal.valueOf(2.0 / (n + 1));
        BigDecimal b = BigDecimal.ONE;
        for(int i = 1;i <= n;i++){
            BigDecimal c = BigDecimal.valueOf(i);
            for(int j = 1;j <= i;j++){
                b = b.multiply(c);
            }
        }
        for(int i = 1;i <= n * (n + 1) / 2;i++){
            b = b.multiply(a);
        }
        return b.toBigInteger();
    }
    public static void main(String[] args){
        BigInteger ans = BigInteger.ZERO;
        for(int i = 2;i <= 15;i++){
            ans = ans.add(cal(i));
        }
        System.out.println(ans);
    }
}
