import java.util.*;

class matrixmulti {
    public static void output(int[][] s, int i, int j) {
        int temp = s[i][j];
        if (j - i > 2) {
            // res.add(s[i][j]);
            output(s, i, temp);
            output(s, temp+2, j);
        }
        System.out.println(temp+1);
    }

    public static void mm(int matrixnumber, ArrayList<Integer> matrixparam, int[][] s) {
        int[][] m = new int[matrixnumber][matrixnumber];
        for (int i = 0; i < matrixnumber; i++) {
            m[i][i] = 0;
        }
        for (int r = 2; r <= matrixnumber; r++) {
            for (int i = 0; i < matrixnumber - r + 1; i++) {
                int j = i + r - 1;
                m[i][j] = m[i + 1][j] + matrixparam.get(i) * matrixparam.get(i + 1) * matrixparam.get(j + 1);
                s[i][j] = i;
                for (int k = i + 1; k < j; k++) {
                    int temp = m[i][k] + m[k + 1][j]
                            + matrixparam.get(i) * matrixparam.get(k + 1) * matrixparam.get(j + 1);
                    if (temp < m[i][j]) {
                        m[i][j] = temp;
                        s[i][j] = k;
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        int matrixnumber;
        Scanner sc = new Scanner(System.in);
        System.out.println("imput matrix number");
        matrixnumber = sc.nextInt();
        sc.nextLine();
        int[][] s = new int[matrixnumber][matrixnumber];
        ArrayList<Integer> matrixparam = new ArrayList<Integer>();
        System.out.println("imput matrix param");
        for (int i = 0; i < matrixnumber + 1; i++) {
            matrixparam.add(sc.nextInt());
        }
        sc.nextLine();
        mm(matrixnumber, matrixparam, s);
        System.out.println("input i,j of Ai and Aj");
        int i = sc.nextInt();
        int j = sc.nextInt();
        sc.nextLine();
        output(s, i-1, j-1);
        sc.close();
    }
}
