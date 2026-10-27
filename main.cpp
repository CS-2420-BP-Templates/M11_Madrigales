// ============================================================================
//  LABORATORIO: Algoritmos de ordenamiento — La familia Madrigal 🕯️🦋
// ============================================================================
//  Curso:   Estructuras de Datos / Programación II
//  Tema:    La Casita Madrigal necesita ordenar su árbol genealógico.
//
//  HISTORIA:
//  Abuela Alma quiere preparar la ofrenda familiar y necesita que los
//  miembros de la familia estén ordenados de distintas formas: por nombre,
//  por edad y por su don. ¡Tu misión es implementar los algoritmos de
//  ordenamiento para ayudarla!
//
//  INSTRUCCIONES:
//  1. Busca todos los comentarios que dicen "TODO".
//  2. Completa los algoritmos en orden: Bubble -> Selection -> Insertion
//     -> Merge -> Quick.
//  3. Cada algoritmo debe usar la función `menorQue` que recibe como
//     parámetro, para poder ordenar por distintos criterios.
//  4. Cada vez que COMPARES dos elementos usa:  est.comparaciones++;
//     Cada vez que INTERCAMBIES o MUEVAS un elemento usa: est.movimientos++;
//  5. Ejecuta el programa. Si todo está bien verás ✅ en cada algoritmo.
//  6. Responde las preguntas de reflexión al final de este archivo.
//
//  NO modifiques las secciones marcadas como "NO TOCAR".
// ============================================================================

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#ifdef _WIN32
#include <windows.h>  // Para mostrar tildes y emojis en la consola de Windows
#endif

using namespace std;

// ============================================================================
//  ESTRUCTURAS DE DATOS (NO TOCAR)
// ============================================================================

struct Madrigal {
    string nombre;
    int edad;
    string don;  // "Sin don" si no tiene
    bool vive;   // false = aparece en la ofrenda del Día de Muertos 🌼
};

// Para medir el trabajo que hace cada algoritmo
struct Estadisticas {
    long long comparaciones = 0;
    long long movimientos = 0;
};

// Tipo de función que decide si a debe ir ANTES que b
using Comparador = bool (*)(const Madrigal& a, const Madrigal& b);

// ============================================================================
//  CRITERIOS DE ORDENAMIENTO
// ============================================================================

// Ya implementado: orden alfabético por nombre (A -> Z)
bool porNombre(const Madrigal& a, const Madrigal& b) {
    return a.nombre < b.nombre;
}

// Ya implementado: de menor a mayor edad
bool porEdad(const Madrigal& a, const Madrigal& b) {
    return a.edad < b.edad;
}

// TODO 1: Implementa el criterio "porDon".
//   - Ordena alfabéticamente por el campo `don` (A -> Z).
//   - Si dos personas tienen el mismo don, desempata por nombre.
//   Pista: puedes reutilizar la función porNombre.
bool porDon(const Madrigal& a, const Madrigal& b) {
    // TODO: reemplaza esta línea con tu código
    return false;
}

// ============================================================================
//  DATOS DE LA FAMILIA (NO TOCAR)
//  Nota: las edades son aproximadas y se usan solo con fines didácticos.
// ============================================================================

vector<Madrigal> crearFamilia() {
    return {
        {"Abuela Alma", 70, "Sin don", true},
        {"Abuelo Pedro", 72, "Sin don", false},  // En la ofrenda 🕯️
        {"Julieta", 50, "Curar con comida", true},
        {"Agustin", 52, "Sin don", true},
        {"Pepa", 48, "Controlar el clima", true},
        {"Felix", 49, "Sin don", true},
        {"Bruno", 46, "Ver el futuro", true},
        {"Isabela", 21, "Hacer crecer flores", true},
        {"Dolores", 18, "Oido sobrehumano", true},
        {"Camilo", 16, "Cambiar de forma", true},
        {"Luisa", 19, "Fuerza sobrehumana", true},
        {"Mirabel", 15, "Sin don", true},
        {"Antonio", 8, "Hablar con animales", true},
    };
}

// ============================================================================
//  UTILIDADES (NO TOCAR)
// ============================================================================

void imprimirFamilia(const vector<Madrigal>& familia, int limite = -1) {
    cout << left << setw(16) << "Nombre" << setw(7) << "Edad"
         << setw(24) << "Don" << "Estado\n";
    cout << string(55, '-') << "\n";
    int n = (limite < 0 || limite > (int)familia.size()) ? (int)familia.size() : limite;
    for (int i = 0; i < n; i++) {
        const Madrigal& m = familia[i];
        cout << left << setw(16) << m.nombre << setw(7) << m.edad
             << setw(24) << m.don << (m.vive ? "Vive" : "En la ofrenda 🕯️") << "\n";
    }
    cout << "\n";
}

bool estaOrdenado(const vector<Madrigal>& v, Comparador menorQue) {
    for (size_t i = 1; i < v.size(); i++) {
        // Si v[i] debe ir antes que v[i-1], el arreglo NO está ordenado
        if (menorQue(v[i], v[i - 1])) return false;
    }
    return true;
}

// ============================================================================
//  ALGORITMO 1: ORDENAMIENTO BURBUJA (Bubble Sort)
// ============================================================================
// Idea: recorre el arreglo comparando pares de vecinos y los intercambia si
// están en el orden incorrecto. En cada pasada, el elemento "más grande"
// sube al final como una burbuja.
//
// TODO 2: Implementa Bubble Sort.
//   - Usa dos ciclos for anidados.
//   - Por cada comparación:  est.comparaciones++;
//   - Por cada intercambio (swap):  est.movimientos++;
//   - BONUS: agrega una bandera `huboIntercambio` para detener el algoritmo
//     si en una pasada completa no se intercambió nada.
void ordenamientoBurbuja(vector<Madrigal>& v, Comparador menorQue, Estadisticas& est) {
    // TODO: escribe tu código aquí
}

// ============================================================================
//  ALGORITMO 2: ORDENAMIENTO POR SELECCIÓN (Selection Sort)
// ============================================================================
// Idea: en cada paso, busca el elemento MÍNIMO del resto del arreglo y lo
// coloca en su posición correcta.
//
// TODO 3: Implementa Selection Sort.
//   - Para cada posición i, encuentra el índice `indiceMin` del menor
//     elemento entre i y el final.
//   - Al final de cada pasada, intercambia v[i] con v[indiceMin].
//   - Cuenta comparaciones y movimientos como en el ejercicio anterior.
//   Pregunta: ¿cuántos intercambios hace como máximo? (ver reflexión)
void ordenamientoSeleccion(vector<Madrigal>& v, Comparador menorQue, Estadisticas& est) {
    // TODO: escribe tu código aquí
}

// ============================================================================
//  ALGORITMO 3: ORDENAMIENTO POR INSERCIÓN (Insertion Sort)
// ============================================================================
// Idea: es como ordenar cartas en la mano. Toma un elemento y lo "inserta"
// en el lugar correcto dentro de la parte que ya está ordenada.
//
// TODO 4: Implementa Insertion Sort.
//   - Para i desde 1 hasta n-1: guarda `Madrigal clave = v[i];`
//   - Desplaza hacia la derecha los elementos mayores que `clave`.
//   - Coloca `clave` en su posición.
//   - Cuenta una comparación en cada evaluación de menorQue y un
//     movimiento en cada desplazamiento/colocación.
void ordenamientoInsercion(vector<Madrigal>& v, Comparador menorQue, Estadisticas& est) {
    // TODO: escribe tu código aquí
}

// ============================================================================
//  ALGORITMO 4: ORDENAMIENTO POR MEZCLA (Merge Sort)
// ============================================================================
// Idea: "divide y vencerás". Divide el arreglo en dos mitades, ordena cada
// mitad recursivamente y luego MEZCLA las dos mitades ya ordenadas.

// TODO 5: Implementa la función `mezclar`.
//   Mezcla las dos mitades ordenadas v[izq..medio] y v[medio+1..der].
//   Pasos sugeridos:
//     1. Copia cada mitad en un vector temporal (izquierda y derecha).
//     2. Con dos índices, toma siempre el menor de los dos frentes y
//        colócalo en v[k]. (Cuenta comparaciones y movimientos)
//     3. Copia los elementos sobrantes de la mitad que no se terminó.
//   OJO: usa `!menorQue(derecha[j], izquierda[i])` al comparar para que el
//   algoritmo sea ESTABLE (los iguales mantienen su orden original).
void mezclar(vector<Madrigal>& v, int izq, int medio, int der,
             Comparador menorQue, Estadisticas& est) {
    // TODO: escribe tu código aquí
}

// Ya implementado: la parte recursiva. Léela y entiéndela antes de seguir.
void mergeSortRec(vector<Madrigal>& v, int izq, int der,
                  Comparador menorQue, Estadisticas& est) {
    if (izq >= der) return;  // Caso base: 0 o 1 elemento
    int medio = izq + (der - izq) / 2;
    mergeSortRec(v, izq, medio, menorQue, est);
    mergeSortRec(v, medio + 1, der, menorQue, est);
    mezclar(v, izq, medio, der, menorQue, est);
}

void ordenamientoMezcla(vector<Madrigal>& v, Comparador menorQue, Estadisticas& est) {
    if (v.empty()) return;
    mergeSortRec(v, 0, (int)v.size() - 1, menorQue, est);
}

// ============================================================================
//  ALGORITMO 5: ORDENAMIENTO RÁPIDO (Quick Sort)
// ============================================================================
// Idea: elige un PIVOTE, coloca a su izquierda los elementos menores y a su
// derecha los mayores, y repite recursivamente en cada lado.

// TODO 6: Implementa la función `particionar` (esquema de Lomuto).
//   - Usa v[der] como pivote.
//   - Mantén un índice `i = izq - 1` que marca el final de la zona de
//     elementos menores al pivote.
//   - Recorre j desde izq hasta der-1: si menorQue(v[j], pivote), incrementa
//     i e intercambia v[i] con v[j].
//   - Al final, intercambia v[i+1] con v[der] y devuelve i+1
//     (la posición final del pivote).
int particionar(vector<Madrigal>& v, int izq, int der,
                Comparador menorQue, Estadisticas& est) {
    // TODO: escribe tu código aquí
    return izq;  // Valor temporal para que el programa compile
}

// Ya implementado: la parte recursiva.
void quickSortRec(vector<Madrigal>& v, int izq, int der,
                  Comparador menorQue, Estadisticas& est) {
    if (izq >= der) return;
    int posPivote = particionar(v, izq, der, menorQue, est);
    quickSortRec(v, izq, posPivote - 1, menorQue, est);
    quickSortRec(v, posPivote + 1, der, menorQue, est);
}

void ordenamientoRapido(vector<Madrigal>& v, Comparador menorQue, Estadisticas& est) {
    if (v.empty()) return;
    quickSortRec(v, 0, (int)v.size() - 1, menorQue, est);
}

// ============================================================================
//  PRUEBAS (NO TOCAR)
// ============================================================================

using Algoritmo = void (*)(vector<Madrigal>&, Comparador, Estadisticas&);

void probarAlgoritmo(const string& titulo, Algoritmo algoritmo,
                     const vector<Madrigal>& original, Comparador criterio) {
    vector<Madrigal> copia = original;  // Cada algoritmo trabaja con su copia
    Estadisticas est;
    algoritmo(copia, criterio, est);

    bool ok = estaOrdenado(copia, criterio) && copia.size() == original.size();
    cout << (ok ? "✅ " : "❌ ") << left << setw(12) << titulo
         << " | comparaciones: " << setw(5) << est.comparaciones
         << " | movimientos: " << setw(5) << est.movimientos << "\n";
}

void ejecutarPruebas(const string& nombreCriterio, const vector<Madrigal>& familia,
                     Comparador criterio) {
    cout << "\n=== Criterio: " << nombreCriterio << " ===\n";
    probarAlgoritmo("Burbuja", ordenamientoBurbuja, familia, criterio);
    probarAlgoritmo("Seleccion", ordenamientoSeleccion, familia, criterio);
    probarAlgoritmo("Insercion", ordenamientoInsercion, familia, criterio);
    probarAlgoritmo("Mezcla", ordenamientoMezcla, familia, criterio);
    probarAlgoritmo("Rapido", ordenamientoRapido, familia, criterio);
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    cout << "🕯️  Bienvenido a la Casita Madrigal  🦋\n";
    cout << "Abuela Alma necesita tu ayuda para ordenar a la familia.\n\n";

    vector<Madrigal> familia = crearFamilia();

    cout << "Familia SIN ordenar:\n";
    imprimirFamilia(familia);

    // --- Pruebas con los tres criterios ---
    ejecutarPruebas("Nombre (A-Z)", familia, porNombre);
    ejecutarPruebas("Edad (menor a mayor)", familia, porEdad);
    ejecutarPruebas("Don (A-Z)", familia, porDon);

    // --- Demostración visual con el algoritmo que prefieras ---
    // TODO 7: Cambia `ordenamientoInsercion` por el algoritmo que quieras y
    //         ordena la familia por edad para mostrarla en la ofrenda
    //         (de la persona mayor a la menor).
    //   Pista: no necesitas escribir otro algoritmo. Escribe un NUEVO
    //   comparador `porEdadDescendente` (arriba, junto a los otros) y úsalo.
    vector<Madrigal> ofrenda = familia;
    Estadisticas estOfrenda;
    ordenamientoInsercion(ofrenda, porEdad, estOfrenda);  // <- modifica esta línea

    cout << "\n🌼 Orden de la ofrenda familiar:\n";
    imprimirFamilia(ofrenda);

    // --- RETO EXTRA (opcional) ---
    // TODO 8 (BONUS): Agrega un criterio `porVivosPrimero` que coloque primero
    //   a los miembros que viven y después a los de la ofrenda, y dentro de
    //   cada grupo ordene por edad. Pruébalo con ejecutarPruebas(...).

    cout << "\n¡Que la magia de la Casita te acompañe! 🦋\n";
    return 0;
}

// ============================================================================
//  PREGUNTAS DE REFLEXIÓN (responde en tu README o en comentarios)
// ============================================================================
//  1. ¿Cuál algoritmo hizo MENOS comparaciones con la familia ordenada por
//     edad? ¿Y MÁS? ¿Por qué crees que ocurrió?
//  2. Selection Sort hace pocos movimientos comparado con Bubble Sort. ¿Por qué?
//  3. ¿Qué pasaría con Insertion Sort si el arreglo YA estuviera ordenado?
//     Compruébalo ejecutando el algoritmo dos veces seguidas.
//  4. ¿Qué significa que un algoritmo sea "estable"? ¿Cuáles de los cinco lo
//     son? Pista: observa el orden de las personas con "Sin don" al ordenar
//     por don con tu implementación.
//  5. Con solo 13 personas, ¿notas diferencias de rendimiento? ¿Qué pasaría
//     con 100,000 personas? Relaciona tu respuesta con O(n²) y O(n log n).
// ============================================================================
