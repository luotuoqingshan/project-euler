import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by thesedays on 2017/11/30.
 */
public class Main {
    static BigInteger n;
    static int[] d = new int[105];
    static long[][] dp = new long[105][2];
    static public void main(String[] args){
        Scanner in = new Scanner(System.in);
        n = in.nextBigInteger();
        int tot = 0;
        while(n.compareTo(BigInteger.ZERO) == 1){
            d[++tot] = (n.mod(BigInteger.valueOf(2)).toString().charAt(0) - '0');
            n = n.divide(BigInteger.valueOf(2));
        }
        dp[tot + 1][0] = 1;
        dp[tot + 1][1] = 0;
        for(int i = tot;i >= 1;i--){
            dp[i][0] = dp[i][1] = 0;
            if(d[i] == 1){
                dp[i][1] += dp[i + 1][0] + dp[i + 1][1];
                dp[i][0] += dp[i + 1][0];
            }else{
                dp[i][1] += dp[i + 1][1];
                dp[i][0] += dp[i + 1][0] + dp[i + 1][1];
            }
        }
        System.out.println(dp[1][0]);
    }
}
