package javav;
import java.util.*;

public class Main {
    public static int func(List<Integer> v, int k) {
        Map<Integer, Integer> mpp = new HashMap<>();
        int count = 0;

        for (int num : v) {
            int need = k - num;

            if (mpp.containsKey(need)) {
                count += mpp.get(need);
            }

            mpp.put(num, mpp.getOrDefault(num, 0) + 1);
        }

        return count;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        List<Integer> v = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            v.add(scanner.nextInt());
        }

        int k = scanner.nextInt();
        System.out.println(func(v, k));

        scanner.close();
    }
}
