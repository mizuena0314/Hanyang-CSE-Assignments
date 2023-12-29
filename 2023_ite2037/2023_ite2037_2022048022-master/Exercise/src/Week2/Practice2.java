package Week2;

public class Practice2 {
    public static void main(String[] args){
        String input = "Walt Savitch";
        String output = null;

        int blankpos = input.indexOf(' ');
        String word1 = input.substring(0, blankpos);
        String word2 = input.substring(blankpos+1,input.length());

        word1 = word1.substring(1,word1.length()) + word1.charAt(0) + "ay";
        word2 = word2.substring(1,word2.length()) + word2.charAt(0) + "ay";

        word1.toLowerCase();
        word2.toLowerCase();

        word1 = Character.toUpperCase(word1.charAt(0)) + word1.substring(1, word1.length());
        word2 = Character.toUpperCase(word2.charAt(0)) + word2.substring(1, word2.length());

        output = word1 + " " + word2;

        System.out.println(output);
    }
}
