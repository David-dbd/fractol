<p align="center">
  <a href="README.md">🇪🇸 Español</a> • <a href="README.en.md">🇺🇸 English</a>
</p>

<h1>Fractol</h1>
Fractol es un proyecto en C que ilustra fractales en tiempo real utilizando la librería MiniLibX y conceptos de matemática compleja.
Se trabajan fractales como Mandelbrot, Julia y Burning Ship, los cuales se generan aplicando iteraciones sobre números complejos para cada pixel de la pantalla.
---
---
<br>
<br>
<img width="500" height="400" alt="Screenshot from 2025-07-30 15-01-20" src="https://github.com/user-attachments/assets/e90fe2e2-f536-4bf3-9553-2c95f851b3aa" />
<img width="500" height="400" alt="Screenshot from 2025-07-30 15-02-59" src="https://github.com/user-attachments/assets/7cfa6c05-6011-44b6-8f05-e959924d9040" />
<img width="500" height="400" alt="Screenshot from 2025-07-30 15-03-32" src="https://github.com/user-attachments/assets/6af28500-dcce-4ccd-a0c1-000f56d3aec2" />
<img width="500" height="400" alt="Screenshot from 2025-07-30 15-04-22" src="https://github.com/user-attachments/assets/9f22a5e7-749e-415c-a331-fe2e23444386" />
<img width="1000" height="400" alt="Screenshot from 2025-07-30 15-05-31" src="https://github.com/user-attachments/assets/ed3c11d1-6cb8-4447-9fd0-75f8be18a7c8" />
---
<br>
<br>
## 📚 Teoría y Contexto

Un **fractal** es un conjunto definido por una iteración matemática.
Partimos de la fórmula general:

$$
Z_{n+1} = Z_n^2 + C
$$

Donde **Z** y **C** son números complejos de la forma $x + yi$.
Si al iterar repetidamente, $|Z|$ supera **2**, decimos que el punto escapa.
De lo contrario, si se mantiene acotado hasta el máximo de iteraciones, pertenece al fractal.

Para optimizar, reemplazamos `sqrt` y `pow` con álgebra compleja:

$$
(x + yi)^2 = (x^2 - y^2) + 2xyi
$$

y verificamos escape con:

$$
|Z|^2 = x^2 + y^2
$$

Si $x^2 + y^2 > 4$, el punto escapa, evitando cálculos costosos.

---

## ⚙️ Pasos del Renderizado

### 1️⃣ Inicializar la interfaz visual con `mlx_init`

* **Código:**

  ```c
  void *mlx = mlx_init();
  ```

* **Descripción:**
  Inicializar la librería MiniLibX es el primer paso porque nos permite conectarnos con el servidor gráfico de nuestro sistema operativo.
  Sin esta inicialización, no podemos crear ventanas ni imágenes en memoria.
  Básicamente, `mlx_init()` establece el “contexto gráfico” que manejará todos los recursos durante la vida del programa.
  Desde este momento, cada operación de dibujo, creación de ventanas e imágenes dependerá de este puntero `mlx`.

---

### 2️⃣ Crear la ventana y la imagen

* **Código:**

  ```c
  void *win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fractol");
  void *img = mlx_new_image(mlx, WIDTH, HEIGHT);
  ```

* **Descripción:**
  La **ventana** es el área visible donde finalmente mostraremos el fractal.
  La **imagen** es diferente: es un **buffer en memoria** donde dibujamos píxel por píxel antes de renderizarlo en pantalla.
  Este enfoque evita parpadeos y nos da control total sobre los colores.
  Cada pixel de la imagen ocupa **4 bytes (RGBA)**, lo que nos permitirá manipular los colores de forma precisa.

---

### 3️⃣ Obtener el buffer de imagen con `mlx_get_data_addr`

* **Código:**

  ```c
  char *ptr_buf_img;
  int bpp, size_l, endian;
  ptr_buf_img = mlx_get_data_addr(img, &bpp, &size_l, &endian);
  ```

* **Descripción:**
  En este paso accedemos directamente al **bloque de memoria** donde vive la imagen.
  `bpp` nos dice cuántos bits ocupa cada pixel (normalmente 32), `size_l` es el tamaño en bytes de cada fila, y `ptr_buf_img` es el puntero al primer byte del buffer.
  Al trabajar a nivel de bytes, podemos escribir colores sin depender de funciones externas, pixel a pixel, usando aritmética de punteros.
  Esto también nos permite optimizar el rendimiento y tener un control preciso sobre la imagen final.

---

### 4️⃣ Mapear cada pixel al plano complejo

* **Descripción:**
  Cada pixel `(px, py)` de la ventana debe convertirse a un número complejo `(x + yi)` para poder evaluar la fórmula del fractal.
  Para ello, definimos un **marco (viewport)** que corresponde al área donde el fractal es visible.
  Por ejemplo, para Mandelbrot usamos:

  * Real: \[-2.0, 1.0]
  * Imaginario: \[-1.5, 1.5]

  Luego escalamos linealmente la posición del pixel a este rango.
  Así, cada punto en pantalla se transforma en un número complejo único que será evaluado.

---

### 5️⃣ Iterar la fórmula $Z^2 + C$ y determinar escape

* **Descripción:**
  Aquí aplicamos la **iteración fundamental** de los fractales:

  $$
  Z_{n+1} = Z_n^2 + C
  $$

  donde desarrollamos el cuadrado con álgebra compleja:

  * Real: $x^2 - y^2 + Re(C)$
  * Imaginaria: $2xy + Im(C)$

  Repetimos esto hasta que:

  1. $x^2 + y^2 > 4$ → el punto escapa
  2. O alcanzamos el máximo de iteraciones → se considera dentro del fractal

  Este bucle es el corazón del proyecto, ya que define la forma final del fractal en pantalla.

---

### 6️⃣ Asignar color según la iteración

* **Descripción:**
  Una vez determinado si el punto escapa o no, elegimos un color.
  Si **no escapa**, pintamos el pixel de **negro** para representar que pertenece al fractal.
  Si **escapa**, asignamos un color basado en la iteración en la que escapó.
  Por ejemplo, con un máximo de 100 iteraciones:

  * Iteración baja → colores claros (escapa rápido)
  * Iteración alta → colores oscuros (cerca del límite)

  Este gradiente genera la **profundidad visual** que hace reconocibles los fractales.

---

### 7️⃣ Escribir el pixel en el buffer

* **Código:**

  ```c
  int offset = y * size_l + x * (bpp / 8);
  *(int *)(ptr_buf_img + offset) = color;
  ```

* **Descripción:**
  Para pintar un pixel calculamos su **desplazamiento en bytes** dentro del buffer:

  * Multiplicamos la fila (`y`) por el tamaño de fila (`size_l`)
  * Sumamos la columna (`x`) multiplicada por los bytes por pixel (`bpp/8`)

  Luego escribimos el color como un `int` de 4 bytes.
  Este método nos da control directo sobre la memoria y permite un dibujado muy rápido.

---

### 8️⃣ Mostrar la imagen y mantener el loop

* **Código:**

  ```c
  mlx_put_image_to_window(mlx, win, img, 0, 0);
  mlx_loop(mlx);
  ```

* **Descripción:**
  Cuando todos los pixeles han sido calculados y coloreados, copiamos la imagen al **framebuffer de la ventana** con `mlx_put_image_to_window`.
  Luego, `mlx_loop` mantiene el programa en ejecución y atiende eventos como:

  * **Zoom con el mouse**
  * **Movimiento con el teclado**
  * **Cierre de ventana**

  Cada vez que interactuamos, podemos recalcular el fractal y redibujarlo dinámicamente.

---

## 🔁 Flujo resumido

1. Inicializar MLX
2. Crear ventana e imagen
3. Obtener buffer de imagen
4. Mapear cada pixel a número complejo
5. Iterar $Z^2 + C$ con álgebra compleja
6. Determinar si escapa y asignar color
7. Escribir color en el buffer
8. Mostrar imagen y mantener el loop

---

## 🚀 Uso del programa

1. **Clonar el repositorio**

   ```bash
   git clone <url_del_repositorio>
   cd fractol
   ```

2. **Compilar el proyecto**

   ```bash
   make
   ```

3. **Ejecutar el programa**

   ```bash
   ./fractol <tipo_de_fractal> [coordenadas]
   ```

   **Ejemplos:**

   ```bash
   ./fractol mandelbrot
   ./fractol burningship
   ./fractol julia -0.7 0.5675
   ./fractol julia -0.8 0.156
   ./fractol julia 0.285 0
   ```

4. **Tipos de fractal disponibles:**

   * `mandelbrot`
   * `burningship`
   * `julia` *(requiere dos coordenadas entre -2.0 y 2.0)*

5. **Si el usuario introduce un argumento inválido**, el programa muestra la ayuda:

```
Invalid input from user

Available input: 

* Type of fractal: Julia - Mandelbrot - Burningship

* If you choose Julia, then add: 
  one coordinate separated by space.

* Egs. 
  ./fractol julia -0.7 0.5675
  ./fractol julia -0.8 0.156 
  ./fractol julia -0.4 0.6 
  ./fractol julia -0.75 0.11
  ./fractol julia 0.285 0

* Please note values can go from -2.0 to 2.0


