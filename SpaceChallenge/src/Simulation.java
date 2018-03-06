import java.util.Scanner;
import java.io.File;
import java.util.ArrayList;

public class Simulation {
    static public int totalBudget=0;
    static public int noOfSucRoc=0;
    static public int noOfFailRoc=0;
    Simulation(){

    }
    public ArrayList<Item> loadItems(int phase) throws Exception{
        String filename ="";
        if(phase == 1){
            filename = "Phase-1.txt";
        }else{
            filename = "Phase-2.txt";
        }
        ArrayList<Item> Items = new ArrayList();
        File file = new File(filename);
        Scanner scanner = new Scanner(file);
        String line;
        while(scanner.hasNextLine()){
            line = scanner.nextLine();
            String [] name= new String[2];
            name = line.split("=");
            int weight = Integer.parseInt(name[1]);

            Item item = new Item(name[0],weight);
            Items.add(item);
        }
        scanner.close();
        return Items;
    }
    public ArrayList<Rocket> loadU1(ArrayList<Item> I){
        ArrayList<Rocket> U1s = new ArrayList<>();
        Rocket u1_1 = new U1();
        int n =1;
        for(Item thisI : I){
            if(u1_1.canCarry(thisI)){
                u1_1.status = "loaded";
                n++;

                u1_1.carry(thisI);
                U1s.add(u1_1);

            }else{
                u1_1 = new U1();
                U1s.add(u1_1);
            }
        }


        return U1s;
}
    public ArrayList<Rocket> loadU2(ArrayList<Item> I2){
        ArrayList<Rocket> U2s = new ArrayList<>();
        Rocket u2_1 = new U2();
        for(Item thisI : I2){
            if(u2_1.canCarry(thisI)){
                u2_1.status = "loaded";

                u2_1.carry(thisI);
                U2s.add(u2_1);
            }else{
                u2_1 = new U2();
                U2s.add(u2_1);
            }
        }
        return U2s;
    }
    public int runSimulation(ArrayList<Rocket> Rs){
        for(int i=0; i< Rs.size()-1; i++){

                totalBudget += Rs.get(i).getCost();

                while (!Rs.get(i).land() || !Rs.get(i).launch()) {

                    totalBudget += Rs.get(i).getCost();
                }

    }
        return totalBudget;
    }
}




























