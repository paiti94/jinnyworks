import java.util.Random;

public class Rocket implements SpaceShip {
    private int Rocketcost;
    private int Rocketweight;
    private int maxWeight;
    private int cargoCarried;
    private int weight;
    private int cargoLimit;
    private double rateExplosion;
    private double rateCrash;
    private double chanceExplosion;
    private double chanceCrash;
    public String status;



    public void setCost(int c){
        this.Rocketcost = c;
    }
    public void setRocketWeight(int w){
        this.Rocketweight= w;
    }
    public void setWeight(int W){
        this.weight = W;
    }
    public void setMaxWeight(int m){
        this.maxWeight = m;
    }
    public void setCargoLimit(int l){
        this.cargoLimit = l;
    }
    public void setRateExplosion(double e){
        this.rateExplosion = e;
    }
    public void setRateCrash(double c){
        this.rateCrash = c;
    }
    public void setChanceExplosion(){
        this.chanceExplosion = this.rateExplosion * (this.cargoCarried / this.cargoLimit);
    }
    public void setChanceCrash(){
        this.chanceCrash = this.rateCrash * (this.cargoCarried / this.cargoLimit);
    }
    public int getCost(){
        return this.Rocketcost;
    }
    public int getRocketWeight(){
        return this.Rocketweight;
    }
    public int getWeight(){
        return this.weight;
    }
    public int getMaxWeight(){
        return this.maxWeight;
    }
    public int getCargoLimit(){
       return this.cargoLimit;
    }
    public double getChanceExplosion(){
        return this.chanceExplosion;
    }
    public double getChanceCrash(){
        return this.chanceCrash;
    }
    public Rocket(){}
    @Override
    public boolean launch() {
        return true;
    }

    @Override
    public boolean land() {
        return true;
    }

    @Override
    final public boolean canCarry(Item I) {
        if((this.weight+I.weight) < this.maxWeight){
            return true;
        }else{
            return false;
        }
    }

    @Override
    final public void carry(Item I) {
        this.weight += I.weight;
        this.cargoCarried = this.weight - this.Rocketweight;
    }
}
