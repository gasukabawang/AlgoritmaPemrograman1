#include "molecule.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define MAX_ATOM_TYPES 20
// #define MAX_SYMBOL_LEN 4

// // Struktur untuk menyimpan informasi satu jenis atom dalam molekul
// typedef struct {
//     char symbol[MAX_SYMBOL_LEN]; // Simbol atom (e.g., "H", "O", "Fe")
//     int count;                   // Jumlah atom jenis ini dalam molekul
// } AtomInfo;

// typedef struct {
//     AtomInfo atoms[MAX_ATOM_TYPES];
//     int numAtomTypes;
// } Molecule;

// --- Implementasi Fungsi ADT Molekul ---

void createMolecule(Molecule *m) {
    m->numAtomTypes = 0;
}

void addAtom(Molecule *m, const char *symbol, int count) {
    for(int i=0; i<m->numAtomTypes; i++){
        if(strcmp(m->atoms->symbol, symbol) == 0){
            m->atoms[i].count += count;
            return;
        }
    }
    if(m->numAtomTypes < MAX_ATOM_TYPES){
        strcpy(m->atoms[m->numAtomTypes].symbol, symbol);
        m->atoms[m->numAtomTypes].count = count;
        m->numAtomTypes++;
    }
}

double getAtomicWeight(const char *symbol) {
    if (strcmp(symbol, "H") == 0)
        return 1.008;
    else if (strcmp(symbol, "He") == 0)
        return 4.0026;
    else if (strcmp(symbol, "Li") == 0)
        return 6.94;
    else if (strcmp(symbol, "C") == 0)
        return 12.011;
    else if (strcmp(symbol, "N") == 0)
        return 14.007;
    else if (strcmp(symbol, "O") == 0)
        return 15.999;
    else if (strcmp(symbol, "F") == 0)
        return 18.998;
    else if (strcmp(symbol, "Ne") == 0)
        return 20.180;
    else if (strcmp(symbol, "Na") == 0)
        return 22.990;
    else if (strcmp(symbol, "Mg") == 0)
        return 24.305;
    else if (strcmp(symbol, "Al") == 0)
        return 26.982;
    else if (strcmp(symbol, "Si") == 0)
        return 28.085;
    else if (strcmp(symbol, "P") == 0)
        return 30.974;
    else if (strcmp(symbol, "S") == 0)
        return 32.06;
    else if (strcmp(symbol, "Cl") == 0)
        return 35.45;
    else if (strcmp(symbol, "Ar") == 0)
        return 39.948;
    else if (strcmp(symbol, "K") == 0)
        return 39.098;
    else if (strcmp(symbol, "Ca") == 0)
        return 40.078;
    else if (strcmp(symbol, "Fe") == 0)
        return 55.845;
    else if (strcmp(symbol, "Au") == 0)
        return 196.967;
    else if (strcmp(symbol, "Br") == 0)
        return 79.904;
    else if (strcmp(symbol, "I") == 0)
        return 126.904;
    return 0.0;
}

double calculateMolecularWeight(const Molecule *m) {
    double weight = 0.0;
    for(int i=0; i<m->numAtomTypes; i++){
        double atomicweight = getAtomicWeight(m->atoms[i].symbol);
        weight += atomicweight*m->atoms[i].count;
    }
    return weight;
}

int getAtomCount(const Molecule *m, const char *symbol) {
    for(int i=0; i<m->numAtomTypes; i++){
        if(strcmp(m->atoms[i].symbol, symbol) == 0){
            return m->atoms[i].count;
        }
    }
    return 0;
}

// --- Fungsi Bantuan untuk qsort jika diperlukan ---
int compareAtomInfo(const void *a, const void *b) {
    AtomInfo *atomA = (AtomInfo *)a;
    AtomInfo *atomB = (AtomInfo *)b;
    return strcmp(atomA->symbol, atomB->symbol);
}

void sortMolecule(Molecule *m) {
    if (m->numAtomTypes > 1) {
        qsort(m->atoms, m->numAtomTypes, sizeof(AtomInfo), compareAtomInfo);
    }
}

bool areEqual(const Molecule *m1, const Molecule *m2) {
    if(m1->numAtomTypes != m2->numAtomTypes){
        return false;
    }
    for(int i=0; i<m1->numAtomTypes; i++){
        bool found = false;
        for(int j=0; j<m2->numAtomTypes; j++){
            if(strcmp(m1->atoms[i].symbol, m2->atoms[j].symbol) == 0 && m1->atoms[i].count == m2->atoms[j].count){
                found = true;
                break;
            }
        }
        if(!found){
            return false;
        }
    }
    return true;
}

Molecule combineMolecules(const Molecule *m1, const Molecule *m2) {
    Molecule result;
    createMolecule(&result);
    for(int i=0; i<m1->numAtomTypes; i++){
        addAtom(&result, m1->atoms[i].symbol, m1->atoms[i].count);
    }
    for(int i=0; i<m2->numAtomTypes; i++){
        addAtom(&result, m2->atoms[i].symbol, m2->atoms[i].count);
    }
    return result;
}

bool canSubtract(const Molecule *m_total, const Molecule *m_sub) {
    for(int i=0; i<m_sub->numAtomTypes; i++){
        int total = getAtomCount(m_total, m_sub->atoms[i].symbol);
        if(total<m_sub->atoms[i].count){
            return false;
        }
    }
    return true;
}

Molecule subtractMolecule(const Molecule *m_total, const Molecule *m_sub) {
    Molecule result;
    createMolecule(&result);
    if(!canSubtract(m_total, m_sub)){
        Molecule temp;
        createMolecule(&temp);
        return temp;
    }
    createMolecule(&result);
    for(int i=0; i<m_total->numAtomTypes; i++){
        addAtom(&result, m_total->atoms[i].symbol, m_total->atoms[i].count);
    }
    for(int i=0; i<m_sub->numAtomTypes; i++){
        for(int j=0; j<result.numAtomTypes; j++){
            if(strcmp(m_sub->atoms->symbol, result.atoms[j].symbol) == 0){
                result.atoms[j].count -= m_sub->atoms[i].count;
                if(result.atoms[j].count == 0){
                    for(int k=j; k<result.numAtomTypes-1; k++){
                        result.atoms[k] = result.atoms[k+1];
                    }
                    result.numAtomTypes--;
                }
                break;
            }
        }
    }
    return result;
}

void printMoleculeFormula(const Molecule *m) {
    // TODO: Implementasikan fungsi ini
    // 1. Jika m->numAtomTypes == 0, cetak "(Kosong)".
    // 2. Urutkan atom berdasarkan simbol untuk output (gunakan fungsi sorting
    // yang sudah diberikan)
    // 3. Cetak formula molekul
    // Contoh output: C6H12O6, H2O, NaCl
    if(m->numAtomTypes == 0){
        printf("(Kosong)\n");
        return;
    }
    Molecule sorted = *m;
    sortMolecule(&sorted);
    for(int i=0; i<sorted.numAtomTypes; i++){
        printf("%s", sorted.atoms[i].symbol);
        if(sorted.atoms[i].count>1){
            printf("%d", sorted.atoms[i].count);
        }
    }
    printf("\n");
}