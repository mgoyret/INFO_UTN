/**
 * \file            info.h
 * \brief           Biblioteca para el manejo de archivos del curso R1042 de Informática I
 * \author          Marcos Goyret, agreguen nombres
 * \date            Ago 02, 2019
 * \details         Usar makefile para compilar y linkear (build)
 */

#ifndef INFO_H_
#define INFO_H_

#define EXITO  0
#define ERROR -1

int abrir_archivo(char* nombreArchivo);
int leer_linea(char* linea);
int escribir_linea(char* linea);
void ir_inicio_archivo();
void cerrar_archivo();

#endif /* INFO_H_ */
