# Taller 1 del segundo semetre de la Licenciatura en Informatica

La idea esencial del taller 1 es que los participantes del equipo apliquen los 
conocimientos adquiridos en el primer año de la licenciatura para producir un 
sistema capaz de generar secuencias de números naturales mediante comandos en 
la terminal.

## Introduccion al sistema
Se desea desarrollar un aplicación de consola que permita a los estudiantes de matemática 
discreta trabajar con secuencias de números naturales

## Comandos

###Create
Crea una nueva secuencia vacía.
```
create pepe 
// crea la secuencia pepe
```

###Insback
Agrega un nuevo valor al final de una secuencia.
```
insback pepe 4 
// agrega el numero 4 a la secuencia pepe
```

###Show
Muestra por pantalla todas las secuencias existentes.
```
show 
```

###Sum
Calcula la suma de los valores de una secuencia.
```
sum pepe 
// suma los valores de la secuencia pepe
```

###Concat
Crea una nueva secuencia que resulta de la concatenación de otras dos.
```
concat pepe lalo miu  
// se crea la secuencia miu como resultado de la concatenación de pepe y lalo
```

###Reverse
Crea una nueva secuencia que resulta de invertir todos los valores de otra.
```
reverse pepe revil 
// se crea la secuencia revil como resultado de la inversion de la secuencia pepe 
```

###Save
Guarda en archivo una secuencia existente.
```
save pepe secuencia.txt 
// guarda la secuencia pepe en el archivo secuencia.txt 
```

###Load
Recupera a memoria una secuencia previamente guardada en archivo.
```
load mou secuencia.txt 
// se crea la secuencia mou en base a la secuencia guardada en el archivo
```

###Exit
Libera toda la memoria dinámica utilizada y finaliza la ejecución de la aplicación,  
```
exit 
```

 

