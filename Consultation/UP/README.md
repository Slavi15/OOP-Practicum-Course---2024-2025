## Уводни задачи

<details>
<summary> <b>Пример №1</b> </summary>
  
Какво ще се отпечата на конзолата?
```c++
#include <iostream>

int main() {
	double a = 1.2; 
	double b = 0; 
	int c = 4; 
	std::cout << a / !c << std::endl; 
	std::cout << b / !!false << std::endl;
	std::cout << -c / b << std::endl; 
}
```
</details>

<details>
<summary> <b>Пример №2</b> </summary>
  
Какво ще се отпечата на конзолата?
```c++
#include <iostream>

int main() {
	int a = 10; 
	std::cout << ++++a; 
	std::cout << ++++a++; 
}
```
</details>

<details>
<summary> <b>Пример №3</b> </summary>
  
Какво ще отпечата следният код? Имаме ли загуба на памет?

```c++
#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int b = 10;
    double c = 2.2;
    double d = 2.3;
    int s = c + d;
    c = a / b;
    d = 1.0 * a / b;
    int e = d;
    cout << s << endl << c << endl << d << endl << e;
}

```
</details>

<details>
<summary> <b>Пример №4</b> </summary>
  
Какво ще отпечата следният код?

```c++
#include <iostream>

int main()
{
    int a = 0;
    int b = a++;
    std::cout << (a == !b) << std::endl;
    {
        int c = ++a;
        c *= 2;
        std::cout << c << std::endl;
    }
    int sum = a + b + c;
    std::cout << sum << std::endl;
    return 0;
}
```
</details>

<details>
<summary> <b>Пример №5</b> </summary>
  
Какво ще се отпечата на конзолата?

```c++
#include <iostream>

int main()
{
	int x = 5;
	char ch = 'A';
	
	switch (x % 3)
	{
	case 0:
		std::cout << "Zero\n";
		break;
	case 1:
		std::cout << "One\n";
	case 2:
		std::cout << "Two\n";
		ch = 'C';
	case 3:
		std::cout << "Three\n";
		break;
	default:
		std::cout << "Default\n";
	}
	
	switch (ch)
	{
	case 'A':
		std::cout << "Character A\n";
		break;
	case 'B':
		std::cout << "Character B\n";
		break;
	case 'C':
		std::cout << "Character C\n";
	default:
		std::cout << "Character Default\n";
	}
	
	return 0;
}
```
</details>

<details>
<summary> <b>Пример №6</b> </summary>
  
Какво ще се отпечата на конзолата?
```c++
#include <iostream>

int main()
{
    for (unsigned int i = 10; i >= 0; i--)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
```
</details>

<details>
<summary> <b>Пример №7</b> </summary>
  
Какво ще се отпечата?

```c++
#include <iostream>

void f(int b) {
   	b++;
   	a += 100;
   	std::cout << (b % 2 == 0) << std::endl;
}
 
int main() {
   	int a = 200, b = 3;
   	f(b);
   	std::cout << a << " " << b << std::endl;
}
```
</details>

## 1. Референции

- Друго име за вече съществуваща променлива
- Не можем да променяме адреса, към който референцията сочи
- Референцията винаги се инициализира

```c++
// Не можем
int& ref = 10;
```

**Примери:**

```c++
void f(int& x)
{
	std::cout << x << std::endl;
}

int x = 21;
f(x++); // НЕ Е ОК !!! rvalue
f(++x); // ОК !!! lvalue
```

```c++
int& g()
{
	int x = 10;
	x += 21;
	return x; // x умира в края на scope-а !!!
}
```

```c++
int& h(int& x)
{
	x += 7;
	return x; // ОК !!!
}
```

```c++
int& k(int& x, int& y)
{
	return x + y; // НЕ Е ОК !!! връща rvalue, а очакваме lvalue
}

int& k(int& x, int& y)
{
	return x += y; // ОК !!! връща lvalue
}
```

## 2. Масиви

- Последователност от елементи с предварително фиксирана дължина
- Големината на един масив трябва да ни е известна още преди компилация! **constexpr** - константа, чиято стойност може да се пресметне преди компилация

```c++
int x;
std::cin >> x;
const int y = x;

int arr[y]; // НЕ Е ОК !!! размерът трябва да се знае още преди компилация
```

```c++
constexpr size_t SIZE = 100;
int arr[SIZE];
```

- В масивите имаме константен достъп до всеки елемент

```c++
arr // => указател към първия елемент на масива
arr[i] // => arr + i * sizeof(<type>)
```

## 3. Указатели

- Променлива, която съдържа адреса на друга променлива
- Указателите имат неутрална стойност **nullptr**

```c++
int x = 10;

int* ptr = &x; // & ни връща адреса на x
int** ptr2 = &ptr;

int y = *ptr; // чрез * дереферираме дадения указател и взимаме неговата стойност
int z = **ptr;
```

### Указателна аритметика

```c++
int* ptr; // (170)
ptr++; // => ptr + 1 * sizeof(int) => (174)
ptr += 10; // => ptr + 10 * sizeof(int) => (214)
```

```c++
void print(const int* arr, size_t size)
{
	if (!arr) return;

	for (size_t i = 0; i < size; i++)
	{
		std::cout << *(arr + i) << " ";
	}
}
```

### Подаване на масиви във функции

```c++
f(int* arr, size_t size) {} // => ако ще променяме масива

f(const int* arr, size_t size) {} // => ако НЯМА да променяме масива
```

## 4. Динамична памет

- Динамичната памет не се освобождава автоматично!
- Чрез **new** заделяме памет по време на **runtime**, като при всяко заделяне на памет, след това трябва да се извика **delete**. Иначе имаме отечка на памет
- **new** заделя памет и връща указател към нея

### Динамично заделяне на масиви

```c++
#include <iostream>

int* readArray(size_t N)
{
	int* arr = new int[N];

	for (size_t i = 0; i < N; i++)
	{
		std::cin >> arr[i];
	}

	return arr;
}

void printArray(const int* arr, size_t N)
{
	if (!arr) return;

	for (size_t i = 0; i < N; i++)
	{
		std::cout << arr[i] << " ";
	}
}

void freeArray(int* arr)
{
	if (!arr) return;

	delete[] arr;
}

int main()
{
	size_t N = 0;
	std::cin >> N;

	int* arr = readArray(N);

	// ...

	freeArray(arr);

	return 0;
}
```

### Динамично заделяне на матрици

```c++
#include <iostream>

int** readMatrix(size_t N, size_t M)
{
	int** mtx = new int* [N] { nullptr };

	for (size_t i = 0; i < N; i++)
	{
		mtx[i] = new int[M] { 0 };

		for (size_t j = 0; j < M; j++)
		{
			std::cin >> mtx[i][j];
		}
	}

	return mtx;
}

void printMatrix(const int* const* mtx, size_t rows, size_t cols)
{
	if (!mtx) return;

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			std::cout << mtx[i][j] << " ";
		}

		std::cout << std::endl;
	}
}

void freeMatrix(int** mtx, size_t N)
{
	if (!mtx) return;

	for (size_t i = 0; i < N; i++)
	{
		delete[] mtx[i];
	}

	delete[] mtx;
}

int main()
{
	size_t rows, cols;
	std::cin >> rows >> cols;

	int** mtx = readMatrix(rows, cols);

	// ...

	freeMatrix(mtx, rows);

	return 0;
}
```

---

**Задача:** Реализирайте функции `void insertAt(int*& arr, size_t& len, int index, int elem)` и `void removeAt(int*& arr, size_t& len, int index)`, които добавят / премахват елемент на дадена позиция в динамичен масив. След операцията подаденият масив да е с точно толкова дължина, колкото е нужна.

**Пример:**

```c++
[ 8, 12, 92, 32, 4 ]
```

```c++
insertAt 4 123 // => [ 8, 12, 92, 32, 123, 4 ]
removeAt 1 // => [ 8, 92, 32, 123, 4 ]
```

---

### Символни низове

- Масив от символи
- Всеки символен низ трябва да завършва с терминираща нула `\0`

```c++
const char* str = "FMI rulez!";
std::cout << str << std::endl; // отпечатва символите, докато не срещне `\0`
```

- При **strcpy(<dest>, <src>)** трябва да ни е гарантирано, че в **dest** ще имаме достатъчно място

## 5. Побитови операции

- Оператори, които работят директно върху битовете

<details>
<summary> <b>Въпрос</b> </summary>
  
Каква е разликата между следните парчета код?
```c++
#include <iostream>

int main()
{
    bool a, b, c, d;

    if (a && b && c && d) {}

    if (a & b & c & d) {}
}
```
</details>

### "&"

```c++
0  0  1  0  1  1  1  0  &
1  0  1  1  0  0  1  1
-----------------------
0  0  1  0  0  0  1  0 
```

### "|"

```c++
0  0  1  0  1  1  1  0  &
1  0  1  1  0  0  1  1
-----------------------
1  0  1  1  1  1  1  1 
```

### "^"

```c++
0  0  1  0  1  1  1  0  &
1  0  1  1  0  0  1  1
-----------------------
0  1  1  0  0  0  1  0 
```

---

**Задача:** С помощта на побитови операции и **8**-битово число `( unsigned char / uint8_t )` запазваме информация в кой ден от предстоящата седмица във **ФМИ** имаме контролно. Да се напише функция, която приема цяло число за броя на контролните в дадената седмица, като след това получава и самите дни

**Пример:**

```c++
4 0 3 5 6 // 01101001
```

```c++
Monday Thursday Saturday Sunday
```

---

**Задача:** Даден е масив, в който всяко число се среща четен брой пъти, освен едно. Да се напише функция, която връща кое е това число

---

## 6. Ламбда-функции и функции от по-висок ред (HOF)

- Ламбда-функцията е функция, която няма име и не е метод на клас
- Функции от по-висок ред са такива функции, които приемат като аргумент друга функция или връщат функция
- Ламбда изразите са изключително полезни, когато искаме да преизползваме логика

### Синтаксис на ламбда израз

```c++
struct A
{
    int x;
};

[](const A& lhs, const A& rhs) -> bool {
    return lhs.x < rhs.x;
}
```

### Подаване на ламбда-функция като аргумент на друга функция

- Ламбда-функциите можем да ги извикваме чрез function pointer в дадена функция

```c++
void f(<data>, bool (*compare)(<lhs>, <rhs>)) {}

int main()
{
    f(<data>, [](<lhs>, <rhs>) -> bool { ... });

    return 0;
}
```

- Можем да си направим **typedef** към даден function pointer по следния начин, и след това във функциите да подаваме него

```c++
using Func = bool (*)(<lhs>, <rhs>);

void f(<data>, Func func) {}

int main()
{
    f(<data>, [](<lhs>, <rhs>) -> bool { ... });

    return 0;
}
```

---

**Задача:** Да се напише програма, която сортира лексикографски множество от наредени двойки

---

**Задача:** Да се напише функция `map`, която прилага дадена функция над всички елементи от даден масив

---
