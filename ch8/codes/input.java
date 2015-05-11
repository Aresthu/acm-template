import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        // 也可以写成 Scanner cin = new Scanner(System.in);
        // 不过前一种写法速度会快一些。
        
        while (cin.hasNextInt()) {
            int a=cin.nextInt();
            int b=cin.nextInt();
            System.out.println(a+b);
        }
    }
}
