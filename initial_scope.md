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

## 1.0.0
La version 1.0.0 es el mínimo viable para probar todas las funcionalidades del framework en al menos dos dispositivos
  
  
- Entrada en la wiki de Code Pretzel, que estipule Requerimientos para la instalación y configuración del framework
- Entrada en la wiki de Code Pretzel, Guía de usuario para descarga, configuración e instalación del framework
  - Incluyendo la generación de código de drivers por el generador de código del fabricante (Ej. Microchip Harmony, Renesas Synergy, STM32CubeMX)
- Un programa con main loop, que permita configurar un GPIO de salida en el que puedas conectar una resistencia y un led para hacer un "hola led" (parpadear un LED cada segundo)
  - El programa de hola led es un módulo independiente, que utilizará interrupciones de timer y on capture compare para lograr el alternado en la salida del GPIO sin trabar el proceso principal ni necesitar código en main.c
- Estructura de carpetas que organicen el contido del framework
  - Estructura para código fuente, para pruebas unitarias, para código ejecutable y para configuraciones del proceso de desarrollo (Makefiles o similares)
- Archivos de configuración para compilar el proyecto
- Archivos de ejecución de pruebas unitarias
- Archivos con pruebas unitarias básicas
  - Prueba unitaria de la funcion (ej. toggleLED), verifica si la función hace cambia el valor existente de salida del GPIO
- Implementación de un estándar de código para el código fuente del framework y del programa "hola led" (ej. misraC o BARC-2018)
- Implementación de pruebas estáticas y verificación de código estándar (ej. cppcheck)
- Documento de referencia de la API (basado en el repositorio de CoDe Pretzel framework, probablemente con Doxygen o Sphinx)
  - Estipula los nombres de las funciones, sus parámetros, el scope y su forma de uso, puede ser algún ejemplo
- Entrada en la wiki de CoDe Pretzel, Guía del Desarrollador v1
  - Capitulo de incluir y compilar hola led
  - Capitulo de errores comunes
  - Capitulo hacer un hola led usando el framework
