# SupermarketKata

Un amigo heredó un pequeño super de un tío abuelo 2do.  Se enteró que sos aspirantes a programador y lo primero que hizo fue preguntarnos si podíamos arreglarle la impresora. Luego de 15 minutos de explicarle nuestra profesión le pareció interesante lo que podíamos hacer y nos invitó a hacer un programa que le permita gestionar sus ventas. 

*Estado inicial*

- hacer un fork del proyecto actual - ok
- Clonar el fork de forma local - ok
- Agregar archivo gitignore - ok
- Agregar Archivos de copilación para - ok 
- Comenzar a avanzar con los requisitos de la primer a iteración - ok
- hacemos un commit y un push - ok

*Primera  interación*

Lo primero siempre es identificar las necesidades de nuestros usuarios ya sea entrevistándolos o bien investigando sobre el tema.
Podemos ver páginas de otros supermercados para entender mejor que se requiere

1. Diseñar la estructura para representar los productos del sistema. - ok
2. Probar la estructura con un generador de valores aleatorios para las atributos de los productos. - ok
3. Generar una función permita visualizar un producto correctamente -ok
4. Hacer un commit y push. 

*Segunda iteración* 

Teniendo una estructura que representa las necesidades del proyecto podemos ahora agruparlas en memoria para que estas sean accesibles por el sistema
Deberemos pensar una forma de mantener estos datos en memória. 

1. Buscar una estructura de datos que nos permita agrupar los elementos productos en memoria .
2. Permitir operaciones de alta de productos en la estructura elegida
3. Generar 20 productos aleatorios en la estructura elegida. 
4. Hacer un commit y push. 

*Tercera iteracion* 
Internamente nuestro sistema hace algunas tareas, pero todavía nos falta poder visualizar, buscar y navegar los productos de los que dispone el sistema.

1. Deberíamos identificar cada producto de una forma particular -> Id de producto
2. Permitir operaciones de búsqueda de productos por Id
3. Si el producto no existe devolver -1, si el producto existe devolver la dirección de memoria del producto buscado
4. Armar un menú simple de búsqueda para el usuario   
5. Hacer un commit y push. 

*Cuarta iteración*

Ya contamos con una representación simple de un producto, además todos los productos disponibles en memoria para poder utilizarlos.
Nuestro Amigo está muy contento con nuestros avances, si no consideramos que el programa todavía no sirve para absolutamente nada más que ver los productos que el super ofrece.  
Ahora nos faltaría ver una forma de armar una factura de compra. Cuando en un local de este tipo se compran productos, es necesario agruparlos en cantidades de cada producto adquirido.
De esta forma tenemos cunado vemos el detalle del producto tenemos algo similar a lo siguiente: 
 <cantidad> <Nombre producto> -------- <Precio Unitario> 

1. Buscar una estructura de datos que nos permita agrupar los elementos en memoria.
2. Permitir Agregar nuevos productos a la estructura dinámica seleccionada.
3. Si al agregar el producto este ya existe, aumentar en +1 el producto seleccionado.
2. Presentar por pantalla la factura con los productos seleccionados.
4. Hacer un commit y push. 
