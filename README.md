### micro_paint
Cree un programa con fopen, fread, fscanf, fcloase, realloc, calloc, malloc,
free, write, memset, powf, sqrtf que pinte rectángulos siguiendo las órdenes
de un "archivo de operaciones" de la forma:  
	WIDT HEIGHT BACKGROUND_CHARACTER  
	operation  
	.  
	.  
	.  
	operation (salto de línea final posible)  
Las operaciones son de la forma:  
	R(ó r) X Y WIDTH HEIGHT CHAR  
Las coordenadas se refieren siempre a la esquina superior izquierda de cada
char en el array. Se redondean hacia abajo. Un '0' en WIDTH o HEIGHT es un error.

-  Devuelve '0' si no ha habido errores.
-  Devuelve '1' si ha habido errores.
	-  Si fue leyendo el archivo de operaciones, imprime Error: Operation file corrupted.
	-  Si fue por dar mal los argumentos al programa, imprime Error: argument.
