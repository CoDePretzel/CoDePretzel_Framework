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

## 1.0.0

- Requerimientos para la instalación y configuración del framework
- Guía de usuario para descarga, configuración e instalación del framework
  - Incluyendo la generación de código de drivers por el generador de código del fabricante (Ej. Microchip Harmony, Renesas Synergy, STM32CubeMX)
- Un programa con main loop, que permita configurar
