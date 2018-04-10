/*
Examen Segundo Parcial, Programación Avanzada
Autor: Mark Octavio Rivera Acosta
Id: A01630250

No hay indicación acerca de: 
    Puede ser en el lenguaje de programación que sea.
    No es necesario código, puede ser pseudocódigo.

Sentence: 
    You are given an integer N, followed by N lines of input (1 <= N <= 100). 
    Each line of input contains one or several words separated with single spaces. 
    Each word is a sequence of letters of English alphabet containing between 1 and 10 characters, inclusive. 
    The total number of words in the input is between 1 and 100, inclusive.

Objective:
    Your task is to reverse the order of words in each line of input, while preserving the words themselves. 
    The lines of your output should not have any trailing or leading spaces.

Example:
    input
        3
        Hello World
        Bye World
        Useless World
    output
        World Hello
        World Bye
        World Useless

Solución: 
    Para mí este es un problema que se resuleve utilizando 
        - Cadenas 
        - Caracteres
        - Arreglos
        - Métodos de entrada y de salida.
    
    Los pasos que considero necesarios a seguir son los siguientes:

        Se le puede preguntar al usuario los datos en consola o leerlos desde un archivo de texto.

        1.  Preguntar al usuario cuántas líneas va a escribir. 
            En este punto se valida:
                -   El número que dé el usuario se encuentre entre 0 y 101. Si el número cumple con el requisito, 
                    pasa al siguiente paso; si no es así, se le pide al usuario que ingrese un número válido o se termina el programa
                    arrojando un error.
        2.  Pedir al usuario que escriba sus líneas.
            En este punto se valida:
                -   Que el número de palabras por línea sea mayor a 0 y menor que 101. 
                    De no ser así, se le pide al usuario que modifique la línea y termina el programa.
                -   Para cada palabra se tiene que revisar que no contenga una cantidad de caracteres entre 0 y 11.
                    De no ser así, se le muestra al usuario la primer palabra que se encontró con el error y se le pide que la cambie o quite.
                -   Que cada palabra esté separada sólo por un espacio en blanco y que al final o inicio de la línea no haya ningún espacio.
                    a. De no ser así, se le indica al usuario que hay un doble espacio y en qué línea.
                    b. De no ser así, se remueve un espacio y se continua con la ejecución.
                -   Que todos los caracteres utilizados se encuentren dentro del alfabeto inglés (aA-zZ).
                    De no ser así, se le muestra al usuario la primer palabra que se encontró con el error y se le pide que la cambie o quite.
        3.  Por cada línea se realiza lo siguiente:
                - Un String que contenga toda la cadena de palabras.
                - Un arreglo de strings.
                - Se parte el string basado en los espacios en blanco, separando todas las palabras.
                - Estos 'pedazos' se guardan en el arreglo de strings
                - Se recorre el arreglo de manera inversa y se van imprimiendo las palabras que se encuentre concatenándolas en una sola línea
                    con espacios en blanco, a menos que sea la última palabra, que iría sin espacio al final.
*/

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class ReverseWords {
	public static void main(String[] args) {
		int numberOfLines = 0;
		int contadorDeLinea = 1;
		String reverseLine = "";
		BufferedReader lectorDeLineas;
		try {
			lectorDeLineas = new BufferedReader(new FileReader("sample-Reverse.3.in.txt"));
			BufferedWriter writer = new BufferedWriter(new FileWriter("sample-Reverse.out.3.txt"));
			String primeraLinea = lectorDeLineas.readLine();
			numberOfLines = Integer.parseInt(primeraLinea);

			if (numberOfLines >= 1 && numberOfLines <= 100) {

				for (int i = 0; i <= numberOfLines; i++) {
					String linea = lectorDeLineas.readLine();

					if (linea != null) {
						String[] arregloDePalabras = linea.split(" ");

						if (arregloDePalabras.length <= 100 && arregloDePalabras.length >= 1) {

							for (int j = arregloDePalabras.length - 1; j >= 0; j--) {

								if (arregloDePalabras[j].length() <= 10 && arregloDePalabras[j].length() >= 1 && revisarPalabraDentroDelLenguaje(arregloDePalabras[j])) {
									

									if (j != 0) {
										reverseLine += arregloDePalabras[j] + " ";
										
									} else {
										reverseLine += arregloDePalabras[j] + "\n";
										
									}

								} else if (arregloDePalabras[j].length() > 10) {
									System.out.println("palabra " + arregloDePalabras[j] + " está muy larga");
									System.exit(1);
								}

								else if (arregloDePalabras[j].length() < 1) {
									System.out.println("palabra " + arregloDePalabras[j] + " está muy larga");
									System.exit(1);
								}
								else if (!revisarPalabraDentroDelLenguaje(arregloDePalabras[j])) {
									System.out.println("palabra " + arregloDePalabras[j] + " tiene un caracter inválido");
									System.exit(1);
								}

							}
							
						} else if (arregloDePalabras.length > 100) {
							System.out.println("La linea " + contadorDeLinea + " tiene muchas palabras: "
									+ arregloDePalabras.length);
							System.exit(1);

						} else if (arregloDePalabras.length < 1) {
							System.out.println("La linea " + contadorDeLinea + " tiene muy pocas palabras: "
									+ arregloDePalabras.length);
							System.exit(1);
						}
					}
					contadorDeLinea++;
				}
				writer.write(reverseLine);
			}
			
			lectorDeLineas.close();
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static boolean revisarPalabraDentroDelLenguaje(String s) {
		
		char[] caracteresDePalabra = s.toCharArray();
		
		boolean palabraPertenece = false;
		
		for (int i = 0; i < caracteresDePalabra.length; i++) {
			char c = caracteresDePalabra[i];
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
				palabraPertenece = true;
				}
		}
		return palabraPertenece;
	}
}
