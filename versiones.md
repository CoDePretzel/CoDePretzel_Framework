# Propuesta de funcionalidades de primeras versions del framework de CoDe Pretzel

## Objetivos generales del framework

Una infraestructura de herramientas, técnicas y configuraciones que nos permita desarrollar software embebido de calidad, con facilidad de replicación, modularidad y con un proceso de desarrollo establecido.

Es decir

1. Una Estructura para hacer to propio código reusable, (No empezar de cero cada vez)
2. Una Forma de organizar tu proyecto (dónde va qué cosa)
3. Un proceso de desarrollo (cómo configurar tus comiplaciones, pruebas y deploy)
4. Una Propuesta periféricos y técnicas usados en industria (mejoras tu CV y no reinventas la rueda)
5. Cierta Independencia de fabricante (Puedas cambiar de fabricante sin tantísima modificación)

Más información en la sección

## Lógica de versionamiento

La numeración de versiones que se seguirá será la siguiente:
**X.Y.Z**

Siendo:

- X = Mayor Number, es el que indica la versión principal del software, todo aquello dentro de un número de versión X será compatible entre sí. Todo aquello que sea de diferente versión no será compatible entre sí, es decir una versión X+1 por ejemplo, no será compatible con una versión X.

- Y = Minor Number, es el que indica un agregado de funcionalidad, un bugfix o un parche, que no afecte la funcionalidad fundamental del software que requiera un cambio Mayor o incompatible.

- Z = Revision Number, indica la entrega de un cambio mínimo, que no es una funcionalidad completa

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

## Proyección de funcionalidades por versión
La version 1.0.0 es el mínimo viable para probar todas las funcionalidades del framework en al menos dos dispositivos, donde se cumplan las 3 prioridades y los 5 objetivos del mismo
Las versiones se muestran en orden cronológico y las versiones mayores siempre serán dependientes de las menores, a menos que se especifique lo contrario
  
### Version 0.0.12
**- Estructura de archivos y carpetas para un proyecto básico incluyendo la división por componentes de:**
  
1. código fuente de aplicación (.c, .h, .a)
2. código fuente de periféricos (.c, .h, .a)
3. código fuente del API agnóstica al hardware (que conecta aplicación y drivers del fabricante)
4. configuración de información específica de la tarjeta (botones, potenciometros, pantallas, etc.)
5. configuración y archivos de pruebas unitarias (ej. Unity)
6. configuración de hardware de las tarjetas - dispositivos soportados (ej. PIO JSON files)
7. configuración y administración de compilación del proyecto (ej. pio directory structure)
8. configuración de análisis estático (rutas hacia ejecutable de cppcheck y archivos de reglas)

**- Documentación mínima inicial requerida:**
  
5. Configuración y prueba inicial del framework (entrada en read the docs)
6. Guía de uso del framework con ejemplo, compilación y flasheo del mismo (entrada en read the docs)
8. Guía de uso del framework con ejemplo de código de aplicación "hola LED" (entrada en read the docs)
10. Guía de requerimientos e instalación dependencias para la instalación y uso del framework (entrada en read the docs)
11. Guía básica de generación de código de drivers por el fabricante, ej. Microchip Harmony, Renesas Synergy, STM32CubeMX (solo dar indicaciones de a dónde acudir por la documentación oficial y una explicación general del proceso)
12. Guía para configuración y uso de pruebas unitarias básicas con ejemplo (entrada en read the docs)
12. Guía para configuración y uso de análisis estático (ej. cppcheck) con ejemplo (entrada en read the docs)
13. Guía del desarrollador en el formato usado de Doxygen para documentar el código del framework
13. Guía del desarrollador con ejemplo de cómo editar la documentación principal del framework y la documentación específica del API (ej. editar comentarios que use Doxygen para la API y editar directamente entradas de readthedocs para el resto de la documentación)
13. Guia del desarrollador de la estructura y diagrama del framework incluyendo la lógica de nombramiento de funciones / módulos / variables

  
**- Ejemplos / Módulos de código: **
12. Código y configuración funcional del ejemplo mínimo del framework (punto .), es decir un template de un Bootloader compatible con 2 dispositivos al menos (ej. AVR128DA y ATMega2560), sin validacion de memoria o checksum, solo cargar un programa por SPI, garbage in / garbage out
12. Código y configuración funcional del ejemplo mínimo de código de aplicación (punto .), es decir, un programa que permita configurar un GPIO de salida en el que puedas conectar una resistencia y un led para hacer un "hola led" (parpadear un LED cada segundo), usando interrupciones del timer, sin usar delay() / polling, ej. usando on capture compare del timer y que solamente requiera agregar #include y #define de configuración en main.c
12. Código de pruebas y configuración de verificación de la función toggleLED(), una prueba unitaria y revisar solo el valor del registro del periférico, usando el framework (es decir, siendo lo más independiente de hardware posible) 
  
  
**- Configuración, instalación e integración : **
4. Asegurar soporte en PIO Boards de AVR128DA
4. Asegurar soporte en PIO Boards de ATMega2560
5. Configuración de Unity con PIO para ejecutar pruebas unitarias como parte del proceso de compilación
6. Configuración de AVR128DA Curiosity Nano en archivos JSON para PIO Boards
6. Configuración de Arduino Mega en archivos JSON para PIO Boards  
7. Toolchain y archivos de configuración para AVR128DA para PIO Platform
7. Toolchain y archivos de configuración para ATMega2560 para PIO Platform
8. Configuración de CPPCheck e integración con PIO Check con reglas por defecto (ej. MISRAC)
14. Verificar si es compatible usar una estrategia de documentación por comentarios como Doxygen para implementar una documentación en [readthedocs.org][[en read the docs](https://readthedocs.org/)]
14. Implementar y configurar el sitio de documentación principal del framework (ej readthedocs.org)
15. Implementar y configurar el generador de documentación basado en comentarios (ej. Doxygen)
  
Versiones futuras
  
  
x. Configuración de reglas para soporta BARR-C2018 en cppcheck, solo las reglas que no requieren code review.
x. Integrar pruebas unitarias en Jenkins
x. Conectar github para que no acepte un pull request si no pasaron las pruebas
x. Conectar Jenkins con artifactory para liberar y administrar versiones pre-compiladas
x. Conectar Jenkins con hardware real que permita hacer pruebas de funcionalidad o integración básicas
x. Incluir y empacar en una imagen de Docker a Jenkins, Articatory, Unity, los archivos de Boards, Platforms y Framework para PIO
