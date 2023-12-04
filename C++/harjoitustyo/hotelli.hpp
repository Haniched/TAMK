#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <array>
#include <vector>
#include <cstdlib>
#include <random>

#define HUONEINFO_FILE "hotelli.txt"

struct Vieras {
    std::string nimi, huonetyyppi;
    int huoneenmaara, yonmaara;
};

struct huonetiedot {
    int hnum;
    std::string vieras;
    char yksi_pari;
};

void rivi();
void tulosta (std::string t, bool RIVI);
void tulosta (std::string t, int& n, bool RIVI);

// kysyy käyttäjälle, haluaako varata vai ei
bool vahvistus (std::string viesti);

// Satunnainen hotellin huoneiden kokonaismäärän generaattori parillinen luku välillä 40 - 300
int satunnainen_huoneetmaara ();

// huoneen numeron määrittely 
int huonenumero (int& num);

// kirjoitettu tiedoston sisällön tarkistus
bool tiedoston_tarkistus (const std::string& tiedosto);

// kirjoittaa tiedostoon
void kirjoitus_tiedot (const std::string &tiedosto, std::vector <huonetiedot> &tieto, int &MAX);

int lukema_numero (const std::string& tiedosto);

// Käyttäjä syötä tiedonsa
void varaus (Vieras &vieras);

// Tarkistaa, että onko käyttäjän tieto on jo talennettu hotellin systeemiin
bool Vieras_tarkistus (const std::string &tiedosto, Vieras &vieras);

// alennus
int alennus (int& hinta);