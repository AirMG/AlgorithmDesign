import java.util.Scanner;

class ZeroOneBag {
    public static void ZOB(int size, int n, int[][] good) {
        // value and space
        int[][] dp = new int[n + 1][size + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= size; j++) {
                // if space is not enough
                if (j < good[i][0]) {
                    dp[i][j] = dp[i - 1][j];
                    // is space is enough
                } else {
                    // not pack value is bigger than pack
                    if (dp[i - 1][j] > dp[i - 1][j - good[i][0]] + good[i][1]) {
                        dp[i][j] = dp[i - 1][j];
                    } else {
                        // value is bigger when packed
                        dp[i][j] = dp[i - 1][j - good[i][0]] + good[i][1];
                    }
                }

            }
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= size; j++) {
                System.out.print(dp[i][j] + " ");
            }
            System.out.println();
        }
        ZOBConstruct(n, size, dp, good);
    }

    public static void ZOBConstruct(int i, int j, int[][] dp, int[][] good) {
        if (i > 0) {
            if (dp[i][j] == dp[i - 1][j]) {
                // System.out.println("")
                ZOBConstruct(i - 1, j, dp, good);
            } else if (j - good[i][0] >= 0 && dp[i][j] == dp[i - 1][j - good[i][0]] + good[i][1]) {
                System.out.print("pack number " + i + "good ");
                if (i != 1)
                    System.out.print(" ");
                ZOBConstruct(i - 1, j - good[i][0], dp, good);
            }
        }
    }

    public static void main(String[] args) {
        System.out.println("input space of bag");
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        sc.nextLine();
        System.out.println("input number of goods");
        int n = sc.nextInt();
        sc.nextLine();
        int[][] good = new int[n + 1][2];
        System.out.println("input good space and value");
        for (int i = 1; i <= n; i++) {
            good[i][0] = sc.nextInt();
            good[i][1] = sc.nextInt();
            sc.nextLine();
        }
        ZOB(size, n, good);
        sc.close();
    }
}