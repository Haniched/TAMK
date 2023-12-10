// Define fucntions only using in main.cpp
// Järjestetään mahdollisimman main toiminnon mukaisesti

#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <array>
#include <vector>
#include <cstdlib>
#include <random> // c++20
#include <thread> // display_slowly
#include <chrono> // display_slowly
// #include <limits>

#define TIETOKANTA "hotelli.txt"
#define TALLENNUS ".hotelli.txt"

// structit
struct Vieras {
    std::string nimi, tyyppi;
    int yo;
};

struct huonetiedot {
    int hnum, yo;
    std::string nimi, tyyppi;
};

// funktiot, jotka eivät käytössä fstream
void rivi();
void tulosta (std::string t, bool RIVI);
void tulosta_virhe (std::string tiedoston_nimi);

void display_slowly (const std::string &text);

// Y/N syotto, vahvistuksen varten 
bool vahvistus (std::string viesti);

// Random number generator
int satunnainen_huoneetmaara ();

// huoneen numeron määrittäminen
int huonenumero (int num);

// tästä olevat funktiot käytetään file stream library

// Alunperin kirjoittaa tiedostoon ohjelman ensinmaisessa kaynnistossa
void kirjoitus_tiedot (const std::string &txt, std::vector <huonetiedot> &tieto, int &MAX);
int lukema_numero (const std::string &txt);

// Käyttäjä syötä tiedonsa
// Tarkistaa, että onko käyttäjän tieto on jo talennettu hotellin systeemiin
bool onko_varattu (Vieras &vieras);
bool varaus_nimi (Vieras &vieras);
void varaus (Vieras &vieras);

// 
char taysi (Vieras &vieras);

void kirjoitus_varaus (Vieras& vieras);

// hinta
int lasku (Vieras& vieras);
int alennushinta (int &hinta);