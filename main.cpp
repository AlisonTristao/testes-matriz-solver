#include <cstdio>
#include <Matrix.hpp>
using namespace std;

// quantidade de vezes q repete o experimento
int qtd_testes = 5, inicio = 0, final = 10, degraus = 10;

// matriz para analise de dados
// col: index_teste, raio, x0, y0, n_pontos, radianos, tempo, ruido, metodo // 9 elementos
Matrix all(qtd_testes*degraus, 9);

int main() {
    // variaveis de cada experimento
    int inicio_pontos = 3, final_pontos = 15, degraus_pontos = 15;  
    float inicio_radianos = 3.1415926/4, final_radianos = 2*3.1415926, degraus_radianos = 7;  
    int inicio_raio = 1, final_raio = 10, degraus_raio = 9;  
    int inicio_xy0 = 0, final_xy0 = 10, degraus_xy0 = 10;  

    for(int index_teste = inicio; index_teste < final; index_teste += (final-inicio/degraus)){
        for(int i = 0; i < qtd_testes; i++){        // repete o mesmo experimento para redundancias
            // dados de cada experimento
            int media, max, min, desv_padrao; 
            // dados do circulo
            int raio, x0, y0;

            // desloca o centro
            for(int desloc_xy = inicio_xy0; desloc_xy < final_xy0; desloc_xy += (inicio_xy0-final_xy0/degraus_xy0)){
                // aumenta o raio
                for(int r = inicio_raio; r < final_raio; r+= (final_raio-inicio_raio/degraus_raio)){
                    // aumenta a circunferencia
                    for(float rad = inicio_radianos; rad < final_radianos; rad += (final_radianos-inicio_radianos/degraus_radianos)){
                        // aumenta a quantidade de pontos
                        for(){
                            
                        }
                    }
                }
            }
            Matrix pontos(n_pontos, 2);


        }
    }
    


    printf("aqui\n");

    return 0;
}
