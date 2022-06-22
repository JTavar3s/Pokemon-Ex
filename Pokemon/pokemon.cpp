#include <iostream>
#include <cstring>

using namespace std;

void calcula_LPS(int lps[], char P[], int tamP)
{
    
    int tam = 0;
    
    lps[0] = 0; 
    
     
    int i = 1; 
    while (i < tamP)
    { 
        if (P[i] == P[tam]) 
        {
            tam++; 
            lps[i] = tam; 
            i++; 
        } 
        else 
        {
            if (tam != 0) 
            {
                tam = lps[tam - 1];
            }
            else 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    }            
}

void kmp(char T[], char P[],int tamT, int tamP, int &cont)
{
    int lps[tamP]; 
                  
    cont = 0;
    calcula_LPS(lps, P, tamP);
    
    int j = 0; 
    int i = 0; 
    while(i < tamT)
    {
        if(T[i] == P[j]) 
        {
            j++;
            i++;
            if(j == tamP) 
            {
                   cont++;
                   j = lps[j-1];
               }
        }
        else 
        {
            if(j != 0) 
                j = lps[j-1];
            else 
                i++;
        }
        
    }
}

int main(){
    char Tex[300]= "(POKEMON! TEMOS QUE PEGAR) ISSO EU SEI PEGA-LOS EU TENTAREI! (POKEMON!) JUNTOS TEREMOS QUE O MUNDO DEFENDER! POKEMON! (TEMOS QUE PEGA-LOS) ISSO EU SEI PEGA-LOS EU TENTAREI VAI SER GRANDE A EMOCAO POKEMON! TEMOS QUE PEGAR TEMOS QUE PEGAR!";
    char Pok[100];
    int cont=0;

    cin.getline(Pok,100);
    while(Pok[0] != '1'){
        kmp(Tex, Pok,strlen(Tex),strlen(Pok),cont);
        if(cont == 0){
            cout << Pok << " NAO APARECE NA MUSICA" << endl;
        }
        else if(cont == 1){
            cout << Pok << ": " << cont << " VEZ" << endl;
        }
        else cout << Pok << ": " << cont << " VEZES" << endl;
        
        cin.getline(Pok,100);
    }
    
    return 0;
}