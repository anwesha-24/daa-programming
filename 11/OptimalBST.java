import java.util.Scanner;

public class OptimalBST{
    public static int obst(int[] keys, int[] freq, int n) {
        int[][] cost = new int[n][n];

        for (int i = 0; i < n; i++) {
            cost[i][i] = freq[i];
        }

        for (int L = 2; L <= n; L++){
            for (int i = 0; i <= n - L; i++) {
                int j = i + L - 1;
                cost[i][j] = Integer.MAX_VALUE;

                for (int r = i; r <= j; r++) {
                    int c = (r > i ? cost[i][r - 1] : 0) +
                            (r < j ? cost[r + 1][j] : 0) +
                            sum(freq, i, j);

                    if (c < cost[i][j]) {
                        cost[i][j] = c;
                    }
                }
            }
        }
        return cost[0][n - 1];
    }

    private static int sum(int[] freq, int i, int j) {
        int s = 0;
        for (int k = i; k <= j; k++) {
            s += freq[k];
        }
        return s;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of keys: ");
        int n = scanner.nextInt();

        int[] keys = new int[n];
        int[] freq = new int[n];

        System.out.println("Enter the keys in sorted order:");
        for (int i = 0; i < n; i++) {
            keys[i] = scanner.nextInt();
        }

        System.out.println("Enter the frequencies for each key:");
        for (int i = 0; i < n; i++) {
            freq[i] = scanner.nextInt();
        }

        System.out.println("Cost of Optimal Binary Search Tree: " + obst(keys, freq, n));
        
        scanner.close();
    }
}
