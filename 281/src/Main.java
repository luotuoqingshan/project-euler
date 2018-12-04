import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by thesedays on 2017/11/27.
 */
public class Main {
    static final BigInteger MAXN = BigInteger.valueOf(1000000000000000L);
    static BigInteger fac(int n){
        BigInteger ret = BigInteger.ONE;
        for(int i = 1;i <= n;i++){
            ret = ret.multiply(BigInteger.valueOf(i));
        }
        return ret;
    }
    static BigInteger cal(int m,int n){
        BigInteger ret = fac(m);
        int x = m / n;
        for(int i = 1;i <= x;i++){
            ret = ret.divide(fac(n));
        }
        return ret;
    }
    static int gcd(int a,int b){
        if(b == 0){
            return a;
        }
        return gcd(b,a % b);
    }
    static BigInteger solve(int m,int n){
        BigInteger ans = BigInteger.ZERO;
        for(int i = 1;i <= n;i++){
            int now = gcd(i,n) * m;
            int tmp = now / m;
            ans = ans.add(cal(now,tmp));
        }
        ans = ans.divide(BigInteger.valueOf(m * n));
        return ans;
    }
    static public void main(String[] args){
        BigInteger ans = BigInteger.ZERO;
        for(int m = 2;m <= 30;m++){
            for(int n = 1;n <= 40;n++){
                BigInteger ret = solve(m,n);
                if(ret.compareTo(MAXN) != 1){
                    ans = ans.add(ret);
                }
            }
        }
        System.out.println(ans);
    }
}
