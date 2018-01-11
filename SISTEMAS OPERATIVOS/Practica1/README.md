# Práctica 2.1.Introducción a la programación de Sistemas UNIX

## Tabla de contenido
- [Gestión de Errores](#destión-de-errores).
- [Información del Sistema](#información-del-sistema).
- [Información del Usuario](#información-del-usuario).
- [Información Horaria del Sistema](#información-horaria-del-sistema).

## Gestión de Errores


*********************** **Ejercicio 1** ***********************

[ej1](Gestión de Errores/ej1.c)

*********************** **Ejercicio 2** ***********************

[ej2](Gestión de Errores/ej2.c)

*********************** **Ejercicio 3** ***********************

[ej3](Gestión de Errores/ej3.c)

Hay 133 errores definidos en el sistema.

## Información del Sistema

*********************** **Ejercicio 1** ***********************
<pre>
<code>$man uname
$uname -all
</code></pre>

**Kernel Name (-s):** Linux

**Node Name (Username) (-n):** Borja

**Kernel Release (-r):** 4.13.0-25-generic

**Kernel Version (-v):** #29-Ubuntu SMP Mon Jan 8 21:14:41 UTC 2018

**Machine (-m):** x86_64

**Processor (-p):** x86_64

**Hardware-platform (-i):** x86_64

**Operating-system (-o):** GNU/Linux

*********************** **Ejercicio 2** ***********************

[ej2](Información del Sistema/ej2.c)

*********************** **Ejercicio 3** ***********************

[ej3](Información del Sistema/ej3.c)

**Longitud Máxima de Argumentos:** 2097152

**Número máximo de hijos:** 15569

**Número máximo de ficheros:** 1024


*********************** **Ejercicio 4** ***********************

[ej4](Información del Sistema/ej4.c)

**Número Máximo de Enlaces:** 65000

**Tamaño Máximo nombre de una Ruta:** 4096

**Tamaño Máximo nombre de un Fichero:** 255

## Información del Usuario

*********************** **Ejercicio 1** ***********************
<pre>
<code>$id
</code></pre>

uid=1000(borja) gid=1000(borja) grupos=1000(borja),4(adm),24(cdrom),27(sudo),30(dip),46(plugdev),118(lpadmin),128(sambashare)


**context (-Z):** Sólo en SELinux

**Group (-g):** 1000

**Groups (-G):** 1000 4 24 27 30 46 118 128

**Name (-n):**-

**Real (-r):**-

**User(-u):** 1000

*********************** **Ejercicio 2** ***********************

[ej2](Información del Sistema/ej2.c)

El setuid se utiliza para dar privilegios elevados en determinados archivos para usuarios que no lo poseen, ocmo por ejemplo en el archivo /etc/bin/passwd para que todos puedan cambiar la contraseña pero que no puedan leer ni escribir las otras.  Por lo tanto, cuando el uid es distinto del euid tiene el bit setuid activado.

*********************** **Ejercicio 3** ***********************

[ej3](Información del Sistema/ej3.c)

## Información Horaria del Sistema

*********************** **Ejercicio 1** ***********************
<pre>
<code>$man date
</code></pre>

Formatos disponibles:

**-I[FMT], --iso-8601[=FMT]:** Example: 2006-08-14T02:34:56-06:00

**-R, --rfc-2822:** Example: Mon, 14 Aug 2006 02:34:56 -0600

**--rfc-3339=FMT:** Example: 2006-08-14 02:34:56-06:00

**-u, --utc, --universal:** Example: mié ene 10 23:21:44 UTC 2018


*********************** **Ejercicio 2** ***********************

[ej2](Información del Sistema/ej2.c)


*********************** **Ejercicio 3** ***********************

[ej3](Información del Sistema/ej3.c)


*********************** **Ejercicio 4** ***********************

[ej4](Información del Sistema/ej4.c)


*********************** **Ejercicio 5** ***********************

[ej5](Información del Sistema/ej5.c)


*********************** **Ejercicio 6** ***********************

[ej6](Información del Sistema/ej6.c)
