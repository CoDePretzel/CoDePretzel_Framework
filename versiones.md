# Estructura de versionamiento y lógica de liberación de versiones (release) del framework de CoDe Pretzel

## Objetivos generales del framework

Una infraestructura de herramientas, técnicas y configuraciones que nos permita desarrollar software embebido de calidad, con facilidad de replicación, modularidad y con un proceso de desarrollo establecido.

Es decir

1. Una Estructura para hacer to propio código reusable, (No empezar de cero cada vez)
2. Una Forma de organizar tu proyecto (dónde va qué cosa)
3. Un proceso de desarrollo (cómo configurar tus comiplaciones, pruebas y deploy)
4. Una Propuesta periféricos y técnicas usados en industria (mejoras tu CV y no reinventas la rueda)
5. Cierta Independencia de fabricante (Puedas cambiar de fabricante sin tantísima modificación)

## Prioridad de funcionalidades para el Framework de CoDe Pretzel

- Portabilidad (entre dispositivos conocidos y previamente enlistados)
- Reusabilidad (mantenibilidad)
- Estandiración

## Lógica de manejo de ramas

Utilizamos la misma lógica recomendada por Atlassian, [gitflow](https://www.atlassian.com/es/git/tutorials/comparing-workflows/gitflow-workflow)

- Main: Última versión estable, contiene los tags de las versiones
- Develop: Última versión en desarrollo, la rama base de donde se bifurcan las demás
- Release: Version casi lista para integrarse a Main, esta branch puede ser usada para implementar pruebas más rigurosas de ser necesario
- Feature_<IssueNumber>: Cada una de las funcion
- Hotfix: Bifurcación de Main que arregla un problema en una versión específica y genera un tag de una versión intermedia con un bug fix (vease Lógica de Versionamiento)

## Lógica de versionamiento

La numeración de versiones que se seguirá será la siguiente:
**X.Y.Z**

Siendo:

**- X = Cambio Mayor (Mayor Number)**, es el que indica la versión principal del software.

Todo aquello dentro de un número de versión X será compatible entre sí.
Todo lo que no, no tendrá asegurada la compatibilidad entre sí, es decir:
Una versión 3.0.1 por ejemplo, no necesariamente será compatible con una versión 2.0.1, sin embargo, una versión 2.0.1 si será compatible con una versión 2.5.0.

Las versiones mayores solo serán modificadas una vez se alcance estabilidad para producción, el codebase se vuelva incompatible con versiones anteriores, haya una migración de herramientas importante o algún caso similar.


**- Y = Cambio Menor (Minor Number)**, es el que indica un aumento de funcionalidad.

Esta nueva funcionalidad no debe requerir un cambio Mayor o incompatible.
Es decir:

- Si el cambio es una funcionalidad que nos acerque a los objetivos del framework, se aumenta el cambio menor Y.
  
  :information_source: Excepto cuando este no está listo para liberarse y la siguiente versión es múltiplo de 5 (vease lógica de liberación de versiones)

Por ejemplo, la versión 0.3.0 necesita soportar la configuración necesaria para poder compilar un firmware para el AVR128DA y se agrega exitosamente, incluyendo documentación asociada y código de una apilcación básica para probar el funcionamiento, estos cambios se convertirían en la versión 0.4.0

**- Z = Revisión (Revision Number)**, contador de cambios mínimos dentro de una versión Y.

Es decir todos los cambios de tipo bugfix, documentación, parche o mejora que no afecte funcionalidad.

Por ejemplo, la versión 0.4.0 necesita un cambio de documentación, una reparación (bugfix) y un nuevo archivo de configuración, por lo tanto se agrupan y estas modificaciones formarían la versión 0.4.1

## :information_source: Lógica de liberación de versiones

* Lo que se encuentra en la rama **main** será siempre la versión más reciente estable y soportada.

* Se buscará que se liberen versiones a **main** cada 5 versiones menores, por ejemplo:

  - 0.5.0 es candidata a liberarse, así como 0.10.0.
  - 0.6.0 es intermedia y no serían candidatas a liberarse

* Las versiones de revisión podrán liberarse a **main** siempre y cuando sean bugfixes críticos o aclaraciones de documentación importantes, por ejemplo:
 
  - Si la versión 0.5.0 necesita un bugfix que arregla el proceso de compilación del bootloader, sí es candidato a liberarse a main, en la versión 0.5.1.
  - Si la versión 0.5.0 necesita un bugfix que mejora comentarios en el código que no afectan funcionalidad, no es candidato y se verá reflejado hasta el próximo release, la versión 0.10.0.


## Propuesta inicial de funcionalidades
  :bangbang: Esta sección probablemente se moverá a un archivo de backlog en el futuro próximo
  
  :bangbang: Las versiones aquí listadas, son solo una propuesta, no representan un plan fijo.
  
  :information_source: La version 1.0.0 es el mínimo viable para probar todas las funcionalidades del framework en al menos dos dispositivos, donde se cumplan las 3 prioridades y los 5 objetivos del mismo
 
  :information_source: Los elementos listados como **(Funcionalidad)** son cambios que directamente nos acercan a los objetivos de prioridad
  
  
### Version 0.1.0
  
*Objetivo:* Un hola led funcionando que incluye, documentación completa de su uso y la configuración de compilación correspondiente
  
**- Estructura de archivos y carpetas para un proyecto básico incluyendo la división por componentes de:**
  
1. Código fuente de aplicación (.c, .h, .a)
2. Código fuente de periféricos (.c, .h, .a)
3. Código fuente del API agnóstica al hardware (que conecta aplicación y drivers del fabricante)
4. Toolchain, configuración y administración de compilación del proyecto (ej. pio y su estructura de archivos)

**- Documentación:**

5. Guía de configuración y prueba inicial del framework 0.2.12 (entrada en read the docs)
6. Guía del desarrollador con ejemplo de cómo editar la documentación principal del framework y la documentación específica del API (ej. editar comentarios que use Doxygen para la API y editar directamente entradas de readthedocs para el resto de la documentación)


**- Ejemplos / Módulos de código:**

7. Código mínimo de prueba "hola led", usarlo como ejemplo inicial de la guía de configuración y prueba inicial del framework, requiere su propio repositorio que permita seguimiento, para asegurar el funcionamiento correcto del toolchain y la configuración inicial
  
**- Configuración, instalación e integración :**

8. Verificar si es compatible usar una estrategia de documentación por comentarios como Doxygen para implementar una documentación en [readthedocs.org][[en read the docs](https://readthedocs.org/)]
9. Implementar y configurar el sitio de documentación principal del framework (ej readthedocs.org)
10. **(Funcionalidad)** Toolchain y archivos de configuración para ATMega2560 para PIO Platform
11. Asegurar soporte en PIO Boards de ATMega2560
12. **(Funcionalidad)** Configuración de Arduino Mega en archivos JSON para PIO Boards 

-----
### Version 0.1.1
**- Estructura de archivos y carpetas para un proyecto básico incluyendo la división por componentes de:**

1. Configuración de información específica de las tarjetas - dispositivos soportados (ej. PIO JSON files) (botones, potenciometros, pantallas, etc.)

**- Documentación:**

2. Guía del desarrollador en el formato usado de Doxygen para documentar el código del framework  
3. Guia del desarrollador de la estructura y diagrama del framework incluyendo la lógica de nombramiento de funciones / módulos / variables
4. Guía de requerimientos e instalación dependencias para la instalación y uso del framework (entrada en read the docs)

**- Configuración, instalación e integración :**

5. Implementar y configurar el generador de documentación basado en comentarios (ej. Doxygen)

----
### Version 0.2.0
**- Estructura de archivos y carpetas para un proyecto básico incluyendo la división por componentes de:**

1. Configuración de análisis estático (rutas hacia ejecutable de cppcheck y archivos de reglas)

**- Documentación:**

2. Guía básica de generación de código de drivers por el fabricante, ej. Microchip Harmony, Renesas Synergy, STM32CubeMX (solo dar indicaciones de a dónde acudir por la documentación oficial y una explicación general del proceso)
3. Guía de uso del framework con ejemplo, compilación y flasheo del mismo (entrada en read the docs)
4. Guía de uso del framework con ejemplo de código de aplicación "hola LED" (entrada en read the docs)  

**- Ejemplos / Módulos de código:**
  
5. **(Funcionalidad)** Código y configuración funcional del ejemplo mínimo de código de aplicación, es decir, un programa que permita configurar un GPIO de salida en el que puedas conectar una resistencia y un led para hacer un "hola led" (parpadear un LED cada segundo), usando interrupciones del timer, sin usar delay() / polling, ej. usando on capture compare del timer y que solamente requiera agregar #include y #define de configuración en main.c

**- Configuración, instalación e integración :**

6. **(Funcionalidad)** Agregar toolchain y configuraci[on para AVR128DA para PIO Platform
7. **(Funcionalidad)** Configuración de AVR128DA Curiosity Nano en archivos JSON para PIO Boards 
8. Toolchain y archivos de configuración para AVR128DA para PIO Platform


----
### Version 0.3.0

**- Documentación:**

1. Guía del desarrollador para añadir cambios al framework (usando la lógica existente de manejo de ramas), es decir, el formato de la información que lleva el Pull Request, título, descripción, etiquetas, triage si es necesario y a quienes agregar como reviewers, además de cómo crear y manejar los issues de las nuevas versiones.  
  
**- Ejemplos / Módulos de código:**

2. **(Funcionalidad)** Código y configuración funcional del ejemplo mínimo del framework, es decir un template de un Bootloader compatible con 2 dispositivos al menos (ej. AVR128DA y ATMega2560), sin validacion de memoria o checksum, solo cargar un programa por SPI, garbage in / garbage out
  
----
### Version 0.4.0
**- Estructura de archivos y carpetas para un proyecto básico incluyendo la división por componentes de:**

1. Configuración y archivos de pruebas unitarias (ej. Unity)  

**- Documentación:**

2. Guía para configuración y uso de análisis estático (ej. cppcheck) con ejemplo (entrada en read the docs)
3. Guía para configuración y uso de pruebas unitarias básicas con ejemplo (entrada en read the docs)
  
**- Ejemplos / Módulos de código:**

4. **(Funcionalidad)** Código de pruebas y configuración de verificación de la función toggleLED(), una prueba unitaria y revisar solo el valor del registro del periférico, usando el framework (es decir, siendo lo más independiente de hardware posible) 
  
**- Configuración, instalación e integración :**

5. **(Funcionalidad)** Configuración de CPPCheck e integración con PIO Check con reglas por defecto (ej. MISRAC)
6. **(Funcionalidad)** Configuración de Unity con PIO para ejecutar pruebas unitarias como parte del proceso de compilación


----
Backlog de funcionalidades deseables
  
**- Documentación:**

  -. Guía de desarrollador con referencia al estándar BARR-C2018, dónde encontrarlo, por qué usarlo y cuáles reglas serán las que se van a agregar (no todo el estándar necesita ser agregado a analizador estático)
  -. Guía del desarrollador con ejemplo de cómo crear una conección con hardware para hacer pruebas automatizadas
  -. Guía del desarrollador con ejemplo de cómo configurar y crear una imagen de Docker para replicar el entorno de desarrollo

**- Configuración, instalación e integración :**
  
  -. (Funcionalidad) Crear archivos de reglas para soporta BARR-C2018 en cppcheck, solo las reglas que no requieren code review.    
  -. Integrar configuración en PIO Check para soportar selección de este estándar
  -. Configurar e instalar Jenkins
  -. Migrar pruebas unitarias a Jenkins
  -. (Funcionalidad) Conectar github con Jenkins para que no acepte un pull request si no pasaron las pruebas
  -.Instalar y configurar Artifactory
  -. (Funcionalidad) Conectar Jenkins con Artifactory para liberar y administrar versiones pre-compiladas
  -. (Funcionalidad) Conectar Jenkins con hardware real que permita hacer pruebas de funcionalidad o integración básicas
  -. Instalar y configurar Docker para comunicarse con hardware connectado por periféricos de la computadora
  - (Funcionalidad) Incluir y empacar en una imagen de Docker a Jenkins, Articatory, Unity, los archivos de Boards, Platforms y Framework para PIO

