import java.util.Scanner;

public class EvenNumberAddicts {
    public static void main(String [] args)
    {
        Scanner scan = new Scanner(System.in);
        int test = scan.nextInt();
        while (test-- >0)
        {
            int n= scan.nextInt();
            long [] a = new long[n];
            int countEven=0;
            int countOdd = 0;
            int countNeg =0;
            for (int i= 0;i<n;i++)
            {
                a[i] = scan.nextLong();
                if(a[i]%2==0)
                {
                    countEven++;
                }
                else {
                    countOdd++;
                }
                if(a[i]<0)
                {
                    countNeg++;
                }
            }


            if(countOdd==n || countEven==n)
            {
                if(n%2==0 && countOdd%4!=0)
                {
                    System.out.println("Bob");
                }
                else if(n%2==1 && countOdd%4==1)
                {
                    System.out.println("Bob");
                }
                else {
                    System.out.println("Alice");
                }

            }else // 1 3  2 4 8 6 7 9 5 11 20
            {
                if(n%2==0)
                {
                    if((countOdd%2==0 && countOdd%4!=0))
                    {
                        System.out.println("Bob");
                    }
                    else
                    {
                        System.out.println("Alice");
                    }
                }else {
                    if((countOdd%2==0 && countOdd%4!=0) || (countOdd%2==1 && countOdd%4!=3))
                    {
                        System.out.println("Bob");
                    }
                    else
                    {
                        System.out.println("Alice");
                    }

                }

            }

        }
    }
}