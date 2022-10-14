Scripts de configuración, integración y automatización
====================================================

Scripts de configuración
--------

Como agregar un framework a platformIO

1. Agregar la nueva plataforma al archivo platform.json
    ubicado en (windows): 
     **~/.platformio/platforms/atmelavr.**
    tanto en la seccion de frameworks y packages.

.. code-block::
   :caption: Ejemplo de archivo:

    ...
        "frameworks": {
        ...
        "codepretzel": {
            "package": "framework-codepretzel",
            "script": "builder/frameworks/codepretzel.py"
            },
        ...
        "packages":{
         ...
          "framework-codepretzel": {
            "type": "toolchain",
            "owner": "codepretzel",
            "version": "~1.70300.0"
            },
          ...
        }
        ...

2.  Crear una carpeta para el framework:
    **~/.platformio/packages/framework-codepretzel**
   
   * Agregar  **package.json** en:
    **~/.platformio/packages/framework-codepretzel**
    con el siguiente texto:

   .. code-block::
    :caption: Agregar el siguiente texto que corresponde al framework:
            {
                "description": "codepretzel",
                "name": "framework-codepretzel",
                "system": "*",
                "url": "...",
                "version": "1.1.0"
            }

3. Escribir el script de compilación para framework-codepretzel,
    usando PlatformIO Build System API.
    Mas `ejemplos <https://github.com/platformio?utf8=%E2%9C%93&query=platform->` _.
    .. code-block::
      :caption: Ruta para el script de compilacion:
            ~/.platformio/platforms/atmelavr/builder/frameworks/codepretzel.py

4. Agrega soporte para el framework CodePretzel a uno de los boards
    Mas `ejemplos <https://github.com/platformio/platform-espressif/blob/develop/boards/esp01.json>` _.
    .. code-block::
         "frameworks": [
         "arduino", 
         "simba",
         "sming"
        ],

5. Construir el proyecto via 
    .. code-block::
        platformio run

    .. code-block::
        [env:smingtest]
        platform = espressif
        framework = sming
        board = esp01

6. Fin, disfruta del nuevo framework :v
