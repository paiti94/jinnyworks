import java.io.File;
import java.util.Scanner;

public class MovieGame {
    private Scanner scanner = new Scanner(System.in);
    private File file = new File("movies.txt");
    private String[] movies = new String[100];
    private int index = 0;
    private int randomNo;
    private int wrongNo =0;
    private String randomMovie;
    private String guessMovie;
    private char[] checkedletter;
    private char guess;
    private char wrongGuess;
    MovieGame(){

    }
    public void getMovie() throws Exception{
        //Read movie lists from the file and create an array.
        Scanner filescanner = new Scanner(file);
        while(filescanner.hasNextLine()){
            String movie = filescanner.nextLine();
            movies[index] = movie.trim();
            index++;
        }
        filescanner.close();
        //Pick one random movie.
        randomNo = (int)(Math.random() * index);

        randomMovie = movies[randomNo];
        guessMovie = randomMovie.replaceAll("[a-zA-Z0-9]","*");

    }
    public void checkLetter() throws Exception{
             boolean correct = false;
            System.out.println("Guess a letter:");
            guess = scanner.nextLine().charAt(0);
            for (int i = 0; i < randomMovie.length(); i++) {
                if (guess == randomMovie.charAt(i)) {
                    checkedletter = guessMovie.toCharArray();
                    checkedletter[i] = guess;
                    guessMovie = String.valueOf(checkedletter);
                    correct = true;
                }

            }
            if(!correct){
               wrongGuess =guess;
               wrongNo++;
            }

    }
    public void Play() throws Exception{
        getMovie();
        for(int i=10;i>0;i--){
            System.out.println("You are guessing:"+guessMovie);
            System.out.print("You have guessed ("+wrongNo+") wrong letters: "+wrongGuess);

            System.out.println("");
            checkLetter();
            if(guessMovie == randomMovie){
                System.out.println("You win!");
                System.out.println("You have guessed '"+randomMovie+"' correctly.");
                break;
            }
        }
        System.out.println("You lost.....");
    }
}
