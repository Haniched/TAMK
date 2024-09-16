// import java.lang.arrayList;

class public main {
    public static void main (String args[]){
        Henkilo macero = new Henkilo("Macero", 27);
        macero.tulostaTiedot();
    }
}

class Henkilo {
    private String nimi;
    private int ika;
    private Osoite kotiosoite;

    public Henkilo(String nimi, int ika){
        this.nimi = nimi;
        this.ika = ika;
    }

    public String getNimi(){
        return nimi;
    }

    public void setNimi(String nimi) {
        this.nimi = nimi;
    }

    public void tulostaTiedot() {
        System.out.println("Nimi: " + nimi);
        System.out.println("Ika" + ika);
    }
}

class Opiskelija extends Henkilo {
    private int opintopisteet;
    private String koulutusala;

    Opiskelija (String nimi, int ika, String koulutusala){
        super(nimi,ika); // Henkilo- luokan rakentaja
    }

    @Override
    public void tulostaTiedot(){

    }
}