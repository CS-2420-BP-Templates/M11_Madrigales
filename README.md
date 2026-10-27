# M11_Madrigales
# 🕯️ Laboratorio: Algoritmos de ordenamiento — La familia Madrigal 🦋

Abuela Alma está preparando la ofrenda familiar y necesita tu ayuda para ordenar a toda la familia Madrigal: por nombre, por edad y por su don. En este laboratorio implementarás cinco algoritmos de ordenamiento en **C++** y compararás cuánto trabajo hace cada uno.

## 🎯 Objetivos de aprendizaje

- Implementar los algoritmos de ordenamiento Burbuja, Selección, Inserción, Mezcla (Merge Sort) y Rápido (Quick Sort).
- Usar **punteros a función** como comparadores para ordenar por distintos criterios.
- Medir comparaciones y movimientos para analizar la eficiencia de cada algoritmo.
- Comprender el concepto de **estabilidad** y la diferencia entre O(n²) y O(n log n).

## 📁 Estructura del proyecto

```
.
├── CMakeLists.txt   # Configuración del proyecto (CLion la detecta sola)
├── main.cpp         # Código base con los TODO que debes completar
└── README.md        # Este archivo
```

## ⚙️ Cómo empezar (CLion)

1. Clona este repositorio o ábrelo desde **File → New → Project from Version Control**.
2. CLion detectará el `CMakeLists.txt` y configurará el proyecto. Si aparece un aviso, haz clic en **Load CMake Project**.
3. Abre la pestaña **TODO** (abajo a la izquierda, o **View → Tool Windows → TODO**) para ver todas las tareas pendientes.
4. Selecciona la configuración `lab_ordenamiento` y presiona ▶️ **Run**.
5. Al principio verás ❌ en todos los algoritmos. Tu meta es que todos muestren ✅.

> 💡 **Consola en Windows:** si ves símbolos extraños en lugar de tildes o emojis, revisa que el archivo esté guardado en UTF-8 (**File → File Encoding**).

## ✅ Lista de TODOs

Completa las tareas en orden. Cada una aparece marcada con `// TODO N` en `main.cpp`.

| # | Dónde | Tarea | Dificultad |
|---|-------|-------|:----------:|
| 1 | `porDon` | Comparador que ordene por el campo `don` (A→Z) y desempate por nombre. | ⭐ |
| 2 | `ordenamientoBurbuja` | Implementar **Bubble Sort** con dos ciclos anidados. Cuenta comparaciones y movimientos. *Bonus:* detenerse si una pasada no hace intercambios. | ⭐ |
| 3 | `ordenamientoSeleccion` | Implementar **Selection Sort**: buscar el mínimo del resto del arreglo e intercambiarlo con la posición actual. | ⭐⭐ |
| 4 | `ordenamientoInsercion` | Implementar **Insertion Sort**: guardar la clave, desplazar los mayores a la derecha e insertar la clave en su lugar. | ⭐⭐ |
| 5 | `mezclar` | Implementar la fase de mezcla de **Merge Sort**: copiar las dos mitades a vectores temporales y combinarlas en orden. Usa `!menorQue(derecha[j], izquierda[i])` para mantener la estabilidad. | ⭐⭐⭐ |
| 6 | `particionar` | Implementar la partición de **Quick Sort** (esquema de Lomuto) con `v[der]` como pivote. Devuelve la posición final del pivote. | ⭐⭐⭐ |
| 7 | `main` | Crear el comparador `porEdadDescendente` y usarlo para mostrar la ofrenda de la persona mayor a la menor. | ⭐ |
| 8 | `main` | 🌟 **Bonus:** crear `porVivosPrimero` (vivos primero, luego los de la ofrenda; dentro de cada grupo, por edad) y probarlo con `ejecutarPruebas`. | ⭐⭐ |

### Reglas para contar el trabajo de cada algoritmo

Para que las estadísticas sean comparables, todos deben contar igual:

- Cada vez que llames a `menorQue(...)`: `est.comparaciones++;`
- Cada intercambio, desplazamiento o colocación de un elemento: `est.movimientos++;`

## 🖥️ Salida esperada

Cuando termines, cada criterio mostrará algo parecido a esto (los números exactos dependen de tu implementación):

```
=== Criterio: Nombre (A-Z) ===
✅ Burbuja      | comparaciones: ...   | movimientos: ...
✅ Seleccion    | comparaciones: ...   | movimientos: ...
✅ Insercion    | comparaciones: ...   | movimientos: ...
✅ Mezcla       | comparaciones: ...   | movimientos: ...
✅ Rapido       | comparaciones: ...   | movimientos: ...
```

Además, al final se imprimirá la tabla de la ofrenda familiar ordenada.

## 🚫 Reglas del laboratorio

- **No modifiques** las secciones marcadas como `NO TOCAR`.
- **No uses** `std::sort`, `std::stable_sort` ni otras funciones de ordenamiento de la biblioteca estándar para resolver los TODO.
- Puedes crear funciones auxiliares (por ejemplo, un `intercambiar`), siempre que respetes las firmas existentes.
- Comenta tu código: explica con tus palabras qué hace cada bloque importante.

## 🤔 Preguntas de reflexión

Responde en un archivo `REFLEXION.md` (o como comentarios al final de `main.cpp`):

1. ¿Qué algoritmo hizo **menos** comparaciones con la familia ordenada por edad? ¿Y cuál **más**? ¿Por qué crees que ocurrió?
2. Selection Sort hace pocos movimientos comparado con Bubble Sort. ¿Por qué?
3. ¿Qué pasa con Insertion Sort si el arreglo **ya está ordenado**? Compruébalo ejecutando el algoritmo dos veces seguidas.
4. ¿Qué significa que un algoritmo sea **estable**? ¿Cuáles de los cinco lo son? Pista: observa el orden de las personas con "Sin don" al ordenar por don.
5. Con solo 13 personas, ¿notas diferencias de rendimiento? ¿Qué pasaría con 100,000 personas? Relaciona tu respuesta con O(n²) y O(n log n).

## 📤 Entrega

1. Verifica que los cinco algoritmos muestren ✅ para los tres criterios.
2. Haz *commit* y *push* de tu trabajo a tu repositorio.
3. Incluye tu archivo de reflexión.

### Este README fue generado por Claude, 10/20/2026
