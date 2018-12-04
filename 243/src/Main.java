import com.sun.tools.internal.xjc.reader.xmlschema.bindinfo.BIGlobalBinding;

import java.math.BigInteger;

/**
 * Created by thesedays on 2017/11/28.
 */
public class Main {
    static int[] vis = new int[1000005];
    static public void main(String[] args){
        for(int i = 1;i <= 1000000;i++){
            vis[i] = 0;
        }
        vis[1] = 1;
        for(int i = 2;i <= 1000000;i++)if(vis[i] == 0){
            for(int j = 2 * i;j <= 1000000;j += i){
                vis[j] = 1;
            }
        }
        BigInteger n = BigInteger.ONE;
        BigInteger d = BigInteger.ONE;
        BigInteger two = BigInteger.valueOf(2);
        for(int i = 1;i <= 2;i++){
            n = n.multiply(two);
            d = d.multiply(two);
        }
        for(int i = 1;i <= 28;i++){
            if(vis[i] == 1) continue;
            n = n.multiply(BigInteger.valueOf(i));
            d = d.multiply(BigInteger.valueOf(i - 1));
            if(d.multiply(BigInteger.valueOf(94744)).compareTo(n.subtract(BigInteger.ONE).multiply(BigInteger.valueOf(15499))) == -1){
                System.out.println(n);
                System.out.print(i);
                break;
            }
        }
        System.out.println(d);
        System.out.println(n.subtract(BigInteger.ONE));
    }
}
