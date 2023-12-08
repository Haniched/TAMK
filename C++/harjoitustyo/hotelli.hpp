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
#include <random>
#include <thread>
#include <chrono>
#include <limits>

#define TIETOKANTA "hotelli.txt"
#define TALLENNUS ".hotelli.txt"

// elements
struct Vieras {
    std::string nimi, tyyppi;
    int yo;
};

struct huonetiedot {
    int hnum, yo;
    std::string nimi, tyyppi;
};

static std::string sym_to_typ(std::string tyyppi);

// funktiot, does not use file input/output stream
void rivi();
void tulosta (std::string t, bool RIVI);
void tulosta (std::string t, int &n, std::string s, bool RIVI);
void tulosta_virhe (std::string tiedoston_nimi);

// Y/N syotto, vahvistuksen varten 
bool vahvistus (std::string viesti);

// Random number generator
int satunnainen_huoneetmaara ();

// 룸 넘버 생성하기 (저장된 벡터를 101호, 102호 이런식으로)
int huonenumero (int num);

// 여기서부터 file stream library

// Alunperin kirjoittaa tiedostoon ohjelman ensinmaisessa kaynnistossa
void kirjoitus_tiedot (const std::string &txt, std::vector <huonetiedot> &tieto, int &MAX);
int lukema_numero (const std::string &txt);

// Käyttäjä syötä tiedonsa
// Tarkistaa, että onko käyttäjän tieto on jo talennettu hotellin systeemiin
bool onko_varattu (Vieras &vieras);
bool varaus_nimi (Vieras &vieras);
void varaus (Vieras &vieras);

std::string taysi (Vieras &vieras);

void kirjoitus_varaus (Vieras& vieras);

// hinta
int lasku (Vieras& vieras);
int alennushinta (int &hinta);