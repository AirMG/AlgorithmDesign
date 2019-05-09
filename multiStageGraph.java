import java.util.*;

class multiStageGraph {
    static int state = 100;
    // save path
    static int[][] minPath = new int[state][state];

    public static void mSG(int stageNum, int[] numPerStage) {
        int i, p, q, weight, temp;
        // init
        for (int j = 0; j < state; j++) {
            for (int k = 0; k < state; k++) {
                minPath[j][k] = Integer.MAX_VALUE;
            }
        }
        // init the source point
        for (p = 0; p < numPerStage[0]; p++) {
            minPath[0][p] = 0;
        }

        Scanner sc = new Scanner(System.in);
        // cal by stage
        for (i = 0; i < stageNum; i++) {
            // traverse every point of source stage
            for (q = 0; q < numPerStage[i]; q++) {
                // traverse every point of stage[i+1]
                for (p = 0; p < numPerStage[i + 1]; p++) {
                    // read weight and save
                    weight = sc.nextInt();
                    // if weight =-1 ,then it doesn't exist
                    if (weight != -1) {
                        // COST(i,j)=min(c(i,j)+COSt(i+1,l))
                        temp = weight + minPath[i][q];
                        // the minimum weight of point in stage[i] to point in stage
                        if (temp < minPath[i + 1][p]) {
                            minPath[i + 1][p] = temp;
                        }
                    }
                }

            }
        }
        sc.close();
        System.out.println(minPath[stageNum - 1][0]);
    }

    public static void main(String[] args) {
        int i, k;
        int[] ni = new int[state];
        Scanner sc = new Scanner(System.in);
        // input stage number
        k = sc.nextInt();
        sc.nextLine();
        if (k != -1) {
            for (i = 0; i < k; i++) {
                // input stage number of every stage
                ni[i] = sc.nextInt();
            }
            sc.nextLine();
            mSG(k, ni);
        }
        sc.close();
    }
}