import java.util.Random;

public class U2 extends Rocket {
    double random = (double)(Math.random() * 101);
    U2(){
        super();
        this.setCost(120000);
        this.setWeight(18000);
        this.setRocketWeight(18000);
        this.setMaxWeight(29000);
        this.setRateExplosion(0.04);
        this.setRateCrash(0.08);
        this.setCargoLimit(11);

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
