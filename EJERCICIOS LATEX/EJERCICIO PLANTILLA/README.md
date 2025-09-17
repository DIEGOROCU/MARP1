# Plantilla para Presentaciones Beamer

Esta carpeta contiene una plantilla completa para crear presentaciones profesionales usando LaTeX y la clase Beamer.

## Estructura de archivos

```
EJERCICIO PLANTILLA/
├── presentacion.tex     # Archivo principal de la presentación
├── Makefile            # Archivo para compilación automática
├── README.md           # Este archivo de instrucciones
├── referencias.bib     # Archivo de bibliografía (opcional)
├── images/             # Carpeta para imágenes
│   └── .gitkeep       # Mantiene la carpeta en Git
└── output/             # Carpeta para archivos generados
    └── .gitkeep       # Mantiene la carpeta en Git
```

## Requisitos

Para usar esta plantilla necesitas tener instalado:

- **LaTeX** (distribución completa como TeX Live o MiKTeX)
- **pdflatex** (incluido en las distribuciones LaTeX)
- **make** (opcional, para usar el Makefile)

### Instalación en Ubuntu/Debian
```bash
sudo apt-get update
sudo apt-get install texlive-full
```

### Instalación en Windows
Descarga e instala [MiKTeX](https://miktex.org/) o [TeX Live](https://www.tug.org/texlive/)

### Instalación en macOS
```bash
# Con Homebrew
brew install mactex
```

## Uso rápido

### Opción 1: Usando Makefile (recomendado)
```bash
# Compilar la presentación
make

# Ver el PDF generado
make view

# Limpiar archivos auxiliares
make clean

# Ver todos los comandos disponibles
make help
```

### Opción 2: Compilación manual
```bash
pdflatex presentacion.tex
pdflatex presentacion.tex  # Segunda pasada para referencias cruzadas
```

## Personalización

### Información básica
Edita las siguientes líneas en `presentacion.tex`:
```latex
\title{Título de la Presentación}
\subtitle{Subtítulo (opcional)}
\author{Tu Nombre}
\institute{Universidad/Institución}
\date{\today}
```

### Cambiar tema
Puedes cambiar el tema de la presentación modificando:
```latex
\usetheme{Madrid}        % Otros: Berlin, Warsaw, Frankfurt, etc.
\usecolortheme{default}  % Otros: dolphin, rose, orchid, etc.
```

### Agregar logo
Descomenta y modifica esta línea:
```latex
\logo{\includegraphics[height=1cm]{images/logo.png}}
```

## Estructura de una presentación

La plantilla incluye ejemplos de:

1. **Diapositiva de título** - Página principal con información del autor
2. **Tabla de contenidos** - Índice automático de secciones
3. **Secciones y subsecciones** - Organización del contenido
4. **Listas** - Viñetas y enumeraciones
5. **Bloques especiales** - Definiciones, alertas, ejemplos
6. **Matemáticas** - Ecuaciones en línea y centradas
7. **Código** - Sintaxis resaltada con `listings`
8. **Imágenes** - Inclusión de figuras
9. **Tablas** - Presentación de datos tabulares
10. **Referencias** - Bibliografía al final

## Consejos para presentaciones efectivas

### Contenido
- **Una idea por diapositiva** - No sobrecargues las diapositivas
- **Usa viñetas** - Facilita la lectura
- **Incluye ejemplos** - Clarifica conceptos abstractos
- **Numera las diapositivas** - Ayuda en las preguntas del público

### Diseño
- **Fuente legible** - Tamaño mínimo 24pt para el texto principal
- **Contraste alto** - Texto oscuro sobre fondo claro
- **Consistencia** - Usa el mismo estilo en toda la presentación
- **Imágenes de calidad** - Preferiblemente vectoriales o alta resolución

### Matemáticas
```latex
% Ecuación en línea
La fórmula $E = mc^2$ es famosa.

% Ecuación centrada
\begin{equation}
    \int_{-\infty}^{\infty} e^{-x^2} dx = \sqrt{\pi}
\end{equation}

% Sistema de ecuaciones
\begin{align}
    x + y &= 5 \\
    2x - y &= 1
\end{align}
```

### Código
```latex
\begin{lstlisting}[language=Python]
def hello_world():
    print("¡Hola, mundo!")
\end{lstlisting}
```

### Imágenes
```latex
\begin{figure}
    \centering
    \includegraphics[width=0.8\textwidth]{images/mi_imagen.png}
    \caption{Descripción de la imagen}
\end{figure}
```

## Solución de problemas

### Error: "Package not found"
Instala el paquete faltante o usa una distribución LaTeX completa.

### Error: "Image not found"
Verifica que la ruta de la imagen sea correcta y que el archivo exista.

### La compilación se cuelga
Usa la opción `-interaction=nonstopmode` o revisa los errores en el archivo `.log`.

### Caracteres especiales no se ven
Asegúrate de usar `\usepackage[utf8]{inputenc}` y `\usepackage[spanish]{babel}`.

## Recursos adicionales

- [Documentación oficial de Beamer](https://ctan.org/pkg/beamer)
- [Galería de temas Beamer](https://hartwork.org/beamer-theme-matrix/)
- [LaTeX Wikibook](https://en.wikibooks.org/wiki/LaTeX)
- [Overleaf - Editor LaTeX online](https://www.overleaf.com/)

## Licencia

Esta plantilla es de dominio público. Puedes usarla, modificarla y distribuirla libremente.