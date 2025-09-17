# Guía Rápida de Comandos LaTeX para Beamer

## Estructura básica

```latex
\begin{frame}{Título de la diapositiva}
    Contenido de la diapositiva
\end{frame}
```

## Listas

### Lista con viñetas
```latex
\begin{itemize}
    \item Primer elemento
    \item Segundo elemento
        \begin{itemize}
            \item Sub-elemento
        \end{itemize}
\end{itemize}
```

### Lista numerada
```latex
\begin{enumerate}
    \item Primer elemento
    \item Segundo elemento
\end{enumerate}
```

## Bloques especiales

```latex
\begin{block}{Título del bloque}
    Contenido normal
\end{block}

\begin{alertblock}{Atención}
    Contenido importante
\end{alertblock}

\begin{exampleblock}{Ejemplo}
    Contenido de ejemplo
\end{exampleblock}
```

## Matemáticas

```latex
% Ecuación en línea
La velocidad de la luz es $c = 3 \times 10^8$ m/s.

% Ecuación centrada
\begin{equation}
    E = mc^2
\end{equation}

% Múltiples ecuaciones
\begin{align}
    x &= a + b \\
    y &= c + d
\end{align}
```

## Imágenes

```latex
\begin{figure}
    \centering
    \includegraphics[width=0.7\textwidth]{images/archivo.png}
    \caption{Descripción de la imagen}
\end{figure}
```

## Tablas

```latex
\begin{table}
    \centering
    \begin{tabular}{|c|c|c|}
        \hline
        \textbf{Columna 1} & \textbf{Columna 2} & \textbf{Columna 3} \\
        \hline
        Dato 1 & Dato 2 & Dato 3 \\
        \hline
    \end{tabular}
    \caption{Título de la tabla}
\end{table}
```

## Formato de texto

```latex
\textbf{Negrita}
\textit{Cursiva}
\texttt{Monoespaciado}
\textcolor{red}{Texto en rojo}
\underline{Subrayado}
```

## Columnas

```latex
\begin{columns}
    \begin{column}{0.5\textwidth}
        Contenido de la primera columna
    \end{column}
    \begin{column}{0.5\textwidth}
        Contenido de la segunda columna
    \end{column}
\end{columns}
```

## Código

```latex
% Código en línea
\lstinline{print("Hola")}

% Bloque de código
\begin{lstlisting}[language=Python]
def funcion():
    return "Hola mundo"
\end{lstlisting}
```

## Animaciones (overlay)

```latex
\begin{itemize}
    \item<1-> Aparece en la primera diapositiva
    \item<2-> Aparece en la segunda
    \item<3-> Aparece en la tercera
\end{itemize}

% También funciona con otros elementos
\only<2->{Texto que solo aparece desde la segunda diapositiva}
```

## Secciones

```latex
\section{Nombre de la sección}
\subsection{Nombre de la subsección}
```

## Notas para el presentador

```latex
\note{Esta es una nota que solo verá el presentador}
```

## Bibliografía

```latex
% En el texto
Como menciona \cite{autor2023}...

% Al final de la presentación
\begin{frame}{Referencias}
    \bibliography{referencias}
    \bibliographystyle{plain}
\end{frame}
```