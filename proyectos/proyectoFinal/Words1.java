import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

class Words1 {
    static final int SIZE = 26;
    static BufferedReader input;
    static boolean[][] areConnected = new boolean[SIZE][SIZE];
    static int[] start_array = new int[SIZE], end_array = new int[SIZE];
    static boolean[] visitado = new boolean[SIZE];

    public static void init() {
        Arrays.fill(start_array, 0);
        Arrays.fill(end_array, 0);
        Arrays.fill(visitado, false);
        for (int i = 0; i < SIZE; i++)
            Arrays.fill(areConnected[i], false);
    }

    public static boolean checkConnectionForWords() {
        boolean checkDone = false;
        for (int i = 0; i < SIZE; i++) {
            if (!checkDone && start_array[i] > 0) {
                dfs(i);
                checkDone = true;
            } else if (start_array[i] > 0 && !visitado[i]) {
                return false;
            }
        }
        return true;
    }

    public static void dfs(int el) {
        for (int i = 0; i < SIZE; i++) {
            if ((areConnected[el][i] || areConnected[i][el]) && !visitado[i]) {
                visitado[i] = true;
                dfs(i);
            }
        }
    }

    public static void main(String[] args) throws Exception {
        input = new BufferedReader(new InputStreamReader(System.in));
        int testCases = Integer.parseInt(input.readLine());
        for (int cas = 1; cas <= testCases; cas++) {
            int wordsPerCase = Integer.parseInt(input.readLine());
            init();
            for (int i = 0; i < wordsPerCase; i++) {
                String s = input.readLine();
                int st = s.charAt(0) - 'a';
                start_array[st]++;
                int end = s.charAt(s.length() - 1) - 'a';
                end_array[end]++;
                areConnected[st][end] = true;
            }
            if (!checkConnectionForWords()) {
                System.out.println("The door cannot be opened.");
            } else {
                int total = 0;
                for (int i = 0; i < 26 && total <= 2; i++) {
                    int diff = Math.abs(start_array[i] - end_array[i]);
                    total += diff;
                }
                if (total <= 2)
                    System.out.println("Ordering is possible.");
                else
                    System.out.println("The door cannot be opened.");
            }
        }
    }
}