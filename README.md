# Ampliación de Sistemas Operativos y Redes

Prácticas de la asignatura Ampliación de Sistemas Operativos y Redes (ASOR) del curso 2017/2018 de la Universidad Complutense de Madrid (UCM).

## Tabla de contenido
- [Plantilla](#plantilla).
  - [Code](#code).
  - [Imágenes](#imágenes).
  - [Enunciado](#enunciado).
- [Máquinas virtuales](#máquinas-virtuales).

## Plantilla:

### Codes

*Virtual Machine:*
<pre>
<code>$command shell
</code></pre>

### Imágenes

<pre>
<code>![descripción](imágenes/imagen.png)
</code></pre>


### Archivos

<pre>
<code>[descripción](carpeta/archivo.c)
</code></pre>

### Enunciado

*********************** **Ejercicio #** ***********************

## Máquinas virtuales

Para ejecutar las máquinas virtuales donde se han realizado las práticas es necesario tener el "Virtual Disk Image" llamado **asorfrontend**.

Lanzar diferentes máquinas virtuales:

- Directamente desde Virtual Box clonando la máquina y modificando los adaptadores de red en función de la práctica:

<pre>
<code>RED
Conectado a: Red interna
Nombre: inetX
Tipo de adaptador: Intel PRO/1000 MT Desktop (82540EM)
Modo promiscuo: Permitir VMs
Cable Conectado: true
</code></pre>

- Ejecutando los scripts desde un entorno Linux:

Para formatear todas las máquinas y crear la máquina ASOR-FE:

<pre>
<code>$asorregenerate
</code></pre>

Para configurar la topología de cada práctica:

<pre>
<code>$car prX.topol
*******************************************
netprefix inet
machine 1 0 0
machine 2 0 0
machine 3 0 0 1 1
machine 4 0 1
*******************************************
$vtopol prX.topol
</code></pre>
