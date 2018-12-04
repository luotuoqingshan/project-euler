import java.math.BigInteger;

/**
 * Created by thesedays on 2017/11/27.
 */

public class Main {
    static public void main(String[] args){
        BigInteger d = BigInteger.valueOf(408),n = BigInteger.valueOf(577);
        int ans = 0;
        for(int i = 8;i <= 1000;i++){
            BigInteger dd,nn;
            nn = d.multiply(BigInteger.valueOf(2)).add(n);
            dd = d.add(n);
            if(nn.toString().length() > dd.toString().length()) ans++;
            d = dd;
            n = nn;
        }
        System.out.println(ans);
    }
}
