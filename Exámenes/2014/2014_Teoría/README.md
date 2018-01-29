# ASOR - Febrero 2014 - Teoría

*********************** **Ejercicio 1** ***********************
a) fe80::218:43ff:fe25:de20

Enlace local (Pertenece a fe80::/10)

b) 2001:db8:2512::2

Unicast de ámbito global (Pertenece a 2000::/3).

c) fdfb:946e:2c3a::

ULA de ámbito de sitio local (Pertenece a FC00::/7)

d) ff02::1

Multicast (Pertenece a FF00::/8) Esta dirección representa todos los interfaces de enlace local.
e) ff12::1180:add2

Multicast (Pertenece a FF00::/8).

*********************** **Ejercicio 2** ***********************

Este método denominado EUI-65 consiste en generar una dirección IPv6 a partir de la direción MAC. Una dirección MAC está compuesta de 48 bits en 6 bloques de dos caracteres hexadecimales. Para generar la dirección IPv6, se cogen los tres primeros bloques, se le añade FF:FE y se le colocan los tres últimos bloques. Además, se cambia el séptimo bit por un 1. De forma que queda:

FE80::BLOQUE1(Bit 7 cambiado)BLOQUE2:BLOQUE3FF:FFEBLOQUE4:BLOQUE5BLOQUE6

En cuanto al problema de privacidad viene dado a que se comparte a través de la dirección IPv6 la direccióm MAC implícitamente lo que supone que las máquinas puedan ser rastreadas. Para mitigarlo, se puede generar la id de interfaz pseudo-aleatorimente.

*********************** **Ejercicio 3** ***********************

El protocolo ARP de IPv4 se lleva a cabo una vez configurada la red, cuando nos intentamos conectar con otro host, necesitamos conocer la dirección MAC asociada a la dirección IP destino, para ello se manda el mensaje a todas las direcciones bradcast lo que hace que se llene de bastante tráfico. Por otro lado, el descubrimiento de vecinos de IPv6, sirve para configurar la red y para asociar las MAC con las IPs, pero hace una llamada de broadcast a las direcciones del mismo ámbito (fe00::1) y además a las direcciones de nodo solicitado creadas dinámicamente.

*********************** **Ejercicio 4** ***********************

| Destino | Distancia | Encaminador|
| ----- | ---- |
| 192.168.1.0 | 1 | - |
| 192.168.2.0 | 3 | 192.168.3.1 |
| 192.168.3.0 | 1 | - |
| 192.168.4.0 | 1 | 192.168.3.1 |
| 192.168.5.0 | 5 | 192.168.3.1 |
| 192.168.6.0 | 6 | 192.168.3.1 |

*********************** **Ejercicio 5** ***********************

Los encaminadores de OSPF son:

**Intra-Area Routers (IA)** que localizan un área (mantiene sólo la topología de ese área).

**Area Border Routers (ABR)** aquellos que conectan varias áreas (mantiene un BD para cada una de las áreas que conecta).

**AS Boundary Routers (ASBR)** aquellos que se situan en la frontera de un AS, intercambia rutas entre la red OSPF  otros sistemas.


*********************** **Ejercicio 6** ***********************

Hay tres tipos de Sistemas Autónomos:

**Stub** son los que están conectados únicamente a otro AS (Destino/origen para el tréfico).

**Multihomed** Son los que están conectados a varios AS pero siguen siendo de Origen/Destino del tráfico.

**Tránsito** Son los que están conectados a varios AS y permiten el tráfico de tránsito.

*********************** **Ejercicio 7** ***********************

Además de la ventana de recepción, TCP utiliza la venta de congestión para controlar la congestión de la red. Cuando se inicia una conexión TCP se envían pocos paquetes, por ejemplo 1, es decir que la ventana de congestión = 1, cuando se confirman dichos paquetes enviados la CW aumenta exponencialmente hasta llegar a un umbral (Normalmente 64), una vez alcanzado ese umbral la CW crecce linelamente hasta alcanzar la ventana de recepción, donde se queda contantes de modo que CW = RW.

Una red está congestionada cuando se alcanza los temporizadores de retrasmisión o cuando se pierden paquetes (cuando llegan 3 ACKs seguidos) esto hace que la ventana de congestión se reduzca, enviando así menos segmentos.

*********************** **Ejercicio 8** ***********************

**A** Registro Address que incluye la traducción directa Nombre-IP para IPv4.

**AAAA** Registro Address que incluye la traducción directa Nombre-IP para IPv6.

**NS** Registro NameServer especifica los servidores autoritativos para la zona, especifica a quién tengo que preguntar por ese dominio.

**MX** registro Mail Exchanger, sirve para representar los sistemas de correos y encaminar los mensajes eficientemente.

**SOA** Registro de servidores autoritativos, marca el comienzo de la definición de una zona.

**PRT** Registro Pointer sirve para la traducción inversa IP-Nombre.
