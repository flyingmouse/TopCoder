package main;

public class RangeEncoding {
    public int minRanges(int[] arr) {
        int n = arr.length;
        int a = arr[0], ans = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] == a + 1) a++;
            else {
                ans++;
                a = arr[i];
            }
        }
        return ans;
    }
}
