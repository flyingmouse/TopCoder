package main;

public class Saleswoman {
    public int minMoves(int[] pos, int[] delta) {
        int n =  pos.length;

        int ans = 0;
        int supply = 0;
        int prev = -1;

        int right = 0;
        while (right < n) {
            for (int i = right; i < n; i++) {
                supply += delta[i];
                if (supply >= 0) {
                    right = i;
                    break;
                }
            }
            int p = (prev == -1) ? 0 : pos[prev];
            ans += pos[right] - p + 2 * (pos[right] - pos[prev + 1]);
            prev = right++;
        }
        return ans;
    }
}
