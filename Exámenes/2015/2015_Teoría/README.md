# ASOR - Febrero 2015 - Teoría

*********************** **Ejercicio 1** ***********************

Para enviar un datagrama IPv6 a todos los nodos de enlace necesitamos una dirección multicast de ámbito de enlace loca en concreto a la dirección ff02::1.

*********************** **Ejercicio 2** ***********************

| Destino | Distancia | Encaminador|
| ----- | ---- |
| 192.168.1.0 | 1 | - |
| 192.168.2.0 | 3 | 192.168.3.1 |
| 192.168.3.0 | 1 | - |
| 192.168.4.0 | 1 | 192.168.3.1 |
| 192.168.5.0 | 5 | 192.168.3.1 |
| 192.168.6.0 | 6 | 192.168.3.1 |

*********************** **Ejercicio 3** ***********************

Los atributos bien conocidos, del inglés, **well-known** son aquellos que deben ser admitidos por todas las implementaciones BGP. Estos atributos pueden ser obligatorios (mandatory) o discrecionales (discretionary). La diferencia entre estos es que los obligatorios deben ser incluidos en TODAS las actualizaciones.  

Un ejemplo de **well-known mandatory** es **AS_PATH** que indica la ruta como conjunto do secuencia de ASs. Enumera los AS por los que ha pasado el mensaje de UPDATE y sirve para prevenir bucles durante el enrutameinto inter-AS.

*********************** **Ejercicio 4** ***********************

Usa el algoritmo de Karn's que consiste en que cuando se pierde un segmento se ignora su RTT y se emplea una estrategia Back-Off de modo que el RTO = X * RTO (Siendo X = 2 normalmente). El RTO anterior se calcula en función de los segmentos confirmados anteriormente de modo que RTO = RTTs + 4*RTTd.

*********************** **Ejercicio 5** ***********************

Las señales no capturadas por el proceso son gestionadas por el kernel que llama a la función por defecto que está asociada a una determinada acción.

*********************** **Ejercicio 6** ***********************

Un servidor TCP puede antender varias conexiones simultáneas a traves de accept-and-fork o prefork. La primera significa que cuando se conecta un cliente y el servidor lo acepta se crea un proceso hijo que maneja la comunicación. La segunda significa que cada hijo gestiona el accept y administra las comunicaciones. 

*********************** **Ejercicio 7** ***********************

Dos procesos sin relación de parentesto se pueden comunicar a través de tuberías **con nombre**, esto es un tipo especial de fichero que ocupa una entrada en el directorio, son iguales que las tuberías con nombre. El núcleo realiza la sincronización que almacena los datos internamente.
