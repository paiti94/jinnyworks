import java.util.Random;

public class U1 extends Rocket {
    double random = (double)(Math.random() * 101);
    U1(){
        super();
        this.setCost(100000);
        this.setRocketWeight(10000);
        this.setWeight(10000);
        this.setMaxWeight(18000);
        this.setRateExplosion(0.05);
        this.setRateCrash(0.01);
        this.setCargoLimit(8);

    }
        public boolean land(){
            int randNo = (int) Math.floor(Math.random() * 101);
            this.setChanceCrash();
            return (this.getChanceCrash()) < randNo;

        }
        public boolean launch(){
            this.setChanceExplosion();
            int randNo = (int) Math.floor(Math.random() * 101);
            return (this.getChanceExplosion()) < randNo;
        }
    }

