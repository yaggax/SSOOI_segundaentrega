# SSOOI_segundaentrega
 

 El programa que hay que presentar constará de un único fichero fuente de nombre dom.c. La correcta compilación de dicho programa, producirá un fichero ejecutable, cuyo nombre será obligatoriamente dom. Respetad las mayúsculas/minúsculas de los nombres, si las hubiere.

La ejecución del programa creará una serie de procesos cuya vida simulará la caída de una ristra de fichas de dominó. En concreto, el árbol de procesos que hay que crear es el siguiente:



Los procesos han sido colocados para reflejar la colocación espacial de las fichas que representan. Las relaciones paterno-filiales son las indicadas por las líneas sólidas. El valor y el orden de los PIDs puede variar. Lo último es debido al reparto de CPU de cada ejecución.

Los procesos, una vez creados, deben permanecer bloqueados, sin consumir CPU. Cuando se mande la señal SIGTERM al proceso original, se originará una cascada de señales que, al final, deberán resultar en la finalización de todos los procesos. Siendo más específicos, las señales que se deben mandar son las indicadas en la siguiente figura:



Por ejemplo, cuando el proceso 38 recibe la señal del 37, antes de morir, debe mandar la señal SIGTERM al 39. Y todos así. Nótese que el 51, el 53 y el 55 se encargan de matar a procesos que no son sus hijos. Para ello, deben conocer el PID de las víctimas. Para que los procesos puedan comunicarse entre sí, debéis usar un único fichero proyectado en memoria. Dicho fichero será único y servirá para transmitir cualquier información entre procesos, su formato es libre y sólo se podrá usar mediante proyección en memoria.

Si se requiere sincronizar alguna acción, se pueden usar señales, pero la espera se debe realizar sin consumo de CPU. Para simplificar el problema, podéis suponer que al ser mandada la señal inicial manualmente, ya ha habido tiempo suficiente para que todos los procesos hayan sido creados para cuando el primer proceso la reciba. Sin embargo, esta concesión en aras de la simplificación, no implica suponer ninguna condición, incluso ésta, en ninguna otra parte de la práctica.

Para ver si habéis conseguido crear el árbol de procesos correctamente, podéis descargaros el siguiente ejecutable: Arbol_dominO. No os va a funcionar en Linux, pues es un ejecutable binario. Desde el servidor, para ver el árbol de procesos que habéis generado, usad la orden: ps -f | grep "dom$" | grep -v grep | sort | Arbol_dominO. Si os aparece el mensaje "Árbol con múltiples raíces. Se aborta.", significa que habéis corrido varias veces vuestra práctica sin matar los procesos de la anterior. Esta puede ser una salida correcta del programa:
         19417
           |
         19418
           |
         19419
     /¯¯¯¯¯¯¯¯¯¯¯\
   19420       19428
  /¯¯¯¯¯\     /¯¯¯¯¯\
19421 19429 19430 19436
  |     |     |     |
19422 19431 19432 19437
  |     |     |     |
19423 19433 19434 19438
  |           |
19424       19435
  |
19425
  |
19426
  |
19427
En el caso de Linux, podéis usar la opción -f de la orden ps.

Restricciones
Se deberán usar llamadas al sistema siempre que sea posible, a no ser que se especifique lo contrario.
No está permitido usar la función de biblioteca system, salvo indicación explícita en el enunciado de la práctica.
Para generar el árbol de procesos, no se usarán llamadas al sistema de la familia exec.
No se puede suponer que los PIDs de los procesos de una ristra van a aparecer consecutivos. Puestos en plan exquisito, ni siquiera podemos suponer que estarán ordenados de menor a mayor (puede ocurrir que se agoten los PIDs y retome la cuenta partiendo de cero).
No está permitido el uso de ficheros, tuberías u otro mecanismo externo para transmitir información entre los procesos, salvo lo permitido expresamente en el enunciado.


Plazo de presentación.
Consultad la entrada de la página web de la asignatura.


