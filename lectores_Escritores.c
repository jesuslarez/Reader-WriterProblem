#include <stdlib.h> // Requerido para atoi
#include <stdio.h> // Requerido para printf
#include <errno.h>
#include <pthread.h>
#include "lectores_Escritores.h"

int writting = 0;  //Variable entera que se usara como boleana para Escritura
int queuWri = 0;   //Variable que contendra el numero de escritores en cola
int queuRead = 0;  //Variable qie contendra el numero de lectores en cola
pthread_mutex_t locker = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t done = PTHREAD_COND_INITIALIZER;

//Funcion read que simula leer de una BD
void read(){
  pthread_mutex_lock(&locker);
  while(writting == 1 || queuWri > 0){
    pthread_cond_wait(&done, &locker);
  }
  queuRead++;
  pthread_mutex_unlock(&locker);
  pthread_mutex_lock(&locker);
  printf("Reading\n");
  sleep(1);
  printf("Reading finished\n");
  pthread_mutex_unlock(&locker);
  pthread_mutex_lock(&locker);
  queuRead--;
  pthread_cond_signal(&done);
  pthread_mutex_unlock(&locker);
}

//Funcion Write que simula leer de una BD
void write(){
  pthread_mutex_lock(&locker);
  queuWri++;
  while(queuRead > 0 || writting == 1){
    pthread_cond_wait(&done, &locker);
  }
  writting = 1;
  printf("writting\n");
  sleep(2);
  writting = 0;
  printf("writting finished\n");
  queuWri--;
  pthread_cond_signal(&done);
  pthread_mutex_unlock(&locker);
}
