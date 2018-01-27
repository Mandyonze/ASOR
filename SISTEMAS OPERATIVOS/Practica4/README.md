# Práctica 2.4.Tuberías

## Tabla de contenido
- [Tuberías con nombre](#tuberías-con-nombre).
- [Multiplexión de caneles de entrada y salida](#multiplexión-de-caneles-de-entrada-y-salida).
- [Tuberías sin nombre](#tuberías-sin-nombre).

## Tuberías con nombre

*********************** **Ejercicio 1** ***********************

*Terminal 1*
<pre>
<code>$man mkfifo
$mkfifo tuberia
$ls -l
&stat tuberia
$echo "Test" > tuberia
</code></pre>

*Terminal 2*
<pre>
<code>$cat tuberia
</code></pre>

*********************** **Ejercicio 2** ***********************

[ej2](Tuberias_con_nombre/ej2.c)

## Multiplexión de caneles de entrada y salida


*********************** **Ejercicio 1** ***********************

*Terminal 1*
<pre>
<code>$gcc -o ej2 ej2.c
$./ej2
</code></pre>

[ej1](Multiplexion_de_caneles_de_entrada_y_salida/ej1.c)

*Terminal 2*
<pre>
<code>$echo "Test" > tuberia
$echo "Test" > tuberia2
</code></pre>

## Tuberías sin nombre

*********************** **Ejercicio 1** ***********************

[ej1](Tuberias_sin_nombre/ej1.c)

*********************** **Ejercicio 2** ***********************

[ej2](Tuberias_sin_nombre/ej2.c)
