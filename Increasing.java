import java.util.Arrays;
import java.util.Scanner;
 
public class Increasing {
 
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int t = scan.nextInt();
    String res[] = new String[t];
 
    for (int i = 0; i < res.length; i++) {
      int n = scan.nextInt();
      int ct = 0;
      long arr[] = new long[n];
 
      for (int j = 0; j < arr.length; j++) {
        arr[j] = scan.nextLong();
      }
      Arrays.sort(arr);
 
      if (n == 1) {
        res[i] = "YES";
      } else {
        for (int j = 1; j < arr.length; j++) {
          if (arr[j] == arr[j - 1]) {
            ct++;
          }
        }
        if (ct > 0) {
          res[i] = "NO";
        } else {
          res[i] = "YES";
        }
      }
    }
    for (int i = 0; i < res.length; i++) {
      System.out.println(res[i]);
    }
  }
}
