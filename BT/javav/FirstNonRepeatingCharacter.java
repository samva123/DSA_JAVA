package javav;
import java.util.HashMap;
import java.util.Scanner;

public class FirstNonRepeatingCharacter {
    public static char firstNonRepeatingChar(String s) {
        HashMap<Character, Integer> freq = new HashMap<>();

        for (char c : s.toCharArray()) {
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }

        for (char c : s.toCharArray()) {
            if (freq.get(c) == 1) {
                return c;
            }
        }

        return '\0';
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        sc.close();

        char result = firstNonRepeatingChar(str);

        if (result != '\0') {
            System.out.println("First non-repeating character: " + result);
        } else {
            System.out.println("No non-repeating character found");
        }
    }
}
