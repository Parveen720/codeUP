import java.util.*; // Required for Scanner and ArrayList

public class ASSIGNMENT_01 {
    String str = "";

    // 1 Append
    void append(String newstring) {
        System.out.println("New string after append operation is:");
        str += newstring;
        System.out.println(str);
    }

    // 2 Count characters
    void countWord1() {
        int count1 = 0;
        for (int i = 0; i < str.length(); i++) {
            count1++;
        }
        System.out.println("Character count: " + count1);
    }

    // 3 Split
    void split() {
        String word1 = "";
        ArrayList<String> vec = new ArrayList<>();

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (ch != ' ' && ch != '\t') {
                word1 += ch;
            } else {
                if (word1.length() > 0) {
                    vec.add(word1);
                    word1 = "";
                }
            }
        }

        // Add last word if it exists
        if (word1.length() > 0) {
            vec.add(word1);
        }

        // Print all words
        System.out.println("Words in the string:");
        for (String w : vec) {
            System.out.println(w);
        }
    }

    // 4 Palindrome check
    boolean isPalindrome() {
        int left = 0;
        int right = str.length() - 1;
        while (left <= right) {
            if (str.charAt(left) != str.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    // 5 Splice (remove substring of given length starting from index)
    void splice(int start, int len) {
        if (start < 0 || start + len > str.length()) {
            System.out.println("Invalid range for splice operation!");
            return;
        }
        String ans = str.substring(0, start) + str.substring(start + len);
        str = ans;
        System.out.println("New string after splicing: " + str);
    }

    // 6 Max repeating character
    void maxRepeat() {
        int freq[] = new int[256]; // supports all ASCII characters

        for (int i = 0; i < str.length(); i++) {
            freq[str.charAt(i)]++;
        }

        int maxFrequency = 0;
        char maxFreqChar = '\0';

        for (int i = 0; i < freq.length; i++) {
            if (freq[i] > maxFrequency) {
                maxFrequency = freq[i];
                maxFreqChar = (char) i;
            }
        }

        System.out.println("The max frequency character is: " + maxFreqChar);
    }

    // 7 Sort characters
    void sort() {
        char[] chars = str.toCharArray();
        Arrays.sort(chars);
        str = new String(chars);
        System.out.println("Sorted string is: " + str);
    }

    // 8 Shift (rotate string)
    void shift(int n) {
        if (n < 0 || n > str.length()) {
            System.out.println("Invalid shift value!");
            return;
        }
        String str1 = str.substring(0, n);
        String str2 = str.substring(n);
        str = str2 + str1;
        System.out.println("New shifted string is: " + str);
    }

    // 9 Reverse
    void reverse() {
        StringBuilder reverse = new StringBuilder(str);
        str = reverse.reverse().toString();
        System.out.println("The reversed string is: " + str);
    }

    //10 Replace substring
    void replaceSubstring(String A, String B) {
        str = str.replace(A, B);
        System.out.println("Current string: " + str);
    }

    //  Main method
    public static void main(String[] args) {
        ASSIGNMENT_01 obj = new ASSIGNMENT_01();
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the string:");
        obj.str = sc.nextLine();

        while (true) {
            System.out.println("\nSelect Operation");
            System.out.println("1.Append\n2.Count Characters\n3.Replace\n4.isPalindrome\n5.Splice\n6.Split\n7.MaxRepeatingCharacter\n8.Sort\n9.Shift\n10.Reverse\n11.Exit");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    System.out.println("Enter string to append:");
                    String temp = sc.nextLine();
                    obj.append(temp);
                    break;
                case 2:
                    obj.countWord1();
                    break;
                case 3:
                    System.out.println("Enter substring to replace:");
                    String first = sc.nextLine();
                    System.out.println("Enter new substring:");
                    String second = sc.nextLine();
                    obj.replaceSubstring(first, second);
                    break;
                case 4:
                    boolean target = obj.isPalindrome();
                    if (!target)
                        System.out.println("The string is NOT a palindrome.");
                    else
                        System.out.println("The string is a palindrome.");
                    break;
                case 5:
                    System.out.println("Enter starting index:");
                    int start = sc.nextInt();
                    System.out.println("Enter length to remove:");
                    int len = sc.nextInt();
                    sc.nextLine();
                    obj.splice(start, len);
                    break;
                case 6:
                    obj.split();
                    break;
                case 7:
                    obj.maxRepeat();
                    break;
                case 8:
                    obj.sort();
                    break;
                case 9:
                    System.out.println("Enter number of characters to shift:");
                    int n = sc.nextInt();
                    sc.nextLine();
                    obj.shift(n);
                    break;
                case 10:
                    obj.reverse();
                    break;
                case 11:
                    System.out.println("Exiting program...");
                    sc.close();
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice. Try again.");
            }
        }
    }
}

