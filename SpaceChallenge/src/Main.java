import java.util.Scanner;

public class Main {

    public static void main(String [] args) throws Exception {
        Simulation s = new Simulation();

        System.out.print("U1 Rocket with phase 1 -> ");
        System.out.print(s.runSimulation(s.loadU1(s.loadItems(1))));
        System.out.println("");
        System.out.print("U1 Rocket with phase 2 -> ");
        System.out.println(s.runSimulation(s.loadU1(s.loadItems(2))));
        System.out.print("U2 Rocket with phase 1 -> ");
        System.out.println(s.runSimulation(s.loadU2(s.loadItems(1))));
        System.out.print("U2 Rocket with phase 2 -> ");
        System.out.println(s.runSimulation(s.loadU2(s.loadItems(2))));
    }
}
