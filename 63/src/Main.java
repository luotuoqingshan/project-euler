import java.math.BigInteger;

/**
 * Created by thesedays on 2017/11/27.
 */
public class Main {
    static BigInteger qpow(int a,int n){
        BigInteger ret = BigInteger.ONE;
        BigInteger b = BigInteger.valueOf(a);
        while(n > 0){
            if(n % 2 == 1){
                ret = ret.multiply(b);
            }
            b = b.multiply(b);
            n >>= 1;
        }
        return BigInteger.ZERO;
    }
    static public void main(String[] args){
        int ans = 0;
       for(int i = 1;i < 10;i++){
           BigInteger b = BigInteger.valueOf(i);
           BigInteger a = BigInteger.ONE;
           for(int j = 1;;j++){
               a = a.multiply(b);
               if(a.toString().length() < j) break;
               if(a.toString().length() == j) ans++;
           }
       }
       System.out.println(ans);
    }
}
