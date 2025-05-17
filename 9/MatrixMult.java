import java.util.Scanner;

public class MatrixMult {

    static void printOptimalParenthesis(int[][] s, int i, int j) {
        if (i == j) System.out.print("A" + i);
        else {
            System.out.print("(");
            printOptimalParenthesis(s, i, s[i][j]);
            printOptimalParenthesis(s, s[i][j] + 1, j);
            System.out.print(")");
        }
    }

    public static void matrixChainOrder(int[] p, int n) {
        int[][] m = new int[n][n];
        int[][] s = new int[n][n];

        for (int L = 2; L < n; L++) {
            for (int i = 1; i < n - L + 1; i++) {
                int j = i + L - 1;
                m[i][j] = Integer.MAX_VALUE;
                for (int k = i; k < j; k++) {
                    int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if (q < m[i][j]) { m[i][j] = q; s[i][j] = k; }
                }
            }
        }

        System.out.println("M Table:");
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) System.out.print(m[i][j] + "\t");
            System.out.println();
        }

        System.out.println("S Table:");
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) System.out.print(s[i][j] + "\t");
            System.out.println();
        }

        System.out.println("Optimal order requires " + m[1][n - 1] + " scalar multiplications.");
        System.out.print("Optimal parenthesization: ");
        printOptimalParenthesis(s, 1, n - 1);
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of matrices: ");
        int numMatrices = scanner.nextInt();
        int[] p = new int[numMatrices + 1];

        for (int i = 1; i <= numMatrices; i++) {
            System.out.print("Enter row and col size of A" + i + ": ");
            int row = scanner.nextInt(), col = scanner.nextInt();
            if (i > 1 && p[i - 1] != row) {
                System.out.println("Incompatible dimensions. Exiting.");
                return;
            }
            p[i - 1] = i == 1 ? row : p[i - 1];
            p[i] = col;
        }

        matrixChainOrder(p, numMatrices + 1);
        scanner.close();
    }
}
