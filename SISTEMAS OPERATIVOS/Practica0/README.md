# Práctica 2.0.Práctica Opcional: Introdución al Lenguaje de Programación Shell.

## Tabla de contenido
- [Comandos y secuencias de comandos](#Comandos-y-secuencias-de-comandos).
- [Variables de entorno](#variables-de-entorno).
- [Comillas](#comillas).
- [El path](#el-path).
- [Manejo de cadenas y flujos de caracteres](#manejo-de-cadenas-y-flujos-de-caracteres).
- [Los comandos cat wc head tail y tr](#los-comandos-cat-wc-head-tail-y-tr).
- [Expresiones Regulares](#expresiones-regulares).
- [Programación en Lenguaje Shell](#programación-en-lenguaje-shell).


## Comandos y secuencias de comandos

*********************** **Ejercicio 1** ***********************

**Echo:** Muestra una línea de texto.
  **-n:** No hace un salto de línea al final.
  **-e:** Interpreta los blacklash escapes (p.e. \n).

  <pre>
  <code>$echo -e "\t Ampliación de Sistemas Operativos y Redes"
  </code></pre>

*********************** **Ejercicio 2** ***********************

&&  = And.
||  = Or.
;   = Se acaba una línea de comandos para dar lugar a otra independiente.
()  = Define una sub-shell.
|   = Pipe, encadena la salida de un comando con la entrada del siguiente.
&   = Pone el comando en background

<pre>
<code>$echo línea uno;echo línea dos; echo línea tres
$ echo línea uno && echo línea dos && echo línea tres
  # Muestra las tres líneas
$ echo línea uno || echo línea dos; echo línea tres
  # Muestra la línea uno y luego la tres
$ (echo En una sub-shell; exit 0) && echo terminó bien || echo terminó mal
  # Muestra "En una sub-sell" y termina bien ya que devuelve 0.
$ (echo En una sub-shell; exit 1) && echo terminó bien || echo terminó mal
  # Muestra "En una sub-shell" y termina mal por que devuelve 1 (error).
</code></pre>

## Variables de entorno

*********************** **Ejercicio 1** ***********************

<pre>
<code>$env
</code></pre>

Algunas variables importantes:

**HOME=**/home/usuario

**PATH=**/usr/lib/jvm/jdk-9.0.1/bin:/home/mandy/anaconda3/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin

**JAVA_HOME=**/usr/lib/jvm/jdk-9.0.1

*********************** **Ejercicio 2** ***********************

<pre>
<code>$echo $VARIABLE
</code></pre>

**USER=** borja

**UID=** 1000

**HOME=** /home/borja

**PWD=** /home/borja

**SHELL=** /bin/bash

**$=** 25193 (PID del proceso)

**PPID=** 25184 (PPID del proceso)

**?=** 0


*********************** **Ejercicio 3** ***********************

<pre>
<code>VARIABLE1="Curso "
VARIABLE2="de "
VARIABLE3="ASOR"
echo "$VARIABLE1$VARIABLE2$VARIABLE3"
bash -c echo $VARIABLE1$VARIABLE2$VARIABLE3
bash -c export; echo $VARIABLE1$VARIABLE2$VARIABLE3
</code></pre>

*********************** **Ejercicio 4** ***********************

<pre>
<code>$VAR1="1+1="
$VAR2="2"
$VAR3=$VAR1$VAR2
$echo $VAR3
</code></pre>

## Comillas

<pre>
<code>echo "El valor es: $VAR3"
  #El valor es: 1+1=2
echo 'El valor es: $VAR3'
  # El valor es: $VAR3
echo "El usuario es `whoami`"
  # El usuario es mandy
</code></pre>

## El path

*********************** **Ejercicio 1** ***********************

<pre>
<code>echo "$PATH"
  #/usr/lib/jvm/jdk-9.0.1/bin:/home/mandy/anaconda3/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
</code></pre>

*********************** **Ejercicio 2** ***********************

<pre>
<code>export $PATH=$PATH:./
$echo "$PATH"
  #/usr/lib/jvm/jdk-9.0.1/bin:/home/mandy/anaconda3/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:./

$export PATH=$PATH:$PWD
$echo "$PATH"
    #/usr/lib/jvm/jdk-9.0.1/bin:/home/mandy/anaconda3/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/hombe/borja
</code></pre>

Uno añade ./ por lo tanto cambiará según la carpeta en la que estemos y el otro el fichero actual.

*********************** **Ejercicio 3** ***********************

<pre>
<code>$which bash
  #/bin/bash
$which env
  #/usr/bin/env
$which gzip
  #/bin/gzip
$which echo
  #/bin/echo
$which set
  # -
$which ls
  #/bin/ls
</code></pre>

*********************** **Ejercicio 4** ***********************

<pre>
<code>$unset $PATH
$echo "Hola, qué tal"
  # No deja porque no encuentra el path absoluto de echo.
$/bin/ls
</code></pre>


## Manejo de cadenas y flujos de caracteres

*********************** **Ejercicio 1** ***********************

<pre>
<code>$echo -e "zorro\npájaro\nvaca\ncaballo\nabeja\npaloma" | sort
  # abeja
  # caballo
  # pájaro
  # paloma
  # vaca
  # zorro
$/bin/ls
</code></pre>

*********************** **Ejercicio 2** ***********************

<pre>
<code>$echo -e "zorro\npájaro\nvaca\ncaballo\nabeja\npaloma" > texto1
$sort -f texto1
</code></pre>

*********************** **Ejercicio 3** ***********************

<pre>
<code>$ls -l text* nada* > salida
$cat salida
  # No aparece nada.
$ls -l text* nada* 2> salida
$cat salida
  #ls: no se puede acceder a 'text*': No existe el archivo o el directorio
  #ls: no se puede acceder a 'nada*': No existe el archivo o el directorio
</code></pre>


*********************** **Ejercicio 4** ***********************

<pre>
<code>$ls -l text* nada* 2>> salida
$cat salida
  #ls: no se puede acceder a 'text*': No existe el archivo o el directorio
  #ls: no se puede acceder a 'nada*': No existe el archivo o el directorio
  #ls: no se puede acceder a 'text*': No existe el archivo o el directorio
  #ls: no se puede acceder a 'nada*': No existe el archivo o el directorio
</code></pre>

## Los comandos cat wc head tail y tr

*********************** **Ejercicio 1** ***********************

<pre>
<code>$cat - > texto2
$pera
$manzana
$plátano
$ciruela
CTR+D
$cat texto2
</code></pre>

*********************** **Ejercicio 2** ***********************

<pre>
<code>$cat texto1 texto2 > texto3
$cat texto3
</code></pre>

*********************** **Ejercicio 3** ***********************

<pre>
<code>~#Líneas / Palabras / Bits
$wc texto1
  # 6  6 40 texto1
$wc texto2
  # 4  4 31 texto2
$wc texto3
  # 10 10 71 texto3
$ls -l texto*
 #-rw-r--r-- 1 mandy mandy 40 ene  9 23:55 texto1
 #-rw-r--r-- 1 mandy mandy 31 ene  9 23:52 texto2
 #-rw-r--r-- 1 mandy mandy 71 ene  9 23:55 texto3
 # Ocupa el mismo espacio.
</code></pre>

*********************** **Ejercicio 4** ***********************

a)

<pre>
<code>$demesg > demesg.out
$wc demesg.out
  #Tiene 511 Líneas
</code></pre>
a)

<pre>
<code>$tail dmesg -n 15
</code></pre>

c)

<pre>
<code>$head dmesg -n 3
</code></pre>


<pre>
<code>$tail -f dmesg
$tail -F dmesg
  # -F = -f + --retry (Retry intenta abrir el archivo si este no está accesible).
</code></pre>

*********************** **Ejercicio 5** ***********************

<pre>
<code>$tr -s '\n' '\t' < texto3 > texto3
</code></pre>

## Expresiones Regulares

**Caracteres y grupos de caracteres:** Ejemplos: a, b, [aA], [0-9], [A-Za-z], [:blank:], [:alnum:]
**Posicionamiento (anclas):** ^ ppio de línea, $ final de línea, \< ppio de palabra, \> final de
palabra
**Wildcards:** . cualquier carácter, * el patrón anterior 0 o más veces, + el patrón anterior 1 o
más veces.
**Repeticiones:** {N} {N,} {N,M} el patrón se repite N veces, N veces o más, N veces y no más de
M.
Los caracteres anteriores se pueden escapar con \ , para encajar el patrón con el propio carácter.

*********************** **Ejercicio 1** ***********************

<pre>
<code>$cat texto1 | grep ja
</code></pre>

*********************** **Ejercicio 2** ***********************

<pre>
<code>$cat texto1 | grep ja$
</code></pre>

*********************** **Ejercicio 3** ***********************

<pre>
<code>$cat texto1 | grep a.a
</code></pre>

*********************** **Ejercicio 4** ***********************

<pre>
<code>$cat texto1 | grep "al*o"
</code></pre>


## Programación en Lenguaje Shell

*********************** **Ejercicio 1** ***********************


[ej1.sh](ej1.sh)

<pre>
<code>$chmod +x ej1.sh
$./ej1.sh hola hola2
 #El programa se llama: ./ej1.sh
 # el primer argumento es: hola
 # el segundo argumento es: hola2

$./ej1.sh "hola hola2"
 #El programa se llama: ./ej1.sh
 # el primer argumento es: hola hola2
 # el segundo argumento es:
</code></pre>

*********************** **Ejercicio 2** ***********************

a)

<pre>
<code>$test -f \bin\bash; echo $?
  # 1
$[ -f \bin\bash ]; echo $?
  # 1
</code></pre>

b)

[ej2.sh](ej2.sh)

*********************** **Ejercicio 3** ***********************

[ej3.sh](ej3.sh)

*********************** **Ejercicio 4** ***********************

[ej4.sh](ej4.sh)
