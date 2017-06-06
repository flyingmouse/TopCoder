package main;

public class RemovingParenthesis {

    boolean check(String s) {
        int n = s.length();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(') cnt++;
            else cnt--;
            if (cnt < 0) return false;
        }
        return true;
    }

    int count(String s) {
        int n = s.length();
        if (s.equals("()")) return 1;

        int ans = 0;

        for (int i = 1; i < n; i++) {
            if (s.charAt(i) == ')') {
                String t = s.substring(1, i) + s.substring(i + 1);
                if (check(t))
                    ans += count(t);
            }
        }
        return ans;
    }
    public int countWays(String s) {
        return count(s);
    }
}
