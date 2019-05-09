import java.util.*;

class dptriangulation {
    // weight fucntion
    public static int CalWeight(int v, int k, int j) {
        return v + k + j;
    }

    // cal
    public static void Dpt(int n, int[][] weight, int[][] res) {
        // res array
        int[][] t = new int[n][n];

        for (int r = 2; r <= n; r++) {
            for (int i = 1; i <= n - r + 1; i++) {
                int j = i + r - 1;
                t[i][j] = t[i + 1][j] + CalWeight(weight[i - 1][i], weight[i][j], weight[i - 1][j]);
                res[i][j] = i;
                for (int k = i + 1; k < j; k++) {
                    int temp = t[i][k] + t[k + 1][j] + CalWeight(weight[i - 1][k], weight[k][j], weight[i - 1][j]);
                    if (temp < t[i][j]) {
                        t[i][j] = temp;
                        res[i][j] = k;
                    }
                }
            }
        }
        System.out.println(t[1][n - 1]);
    }

    // output
    public static void Struct(int i, int j, int[][] res) {
        if (i == j) {
            return;
        }
        Struct(i, res[i][j], res);
        Struct(res[i][j] + 1, j, res);
        System.out.println("point:v" + (i - 1) + "v" + j + "v" + res[i][j]);
    }

    public static void main(String[] args) {
        System.out.println("input n");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        // input weight
        System.out.println("input weight");
        int[][] weight = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.println("input the weight of point " + i );
                weight[i][j] = sc.nextInt();
                sc.nextLine();
            }
        }
        // save Vk's position 
        int[][] res = new int[n][n];
        Dpt(n - 1, weight, res);
        Struct(1, n, res);
        sc.close();
    }
}