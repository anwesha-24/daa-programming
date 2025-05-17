import java.util.Scanner;

public class tsp {
    private static final int INF = Integer.MAX_VALUE;
    private int[][] distance;
    private int[][] memo;
    private int n;

    public tsp(int[][] distance) {
        this.distance = distance;
        this.n = distance.length;
        this.memo = new int[n][1 << n];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (1 << n); j++) {
                memo[i][j] = -1;
            }
        }
    }

    private int _tsp(int pos, int visited) {
        if (visited == (1 << n) - 1) {
            return distance[pos][0] != 0 ? distance[pos][0] : INF;
        }

        if (memo[pos][visited] != -1) {
            return memo[pos][visited];
        }

        int ans = INF;
        for (int city = 0; city < n; city++) {
            if ((visited & (1 << city)) == 0 && distance[pos][city] != 0) {
                int newAns = distance[pos][city] + _tsp(city, visited | (1 << city));
                ans = Math.min(ans, newAns);
            }
        }
        return memo[pos][visited] = ans;
    }

    public int findMinCost() {
        return _tsp(0, 1);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the number of cities: ");
        int n = scanner.nextInt();

        int[][] distance = new int[n][n];
        System.out.println("Enter the distance matrix (enter 0 for no path):");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                distance[i][j] = scanner.nextInt();
            }
        }

        tsp tsp = new tsp(distance);
        int minCost = tsp.findMinCost();
        System.out.println("The minimum cost to visit all cities: " + minCost);

        scanner.close();
    }
}
