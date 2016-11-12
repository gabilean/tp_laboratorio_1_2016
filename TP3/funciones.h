#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[4000];
    int estado;
    int id;
}EMovie;

int isEmpty(EMovie movie[], int lenght);
int findMovie(EMovie movie[], int index, int lenght);
void initMovie(EMovie movie[], int lenght);
int menuModifyMovie();
void addMovie(EMovie movie[], int lenght);
void deleteMovie(EMovie movie[], int lenght);
void modifyMovie(EMovie movie[], int lenght);
void showMovie(EMovie movie);
void showMovies(EMovie movie[], int lenght);
void generateWeb(EMovie movie[], int lenght);

void readBin(EMovie movie[], int lenght);
void saveBin(EMovie movie[], int lenght);


int getInt();
float getFloat();
char getChar();

int validaS_N(void);

int esNumerico(char *str) ;
int esTelefono(char *str);
int esAlfaNumerico(char *str);
int esSoloLetras(char *str);
int esNumericoFlotante(char str[]);

void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
void getValidString(char requestMessage[],char errorMessage[], char input[]);


#endif // FUNCIONES_H_INCLUDED
