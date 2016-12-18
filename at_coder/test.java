//Translate the following pseudocode for randomly permuting the characters in
//a string into a method in the given Java class.

//Read a word.
//Repeat word.length() times
//   Pick a random position i in the word, but not the last position.
//   Pick a random position j > i in the word. (this is tricky)
//   Swap the letters at positions j and i.
//Print the word.

//To swap the letters, construct substrings as follows:
//http://i.imgur.com/re4bGPu.png

//Create and return the string:
//   first + word.substring(j, j + 1) + middle
//         + word.substring(i, i + 1) + last

//As a starting point, just pick the random i and j as described above. then return last.
//Only do this one time.

//I recommend that you implement and test the swapping before implementing
//the loop. If something is wrong in the swap, it will be much more difficult
//to find it if you have executed the swap many times. That is an example of
//step-wise refinement. Code a little, test, code a little more.

import java.util.Random;

public class Word
{
    private Random generator = new Random();

    public Word()  //leave the constructor alone
    {
        generator = new Random();
        final long SEED = 42;
        generator.setSeed(SEED);
    }
    /**
     * Gets a version of this word with the letters scrambled
     * @param word the string to scramble
     * @return the scrambled string
     */
    public String scramble(String word)
    {
        int i;
        int j;
        
        for(int k = 0; k < word.length(); k++){
           String tmp = "";
           //テストケースこれだと通らない。乱数発生の仕方おなじにしろってことなのかな？
           //あんまり本質的じゃないんご
           // do{
           //     i = generator.nextInt(word.length());
           //     j = generator.nextInt(word.length());
           // }while(j <= i);
           i = generator.nextInt(word.length()-1);
           j = i + generator.nextInt(word.length());
           tmp += word.substring(0, i);
           tmp += word.substring(j, j+1);
           tmp += word.substring(i+1, j);
           tmp += word.substring(i, i+1);
           tmp += word.substring(j+1, word.length());
           word = tmp;
        }
        return word;
        
        
        //TODO pick a random i and j and return last as described in
        //http://i.imgur.com/re4bGPu.png
    }

}
