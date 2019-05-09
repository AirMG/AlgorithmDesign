import java.util.Scanner;

class LongestCommonSubsequence {
    public static void LCS(String sa, String sb) {
        int lena = sa.length();
        int lenb = sb.length();
        // System.out.println(lena);
        // System.out.println(lenb);
        // System.out.println(sa.charAt(1));
        int[][] res = new int[lena + 1][lenb + 1];
        int[][] c = new int[lena + 1][lenb + 1];
        for (int i = 1; i < lena + 1; i++) {
            for (int j = 1; j < lenb + 1; j++) {
                if (sa.charAt(i - 1) == sb.charAt(j - 1)) {
                    c[i][j] = c[i - 1][j - 1] + 1;
                    res[i][j] = 1;
                } else if (c[i][j - 1] < c[i - 1][j]) {
                    c[i][j] = c[i - 1][j];
                    res[i][j] = 2;
                } else {
                    c[i][j] = c[i][j - 1];
                    res[i][j] = 3;
                }
            }
        }
        // System.out.println("mark");
        LCSConstruct(sa.length(), sb.length(), sa, res);
    }

    // output
    public static void LCSConstruct(int i, int j, String sa, int[][] res) {
        if (i == 0 || j == 0) {
            return;
        }
        if (res[i][j] == 1) {
            LCSConstruct(i - 1, j - 1, sa, res);
            System.out.print(sa.charAt(i - 1));
        } else if (res[i][j] == 2) {
            LCSConstruct(i - 1, j, sa, res);
        } else
            LCSConstruct(i, j - 1, sa, res);
    }

    public static void main(String[] args) {
        System.out.println("input first String");
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        sc.nextLine();
        System.out.println("input second String");
        String b = sc.next();
        sc.nextLine();
        LCS(a, b);
        sc.close();
    }
}