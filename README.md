# MARP1 - Métodos Algorítmicos de Resolución de Problemas 1

Asignatura del Grado en Informática de la Universidad Complutense de Madrid (UCM).

## 📚 Descripción

Este repositorio contiene la resolución de ejercicios y trabajos de la asignatura **MARP1**, enfocada en el desarrollo de habilidades algorítmicas y técnicas de resolución de problemas mediante programación. Se trabaja con estructuras de datos avanzadas, algoritmos de grafos, optimización y técnicas de análisis de complejidad.

## 📁 Estructura del Repositorio

### 1. **EJERCICIOS LATEX** - Problemas Teóricos
Ejercicios propuestos en fichas de trabajo, resueltos con documentación en LaTeX:

- **Hoja 1:**
  - 2 Ejercicios de análisis de costes amortizados

- **Hoja 3:**
  - 2 Ejercicios de montículos

- **Hoja 4:**
  - 2 Ejercicios de grafos

- **Hoja 5:**
  - 2 Ejercicios de resoluciones voraces

Cada ejercicio incluye:
- Archivo `.tex` con la solución documentada
- Bibliografía en `referencias.bib`
- Estilo personalizado en `estilo.tex`
- Imágenes y diagramas en carpeta `images/`
- Output PDF compilado en carpeta `output/`

### 2. **JUEZ** - Problemas de Programación
Sistema de ejercicios prácticos basados en un juez automático.

#### **EJERCICIOS** (41 problemas)
Ejercicios de programación (EJ1 a EJ41) con las siguientes características:
- Resolución de problemas algorítmicos
- Validación automática mediante juez online
- Énfasis en eficiencia y corrección

#### **CLASES** - Estructuras de Datos
Implementación de TADs (Tipos Abstractos de Datos) fundamentales en C++:
- `bintree.h` - Árboles binarios
- `Grafo.h` - Grafos no ponderados
- `GrafoValorado.h` - Grafos ponderados
- `Digrafo.h` - Dígrafos (grafos dirigidos)
- `DigrafoValorado.h` - Dígrafos ponderados
- `ConjuntosDisjuntos.h` - Unión-Búsqueda (Union-Find)
- `TreeSet_AVL.h` - Árboles AVL
- `Matriz.h` - Operaciones con matrices
- `EnterosInf.h` - Enteros con valor infinito
- `PriorityQueue.h` - Cola de prioridad
- `IndexPQ.h` - Cola de prioridad indexada

#### **PLANTILLAS**
Plantillas de código reutilizable para resolver problemas comunes.

## 🎯 Competencias Desarrolladas

- ✅ Análisis de complejidad de algoritmos (O grande, Theta, Omega)
- ✅ Implementación de estructuras de datos complejas
- ✅ Algoritmos en grafos (BFS, DFS, Dijkstra, Floyd-Warshall, etc.)
- ✅ Técnicas de programación dinámica y voraz
- ✅ Optimización de soluciones algorítmicas
- ✅ Resolución eficiente de problemas bajo restricciones de tiempo y memoria
- ✅ Documentación técnica en LaTeX

## 🛠️ Herramientas Utilizadas

- **Lenguaje:** C++
- **Compilador:** g++ (MinGW UCRT64)
- **Documentación:** LaTeX
- **Control de versiones:** Git
- **IDE:** VS Code

## 📝 Cómo Usar

### Para compilar los ejercicios de programación:
```bash
cd JUEZ/EJERCICIOS/EJ[N]
g++ -o solucion solucion.cpp
./solucion
```

### Para compilar los documentos LaTeX:
```bash
cd "EJERCICIOS LATEX/EJERCICIO Hoja[N]-[M]"
make
```

## 📊 Progreso

- [x] Ejercicios de las 5 primeras hojas teóricas
- [x] 41 problemas de programación del juez
- [x] Implementación de TADs fundamentales
- [x] Preparación con problemas de examen

## 👤 Autor

Diego RC - Estudiante de Grado doble grado en Ingenieria Informatica y Matemáticas, UCM

---

*Última actualización: Enero 2026, temario TERMINADO*
