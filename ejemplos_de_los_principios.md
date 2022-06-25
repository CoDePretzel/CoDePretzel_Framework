# Los objetivos se pueden aplicar de la siguiente manera:

Los siguientes elementos definen un poco mejor los elementos que atañen a cada punto entre paréntesis.
ej. (1,2) se refiere a los puntos 1. Estructura de código reusable, 2. Forma de organizar tu proyecto

## Desarrollo de software colaborativo (2, 3)
- Colaboración en github (pull requests y branches para cada funcionalidad)
- Code reviews para aprobar los pull requests
- Merge conflicts

## Aseguramiento de la calidad (1, 2, 3)
- Análisis estático
- Enforzamiento del estándar BarrC-2018
- Pruebas unitarias

## Desarrollo modular (1)
- Desarrollo impulsado por pruebas (para embedded)

## Automatización del proceso de desarrollo (3)
- Automatización de pruebas y compilación en jenkins
- Deploy conectado a Jenkins con Artifactory

## Técnicas usadas en industria (4)
- Desarrollo de bootloaders (UART o SPI)
- Uso de filtros digitales (algún otro que no sea promedio)
- Uso de Formato Q (Q15 por ejemplo) (Número fraccionario representado en un número entero)
- Abstracción de hardware multicapas (APIs y HALs)
- Machine Learning en Embedded (Edge devices, probablemente con TinyML/TFLight)
- Configuración y uso de Watchdog timers
- Implementación de máquinas de estados
- Manejo de información por interrupciones sin variables globales (y posteriormente interrupciones anidadas)
- Uso de JTAG para acceso a opciones avanzadas de depuración
- Implementación básica de modos de bajo consumo (sleep mode)

## periféricos usados en industria (4)
- ADC
- PWM
- I2C
- SPI
- QEI


Sin embargo, estamos conscientes de que es una cantidad de trabajo enorme, sobre todo si pensamos que solo podremos desarrollar proyectos hasta tener esta infraestructura lista.
Por lo que hemos pensado en ir implementando diferentes elementos de la misma a través de pequeños proyectos que a su vez también nos permitan practicar y aprender.
