//Archivos cabecera del sistema
#include <stdlib.h> // Requerido para atoi
#include <stdio.h> // Requerido para printf
#include <errno.h>
#include <pthread.h>
#include "lectores_Escritores.h"

//Test de lectores_Escritores 

void test_Lectores_Escritores(){

  // Hilo readerOne: Lee de la BD
  pthread_t *readerOne;

  //Hilo readerTwo: Lee de la BD
  pthread_t *readerTwo;

 // Hilo readerThree: Lee de la BD
  pthread_t *readerThree;

 // Hilo readerFour: Lee de la BD
  pthread_t *readerFour;

//  Hilo writterOne: Lee de la BD
  pthread_t *writterOne;

 // Hilo writterTwo: Lee de la BD
  pthread_t *writterTwo;

  int ret;
  void* dummy;

  readerOne = malloc(sizeof(pthread_t));
  readerTwo = malloc(sizeof(pthread_t));
  readerThree = malloc(sizeof(pthread_t));
  readerFour = malloc(sizeof(pthread_t));
  writterOne = malloc(sizeof(pthread_t));
  writterTwo = malloc(sizeof(pthread_t));

//Se lanzan los Hilos Readers y Writers (Lectores y Escritores)

  ret = pthread_create(&readerOne, NULL, read, NULL);
  if (ret) {
      errno=ret;
      fprintf(stderr,"error %d: %s\n",errno,strerror(errno));
    exit(-1);
  }

  ret = pthread_create(&writterOne, NULL, write, NULL);
  if (ret) {
      errno=ret;
      fprintf(stderr,"error %d: %s\n",errno,strerror(errno));
    exit(-1);
  }

  ret = pthread_create(&readerTwo, NULL, read, NULL);
  if (ret) {
      errno=ret;
      fprintf(stderr,"error %d: %s\n",errno,strerror(errno));
    exit(-1);
  }

  ret = pthread_create(&readerThree, NULL, read, NULL);
  if (ret) {
      errno=ret;
      fprintf(stderr,"error %d: %s\n",errno,strerror(errno));
    exit(-1);
  }

  ret = pthread_create(&readerFour, NULL, read, NULL);
  if (ret) {
      errno=ret;
      fprintf(stderr,"error %d: %s\n",errno,strerror(errno));
    exit(-1);
  }

  ret = pthread_create(&writterTwo, NULL, write, NULL);
  if (ret) {
      errno=ret;
      fprintf(stderr,"error %d: %s\n",errno,strerror(errno));
    exit(-1);
  }
//Se hacen los Join de los hilos 
  
  ret=pthread_join(readerOne,&dummy);
  if (ret) {
    errno=ret;
    fprintf(stderr,"Error %d en el join del hilo readerOne %d: %s\n",errno,strerror(errno));
    exit(-1);
  }

  ret=pthread_join(readerTwo,&dummy);
  if (ret) {
    errno=ret;
    fprintf(stderr,"Error %d en el join del hilo readerTwo %d: %s\n",errno,strerror(errno));
    exit(-1);
  }

  ret=pthread_join(readerThree,&dummy);
  if (ret) {
    errno=ret;
    fprintf(stderr,"Error %d en el join del hilo readerThree %d: %s\n",errno,strerror(errno));
    exit(-1);
  }

  ret=pthread_join(readerFour,&dummy);
  if (ret) {
    errno=ret;
    fprintf(stderr,"Error %d en el join del hilo readerFour %d: %s\n",errno,strerror(errno));
    exit(-1);
  }

  ret=pthread_join(writterOne,&dummy);
  if (ret) {
    errno=ret;
    fprintf(stderr,"Error %d en el join del hilo writterOne %d: %s\n",errno,strerror(errno));
    exit(-1);
  }

  ret=pthread_join(writterTwo,&dummy);
  if (ret) {
    errno=ret;
    fprintf(stderr,"Error %d en el join del hilo writterTwo %d: %s\n",errno,strerror(errno));
    exit(-1);
  }
}

//Funcion main:
//Ejecuta la pruebas de Lectores y Escritores
//Solo se lanzaran 4 lectores y 2 escritores para evitar bucle infinito
void main(){

  printf("////Comienza la prueba de Lectores y Escritores...\n");

  test_Lectores_Escritores();

  printf("////Termina la prueba de Lectores y Escritores...\n");
}