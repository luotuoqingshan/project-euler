import jdk.internal.util.xml.impl.Input;

import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by thesedays on 2017/12/1.
 */
public class Main {
    static public void main(String[] args)throws Exception{
        File f = new File("../271.txt");
        FileInputStream fis = new FileInputStream(f);
        Scanner in = new Scanner(fis);
        BigInteger ans = BigInteger.ZERO;
        while(in.hasNext()){
            ans = ans.add(in.nextBigInteger());
        }
        System.out.println(ans);
    }
}
