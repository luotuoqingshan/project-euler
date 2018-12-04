import java.math.BigInteger;

/**
 * Created by thesedays on 2017/12/1.
 */
public class Main {
    static BigInteger qpow(int a,int n){
        BigInteger A = BigInteger.valueOf(a);
        BigInteger ret = BigInteger.ONE;
        while(n > 0){
            if(n % 2 == 1) ret = ret.multiply(A);
            A = A.multiply(A);
            n >>= 1;
        }
        return ret;
    }
    static public void main(String[] args){
        BigInteger ans = qpow(2,7830457);
        ans = ans.multiply(BigInteger.valueOf(28433)).add(BigInteger.ONE);
        System.out.println(ans.mod(BigInteger.valueOf(10000000000L)));
    }
}
