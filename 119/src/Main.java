import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

/**
 * Created by thesedays on 2017/11/29.
 */
public class Main {
    static ArrayList<BigInteger> ans = new ArrayList<BigInteger>();
    BigInteger qpow(BigInteger a,int n){
        BigInteger ret = BigInteger.ONE;
        while(n > 0){
            if(n % 2 == 1) ret = ret.multiply(a);
            a = a.multiply(a);
            n >>= 1;
        }
        return ret;
    }
    static public void main(String[] args){
        for(int i = 2;i <= 100;i++){
            BigInteger tmp = BigInteger.valueOf(i);
            for(int j = 2;j <= 100;j++){
                tmp = tmp.multiply(BigInteger.valueOf(i));
                if(tmp.toString().length() > i) break;
                String s = tmp.toString();
                int now = 0;
                for(int k = 0;k < s.length();k++){
                    now += (s.charAt(k) - '0');
                }
                if(now == i){
                    ans.add(tmp);
                }
            }
        }
        Collections.sort(ans);
        int cnt = 0;
        for(BigInteger now : ans){
            cnt++;
            if(cnt == 30){
                System.out.println(now);
            }
        }
    }

}
