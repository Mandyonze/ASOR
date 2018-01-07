# Práctica 1.3.Domain Name System (DNS)

## Tabla de contenido
- [Topología](#topología).
- [Dirección de enlace local](#dirección-de-enlace-local).
- [Dirección ULA](#dirección-ula).
- [Encaminamiento estático](#encaminamiento-estático).
- [Configuración Persistente](#configuración-persistente).
- [Autoconfiguración Anuncio de Prefijos](#autoconfiguración-anuncio-de-prefijos).
- [ICMP versión 6](#icmp-versión-6).

### Topología
![topología](topologia.png)

### Dirección de enlace local

*********************** **Ejercicio 1** ***********************

*VM1:*
<pre>
<code>$ip link set eth0 up
</code></pre>

*VM2:*
<pre>
<code>$ip link set eth0 up
</code></pre>

Resultado(VM1):
<pre>
<code>fe80::a00:27ff:fef2:5a8f/64
</code></pre>

Resultado(VM2):
<pre>
<code>fe80::a00:27ff:feca:9ce8/64
</code></pre>


*********************** **Ejercicio 2** ***********************

*VM1:*
<pre>
<code>$ping6 fe80::a00:27ff:feca:9ce8 -I eth0
</code></pre>

*********************** **Ejercicio 3** ***********************

*VM1:*
<pre>
<code>$ping6 fe80::a00:27ff:feca:9ce8 -I eth0
</code></pre>

WhireShark:
![ws1](ws1.png)

Podemos ver los siguientes datagramas:

**->Neighbor Solicitation:** Cuando se ha levantado la interfaz se ha enviado los datagramadas usados en el protocolo ode descubrimiento de vecinos. Se envían los datagramas desde la dirección :: que indica que la interfaz aún no tiene ninguna dirección asignada a la dirección multicas de enlace y a la dirección calculada en funciñon de la dirección unicast del nodo (FF02::1:FFXX:XXXX).

**->Router Solicitation:** Una vez asignada una dirección de enlace, se envían datagramanas a la dirección multicast para definir los routers.

**->Echo Request/Reply:** Los valores dentro del datagrama son:
-VER: 0110 (6)
-Trafic Class y Flow Lavel: 0
-Payload length: 64
-Next header: ICMPv6
-Hop limit: 64
-Source y Destination Address.

### Dirección ULA

*********************** **Ejercicio 1** ***********************

*VM1:*
<pre>
<code>$ip link set eth0 up
$ip a add fd00:0:0:a::1/64 dev eth0
</code></pre>

*VM2:*
<pre>
<code>$ip link set eth0 up
$ip a add fd00:0:0:a::2/64 dev eth0
</code></pre>

*********************** **Ejercicio 2** ***********************

*VM1:*
<pre>
<code>$ip link set eth0 up
$ping6 fd00:0:0:a::2 -I eth0
</code></pre>

![ws2](ws2.png)


*********************** **Ejercicio 3** ***********************

*VM3:*
<pre>
<code>$ip link set eth0 up
$ip link set eth1 up
</code></pre>

*VM4:*
<pre>
<code>$ip link set eth0 up
</code></pre>

*VM1:*
<pre>
<code>$ping6 fe80::a00:27ff:feff:f43d  -I eth0
</code></pre>

![ping](ping.png)

*VM3:*
<pre>
<code>$ping6 fe80::a00:27ff:fee7:2755  -I eth1
</code></pre>

![ping2](ping2.png)

*********************** **Ejercicio 4** ***********************

*VM3:*
<pre>
<code>$ip a add fd00:0:0:a::3/64 dev eth0
$ip a add fd00:0:0:b::1/64 dev eth1
</code></pre>

*VM4:*
<pre>
<code>$ip a add fd00:0:0:b::2/64 dev eth0
</code></pre>

*********************** **Ejercicio 5** ***********************

*VM3:*
<pre>
<code>$ping6 fd00:0:0:a::1  -I eth0
</code></pre>

![ping3](ping3.png)

*VM3:*
<pre>
<code>$ping6 fd00:0:0:b::2  -I eth1
</code></pre>

![ping4](ping4.png)

*VM1:*
<pre>
<code>$ping6 fd00:0:0:b::2  -I eth0
</code></pre>

![ping5](ping5.png)

### Encaminamiento estático

*********************** **Ejercicio 1** ***********************

*VM1:*
<pre>
<code>$ip route -6
</code></pre>

![route](route.png)


*VM3:*
<pre>
<code>$ip route -6
</code></pre>

![route1](route1.png)

*********************** **Ejercicio 2** ***********************

*VM3:*
<pre>
<code>$sysctl -w net.ipv6.conf.all.forwarding=1.
</code></pre>

*********************** **Ejercicio 3** ***********************

*VM1 y VM2:*
<pre>
<code>$ip -6 route add fd00:0:0:b::/64 via fd00:0:0:a::3
</code></pre>

*VM4:*
<pre>
<code>$ip -6 route add fd00:0:0:a::/64 via fd00:0:0:b::1
</code></pre>

*VM1:*
<pre>
<code>$ping6 fd00:0:0:b::2  -I eth0
</code></pre>


*********************** **Ejercicio 4** ***********************

Red fd00:0:0:a::/64 (VM1)

![tabla](tabla.png)

Red fd00:0:0:b::/64 (VM4)

![tabla1](tabla1.png)

### Configuración Persistente


*********************** **Ejercicio 1** ***********************

*VM4:*
<pre>
<code>$nano /etc/network/interfaces/
********************************
iface eth0 inet6 static
   address fd00:0:0:a::f
   netmask 64

iface eth1 inet6 static
   address fd00:0:0:b::f
   netmask 64
********************************
</code></pre>

*********************** **Ejercicio 2** ***********************

*VM4:*
<pre>
<code>$ip link set eth0 down
$ip link set eth1 down
$ifup
$ifdown
</code></pre>

Resultado:
Se han configurado automáticamente las direccones ipv6.

### Autoconfiguración Anuncio de Prefijos


### ICMP versión 6
