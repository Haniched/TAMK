// Define fucntions only using in main.cpp

#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <array>
#include <vector>
#include <cstdlib>
#include <random>
#include <thread>
#include <chrono>
#include <limits>

#define TIETOKANTA "hotelli.txt"
#define TALLENNUS ".hotelli.txt"

struct Vieras {
    std::string nimi, tyyppi;
    int yo;
};

struct huonetiedot {
    int hnum, yo;
    std::string nimi, tyyppi;
};

static std::string sym_to_typ(std::string tyyppi);

void rivi();
void tulosta (std::string t, bool RIVI);
void tulosta (std::string t, int& n, std::string s, bool RIVI);
void tulosta_virhe (std::string tiedoston_nimi);

// kysyy käyttäjälle, haluaako varata vai ei
bool vahvistus (std::string viesti);

bool varattu (Vieras &vieras);

// Satunnainen hotellin huoneiden kokonaismäärän generaattori parillinen luku välillä 40 - 300
int satunnainen_huoneetmaara ();

// huoneen numeron määrittely 
int huonenumero (int num);

// kirjoittaa tiedostoon
void kirjoitus_tiedot (const std::string &txt, std::vector <huonetiedot> &tieto, int &MAX);
int lukema_numero (const std::string &txt);

// Käyttäjä syötä tiedonsa
void varaus (Vieras &vieras);

std::string get_nth_column (std::string line, int n);

// Tarkistaa, että onko käyttäjän tieto on jo talennettu hotellin systeemiin
void kirjoitus_varaus (Vieras& vieras);

// alennus
int lasku (Vieras& vieras);